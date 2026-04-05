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
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        ListNode* mid = findMiddle(head);
        ListNode* newHead = reverse(mid->next);
        ListNode* second = newHead;
        while (second) {
            if (first->val != second->val) {
                reverse(newHead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        reverse(newHead);
        return true;
    }
};