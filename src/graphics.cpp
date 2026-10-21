#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <raylib.h>

#include "eulers.cpp"

// graphics.cpp is a suplement to this project, but isn't mandatory, this was just a way to
// introduce myself to OpenGL and other libraries ~ to help visualize the numerical methods and its errors

// In this project, I decided to take an easier route to introduce myself to OpenGL, instead of learning raw OpenGL,
// I am using the Raylib library (on github), but I plan on learning it soon, but I don't wanna put myself through
// its difficulties for now!

const int height = 800;
const int width = 800;

void single()
{
     InitWindow(width, height, "graphics.cpp");

     SetTargetFPS(60);

     while(WindowShouldClose() == false)
     {
          BeginDrawing();
          EndDrawing();
     }

     CloseWindow();
}

int main() {
     single();
     return 0;
}

