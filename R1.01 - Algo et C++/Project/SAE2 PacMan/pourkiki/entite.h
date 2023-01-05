#ifndef ENTITE_H
#define ENTITE_H

#include "mingl/mingl.h"

namespace entite{
void dessinePacMan (MinGL &window, const unsigned &x, const unsigned &y);

void dessineFantômeMangeable (MinGL &window, unsigned &x, unsigned &y);

void dessineFantômeMangeable2 (MinGL &window, unsigned &x, unsigned &y);

void dessineFantôme (MinGL &window, unsigned &x, unsigned &y, const nsGraphics::RGBAcolor &Couleur);
}


#endif // ENTITE_H
