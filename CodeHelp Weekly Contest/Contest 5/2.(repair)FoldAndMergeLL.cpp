/************************************************
   
   Following is the linkedList class structure:

   class List {
      public:
          int data;
          List *next;

          List(int val) {
              this->data = val;
              next = NULL;
          }
          ~List() {
              if (next != NULL) {
                  delete next;
              }
          }
   };

*************************************************/

//repair
List* reverseLL (List* &head) {
    //base case
    if (head-> data == -1 || head -> next -> data == -1) {
        return head;
    }
    head -> next -> next = head;
    head -> next -> data = -1;
    return reverseLL(head -> next);
}
List* foldAndMerge(List *head) {

    //step 1:  put a ptr at second half of LL
    if (head -> next -> data == -1) {
        return head;
    }
    List* fast = head -> next;
    List* slow = head;
    List* temp = head;
    List* head2 = NULL;
    if (fast -> next -> data == -1) {
        slow = fast;
        return slow;
    }
    while(fast -> next -> data != -1) {
        
        slow = slow->next; 
        fast = fast -> next -> next;
    }//now slow is pointing to last element of 1st half
    head2 = slow->next;
    slow-> next-> data = -1;
    //step 2: reverse LL till half of LL by heir and turtle
    temp = reverseLL(head);
    //step 2: iterate over the list with both ptrs and get product
    while (temp->data != -1) {
        temp -> data = (temp -> data) * (head2 -> data);
        temp = temp -> next;
        head2 = head2 -> next;
    }
    //step 4: return head
    return head;
}