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

const int height = 900;
const int width = 1200;
void singlePendulum(int n, double tf, double ic[])
{
     SetConfigFlags(FLAG_MSAA_4X_HINT);
     InitWindow(width, height, "graphics.cpp");
     SetTargetFPS(80);

     Vector2 pivot = {(float) width / 2.0f, 240.0f};

     float lengthPixels = 460.0f; 
     float bobRadius = 45.0f; // Made the bob significantly bigger
     float rodThickness = 12.0f;

     float pivotRadius = 16.0f;
     float pivotRing = 6.5f;
     float pivotDotRadius = 5.5f;

     float arcRadius = 220.0f;
     float arcThickness = 3.0f;
     float headSize = 12.0f;
     float headRampLength = 36.0f;

     float dashLength = 14.0f;
     float dashGap = 10.0f;
     float dashThickness = 2.0f;

     float topIncrement = 220.0f;
     float topThickness = 8.0f;  // Thicker support bar
     float hatchSpacing = 60.0f;
     float hatchLength = 36.0f;
     float hatchThickness = 4.0f; // Thicker hatch lines

     result data = forward_euler(n, tf, ic);
     size_t frameIndex = 0;

     Texture2D eom = LoadTexture("images/eom.png");
     GenTextureMipmaps(&eom);
     SetTextureFilter(eom, TEXTURE_FILTER_TRILINEAR);

     float eomScale = 0.4f;
     float eomMargin = 40.0f;

     Vector2 eomPos = {eomMargin, (float)(height - eom.height) - eomMargin};

     Texture2D phiLabel = LoadTexture("images/phi.png");
     SetTextureFilter(phiLabel, TEXTURE_FILTER_BILINEAR);
     float labelRadius = arcRadius + 30.0f;

     while(WindowShouldClose() == false)
     {
          double currentPhi = data.phi[frameIndex];

          Vector2 bobPos = {
               pivot.x + (float)(lengthPixels * sin(currentPhi)),
               pivot.y + (float)(lengthPixels * cos(currentPhi))
          };

          BeginDrawing();
          ClearBackground(RAYWHITE);

          Vector2 startLine = {pivot.x - topIncrement, pivot.y};
          Vector2 endLine = {pivot.x + topIncrement, pivot.y};
          float hatchNarrow = 15.0f;

          DrawLineEx(startLine, endLine, topThickness, BLACK);
          for (float x = startLine.x + hatchNarrow; x <= endLine.x - hatchNarrow; x += hatchSpacing)
          {
               Vector2 hatchStart = {x, pivot.y};
               Vector2 hatchEnd = {x + hatchLength, pivot.y - hatchLength};
               DrawLineEx(hatchStart, hatchEnd, hatchThickness, BLACK);
          }

          for (float y = pivot.y; y < pivot.y + lengthPixels + bobRadius; y += dashLength + dashGap)
          {
               DrawLineEx({pivot.x, y}, {pivot.x, y + dashLength}, dashThickness, BLACK);
          }

          DrawLineEx(pivot, bobPos, rodThickness, BLACK);

          float phiDeg = (float)(currentPhi * RAD2DEG);
          float arcStart = fminf(90.0f, 90.0f - phiDeg);
          float arcEnd = fmaxf(90.0f, 90.0f - phiDeg);
          DrawRing(pivot, arcRadius - arcThickness / 2.0f, arcRadius + arcThickness / 2.0f, arcStart, arcEnd, 64, BLACK);

          float sign = (currentPhi >= 0.0) ? 1.0f : -1.0f;
          float head = headSize * fminf(1.0f, arcRadius * (float)fabs(currentPhi) / headRampLength);
          Vector2 tip = {
               pivot.x + arcRadius * (float)sin(currentPhi),
               pivot.y + arcRadius * (float)cos(currentPhi)
          };
          Vector2 direction = {sign * (float)cos(currentPhi), -sign * (float)sin(currentPhi)};
          Vector2 headCenter = {tip.x - direction.x * head, tip.y - direction.y * head};
          DrawPoly(headCenter, 3, head, atan2f(direction.y, direction.x) * RAD2DEG, BLACK);

          Vector2 labelPos = {
               pivot.x + labelRadius * (float)sin(currentPhi / 2.0) - phiLabel.width / 2.0f,
               pivot.y + labelRadius * (float)cos(currentPhi / 2.0) - phiLabel.height / 2.0f
          };
          DrawTextureV(phiLabel, labelPos, WHITE);

          DrawCircleV(pivot, pivotRadius, BLACK);
          DrawCircleV(pivot, pivotRadius - pivotRing, WHITE);
          DrawCircleV(pivot, pivotDotRadius, BLACK);

          DrawCircleV(bobPos, bobRadius, BLACK);

          DrawTextureV(eom, eomPos, WHITE);

          EndDrawing();

          frameIndex = (frameIndex + 1) % data.phi.size();
     }

     CloseWindow();
}

int main() {
     int n = 5000;
     double tf = 50.0;
     double ic[2] = {0.4, 0.0};
     singlePendulum(n, tf, ic);
     return 0;
}
