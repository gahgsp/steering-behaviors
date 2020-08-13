//
// Created by Kelvin on 12/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_OBSTACLEAVOIDANCESHOWCASE_H
#define AI_STEERING_BEHAVIOR_OBSTACLEAVOIDANCESHOWCASE_H

#include <vector>
#include "Showcase.h"
#include "Vector2D.h"
#include "Agent.h"

class ObstacleAvoidanceShowcase: public Showcase {
public:
    ObstacleAvoidanceShowcase();
    ~ObstacleAvoidanceShowcase() override;
    void Update(float deltaTime, SDL_Event *event) override;
    void Draw() override;
private:
    std::vector<Vector2D<float>> obstacles;
    Vector2D<float> target;
    Agent *agent;
};

#endif //AI_STEERING_BEHAVIOR_OBSTACLEAVOIDANCESHOWCASE_H
