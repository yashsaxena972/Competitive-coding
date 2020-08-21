// Reverse Link List II
// Reverse a linked list from position m to n. Do it in-place and in one-pass.
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
// return 1->4->3->2->5->NULL.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* curr = A;
    ListNode* prev;
    ListNode* temp;
    ListNode* start = NULL;
    ListNode* startTemp;
    ListNode* end;
    ListNode* endTemp;
    
    if(A == NULL){
        return NULL;
    }
    
    int length = 0;
    
    while(length < B){
        length++;
        if(length == B-1){
            start = curr;
        }
        else if(length == B){
            startTemp = curr;
        }
        prev = curr;
        curr = curr->next;
    }
    
    while(length < C){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        length++;
        if(length == C){
            endTemp = prev;
            end = curr;
            startTemp->next = end;
            if(start != NULL){
                start->next = endTemp;
            }
            else if(start == NULL){
                A = endTemp;
            }
        }
    }
    
    return A;
}
