#include <iostream>
#include <string>
#include <vector>

#include "data/data_generator.h"
#include "pallindrome/pallindrome.h"
#include "line_coding.h"

int main()
{
    int inputChoice;

    std::cout << "===== DIGITAL SIGNAL ENCODER AND DECODER =====\n";
    std::cout << "1. Digital input\n";
    std::cout << "2. Analog input (PCM/DM - coming next)\n";
    std::cout << "Choose input type: ";

    if (!(std::cin >> inputChoice))
    {
        std::cout << "Invalid input.\n";
        return 1;
    }

    if (inputChoice == 1)
    {
        int dataChoice;
        int length;

        std::cout << "\n1. Completely random binary data\n";
        std::cout << "2. Binary data with four consecutive zeros\n";
        std::cout << "3. Binary data with eight consecutive zeros\n";
        std::cout << "Choose data type: ";

        if (!(std::cin >> dataChoice) ||
            dataChoice < 1 || dataChoice > 3)
        {
            std::cout << "Invalid data choice.\n";
            return 1;
        }

        std::cout << "Enter data length (minimum 1): ";

        if (!(std::cin >> length) || length < 1)
        {
            std::cout << "Invalid length.\n";
            return 1;
        }

        if (dataChoice == 2 && length < 4)
        {
            std::cout << "Length must be at least 4.\n";
            return 1;
        }

        if (dataChoice == 3 && length < 8)
        {
            std::cout << "Length must be at least 8.\n";
            return 1;
        }

        std::string data;

        if (dataChoice == 1)
            data = generateData(length);
        else if (dataChoice == 2)
            data = generateDataWithZeros(length, 4);
        else
            data = generateDataWithZeros(length, 8);

        std::cout << "\nDigital data stream: "
                  << data << '\n';

        std::string palindrome = longestPalindrome(data);

        std::cout << "Longest palindrome: "
                  << palindrome << '\n';

        std::cout << "Palindrome length: "
                  << palindrome.length() << '\n';

        int codingChoice;

        std::cout << "\nChoose line coding scheme:\n";
        std::cout << "1. NRZ-L\n";
        std::cout << "2. NRZ-I\n";
        std::cout << "3. Manchester\n";
        std::cout << "4. Differential Manchester\n";
        std::cout << "5. AMI\n";
        std::cout << "Choice: ";

        if (!(std::cin >> codingChoice) ||
            codingChoice < 1 || codingChoice > 5)
        {
            std::cout << "Invalid coding choice.\n";
            return 1;
        }

        std::vector<int> signal;
        std::string schemeName;

        if (codingChoice == 1)
        {
            signal = encodeNRZL(data);
            schemeName = "NRZ-L";
        }
        else if (codingChoice == 2)
        {
            signal = encodeNRZI(data);
            schemeName = "NRZ-I";
        }
        else if (codingChoice == 3)
        {
            signal = encodeManchester(data);
            schemeName = "Manchester";
        }
        else if (codingChoice == 4)
        {
            signal = encodeDifferentialManchester(data);
            schemeName = "Differential Manchester";
        }

else
{

int scrambleChoice;

std::cout << "\nChoose AMI scrambling option:\n";
std::cout << "1. B8ZS\n";
std::cout << "2. HDB3\n";
std::cout << "3. Normal AMI\n";
std::cout << "Choice: ";

if (!(std::cin >> scrambleChoice) ||
    scrambleChoice < 1 || scrambleChoice > 3)
{
    std::cout << "Invalid scrambling choice.\n";
    return 1;
}

if (scrambleChoice == 1)
{
    signal = encodeB8ZS(data);
    schemeName = "AMI with B8ZS";
}
else if (scrambleChoice == 2)
{
    signal = encodeHDB3(data);
    schemeName = "AMI with HDB3";
}
else
{
    signal = encodeAMI(data);
    schemeName = "AMI";
}

}


        std::cout << schemeName << " signal: ";

        for (int level : signal)
            std::cout << level << ' ';

        std::cout << '\n';
    }
    else if (inputChoice == 2)
    {
        std::cout
            << "\nAnalog input will be implemented with PCM/DM later.\n";
    }
    else
    {
        std::cout << "Invalid input choice.\n";
        return 1;
    }

    return 0;
}


