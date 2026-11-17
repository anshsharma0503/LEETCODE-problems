class Solution {
public:

    ListNode * reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr  != nullptr){
            ListNode* next = curr -> next;

            curr -> next = prev;
            prev = curr;
            curr = next;            
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow->next);
        
        ListNode* first = head;
        ListNode* second = secondHalf;

        while (second != nullptr) {
            if (first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};