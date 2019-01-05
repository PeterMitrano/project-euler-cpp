#!/usr/bin/env python3.7
import argparse
import csv
import os
import subprocess
from dataclasses import dataclass

import sys


@dataclass
class Entry:
    last_modified: float
    runtime_ns: int


def check_and_setup_env(args):
    home_env = 'EULER_HOME'

    if args.build_dir:
        build_dir = args.build_dir
    else:
        if home_env not in os.environ:
            print("Environment variable {} not set".format(home_env))
            return False, None, None

        euler_home = os.environ[home_env]

        if not os.path.isdir(euler_home):
            print("Euler home path {} is not a directory".format(euler_home))
            return False, None, None

        cmake_dir = "cmake-build-release"
        if not args.quiet:
            print("Assuming cmake build directory is {}".format(cmake_dir))
        build_dir = os.path.join(euler_home, cmake_dir)

    if args.db_file:
        db_file = args.db_file
    else:
        db_file = os.path.join(build_dir, "perf.db.csv")
        if not os.path.exists(db_file):
            open(db_file, 'w')

    return True, build_dir, db_file


def build_all_problems(args, build_dir):
    cmd = ['make', '-j4']
    if not args.quiet:
        print("building...")
    if args.quiet:
        result = subprocess.run(cmd, capture_output=True, cwd=build_dir)
    else:
        result = subprocess.run(cmd, cwd=build_dir)
    if result.returncode != 0:
        print("build failed")
        return False
    return True


def update_db_table(args, build_dir, db_file):
    # load the db
    db_file_ptr_read = open(db_file, 'r')
    db_reader = csv.reader(db_file_ptr_read)
    db = {}
    for problem_number, last_modified, runtime_ns in db_reader:
        db[int(problem_number)] = Entry(float(last_modified), int(runtime_ns))

    # look at all the current executables
    files = os.listdir(build_dir)
    for file in files:
        full_file = os.path.join(build_dir, file)
        try:
            problem_number = int(file)
        except ValueError:
            continue
        if problem_number > 600:
            continue

        file_last_modified = os.path.getmtime(full_file)
        if problem_number not in db or file_last_modified > db[problem_number].last_modified:
            if not args.quiet:
                print("Running problem #{}...".format(problem_number))
            cmd = [full_file, '-t', '-p']
            result = subprocess.run(cmd, capture_output=True, check=True)
            try:
                runtime_ns = int(result.stdout)
            except ValueError:
                print("Failed to parse runtime {} to an integer".format(result.stdout))
                continue

            # Update the db data structure
            entry = Entry(file_last_modified, runtime_ns)
            db[problem_number] = entry

    # write update db back to the file
    db_file_ptr_write = open(db_file, 'w')
    db_writer = csv.writer(db_file_ptr_write)
    for problem_number, entry in db.items():
        db_writer.writerow([problem_number, entry.last_modified, entry.runtime_ns])


def markdown_table(args, db_file):
    db_file_ptr = open(db_file, 'r')
    db_reader = csv.reader(db_file_ptr)
    markdown_table = "|Problem Number|Runtime (nanoseconds)|\n|-|-|\n"
    for problem_number, _, runtime_ns in db_reader:
        markdown_row = "|{}|{}|".format(problem_number, runtime_ns)
        markdown_table += markdown_row + "\n"
    return markdown_table


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--quiet", '-q', action="store_true")
    parser.add_argument("--build-dir", '-b', action="store_true")
    parser.add_argument("--db-file", '-d', action="store_true")
    args = parser.parse_args()

    success, build_dir, db_file = check_and_setup_env(args)
    if not success:
        return -1

    success = build_all_problems(args, build_dir)
    if not success:
        return -2

    update_db_table(args, build_dir, db_file)

    table = markdown_table(args, db_file)
    print(table)

    return 0


if __name__ == '__main__':
    sys.exit(main())
