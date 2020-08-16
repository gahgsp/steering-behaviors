//
// Created by Kelvin on 08/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_APPLICATION_H
#define AI_STEERING_BEHAVIOR_APPLICATION_H

#include "../include/SDL2/SDL.h"

#include "Showcase.h"

class Application {
public:
    static SDL_Renderer *renderer;
    Application();
    ~Application();
    void Run();
private:
    SDL_Window *window;
};

#endif //AI_STEERING_BEHAVIOR_APPLICATION_H
