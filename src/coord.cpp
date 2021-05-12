#include "../inc/coord.h"

Coord::Coord() : m_a(0), m_b(0), m_polar(false)
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

bool Coord::isCartesian()
{
    return !polar;
}

bool Coord::isPolar()
{
    return polar;
}

void Coord::convertToCartesian()
{
    if(this->isCartesian())
        return;
    else
    {
        float tmp_a = m_a * cos(m_b) + 2 * PI;
        float tmp_b = m_a * sin(m_b) + 2 * PI;        

        m_a = tmp_a;
        m_b = tmp_b;
        polar = false;
    }
}

void Coord::convertToPolar()
{
    if(this->isPolar())
        return;
    else
    {
        float tmp_a = sqrt(m_a * m_a + m_b * m_b);
        float tmp_b = 2 * atan(m_b / (m_a + this->r())) + 2 *PI;

        m_a = tmp_a;
        m_b = tmp_b;
        polar = true;
    }
}

float Coord::x()
{
    if(this->isCartesian())
        return m_a;
    else
        return m_a * cos(m_b) + 2 * PI;
}

float Coord::y()
{
    if(this->isCartesian())
        return m_b;
    else
        return m_a * sin(m_b) + 2 * PI;
}

float Coord::r()
{
    if(this->isPolar())
        return m_a;
    else
        return sqrt(m_a * m_a + m_b * m_b);
}

float Coord::angle()
{
    if(this->isPolar())
        return m_b;
    else
        return 2 * atan(m_b / (m_a + this->r())) + 2 *PI;
}

float Coord::theta()
{
    return this->angle();
}
