//
// Created by Kelvin on 12/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_OBSTACLEAVOIDANCE_H
#define AI_STEERING_BEHAVIOR_OBSTACLEAVOIDANCE_H

#include <vector>
#include "SteeringBehavior.h"

class ObstacleAvoidance: public SteeringBehavior {
public:
    ObstacleAvoidance(Agent *pAgent, std::vector<Vector2D<float>> pObstacles, const Vector2D<float> &pTarget);
    Steering GetSteering() override;
private:
    Agent *agent;
    std::vector<Vector2D<float>> obstacles;
    Vector2D<float> target;
};

#endif //AI_STEERING_BEHAVIOR_OBSTACLEAVOIDANCE_H
