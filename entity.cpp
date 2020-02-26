#include "entity.h"


Entity::Entity(Direction d, uint8_t s, uint8_t l, uint8_t x, uint8_t  y, uint8_t maxX, uint8_t maxY): 
    _direction{d}, _speed{2}, _lenght{2}, maxX{maxX}, maxY{maxY}
{
    // if(x > maxX)
    //     x = 0;
    // if(y > maxY)
    //     y = 0;
    x_tail.push_back(x);
    y_tail.push_back(y);
}

bool
Entity::setShape(vector<char> shape, Direction d)
{
    this->shape = shape;
    uint8_t px = x_tail.at(0);
    uint8_t py = y_tail.at(0);

    x_tail.clear();
    y_tail.clear();
    _lenght = shape.size();
    for(int i = 0; i < shape.size(); i++)
    {
        switch (d)
        {
        case eLeft:
            x_tail.push_back(px);
            py = (py + i > maxY)? 0:py + i;
            y_tail.push_back(py);
            break;
        case eRight:
            x_tail.push_back(px);
            py = (py - i == 255)? 0:py - i;
            y_tail.push_back(py);
            break;
        case eUp:
            px = (px - i == 255)? 0:px - i;
            x_tail.push_back(px);
            y_tail.push_back(py);
            break;
        case eDown:
            px = (px + i > maxX)? 0:px + i;
            x_tail.push_back(px);
            y_tail.push_back(py);
            break;
        }
        
    }

    return true;    
}

bool
Entity::setPosition(vector<uint8_t> x, vector<uint8_t> y)
{
    if((x.size() != y.size()) || x.size() != _lenght)
    {
        return false;
    }
    x_tail = x;
    y_tail = y;
    return true;
}   

bool
Entity::setPosition(uint8_t x, uint8_t y)
{

    if(x_tail.size() == 0)
        return false;

    if(x >= maxX)
        x = 0;
    if(y >= maxY)
        y = 0;

    int16_t mx = x - x_tail.at(0);
    int16_t my = y - y_tail.at(0);

    for(int i=0;i<x_tail.size();i++)
    {
        x_tail.at(i) += mx;
        y_tail.at(i) += my;
    }
    return true;
}

bool
Entity::incLenght()
{
    uint8_t value;
    _lenght++;
    shape.push_back(shape.back());
    if(x_tail.at(x_tail.size()-1) == x_tail.at(x_tail.size()-2))
    {
        x_tail.push_back(x_tail.front());
        value = (y_tail.front()-1 == 255)? 0:y_tail.front()-1;
        y_tail.push_back(value);
    } else
    {
        value = (x_tail.front()-1 == 255)? 0:x_tail.front()-1;
        x_tail.push_back(x_tail.front()-1);
        y_tail.push_back(y_tail.front());
    } 
    return true;
}

bool
Entity::decLenght()
{
    
    if(_lenght < 3)
    {
        return false;
    }

    shape.pop_back();
    x_tail.pop_back();
    y_tail.pop_back();
    _lenght--;
    return true;
}


void
Entity::incX()
{
    uint8_t value;
    vector<uint8_t> x,y;
    value = (x_tail.at(0) >= maxX)? 0:x_tail.at(0)+1;
    x.push_back(value);
    y.push_back(y_tail.at(0));
    for(int i=1;i<_lenght;i++)
    {
        x.push_back(x_tail.at(i-1));
        y.push_back(y_tail.at(i-1));
    }
    x_tail = x;
    y_tail = y;
}

void
Entity::decX()
{
    vector<uint8_t> x,y;
    uint8_t value;
    value = (x_tail.at(0) == 255)? maxX:x_tail.at(0)-1;
    x.push_back(value);
    y.push_back(y_tail.at(0));
    for(int i=1;i<_lenght;i++)
    {
        x.push_back(x_tail.at(i-1));
        y.push_back(y_tail.at(i-1));
    }
    x_tail = x;
    y_tail = y;
}

void
Entity::incY()
{

    uint8_t value;
    vector<uint8_t> x,y;
    x.push_back(x_tail.at(0));
    value = (y_tail.at(0) >= maxY)? 0:y_tail.at(0)+1;
    y.push_back(value);
    for(int i=1;i<_lenght;i++)
    {
        x.push_back(x_tail.at(i-1));
        y.push_back(y_tail.at(i-1));
    }
    x_tail = x;
    y_tail = y;

}

void
Entity::decY()
{
    
    vector<uint8_t> x,y;
    uint8_t value;
    x.push_back(x_tail.at(0));
    value = (y_tail.at(0) == 255)? maxY:y_tail.at(0)-1;
    y.push_back(value);
    for(int i=1;i<_lenght;i++)
    {
        x.push_back(x_tail.at(i-1));
        y.push_back(y_tail.at(i-1));
    }
    x_tail = x;
    y_tail = y;

}

//=================================================================================


Snake::Snake(uint8_t x, uint8_t y, uint8_t maxX, uint8_t maxY) : Entity(eRight, 1, 1, x, y, maxX, maxY)
{
    vector<char> _shape = {'O', 'o'};
    setShape(_shape, eLeft);
}

//=================================================================================

Food::Food(uint8_t x, uint8_t y, uint8_t maxX, uint8_t maxY) : Entity(eStall, 0, 1, x, y, maxX, maxY)
{
    vector<char> _shape = {'H'};
    setShape(_shape, eLeft);
}