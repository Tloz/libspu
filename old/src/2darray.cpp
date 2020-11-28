#include "../inc/2darray.h"
#include <iostream>
using namespace std;

libspu::TDArray::TDArray()
{
    #warning "TDArray class is deprecated since v0.2.2"

}

libspu::TDArray::TDArray(int width, int height, int defaultValue) : m_width(width), m_height(height)
{
    #warning "TDArray class is deprecated since v0.2.2"
    if((m_width * m_height) == 0)
        throw bad_alloc();

    m_array = new int*[m_height];
    for(int i = 0; i < m_height; i++)
    {
        m_array[i] = new int[m_width];
        for (int a = 0; a < m_width; ++a)
            m_array[i][a] = defaultValue;
    }
}

libspu::TDArray::~TDArray()
{
    delete [] m_array;
}

int libspu::TDArray::cardinal() const
{
    return m_height * m_width;
}

void libspu::TDArray::display(bool fancy) const
{
    if(fancy)
    {
        cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
        cout << " +--------------------+" << endl;
    }
    for(int y = 0; y < m_height; y++)
    {
        if(fancy)
            cout << y << "|";
        for(int x = 0; x < m_width; x++)
        {
            cout << m_array[y][x] << ' ';
        }
        if(fancy)
            cout << "| " << m_height - y - 1;
        cout << endl;
    }
    if(fancy)
    {
        cout << " +--------------------+" << endl;
        cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
    }
}

int libspu::TDArray::height() const
{
    return m_height;
}

int libspu::TDArray::width() const
{
    return m_width;
}

int* libspu::TDArray::row(int index, bool top) const
{
    if(top)
        return m_array[index];
    else
        return m_array[m_height - index - 1];
}

int* libspu::TDArray::col(int index) const
{
    int* set = new int[m_height];
    for (int y = 0; y < m_height; ++y)
        set[y] = m_array[y][index];
    return set;
}

int libspu::TDArray::at(int x, int y, bool top) const
{
    if(top)
        return m_array[y][x];
    else
        return m_array[m_height - y - 1][x];
}

void libspu::TDArray::set(int x, int y, int newVal, bool top)
{
    if(top)
        m_array[y][x] = newVal;
    else
        m_array[m_height - y - 1][x] = newVal; 
}

int libspu::TDArray::sum() const
{
    int sum = 0;
    for(int y = 0; y < m_height; ++y)
        for(int x = 0; x < m_width; ++x)
            sum+= m_array[y][x];
    return sum;
}

float libspu::TDArray::average() const
{
    return (1.0 * this->sum()) / (1.0 * this->cardinal());
}

int libspu::TDArray::sumOnRow(int index, bool top) const
{
    int sum = 0;
    int* set = this->row(index, top);
    for (int i = 0; i < m_width; ++i)
        sum += set[i];
    return sum;
}

int libspu::TDArray::sumOnCol(int index) const
{
    int sum = 0;
    int* set = this->col(index);
    for (int i = 0; i < m_height; ++i)
        sum += set[i];
    return sum;
}
