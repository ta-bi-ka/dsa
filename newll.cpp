#include <bits/stdc++.h>
using namespace std;

class Figure
{
    int row;
    int col;
    string name;
    int **matrix;

public:
    Figure()
    {
        row = 0;
        col = 0;
        name = "";
        matrix = nullptr;
    }
    Figure(int r, int c, int array[])
    {
        row = r;
        col = c;
        if (r == 2 && c == 3)
        {
            name = "Line3D";
        }
        else if (r == 2 && c == 2)
        {
            name = "Line2D";
        }
        else if (r == 3 && c == 2)
        {
            name = "Triangle2D";
        }
        else if (r == 3 && c == 3)
        {
            name = "Triangle3D";
        }
        else if (r == 4 && c == 3)
        {
            name = "Rectangle3D";
        }
        else if (r == 4 && c == 2)
        {
            name = "Rectangle2D";
        }
        else
        {
            name = "UnknownFigure";
        }
        matrix = new int *[row];
        int k = 0;
        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = array[k++];
            }
        }
    }

 Figure(const Figure &other)
    {
        row = other.row;
        col = other.col;
        name = other.name;
        if (other.matrix == nullptr)
        {
            matrix = nullptr;
            return;
        }
        matrix = new int *[row];
        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }



    ~Figure()
    {
        if (matrix == nullptr)
            return;
        for (int i = 0; i < row; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;

        cout << name << " has been destroyed." << endl;
    }

    string getname()
    {
        return name;
    }

    int getsum()
    {
        int sum = 0;

        if (matrix == nullptr)
        {
            return 0;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
    int getsum(int r, int c, int array[])
    {
        int sum = 0;
        if (r > row || c > col)
        {
            cout << "Invalid dimensions for sum calculation." << endl;
            return -1;
        }
        for (int i = 0; i < r; i++)

        {
            for(int j = 0; j < c; j++)
            {
                sum += matrix[i][j];
            }
            
        }
        return sum;
    }
};

int main()
{

    int r,c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;
    int *arr = new int[r*c];
    cout << "Enter " << r*c << " elements for the matrix: ";
    for(int i=0; i<r*c; i++) {
        cin >> arr[i];
    }


    cout << "Creating fig1 with " << r << " rows and " << c << " columns." << endl;
    Figure fig1(r, c, arr);
    cout << "Figure name: " << fig1.getname() << endl;
    cout << "Sum of elements in fig1: " << fig1.getsum() << endl;
    cout<<"Enter number of rows and columns for partial sum calculation: ";
    int r1, c1;
    cin >> r1 >> c1;
    cout << "Sum of elements for first " << r1 << " rows and " << c1 << " columns: " << fig1.getsum(r1, c1, arr) << endl;
    cout << "Cloning fig1 to create clone." << endl;
    Figure clone = fig1;
    cout << "Cloned Figure name: " << clone.getname() << endl;
    cout << "Sum of elements in cloned figure: " << clone.getsum() << endl;
    cout << "Default constructor" << endl;
    Figure defaultFig;
    cout << "Default Figure name: " << defaultFig.getname() << endl;
    cout << "Sum of elements in default figure: " << defaultFig.getsum() << endl;

    
    return 0;
}