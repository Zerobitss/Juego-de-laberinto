#include "Player.h"
#include <iostream>
using namespace std;
Player::Player()
{
    x = 1;
    y = 1;
}
void Player::callInput()
{
        char userInput = ' ';
        cin >> userInput;


        switch(userInput)
        {
        case 'w':
                lastY = y;
                y = y - 1;
                cout << "El jugador se mueve arriba" << endl;
                break;
        case 's':
                lastY = y;
                y = y + 1;
                cout << "El jugador se mueve abajo" << endl;
                break;
        case 'd':
                lastX = x;
                x = x + 1;
                cout << "El jugador se mueve a la derecha" << endl;
                break;
        case 'a':
                lastX = x;
                x = x - 1;
                cout << "El jugador se mueve a la izquierda" << endl;
                break;
        case 'p':
                cout << "fin del juego" << endl;
                break;
        }
       // cout << "Mi jugador esta en las coordenadas: " << x << ", " << y << endl;
}
void Player::resetPosition()
{
    x = lastX;
    y = lastY;
}
Player::~Player()
{
    //dtor
}
