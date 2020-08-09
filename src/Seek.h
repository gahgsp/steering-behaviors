//
// Created by Kelvin on 08/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_SEEK_H
#define AI_STEERING_BEHAVIOR_SEEK_H

#include "SteeringBehavior.h"

class Seek: SteeringBehavior {
private:
    Agent *agent;
    Vector2D<float> target;
public:
    Seek(Agent *pAgent, Vector2D<float> pTarget);
    Steering GetSteering();
};


#endif //AI_STEERING_BEHAVIOR_SEEK_H
