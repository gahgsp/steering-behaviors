//
// Created by Kelvin on 12/08/2020.
//

#include "ObstacleAvoidance.h"
#include "Seek.h"

ObstacleAvoidance::ObstacleAvoidance(Agent *pAgent, std::vector<Vector2D<float>> pObstacles, const Vector2D<float>& pTarget) {
    agent = pAgent;
    obstacles = pObstacles;
    target = pTarget;
}

Steering ObstacleAvoidance::GetSteering() {
    Vector2D<float> mostThreateningObstacle;
    Vector2D<float> avoidanceRoute;
    Vector2D<float> avoidanceForce;
    auto dynamicLength = agent->GetVelocity().length() / agent->GetMaximumSpeed();
    auto forward = agent->GetPosition() + agent->GetVelocity().normalize() * dynamicLength;
    auto halfForward = forward * 0.5;


    // TODO: When having multiple obstacles, should select the closest to calculate the steering force
    for (auto i = 0; i < obstacles.size(); i++) {
        if (obstacles[i].dist(forward) <= 55 || obstacles[i].dist(halfForward) <= 55) {
            avoidanceForce = forward - obstacles[i];
            avoidanceForce = avoidanceForce.normalize() * 100;
            mostThreateningObstacle = obstacles[i];
        }
    }

    // TODO: Change these validations with X and Y equals to 0
    if (mostThreateningObstacle.x != 0 && mostThreateningObstacle.y != 0) {
        avoidanceRoute.x = forward.x - mostThreateningObstacle.x;
        avoidanceRoute.y = forward.y - mostThreateningObstacle.y;

        Seek seekBehavior(agent, avoidanceRoute);
        Steering steeringForce = seekBehavior.GetSteering();
        steeringForce.linear += avoidanceForce;
        return steeringForce;
    } else if (target.x != 0 && target.y != 0){
        Seek seekBehavior(agent, target);
        Steering steeringForce = seekBehavior.GetSteering();
        return steeringForce;
    }

    return Steering(Vector2D<float>(0, 0), 0);
}
