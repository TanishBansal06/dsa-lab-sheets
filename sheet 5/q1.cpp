#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
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
    ~LinkedList() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertAfter(int target_data, int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == target_data) {
                Node* newNode = new Node(data);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Node with value " << target_data << " not found." << endl;
    }
    void insertBefore(int target_data, int data) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == target_data) {
            insertAtBeginning(data);
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == target_data) {
                Node* newNode = new Node(data);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Node with value " << target_data << " not found." << endl;
    }
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is already empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is already empty." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* second_last = head;
        while (second_last->next->next != nullptr) {
            second_last = second_last->next;
        }
        delete second_last->next;
        second_last->next = nullptr;
    }
    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void search(int key) {
        Node* current = head;
        int position = 1;
        while (current != nullptr) {
            if (current->data == key) {
                cout << "Found " << key << " at position " << position << "." << endl;
                return;
            }
            current = current->next;
            position++;
        }
        cout << "Node with value " << key << " not found in the list." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    int choice, data, target;

    while (true) {
        cout << "Insert beginning" << endl;
        cout << "Insert end" << endl;
        cout << "Insert after a specific node" << endl;
        cout << "Insert before a specific node" << endl;
        cout << "Delete beginning" << endl;
        cout << "Delete end" << endl;
        cout << "Delete a specific node" << endl;
        cout << "Search for a node" << endl;
        cout << "Display the list" << endl;
        cout << "Exit" << endl;
        cout << "Enter your choice (1-10): ";
        cin >> choice;
        
        if(cin.fail()){
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value ";
                cin >> data;
                ll.insertAtBeginning(data);
                cout << "Updated List: ";
                ll.display();
                break;
            case 2:
                cout << "Enter value ";
                cin >> data;
                ll.insertAtEnd(data);
                cout << "Updated List: ";
                ll.display();
                break;
            case 3:
                cout << "Enter the node value to insert after: ";
                cin >> target;
                cout << "Enter the new value to insert after " << target << ": ";
                cin >> data;
                ll.insertAfter(target, data);
                cout << "Updated List: ";
                ll.display();
                break;
            case 4:
                cout << "Enter the node value to insert before: ";
                cin >> target;
                cout << "Enter the new value to insert before " << target << ": ";
                cin >> data;
                ll.insertBefore(target, data);
                cout << "Updated List: ";
                ll.display();
                break;
            case 5:
                ll.deleteFromBeginning();
                cout << "Deleted from the beginning." << endl;
                cout << "Updated List: ";
                ll.display();
                break;
            case 6:
                ll.deleteFromEnd();
                cout << "Deleted from the end." << endl;
                cout << "Updated List: ";
                ll.display();
                break;
            case 7:
                cout << "Enter the node value to delete: ";
                cin >> data;
                ll.deleteNode(data);
                cout << "Updated List: ";
                ll.display();
                break;
            case 8:
                cout << "Enter the node value to search for: ";
                cin >> data;
                ll.search(data);
                break;
            case 9:
                cout << "Current List: ";
                ll.display();
                break;
            case 10:
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
