#include <iostream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"
using namespace std;

int main()
{
    GameMap Map;//creacion de objeto
    Map.drawIntro();
    Map.draw();
    Player Hero;
    //cout << "Inicio el juego!" <<endl;
    while (Map.isGameOver == false)
    {
        cout << "Introduce el movimiento mediate 'W' 'S' 'D' 'A'" << endl;
        Hero.callInput();// input del jugador
        if(Map.setPlayerCell(Hero.x,Hero.y)) //actualizador de posicion del jugador
        {
            Map.draw();// dibujar el mapa
        }
        else
        {
            Hero.resetPosition();
            Map.draw();
        }
    }
    return 0;
}
