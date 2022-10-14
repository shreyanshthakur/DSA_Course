ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL) {
            delete head;
            return NULL;
        }
        //slow fast method to reach till mid
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //shift
        if (slow->next != NULL)
            *slow = *slow->next;
        else {
            delete slow->next;
            head->next = NULL;
        }
        return head;
    }