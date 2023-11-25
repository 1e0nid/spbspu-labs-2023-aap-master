#include "class.hpp"
#include <cmath>
#include <iostream>

bool matrix::Matrix::isSquareMatrix()
{
  return rows == cols;
}

bool matrix::Matrix::matrixConditionCheck(const int flag)
{
  int count = 0;
  int count_zero = 0;
	if (flag == 1)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (staticMatrix[(i * rows) + j] == 0)
				{
					count++;
				}
				count_zero++;
			}
		}
	}
	else if (flag == 2)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (matrix[(i * rows) + j] == 0)
				{
					count++;
				}
				count_zero++;
			}
		}
	}
	std::cout << count << "\t" << count_zero;
  return count == count_zero;
}

void matrix::Matrix::delMatrix()
{
  delete[] matrix;
}

matrix::Matrix matrix::Matrix::operator()(const std::string & text)
{
	matrix::Matrix matrix;
	fileText = text;
	return matrix;
}

void matrix::Matrix::creatDynamicMatrix(const std::string&)
{
	try
	{
		rows = (size_t)fileText[0] - '0';
		cols = (size_t)fileText[1] - '0';
		matrix = new int[rows * cols];
		for (int i = 0; i < (rows * cols); i++)
		{
			matrix[i] = fileText[i + 2] - '0';
		}
	}
	catch (const std::exception&)
	{
		throw "the matrix is the wrong size";
	}
}

void matrix::Matrix::creatStaticMatrix(const std::string &)
{
	try
	{
		rows = (size_t)fileText[0] - '0';
		cols = (size_t)fileText[1] - '0';
		for (int i = 0; i <= (rows * cols); i++)
		{
			staticMatrix[i] = fileText[i + 2] - '0';
		}
	}
	catch (const std::exception&)
	{
		throw "the matrix is the wrong size";
	}
}