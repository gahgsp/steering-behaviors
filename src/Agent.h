//
// Created by Kelvin on 08/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_AGENT_H
#define AI_STEERING_BEHAVIOR_AGENT_H

#include "Application.h"
#include "SteeringBehavior.h"
#include "Utils.h"
#include "Vector2D.h"

// This is here because the struct is inside the SteeringBehavior header.
// Maybe it would be better creating a separated header for this?
struct Steering;

class Agent {
public:
    Agent();
    void SetPosition(Vector2D<float> pos);
    Vector2D<float> GetPosition();
    void SetVelocity(Vector2D<float> vel);
    Vector2D<float> GetVelocity();
    void Draw();
    void Update(Steering steeringForce, float deltaTime);
    float GetMaximumSpeed();
    float GetMaximumSteerForce();
private:
    Vector2D<float> position;
    Vector2D<float> velocity;
    float maxSpeed;
    float maxSteerForce;
};

#endif //AI_STEERING_BEHAVIOR_AGENT_H
