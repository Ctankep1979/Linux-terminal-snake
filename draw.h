#ifndef _H_DRAW_
#define _H_DRAW_

#include <chrono>   // for std::chrono and time
#include <thread>   // for independent threads
#include <ncurses.h>    // ncurses library
#include <vector>
#include "entity.h"     // different game charachters like snake and foods
#include "Keyboard.hpp" // tp handle keypress keyrelease and keyhold events

using namespace std;

class Draw
{
private:
    vector<thread> _entity_thread;
    Ctankep::Keyboard _keyboard;    // an instance of keyboard
    Snake* _snake;                  // our snake
    Food* _food;

private:
    void init();
    void deinit();
    void wait(int);     // halt for animation 
    void move(Direction d);
    void drawEntity(vector<uint8_t> x, vector<uint8_t> y, vector<char> shape);

public:
    Draw();
    ~Draw();
    void updateSnake();
    void updateFood();


};




#endif