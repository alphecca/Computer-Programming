#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    std::fill_n(v.end(), 3, -1);
//    for (int n : v)
//        std::cout << n << ' ';
    std::vector<int> v2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::fill_n(std::back_inserter(v2), 3, -1);
    for (int n : v2)
        std::cout << n << ' ';
 
}
