//
// Created by Kelvin on 09/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_ARRIVEBEHAVIORSHOWCASE_H
#define AI_STEERING_BEHAVIOR_ARRIVEBEHAVIORSHOWCASE_H

#include "Showcase.h"
#include "Agent.h"

class ArriveBehaviorShowcase: public Showcase {
public:
    ArriveBehaviorShowcase();
    ~ArriveBehaviorShowcase();
    void Update(float deltaTime);
    void Draw();
private:
    Agent* agent;
    Vector2D<float> target;
};

#endif //AI_STEERING_BEHAVIOR_ARRIVEBEHAVIORSHOWCASE_H
