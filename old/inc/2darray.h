#ifndef TDARRAY_H
#define TDARRAY_H

/***************************************************************************
*             Two Dimensionnal Array module for SimpleProjectUtilities
*
*   File    : 2darray.h
*   Author  : Emeric Frémion <ScrimeT@hotmail.fr>
*   Date    : November 22, 2020
*   Licence : The Unlicence - https://unlicense.org/
*   Repo    : https://github.com/Tloz/libspu
*   Purpose : Header for Two-Dimensionnal Array management.
*             Part of the SimpleProjectUtilities library
*
***************************************************************************/

/**************************************************************************\
*                              IMPORTANT NOTES                             *
****************************************************************************
*
*             Please note that the TDArray class deprecated as of v0.2.2
*             Next major version (1.0.0) will not support it anymore.
*             You will be able to update your code usin a matrix class
*             with more fun and less memory leaks (yup, I'll use vectors)
*
*             _________________________________________
*            / Be careful next time you update libspu, \
*            | as next upgrade will break backwards    |
*            \ compatibility for this module           /
*             -----------------------------------------
*                 \
*                  \
*                    ,__, |    | 
*                    (oo)\|    |___
*                    (__)\|    |   )\_
*                         |    |_w |  \
*                         |    |  ||   *
*
***************************************************************************/


/**************************************************************************\
*                 DECLARATION OF CLASS, MEMBERS AND METHOD                 *
\**************************************************************************/

namespace libspu
{
    class TDArray
    {
    private:
        int** m_array;
    protected:
        int m_width;
        int m_height;

    public:
        // ctors and dtors
        // this one is empty, do not use
        TDArray();
        // use this one
        TDArray(int width, int height, int defaultValue = 0);
        ~TDArray();

        // returns the number of cells in tab
        int cardinal() const;

        // displays the tab, fancy will show indexes
        void display(bool fancy = false) const;

        // returns width of the tab
        int width() const;

        // returns height of the tab
        int height() const;

        // return all the numbers in row index set top to true if you want to input 
        // your y value from the top (like a programmer)
        // or from the bottom (like a normal human beeing)
        int* row(int index, bool top = false) const;

        // return all the numbers in column index
        int* col(int index) const;

        // returns the number at (x;y) 
        // top is the same as with row method
        int at(int x, int y, bool top = false) const;
        
        // replace current value at (x;y) with newVal
        // top is the same as with row method
        void set(int x, int y, int newVal, bool top = false);
        
        // returns the sum of all cells
        int sum() const;
        
        // returns the average value of all cells
        float average() const;
        
        // return the sum of all cells on given row
        // top is the same as with row method
        int sumOnRow(int index, bool top = false) const;
        
        // return the sum of all cells on given column
        int sumOnCol(int index) const;
    };
}


#endif

