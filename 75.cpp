#include <iterator>
#include <algorithm>
#include <vector>
#include <eigen3/Eigen/Eigen>
#include <iostream>


unsigned long problem() {
    constexpr auto const N{1'500'000};
    Eigen::Matrix3i A;
    Eigen::Matrix3i B;
    Eigen::Matrix3i C;
    A << 1, -2, 2, 2, -1, 2, 2, -2, 3;
    B << 1, 2, 2, 2, 1, 2, 2, 2, 3;
    C << -1, 2, 2, -2, 1, 2, -2, 2, 3;

    std::vector<unsigned long> perimeters;

    auto add_non_primitives = [&](Eigen::Vector3i const &primitive) {
        auto x{2ul};
        while (true) {
            Eigen::Vector3i const scaled = x * primitive;
            auto const sum = scaled.sum();
            if (sum > N) {
                break;
            }
            perimeters.emplace_back(sum);
            ++x;
        }
    };

    Eigen::Vector3i root{3, 4, 5};
    perimeters.emplace_back(root.sum());
    add_non_primitives(root);
    std::vector<Eigen::Vector3i> leaves{root};

    while (true) {
        std::vector<Eigen::Vector3i> new_leaves;
        for (auto const &leaf : leaves) {
            Eigen::Vector3i const left = A * leaf;
            Eigen::Vector3i const center = B * leaf;
            Eigen::Vector3i const right = C * leaf;
            if (left.sum() <= N) {
                perimeters.emplace_back(left.sum());
                new_leaves.emplace_back(left);
                add_non_primitives(left);
            }
            if (center.sum() <= N) {
                perimeters.emplace_back(center.sum());
                new_leaves.emplace_back(center);
                add_non_primitives(center);
            }
            if (right.sum() <= N) {
                perimeters.emplace_back(right.sum());
                new_leaves.emplace_back(right);
                add_non_primitives(right);
            }
        }
        if (new_leaves.empty()) {
            break;
        }
        leaves = new_leaves;
    };

    std::sort(perimeters.begin(), perimeters.end());
    auto count{0ul};
    perimeters.push_back(0);
    auto start{perimeters.cbegin()};
    auto head{perimeters.cbegin() + 1};
    while (head != perimeters.cend()) {
        if (*head != *start) {
            ++count;
            start = head;
            ++head;
        } else {
            while (*head == *start and head != perimeters.cend()) {
                ++head;
                ++start;
            }
            if (head == perimeters.cend()) {
                break;
            }
            ++head;
            ++start;
        }
    }

    return count;
}