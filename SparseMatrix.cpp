#include <iostream>
#define NAME_OF(v) #v

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
    void sort(Data *arr);
    SparseMatrix(int rows, int cols, int dataCount) : dataCount(dataCount), rows(rows), cols(cols)
    {
        arr = new Data[dataCount];
    }

public:
    SparseMatrix(int row, int col);
    SparseMatrix &operator=(const SparseMatrix &other);
    SparseMatrix(SparseMatrix const &other);
    ~SparseMatrix();
    SparseMatrix operator+(SparseMatrix const &oprand);
    SparseMatrix operator-(SparseMatrix const &oprand);
    int getElement(int r, int c);
    SparseMatrix transpose();
    SparseMatrix getSparse();
    void printSparse();
    void printMatrix();
};

SparseMatrix::SparseMatrix(int row, int col) : rows(row), cols(col)
{
    int dCount = 0;
    int input;
    Data array[1000];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Please enter value of  [" << i << "][" << j << "]\n";
            cin >> input;
            if (input != 0)
            {

                array[dCount].row = i;
                array[dCount].col = j;
                array[dCount].data = input;
                dCount++;
            }
        }
    }
    arr = new Data[dCount];
    for (int i = 0; i < dCount; i++)
    {
        arr[i] = array[i];
    }
    dataCount = dCount;
}

SparseMatrix::SparseMatrix(SparseMatrix const &other) : rows(other.rows), cols(other.cols), dataCount(other.dataCount)
{
    arr = new Data[dataCount];
    for (int i = 0; i < dataCount; i++)
    {
        arr[i] = other.arr[i];
    }
}
void SparseMatrix::sort(Data *arr)
{
}

SparseMatrix::~SparseMatrix()
{
    delete[] arr;
}

int SparseMatrix::getElement(int r, int c)

{
    if (r >= 0 && r <= this->rows && c >= 0 && c <= this->cols)
    {
        for (int i = 0; i < this->dataCount; i++)
        {
            if (arr[i].row == r && arr[i].col == c)
            {
                return arr[i].data;
            }
        }
        return 0;
    }

    else
    {
        throw out_of_range("Index out of range");
    }
}
SparseMatrix &SparseMatrix::operator=(const SparseMatrix &other)
{
    if (this != &other)
    {
        delete[] arr;
        rows = other.rows;
        cols = other.cols;
        dataCount = other.dataCount;
        arr = new Data[dataCount];
        for (int i = 0; i < dataCount; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

SparseMatrix SparseMatrix::operator+(SparseMatrix const &oprand)
{
    SparseMatrix result(this->rows, this->cols, dataCount + oprand.dataCount);
    if (rows == oprand.rows && cols == oprand.cols)
    {
        Data temp;
        SparseMatrix op = oprand;
        int index = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int first = getElement(i, j);
                int secend = op.getElement(i, j);
                int tempRes = first + secend;
                if (tempRes != 0)
                {
                    temp.row = i;
                    temp.col = j;
                    temp.data = tempRes;
                    result.arr[index] = temp;
                    index++;
                }
                else
                {
                    result.dataCount--;
                }
            }
        }
        result.dataCount = index;
        return result;
    }
    else
    {
        throw logic_error("matrices must have same dimensions");
    }
}

SparseMatrix SparseMatrix::operator-(SparseMatrix const &oprand)
{
    // return SparseMatrix;
}

SparseMatrix SparseMatrix::transpose()
{
    // return SparseMatrix();
}

SparseMatrix SparseMatrix::getSparse()
{
    SparseMatrix result(this->rows, this->cols, this->dataCount);
    Data temp;
    for (int i = 0; i < dataCount; i++)
    {
        temp.row = arr[i].row;
        temp.col = arr[i].col;
        temp.data = arr[i].data;
        result.arr[i] = temp;
    }

    return result;
}

void SparseMatrix::printSparse()
{
    if (dataCount != 0)
    {
        cout << "row\t"
             << "column\t"
             << "value\n";
        cout << dataCount << endl;
        for (int i = 0; i < dataCount; i++)
        {
            cout << this->arr[i].row << "\t";
            cout << this->arr[i].col << "\t";
            cout << this->arr[i].data << endl;
        }
    }
    else
    {
        cout << "Matrix has not data!";
    }
    
}

int main(int argc, char const *argv[])
{
    SparseMatrix sm(1, 1);
    SparseMatrix s(1, 1);
    SparseMatrix sum = (sm + s);
    sum.printSparse();
    return 0;
}
