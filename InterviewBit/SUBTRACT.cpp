// SUBTRACT
// Given a singly linked list, modify the value of first half nodes such that :
// 1st node’s new value = the last node’s value - first node’s current value
// 2nd node’s new value = the second last node’s value - 2nd node’s current value,
// and so on …
// Given linked list 1 -> 2 -> 3 -> 4 -> 5,
// You should return 4 -> 2 -> 3 -> 4 -> 5


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool solve(ListNode*& first, ListNode* second){
    if(second->next == NULL){
        first->val = second->val - first->val;
        return true;
    }
    else{
        if(solve(first,second->next)){
            if(first == second || first->next == second){
                return false;
            }
            else{
                first = first->next;
                first->val = second->val - first->val;
                return true;
            }
        }
        else{
            return false;
        }
    }
} 
 
ListNode* Solution::subtract(ListNode* A) {
    if(!A || A->next == NULL){
        return A;
    }
    
    ListNode *head = A;
    solve(head,head->next);
    return A;
}
