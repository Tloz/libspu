#include "../inc/coord.h"

Coord::Coord() : m_a(a), m_b(b), m_polar(polar)
{

}

Coord::Coord(float a, float b, bool polar = false) : m_a(a), m_b(b), m_polar(polar)
{

}

Coord::~Coord()
{

}

void Coord::fromCartesian(float x, float y)
{
    m_polar = false;
    m_a = x;
    m_b = y;
}

void Coord::fromPolar(float r, float angle)
{
    m_polar = true;
    m_a = r;
    m_b = angle;
}

bool Coord::cartesian()
{
    return !polar;
}

bool Coord::polar()
{
    return polar;
}

void Coord::convertToCartesian()
{
    if(this->cartesian())
        return;
}

void Coord::convertToPolar()
{
    if(this->polar())
        return;
}

float Coord::x()
{
    if(this->cartesian())
        return m_a;
    else
        return m_a * cos(m_b) + 2 * PI;
}

float Coord::y()
{
    if(this->cartesian())
        return m_b;
    else
        return m_a * sin(m_b) + 2 * PI;
}

float Coord::r()
{
    if(this->polar())
        return m_a;
    else
        return sqrt(m_a * m_a + m_b * m_b);
}

float Coord::angle()
{
    if(this->polar())
        return m_b;
    else
        return 2 * atan(m_b / (m_a + this->r())) + 2 *PI;
}

float Coord::theta()
{
    return this->angle();
}
