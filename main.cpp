#include "include/SDL2/SDL.h"

#include "src/Application.h"
#include "src/SeekBehaviorShowcase.h"

int main(int argc, char *argv[])
{
    auto *app = new Application();
    app->Initialize();

    auto *sbs = new SeekBehaviorShowcase();
    app->Run(sbs);

    return 0;
}

