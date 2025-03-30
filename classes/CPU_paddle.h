#ifndef CPU_PADDLE_H
#define CPU_PADDLE_H

#include "window.h"
#include "../raylib.h"

#define CPU_PADDLE_WIDTH    30
#define CPU_PADDLE_HEIGHT   100
#define CPU_PADDLE_VELOCITY 14
#define CPU_PADDLE_COLOR    WHITE

int CPUPaddlePosX = 0;
int CPUPaddlePosY = WINDOW_HEIGHT/2;

#endif