//红果研的算法
ListNode* reverseList(ListNode* head) {
       if(!head) return NULL;
       ListNode *rear = head;
       head = NULL;
       while(rear){
            ListNode *front = rear;
            rear = rear->next;
            front->next = head;
            head= front;
       }  
        return newhead;
}