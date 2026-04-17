class Solution {
private:
    // Helper to get kth node from current
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {
            // Find kth node
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break;

            ListNode* groupNext = kth->next;

            // Reverse group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Reconnect
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy->next;
    }
};