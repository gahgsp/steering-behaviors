//
// Created by Kelvin on 09/08/2020.
//

#include "ArriveBehaviorShowcase.h"
#include "Arrive.h"

ArriveBehaviorShowcase::ArriveBehaviorShowcase() {
    auto *pAgent = new Agent();
    pAgent->SetPosition(Vector2D<float>(600, 400));
    pAgent->SetVelocity(Vector2D<float>(0, 0));

    agent = pAgent;
}

ArriveBehaviorShowcase::~ArriveBehaviorShowcase() {
    delete agent;
}

void ArriveBehaviorShowcase::Update(float deltaTime) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    target = Vector2D<float>(x, y);

    Arrive arriveBehavior(agent, target, 100);
    Steering steering = arriveBehavior.GetSteering();
    agent->Update(steering, deltaTime);
}

void ArriveBehaviorShowcase::Draw() {
    agent->Draw();

    Utils::DrawCircle(
            Application::renderer,
            static_cast<int>(target.x),
            static_cast<int>(target.y), 15, 181, 33, 92, 255);

    Utils::DrawCircle(
            Application::renderer,
            static_cast<int>(target.x),
            static_cast<int>(target.y), 100, 245, 218, 66, 255);

    SDL_RenderPresent(Application::renderer);
}

