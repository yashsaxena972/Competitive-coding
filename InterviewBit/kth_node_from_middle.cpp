// Kth Node From Middle
/*

Given a linked list A of length N and an integer B.
You need to find the value of the Bth node from the middle towards the beginning of the Linked List A.
If no such element exists, then return -1.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    if(A->next == NULL){
        return -1;
    }
    ListNode* slow = A;
    ListNode* fast = A;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow;
    mid->next = NULL;
    slow = A;
    int len=0;
    while(slow != NULL){
        len++;
        slow = slow->next;
    }
    if(B>len)
        return -1;
    int i=1;
    slow =A;
    while(i<(len-B)){
        slow = slow->next;
        i++;
    }
    return slow->val;
}
