#include<iostream>
using namespace std;
void EnterElements(int arr[100][100],int n,int m)
{
    cout<<"Enter matrix elements"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
}
void ColumnSum(int arr[100][100],int n,int m)
{
    for(int j=0;j<m;j++)
    { int sum=0;
        for(int i=0;i<n;i++)
        { 
            
            sum+=arr[i][j];
           
        }
         cout<<"Sum of column "<<j<<" is "<<sum<<endl;
    }
}
void RowSum(int arr[100][100],int n,int m)
{
   
    for(int i=0;i<n;i++)
    { int sum=0;
        for(int j=0;j<m;j++)
        { 
            
            sum+=arr[i][j];
          
        }
        cout<<"Sum of row "<<i<<" is"<<sum<<endl;
    }  
}
int main() {
    int n, m;
    cout << "Enter number of rows and columns of Matrix:" << endl;
    cin >> n >> m;

    int arr[100][100];
   
     EnterElements(arr, n, m);

     RowSum(arr,n,m);
     ColumnSum(arr,n,m);
}
