#ifndef ENTITIES_H
#define ENTITIES_H

#include "mingl/mingl.h"

namespace entities{
    void drawPacman(MinGL &window, const unsigned &x, const unsigned &y);

    void drawGhost(MinGL &window, const unsigned &x, const unsigned &y, const nsGraphics::RGBAcolor &Couleur);

    void drawEatableGhost(MinGL &window, const unsigned &x, const unsigned &y);

    void drawEatableGhost2(MinGL &window, const unsigned &x, const unsigned &y);

    void drawDeadGhost(MinGL &window, const unsigned &x, const unsigned &y);

    void drawBall(MinGL &window, const unsigned &x, const unsigned &y);

    void drawBigBall(MinGL &window, const unsigned &x, const unsigned &y);
}

#endif // ENTITIES_H
