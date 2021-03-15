#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
private:
	int num_rows;
	int num_cols;
	vector<vector<int>>  matrix_num;

public:
	Matrix()
	{
		num_rows = 0;
		num_cols = 0;
	}
	Matrix(const int rows, const int cols)
	{		
		Reset(rows, cols);
	}
	void Reset(const int rows, const int cols)
	{
		if (rows < 0)
			throw out_of_range("Rows must be >= 0");

		if (cols < 0)
			throw out_of_range("Cols must be >= 0");
		num_rows = rows;
		num_cols = cols;

		matrix_num.assign(num_rows, vector<int>(num_cols));
	}

	int& At(int rows, int cols)
	{
		return matrix_num.at(rows).at(cols);
	}
	int At(int rows, int cols) const
	{
		return matrix_num.at(rows).at(cols);
	}	

	int GetNumRows() const
	{
		return num_rows;
	}
	int GetNumColumns() const
	{
		return num_cols;
	}
};
istream& operator>>(istream& str, Matrix& matrix)
{
	int num_rows, num_cols;
	str >> num_rows >> num_cols;
	matrix.Reset(num_rows, num_cols);

	for (int i(0); i < num_rows; ++i)
	{
		for (int j(0); j < num_cols; ++j)
		{
			str >> matrix.At(i, j);
		}
	}
	return str;
}
ostream& operator<<(ostream& str, const Matrix& matrix)
{
	str << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
	for (int i(0); i < matrix.GetNumRows(); ++i)
	{
		for (int j(0); j < matrix.GetNumColumns(); ++j)
		{
			if (j > 0)
				str << " ";
			str << matrix.At(i, j);
		}
		str << endl;
	}
	return str;
}

bool operator==(const Matrix& one, const Matrix& two)
{
	if (one.GetNumRows() == two.GetNumRows() && one.GetNumColumns() == two.GetNumColumns())
	{
		for (int i(0); i < one.GetNumRows(); ++i)
		{
			for (int j(0); j < one.GetNumColumns(); ++j)
			{
				if (one.At(i, j) != two.At(i, j))
					return false;
			}
		}
		return true;
	}

	return false;
}

Matrix operator+(const Matrix& one, const Matrix& two)
{
	Matrix three(one.GetNumRows(), one.GetNumColumns());
	if (one.GetNumRows() != two.GetNumRows())
	{
		throw  invalid_argument("Rows not equal");
	}
	if (one.GetNumColumns() != two.GetNumColumns())
	{
		throw  invalid_argument("Columns not equal");
	}
	
		for(int i(0); i < one.GetNumRows(); ++i)
		{
			for(int j(0); j < one.GetNumColumns(); ++j)
			{
				three.At(i, j) = one.At(i, j) + two.At(i, j);
			}
		}

	return three;
}


int main() {
	Matrix one;
	Matrix two;

	try
	{
		cin >> one >> two;
		cout << one + two << endl;
	}
	catch(out_of_range& error)
	{
		cout << error.what() << endl;
	}
	catch (invalid_argument& error)
	{
		cout << error.what() << endl;
	}	

	return 0;
}
