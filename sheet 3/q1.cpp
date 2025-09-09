#include <iostream>
using namespace std;
#define SIZE 5
class stack
{
    int arr[SIZE];
    int top;
public:
    stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == SIZE - 1;
    }
    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack full\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed\n";
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack empty\n";
            return;
        }
        cout << arr[top--] << " popped\n";
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack empty\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    stack s;
    int choice, value;
    do
    {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            if (s.isEmpty())
                cout << "stack empty\n";
            else
                cout << "stack not empty\n";
            break;
        case 5:
            if (s.isFull())
                cout << "stack full\n";
            else
                cout << "stack not full\n";
            break;
        case 6:
            s.display();
            break;
        case 7:
            cout << "exiting\n";
            break;
        default:
            cout << "invalid choice\n";
        }
    } while (choice != 7);
    return 0;
}
