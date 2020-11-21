// Remove Duplicates from Sorted List II
// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A || !A->next)
        return A;
        
    ListNode* fakeHead = new ListNode(0);
    fakeHead->next = A;
    ListNode* prev = fakeHead;
    while (A)
    {
        while (A->next && A->val == A->next->val)
            A = A->next;
        
        if (prev->next == A)
            prev = prev->next; 
        else 
            prev->next = A->next;
            
        A = A->next;
    }
    return fakeHead->next;
}
