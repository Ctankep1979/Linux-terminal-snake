#include "draw.h"

Draw::Draw(): _keyboard{"/dev/input/event12"}
{
    
    _snake = new Snake(2,2);
}

Draw::~Draw()
{
    delete _snake;
}

void
Draw::init()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    cbreak();
    //raw();
}

void
Draw::deinit()
{
    endwin();
}

void
Draw::wait(int t)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(t));
}

void
Draw::drawEntity(std::vector<uint8_t> x, std::vector<uint8_t> y, vector<char> shape)
{
    if(x.size() != y.size())
    {
        printw("ERROOR!");
        exit(0);
    }

    for(int i = x.size()-1;i >= 0 ;i--)
    {
        mvaddch(x.at(i), y.at(i), shape.at(i));
    }
}


void
Draw::updateFood()
{
    bool loop = true;
    _food = new Food(10,10);
    init();
    while(loop)
    {
        //clear();
        drawEntity(_food->getX(), _food->getY(), _food->getShape());
        refresh();
        wait(5);
    }

}

void
Draw::updateSnake()
{
    int key = 0;
    bool loop = true;
    init();
    while(loop)
    {
        key = _keyboard.keyPress();
        switch (key)
        {
        case KEY_RIGHT:
            clear();
            _snake->incY();
            drawEntity(_snake->getX(), _snake->getY(), _snake->getShape());
            break;

        case KEY_LEFT:
            clear();
            _snake->decY();
            drawEntity(_snake->getX(), _snake->getY(), _snake->getShape());
            break;

        case KEY_UP:
            clear();
            _snake->decX();
            drawEntity(_snake->getX(), _snake->getY(), _snake->getShape());
            break;

        case KEY_DOWN:
            clear();
            _snake->incX();
            drawEntity(_snake->getX(), _snake->getY(), _snake->getShape());
            break;
        case KEY_ESC:
            loop = false;
            break;
        default:
            break;
        }
        refresh();
        wait(5);
        
    }


    deinit();
}