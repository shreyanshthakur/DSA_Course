/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fw = head, *bk = head, *temp = NULL;
        int count = 1;
        while (fw != NULL && count <= n) {
            fw = fw->next;
            count++;
        }
        if (fw == NULL) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while (fw->next != NULL) {
            fw = fw->next;
            bk = bk->next;
        }
        temp = bk->next;
        bk->next = bk->next->next;
        delete temp;
        return head;
    }
};