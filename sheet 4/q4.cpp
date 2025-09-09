#include <iostream>
#include <queue>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    queue<char> q;
    int freq[100] = {0};
    for (char ch : s)
    {
        if (ch == ' ')
            continue;
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1)
        {
            q.pop();
        }
        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    return 0;
}
