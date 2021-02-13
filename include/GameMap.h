#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "MapCell.h"

class GameMap
{
    public:
        GameMap();
        MapCell* playerCell;
        virtual ~GameMap();
        MapCell cells [15][10]; // arreglo bidimensional herencia del archivo MapCell.h
        void draw();
        void drawIntro();
        void drawVictory();
        bool setPlayerCell (int playerX, int playerY);
        bool isGameOver = false;
    protected:
    void loadFromFile();
    private:
};

#endif // GAMEMAP_H
