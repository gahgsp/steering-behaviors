//
// Source: https://gist.github.com/derofim/912cfc9161269336f722
//

#include "Utils.h"

void Utils::SetPixel(SDL_Renderer *rend, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(rend, r, g, b, a);
    SDL_RenderDrawPoint(rend, x, y);
}

void Utils::DrawCircle(SDL_Renderer *surface, int n_cx, int n_cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    // if the first pixel in the screen is represented by (0,0) (which is in sdl)
    // remember that the beginning of the circle is not in the middle of the pixel
    // but to the left-top from it:

    double error = (double)-radius;
    double x = (double)radius - 0.5;
    double y = (double)0.5;
    double cx = n_cx - 0.5;
    double cy = n_cy - 0.5;

    while (x >= y)
    {
        SetPixel(surface, (int)(cx + x), (int)(cy + y), r, g, b, a);
        SetPixel(surface, (int)(cx + y), (int)(cy + x), r, g, b, a);

        if (x != 0)
        {
            SetPixel(surface, (int)(cx - x), (int)(cy + y), r, g, b, a);
            SetPixel(surface, (int)(cx + y), (int)(cy - x), r, g, b, a);
        }

        if (y != 0)
        {
            SetPixel(surface, (int)(cx + x), (int)(cy - y), r, g, b, a);
            SetPixel(surface, (int)(cx - y), (int)(cy + x), r, g, b, a);
        }

        if (x != 0 && y != 0)
        {
            SetPixel(surface, (int)(cx - x), (int)(cy - y), r, g, b, a);
            SetPixel(surface, (int)(cx - y), (int)(cy - x), r, g, b, a);
        }

        error += y;
        ++y;
        error += y;

        if (error >= 0)
        {
            --x;
            error -= x;
            error -= x;
        }
        /*
        // sleep for debug
        SDL_RenderPresent(gRenderer);
        std::this_thread::sleep_for(std::chrono::milliseconds{ 100 });
        */
    }
}
