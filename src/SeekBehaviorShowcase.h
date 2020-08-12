//
// Created by Kelvin on 08/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_SEEKBEHAVIORSHOWCASE_H
#define AI_STEERING_BEHAVIOR_SEEKBEHAVIORSHOWCASE_H

#include <vector>
#include "Showcase.h"
#include "Agent.h"

class SeekBehaviorShowcase: public Showcase {
public:
    SeekBehaviorShowcase();
    ~SeekBehaviorShowcase() override;
    void Update(float deltaTime, SDL_Event *event) override;
    void Draw() override;
private:
    Agent* agent;
    Vector2D<float> target;
};


#endif //AI_STEERING_BEHAVIOR_SEEKBEHAVIORSHOWCASE_H
