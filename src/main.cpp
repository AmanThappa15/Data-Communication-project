
#include <iostream>
#include <string>
#include "data/data_generator.h"
#include "pallindrome/pallindrome.h"

int main()
{
    int length = 16;

    // Generate random binary data using your existing function
    std::string data = generateData(length);

    std::cout << "Generated binary data: " << data << '\n';

    // Find the longest pallindromic substring
    std::string palindrome = longestPalindrome(data);

    std::cout << "Longest palindrome: " << palindrome << '\n';
    std::cout << "Pallindrome length: " << palindrome.length() << '\n';

    return 0;
}


