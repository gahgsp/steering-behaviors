//
// Created by Kelvin on 10/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_WANDERBEHAVIORSHOWCASE_H
#define AI_STEERING_BEHAVIOR_WANDERBEHAVIORSHOWCASE_H

#include "Showcase.h"
#include "Agent.h"

class WanderBehaviorShowcase: public Showcase {
public:
    WanderBehaviorShowcase();
    ~WanderBehaviorShowcase() override;
    void Update(float deltaTime) override;
    void Draw() override;
private:
    Agent *agent;
};

#endif //AI_STEERING_BEHAVIOR_WANDERBEHAVIORSHOWCASE_H
