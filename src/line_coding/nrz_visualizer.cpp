
#include "raylib.h"
#include "../line_coding.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

int main()
{
    std::string data;

    std::cout << "Enter binary data (e.g. 10110010): ";
    std::cin >> data;
    if (data.empty())
    {
        std::cout << "Error: Input cannot be empty.\n";
        return 1;
    }

    for (char bit : data)
    {
        if (bit != '0' && bit != '1')
        {
            std::cout << "Error: Enter only binary digits (0 and 1).\n";
            return 1;
        }
    }
    std::vector<int> nrzl;
    std::vector<int> nrzi;

    try
    {
        nrzl = encodeNRZL(data);
        nrzi = encodeNRZI(data);
        std::string decodedNRZL = decodeNRZL(nrzl);
        std::string decodedNRZI = decodeNRZI(nrzi);
        std::cout << "\nOriginal data: " << data << '\n';
        std::cout << "NRZ-L decoded: " << decodedNRZL << '\n';
        std::cout << "NRZ-I decoded: " << decodedNRZI << '\n';

        if (decodedNRZL == data && decodedNRZI == data)
            std::cout << "Both decoding tests PASSED!\n";
        else
            std::cout << "Decoding test FAILED!\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    const int width = 1000;
    const int height = 600;

    const float left = 110.0f;
    const float right = 950.0f;
    const float bitWidth =
        (right - left) / static_cast<float>(data.size());

    InitWindow(width, height, "NRZ-L and NRZ-I Waveform Visualizer");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("NRZ-L AND NRZ-I WAVEFORMS",
                 250, 20, 26, DARKBLUE);

        DrawText("Input bits:", 25, 75, 18, DARKGRAY);
        for (int i = 0; i < static_cast<int>(data.size()); i++)
        {
            float x = left + i * bitWidth;

            DrawText(TextFormat("%c", data[i]),
                     static_cast<int>(x + bitWidth / 2 - 5),
                     75, 18, BLACK);

            DrawLine(static_cast<int>(x), 105,
                     static_cast<int>(x), 500, LIGHTGRAY);
        }

        DrawLine(static_cast<int>(right), 105,
                 static_cast<int>(right), 500, LIGHTGRAY);
        DrawText("NRZ-L", 25, 165, 20, MAROON);
        DrawText("+1", 65, 120, 16, DARKGRAY);
        DrawText("-1", 65, 205, 16, DARKGRAY);

        const float nrzlHigh = 135.0f;
        const float nrzlLow = 220.0f;

        for (int i = 0; i < static_cast<int>(nrzl.size()); i++)
        {
            float x1 = left + i * bitWidth;
            float x2 = x1 + bitWidth;
            float y = (nrzl[i] == 1) ? nrzlHigh : nrzlLow;
            DrawLineEx({x1, y}, {x2, y}, 3.0f, MAROON);
            if (i > 0 && nrzl[i] != nrzl[i - 1])
            {
                float previousY =
                    (nrzl[i - 1] == 1) ? nrzlHigh : nrzlLow;

                DrawLineEx({x1, previousY}, {x1, y},
                           3.0f, MAROON);
            }
        }
        DrawText("NRZ-I", 25, 365, 20, DARKGREEN);
        DrawText("+1", 65, 320, 16, DARKGRAY);
        DrawText("-1", 65, 405, 16, DARKGRAY);

        const float nrziHigh = 335.0f;
        const float nrziLow = 420.0f;

        for (int i = 0; i < static_cast<int>(nrzi.size()); i++)
        {
            float x1 = left + i * bitWidth;
            float x2 = x1 + bitWidth;
            float y = (nrzi[i] == 1) ? nrziHigh : nrziLow;
            DrawLineEx({x1, y}, {x2, y}, 3.0f, DARKGREEN);
            if (i > 0 && nrzi[i] != nrzi[i - 1])
            {
                float previousY =
                    (nrzi[i - 1] == 1) ? nrziHigh : nrziLow;

                DrawLineEx({x1, previousY}, {x1, y},
                           3.0f, DARKGREEN);
            }
        }

        DrawText("NRZ-L: 0 = -1, 1 = +1",
                 280, 475, 17, MAROON);

        DrawText("NRZ-I: 1 causes a transition; 0 keeps the level",
                 220, 510, 17, DARKGREEN);

        DrawText("Close this window to exit",
                 365, 565, 16, GRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

