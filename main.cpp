/* 
 * File:   main.cpp
 * Author: kivi
 *
 * Created on March 10, 2013, 4:18 PM
 */

#include "GameOfLife.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    GameOfLife gol(1300,600);
    while(gol.isRunning){
        gol.Draw();
        SDL_Delay( 20 );
        gol.Tick();        
    }
    return 0;
}

