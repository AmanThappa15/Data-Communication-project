
#include <iostream>
#include <string>
#include <vector>
#include "../line_coding.h"

void test(const std::string& data)
{
    std::cout << "\nInput: " << data << '\n';

    const auto b8zs = encodeB8ZS(data);
    const auto hdb3 = encodeHDB3(data);

    std::cout << "B8ZS: ";
    for (int x : b8zs)
        std::cout << x << ' ';
    std::cout << "\nLength: " << b8zs.size() << '\n';

    std::cout << "HDB3: ";
    for (int x : hdb3)
        std::cout << x << ' ';
    std::cout << "\nLength: " << hdb3.size() << '\n';
}

int main()
{
    test("1000000001");  // Eight zeros after a positive pulse
    test("1100000001");  // Seven zeros after a negative pulse
    test("10000");       // HDB3: odd pulse count before four zeros
    test("110000");      // HDB3: even pulse count before four zeros

    return 0;
}

