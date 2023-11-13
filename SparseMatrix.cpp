#include <iostream>
#include <iomanip>
#include "Mylib/cqueue.h"
#define MAX 1000

using namespace std;

struct Data
{
    int row, col;
    int data;
};

class SparseMatrix
{
private:
    int rows, cols, dataCount;
    Data *arr;
    SparseMatrix(int rows, int cols, int dataCount) : dataCount(dataCount), rows(rows), cols(cols)
    {
        arr = new Data[dataCount];
    }

    int getIndex(int row, int col)
    {
        if (row > 0 || row <= rows || col > 0 || col <= cols)
        {
            for (int i = 0; i < dataCount; i++)
            {
                if (arr[i].row == row && arr[i].col == col)
                {
                    return i;
                }
            }
            return -1;
        }
        else
        {
            throw out_of_range("row or col is not valid!");
        }
    }

    void sort(Data *arr)
    {
        // Use a bubble sort algorithm
        for (int i = 0; i < dataCount - 1; i++)
        {
            for (int j = 0; j < dataCount - i - 1; j++)
            {
                // Compare the row values first, then the col values
                if (arr[j].row > arr[j + 1].row || (arr[j].row == arr[j + 1].row && arr[j].col > arr[j + 1].col))
                {
                    // Swap the elements if they are not in order
                    Data temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

public:
    SparseMatrix(int row, int col);
    SparseMatrix(SparseMatrix const &other); // Deep copy constructor
    ~SparseMatrix();
    void insert(int row, int col, int val);
    SparseMatrix &operator=(const SparseMatrix &other);
    SparseMatrix operator+(SparseMatrix const &oprand);
    SparseMatrix operator-(SparseMatrix const &oprand);
    SparseMatrix transpose();
    int getElement(int r, int c);
    void printSparse() const;
    void printMatrix();
};

void SparseMatrix::insert(int row, int col, int val)
{
    int index = getIndex(row, col);
    if (row < rows, col < cols)
    {
        if (index == -1)
        {
            arr[dataCount].col = col;
            arr[dataCount].row = row;
            arr[dataCount].data = val;
            dataCount++;
        }
        else
        {
            arr[index].col = col;
            arr[index].row = row;
            arr[index].data = val;
        }
    }
}

SparseMatrix::SparseMatrix(int row, int col) : rows(row), cols(col)
{
    arr = new Data[MAX];
    dataCount = 0;
    int input;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Please enter value for : [" << i << "][" << j << "]" << endl;
            cin >> input; // Get the element from the user
            if (input != 0)
            {
                insert(i, j, input);
            }
        }
    }
}

SparseMatrix::SparseMatrix(SparseMatrix const &other) : rows(other.rows), cols(other.cols), dataCount(other.dataCount) // Deep copy constructor
{
    arr = new Data[dataCount];
    for (int i = 0; i < dataCount; i++) // Copy the data from the other object
    {
        arr[i] = other.arr[i];
    }
}

SparseMatrix::~SparseMatrix()
{
    delete[] arr;
}

SparseMatrix &SparseMatrix::operator=(const SparseMatrix &other)
{
    // Check for self-assignment
    if (this == &other)
        return *this;

    // Delete the old data
    delete[] arr;

    // Copy the new data
    rows = other.rows;
    cols = other.cols;
    dataCount = other.dataCount;
    arr = new Data[dataCount];
    for (int i = 0; i < dataCount; i++)
    {
        arr[i] = other.arr[i];
    }

    return *this;
}

SparseMatrix SparseMatrix::operator+(SparseMatrix const &oprand)
{
    // Check if the operands have the same dimensions
    if (rows != oprand.rows || cols != oprand.cols)
    {
        throw invalid_argument("Matrices are not compatible for addition");
    }

    // Create a new matrix to store the result
    SparseMatrix result(rows, cols, dataCount + oprand.dataCount);

    // Add the corresponding elements
    int i = 0, j = 0, k = 0;
    while (i < dataCount && j < oprand.dataCount)
    {
        if (arr[i].row < oprand.arr[j].row)
        {
            result.arr[k++] = arr[i++];
        }
        else if (arr[i].row > oprand.arr[j].row)
        {
            result.arr[k++] = oprand.arr[j++];
        }
        else
        {
            if (arr[i].col < oprand.arr[j].col)
            {
                result.arr[k++] = arr[i++];
            }
            else if (arr[i].col > oprand.arr[j].col)
            {
                result.arr[k++] = oprand.arr[j++];
            }
            else
            {
                result.arr[k].row = arr[i].row;
                result.arr[k].col = arr[i].col;
                result.arr[k].data = arr[i].data + oprand.arr[j].data;
                k++;
                i++;
                j++;
            }
        }
    }

    // Copy the remaining elements
    while (i < dataCount)
    {
        result.arr[k++] = arr[i++];
    }
    while (j < oprand.dataCount)
    {
        result.arr[k++] = oprand.arr[j++];
    }

    // Update the data count of the result
    result.dataCount = k;

    return result;
}

SparseMatrix SparseMatrix::operator-(SparseMatrix const &oprand)
{
    // Check if the operands have the same dimensions
    if (rows != oprand.rows || cols != oprand.cols)
    {
        throw invalid_argument("Matrices are not compatible for subtraction");
    }

    // Create a new matrix to store the result
    SparseMatrix result(rows, cols, dataCount + oprand.dataCount);

    // Subtract the corresponding elements
    int i = 0, j = 0, k = 0;
    while (i < dataCount && j < oprand.dataCount)
    {
        if (arr[i].row < oprand.arr[j].row)
        {
            result.arr[k++] = arr[i++];
        }
        else if (arr[i].row > oprand.arr[j].row)
        {
            result.arr[k] = oprand.arr[j++];
            result.arr[k].data = -result.arr[k].data;
            k++;
        }
        else
        {
            if (arr[i].col < oprand.arr[j].col)
            {
                result.arr[k++] = arr[i++];
            }
            else if (arr[i].col > oprand.arr[j].col)
            {
                result.arr[k] = oprand.arr[j++];
                result.arr[k].data = -result.arr[k].data;
                k++;
            }
            else
            {
                result.arr[k].row = arr[i].row;
                result.arr[k].col = arr[i].col;
                result.arr[k].data = arr[i].data - oprand.arr[j].data;
                k++;
                i++;
                j++;
            }
        }
    }

    // Copy the remaining elements
    while (i < dataCount)
    {
        result.arr[k++] = arr[i++];
    }
    while (j < oprand.dataCount)
    {
        result.arr[k] = oprand.arr[j++];
        result.arr[k].data = -result.arr[k].data;
        k++;
    }

    // Update the data count of the result
    result.dataCount = k;

    return result;
}

SparseMatrix SparseMatrix::transpose()
{
    // Create a new matrix to store the result
    SparseMatrix result(cols, rows, dataCount);

    // Swap the row and col values of each element
    for (int i = 0; i < dataCount; i++)
    {
        result.arr[i].row = arr[i].col;
        result.arr[i].col = arr[i].row;
        result.arr[i].data = arr[i].data;
    }

    // Sort the result by row and col values
    result.sort(result.arr);

    return result;
}

int SparseMatrix::getElement(int r, int c)
{
    // Check if the row and col values are valid
    if (r < 0 || r >= rows || c < 0 || c >= cols)
    {
        throw out_of_range("Invalid row or col value");
    }

    // Search for the element in the array
    for (int i = 0; i < dataCount; i++)
    {
        if (arr[i].row == r && arr[i].col == c)
        {
            return arr[i].data;
        }
    }

    // If not found, return 0
    return 0;
}

void SparseMatrix::printSparse() const
{
    // Print the number of rows, cols, and non-zero elements
    cout << "Sparse Matrix: " << endl;
    cout << "rows: " << rows << " cols: " << cols << " data count: " << dataCount << endl;

    // Print the row, col, and data values of each element
    for (int i = 0; i < dataCount; i++)
    {
        cout << arr[i].row << " " << arr[i].col << " " << arr[i].data << endl;
    }
}

void SparseMatrix::printMatrix()
{
    // Print the matrix in a normal format
    cout << "Matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << getElement(i, j) << " "; // Use setw to align the columns
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{

    SparseMatrix s(2, 2);
    s.insert(0, 0, 5);
    SparseMatrix trs = s.transpose();
    trs.printSparse();
    trs.printMatrix();
    return 0;
}
