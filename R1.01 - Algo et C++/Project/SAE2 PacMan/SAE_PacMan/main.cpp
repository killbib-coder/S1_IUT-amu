#define FPS_LIMIT 60

#include <iostream>
#include <thread>

#include "mingl/mingl.h"

#include "entities.h"
#include "map.h"

using namespace std;

Pacman PacMan;

void mouvment(MinGL &window){ // Fonction pour déplacer Pacman
    if(window.isPressed({GLUT_KEY_LEFT, true})){
        PacMan.mooveToLeft();
    }
    else if(window.isPressed({GLUT_KEY_RIGHT, true})){
        PacMan.mooveToRight();
    }
    else if(window.isPressed({GLUT_KEY_UP, true})){
        PacMan.mooveToUp();
    }
    else if(window.isPressed({GLUT_KEY_DOWN, true})){
        PacMan.mooveToDown();
    }
}

int main()
{
    // Initialise le système
    MinGL window("PacMan", nsGraphics::Vec2D(1200, 1080), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    // On fait tourner la boucle tant que la fenêtre est ouverte
    while (window.isOpen())
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        // On dessine la map
        environment::intiMap(window);

        // On récupère les entrées claviers
        mouvment(window);

        // On finit la frame en cours
        window.finishFrame();

        // On vide la queue d'évènements
        window.getEventManager().clearEvents();

        // On attend un peu pour limiter le framerate et soulager le CPU
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

        // On récupère le temps de frame
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }

    return 0;
}
