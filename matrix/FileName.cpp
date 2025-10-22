#include <iostream>
using namespace std;

template<typename M>
class Matrix
{
	M** ptr;
	int rows;
	int columns;
public:
	Matrix();
	Matrix(int r, int c);
	~Matrix();
	void Input();
	void Output();
	void MinElement();
	void MaxElement();
	Matrix<M> operator+(Matrix<M>& obj2);
	Matrix<M> operator-(Matrix<M>& obj2);
	Matrix<M> operator/(Matrix<M>& obj2);
	Matrix<M> operator*(Matrix<M>& obj2);
	bool Check(Matrix<M>& obj, int r,int c);
	int GetRows()
	{
		return rows;
	}
	int GetColumns()
	{
		return columns;
	}
};

template<typename M>
Matrix<M>::Matrix()
{
	ptr = nullptr;
	rows = 0;
	columns = 0;
}

template<typename M>
Matrix<M>::Matrix(int r, int c)
{
	rows = r;
	columns = c;
	ptr = new M * [rows];
	for (int i = 0; i < rows; i++)
	{
		ptr[i] = new M[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ptr[i][j] = rand() % 20;
		}
	}
}

template<typename M>
Matrix<M>::~Matrix()
{
	if (ptr != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] ptr[i];
		}
		delete[] ptr;
	}
}

template<typename M>
void Matrix<M>::Input()
{
	if (ptr != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] ptr[i];
		}
		delete[] ptr;
	}
	cout << "Enter the rows: " << endl;
	cin >> rows;
	cout << "Enter the columns: " << endl;
	cin >> columns;
	ptr = new M * [rows];
	for (int i = 0; i < rows; i++)
	{
		ptr[i] = new M[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "Enter [" << i << "][" << j << "]: " << endl;
			cin >> ptr[i][j];
		}
	}
}

template<typename M>
void Matrix<M>::Output()
{
	cout << "Your matrix: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << ptr[i][j] << "\t";
		}
		cout << endl;
	}
}

template<typename M>
void Matrix<M>::MinElement()
{
	M min = ptr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (ptr[i][j] < min)
			{
				min = ptr[i][j];
			}
		}
	}
	cout << "Min element: " << min << endl;
}

template<typename M>
void Matrix<M>::MaxElement()
{
	M max = ptr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (ptr[i][j] > max)
			{
				max = ptr[i][j];
			}
		}
	}
	cout << "Max element: " << max << endl;
}

template<typename M>
Matrix<M> Matrix<M>::operator+(Matrix<M>& obj2)
{
	Matrix<M> res(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			M check = Check(obj2,i,j) ? obj2.ptr[i][j] : 0;
			res.ptr[i][j] = ptr[i][j] + check;
		}
	}
	return res;
}

template<typename M>
Matrix<M> Matrix<M>::operator-(Matrix<M>& obj2)
{
	Matrix<M> res(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			M check = Check(obj2, i, j) ? obj2.ptr[i][j] : 0;
			res.ptr[i][j] = ptr[i][j] - check;
		}
	}
	return res;
}

template<typename M>
Matrix<M> Matrix<M>::operator/(Matrix<M>& obj2)
{
	Matrix<M> res(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			M check = Check(obj2, i, j) ? obj2.ptr[i][j] : 1;
			res.ptr[i][j] = ptr[i][j] / check;
		}
	}
	return res;
}

template<typename M>
Matrix<M> Matrix<M>::operator*(Matrix<M>& obj2)
{
	Matrix<M> res(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			M check = Check(obj2, i, j) ? obj2.ptr[i][j] : 1;
			res.ptr[i][j] = ptr[i][j] * check;
		}
	}
	return res;
}

template<typename M>
bool Matrix<M>::Check(Matrix<M>& obj, int r, int c)
{
	return obj.GetRows() > r && obj.GetColumns() > c;
}

int main()
{
	srand(unsigned(time(0)));

	Matrix<int> obj(4, 5);
	obj.Output();
	obj.MinElement();
	obj.MaxElement();

	Matrix<int> obj2(3, 5);
	obj2.Output();

	Matrix<int> obj3 = obj + obj2;
	obj3.Output();

	Matrix<int> obj4 = obj - obj2;
	obj4.Output();

	Matrix<int> obj5 = obj * obj2;
	obj5.Output();

	Matrix<int> obj6 = obj / obj2;
	obj6.Output();

	/*Matrix<int> obj2;
	obj2.Input();
	obj2.Output();*/
}


