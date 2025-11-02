class Solution {
public:
    ListNode* head = NULL;
    ListNode* reverse(ListNode* &head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void create(int val) {
        ListNode* newnode = new ListNode(val);
        if (head == NULL) {
            head = newnode;
            return;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }
    void sum(ListNode* l1, ListNode* l2) {
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry) {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int total = x + y + carry;
            carry = total / 10;
            create(total % 10);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        head = NULL;
        sum(l1, l2);
        return head; 
    }
};
