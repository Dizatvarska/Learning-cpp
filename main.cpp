#include <iostream>
using namespace std;

class Array
{
private:
    int rows;
    int cols;
    int depth;
public:
    Array() {} // Конструктор без параметрів

    int* Create1DArray(const int rows)
    {
        int *arr = new int[rows];
        return 	arr;
    }
    
    void Fill1DArray(int* const arr, int const rows) 
    {
        for (int i = 0; i < rows; i++)
        {
            arr[i] = i;
        }
    }

    void Show1DArray(int* const arr, const int rows)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    void Delete1DArray(int* arr)
    {
        delete[] arr;
    }
    // ******************************************

    int** Create2DArray(const int rows, const int cols)
    {
        int** arr = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = Create1DArray(cols);
        }
        return arr;
    }
    
    void Fill2DArray(int** const arr, const int rows, const int cols) 
    {
        for (int i = 0; i < rows; i++)
        {
            Fill1DArray(arr[i], cols);
        }

    }

    void Show2DArray(int** const arr, const int rows, const int cols) 
    {
        for (int i = 0; i < rows; i++)
        {
            Show1DArray(arr[i], cols);
        }
        cout << endl;

    }

    void Delete2DArray(int** arr, const int rows)
    {
        for (int i = 0; i < rows; i++)
        {
            Delete1DArray(arr[i]);
        }
        delete[]arr;
    }

    //************************************************************

    int*** Create3DArray(const int rows, const int cols, const int depth)
    {
        int*** arr = new int** [depth];
        for (int i = 0; i < depth; i++)
        {
            arr[i] = Create2DArray(rows, cols);
        }
        return arr;
    }

    void Fill3DArray(int*** const arr, const int rows, const int cols, const int depth) 
    {
        for (int i = 0; i < depth; i++)
        {
            Fill2DArray(arr[i], rows, cols);
        }

    }

    void Show3DArray(int*** const arr, const int rows, const int cols, const int depth) 
    {
        for (int i = 0; i < depth; i++)
        {
            Show2DArray(arr[i], rows, cols);
        }
        cout << endl;
    }

    void Delete3DArray(int*** arr, const int rows, const int cols)
    {
        for (int i = 0; i < cols; i++)
        {
            Delete2DArray(arr[i], rows);
        }
        delete[]arr;
    }
};
//*************************************

int main()
{
    int rows, cols, depth;
    cout << "Please input rows:\t";
    cin >> rows;
    cout << "Please input cols:\t";
    cin >> cols;
    cout << "Please input depth:\t";
    cin >> depth;
    cout << "*********************1d array*********************" << endl;
    Array arr;
    int* arr1 = arr.Create1DArray(rows);
    arr.Fill1DArray(arr1, rows);
    arr.Show1DArray(arr1, rows);
    arr.Delete1DArray(arr1);
    cout << "*********************1d array*********************" << endl;

    cout << "*********************2d array*********************" << endl;
    int** arr2 = arr.Create2DArray(rows, cols);
    arr.Fill2DArray(arr2, rows, cols);
    arr.Show2DArray(arr2, rows, cols);
    arr.Delete2DArray(arr2, rows);
    cout << "*********************2d array*********************" << endl;

    cout << "*********************3d array*********************" << endl;
    int*** arr3 = arr.Create3DArray(rows, cols, depth);
    arr.Fill3DArray(arr3, rows, cols, depth);
    arr.Show3DArray(arr3, rows, cols, depth);
    arr.Delete3DArray(arr3, rows, cols);
    cout << "*********************3d array*********************" << endl;
    return 0;
}
