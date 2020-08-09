//
// Created by Kelvin on 08/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_UTILS_H
#define AI_STEERING_BEHAVIOR_UTILS_H

#include "../include/SDL2/SDL.h"

class Utils {
public:
    static void SetPixel(SDL_Renderer *rend, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    static void DrawCircle(SDL_Renderer *surface, int n_cx, int n_cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};

#endif //AI_STEERING_BEHAVIOR_UTILS_H
