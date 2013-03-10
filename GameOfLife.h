/* 
 * File:   GameOfLife.h
 * Author: kivi
 *
 * Created on March 10, 2013, 4:26 PM
 */

#ifndef GAMEOFLIFE_H
#define	GAMEOFLIFE_H

#include <cstdlib>
#include <SDL/SDL.h>
#include <iostream>

class GameOfLife {
public:
    int width, height, isRunning;
    SDL_Surface* screen;
    GameOfLife(int w_, int h_);
    void Draw();
    void Tick();
    virtual ~GameOfLife();
private:
    void setPixel(int x, int y, int rgb);
    int **map1;
    int **map2;
};

#endif	/* GAMEOFLIFE_H */

