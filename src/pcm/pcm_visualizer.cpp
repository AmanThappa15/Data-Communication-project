
#include "raylib.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main()
{
    std::ifstream file("pcm_output.csv");
    std::vector<double> samples;
    double value;

    while (file >> value)
        samples.push_back(value);

    file.close();

    if (samples.empty())
    {
        std::cout << "No samples found! Run the PCM program first.\n";
        std::cout << "Make sure pcm_output.csv is in the project root.\n";
        return 1;
    }

    const int screenWidth = 1000;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "PCM Decoder - Staircase Signal");
    SetTargetFPS(60);

    const float left = 100;
    const float right = 940;
    const float top = 100;
    const float bottom = 530;

    const double minAmplitude = -10.0;
    const double maxAmplitude = 10.0;

    auto getX = [&](int i)
    {
        return left + (right - left) * i / samples.size();
    };

    auto getY = [&](double amplitude)
    {
        return bottom - (float)(
            (amplitude - minAmplitude) /
            (maxAmplitude - minAmplitude) * (bottom - top)
        );
    };

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

       DrawText("PCM DECODER - RECONSTRUCTED STAIRCASE SIGNAL",
         100, 25, 26, DARKBLUE);

DrawText("Amplitude", 20, 75, 22, DARKGRAY);
DrawText("Sample Number (Time)", 370, 585, 22, DARKGRAY);

        // Horizontal grid and amplitude labels
        for (int a = -10; a <= 10; a += 2)
        {
            float y = getY(a);
            Color gridColor = (a == 0) ? GRAY : LIGHTGRAY;

            DrawLine((int)left, (int)y, (int)right, (int)y, gridColor);

            DrawText(TextFormat("%d", a),
                     60, (int)y - 8, 16, DARKGRAY);
        }

        // Vertical axis and horizontal axis
        DrawLine((int)left, (int)top,
                 (int)left, (int)bottom, BLACK);

        DrawLine((int)left, (int)getY(0),
                 (int)right, (int)getY(0), BLACK);

        // Draw staircase signal
        for (int i = 0; i < (int)samples.size(); i++)
        {
            float x1 = getX(i);
            float x2 = getX(i + 1);
            float y = getY(samples[i]);

            // Horizontal section
            DrawLineEx({x1, y}, {x2, y}, 4.0f, BLUE);

            // Vertical transition to the next sample
            if (i + 1 < (int)samples.size())
            {
                float nextY = getY(samples[i + 1]);
                DrawLineEx({x2, y}, {x2, nextY}, 4.0f, BLUE);
            }

            DrawCircle((int)((x1 + x2) / 2),
                       (int)y, 5, RED);

            DrawText(TextFormat("%.2f", samples[i]),
                     (int)((x1 + x2) / 2) - 25,
                     (int)y - 25, 16, DARKBLUE);

            DrawText(TextFormat("%d", i + 1),
                     (int)((x1 + x2) / 2) - 5,
                     (int)bottom + 12, 16, DARKGRAY);
        }

        DrawText("Blue: Reconstructed PCM staircase",
                 300, 620, 16, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
