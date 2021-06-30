#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix
{
	public:
		Matrix()
		{
			cols = 0;
			rows = 0;
		}
		Matrix(int new_row, int new_col)
		{
			Reset(new_row, new_col);
		}
		int GetNumRows() const
		{
			return rows;
		}
		int GetNumColumns() const
		{
			return cols;
		}
		void Reset (int new_row, int new_col)
		{
			if (new_row < 0)
				throw out_of_range("num of rows should be positive");
			if (new_col < 0)
				throw out_of_range("num of cols should be positive");
			if (new_col == 0 || new_row == 0)
	        {
				new_row = new_col = 0;
	        }
			cols = new_col;
			rows = new_row;
			matr.assign(new_row, vector<int>(new_col));
		}
		int At (int row, int col) const
		{
			return matr.at(row).at(col);
		}
		int& At (int row, int col)
		{
			return matr.at(row).at(col);
		}
	private:
		vector<vector<int>> matr;
		int cols,rows;
};


istream& operator >>(istream& stream, Matrix& m)
{
	int cols, rows;
	stream >> rows >> cols;
	m.Reset(rows, cols);
	for (int i=0; i<rows; i++)
		for (int j=0; j<cols; j++)
			stream >> m.At(i,j);
	return stream;
}

ostream& operator<<(ostream& stream, Matrix m)
{
	stream << m.GetNumRows() << " " << m.GetNumColumns() << endl;
	for (int row=0; row<m.GetNumRows(); row++)
	{
		for (int col=0;col<m.GetNumColumns();col++)
		{
			if (col!=m.GetNumColumns()-1)
				stream << m.At(row,col) << " ";
			else
				stream << m.At(row,col);
//			stream << m.At(row,col);
		}
		stream << endl;
	}
	return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.GetNumColumns()!=rhs.GetNumColumns())
		return false;
	if (lhs.GetNumRows()!=rhs.GetNumRows())
		return false;
	for (int row=0; row<lhs.GetNumRows();row++)
		for (int col=0;col<lhs.GetNumColumns();col++)
			if (lhs.At(row,col)!=rhs.At(row, col))
				return false;
	return true;
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

int main() {
    Matrix one(0, 1);
    Matrix two(2, 0);
    auto uno = one + two;
    std::cout << uno.GetNumColumns() << ' ' << uno.GetNumRows();

    return 0;
}
