#include <iostream>
using namespace std;

class Array
{
private:
    int rows;
    int cols;
    int depth;
   
	 static int* CreateArray(const int rows)
    {
        int *arr = new int[rows];
        return 	arr;
    }
	static void FillArray(int* const arr, int const rows) 
    {
        for (int i = 0; i < rows; i++)
        {
            arr[i] = i;
        }
    }
	static void ShowArray(int* const arr, const int rows)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

	static void Delete1DArray(int* arr)
    {
        delete[] arr;
    }
//*******************2d arr****************************************
	static int** CreateArray(const int rows, const int cols)
    {
        int** arr = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = CreateArray(cols);
        }
        return arr;
    }
 	static void FillArray(int** const arr, const int rows, const int cols) 
    {
        for (int i = 0; i < rows; i++)
        {
            FillArray(arr[i], cols);
        }

    }

 	static void ShowArray(int** const arr, const int rows, const int cols) 
    {
        for (int i = 0; i < rows; i++)
        {
            ShowArray(arr[i], cols);
        }
        cout << endl;

    }
	static void Delete2DArray(int** arr, const int rows)
    {
        for (int i = 0; i < rows; i++)
        {
            Delete1DArray(arr[i]);
        }
        delete[]arr;
    }
//*************************2d arr*************************
	 static int*** CreateArray(const int rows, const int cols, const int depth)
    {
        int*** arr = new int** [depth];
        for (int i = 0; i < depth; i++)
        {
            arr[i] = CreateArray(rows, cols);
        }
        return arr;
    }

	static void FillArray(int*** const arr, const int rows, const int cols, const int depth) 
    {
        for (int i = 0; i < depth; i++)
        {
            FillArray(arr[i], rows, cols);
        }

    }
	 static void ShowArray(int*** const arr, const int rows, const int cols, const int depth) 
    {
        for (int i = 0; i < depth; i++)
        {
            ShowArray(arr[i], rows, cols);
        }
        cout << endl;
    }	
       	static void Delete3DArray(int*** arr, const int rows, const int cols)
    {
        for (int i = 0; i < cols; i++)
        {
            Delete2DArray(arr[i], rows);
        }
        delete[]arr;
    }

public:
	int* arr1;
      	int** arr2;
       	int*** arr3;
	Array(int valueRows)
	{
		this->rows = valueRows;
		this->cols = 0;
		this->depth = 0;
    		this->arr1 = CreateArray(rows);
		FillArray(this->arr1, rows);
	}
	~Array()
	{
		if (cols == 0 and depth == 0)
		{
			Delete1DArray(this->arr1);
		}
		else if (depth == 0)
		{
			Delete2DArray(this->arr2, this->rows);
		}
		else
		{
		Delete3DArray(this->arr3, this->rows, this->cols);
		}
	}
	Array(int valueRows, int valueCols)
	{
		this->rows = valueRows;
		this->cols = valueCols;
		this->depth =0;
		this->arr2 = CreateArray(rows, cols);
		FillArray(this->arr2, rows, cols);
	}
	Array(int valueRows,  int valueCols,  int valueDepth)
	{
		this->rows = valueRows;
		this->cols = valueCols;
		this->depth = valueDepth;
		this->arr3 = CreateArray(rows, cols, depth);
		FillArray(this->arr3, rows, cols, depth);
	}
	void ShowArray()
	{
		
		if (cols == 0 and depth == 0)
		{
			ShowArray(this->arr1, this->rows);
		}
		else if (depth == 0)
		{
			ShowArray(this->arr2, this->rows, this->cols);
		}
		else
		{
			ShowArray(this->arr3, this->rows, this->cols, this->depth);
		}
	}
    

    //Array() {} // Конструктор без параметрів
	
   


    // ******************************************

      



    //************************************************************

  





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
    Array arr_object1 = Array(rows);
//    arr_object1.FillArray(arr_object1.arr1, rows);
    arr_object1.ShowArray();
   // arr_object1.Delete1DArray(arr_object1.arr1);
    cout << "*********************1d array*********************" << endl;

    cout << "*********************2d array*********************" << endl;
    Array arr_object2 = Array(rows, cols);
  //  arr_object2.FillArray(arr_object2.arr2, rows, cols);
   arr_object2.ShowArray();
   // arr_object2.Delete2DArray(arr_object2.arr2, rows);
    cout << "*********************2d array*********************" << endl;

    cout << "*********************3d array*********************" << endl;
    Array arr_object3 = Array(rows, cols, depth);
    //arr_object3.FillArray(arr_object3.arr3, rows, cols, depth);
   arr_object3.ShowArray();
   // arr_object3.Delete3DArray(arr_object3.arr3, rows, cols);
    cout << "*********************3d array*********************" << endl;
    return 0;
}
