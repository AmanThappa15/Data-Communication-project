
#include "../line_coding.h"
#include <stdexcept>

std::vector<int> encodeNRZL(const std::string& data)
{
    std::vector<int> signal;

    for (char bit : data)
    {
        if (bit == '0')
            signal.push_back(-1);
        else if (bit == '1')
            signal.push_back(1);
        else
            throw std::invalid_argument(
                "Input must contain only 0 and 1"
            );
    }

    return signal;
}

std::vector<int> encodeNRZI(const std::string& data)
{
    std::vector<int> signal;
    int level = -1;

    for (char bit : data)
    {
        if (bit != '0' && bit != '1')
            throw std::invalid_argument(
                "Input must contain only 0 and 1"
            );

        if (bit == '1')
            level = -level;

        signal.push_back(level);
    }

    return signal;
}

std::vector<int> encodeManchester(const std::string& data)
{
    std::vector<int> signal;

    for (char bit : data)
    {
        if (bit == '0')
        {
            signal.push_back(-1);
            signal.push_back(1);
        }
        else if (bit == '1')
        {
            signal.push_back(1);
            signal.push_back(-1);
        }
        else
        {
            throw std::invalid_argument(
                "Input must contain only 0 and 1"
            );
        }
    }

    return signal;
}

std::vector<int> encodeDifferentialManchester(
    const std::string& data)
{
    std::vector<int> signal;
    int level = -1;

    for (char bit : data)
    {
        if (bit != '0' && bit != '1')
            throw std::invalid_argument(
                "Input must contain only 0 and 1"
            );
        if (bit == '0')
            level = -level;

        signal.push_back(level);
        level = -level;
        signal.push_back(level);
    }

    return signal;
}
std::vector<int> encodeAMI(const std::string& data)
{
    std::vector<int> signal;
    int level = 1;

    for (char bit : data)
    {
        if (bit == '0')
        {
            signal.push_back(0);
        }
        else if (bit == '1')
        {
            signal.push_back(level);
            level = -level;
        }
        else
        {
            throw std::invalid_argument(
                "Input must contain only 0 and 1"
            );
        }
    }

    return signal;
}

std::vector<int> encodeB8ZS(const std::string& data)
{
    std::vector<int> signal;
    int lastPulse = -1;

    for (std::size_t i = 0; i < data.size();)
    {
        if (data[i] != '0' && data[i] != '1')
        {
            throw std::invalid_argument(
                "Input must contain only 0 and 1"
            );
        }


        if (i + 8 <= data.size() &&
            data.compare(i, 8, "00000000") == 0)
        {
            if (lastPulse == 1)
            {
                const int pattern[] =
                    {0, 0, 0, 1, -1, 0, -1, 1};

                for (int level : pattern)
                    signal.push_back(level);

                lastPulse = 1;
            }
            else
            {
                const int pattern[] =
                    {0, 0, 0, -1, 1, 0, 1, -1};

                for (int level : pattern)
                    signal.push_back(level);

                lastPulse = -1;
            }

            i += 8;
        }
        else
        {
            if (data[i] == '1')
            {
                lastPulse = -lastPulse;
                signal.push_back(lastPulse);
            }
            else
            {
                signal.push_back(0);
            }

            ++i;
        }
    }

    return signal;
}

std::vector<int> encodeHDB3(const std::string& data)
{
    std::vector<int> signal;

    // Last non-zero pulse polarity
    int lastPulse = -1;

    // Number of normal pulses since the last violation
    int pulseCount = 0;

    for (std::size_t i = 0; i < data.size();)
    {
        if (data[i] != '0' && data[i] != '1')
        {
            throw std::invalid_argument(
                "Input must contain only 0 and 1"
            );
        }

        // Detect four consecutive zeros
        if (i + 4 <= data.size() &&
            data.compare(i, 4, "0000") == 0)
        {
            if (pulseCount % 2 == 1)
            {
                // Odd count: 000V
                int V = lastPulse;

                signal.push_back(0);
                signal.push_back(0);
                signal.push_back(0);
                signal.push_back(V);

                lastPulse = V;
            }
            else
            {
                // Even count: B00V
                int B = -lastPulse;
                int V = B;

                signal.push_back(B);
                signal.push_back(0);
                signal.push_back(0);
                signal.push_back(V);

                lastPulse = V;
            }

            // Start counting again after substitution
            pulseCount = 0;
            i += 4;
        }
        else
        {
            if (data[i] == '1')
            {
                lastPulse = -lastPulse;
                signal.push_back(lastPulse);
                pulseCount++;
            }
            else
            {
                signal.push_back(0);
            }

            ++i;
        }
    }

    return signal;
}
