//
// Created by Kelvin on 08/08/2020.
//

#include <iostream>
#include "Application.h"

SDL_Renderer* Application::renderer;

void Application::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        std::cerr << "Something went wrong with the SDL2 initialization!" << SDL_GetError() << std::endl;
    }

    SDL_Window* window = SDL_CreateWindow("Steering Behaviors", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
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

void Application::Run(Showcase *showcase) {
    bool quit = false;
    float last_update = static_cast<float>(SDL_GetTicks());

    while (!quit) {
        SDL_Event event;
        SDL_PollEvent(&event);

        float deltaTime = static_cast<float>(SDL_GetTicks() - last_update) / 1000.0f;
        last_update = static_cast<float>(SDL_GetTicks());

        // Clear the screen!
        SDL_SetRenderDrawColor(Application::renderer, 0, 0, 0, 255);
        SDL_RenderClear(Application::renderer);

        showcase->Update(deltaTime);
        showcase->Draw();

        SDL_RenderPresent(Application::renderer);

        switch (event.type) {
            case SDL_QUIT:
                quit = true;
        }
    }

    SDL_Quit();
}
