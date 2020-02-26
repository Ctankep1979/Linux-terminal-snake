#include "draw.h"

Ctankep::Keyboard Draw::_keyboard("/dev/input/event12");
Snake *Draw::_snake;
Food *Draw::_food;
bool Draw::_run = false;
int Draw::scrMaxX;
int Draw::scrMaxY;

Draw::Draw()
{
    srand(time(NULL));
}

Draw::~Draw()
{
    delete Draw::_snake;
    delete Draw::_food;

}

void
Draw::init()
{
    initscr();
    getmaxyx(stdscr, scrMaxY, scrMaxX);
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    cbreak();
    Draw::_snake = new Snake(1,15, scrMaxY, scrMaxX);
    Draw::_food = new Food(10,10, scrMaxY, scrMaxX);
}

void
Draw::deinit()
{
    getch();
    Draw::_run = false;
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
    int xp;
    int yp;
    if(x.size() != y.size())
    {
        printw("ERROOR!");
        exit(0);
    }

    for(int i = x.size()-1;i >= 0 ;i--)
    {
        xp = x.at(i);
        yp = y.at(i);
        
        mvaddch(xp, yp, shape.at(i));
    }
}

void
Draw::update()
{
    uint16_t cnt = 0;
    uint16_t time = rand()%100 + 100;
    init();
    _entity_thread = thread(updateSnake);
    _entity_thread.detach();
    Draw::_run = true;
    do
    {
        if(cnt++ > time)
        {
            time = updateFood(600);
            cnt = 0;
        }
        clear();
        drawEntity(Draw::_food->getX(), Draw::_food->getY(), Draw::_food->getShape());
        drawEntity(_snake->getX(), _snake->getY(), _snake->getShape());
        refresh();
        wait(5);
        
    } while(Draw::_run);
    clear();
    printw("GAME OVER!");
    refresh();
    getch();
    deinit();

}


uint16_t
Draw::updateFood(uint16_t offset)
{
    uint16_t time = rand()%100 + offset;
    uint8_t newX;
    uint8_t newY;
    newX =  rand() % scrMaxY;
    newY = rand() % scrMaxX;
    Draw::_food->setPosition(newX, newY);
    return time;
}

bool
Draw::updateSnake()
{ 
    int key = 0;
    bool run = false;
    do
    {
        key = _keyboard.keyPress();
        switch (key)
        {
        case KEY_RIGHT:
            _snake->incY();
            break;

        case KEY_LEFT:
            _snake->decY();
            break;

        case KEY_UP:
            _snake->decX();
            break;

        case KEY_DOWN:
            _snake->incX();
            break;
        case KEY_ESC:
            Draw::_run = false;
            return false;
            break;
        case KEY_SPACE:
            break;
        default:
            break;
        }
    if(Draw::_snake->getX().at(0) == Draw::_food->getX().at(0) && 
                Draw::_snake->getY().at(0) == Draw::_food->getY().at(0))
                {
                    Draw::updateFood(600);
                    _snake->incLenght();
                }

    for(int i=1;i < Draw::_snake->getLenght();i++)
    {
        if(Draw::_snake->getX().at(0) == _snake->getX().at(i) && 
                Draw::_snake->getY().at(0) == Draw::_snake->getY().at(i) && run == true)
                {
                    Draw::_run = false;
                    return false;
                }
    }
    run = true;
    } while(Draw::_run);
    
    return true; 
}