#include <iostream>
#include <thread>

#include "mingl/mingl.h"

#include "mingl/shape/rectangle.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/triangle.h"

#include "entite.h"

using namespace std;

void entite::dessinePacMan (MinGL &window, const unsigned &x, const unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+50, y+50), 50, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+50, y+50), nsGraphics::Vec2D(x+100, y+30), nsGraphics::Vec2D(x+100,y+70), nsGraphics::KBlack);
    window << nsShape::Circle(nsGraphics::Vec2D(x+50, y+30), 5, nsGraphics::KBlack);
}

void entite::dessineFantômeMangeable (MinGL &window, unsigned &x, unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+50,y+50),50,nsGraphics::KBlue);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+0,y+100), nsGraphics::Vec2D(x+100, y+50), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+0,y+100), nsGraphics::Vec2D(x+0, y+125), nsGraphics::Vec2D(x+25,y+100), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+25,y+100), nsGraphics::Vec2D(x+50, y+125), nsGraphics::Vec2D(x+75,y+100), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+75,y+100), nsGraphics::Vec2D(x+100, y+125), nsGraphics::Vec2D(x+100,y+100), nsGraphics::KBlue);
    window << nsShape::Circle(nsGraphics::Vec2D(x+70,y+50),15,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+30,y+50),15,nsGraphics::KWhite);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+30,y+90), nsGraphics::Vec2D(x+70,y+95), nsGraphics::KWhite);
}

void entite::dessineFantômeMangeable2 (MinGL &window, unsigned &x, unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+50,y+50),50,nsGraphics::KBlue);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+0,y+100), nsGraphics::Vec2D(x+100, y+50), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+0,y+100), nsGraphics::Vec2D(x+25, y+125), nsGraphics::Vec2D(x+50,y+100), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+50,y+100), nsGraphics::Vec2D(x+75, y+125), nsGraphics::Vec2D(x+100,y+100), nsGraphics::KBlue);
    window << nsShape::Circle(nsGraphics::Vec2D(x+70,y+50),15,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+30,y+50),15,nsGraphics::KWhite);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+30,y+90), nsGraphics::Vec2D(x+70,y+95), nsGraphics::KWhite); //bouche
}

void entite::dessineFantôme (MinGL &window, unsigned &x, unsigned &y, const nsGraphics::RGBAcolor &Couleur){
    window << nsShape::Circle(nsGraphics::Vec2D(x+50,y+50),50,Couleur);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+0,y+100), nsGraphics::Vec2D(x+100, y+50), Couleur);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+0,y+100), nsGraphics::Vec2D(x+0, y+125), nsGraphics::Vec2D(x+25,y+100), Couleur);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+25,y+100), nsGraphics::Vec2D(x+50, y+125), nsGraphics::Vec2D(x+75,y+100), Couleur);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+75,y+100), nsGraphics::Vec2D(x+100, y+125), nsGraphics::Vec2D(x+100,y+100), Couleur);
    window << nsShape::Circle(nsGraphics::Vec2D(x+70,y+50),15,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+30,y+50),15,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+70,y+50),5,nsGraphics::KCyan);
    window << nsShape::Circle(nsGraphics::Vec2D(x+30,y+50),5,nsGraphics::KCyan);
}
