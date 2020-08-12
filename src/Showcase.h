//
// Created by Kelvin on 08/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_SHOWCASE_H
#define AI_STEERING_BEHAVIOR_SHOWCASE_H

#include <SDL2/SDL_events.h>

class Showcase {
public:
    Showcase() = default;
    virtual ~Showcase() = default;
    virtual void Update(float deltaTime, SDL_Event *event) = 0;
    virtual void Draw() = 0;
};

#endif //AI_STEERING_BEHAVIOR_SHOWCASE_H
