#include "../inc/2darray.h"
#include <iostream>
using namespace std;

libspu::TDArray::TDArray()
{

}

libspu::TDArray::TDArray(int col, int row, int defaultValue) : m_col(col), m_row(row)
{
    m_array = new int*[m_row];
    for(int i = 0; i < m_row; i++)
        m_array[i] = new int[m_col];

    for (int i = 0; i < row; ++i)
        for (int j = 0; j < m_col; ++j)
            m_array[i][j] = defaultValue;
}

libspu::TDArray::~TDArray()
{
    delete [] m_array;
}

int libspu::TDArray::cardinal() const
{
    return m_row * m_col;
}

void libspu::TDArray::display() const
{
    for(int i = 0; i< m_row; i++)
    {
        for(int j = 0; j< m_col; j++)
        {
            cout << m_array[i][j] << ' ';
        }
        cout << endl;
    }
}

int libspu::TDArray::row() const
{
    return m_row;
}

int libspu::TDArray::col() const
{
    return m_col;
}

int* libspu::TDArray::row(int index) const
{
    return m_array[index];
}

int* libspu::TDArray::col(int index) const
{
    int* set = new int[m_row];
    for (int i = 0; i < m_row; ++i)
        set[i] = m_array[i][index]; // TODO : i and index
    return set;
}

int libspu::TDArray::at(int r, int c, bool top) const
{
    if(top)
        return m_array[c][r];
    else
        return m_array[m_row - c - 1][r];
}

void libspu::TDArray::set(int r, int c, int value, bool top)
{
    if(top)
        m_array[c][r] = value;
    else
        m_array[m_row - c - 1][r] = value; 
}

int libspu::TDArray::sum() const
{
    int sum = 0;
    for(int i = 0; i< m_row; i++)
        for(int j = 0; j< m_col; j++)
            sum+= m_array[i][j];
    return sum;
}

float libspu::TDArray::average() const
{
    return (1.0 * this->sum()) / (1.0 * this->cardinal());
}

int libspu::TDArray::sumOnRow(int index) const
{
    int sum = 0;
    int* set = this->row(index);
    for (int i = 0; i < m_col; ++i)
        sum += set[i];
    return sum;
}

int libspu::TDArray::sumOnCol(int index) const
{
    int sum = 0;
    int* set = this->col(index);
    for (int i = 0; i < m_row; ++i)
        sum += set[i];
    return sum;
}
