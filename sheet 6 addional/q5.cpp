#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node *right, *left, *up, *down;
    Node(int val) : data(val), right(NULL), left(NULL), up(NULL), down(NULL) {}
};
Node* constructLinkedMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    if (n == 0) return NULL;
    int m = mat[0].size();
    vector<vector<Node*>> nodes(n, vector<Node*>(m, NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nodes[i][j] = new Node(mat[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0)
                nodes[i][j]->left = nodes[i][j - 1];
            if (j < m - 1)
                nodes[i][j]->right = nodes[i][j + 1];
            if (i > 0)
                nodes[i][j]->up = nodes[i - 1][j];
            if (i < n - 1)
                nodes[i][j]->down = nodes[i + 1][j];
        }
    }
    return nodes[0][0];
}
void printLinkedMatrix(Node* head, int n, int m) {
    Node* row = head;
    while (row) {
        Node* col = row;
        while (col) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Node* head = constructLinkedMatrix(mat);
    cout << "Doubly Linked Matrix:\n";
    printLinkedMatrix(head, 3, 3);
    return 0;
}
