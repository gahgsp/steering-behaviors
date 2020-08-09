//
// Created by Kelvin on 08/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_STEERINGBEHAVIOR_H
#define AI_STEERING_BEHAVIOR_STEERINGBEHAVIOR_H

#include "Vector2D.h"
#include "Agent.h"

struct Steering {
    Steering(Vector2D<float> l, float a): linear(l), angular(a) {}
    Vector2D<float> linear;
    float angular;
};

class SteeringBehavior {
public:
    virtual ~SteeringBehavior() = default;
    virtual Steering GetSteering() = 0;
};


#endif //AI_STEERING_BEHAVIOR_STEERINGBEHAVIOR_H
