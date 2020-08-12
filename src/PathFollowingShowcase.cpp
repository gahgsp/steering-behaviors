//
// Created by Kelvin on 11/08/2020.
//

#include "PathFollowingShowcase.h"
#include "Seek.h"
#include "Arrive.h"

PathFollowingShowcase::PathFollowingShowcase() {
    auto *pAgent = new Agent(100, 0.5);
    pAgent->SetPosition(Vector2D<float>(600, 400));
    pAgent->SetVelocity(Vector2D<float>(0, 0));

    agent = pAgent;

    // We need to keep track of the current target index during all the execution of the scene
    // since we need to keep moving forward thus every iteration adding one to the current target index.
    currentTargetIndex = 0;
}

PathFollowingShowcase::~PathFollowingShowcase() {
    delete agent;
}

void PathFollowingShowcase::Update(float deltaTime, SDL_Event *event) {
    // Listen to mouse events to create the path.
    switch (event->type) {
        case SDL_MOUSEBUTTONDOWN:
            targets.emplace_back(event->button.x, event->button.y);
            break;
    }

    // Initialize the shortest distance with a high value to search for the closest target to go.
    float shortestDistance = INFINITY;

    if (!targets.empty()) {

        // Calculate the distance of the agent to the current target.
        auto currentDistanceToCurrentTarget = (agent->GetPosition() - targets[currentTargetIndex]).length();

        // If we "reached" the current target, we can search for the next.
        if (currentDistanceToCurrentTarget < 10) {

            // We add one to the current because we are always going forward on the path
            // and this way we ensure that the current target that we reached is not taken into account
            // when searching for the next target in the path.
            for (auto i = currentTargetIndex + 1; i < targets.size(); i++) {
                auto currTarget = targets[i];
                if ((agent->GetPosition() - currTarget).length() < shortestDistance) {
                    shortestDistance = (agent->GetPosition() - currTarget).length();
                    currentTargetIndex = i;
                }
            }
        }

        // We could use Seek here as well.
        Arrive arriveBehavior(agent, targets[currentTargetIndex], 20);
        Steering steering = arriveBehavior.GetSteering();
        agent->Update(steering, deltaTime);
    }
}

void PathFollowingShowcase::Draw() {
    for (auto i = 0; i < targets.size(); i++) {
        Utils::DrawCircle(
                Application::renderer,
                static_cast<int>(targets[i].x),
                static_cast<int>(targets[i].y), 15, 181, 33, 92, 255);
    }

    agent->Draw();
}
