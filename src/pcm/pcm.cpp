
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include "pcm.h"

void runPCM()
{
    int n;

    std::cout << "\n===== PCM ENCODER AND DECODER =====\n";
    std::cout << "Enter number of samples: ";

    if (!(std::cin >> n) || n < 1 || n > 1000)
    {
        std::cout << "Enter a sample count from 1 to 1000.\n";
        return;
    }

    std::vector<double> samples(n);
    std::vector<int> levels(n);
    std::vector<std::string> codes(n);
    std::vector<double> reconstructed(n);

    // Read analog sample values
    for (int i = 0; i < n; i++)
    {
        std::cout << "Sample " << i + 1
                  << " (-10 to 10): ";

        if (!(std::cin >> samples[i]) ||
            !std::isfinite(samples[i]) ||
            samples[i] < -10 || samples[i] > 10)
        {
            std::cout << "Invalid sample value.\n";
            return;
        }
    }

    // PCM ENCODER
    for (int i = 0; i < n; i++)
    {
        // Divide the input range into 8 levels
        int level = static_cast<int>(
            std::floor((samples[i] + 10.0) / 2.5)
        );

        if (level > 7)
            level = 7;

        levels[i] = level;

        // Convert level number into a 3-bit binary code
        codes[i] = std::string(3, '0');

        for (int bit = 2; bit >= 0; bit--)
        {
            if (level & (1 << bit))
                codes[i][2 - bit] = '1';
        }
    }

    std::cout << "\n--- PCM ENCODER OUTPUT ---\n";
    std::cout << "Original\tLevel\tPCM Code\n";

    for (int i = 0; i < n; i++)
    {
        std::cout << std::fixed << std::setprecision(2)
                  << samples[i] << "\t\t"
                  << levels[i] << "\t"
                  << codes[i] << '\n';
    }

    // PCM DECODER
    for (int i = 0; i < n; i++)
    {
        int level = 0;

        for (char bit : codes[i])
            level = level * 2 + (bit - '0');

        // Reconstruct using the middle of each quantization interval
        reconstructed[i] = -8.75 + level * 2.5;
    }

    std::cout << "\n--- PCM DECODER OUTPUT ---\n";
    std::cout << "PCM Code\tReconstructed Sample\n";

    for (int i = 0; i < n; i++)
    {
        std::cout << codes[i] << "\t\t"
                  << std::fixed << std::setprecision(2)
                  << reconstructed[i] << '\n';
    }

    std::cout << "\nBits per sample: 3\n";
    std::cout << "Total encoded bits: " << n * 3 << '\n';
}
