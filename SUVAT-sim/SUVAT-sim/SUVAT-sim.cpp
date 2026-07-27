#include <iostream>
#include "raylib.h"

struct Ball {
    float Xpos;
    float Ypos;
    int radius;
};

float CalcPos(float u, float a, float t) {
    return (u * t) + (0.5 * a * t * t);
}

int flipY(int windowY , int Y) {
    return windowY - Y;
}

int main()
{
    int windowX = 3200;
    int windowY = 1800;

    float XInitVel = 750;
    float YInitVel = 1000;
    float gravity = -400;
    float time = 0;
    Ball ball = { 0 , 0 , 25};



    InitWindow(windowX, windowY , "SUVAT-sim");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircle(ball.Xpos, ball.Ypos, ball.radius, RED);

        EndDrawing();

        time += deltaTime;
        ball.Xpos = CalcPos(XInitVel, 0, time);
        ball.Ypos = flipY(windowY , CalcPos(YInitVel, gravity, time));

        if (ball.Xpos >= windowX || (ball.Ypos >= windowY && ball.Xpos > 0)) {
            break;
        }
    }

    CloseWindow();
    return 0;
}


