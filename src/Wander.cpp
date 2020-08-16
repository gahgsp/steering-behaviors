//
// Created by Kelvin on 10/08/2020.
//

#include <random>
#include "Wander.h"

Wander::Wander(Agent *pAgent, float pWanderCircleDistance, float pWanderCircleRadius) {
    agent = pAgent;
    wanderCircleDistance = pWanderCircleDistance;
    wanderCircleRadius = pWanderCircleRadius;
}

Steering Wander::GetSteering() {
    auto wanderCircleCenterPosition = agent->GetPosition() + agent->GetVelocity().normalize() * wanderCircleDistance;
    auto angle = rand() % 360; // If we make uniform randomization the agent will traverse in a more straight line

    // Calculates an edge position inside the wander circle
    // using a random angle
    Vector2D<float> wanderCircleEdgePosition(wanderCircleRadius, 0);
    wanderCircleEdgePosition.rotate(angle);

    Vector2D<float> target = wanderCircleCenterPosition + wanderCircleEdgePosition;

    Vector2D<float> desiredVelocity = target - agent->GetPosition();
    desiredVelocity.normalize();
    desiredVelocity *= agent->GetMaximumSpeed();

    Vector2D<float> steeringForce = desiredVelocity - agent->GetVelocity();
    if (steeringForce.length() > agent->GetMaximumSteerForce()) {
        steeringForce.normalize();
        steeringForce *= agent->GetMaximumSteerForce();
    }

    // Draws the circle where target random point will be selected as the target position
    Utils::DrawCircle(
            Application::renderer,
            static_cast<int>(wanderCircleCenterPosition.x),
            static_cast<int>(wanderCircleCenterPosition.y), 100, 255, 193, 7, 255);

    // Draws the Agent's current velocity (purple line)
    SDL_SetRenderDrawColor(Application::renderer, 149, 117, 205, 255);
    SDL_RenderDrawLine(
            Application::renderer,
            static_cast<int>(agent->GetPosition().x), static_cast<int>(agent->GetPosition().y),
            static_cast<int>(agent->GetPosition().x) + static_cast<int>(agent->GetVelocity().x) * 0.3,
            static_cast<int>(agent->GetPosition().y) + static_cast<int>(agent->GetVelocity().y) * 0.3);

    // Draws the Agent's current desired velocity (blue line)
    SDL_SetRenderDrawColor(Application::renderer, 79, 195, 247, 255);
    SDL_RenderDrawLine(
            Application::renderer,
            static_cast<int>(agent->GetPosition().x), static_cast<int>(agent->GetPosition().y),
            static_cast<int>(agent->GetPosition().x) + static_cast<int>(desiredVelocity.x) * 0.3,
            static_cast<int>(agent->GetPosition().y) + static_cast<int>(desiredVelocity.y) * 0.3);

    auto steering = Steering(steeringForce, 0);
    return steering;
}
