//
// Created by Kelvin on 09/08/2020.
//

#include "Flee.h"

Flee::Flee(Agent *pAgent, Vector2D<float> pTarget) {
    agent = pAgent;
    target = pTarget;
}

Steering Flee::GetSteering() {
    Vector2D<float> desiredVelocity = agent->GetPosition() - target;
    desiredVelocity.normalize();
    desiredVelocity *= agent->GetMaximumSpeed();

    Vector2D<float> steeringForce = desiredVelocity - agent->GetVelocity();
    if (steeringForce.length() > agent->GetMaximumSteerForce()) {
        steeringForce.normalize();
        steeringForce *= agent->GetMaximumSteerForce();
    }

    // Draws the Agent's current velocity (yellow line)
    SDL_SetRenderDrawColor(Application::renderer, 245, 218, 66, 255);
    SDL_RenderDrawLine(
            Application::renderer,
            static_cast<int>(agent->GetPosition().x), static_cast<int>(agent->GetPosition().y),
            static_cast<int>(agent->GetPosition().x) + static_cast<int>(agent->GetVelocity().x) * 0.1,
            static_cast<int>(agent->GetPosition().y) + static_cast<int>(agent->GetVelocity().y) * 0.1);

    // Draws the Agent's current desired velocity (blue line)
    SDL_SetRenderDrawColor(Application::renderer, 66, 114, 245, 255);
    SDL_RenderDrawLine(
            Application::renderer,
            static_cast<int>(agent->GetPosition().x), static_cast<int>(agent->GetPosition().y),
            static_cast<int>(agent->GetPosition().x) + static_cast<int>(desiredVelocity.x) * 0.1,
            static_cast<int>(agent->GetPosition().y) + static_cast<int>(desiredVelocity.y) * 0.1);

    auto steering = Steering(steeringForce, 0); // TODO: Calculate the rotation.
    return steering;
}
