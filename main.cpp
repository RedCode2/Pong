#include "header.h"

int main (void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);  // Initialize Window

    InitAudioDevice();  // Initialize Audio Device

    Sound fxCollision       =   LoadSound("res/collision.wav");
    Sound gameOver          =   LoadSound("res/game-over.wav");
    Sound mouseButtonClick  =   LoadSound("res/mouse-btn-click.mp3");
    Sound gameWin           =   LoadSound("res/game-win.wav");

    SetTargetFPS(TARGET_FPS);   // Set Target FPS

    bool isMainGameRunning          = false; // Main Game Loop
    bool isShowingHomeScreen        = true;  // Home Screen
    bool isShowingGameWonScreen     = false; // Game Won Screen
    bool isShowingGameOverScreen    = false; // Game Over Screen

    int score = 100;

    Rectangle playAgainRect = {
        WINDOW_WIDTH/2 - 100,   WINDOW_HEIGHT/2 + 50,
        200,                    30
    };    // Play Again Rectangle
    Rectangle backToMenuRect = {
        WINDOW_WIDTH/2 - 100,   WINDOW_HEIGHT/2 + 100,
        200,                    30
    };  // Back to Menu Rectangle
    Rectangle exitRect = {
        WINDOW_WIDTH/2 - 100,   WINDOW_HEIGHT/2 + 150,
        200,                    30
    };  // Exit Rectangle

    Rectangle homeScreenPlayGameRect = {
        100, WINDOW_HEIGHT/2 - 50,
        300, 50
    };
    Rectangle homeScreenExitRect = {
        100, WINDOW_HEIGHT/2 + 50,
        300, 50
    };

    while (WindowShouldClose() == false) {
        BeginDrawing(); // Begin Drawing

        // Clear Background
        ClearBackground(WINDOW_BGCOLOR);

        // Display game lost screen
        if (isShowingGameOverScreen) {
            isShowingGameWonScreen = false;

            DrawText("Game Lost", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 - 50, 50, RED);         // Draw Game Over Text

            DrawText("Play Again", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 50, 30, WHITE);      // Draw Play Again Text
            DrawText("Back to Menu", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 100, 30, WHITE);   // Draw Back to Menu Text
            DrawText("Exit", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 150, 30, WHITE);           // Draw Exit Text

            // Check if mouse hovers over Play Again Text
            if (CheckCollisionPointRec(GetMousePosition(), playAgainRect)) {
                DrawText("Play Again", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 50, 30, GRAY);  // Draw Play Again Text
                // Check if text is clicked
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    PlaySound(mouseButtonClick);
                    isMainGameRunning = true;           // Start the game
                    ballPosX = INITIAL_BALL_POS_X;      // Reset Ball X Position
                    ballPosY = INITIAL_BALL_POS_Y;      // Reset Ball Y Position
                }
            }

            // Check if mouse hovers over Back to Menu Text
            if (CheckCollisionPointRec(GetMousePosition(), backToMenuRect)) {
                DrawText("Back to Menu", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 100, 30, GRAY);  // Draw Back to Menu Text
                // Check if text is clicked
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    PlaySound(mouseButtonClick);    // Play Mouse Button Click Sound
                    isShowingHomeScreen = true;     // Show Home Screen
                }
            }

            // Check if mouse hovers over Exit Text
            if (CheckCollisionPointRec(GetMousePosition(), exitRect)) {
                DrawText("Exit", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 150, 30, GRAY);   // Draw Exit Text
                // Check if text is clicked
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    PlaySound(mouseButtonClick);
                    CloseWindow();  // Close Window
                }
            }
        }

        // Display game won screen
        if (isShowingGameWonScreen) {
            isShowingGameOverScreen = false;

            DrawText("Game Won", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 - 50, 50, GREEN);        // Draw Game Over Text

            DrawText("Play Again", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 50, 30, WHITE);      // Draw Play Again Text
            DrawText("Back to Menu", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 100, 30, WHITE);   // Draw Back to Menu Text
            DrawText("Exit", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 150, 30, WHITE);           // Draw Exit Text

            // Check if mouse hovers over Play Again Text
            if (CheckCollisionPointRec(GetMousePosition(), playAgainRect)) {
                DrawText("Play Again", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 50, 30, GRAY);  // Draw Play Again Text
                // Check if text is clicked
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    PlaySound(mouseButtonClick);
                    isMainGameRunning = true;           // Start the game
                    ballPosX = INITIAL_BALL_POS_X;      // Reset Ball X Position
                    ballPosY = INITIAL_BALL_POS_Y;      // Reset Ball Y Position
                }
            }

            // Check if mouse hovers over Back to Menu Text
            if (CheckCollisionPointRec(GetMousePosition(), backToMenuRect)) {
                DrawText("Back to Menu", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 100, 30, GRAY);  // Draw Back to Menu Text
                // Check if text is clicked
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    PlaySound(mouseButtonClick);    // Play Mouse Button Click Sound
                    isShowingHomeScreen = true;     // Show Home Screen
                }
            }

            // Check if mouse hovers over Exit Text
            if (CheckCollisionPointRec(GetMousePosition(), exitRect)) {
                DrawText("Exit", WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 + 150, 30, GRAY);   // Draw Exit Text
                // Check if text is clicked
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    PlaySound(mouseButtonClick);
                    CloseWindow();  // Close Window
                }
            }
        }

        if (isShowingHomeScreen) {

            isShowingGameOverScreen = false;
            isShowingGameWonScreen = false;
            isMainGameRunning = false;

            DrawText("Pong", 100, WINDOW_HEIGHT/2 - 200, 100, BLUE);        // Pong Title Text
            DrawText("Play Game", 100, WINDOW_HEIGHT/2 - 50, 50, WHITE);    // Home Screen Play Game Text
            DrawText("Exit", 100, WINDOW_HEIGHT/2 + 50, 50, WHITE);         // Home Screen Exit Text

            // Check if mouse hovers over Play Game Text
            if (CheckCollisionPointRec(GetMousePosition(), homeScreenPlayGameRect)) {
                DrawText("Play Game", 100, WINDOW_HEIGHT/2 - 50, 50, GRAY);  // Draw Home Screen Play Game Text
                // Check if text is clicked
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    PlaySound(mouseButtonClick);
                    isShowingHomeScreen = false;        // Exit Home Screen
                    isMainGameRunning = true;           // Start the game

                    // Reset ball position
                    ballPosX = INITIAL_BALL_POS_X;
                    ballPosY = INITIAL_BALL_POS_Y;
                }
            }

            // Check if mouse hovers over Exit Text
            if (CheckCollisionPointRec(GetMousePosition(), homeScreenExitRect)) {
                DrawText("Exit", 100, WINDOW_HEIGHT/2 + 50, 50, GRAY);   // Draw Home Screen Exit Text
                // Check if text is clicked
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    PlaySound(mouseButtonClick);
                    CloseWindow();  // Close Window
                }
            }
        }

        if (isMainGameRunning) {
            isShowingGameOverScreen = false;    // Hide Game Over Screen
            isShowingGameWonScreen = false;     // Hide Game Won Screen
            isShowingHomeScreen = false;        // Hide Home Screen

            // Check if game won
            if (((ballPosX - BALL_RADIUS) <= 0)) {
                PlaySound(gameWin);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));    // Sleep for 0.5 seconds
                isMainGameRunning = false;
                isShowingGameWonScreen = true;
            };

            // Check if game lost
            if ((ballPosX + BALL_RADIUS) >= WINDOW_WIDTH) {
                PlaySound(gameOver);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));    // Sleep for 0.5 seconds
                isMainGameRunning = false;
                isShowingGameOverScreen = true;
            }

            // Check collisions for movement of ball
            if ((ballPosY - BALL_RADIUS) <= 0) isBallMovingUp = false;
            if ((ballPosY + BALL_RADIUS) >= WINDOW_HEIGHT) isBallMovingUp = true;

            // Check Ball Collision with CPU Paddle
            if ((ballPosY + CPU_PADDLE_HEIGHT/2) >= CPUPaddlePosY && (ballPosY - CPU_PADDLE_HEIGHT/2) <= (CPUPaddlePosY + CPU_PADDLE_HEIGHT) && (ballPosX + BALL_RADIUS) >= CPUPaddlePosX && (ballPosX - BALL_RADIUS) <= (CPUPaddlePosX + CPU_PADDLE_WIDTH)) {
                isBallMovingLeft = false;   // Change direction of ball
                PlaySound(fxCollision);     // Play Collision Sound Effect
            };

            // Check Ball Collision with Player Paddle
            if ((ballPosY + PLAYER_PADDLE_HEIGHT/2) >= playerPaddlePosY && (ballPosY - PLAYER_PADDLE_HEIGHT/2) <= (playerPaddlePosY + PLAYER_PADDLE_HEIGHT) && (ballPosX + BALL_RADIUS) >= playerPaddlePosX && (ballPosX - BALL_RADIUS) <= (playerPaddlePosX + PLAYER_PADDLE_WIDTH)) {
                isBallMovingLeft = true;    // Change direction of ball
                PlaySound(fxCollision);     // Play Collision Sound Effect
            };

            // Ball Movement Y
            if (isBallMovingUp) ballPosY -= BALL_VELOCITY;
            else ballPosY += BALL_VELOCITY;

            // Ball Movement X
            if (isBallMovingLeft) ballPosX -= BALL_VELOCITY;
            else ballPosX += BALL_VELOCITY;

            // CPU Paddle Movement
            if ((ballPosY < CPUPaddlePosY) && (CPUPaddlePosY > 0)) CPUPaddlePosY -= CPU_PADDLE_VELOCITY;
            if ((ballPosY > CPUPaddlePosY) && (CPUPaddlePosY < (WINDOW_HEIGHT - CPU_PADDLE_HEIGHT))) CPUPaddlePosY += CPU_PADDLE_VELOCITY;

            // Player Paddle Movement
            if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && (playerPaddlePosY > 0)) playerPaddlePosY -= PLAYER_PADDLE_VELOCITY;
            if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && (playerPaddlePosY < (WINDOW_HEIGHT - PLAYER_PADDLE_HEIGHT))) playerPaddlePosY += PLAYER_PADDLE_VELOCITY;

            // Draw Ball
            DrawCircle(
                ballPosX,       // Ball X Position
                ballPosY,       // Ball Y Position
                BALL_RADIUS,    // Ball Radius
                BALL_COLOR      // Ball Color
            );

            // Draw CPU Paddle
            DrawRectangle(
                CPUPaddlePosX,      // CPU Paddle X Position
                CPUPaddlePosY,      // CPU Paddle Y Position
                CPU_PADDLE_WIDTH,   // CPU Paddle Width
                CPU_PADDLE_HEIGHT,  // CPU Paddle Height
                CPU_PADDLE_COLOR    // CPU Paddle Color
            );

            // Draw Player Paddle
            DrawRectangle(
                playerPaddlePosX,     // Player Paddle X Position
                playerPaddlePosY,     // Player Paddle Y Position
                PLAYER_PADDLE_WIDTH,  // Player Paddle Width
                PLAYER_PADDLE_HEIGHT, // Player Paddle Height
                PLAYER_PADDLE_COLOR   // Player Paddle Color
            );

            // Draw Middle Line
            DrawLine(
                WINDOW_WIDTH/2,     // Middle Line X Position
                0,                  // Middle Line Y Position
                WINDOW_WIDTH/2,     // Middle Line X Position
                WINDOW_HEIGHT,      // Middle Line Y Position
                DARKGRAY            // Middle Line Color
            );
        }

        EndDrawing();   // End Drawing
    }

    UnloadSound(fxCollision);       // Unload Collision Sound
    UnloadSound(gameOver);          // Unload Game Over Sound
    UnloadSound(mouseButtonClick);  // Unload Mouse Button Click Sound

    CloseAudioDevice(); // Close Audio Device

    CloseWindow();      // Close Window

    return 0;
}