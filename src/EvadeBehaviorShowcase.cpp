//
// Created by Kelvin on 13/08/2020.
//

#include "EvadeBehaviorShowcase.h"
#include "Evade.h"

EvadeBehaviorShowcase::EvadeBehaviorShowcase() {
    auto *pAgent = new Agent(200, 10);
    pAgent->SetPosition(Vector2D<float>(600, 400));
    pAgent->SetVelocity(Vector2D<float>(0, 0));

    agent = pAgent;
}

EvadeBehaviorShowcase::~EvadeBehaviorShowcase() {
    delete agent;
}

void EvadeBehaviorShowcase::Update(float deltaTime, SDL_Event *event) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    target = Vector2D<float>(x, y);

    auto distance = (agent->GetPosition() - target).length();
    if (distance < 115) { // Target radius + Awareness circle radius
        Evade evadeBehavior(agent, target);
        Steering steering = evadeBehavior.GetSteering();
        agent->Update(steering, deltaTime);
    }
}

void EvadeBehaviorShowcase::Draw() {
    // Target
    Utils::DrawCircle(
            Application::renderer,
            static_cast<int>(target.x),
            static_cast<int>(target.y), 15, 244, 67, 54, 255);

    // Awareness Circle
    Utils::DrawCircle(
            Application::renderer,
            static_cast<int>(target.x),
            static_cast<int>(target.y), 100, 255, 87, 34, 255);

    agent->Draw();
}
