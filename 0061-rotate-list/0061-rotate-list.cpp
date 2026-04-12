class Solution {
private: 
    ListNode* findNthNode(ListNode* head, int n){
        ListNode* temp = head;
        int cnt = 1;
        while(temp){
            if(cnt == n) return temp;
            temp = temp->next;
            cnt++;
        }
        return NULL;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;

        int len = 1;
        ListNode* tail = head;

        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        k = k % len;
        if(k == 0) return head;

        ListNode* newNode = findNthNode(head, len - k);

        // Make circular
        tail->next = head;

        // Break
        head = newNode->next;
        newNode->next = NULL;

        return head;
    }
};