#define FPS_LIMIT 60

#include <iostream>
#include <thread>

#include "mingl/mingl.h"

#include "entite.h"

using namespace std;

void dessiner(MinGL &window)
{
    unsigned x=50;
    unsigned y=50;
    entite::dessinePacMan(window, x, y);
}

int main()
{
    // Initialise le système
    MinGL window("PacMan", nsGraphics::Vec2D(1920, 1080), nsGraphics::Vec2D(128, 128), nsGraphics::KBlack);
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

        // On dessine les formes géométriques
        //dessiner(window);

        entite::dessinePacMan(window, 0, 0);
        entite::dessineFantôme(window, 300, 0, nsGraphics::KGray);
        entite::dessineFantômeMangeable(window, 600, 0);
        entite::dessineFantômeMangeable2(window, 900, 0);
        entite::dessineFantômeMort(window, 1200, 0);


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
