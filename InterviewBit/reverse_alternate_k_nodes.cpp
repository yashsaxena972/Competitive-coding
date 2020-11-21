// Reverse Alternate K Nodes
/*

Given a linked list A of length N and an integer B.
You need to reverse every alternate B nodes in the linked list A.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode *rev(ListNode *head,int y, bool r)
 {
    if(!head) return head;
    if(r)
    {
        ListNode *a = head,*b=NULL,*c=NULL;
        int x = y;
        while(a && x--)
        {
            b = a;
            a = a->next;
            b->next = c;
            c = b;
        }
        head->next = rev(a,y,!r);
        return b;
     }
     else
     {
        ListNode *a = head,*prev = NULL;
        int x = y;
        while(x-- && a)
        {
            prev = a;
            a = a->next;
        }
        prev->next = rev(a,y,!r);
        return head;
        
     }
   return NULL;
 } 
 
ListNode* Solution::solve(ListNode* A, int B) {
    bool r = 1;
    if(B <= 1 || !A) return A;
    return rev(A,B,r);
}