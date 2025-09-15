#include <iostream>
using namespace std;
#define size 5
class quene
{
    int arr[size];
    int front, back;

public:
    quene()
    {
        front = -1;
        back = -1;
    }
    bool isEmpty()
    {
        return (front == -1);
    }
    bool isfull()
    {
        return (back = size - 1);
    }
    void enqueue(int x)
    {
        if (isfull())
        {
            cout << "queue element" << x << endl;
                }
        if (isEmpty())
        {
            front = 0;
        }
        arr[++back] = x;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty\n";
        }
        cout << arr[front] << " deleted from the queue.\n";
        if (front == back)
        {
            front = back = -1;
        }
        else
        {
            front++;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "queue is empty.\n";
        }
        else
        {
            cout << "front element: " << arr[front] << endl;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "quene is empty";
        }
        for (int i = front; i < back; i++)
        {
            cout << arr[front] << endl;
        }
    }
};
int main()
{ Queue q;
    int choice, x;

   do
    { 
        cout << "1. Enqueue)\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (Front Element)\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to insert: ";
            cin >> x;
            q.enqueue(x);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
