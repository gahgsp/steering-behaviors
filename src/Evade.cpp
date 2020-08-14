//
// Created by Kelvin on 13/08/2020.
//

#include "Evade.h"
#include "Flee.h"

Evade::Evade(Agent *pAgent, const Vector2D<float> &pTarget) {
    agent = pAgent;
    target = pTarget;
}

Steering Evade::GetSteering() {
    Flee fleeBehavior(agent, target);
    return fleeBehavior.GetSteering();
}
