#include <iostream>
#include <vector>
#include <experimental/iterator>
#include <algorithm>

int main() {
    std::vector v{{1, 2, 3, 4, 5}};
    std::copy(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, ", "));
    return 0;
}