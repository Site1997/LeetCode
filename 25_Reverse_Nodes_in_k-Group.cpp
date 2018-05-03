/* version 1 */
// non-recursion
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
            p = p->next; cnt ++;
        }
        return cnt;
    }
    
    void reverse(ListNode* bef_p, ListNode* cur_p, int mx) {
        if (mx <= 1)
            return ;
        ListNode* p1 = cur_p, *p2 = p1->next, *p3 = p2->next;
        for (int i=0; i<mx-1; i++) {
            p2->next = p1;
            if (i != mx-2) {
                p1 = p2;
                p2 = p3;
                p3 = p3->next;
            }
        }
        cur_p->next = p3;
        bef_p->next = p2;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        // init
        int len = get_len(head);
        ListNode* bef_head = new ListNode(0);
        bef_head->next = head;
        // solve
        ListNode* cur_p = head, *bef_p = bef_head;
        for (int i=0; i<len-k+1; i+=k) {
            reverse(bef_p, cur_p, k);
            bef_p = cur_p;
            cur_p = cur_p->next;
        }
        head = bef_head->next;
        delete bef_head;
        return head;
    }
};

/* version 2 */
// 1. notice the use of pointer, it is changing all the time
// 2. practice the recursion

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
    ListNode* first, *last;
    
    int get_len(ListNode* p) {
        int cnt = 0;
        while (p) {
            p = p->next; cnt ++;
        }
        return cnt;
    }
    
    void dfs(ListNode* p, int cur, int mx) {
        if (cur >= mx) {
            first = p;
            last = p->next;
        }
        else {
            dfs(p->next, cur+1, mx);
            p->next->next = p;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = get_len(head);
        for (int i=0; i<len-k+1; i+=k) {
            ListNode* cur_p = head, *bef_p = head;
            for (int j=0; j<i; j++) {
                bef_p = cur_p;
                cur_p = cur_p->next;
            }
            dfs(cur_p, 0, k-1);
            cur_p->next = last;
            if (i == 0)
                head = first;
            else
                bef_p->next = first;
        }

        return head;
    }
};
