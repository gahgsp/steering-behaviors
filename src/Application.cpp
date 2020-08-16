//
// Created by Kelvin on 08/08/2020.
//

#include <iostream>

#include "Application.h"
#include "SeekBehaviorShowcase.h"
#include "FleeBehaviorShowcase.h"
#include "ArriveBehaviorShowcase.h"
#include "WanderBehaviorShowcase.h"
#include "PathFollowingShowcase.h"
#include "ObstacleAvoidanceShowcase.h"
#include "EvadeBehaviorShowcase.h"

SDL_Renderer* Application::renderer;

void Application::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cerr << "Something went wrong with the SDL2 initialization!" << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow(
            "Artificial Intelligence: Steering Behaviors - Showcase",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            1280,
            720,
            SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "Something went wrong with the SDL Window creation!" << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Something went wrong with the SDL Renderer creation!" << std::endl;
        return;
    }
}

void Application::Run() {
    bool quit = false;
    bool isFullscreen = false;
    auto last_update = static_cast<float>(SDL_GetTicks());

    Showcase *currentBehaviorShowcase = new SeekBehaviorShowcase();

    while (!quit) {
        SDL_Event event;
        SDL_PollEvent(&event);

        float deltaTime = static_cast<float>(SDL_GetTicks() - last_update) / 1000.0f;
        last_update = static_cast<float>(SDL_GetTicks());

        // Clear the screen!
        SDL_SetRenderDrawColor(Application::renderer, 0, 0, 0, 255);
        SDL_RenderClear(Application::renderer);

        currentBehaviorShowcase->Update(deltaTime, &event);
        currentBehaviorShowcase->Draw();

        SDL_RenderPresent(Application::renderer);

        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_1:
                        delete currentBehaviorShowcase;
                        currentBehaviorShowcase = new SeekBehaviorShowcase();
                        break;
                    case SDL_SCANCODE_2:
                        delete currentBehaviorShowcase;
                        currentBehaviorShowcase = new FleeBehaviorShowcase();
                        break;
                    case SDL_SCANCODE_3:
                        delete currentBehaviorShowcase;
                        currentBehaviorShowcase = new ArriveBehaviorShowcase();
                        break;
                    case SDL_SCANCODE_4:
                        delete currentBehaviorShowcase;
                        currentBehaviorShowcase = new WanderBehaviorShowcase();
                        break;
                    case SDL_SCANCODE_5:
                        delete currentBehaviorShowcase;
                        currentBehaviorShowcase = new PathFollowingShowcase();
                        break;
                    case SDL_SCANCODE_6:
                        delete currentBehaviorShowcase;
                        currentBehaviorShowcase = new ObstacleAvoidanceShowcase();
                        break;
                    case SDL_SCANCODE_7:
                        delete currentBehaviorShowcase;
                        currentBehaviorShowcase = new EvadeBehaviorShowcase();
                        break;
                    case SDL_SCANCODE_F:
                        isFullscreen = !isFullscreen;
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        delete currentBehaviorShowcase;
                        quit = true;
                        break;
                }
                break;
            case SDL_QUIT:
                quit = true;
        }

        if (isFullscreen) {
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        } else {
            SDL_SetWindowFullscreen(window, 0);
        }
    }

    SDL_Quit();
}
