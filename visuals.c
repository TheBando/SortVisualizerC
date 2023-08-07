#include "visuals.h"


/* Window dimensions */
const int WIDTH = 1024;
const int HEIGHT = 720;
/*********************/

void create()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "Sort Visualizer",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,HEIGHT, SDL_WINDOW_SHOWN );
        
    if (window == NULL)
    {
        fprintf(stderr, "An error occurred: %s\n", COLOR_ERRO "NULL WINDOW" COLOR_NORM);
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        fprintf(stderr, "An error occurred: %s\n", COLOR_ERRO "NULL RENDERER" COLOR_NORM);
        exit(EXIT_FAILURE);
    }
    
}

int pass_info(int * array, int size)
{
    bar_count = size;
    for (int i = 0; i < size; i++){
        if (*(array + i) > max_val)
            max_val = *(array + i);
    }
    if (bar_count == 0 || max_val == 0)
        return -1;
    printf("bar_count: %d\n", bar_count);
    return 0; /* I had anticipated returning something like -1 if things went wrong, but there aren't
                many checks here.*/
}

void draw(int * array)
{
    /*draw_interface(array); Not ready until text is */
    int x = 0; int y = 10;
    int h = 500; int w = (WIDTH - (WIDTH * 0.1f)) / bar_count;
    SDL_SetRenderDrawColor(renderer, 20, 20, 255, 255);
    for (int i = 0; i < bar_count; i ++)
    {
        int array_val = *(array + i);
        int bar_height = (array_val * h) / max_val;
        int y_offset = h - bar_height; 
        draw_bar(x, y + y_offset, w, bar_height);
        sleepMilliseconds(120);
        x+=(w+(w*0.05f));
    }
}

void draw_interface(int * array)
{
    int spacing = (WIDTH-50) / bar_count;
    int x = 50;
    int y = HEIGHT - 50;
    /* need to implement text before this can be finished */
}

/* (x,y) is top left of the rectangle being drawn */
void draw_bar(int xPos, int yPos, int w, int h)
{
    SDL_Rect rect;
    rect.x = xPos;
    rect.y = yPos;
    rect.w = w;
    rect.h = h;

    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);

}


void refresh(int * array)
{
    /*black*/
    /*SDL_SetRenderDrawColor(renderer, 1, 1, 1, 255);*/
    /*white*/
    /*SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); */
    /*******/
    SDL_SetRenderDrawColor(renderer, 1, 1, 1, 255);
    SDL_RenderClear(renderer);
    draw(array);
    SDL_RenderPresent(renderer);

}

void sleepMilliseconds(unsigned long milliseconds) 
{
    unsigned long start = SDL_GetTicks();
    unsigned long now = start;
    while ((now - start) < milliseconds)
    {
        SDL_PumpEvents(); // Process pending events
        now = SDL_GetTicks();
    }
}

void clean_up()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}