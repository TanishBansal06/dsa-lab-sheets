
ListNode* getIntersectionNode(ListNode *A, ListNode *B) {
	
    while(A!=NULL){
		ListNode* temp=B;
		while(temp!=NULL){
			if(A == temp){
				return A;
			}
			temp = temp->next;
		}
		A = A->next;
	}
	return NULL;
}
