
#include "pallindrome.h"
#include <algorithm>
#include <vector>
#include <string>

std::string longestPalindrome(const std::string& s)
{
    if (s.empty())
        return "";

    // Add separators to handle odd/even length palindromes.
    std::string t = "^";

    for (char c : s)
    {
        t += '#';
        t += c;
    }

    t += "#$";

    int n = static_cast<int>(t.size());
    std::vector<int> radius(n, 0);

    int center = 0;
    int right = 0;

    int bestCenter = 0;
    int bestLength = 0;

    for (int i = 1; i < n - 1; ++i)
    {
        int mirror = 2 * center - i;

        if (i < right)
            radius[i] = std::min(right - i, radius[mirror]);

        while (t[i + 1 + radius[i]] ==
               t[i - 1 - radius[i]])
        {
            ++radius[i];
        }

        if (i + radius[i] > right)
        {
            center = i;
            right = i + radius[i];
        }

        if (radius[i] > bestLength)
        {
            bestLength = radius[i];
            bestCenter = i;
        }
    }

    int start = (bestCenter - bestLength) / 2;

    return s.substr(start, bestLength);
}
