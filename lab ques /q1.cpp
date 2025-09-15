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
      cout<<"Given array is"<<endl;
      for(int i=0;i<n;i++)
      {
        cout<<arr[i]<<" ";
      }
}
void Insert(int arr[],int &n)
{
    int key;
    cout<<"Enter the element to be inserted"<<endl;
    cin>>key;
    int pos;
    cout<<"Enter the poisition to be inserted"<<endl;
    cin>>pos;
    for(int i=n;i>=pos-1;i--)
    {
           arr[i]=arr[i-1];
            
    }
        arr[pos]=key;  
        n++;
          
        cout<<"Updated array is"<<endl;
        Display(arr,n);
}
void Delete(int arr[],int &n)
{
    int pos;
    cout<<"Enter the poisition of element to be deleted"<<endl;
    cin>>pos;

    if(pos<1||pos>n)
    {
        cout<<"Enter valid size"<<endl;
    }
    for(int i=0;i<pos-1;i++)
    {
           arr[i+1]=arr[i];
    }
    n--;
    cout<<"Updated array is"<<endl;
        Display(arr,n);
}
void LinearSearch(int arr[],int n)
{
    int key;
    cout<<"Enter the no to be searched"<<endl;
    cin>>key;
    bool found=false;
    int pos;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            found=true;
            pos=i;
        }
    }
    if(found)
    {
        cout<<"Element "<<key<<"Found at poisition "<<pos<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
}
int main ()
{
      int arr[100];
      int n;
      cout<<"Enter size of array"<<endl;
      cin>>n;
      char choice;
      do{
        cout << "\nChoose an operation:\n";
        cout << "1. Create Array\n";
        cout << "2. Display Array\n";
        cout << "3. Insert Element\n";
        cout << "4. Delete Element\n";
        cout << "5. Linear Search\n";
        cout << "Enter choice: ";
         int operation;
         cin>>operation;
      switch (operation)
      {
      case 1:
       CreateArray(arr,n);
        break;
        case 2:
       Display(arr,n);
        break;
        case 3:
        Insert(arr,n);
        break;
        case 4:
          Delete(arr,n);
        break;
        case 5:
        LinearSearch(arr,n);
        break;
      default:
        break;
      }
     cout<<endl;
      cout<<"Do you want to run another operation (yes/no)"<<endl;
      cin>>choice;
    }while(choice=='y'||choice=='Y');




}
