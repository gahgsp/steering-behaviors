//
// Created by Kelvin on 11/08/2020.
//

#ifndef AI_STEERING_BEHAVIOR_PATHFOLLOWINGSHOWCASE_H
#define AI_STEERING_BEHAVIOR_PATHFOLLOWINGSHOWCASE_H

#include <vector>
#include "Showcase.h"
#include "Agent.h"

class PathFollowingShowcase: public Showcase {
public:
    PathFollowingShowcase();
    ~PathFollowingShowcase() override;
    void Update(float deltaTime, SDL_Event *event) override;
    void Draw() override;
private:
    Agent *agent;
    std::vector<Vector2D<float>> targets;
    int currentTargetIndex;
};

#endif //AI_STEERING_BEHAVIOR_PATHFOLLOWINGSHOWCASE_H
