#include <iostream>
#include <thread>

#include "mingl/mingl.h"

#include "mingl/shape/rectangle.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/triangle.h"

#include "entities.h"

using namespace std;

// Pacman
void entities::drawPacmanOpen (MinGL &window, const unsigned &x, const unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+30, y+30), 25, nsGraphics::KYellow);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+30, y+30), nsGraphics::Vec2D(x+55, y+20), nsGraphics::Vec2D(x+55,y+40), nsGraphics::KBlack);
    window << nsShape::Circle(nsGraphics::Vec2D(x+30, y+20), 3, nsGraphics::KBlack);
}
void entities::drawPacmanClosed (MinGL &window, const unsigned &x, const unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+30, y+30), 25, nsGraphics::KYellow);
    window << nsShape::Circle(nsGraphics::Vec2D(x+30, y+20), 3, nsGraphics::KBlack);
}
void Pacman::showPacman(MinGL &window){
    if (Pacman::spriteId == 1 ) entities::drawPacmanOpen(window, Pacman::getX(), Pacman::getY());
    else if (Pacman::spriteId == 2 ) entities::drawPacmanClosed(window, Pacman::getX(), Pacman::getY());
}
void Pacman::setX(unsigned n) {  // Method/function defined inside the class
    Pacman::x = n;
}
void Pacman::setY(unsigned n) {  // Method/function defined inside the class
    Pacman::y = n;
}
unsigned Pacman::getX() {  // Method/function defined inside the class
    return x;
}
unsigned Pacman::getY() {  // Method/function defined inside the class
    return y;
}
void Pacman::mooveToLeft() {  // Method/function defined inside the class
    cout << "left";
}
void Pacman::mooveToRight() {  // Method/function defined inside the class
    cout << "right";
}
void Pacman::mooveToUp() {  // Method/function defined inside the class
    cout << "up";
}
void Pacman::mooveToDown() {  // Method/function defined inside the class
    cout << "down";
}

// Ghost
void entities::drawGhost (MinGL &window, const unsigned &x, const unsigned &y, const nsGraphics::RGBAcolor &Couleur){
    window << nsShape::Circle(nsGraphics::Vec2D(x+25,y+25),20,Couleur);
    window << nsShape::Rectangle(nsGraphics::Vec2D(x+5,y+50), nsGraphics::Vec2D(x+45, y+25), Couleur);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+5,y+50), nsGraphics::Vec2D(x+5, y+60), nsGraphics::Vec2D(x+15,y+50), Couleur);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+15,y+50), nsGraphics::Vec2D(x+35, y+50), nsGraphics::Vec2D(x+25,y+60), Couleur);
    window << nsShape::Triangle(nsGraphics::Vec2D(x+35,y+50), nsGraphics::Vec2D(x+45, y+60), nsGraphics::Vec2D(x+45,y+50), Couleur);
    window << nsShape::Circle(nsGraphics::Vec2D(x+33,y+25),5,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+18,y+25),5,nsGraphics::KWhite);
    window << nsShape::Circle(nsGraphics::Vec2D(x+33,y+25),2,nsGraphics::KBlack);
    window << nsShape::Circle(nsGraphics::Vec2D(x+18,y+25),2,nsGraphics::KBlack);
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
    window << nsShape::Circle(nsGraphics::Vec2D(x+33,y+25),2,nsGraphics::KBlack);
    window << nsShape::Circle(nsGraphics::Vec2D(x+18,y+25),2,nsGraphics::KBlack);
}
void Ghost::draw(MinGL &window, const nsGraphics::RGBAcolor &Couleur){ // Fonction pour dessiner le fantôme en fonction de son statut (spiteId)
    switch (Ghost::spriteId) {
    case 1:
        entities::drawGhost(window, Ghost::x, Ghost::y, Couleur);
        break;
    case 2:
        entities::drawEatableGhost(window, Ghost::x, Ghost::y);
        break;
    case 3:
        entities::drawEatableGhost2(window, Ghost::x, Ghost::y);
        break;
    case 4:
        entities::drawDeadGhost(window, Ghost::x, Ghost::y);
        break;
    default:
        entities::drawGhost(window, Ghost::x, Ghost::y, Couleur);
        break;
    }
}
void Ghost::setX(unsigned n){
    Ghost::x=n;
}
void Ghost::setY(unsigned n){
    Ghost::y=n;
}
unsigned Ghost::getX(){
    return Ghost::x;
}
unsigned Ghost::getY(){
    return Ghost::y;
}
void Ghost::moveToRight(){
    Ghost::x+=1;
}
void Ghost::moveToLeft(){
    Ghost::x-=1;
}
void Ghost::moveToUp(){
    Ghost::y-=1;
}
void Ghost::moveToDown(){
    Ghost::y+=1;
}
void Ghost::isEated(){

}


void entities::drawBall(MinGL &window, const unsigned &x, const unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+30, y+30), 5, nsGraphics::KYellow);
}

void entities::drawBigBall(MinGL &window, const unsigned &x, const unsigned &y){
    window << nsShape::Circle(nsGraphics::Vec2D(x+30, y+30), 10, nsGraphics::KYellow);
}
