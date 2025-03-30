#ifndef BALL_H
#define BALL_H

#define BALL_RADIUS     15
#define BALL_COLOR      WHITE
#define BALL_VELOCITY   14

#include "../raylib.h"
#include "window.h"

#define INITIAL_BALL_POS_X WINDOW_WIDTH / 2
#define INITIAL_BALL_POS_Y WINDOW_HEIGHT / 2

int ballPosX = INITIAL_BALL_POS_X;
int ballPosY = INITIAL_BALL_POS_Y;

bool isBallMovingUp = true;
bool isBallMovingLeft = true;

#endif