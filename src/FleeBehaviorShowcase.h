//
// Created by Kelvin on 09/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_FLEEBEHAVIORSHOWCASE_H
#define AI_STEERING_BEHAVIOR_FLEEBEHAVIORSHOWCASE_H

#include <vector>
#include "Showcase.h"
#include "Agent.h"

class FleeBehaviorShowcase: public Showcase {
public:
    FleeBehaviorShowcase();
    ~FleeBehaviorShowcase() override;
    void Update(float deltaTime) override;
    void Draw() override;
private:
    Agent* agent;
    Vector2D<float> target;
};

#endif //AI_STEERING_BEHAVIOR_FLEEBEHAVIORSHOWCASE_H
