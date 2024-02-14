#include <iostream>
#include <vector>
#include <experimental/iterator>
#include <algorithm>
#include <string_view>
#include <cassert>

std::vector<int> CalculatePrefixFunc(std::string_view s) {
    if (s.empty()) {
        return {};
    }

    std::vector<int> prefs(s.size());
    prefs[0] = -1;

    for (size_t i = 1; i != prefs.size(); ++i) {
        int k = prefs[i - 1];
        assert(k + 1 < static_cast<int>(prefs.size()));
        while ((k >= 0) && (s[k] != s[i])) {
            k = prefs[k];
        }
        prefs[i] = k + 1;
    }

    prefs[0] = 0;
    return prefs;
}

template <class ContT>
void Print(ContT&& v) {
    std::copy(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    std::string s;
    std::cin >> s;

    auto v = CalculatePrefixFunc(s);
    Print(v);

    return 0;
}