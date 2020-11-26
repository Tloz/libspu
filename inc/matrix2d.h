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
*       Since the TDstd::array class has been deprecated in v0.2.2, this is the
*       class that will do roughly the same job in a more clean and
*       efficient way. The dimensions are not needed at compile time.
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
// This part is outrageously stolen from https://stackoverflow.com/questions/37259936/template-c-to-allocate-dynamic-matrix-2d

namespace libspu
{
    template<class TYPE>
    class Matrix2D
    {
    public:
        Matrix2D(size_t numrows, size_t numcols);
        Matrix2D(size_t numrows, size_t numcols, TYPE init);
        ~Matrix2D();
        TYPE & operator()(size_t x, size_t y);
        TYPE operator()(size_t x, size_t y) const;
        size_t getRows() const;
        size_t getColumns() const;
        friend std::ostream & operator<<(std::ostream & out, const Matrix2D & in);
    };
}

    ///////////////////////////////////////////////////////////////////////////////
        /*
    class Matrix2D
    {
    private:
        size_t m_width;
        size_t m_height;
        std::array< std::array<typename T, m_height>, m_width> m_data;

    public:
        // ctors and dtors
        // this one is empty, do not use
        Matrix2D();
        // use this one
        Matrix2D(size_t width, size_t height, <typename T> type);
        ~Matrix2D();

        // fills all cells with default value
        void init(template<typename T> defaultValue);

        // returns the number of cells in matrix
        size_t cardinal() const;

        // displays the matrix, fancy will show indexes
        void display(bool fancy = false) const;

        // returns width of the matrix
        size_t width() const;

        // returns height of the matrix
        size_t height() const;

        // return all the numbers in row index set top to true if you want to input 
        // your y value from the top (like a programmer)
        // or from the bottom (like a normal human beeing)
        <typename T> row(int index, bool top = false) const;

        // return all the numbers in column index
        <typename T> col(int index) const;

        // returns the number at (x;y) 
        // top is the same as with row method
        <typename T> at(int x, int y, bool top = false) const;
        
        // replace current value at (x;y) with newVal
        // top is the same as with row method
        void set(int x, int y, <typename T> newVal, bool top = false);
    };
    */

#endif // MATRIX2D_H /*************** END OF FILE - matrix2d.h **************/

