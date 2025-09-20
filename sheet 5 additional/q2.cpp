#include <iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        while (count < k) {
            if (temp == NULL) {
                return head;
            }
            temp = temp->next;
            count++;
        }
        ListNode* prev = reverseKGroup(temp, k);
        temp = head;
        count = 0;
        ListNode* next = NULL;
        while (count < k) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }
        return prev;
    }
};
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    int k = 2;
    head = s.reverseKGroup(head, k);
    printList(head);
    return 0;
}
