#ifndef ENTITE_H
#define ENTITE_H

#include "mingl/mingl.h"

namespace entite{
    void dessinePacMan (MinGL &window, const unsigned &x, const unsigned &y);

    void dessineFantôme (MinGL &window, const unsigned &x, const unsigned &y, const nsGraphics::RGBAcolor &Couleur);

    void dessineFantômeMangeable (MinGL &window, const unsigned &x, const unsigned &y);

    void dessineFantômeMangeable2 (MinGL &window, const unsigned &x, const unsigned &y);

    void dessineFantômeMort (MinGL &window, const unsigned &x, const unsigned &y);
}


#endif // ENTITE_H
