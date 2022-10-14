//----------------------------O(n) & O(1)-------------------------------------
// brute force

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while(curr != NULL){
            len++;
            curr = curr->next;
        }
        if(len == 1) return NULL;
        int mid = len/2;
        curr = head;
        int i=0;
        while(i != mid-1){
            i++;
            curr = curr->next;
        }
	   ListNode* temp = curr->next;
        curr->next = temp->next;
	   delete(temp);
        return head;
    }
};


//--------------------------------------------------------------------------
//slow and fast pointer with dummy node


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy, *fast = head;
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete(temp);
        return head;
    }
};



//--------------------------------------------------------------------------
//Slow and fast pointer without dummy

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)
            return nullptr;
        auto slow = head, fast = head->next->next;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};