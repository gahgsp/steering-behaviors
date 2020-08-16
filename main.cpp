#include "include/SDL2/SDL.h"

#include "src/Application.h"

int main(int argc, char *argv[])
{
    auto *app = new Application();
    app->Run();

    return 0;
}

