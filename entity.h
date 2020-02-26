#ifndef _H_ENTITY_
#define _H_ENTITY_

#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

enum
Direction : uint8_t {eLeft, eRight, eUp, eDown, eStall};

class
Entity
{
private:
    Direction _direction;   // direction of entity
    uint8_t _speed;         // speed of entity
    uint8_t _lenght;        // lenght of entity

    uint8_t maxX;
    uint8_t maxY;

    vector<uint8_t> x_tail; // vector of x positions of the entity in a 2D space
    vector<uint8_t> y_tail; // vector of y positions of the entity in a 2D space
    vector<char> shape;     // shape of entity for each block        
public:
    Entity(Direction d, uint8_t s, uint8_t l, uint8_t x, uint8_t  y, uint8_t maxX, uint8_t maxY);

    void
    setmax(uint8_t mx, uint8_t my){maxX = mx; maxY = my;}

    uint8_t
    getLenght() const {return _lenght;}

    void
    setLenght(uint8_t l){ _lenght = l;}

    void
    setDirection(Direction direction){_direction = direction;}
    
    Direction
    getDirection() const {return _direction;}

    void
    setSpeed(uint8_t speed){_speed = speed;}

    uint8_t
    getSpeed() const {return _speed;}

    vector<uint8_t>
    getX() {return x_tail;}

    vector<uint8_t> getY()
    {return y_tail;}

    bool
    setPosition(vector<uint8_t> x, vector<uint8_t> y);

    bool
    setPosition(uint8_t x, uint8_t y);

    bool
    setShape(vector<char> shape, Direction d);

    vector<char>
    getShape(){return shape;}

    void
    incX();

    void
    incY();

    void
    decX();

    void
    decY();
    
    bool
    incLenght();

    bool
    decLenght();

};


class
Snake : public Entity
{
private:
    const uint8_t MAXSIZE = 5;

public:
    Snake(uint8_t x, uint8_t y, uint8_t maxX, uint8_t maxY);

};


class
Food : public Entity
{

public:
    Food(uint8_t x, uint8_t y, uint8_t maxX, uint8_t maxY);

};


#endif