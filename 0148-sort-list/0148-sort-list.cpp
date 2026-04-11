class Solution {
public:
    // Find middle of linked list
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted linked lists
    ListNode* merge2LL(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* temp = dummy;

        while(left && right){
            if(left->val < right->val){
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if(left) temp->next = left;
        else temp->next = right;

        return dummy->next;
    }

    // Merge sort on linked list
    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* mid = findMiddle(head);

        ListNode* right = mergeSort(mid->next);

        mid->next = nullptr;

        ListNode* left = mergeSort(head);

        return merge2LL(left,right);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};