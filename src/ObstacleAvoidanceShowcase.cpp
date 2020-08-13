//
// Created by Kelvin on 12/08/2020.
//

#include "ObstacleAvoidanceShowcase.h"
#include "Utils.h"
#include "Application.h"
#include "ObstacleAvoidance.h"

ObstacleAvoidanceShowcase::ObstacleAvoidanceShowcase() {
    auto *pAgent = new Agent(100, 10);
    pAgent->SetPosition(Vector2D<float>(600, 400));
    pAgent->SetVelocity(Vector2D<float>(0, 0));

    agent = pAgent;
}

ObstacleAvoidanceShowcase::~ObstacleAvoidanceShowcase() {
    delete agent;
}

void ObstacleAvoidanceShowcase::Update(float deltaTime, SDL_Event *event) {
    switch (event->type) {
        case SDL_MOUSEBUTTONDOWN:
            if (event->button.button == SDL_BUTTON_LEFT) {
                target = Vector2D<float>(event->button.x, event->button.y);
            } else if (event->button.button == SDL_BUTTON_RIGHT) {
                obstacles.emplace_back(event->button.x, event->button.y);
            }
            break;
    }

    ObstacleAvoidance obstacleAvoidance(agent, obstacles, target);
    Steering steeringForce = obstacleAvoidance.GetSteering();
    agent->Update(steeringForce, deltaTime);
}

void ObstacleAvoidanceShowcase::Draw() {
    for (auto i = 0; i < obstacles.size(); i++) {
        Utils::DrawCircle(
                Application::renderer,
                static_cast<int>(obstacles[i].x),
                static_cast<int>(obstacles[i].y), 40, 237, 38, 24, 255);
    }

    if (target.x != 0 && target.y != 0) {
        Utils::DrawCircle(
                Application::renderer,
                static_cast<int>(target.x),
                static_cast<int>(target.y), 20, 29, 186, 20, 255);
    }

    agent->Draw();
}
