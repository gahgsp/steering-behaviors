//
// Created by Kelvin on 10/08/2020.
//

#include "WanderBehaviorShowcase.h"
#include "Wander.h"

WanderBehaviorShowcase::WanderBehaviorShowcase() {
    auto *pAgent = new Agent();
    pAgent->SetPosition(Vector2D<float>(600, 400));
    pAgent->SetVelocity(Vector2D<float>(0, 0));

    agent = pAgent;
}

WanderBehaviorShowcase::~WanderBehaviorShowcase() {
    delete agent;
}

void WanderBehaviorShowcase::Update(float deltaTime, SDL_Event *event) {
    // Higher the radius, the more quantity of turns the agent will make
    Wander wanderBehavior(agent, 150, 100);
    Steering steering = wanderBehavior.GetSteering();
    agent->Update(steering, deltaTime);
}

void WanderBehaviorShowcase::Draw() {
    agent->Draw();
}

