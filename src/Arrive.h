//
// Created by Kelvin on 09/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_ARRIVE_H
#define AI_STEERING_BEHAVIOR_ARRIVE_H

#include "SteeringBehavior.h"

class Arrive: public SteeringBehavior {
public:
    Arrive(Agent *pAgent, Vector2D<float> pTarget, float pApproachRadius);
    Steering GetSteering();
private:
    Agent *agent;
    Vector2D<float> target;
    float approachRadius;
};

#endif //AI_STEERING_BEHAVIOR_ARRIVE_H
