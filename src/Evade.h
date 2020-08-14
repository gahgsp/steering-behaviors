//
// Created by Kelvin on 13/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_EVADE_H
#define AI_STEERING_BEHAVIOR_EVADE_H

#include "SteeringBehavior.h"

class Evade: public SteeringBehavior {
public:
    Evade(Agent *pAgent, const Vector2D<float>& pTarget);
    Steering GetSteering() override;
private:
    Agent *agent;
    Vector2D<float> target;
};

#endif //AI_STEERING_BEHAVIOR_EVADE_H
