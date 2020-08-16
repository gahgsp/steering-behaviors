//
// Created by Kelvin on 08/08/2020.
//

#include "SeekBehaviorShowcase.h"
#include "Seek.h"

SeekBehaviorShowcase::SeekBehaviorShowcase() {
    auto *pAgent = new Agent();
    pAgent->SetPosition(Vector2D<float>(100, 100));
    pAgent->SetVelocity(Vector2D<float>(0, 0));

    agent = pAgent;
}

SeekBehaviorShowcase::~SeekBehaviorShowcase() {
    delete agent;
}

void SeekBehaviorShowcase::Update(float deltaTime, SDL_Event *event) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    target = Vector2D<float>(x, y);

    Seek seekBehavior(agent, target);
    Steering steering = seekBehavior.GetSteering();
    agent->Update(steering, deltaTime);
}

void SeekBehaviorShowcase::Draw() {
    agent->Draw();

    Utils::DrawCircle(
            Application::renderer,
            static_cast<int>(target.x),
            static_cast<int>(target.y), 15, 244, 67, 54, 255);
}