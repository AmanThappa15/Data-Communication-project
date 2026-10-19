
#include "pallindrome.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string& s)
{
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;

    while (left < right)
    {
        if (s[left] != s[right])
            return false;

        ++left;
        --right;
    }

    return true;
}

// Slow reference implementation used only for testing.
int bruteForceLength(const string& s)
{
    int best = 0;

    for (int i = 0; i < static_cast<int>(s.size()); ++i)
    {
        for (int j = i; j < static_cast<int>(s.size()); ++j)
        {
            string part = s.substr(i, j - i + 1);

            if (isPalindrome(part))
                best = max(best, static_cast<int>(part.size()));
        }
    }

    return best;
}

int main()
{
    vector<string> tests = {
        "",
        "0",
        "1",
        "10",
        "0000",
        "11111",
        "10101",
        "0110",
        "1001",
        "101101",
        "101110",
        "110011",
        "010101010"
    };

    int passed = 0;

    cout << "=== Longest Palindrome Tests ===\n\n";

    for (const string& input : tests)
    {
        string result = longestPalindrome(input);

        bool valid =
            isPalindrome(result) &&
            input.find(result) != string::npos &&
            result.length() ==
                static_cast<size_t>(bruteForceLength(input));

        cout << "Input: " << (input.empty() ? "(empty)" : input)
             << "\nPalindrome: "
             << (result.empty() ? "(empty)" : result)
             << "\nLength: " << result.length()
             << "\nResult: " << (valid ? "PASS" : "FAIL")
             << "\n\n";

        if (valid)
            ++passed;
    }

    // Exhaustively test every binary string up to 12 bits.
    int exhaustivePassed = 0;
    int exhaustiveTotal = 0;

    for (int n = 1; n <= 12; ++n)
    {
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            string input(n, '0');

            for (int i = 0; i < n; ++i)
            {
                if (mask & (1 << i))
                    input[i] = '1';
            }

            string result = longestPalindrome(input);

            bool valid =
                isPalindrome(result) &&
                input.find(result) != string::npos &&
                result.length() ==
                    static_cast<size_t>(bruteForceLength(input));

            ++exhaustiveTotal;

            if (valid)
                ++exhaustivePassed;
            else
                cout << "EXHAUSTIVE FAILURE: " << input
                     << " -> " << result << '\n';
        }
    }

    cout << "Manual tests: " << passed
         << "/" << tests.size() << " passed\n";

    cout << "Exhaustive tests: " << exhaustivePassed
         << "/" << exhaustiveTotal << " passed\n";

    if (passed == static_cast<int>(tests.size()) &&
        exhaustivePassed == exhaustiveTotal)
    {
        cout << "\nALL TESTS PASSED!\n";
        return 0;
    }

    cout << "\nSOME TESTS FAILED!\n";
    return 1;
}
