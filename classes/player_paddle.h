#ifndef PLAYER_PADDLE_H
#define PLAYER_PADDLE_H

#include "window.h"
#include "../raylib.h"

#define PLAYER_PADDLE_WIDTH    30
#define PLAYER_PADDLE_HEIGHT   100
#define PLAYER_PADDLE_VELOCITY 12
#define PLAYER_PADDLE_COLOR    WHITE

int playerPaddlePosX = WINDOW_WIDTH - PLAYER_PADDLE_WIDTH;
int playerPaddlePosY = WINDOW_HEIGHT/2;

#endif