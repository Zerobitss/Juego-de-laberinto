#include "GameMap.h"
#include <iostream>
#include <fstream>
using namespace std;
GameMap::GameMap()
{
    //ctor
    playerCell = NULL;
    loadFromFile();
    isGameOver = false;
}
void GameMap::draw()
{
    for (int x = 0; x < 15; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            cout << cells [x][y].id;
        }
        cout << endl;
    }
}
bool GameMap::setPlayerCell(int playerX, int playerY)
{
    if (cells[playerY][playerX].id == '$')
    {
        drawVictory();
        isGameOver = true;
        return true;
    }
    if (cells[playerY][playerX].isBlocked() == false)
    {
        if (playerCell != NULL)
        {
        playerCell->id = 0;
        }
        playerCell = &cells[playerY] [playerX]; // Con esto tenemos la direccion de la celda en la posicion del heroe
        playerCell->id = 3;
        //cout << "Las coordenadas del hero son: " << playerX << ", " << playerY <<endl;
        return true;
    }
    else
    {
        return false;
    }
}
void GameMap :: loadFromFile()
{
    /*ofstream fileCreate("Map.txt");
    if (fileCreate.is_open())
    {
        cout << "Good" << endl;
    }
    else
    {
        cout << "ERROR" << endl;
    }*/
    string line;
    int fila = 0;
    ifstream myFile("Map.txt");
    if (myFile.is_open())
    {   //cout <<"Inicio de prueba" << endl;
        while(getline (myFile, line))
        {
            for (int i = 0; i < line.length(); i++)
            {   if(line[i] == '0')
                {
                  cells [fila] [i].id = 0;
                }
                else
                {
                   cells [fila] [i].id = line [i];
                }

            }
            fila++;
        }
            //cout << "Fin de prueba" <<endl;
    }
    else{
        cout << "Error 504"<<endl;
    }
}
void GameMap::drawIntro()
{
    string line;
    ifstream myFile("Intro.txt");
    if (myFile.is_open())
    {   //cout <<"Inicio de prueba" << endl;
        while(getline (myFile, line))
        {
            cout << line << endl;
        }
            cin >> line; // para hacer la accion de pasar al siguiente escenario
    }
    else
        {
            cout <<"No pude cargar el intro" << endl;
        }
}
void GameMap::drawVictory()
{
    string line;
    ifstream myFile("Victory.txt");
    if (myFile.is_open())
    {   //cout <<"Inicio de prueba" << endl;
        while(getline (myFile, line))
        {
            cout << line << endl;
        }
            cin >> line; // para hacer la accion de pasar al siguiente escenario
    }
    else
        {
            cout <<"No pude cargar la victoria" << endl;
        }
}
GameMap::~GameMap()
{
    //dtor
}
