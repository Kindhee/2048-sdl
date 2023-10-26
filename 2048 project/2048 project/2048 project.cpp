#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include "grid.h"
#include <SDL.h>
#undef main

using namespace std;

const int texture_count = 1;

// window related 
SDL_Renderer* renderer = NULL;
SDL_Window* window;
int isRunning;
int fullscreen;
// window related 

// Function : necessary but not used
void update() {
    // ...
}


// Function : to test event in our window
void handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);


    switch (event.type) {
    case SDL_QUIT:
        isRunning = 0;
        break;
    default:
        break;
    }
}

// Function : to load all of our Images as SDL Textures and place them in a list
void loadBmpImg(SDL_Texture* tabBmpImg[texture_count]) {
    SDL_Surface* S0 = SDL_LoadBMP("img/board-grid.bmp");
    SDL_Texture* Bmp0 = SDL_CreateTextureFromSurface(renderer, S0);
    tabBmpImg[0] = Bmp0;
    SDL_FreeSurface(S0);
}

// Function : initializing our SDL window 
void initWindow() {
    int fullscreen = 0;
    int flags = 0;
    flags = SDL_WINDOW_RESIZABLE;
    if (fullscreen == 1) {
        flags = flags | SDL_WINDOW_FULLSCREEN;
    }



    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

        window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, flags);
        if (window) {
            SDL_SetWindowMinimumSize(window, 800, 800);
            SDL_SetWindowMaximumSize(window, 800, 800);
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_RenderPresent(renderer);
            isRunning = 1;
        }

    }
}

void showTable(int grid[size_gridC][size_gridC], SDL_Texture* tabBmpImg[texture_count]){

}

// Function : containing our Game
int windowGame(int initDone, SDL_Texture* tabBmpImg[texture_count]) {

    srand(time(NULL));

    int grid[size_gridC][size_gridC];
    Grid my_grid(grid);

    int valid_play;
    int end_of_game = 0;
    int zero = 0;

    while (isRunning == 1) {

        while (end_of_game == 0) {

            SDL_Event event;

            while (SDL_PollEvent(&event))
            {

                system("cls");

                valid_play = 0;

                my_grid.showTableC(grid);

                if (my_grid.testLooseC(grid, zero) == true) {
                    end_of_game = 1;
                }

                switch (event.type)
                {
                case SDL_KEYDOWN:

                    if (event.key.keysym.sym == SDLK_UP) {
                        my_grid.moveUpC(grid);
                        valid_play = 1;
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_DOWN) {
                        my_grid.moveDownC(grid);
                        valid_play = 1;
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT) {
                        my_grid.moveRightC(grid);
                        valid_play = 1;
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_LEFT) {
                        my_grid.moveLeftC(grid);
                        valid_play = 1;
                        break;
                    }

                case SDL_QUIT:
                    isRunning = 0;
                    break;

                default:
                    break;
                }
                if (valid_play == 1) {
                    zero = my_grid.newTilesC(grid);
                }
            }
        }
        return 0;
    }
}


int main(){

    initWindow();

    SDL_Rect rect;

    SDL_Texture* tabBmpImg[texture_count];
    loadBmpImg(tabBmpImg);

    rect.x = 0;
    rect.y = 0;
    rect.w = 800;
    rect.h = 800;
    SDL_Texture* TextureLoose = tabBmpImg[0];
    SDL_RenderCopy(renderer, TextureLoose, NULL, &rect);
    SDL_RenderPresent(renderer);


    windowGame(0, tabBmpImg);
       
}