// #include "../inc/matrix2d.h"
#include <iostream>
#include <vector>

namespace libspu
{
    template<class TYPE>
    class Matrix2D
    {
    private:
        size_t m_height, m_width;
        std::vector<TYPE> m_matrix;
    public:
        Matrix2D(size_t numrows, size_t numcols) :
                m_height(numrows), m_width(numcols), m_matrix(m_height * m_width)
        {
            if((m_height * m_width) == 0)
                throw std::logic_error("None of the dimension can be zero.");
        }

        Matrix2D(size_t numrows, size_t numcols, TYPE init) :
                m_height(numrows), m_width(numcols), m_matrix(m_height * m_width, init)
        {
            if((m_height * m_width) == 0)
                throw std::logic_error("None of the dimension can be zero.");
        }

        TYPE & operator()(size_t x, size_t y)
        {
            // As a size_t is always at least 0, we don't have to check if
            // the coordinates are below zero, just over dimensions
            if(x >= m_width)
                throw std::out_of_range("x has to be less than " + std::to_string(m_width) + " (current x = " + std::to_string(x) + ")");
            if(y >= m_height)
                throw std::out_of_range("y has to be less than " + std::to_string(m_width) + " (current y = " + std::to_string(y) + ")");
            return m_matrix[y * m_width + x];
        }

        TYPE operator()(size_t x, size_t y) const
        {
            
            // As a size_t is always at least 0, we don't have to check if
            // the coordinates are below zero, just over dimensions
            // if(x >= m_width)
            //     throw std::out_of_range("x has to be less than " + std::to_string(m_width) + " (current x = " + std::to_string(x) + ")");
            // if(y >= m_height)
            //     throw std::out_of_range("y has to be less than " + std::to_string(m_width) + " (current y = " + std::to_string(y) + ")");
            return m_matrix[y* m_width + x];
        }

        size_t getRows() const
        {
            return m_height;
        }
        size_t getColumns() const
        {
            return m_width;
        }
        friend std::ostream & operator<<(std::ostream & out, const Matrix2D & in)
        {
            for (int i = 0; i < in.getRows(); i++)
            {
                for (int j = 0; j < in.getColumns(); j++)
                {
                    out << in(i, j) << ' ';
                }
                out << std::endl;
            }

            return out;
        }
    };
}