#include <iostream>
using namespace std;
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(NULL), prev(NULL) {}
};
struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(NULL) {}
};
bool isEvenParity(int n) {
    return (__builtin_popcount(n) % 2 == 0);
}
DNode* removeEvenParityDLL(DNode* head) {
    if (!head) return NULL;
    DNode* curr = head;
    while (curr) {
        if (isEvenParity(curr->data)) {
            DNode* temp = curr;
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;
            if (curr->next)
                curr->next->prev = curr->prev;
            curr = curr->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}
CNode* removeEvenParityCLL(CNode* head) {
    if (!head) return NULL;
    CNode *curr = head, *prev = NULL;
    do {
        if (isEvenParity(curr->data)) {
            if (curr == head && curr->next == head) {
                delete curr;
                return NULL;
            }
            if (curr == head) {
                CNode* last = head;
                while (last->next != head)
                    last = last->next;
                head = head->next;
                last->next = head;
                delete curr;
                curr = head;
                prev = last;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != head);
    return head;
}

void printDLL(DNode* head) {
    for (DNode* t = head; t; t = t->next)
        cout << t->data << (t->next ? " <=> " : "");
    cout << endl;
}

void printCLL(CNode* head) {
    if (!head) return;
    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    CNode* headC = new CNode(9);
    headC->next = new CNode(11);
    headC->next->next = new CNode(34);
    headC->next->next->next = new CNode(6);
    headC->next->next->next->next = new CNode(13);
    headC->next->next->next->next->next = new CNode(21);
    headC->next->next->next->next->next->next = headC;

    cout << "original cll";
    printCLL(headC);
    headC = removeEvenParityCLL(headC);
    cout << "after removing even parity nodes";
    printCLL(headC);

    DNode* headD = new DNode(18);
    headD->next = new DNode(15);
    headD->next->prev = headD;
    headD->next->next = new DNode(8);
    headD->next->next->prev = headD->next;
    headD->next->next->next = new DNode(9);
    headD->next->next->next->prev = headD->next->next;
    headD->next->next->next->next = new DNode(14);
    headD->next->next->next->next->prev = headD->next->next->next;

    cout << "original dll";
    printDLL(headD);
    headD = removeEvenParityDLL(headD);
    cout << "dfter removing even parity nodes ";
    printDLL(headD);

    return 0;
}
