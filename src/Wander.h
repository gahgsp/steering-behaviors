//
// Created by Kelvin on 10/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_WANDER_H
#define AI_STEERING_BEHAVIOR_WANDER_H

#include "Agent.h"

class Wander: public SteeringBehavior {
public:
    Wander(Agent *pAgent, float pWanderCircleDistance, float pWanderCircleRadius);
    Steering GetSteering() override;
private:
    Agent *agent;
    float wanderCircleDistance;
    float wanderCircleRadius;
};

#endif //AI_STEERING_BEHAVIOR_WANDER_H
