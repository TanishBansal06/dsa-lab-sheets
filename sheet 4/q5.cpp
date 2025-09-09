#include <iostream>
#include <queue>
using namespace std;
class twostackQ
{
    queue<int> q1, q2;
public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack empty\n";
            return;
        }
        q1.pop();
    }
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }
    bool empty()
    {
        return q1.empty();
    }
};
class onestackQ
{
    queue<int> q;

public:
    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if (q.empty())
        {
            cout << "Stack empty\n";
            return;
        }
        q.pop();
    }
    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
    }
    bool empty()
    {
        return q.empty();
    }
};
int main()
{
    twostackQ s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Top" << s1.top() << endl;
    s1.pop();
    cout << "Top" << s1.top() << endl;

    onestackQ s2;
    s2.push(40);
    s2.push(50);
    s2.push(60);
    cout << "Top" << s2.top() << endl;
    s2.pop();
    cout << "Top" << s2.top() << endl;
}
