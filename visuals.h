#ifndef VISUALS_H
#define VISUALS_H

/*SDL*/
#include <SDL2/SDL.h>

/*GEN*/
#include "incl.h"

#define COLOR_WARN "\x1b[33m"
#define COLOR_ERRO "\x1b[31m"
#define COLOR_NORM "\x1b[0m"



static int max_val = 0;
static int bar_count = 0;

static SDL_Window * window;
static SDL_Renderer * renderer;


int pass_info(int * array, int size);

void create();

void draw(int * array);
void draw_interface(int * array); /* don't know if I'm gonna use this */
void draw_bar(int xPos, int yPos, int w, int h);


void refresh(int * array);

int check_window();
int check_renderer();

void sleepMilliseconds(unsigned long milliseconds);

void clean_up();




#endif