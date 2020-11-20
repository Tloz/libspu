namespace libspu
{
    class TDArray
    {
    private:
        int** m_array;
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

        // return all the numbers in row index
        int* row(int index) const;

        // return all the numbers in column index
        int* col(int index) const;

        // returns the number at (x;y) set top to true if you want to input 
        // your y value from the top (like a programmer)
        // or from the bottom (like a normal human beeing)
        int at(int x, int y, bool top = false) const;
        
        // replace current value at (x;y) with newVal
        // top is the same as above
        void set(int x, int y, int newVal, bool top = false);
        
        // returns the sum of all cells
        int sum() const;
        
        // returns the average value of all cells
        float average() const;
        
        // return the sum of all cells on given row
        int sumOnRow(int index) const;
        
        // return the sum of all cells on given column
        int sumOnCol(int index) const;
    };
}