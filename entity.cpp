#include "entity.h"


Entity::Entity(Direction d, uint8_t s, uint8_t l): _direction{d}, _speed{2}, _lenght{2} {}

bool
Entity::setShape(vector<char> shape, Oriention o)
{
    this->shape = shape;
    uint8_t px = x_tail.at(0);
    uint8_t py = y_tail.at(0);

    x_tail.clear();
    y_tail.clear();
    _lenght = shape.size();
    for(int i = 0; i < shape.size(); i++)
    {
        switch (o)
        {
        case oLeft:
            x_tail.push_back(px);
            y_tail.push_back(py+i);
            break;
        case oRight:
            x_tail.push_back(px);
            y_tail.push_back(py-i);
            break;
        case oUp:
            x_tail.push_back(px-i);
            y_tail.push_back(py);
            break;
        case oDown:
            x_tail.push_back(px+i);
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
Entity::incLenght()
{
    _lenght++;
    shape.push_back(shape.front());
    if(x_tail.at(x_tail.size()-1) == x_tail.at(x_tail.size()-2))
    {
        x_tail.push_back(x_tail.front());
        y_tail.push_back(y_tail.front()-1);
    } else
    {
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
    vector<uint8_t> x,y;
    x.push_back(x_tail.at(0)+1);
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
    x.push_back(x_tail.at(0)-1);
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
    
    vector<uint8_t> x,y;
    x.push_back(x_tail.at(0));
    y.push_back(y_tail.at(0)+1);
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
    x.push_back(x_tail.at(0));
    y.push_back(y_tail.at(0)-1);
    for(int i=1;i<_lenght;i++)
    {
        x.push_back(x_tail.at(i-1));
        y.push_back(y_tail.at(i-1));
    }
    x_tail = x;
    y_tail = y;

}

//=================================================================================


Snake::Snake(uint8_t x, uint8_t y) : Entity(eRight, 2, 2)
{
    vector<char> _shape = {'O', 'o'};
    vector<uint8_t> x_tail;
    vector<uint8_t> y_tail;
    setShape(_shape);

    for(int i = 0; i < 2; i++)
    {
        x_tail.push_back(x);
        y_tail.push_back(y+i);
    }

    setPosition(x_tail,y_tail);
    
}

//=================================================================================

Food::Food(uint8_t x, uint8_t y) : Entity(eStall, 0, 1)
{
    vector<char> _shape = {'H'};
    setShape(_shape);
    vector<uint8_t> x_tail;
    vector<uint8_t> y_tail;
    x_tail.push_back(x);
    y_tail.push_back(y);
    setPosition(x_tail,y_tail);
}