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

    int* CreateArray(const int rows)
    {
        int *arr = new int[rows];
        return 	arr;
    }
    
    void FillArray(int* const arr, int const rows) 
    {
        for (int i = 0; i < rows; i++)
        {
            arr[i] = i;
        }
    }

    void ShowArray(int* const arr, const int rows)
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

    int** CreateArray(const int rows, const int cols)
    {
        int** arr = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = CreateArray(cols);
        }
        return arr;
    }
    
    void FillArray(int** const arr, const int rows, const int cols) 
    {
        for (int i = 0; i < rows; i++)
        {
            FillArray(arr[i], cols);
        }

    }

    void ShowArray(int** const arr, const int rows, const int cols) 
    {
        for (int i = 0; i < rows; i++)
        {
            ShowArray(arr[i], cols);
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

    int*** CreateArray(const int rows, const int cols, const int depth)
    {
        int*** arr = new int** [depth];
        for (int i = 0; i < depth; i++)
        {
            arr[i] = CreateArray(rows, cols);
        }
        return arr;
    }

    void FillArray(int*** const arr, const int rows, const int cols, const int depth) 
    {
        for (int i = 0; i < depth; i++)
        {
            FillArray(arr[i], rows, cols);
        }

    }

    void ShowArray(int*** const arr, const int rows, const int cols, const int depth) 
    {
        for (int i = 0; i < depth; i++)
        {
            ShowArray(arr[i], rows, cols);
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
    int* arr1 = arr.CreateArray(rows);
    arr.FillArray(arr1, rows);
    arr.ShowArray(arr1, rows);
    arr.Delete1DArray(arr1);
    cout << "*********************1d array*********************" << endl;

    cout << "*********************2d array*********************" << endl;
    int** arr2 = arr.CreateArray(rows, cols);
    arr.FillArray(arr2, rows, cols);
    arr.ShowArray(arr2, rows, cols);
    arr.Delete2DArray(arr2, rows);
    cout << "*********************2d array*********************" << endl;

    cout << "*********************3d array*********************" << endl;
    int*** arr3 = arr.CreateArray(rows, cols, depth);
    arr.FillArray(arr3, rows, cols, depth);
    arr.ShowArray(arr3, rows, cols, depth);
    arr.Delete3DArray(arr3, rows, cols);
    cout << "*********************3d array*********************" << endl;
    return 0;
}
