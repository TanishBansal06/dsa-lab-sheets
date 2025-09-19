#include<iostream>
using namespace std;
void CreateArray(int arr[],int n)
{
    cout<<"Enter elements of array"<<endl;
     for(int i=0;i<n;i++)
     {
        cin>>arr[i];
     }
}
void Display(int arr[],int n)
{
    cout<<"Updated array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void RemoveDuplicates(int arr[],int &n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
             if(arr[i]==arr[j])
            {
                   for (int k = j; k < n - 1; k++)
                {
                  
                   arr[k] = arr[k + 1];

                }
                n--;
                j--;
            }
        }
    }
    Display(arr,n);
}
int main ()
{
   int n;
   cout<<"Enter size of array"<<endl;
   cin>>n;
   int arr[100];
   CreateArray(arr,n);
   RemoveDuplicates(arr,n);
}
