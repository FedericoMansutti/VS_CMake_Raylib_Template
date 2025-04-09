/*******************************************************************************************
*
*   raylib [core] example - Basic 3d example
*
*   Welcome to raylib!
*
*   To compile example, just press F5.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include "raylib.h"


class Game {
    public:
        Camera camera;
        Vector3 cubePosition;

    public:
        Game() : camera{}, cubePosition{} {

            camera.position = Vector3{ 10.0f, 10.0f, 8.0f };
            camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
            camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
            camera.fovy = 60.0f;
            camera.projection = CAMERA_PERSPECTIVE;


            SetConfigFlags(FLAG_WINDOW_RESIZABLE);
            InitWindow(1920, 1080, "raylib");
            MaximizeWindow();

        }

        void UpdateDrawFrame(void)
        {
            // Update
            //----------------------------------------------------------------------------------
            UpdateCamera(&camera, CAMERA_ORBITAL);
            //----------------------------------------------------------------------------------

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

                ClearBackground(RAYWHITE);

                BeginMode3D(camera);

                    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
                    DrawGrid(10, 1.0f);

                EndMode3D();



                DrawText("This is a raylib example", 10, 40, 20, DARKGRAY);

                DrawFPS(10, 10);

            EndDrawing();
            //----------------------------------------------------------------------------------
        }

        void run() {

            SetTargetFPS(10000);

            // Main game loop
            while (!WindowShouldClose())    // Detect window close button or ESC key
            {
                UpdateDrawFrame();
            }

            // De-Initialization
            CloseWindow(); 

        }
        
};
    

int main()
{
    Game game;
    game.run();
}
