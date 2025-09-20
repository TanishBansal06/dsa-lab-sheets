#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    bool empty() {
        return head == nullptr;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Pushed " << value << " into the list.\n";
    }
    void acc(int val) {
        if (empty()) {
            cout << "List is empty.\n";
            return;
        }
        int count = 0;
        while (head != nullptr && head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            count++;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr) {
            if (temp->data == val) {
                Node* toDelete = temp;
                prev->next = temp->next;
                temp = temp->next;
                delete toDelete;
                count++;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        if (count == 0)
            cout << "Value " << val << " not found in the list.\n";
        else
            cout << "Removed " << count << " occurrence(s) of value " << val << ".\n";
    }
    void display() {
        if (empty()) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
int main() {
    LinkedList list;
    list.push(10);
    list.push(20);
    list.push(10);
    list.push(30);
    list.push(10);
    cout << "Original list: ";
    list.display();
    list.acc(10);
    cout << "Updated list: ";
    list.display();
    list.acc(40);
    return 0;
}
