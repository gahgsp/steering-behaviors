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
    ~FleeBehaviorShowcase();
    void Update(float deltaTime);
    void Draw();
private:
    std::vector<Agent*> agents;
    Vector2D<float> target;
};

#endif //AI_STEERING_BEHAVIOR_FLEEBEHAVIORSHOWCASE_H
