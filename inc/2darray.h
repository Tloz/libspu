namespace libspu
{
    class TDArray
    {
    private:
        int** m_array;
        int m_row;
        int m_col;

    public:
        TDArray();
        TDArray(int col, int row, int defaultValue = 0);
        ~TDArray();
        int cardinal() const;
        void display() const;
        int row() const;
        int col() const;
        int* row(int index) const;
        int* col(int index) const;
        int at(int c, int r, bool top = false) const;
        void set(int c, int r, int value, bool top = false);
        int sum() const;
        float average() const;
        int sumOnRow(int index) const;
        int sumOnCol(int index) const;
    };
}