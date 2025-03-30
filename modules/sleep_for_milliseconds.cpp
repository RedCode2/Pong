#include "sleep_for_milliseconds.h"

void sleep_for_milliseconds(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}