#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix()
    {
        columns = 0;
        rows = 0;
    };
    Matrix(int num_rows, int num_columns)
    {
        Reset(num_rows, num_columns);
    }
    void Reset(int num_rows, int num_columns)
    {
        if (num_rows < 0)
        {
          throw out_of_range("num_rows must be >= 0");
        }
        if (num_columns < 0)
        {
          throw out_of_range("num_columns must be >= 0");
        }
        if (num_rows == 0 || num_columns == 0)
        {
          num_rows = num_columns = 0;
        }
        rows = num_rows;
        columns = num_columns;
        matr.assign(num_rows, vector<int>(num_columns));
      }
    int At ( int row,  int col) const
    {
//        if (row < 0 || col < 0 || row > matr.size() || col > matr[0].size())
//            throw out_of_range("at");
        return matr.at(row).at(col);
    }
    int& At ( int row,  int col)
    {
//        if (row < 0 || col < 0 || row > matr.size() || col > matr[0].size())
//            throw out_of_range("at");
        return matr.at(row).at(col);
    }
    int GetNumRows () const
    {
        return rows;
    }
    int GetNumColumns () const
    {
        return columns;
    }

private:
    vector<vector<int>> matr;
    int columns, rows;
};

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.GetNumColumns() != rhs.GetNumColumns())
        return false;
    if (lhs.GetNumRows() != rhs.GetNumRows())
        return false;
    for (int row = 0; row < lhs.GetNumRows(); row++)
        for (int col = 0; col < lhs.GetNumColumns(); col++)
            if (lhs.At(row, col) != rhs.At(row, col))
                return false;
    return true;
}

istream& operator>>(istream& is, Matrix& m)
{
    int cols, rows;
    is >> rows >> cols;
    m.Reset(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            is >> m.At(i,j);
    return is;
}

ostream& operator<<(ostream& os, Matrix m)
{
    os << m.GetNumRows() << " " << m.GetNumColumns() << endl;
    for (int row = 0; row < m.GetNumRows(); ++row)
    {
        for (int col = 0; col < m.GetNumColumns(); ++col)
            os << m.At(row, col) << " ";
        os << endl;
    }
    return os;
}




Matrix operator+ (const Matrix& lhs, const Matrix& rhs)
{
    Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());
    if (lhs.GetNumRows() != rhs.GetNumRows())
        throw invalid_argument("+");
    if (lhs.GetNumColumns() != rhs.GetNumColumns())
        throw invalid_argument("+");
    for (int row = 0; row < lhs.GetNumRows(); row++)
        for (int col = 0; col < lhs.GetNumColumns(); col++)
            result.At(row, col) = lhs.At(row, col) + rhs.At(row, col);
    return result;
}

    // Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main()
{
    Matrix one(0, 1);
    Matrix two(2, 0);
    auto uno = one + two;
    std::cout << uno.GetNumColumns() << ' ' << uno.GetNumRows();

    return 0;
}
