//
// Created by Kelvin on 09/08/2020.
//

#include "Arrive.h"

Arrive::Arrive(Agent *pAgent, const Vector2D<float>& pTarget, float pApproachRadius) {
    agent = pAgent;
    target = pTarget;
    approachRadius = pApproachRadius;
}

Steering Arrive::GetSteering() {
    Vector2D<float> desiredVelocity = target - agent->GetPosition();
    float distance = desiredVelocity.length();
    desiredVelocity.normalize();

    if (distance < approachRadius) {
        desiredVelocity *= distance / approachRadius * agent->GetMaximumSpeed();
    } else {
        desiredVelocity *= agent->GetMaximumSpeed();
    }

    Vector2D<float> steeringForce = desiredVelocity - agent->GetVelocity();
    if (steeringForce.length() > agent->GetMaximumSteerForce()) {
        steeringForce.normalize();
        steeringForce *= agent->GetMaximumSteerForce();
    }

    auto steering = Steering(steeringForce, 0);
    return steering;
}
