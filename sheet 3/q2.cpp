#include <iostream>
using namespace std;
#define SIZE 100
class stack {
    char arr[SIZE];
    int top;
public:
    stack() {
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == SIZE - 1;
    }
    void push(char x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }
    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
};
int main() {
    string s;
    cout << "enter a string ";
    cin >> s;
    stack st;
    for (char c : s) {
        st.push(c);
    }
    string rev = "";
    while (!st.isEmpty()) {
        rev += st.pop();
    }
    cout << "reversed string " << rev << endl;
    return 0;
}
