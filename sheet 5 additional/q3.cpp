void removeLoop(ListNode* list) {
    if (list == NULL || list->next == NULL) {
        return;
    }
    ListNode* slow = list;
    ListNode* fast = list;
    bool cycle = false;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cycle = true;
            break;
        }
    }
    if (cycle) {
        slow = list;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = fast;
        while (temp->next != slow) {
            temp = temp->next;
        }
        temp->next = NULL; 
    } else {
        cout << "no cycle" << endl;
    }
}
