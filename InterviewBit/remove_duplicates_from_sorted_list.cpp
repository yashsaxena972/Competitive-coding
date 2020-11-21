// Remove Duplicates from Sorted List
// Given a sorted linked list, delete all duplicates such that each element appear only once.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL){
        return A;
    }
    
    ListNode* curr;
    ListNode* temp;
    
    curr = A;
    
    while(curr->next != NULL){
        temp = curr->next;
        while(curr->val == temp->val){
            if(temp->next == NULL){
                curr->next = NULL;
                return A;
            }
            temp = temp->next;
        }
        curr->next = temp;
        curr = temp;
    }
    
    return A;
}
