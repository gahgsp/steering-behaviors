//
// Created by Kelvin on 09/08/2020.
//

#include "FleeBehaviorShowcase.h"
#include "Flee.h"

FleeBehaviorShowcase::FleeBehaviorShowcase() {
    auto *agent = new Agent();
    agent->SetPosition(Vector2D<float>(600, 400));
    agent->SetVelocity(Vector2D<float>(0, 0));

    agents.push_back(agent);
}

FleeBehaviorShowcase::~FleeBehaviorShowcase() {
    for (int i = 0; i < agents.size(); i++) {
        delete agents[i];
    }
}

void FleeBehaviorShowcase::Update(float deltaTime) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    target = Vector2D<float>(x, y);

    Flee fleeBehavior(agents[0], target);
    Steering steering = fleeBehavior.GetSteering();
    agents[0]->Update(steering, deltaTime);
}

void FleeBehaviorShowcase::Draw() {
    agents[0]->Draw();

    Utils::DrawCircle(
            Application::renderer,
            static_cast<int>(target.x),
            static_cast<int>(target.y), 15, 181, 33, 92, 255);

    SDL_RenderPresent(Application::renderer);
}