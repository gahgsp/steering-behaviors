//
// Created by Kelvin on 09/08/2020.
//

#include "FleeBehaviorShowcase.h"
#include "Flee.h"

FleeBehaviorShowcase::FleeBehaviorShowcase() {
    auto *pAgent = new Agent();
    pAgent->SetPosition(Vector2D<float>(600, 400));
    pAgent->SetVelocity(Vector2D<float>(0, 0));

    agent = pAgent;
}

FleeBehaviorShowcase::~FleeBehaviorShowcase() {
    delete agent;
}

void FleeBehaviorShowcase::Update(float deltaTime) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    target = Vector2D<float>(x, y);

    Flee fleeBehavior(agent, target);
    Steering steering = fleeBehavior.GetSteering();
    agent->Update(steering, deltaTime);
}

void FleeBehaviorShowcase::Draw() {
    agent->Draw();

    Utils::DrawCircle(
            Application::renderer,
            static_cast<int>(target.x),
            static_cast<int>(target.y), 15, 181, 33, 92, 255);
}