#ifndef _H_DRAW_
#define _H_DRAW_

#include <iostream>

#include <chrono>   // for std::chrono and time
#include <thread>   // for independent threads
#include <ncurses.h>    // ncurses library
#include <time.h>       // for srand number generator
#include <vector>
#include "entity.h"     // different game charachters like snake and foods
#include "Keyboard.hpp" // tp handle keypress keyrelease and keyhold events

using namespace std;

class Draw
{
private:
    static int scrMaxX;
    static int scrMaxY;
    thread _entity_thread;
    
    static
    Ctankep::Keyboard _keyboard;    // an instance of keyboard

    static
    Snake* _snake;                  // our snake

    static
    Food* _food;

    static
    bool _run;

private:
    void
    init();

    void
    deinit();

    static void
    wait(int);     // halt for animation 

    void
    move(Direction d);

    void
    drawEntity(vector<uint8_t> x, vector<uint8_t> y, vector<char> shape);

public:
    Draw();
    ~Draw();

    void
    update();

    static bool
    updateSnake();

    static uint16_t
    updateFood(uint16_t offset);
};

#endif