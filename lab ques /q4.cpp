a)  #include <iostream>

using namespace std;

void CreateArray(int arr[], int n)
{
    cout << "Enter elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void Display(int arr[], int n)
{
    cout << "Updated array is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void ReverseArray(int arr[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }

    Display(arr, n);
}

int main()
{
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;

    int arr[100];

    CreateArray(arr, n);

    ReverseArray(arr, n);
}

b) #include <iostream>
using namespace std;

void multiplyMatrices(int A[][10], int B[][10], int result[][10], int r1, int c1, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int r1, c1, r2, c2;
    int A[10][10], B[10][10], result[10][10] = {0};

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2)
    {
        cout << "Matrix multiplication not possible.\n";
        return 0;
    }

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> B[i][j];
        }
    }

    multiplyMatrices(A, B, result, r1, c1, c2);

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// with vector

// #include<iostream>
// #include<vector>

// using namespace std;
// vector<vector<int>> Multiply(vector<vector<int>> &a,vector<vector<int>> &b)
// { 
//     vector<vector<int>> temp(a.size(),vector<int>(b[0].size()));

//     for(int i=0;i<a.size();i++)
//     {
//         for(int j=0;j<b[0].size();j++)
//         {
//            for(int k=0;k<b.size();k++)
//            {
//             temp[i][j]+=a[i][k]*b[k][j];
//            }
//         }
//     }

//     return temp;
// }

// void EnterNumbers( vector<vector<int>> &matrix)
// {
//     int n=matrix.size();
//     int m=matrix[0].size();

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>matrix[i][j];
//         }
//     }
// }
    

// int main ()
// {
//     int n,m;

//     cout<<"Enter rows and columns of matrix 1"<<endl;
//     cin>>n>>m;

//     vector<vector<int>> a(n,vector<int> (m));

//     EnterNumbers(a);

//     int p,q;

//     cout<<"Enter rows and columns of matrix 2"<<endl;
//     cin>>p>>q;

//     vector<vector<int>> b(p,vector<int> (q));

//     EnterNumbers(b);

//     vector<vector<int>> c=Multiply(a,b);

//     cout<<"Matrix Multiplication is"<<endl;
//     for(int i=0;i<c.size();i++)
//     {
//         for(int k=0;k<c[0].size();k++)
//         {
//             cout<<c[i][k]<<" ";
//         }
//         cout<<endl;
//     }
// }

c)  #include <iostream>

using namespace std;

void EnterElements(int arr[100][100], int n, int m)
{
    cout << "enter array";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void Display(int arr[100][100], int n, int m)
{
    cout << "Transposed matrix is" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void TransposeMatrix(int arr[100][100], int n, int m)
{
    int temp[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[i][j] = arr[j][i];
        }
    }

    Display(temp, n, m);
}

int main()
{
    int n, m;
    cout << "Enter number of rows and columns of Matrix:" << endl;
    cin >> n >> m;

    int arr[100][100];
    EnterElements(arr, n, m);
    TransposeMatrix(arr, n, m);
}
