
#include <iostream>
#include <string>
#include "data/data_generator.h"
#include "pallindrome/pallindrome.h"

int main()
{
    int length = 16;

    std::string data = generateData(length);

    // Display the generated binary data
    std::cout << "Generated binary data: " << data << '\n';

    // Find and display the longest palindrome
    std::string palindrome = longestPalindrome(data);

    std::cout << "Longest palindrome: " << palindrome << '\n';
    std::cout << "Palindrome length: " << palindrome.length() << '\n';

    return 0;
}

