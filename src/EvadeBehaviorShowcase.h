//
// Created by Kelvin on 13/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_EVADEBEHAVIORSHOWCASE_H
#define AI_STEERING_BEHAVIOR_EVADEBEHAVIORSHOWCASE_H

#include "Showcase.h"
#include "Agent.h"

class EvadeBehaviorShowcase: public Showcase {
public:
    EvadeBehaviorShowcase();
    ~EvadeBehaviorShowcase() override;
    void Update(float deltaTime, SDL_Event *event) override;
    void Draw() override;
private:
    Agent* agent;
    Vector2D<float> target;
};

#endif //AI_STEERING_BEHAVIOR_EVADEBEHAVIORSHOWCASE_H
