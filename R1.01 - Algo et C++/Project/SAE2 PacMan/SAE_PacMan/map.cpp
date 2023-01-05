#define FPS_LIMIT 60

#include <iostream>
#include <thread>
#include <vector>

#include "mingl/mingl.h"
#include "mingl/shape/rectangle.h"
#include "map.h"

using namespace std;

void environment::intiMap(MinGL &window){
    //rectangles
    //horizontal haut
    window << nsShape::Rectangle(nsGraphics::Vec2D(0,0), nsGraphics::Vec2D(1920,20), nsGraphics::KBlue);
    //horizontal bas
    window << nsShape::Rectangle(nsGraphics::Vec2D(0,940), nsGraphics::Vec2D(1920,920 ), nsGraphics::KBlue);
    //vertical droit
    window << nsShape::Rectangle(nsGraphics::Vec2D(1920,20), nsGraphics::Vec2D(1890,920 ), nsGraphics::KBlue);
    //vertical gauche
    window << nsShape::Rectangle(nsGraphics::Vec2D(0,0), nsGraphics::Vec2D(30,920 ), nsGraphics::KBlue);

    //1880 / 40 = 47 nb column
    //960 / 40 = 24 nb line

    // un mur statique vaut 0,
    // un chemin vide vaut 1,
    // un chemin avec une petite boule vaut 2,
    // une grosse boule 3,
    // pacman vaut 5 ,
    // les fantomes sont des entiers de 6, a 15

    vector<vector<unsigned>> mapPacman {
        {0,0,0,0,0,1,0,0,0,0, 0,0,0,0,0, 1, 0,0,0,0,0, 0,0,0,0,1,0,0,0,0,0},
        {0,1,1,1,0,1,0,1,0,1, 1,1,1,1,0, 1, 0,1,1,1,1, 1,0,1,0,1,0,1,1,1,0},
        {0,1,1,1,0,1,0,1,0,0, 0,0,0,1,0, 1, 0,1,0,0,0, 0,0,1,0,1,0,1,1,1,0},
        {0,0,0,0,0,0,0,1,1,1, 0,1,0,0,0, 0, 0,0,0,1,0, 1,1,1,0,0,0,0,0,0,0},
        {1,1,0,1,1,1,0,0,0,0, 0,1,1,0,1, 1, 1,0,1,1,0, 0,0,0,0,1,1,1,0,1,1},
        {0,0,0,0,0,1,0,1,1,1, 0,1,0,0,0, 0, 0,0,0,1,0, 1,1,1,0,1,0,0,0,0,0},
        {0,1,1,1,0,1,0,1,0,0, 0,0,0,1,1, 0, 1,1,0,0,0, 0,0,1,0,1,0,1,1,1,0},

        {0,0,0,0,0,0,0,1,0,1, 1,1,0,1,0, 0, 0,1,0,1,1, 1,0,1,0,0,0,0,0,0,0},

        {0,1,1,1,0,1,0,1,0,0, 0,0,0,1,1, 1, 1,1,0,0,0, 0,0,1,0,1,0,1,1,1,0},
        {0,0,0,0,0,1,0,1,1,1, 0,1,0,0,0, 0, 0,0,0,1,0, 1,1,1,0,1,0,0,0,0,0},
        {1,1,0,1,1,1,0,0,0,0, 0,1,1,0,1, 1, 1,0,1,1,0, 0,0,0,0,1,1,1,0,1,1},
        {0,0,0,0,0,0,0,1,1,1, 0,1,0,0,0, 0, 0,0,0,1,0, 1,1,1,0,0,0,0,0,0,0},
        {0,1,1,1,0,1,0,1,0,0, 0,0,0,1,0, 1, 0,1,0,0,0, 0,0,1,0,1,0,1,1,1,0},
        {0,1,1,1,0,1,0,1,0,1, 1,1,1,1,0, 1, 0,1,1,1,1, 1,0,1,0,1,0,1,1,1,0},
        {0,0,0,0,0,1,0,0,0,0, 0,0,0,0,0, 1, 0,0,0,0,0, 0,0,0,0,1,0,0,0,0,0},
    };

    for (unsigned x=0; x<31; x++) {
        for (unsigned y=0;y<15;y++) {
            if (mapPacman[y][x]==1)
            {
                //if (x==0)       window << nsShape::Rectangle(nsGraphics::Vec2D(x*60+30,y*60+20), nsGraphics::Vec2D(x*60+60+20,y*60+60+20), nsGraphics::KBlue);
                //else if (x==31) window << nsShape::Rectangle(nsGraphics::Vec2D(x*60+20,y*60+20), nsGraphics::Vec2D(x*60+60+20,y*60+60+30), nsGraphics::KBlue);
                window << nsShape::Rectangle(nsGraphics::Vec2D(x*60+30,y*60+20), nsGraphics::Vec2D(x*60+60+30,y*60+60+20), nsGraphics::KBlue);

            }
        }
    }
}
