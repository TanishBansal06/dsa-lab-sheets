#include <iostream>
using namespace std;
struct Term {
    int row, col, val;
};
class Sparse {
public:
    int rows, cols, num;
    Term data[20];   
    void read() {
        cout << "Enter number of rows, cols and nonzero elements: ";
        cin >> rows >> cols >> num;

        cout << "Enter row, col, value for each nonzero element:\n";
        for (int i = 0; i < num; i++) {
            cin >> data[i].row >> data[i].col >> data[i].val;
        }
    }
    void display() {
        cout << "Row Col Val\n";
        for (int i = 0; i < num; i++) {
            cout << data[i].row << " " << data[i].col << " " << data[i].val << endl;
        }
    }
    // (a) Transpose of sparse matrix
    Sparse transpose() {
        Sparse t;
        t.rows = cols;
        t.cols = rows;
        t.num = num;

        int k = 0;
        for (int c = 0; c < cols; c++) {
            for (int i = 0; i < num; i++) {
                if (data[i].col == c) {
                    t.data[k].row = data[i].col;
                    t.data[k].col = data[i].row;
                    t.data[k].val = data[i].val;
                    k++;
                }
            }
        }
        return t;
    }
    // (b) Add two sparse matrices
    Sparse add(Sparse s) {
        Sparse sum;
        if (rows != s.rows || cols != s.cols) {
            cout << "Addition not possible!" << endl;
            sum.num = 0;
            return sum;
        }

        int i=0, j=0, k=0;
        while (i < num && j < s.num) {
            if (data[i].row < s.data[j].row ||
               (data[i].row == s.data[j].row && data[i].col < s.data[j].col)) {
                sum.data[k++] = data[i++];
            }
            else if (s.data[j].row < data[i].row ||
                    (s.data[j].row == data[i].row && s.data[j].col < data[i].col)) {
                sum.data[k++] = s.data[j++];
            }
            else { // same position
                sum.data[k] = data[i];
                sum.data[k++].val = data[i++].val + s.data[j++].val;
            }
        }
        while (i < num) sum.data[k++] = data[i++];
        while (j < s.num) sum.data[k++] = s.data[j++];

        sum.rows = rows;
        sum.cols = cols;
        sum.num = k;
        return sum;
    }

    // (c) Multiply two sparse matrices
    Sparse multiply(Sparse s) {
        Sparse prod;
        if (cols != s.rows) {
            cout << "Multiplication not possible!" << endl;
            prod.num = 0;
            return prod;
        }

        prod.rows = rows;
        prod.cols = s.cols;
        prod.num = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < s.cols; j++) {
                int sum = 0;
                for (int a = 0; a < num; a++) {
                    if (data[a].row == i) {
                        for (int b = 0; b < s.num; b++) {
                            if (s.data[b].row == data[a].col && s.data[b].col == j) {
                                sum += data[a].val * s.data[b].val;
                            }
                        }
                    }
                }
                if (sum != 0) {
                    prod.data[prod.num].row = i;
                    prod.data[prod.num].col = j;
                    prod.data[prod.num].val = sum;
                    prod.num++;
                }
            }
        }
        return prod;
    }
};

int main() {
    Sparse m1, m2;
    cout << "Enter first matrix:\n";
    m1.read();
    cout << "Enter second matrix:\n";
    m2.read();
    cout << "\nFirst matrix in triplet form:\n";
    m1.display();
    cout << "\nSecond matrix in triplet form:\n";
    m2.display();
    cout << "\nTranspose of first matrix:\n";
    Sparse t = m1.transpose();
    t.display();
    cout << "\nAddition of matrices:\n";
    Sparse sum = m1.add(m2);
    sum.display();
    cout << "\nMultiplication of matrices:\n";
    Sparse prod = m1.multiply(m2);
    prod.display();

    return 0;
}
