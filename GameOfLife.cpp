/* 
 * File:   GameOfLife.cpp
 * Author: kivi
 * 
 * Created on March 10, 2013, 4:26 PM
 */

#include "GameOfLife.h"

GameOfLife::GameOfLife(int w_, int h_) {
    isRunning = true;
    width = w_;
    height = h_;
    //Start SDL
    
    map1 = new int*[width];
    map2 = new int*[width];
    
    for(int i=0; i<width; i++){
        map1[i] = new int[height];
        map2[i] = new int[height];
        for(int j=0; j<height; j++){
            if(i==0 || j==0 || i==width-1 || j==height-1){
                map1[i][j] = 0;
            }else{
                map1[i][j] = rand()%2;
            }
        }
    }
    
    SDL_Init( SDL_INIT_EVERYTHING );
    screen = SDL_SetVideoMode( width, height, 32, SDL_SWSURFACE );
}

void GameOfLife::Draw(){
    SDL_LockSurface(screen);
    for(int x=0; x<width; x++){
        for(int y=0; y<height; y++){
            if(map1[x][y] == 0){
                setPixel(x,y,0);
            }else{
                setPixel(x,y,0xffffff);
            }
        }
    }
    SDL_FreeSurface(screen);
    //Update Screen
    SDL_Flip( screen );
}

void GameOfLife::Tick(){
    SDL_Event event;
    while( SDL_PollEvent( &event ) ) {
        switch( event.type ) {
        case SDL_QUIT:
            isRunning = false;
            break;
        }
    }
    for(int i=1; i<width-1; i++){
        for(int j=1; j<height-1; j++){
            int c = 0;
            for(int x=i-1; x<=i+1; x++){
                for(int y=j-1; y<=j+1; y++){
                    c += map1[x][y];
                }
            }
            c -= map1[i][j];
            switch(c){
                case 2:
                    if(map1[i][j]){
                        map2[i][j] = 1;
                    }else{
                        map2[i][j] = 0;
                    }
                    break;
                case 3:
                    map2[i][j] = 1;
                    break;
                default:
                    map2[i][j] = 0;
                    break;
            }
        }
    }
    int **m1m = map1;
    map1 = map2;
    map2 = m1m; 
}

void GameOfLife::setPixel(int x, int y, int rgb){
    Uint8 * pixel = (Uint8*)screen->pixels;
    pixel += (y * screen->pitch) + (x * sizeof(Uint32));
    *((Uint32*)pixel) = rgb;
}



GameOfLife::~GameOfLife() {
    //Quit SDL
    SDL_Quit();
}

