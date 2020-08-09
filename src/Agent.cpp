//
// Created by Kelvin on 08/08/2020.
//

#include "Agent.h"

Agent::Agent(): maxSpeed(300), maxSteerForce(400) {}

void Agent::Draw() {
    Utils::DrawCircle(Application::renderer, static_cast<int>(position.x), static_cast<int>(position.y), 15, 25, 156, 31, 255);
}

void Agent::SetPosition(Vector2D<float> pos) {
    position = pos;
}

void Agent::SetVelocity(Vector2D<float> vel) {
    velocity = vel;
}

void Agent::Update(Steering steering, float deltaTime) {
    position += velocity * deltaTime;
    velocity += steering.linear * deltaTime;

    if (velocity.length() > maxSpeed) {
        velocity.normalize();
        velocity *= maxSpeed;
    }
}

Vector2D<float> Agent::GetPosition() {
    return position;
}

float Agent::GetMaximumSpeed() {
    return maxSpeed;
}

Vector2D<float> Agent::GetVelocity() {
    return velocity;
}

float Agent::GetMaximumSteerForce() {
    return maxSteerForce;
}
