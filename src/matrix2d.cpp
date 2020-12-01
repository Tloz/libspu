#ifndef MATRIX2D_H
#define MATRIX2D_H

/***************************************************************************
*             2 Dimensionnal Matrix module for SimpleProjectUtilities
*
*   File    : matrix2d.h
*   Author  : Emeric Frémion <ScrimeT@hotmail.fr>
*   Date    : November 22, 2020
*   Licence : The Unlicence - https://unlicense.org/
*   Repo    : https://github.com/Tloz/libspu
*   Purpose : Header for managing 2D Matrix objetcs.
*             Part of the SimpleProjectUtilities library
*
***************************************************************************/

/**************************************************************************\
*                              IMPORTANT NOTES                             *
****************************************************************************
*
*       Since the TDArray class has been deprecated in v0.2.2, this is the
*       class that will do roughly the same job in a more clean and
*       efficient way. The dimensions are not needed at compile time.
*
***************************************************************************
*
*       It is currently not possible to have template declaration separated
*       from it's implementation (see https://stackoverflow.com/questions\
*       /495021/why-can-templates-only-be-implemented-in-the-header-file
*       and https://stackoverflow.com/questions/5417465/separating-template\
*       -interface-and-implementation-in-c for more info).
*       So enjoy the source here. Thanks, C++
*
***************************************************************************/


/**************************************************************************\
*                  REQUIRED HEADERS AND MACRO DEFINITION                   *
\**************************************************************************/

#include <iostream>
#include <vector>

/**************************************************************************\
*                DECLARATION OF CLASS, MEMBERS AND METHODS                 *
\**************************************************************************/
// This part is outrageously stolen from https://stackoverflow.com/\
// questions/37259936/template-c-to-allocate-dynamic-matrix-2d

using namespace std;

namespace libspu
{
    template<class TYPE>
    class Matrix2D
    {
    private:
        size_t m_height, m_width;
        std::vector<TYPE> m_matrix;
    public:
        Matrix2D(size_t height, size_t width) :
                m_height(height), m_width(width), m_matrix(m_height * m_width)
        {
            if((m_height * m_width) == 0)
                throw std::logic_error("None of the dimension can be zero.");
        }

        Matrix2D(size_t height, size_t width, TYPE init) :
                m_height(height), m_width(width), m_matrix(m_height * m_width, init)
        {
            if((m_height * m_width) == 0)
                throw std::logic_error("None of the dimension can be zero.");
        }

        // This function is used when you want to acces an element to replace it
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
            return m_matrix[y * m_width + x];
        }

        size_t height() const
        {
            return m_height;
        }

        size_t width() const
        {
            return m_width;
        }

        friend std::ostream & operator<<(std::ostream & out, const Matrix2D & in)
        {
            for (unsigned int i = 0; i < in.height(); i++)
            {
                for (unsigned int j = 0; j < in.width(); j++)
                {
                    out << in(i, j) << ' ';
                }
                out << std::endl;
            }

            return out;
        }

        size_t cardinal() const
        {
            return m_width * m_height;
        }
    };

    template<class TYPE>
    std::ostream &operator<<(ostream &flux, Matrix2D<TYPE> const& mat)
    {
        for (int y = 0; y < mat.height(); ++y)
        {
            for (int x = 0; x < mat.width(); ++x)
            {
                flux << mat(x, y) << " ";
            }
            flux << std::endl;
        }
    }
}

#endif // MATRIX2D_H /*************** END OF FILE - matrix2d.h **************/

