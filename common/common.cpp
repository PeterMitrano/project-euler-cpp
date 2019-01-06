#include <common/ways_to_write_as_sum.h>

int IS_PRIME{0};

unsigned long ways_to_write_as_sum_v2(std::vector<unsigned int> const &S, int n) {
    static std::map<std::pair<std::vector<unsigned int>, int>, unsigned long> memorization;
    auto const it = memorization.find(std::make_pair(S, n));
    if (it != memorization.cend()) {
        return  it->second;
    }
    if (S.empty() or n < 0) {
        return 0ul;
    }
    else if (n == 0) {
        return 1ul;
    }
    else {
        auto sub_S = S;
        sub_S.pop_back();
        auto const result = ways_to_write_as_sum_v2(sub_S, n) + ways_to_write_as_sum_v2(S, n - S.back());
        memorization.emplace(std::make_pair(S, n), result);
        return result;
    }
}
