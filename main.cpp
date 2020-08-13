#include "include/SDL2/SDL.h"

#include "src/Application.h"
#include "src/SeekBehaviorShowcase.h"
#include "src/FleeBehaviorShowcase.h"
#include "src/ArriveBehaviorShowcase.h"
#include "src/WanderBehaviorShowcase.h"
#include "src/PathFollowingShowcase.h"
#include "src/ObstacleAvoidanceShowcase.h"

int main(int argc, char *argv[])
{
    auto *app = new Application();
    app->Initialize();

    // auto *sbs = new SeekBehaviorShowcase();
    // app->Run(sbs);

    // auto *fbs = new FleeBehaviorShowcase();
    // app->Run(fbs);

    //auto *abs = new ArriveBehaviorShowcase();
    //app->Run(abs);

    // auto wbs = new WanderBehaviorShowcase();
    // app->Run(wbs);

    // auto pfbs = new PathFollowingShowcase();
    // app->Run(pfbs);

    auto oabs = new ObstacleAvoidanceShowcase();
    app->Run(oabs);

    return 0;
}

