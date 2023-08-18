#include <iostream>
using namespace std;

int *Create1DArray(const int rows)//creating 1d array

        //      cout << " __Create1DArray start________________\n";
        {

                int *arr = new int [rows];
                return arr;
        }
        //      cout << " __Create1DArray end________________\n";



int ** Create2DArray ( const int rows, const int cols)//creating 2D array
        //      cout << " __Create2DArray start________________\n";
        {       int **arr = new int *[rows];
                for (int i = 0; i < rows; i++)
                {
                //      arr[i] = new int[cols];
                        arr[i] = Create1DArray(cols);
                } 
                return arr; 
        }
        //cout << " __Create2DArray end________________\n";

 
int *** Create3DArray ( const int rows, const int cols, const int depth)//creating 3D array
        //      cout << " __Create3DArray start________________\n";
        {       int ***arr = new int **[depth];
                for (int i = 0; i < depth; i++)
                {
                        arr[i] = Create2DArray(rows,cols);
                } 
                return arr; 
        }
        //      cout << " __Create3DArray end________________\n";


void Fill1DArray (int *const arr,int const rows) // filling 1d array
        //      cout << " __Create3DArray start________________\n";
        {
                for (int i = 0; i < rows; i++)
                {
                        arr[i] = i;
                }
        }
        //      cout << " __Create3DArray start________________\n";



void Fill2DArray(int** const arr,const int rows, const int cols) // filling 2d array
        //      cout << " __Fill2DArray start________________\n";
        {
                for (int i = 0; i < rows; i++)
                {
                //      arr[i] = new int [cols];
                        Fill1DArray(arr[i],cols);
                }

        }

        //      cout << " ____Fill2DArray end________________\n";


void Fill3DArray(int*** const arr,const int rows, const int cols, const int depth) // filling 3d array
        //      cout << " __Fill3DArray start________________\n";
        {
                for (int i = 0; i < depth; i++)
                {
                //      arr[i] = new int* [depth];
                        Fill2DArray(arr[i],rows,cols);
                }

        }


        //      cout << " ____Fill3DArray end________________\n";


void Show1DArray (int* const arr, const int rows)// showing 1d array
        //      cout << " ____Show1DArray start________________\n";
        {
                for(int i = 0; i < rows; i++)
                {
                        cout << arr[i]<<"\t";
                }
                cout<<endl;
        }
        //      cout << " ____Show1DArray end________________\n";


void Show2DArray(int** const arr,const int rows, const int cols) // showing 2d array
        //      cout << " __Show2DArray start________________\n";
        {
                for (int i = 0; i < rows; i++)
                {
                //      arr[i] = new int[cols];
                        Show1DArray(arr[i],cols);
                 }
                        cout<<endl;

        }
        //      cout << " __Show2DArray end________________\n";



void Show3DArray(int*** const arr,const int rows, const int cols, const int depth) // showing 3d array
        //      cout << " __Show3DArray start________________\n";
        {
                for (int i = 0; i < depth; i++)
                {
                //      arr[i] = new int*[depth];
                        Show2DArray(arr[i],rows,cols);
                }
                        cout<<endl;
        }
        //      cout << " __Show2DArray end________________\n";



void Delete1DArray(int *arr)// delieting 1d array  
        // cout<<"___________delete1darray start________";
        {
                delete[] arr;
        }
        // cout<<"___________delete1darray end________";

void Delete2DArray(int **arr, const int rows)
        // cout<<"___________delete2darray start______";
        {
                for (int i = 0; i <rows; i++)
                { 
                        Delete1DArray(arr[i]);
                }
                delete []arr;
        }
        // cout<<"___________delte2darray end_______";

void Delete3DArray(int ***arr, const int rows, const int cols)
        // cout<<"___________delete2darray start______";
        {
                for (int i = 0; i <cols; i++)
                { 
                        Delete2DArray(arr[i],rows);
                }
                delete []arr;
        }
        // cout<<"___________delte2darray end_______";

/*void widArr(int *&oldArr, int &size, int &index) // widing the origin array 
{
        cout << " ___________Shift left__________\n";
        int* newArray = new int[size + index];
          
        for (int i = 0; i < size + index; i++) 
        {
                if (i > size-1)
                {
                        newArray[i] = 0;
                         cout<<" newArr got 0"<< endl ;
                }
                else
                {
                        newArray[i] = oldArr[i];
                        cout <<" newArr got value "<<oldArr[i]<<endl ;
                }
        }

        cout << endl;

        delete[]oldArr;
        oldArr = newArray;
        cout << " ___________Shift left__________\n";
}



void narArr(int *&oldArr, int &size, int &index) //narrowing the origin array
{
        cout << " _____________narArr__________\n";
        int* newArray = new int[size - index];
          int newsize = size - index;
        for (int i = 0; i < size; i++) 
        {
                if (i> newsize)
                {

                         cout<<" newArr got newsize elements\t" <<oldArr[i]<< endl ;
                }
                else
                {
                        newArray[i] = oldArr[i];

                        cout <<" newArr gow copied with old array"<<endl ;
                }
        }

        cout << endl;

        delete[]oldArr;
        oldArr = newArray;
        cout << " ___________narrArr__________\n";
}
*/


int main()
{
        int rows, cols,depth;
        cout << "Please input rows:\t";
        cin>>rows;
        cout << "Please input cols:\t";
        cin >> cols;
        cout << "Please input depth:\t";
        cin >> depth;

        cout<<"*********************1d array*********************"<<endl;
        int *arr1 = Create1DArray(rows);
        Fill1DArray(arr1, rows);
        Show1DArray(arr1,rows);
        cout<<"*********************1d array*********************"<<endl;

        cout<<"*********************2d array*********************"<<endl;
        int **arr2 = Create2DArray(rows, cols);
        Fill2DArray(arr2, rows, cols);
        Show2DArray(arr2, rows, cols);
        cout<<"*********************2d array*********************"<<endl;

        cout<<"*********************3d array*********************"<<endl;
        int ***arr3 = Create3DArray(rows, cols, depth);
        Fill3DArray(arr3, rows, cols, depth);
        Show3DArray(arr3, rows, cols, depth);
        cout<<"*********************3d array*********************"<<endl;
        Delete1DArray(arr1);
        Delete2DArray(arr2,rows);
        Delete3DArray(arr3, rows,cols);
        //int newsize  = size - index; 
        //int* arr = new int[size];
        //Fill1DArray(arr, size);
        //Show1Darray(arr, size);
        //narArr(arr, size, index);
        //Show1Darray(arr, newsize);
        //delete[] arr;
        return 0;
}
