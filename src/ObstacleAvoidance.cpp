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
    Vector2D<float> avoidanceTarget;
    auto forward = agent->GetVelocity();
    forward.normalize();
    forward *= 10; // TODO: Make this value a parameter!

    if (!obstacles.empty()) {
        for (auto i = 0; i < obstacles.size(); i++) {
            auto distanceFromObstacle = (obstacles[i] - agent->GetPosition()).length();
            if (distanceFromObstacle < 80) {
                avoidanceTarget = obstacles[i] + obstacles[i].normalize() * 80;
            }
        }
    }

    // TODO: It can be 0 ...
    if (avoidanceTarget.x != 0 && avoidanceTarget.y != 0) {
        Seek seekBehavior(agent, avoidanceTarget);
        return seekBehavior.GetSteering();
    } else if (target.x != 0 && target.y != 0) {
        // TODO: Also here it can be 0 ...
        Seek seekBehavior(agent, target);
        return seekBehavior.GetSteering();
    }

    return Steering(Vector2D<float>(0, 0), 0);
}
