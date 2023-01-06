#define FPS_LIMIT 60

#include <iostream>
#include <thread>
#include <vector>

#include "mingl/mingl.h"
#include "mingl/shape/rectangle.h"
#include "map.h"
#include "entities.h"

using namespace std;

void environment::intiMap(MinGL &window){
    //rectangles
    //horizontal haut
    window << nsShape::Rectangle(nsGraphics::Vec2D(0,0), nsGraphics::Vec2D(1200,20), nsGraphics::KBlue);
    //horizontal bas
    window << nsShape::Rectangle(nsGraphics::Vec2D(0,940), nsGraphics::Vec2D(1200,920 ), nsGraphics::KBlue);
    //vertical droit
    window << nsShape::Rectangle(nsGraphics::Vec2D(1200,20), nsGraphics::Vec2D(1170,920 ), nsGraphics::KBlue);
    //vertical gauche
    window << nsShape::Rectangle(nsGraphics::Vec2D(0,0), nsGraphics::Vec2D(30,920 ), nsGraphics::KBlue);

    //1880 / 40 = 47 nb column
    //960 / 40 = 24 nb line

    // un mur statique vaut 1
    // un chemin vide vaut 2 ,
    // un chemin avec une petite boule vaut 0,
    // une grosse boule 3,
    // pacman vaut 5 ,
    // les fantomes sont des entiers de 6, a 15

    vector<vector<unsigned>> mapPacman {
        {0,0,0,0, 0,0,0,0,0, 1, 0,0,0,0,0, 0,0,0,0},
        {0,1,0,1, 1,1,1,1,0, 1, 0,1,1,1,1, 1,0,1,0},
        {0,1,0,0, 0,0,0,1,0, 1, 0,1,0,0,0, 0,0,1,0},
        {0,1,1,1, 0,1,0,0,0, 3, 0,0,5,1,0, 1,1,1,3},
        {0,0,0,0, 0,1,1,0,1, 1, 1,0,1,1,0, 0,0,0,0},
        {0,1,1,1, 0,1,2,2,2, 2, 2,2,2,1,0, 1,1,1,0},
        {0,1,0,0, 0,0,2,1,1, 9, 1,1,2,0,0, 0,0,1,0},

        {0,1,3,1, 1,1,2,1,6, 7, 8,1,2,1,1, 1,0,1,0},

        {0,1,0,0, 0,0,2,1,1, 1, 1,1,2,0,0, 0,0,1,0},
        {0,1,1,1, 0,1,2,2,2, 2, 2,2,2,1,0, 1,1,1,0},
        {0,0,0,0, 0,1,1,0,1, 1, 1,0,1,1,0, 0,0,0,0},
        {0,1,1,1, 0,1,0,0,0, 0, 0,0,0,1,0, 1,1,1,0},
        {0,1,0,0, 0,0,0,1,0, 1, 0,1,0,0,0, 0,0,1,0},
        {0,1,0,1, 1,1,1,1,0, 1, 0,1,1,1,1, 1,0,1,0},
        {0,0,0,0, 0,0,0,0,0, 1, 0,0,0,3,0, 0,0,0,0},
    };

    for (unsigned x=0; x<19; x++) {
        for (unsigned y=0;y<15;y++) {
            if (mapPacman[y][x]==1)
            {
                //if (x==0)       window << nsShape::Rectangle(nsGraphics::Vec2D(x*60+30,y*60+20), nsGraphics::Vec2D(x*60+60+20,y*60+60+20), nsGraphics::KBlue);
                //else if (x==31) window << nsShape::Rectangle(nsGraphics::Vec2D(x*60+20,y*60+20), nsGraphics::Vec2D(x*60+60+20,y*60+60+30), nsGraphics::KBlue);
                window << nsShape::Rectangle(nsGraphics::Vec2D(x*60+30,y*60+20), nsGraphics::Vec2D(x*60+60+30,y*60+60+20), nsGraphics::KBlue);


            }
            else if (mapPacman[y][x]==0){
                entities::drawBall (window, x*60+30, y*60+20);
            }
            else if (mapPacman[y][x]==3){
                entities::drawBigBall (window, x*60+30, y*60+20);
            }
            else if (mapPacman[y][x]==5){
                entities::drawPacmanOpen (window, x*60+30, y*60+20);
            }
            else if (mapPacman[y][x]==6){
                entities::drawGhost (window, x*60+35, y*60+20,nsGraphics::KNavy);
            }
            else if (mapPacman[y][x]==7){
                entities::drawGhost (window, x*60+35, y*60+20,nsGraphics::KMagenta);
            }
            else if (mapPacman[y][x]==8){
                entities::drawGhost (window, x*60+35, y*60+20,nsGraphics::KRed);
            }
            else if (mapPacman[y][x]==9){
                entities::drawGhost (window, x*60+35, y*60+20,nsGraphics::KLime);
            }
        }

    }
}
