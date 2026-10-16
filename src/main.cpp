#include <iostream>
#include "data/data_generator.h"

int main()
{
    int length = 16;

    std::string data = generateData(length);

    std::cout << "===== Digital Data Generator =====\n";
    std::cout << "Generated Data: " << data << '\n';

    return 0;
}