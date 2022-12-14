#ifndef ENTITIES_H
#define ENTITIES_H

#include "mingl/mingl.h"

namespace entities{ // Initialisation de dessin des entittés
    void drawPacmanOpen(MinGL &window, const unsigned &x, const unsigned &y);

    void drawPacmanClosed(MinGL &window, const unsigned &x, const unsigned &y);

    void drawGhost(MinGL &window, const unsigned &x, const unsigned &y, const nsGraphics::RGBAcolor &Couleur);

    void drawEatableGhost(MinGL &window, const unsigned &x, const unsigned &y);

    void drawEatableGhost2(MinGL &window, const unsigned &x, const unsigned &y);

    void drawDeadGhost(MinGL &window, const unsigned &x, const unsigned &y);

    void drawBall(MinGL &window, const unsigned &x, const unsigned &y);

    void drawBigBall(MinGL &window, const unsigned &x, const unsigned &y);
}

class Pacman { // Initialisation de l'objet Pacman
    private:
        unsigned speed = 5 ;
        unsigned x ;
        unsigned y ;
        unsigned spriteId = 1 ;
    public:
        void showPacman(MinGL &window) ;
        void setX(unsigned n) ;
        void setY(unsigned n) ;
        unsigned getX() ;
        unsigned getY()  ;
        void mooveToLeft() ;
        void mooveToRight() ;
        void mooveToUp() ;
        void mooveToDown() ;
};

class Ghost { // Initialisation de l'objet Fantôme
    private:
        unsigned x=0;
        unsigned y=0;
        unsigned short spriteId = 1;
    public:
        void draw(MinGL &window, const nsGraphics::RGBAcolor &Couleur);
        void setX(unsigned n);
        void setY(unsigned n);
        unsigned getX();
        unsigned getY();
        void moveToUp();
        void moveToDown();
        void moveToLeft();
        void moveToRight();
        void isEated();
};

#endif // ENTITIES_H
