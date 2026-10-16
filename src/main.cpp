
#include <iostream>
#include <string>
#include "data/data_generator.h"

int main()
{
    int length = 16;

    std::string data = generateData(length);

    std::cout << "Generated binary data: " << data << '\n';

    return 0;
}
