#include <iostream>
#include <vector>
using namespace std;
#define SIZE 10
class Queue
{
    int arr[SIZE];
    int front, rear;
public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }
    bool isFull()
    {
        return (rear == SIZE - 1);
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        arr[++rear] = x;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
vector<int> interleave(Queue q, int n)
{
    vector<int> v, vr, ans;

    int half = n / 2;

    for (int i = 0; i < half; i++)
    {
        v.push_back(q.peek());
        q.dequeue();
    }
    for (int i = 0; i < half; i++)
    {
        vr.push_back(q.peek());
        q.dequeue();
    }
    int j = 0, k = 0;
    while (j < half && k < half)
    {
        ans.push_back(v[j]);
        ans.push_back(vr[k]);
        j++;
        k++;
    }
    return ans;
}
int main()
{
    Queue q;
    for (int i = 1; i <= 6; i++)
    {
        q.enqueue(i);
    }
    cout << "original queue: ";
    q.display();
    vector<int> result = interleave(q, 6);
    cout << "interleaved result";
    for (int x : result)
        cout << x << " ";
    cout << endl;
    return 0;
}
