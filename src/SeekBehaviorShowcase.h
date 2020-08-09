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
    ~SeekBehaviorShowcase();
    void Update(float deltaTime);
    void Draw();
private:
    std::vector<Agent*> agents;
    Vector2D<float> target;
};


#endif //AI_STEERING_BEHAVIOR_SEEKBEHAVIORSHOWCASE_H
