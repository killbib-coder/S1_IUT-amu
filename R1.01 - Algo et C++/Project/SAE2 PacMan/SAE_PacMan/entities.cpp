#include <iostream>
#include <thread>

#include "mingl/mingl.h"

#include "mingl/shape/rectangle.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/triangle.h"

#include "entities.h"

using namespace std;

void entities::drawPacman (MinGL &window, const unsigned &x, const unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+30, y+30), 25, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+30, y+30), nsGraphics::Vec2D(x+55, y+20), nsGraphics::Vec2D(x+55,y+40), nsGraphics::KBlack);
    window << nsShape::Circle(nsGraphics::Vec2D(x+30, y+20), 3, nsGraphics::KBlack);
}

void entities::drawGhost (MinGL &window, const unsigned &x, const unsigned &y, const nsGraphics::RGBAcolor &Couleur){
    window << nsShape::Circle(nsGraphics::Vec2D(x+25,y+25),20,Couleur);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+5,y+50), nsGraphics::Vec2D(x+45, y+25), Couleur);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+5,y+50), nsGraphics::Vec2D(x+5, y+60), nsGraphics::Vec2D(x+15,y+50), Couleur);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+15,y+50), nsGraphics::Vec2D(x+35, y+50), nsGraphics::Vec2D(x+25,y+60), Couleur);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+35,y+50), nsGraphics::Vec2D(x+45, y+60), nsGraphics::Vec2D(x+45,y+50), Couleur);
    window << nsShape::Circle(nsGraphics::Vec2D(x+33,y+25),5,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+18,y+25),5,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+33,y+25),2,nsGraphics::KCyan);
    window << nsShape::Circle(nsGraphics::Vec2D(x+18,y+25),2,nsGraphics::KCyan);
}

void entities::drawEatableGhost (MinGL &window, const unsigned &x, const unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+25,y+25),20,nsGraphics::KBlue);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+5,y+50), nsGraphics::Vec2D(x+45, y+25), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+5,y+50), nsGraphics::Vec2D(x+5, y+60), nsGraphics::Vec2D(x+15,y+50), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+15,y+50), nsGraphics::Vec2D(x+35, y+50), nsGraphics::Vec2D(x+25,y+60), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+35,y+50), nsGraphics::Vec2D(x+45, y+60), nsGraphics::Vec2D(x+45,y+50), nsGraphics::KBlue);
    window << nsShape::Circle(nsGraphics::Vec2D(x+33,y+25),5,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+18,y+25),5,nsGraphics::KWhite);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+12,y+40), nsGraphics::Vec2D(x+38,y+43), nsGraphics::KWhite);
}

void entities::drawEatableGhost2 (MinGL &window, const unsigned &x, const unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+25,y+25),20,nsGraphics::KBlue);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+5,y+50), nsGraphics::Vec2D(x+45, y+25), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+5,y+50), nsGraphics::Vec2D(x+15, y+60), nsGraphics::Vec2D(x+25,y+50), nsGraphics::KBlue);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+25,y+50), nsGraphics::Vec2D(x+35, y+60), nsGraphics::Vec2D(x+45,y+50), nsGraphics::KBlue);
    window << nsShape::Circle(nsGraphics::Vec2D(x+33,y+25),5,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+18,y+25),5,nsGraphics::KWhite);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+12,y+40), nsGraphics::Vec2D(x+38,y+43), nsGraphics::KWhite);
}

void entities::drawDeadGhost (MinGL &window, const unsigned &x, const unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+33,y+25),5,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+18,y+25),5,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+33,y+25),2,nsGraphics::KCyan);
    window << nsShape::Circle(nsGraphics::Vec2D(x+18,y+25),2,nsGraphics::KCyan);
}
