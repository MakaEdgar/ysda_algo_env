#include <iostream>

int Sum2(int a, int b) {
    return a + b;
}

int main() {
#ifdef NDEBUG
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif

    int a{0};
    int b{0};
    std::cin >> a >> b;

    auto ans = Sum2(a, b);

    std::cout << ans;

    return 0;
}