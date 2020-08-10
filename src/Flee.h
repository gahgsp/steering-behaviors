//
// Created by Kelvin on 09/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_FLEE_H
#define AI_STEERING_BEHAVIOR_FLEE_H

#include "Agent.h"

class Flee: public SteeringBehavior {
public:
    Flee(Agent *pAgent, const Vector2D<float>& pTarget);
    Steering GetSteering() override;
private:
    Agent *agent;
    Vector2D<float> target;
};

#endif //AI_STEERING_BEHAVIOR_FLEE_H
