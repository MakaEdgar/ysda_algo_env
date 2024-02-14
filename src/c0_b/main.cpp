#include <iostream>
#include <vector>
#include <experimental/iterator>
#include <numeric>

template <class ContT>
std::ostream& Print(ContT&& v, std::ostream& os = std::cout) {
    std::copy(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, " "));
    os << std::endl;
    return os;
}

int main() {
#ifdef NDEBUG
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif

    int n{0};
    std::cin >> n;

    std::vector<int> v(n);
    std::iota(v.begin(), v.end(), 1);

    Print(v);

    return 0;
}