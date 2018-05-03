// it's the same as the problem: Reverse Nodes in k-Group
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int get_len(ListNode* p) {
        int cnt = 0;
        while (p) {
            cnt ++; p = p->next;
        }
        return cnt;
    }
    
    void reverse(ListNode* pre_p, ListNode* cur_p) {
        ListNode* p1 = cur_p, *p2 = p1->next, *p3 = p2->next;
        p2->next = p1;
        pre_p->next = p2;
        cur_p->next = p3;
    }
    
    ListNode* swapPairs(ListNode* head) {
        int len = get_len(head);
        ListNode* pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode* cur_p = head, * pre_p = pre_head;
        for (int i=1; i<len; i+=2) {
            reverse(pre_p, cur_p);
            pre_p = cur_p;
            cur_p = cur_p->next;
        }
        head = pre_head->next;
        delete pre_head;
        return head;
    }
};
