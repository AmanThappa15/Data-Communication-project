
#include "pallindrome.h"

#include <chrono>
#include <iostream>
#include <random>
#include <string>

int main()
{
    const int length = 1000000;

    std::mt19937 generator(42);
    std::uniform_int_distribution<int> bit(0, 1);

    std::string data;
    data.reserve(length);

    for (int i = 0; i < length; ++i)
        data += char('0' + bit(generator));

    auto start = std::chrono::steady_clock::now();

    std::string result = longestPalindrome(data);

    auto end = std::chrono::steady_clock::now();

    auto elapsed = std::chrono::duration<double, std::milli>(
        end - start
    ).count();

    std::cout << "Input length: " << data.length() << '\n';
    std::cout << "Longest palindrome length: "
              << result.length() << '\n';
    std::cout << "Execution time: " << elapsed << " ms\n";

    return 0;
}
