//
// Created by Kelvin on 08/08/2020.
//

#include "SeekBehaviorShowcase.h"
#include "Seek.h"

SeekBehaviorShowcase::SeekBehaviorShowcase() {
    auto *agent = new Agent();
    agent->SetPosition(Vector2D<float>(100, 100));
    agent->SetVelocity(Vector2D<float>(0, 0));

    agents.push_back(agent);
}

SeekBehaviorShowcase::~SeekBehaviorShowcase() {
    for (int i = 0; i < agents.size(); i++) {
        delete agents[i];
    }
}

void SeekBehaviorShowcase::Update(float deltaTime) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    target = Vector2D<float>(x, y);

    Seek seekBehavior(agents[0], target);
    Steering steering = seekBehavior.GetSteering();
    agents[0]->Update(steering, deltaTime);
}

void SeekBehaviorShowcase::Draw() {
    agents[0]->Draw();

    Utils::DrawCircle(
            Application::renderer,
            static_cast<int>(target.x),
            static_cast<int>(target.y), 15, 181, 33, 92, 255);

    SDL_RenderPresent(Application::renderer);
}