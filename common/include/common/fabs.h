template <typename T>
constexpr auto constexpr_fabs(T d) {
    if (d < T{0}) {
        return -d;
    }
    return d;
}
