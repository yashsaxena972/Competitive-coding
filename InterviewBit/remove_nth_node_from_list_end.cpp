// Remove Nth Node from List End
// Given a linked list, remove the nth node from the end of list and return its head.
// For example,
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // To store length of the linked list 
    int len = 0; 
    ListNode* tmp = A; 
    while (tmp != NULL) { 
        len++; 
        tmp = tmp->next;  
    } 
      
    // B > length, then we can't remove node 
    if (B > len)  
    { 
        return removeNthFromEnd(A,len);
    } 
      
    // We need to remove head node 
    else if (B == len) { 
          
        // Return head->next 
        return A->next;  
          
    } 
    else 
    { 
        // Remove len - B th node from starting 
        int diff = len - B;           
        ListNode* prev= NULL;        
        ListNode* curr = A;          
        for(int i = 0;i < diff;i++){ 
            prev = curr;             
            curr = curr->next;       
        } 
        prev->next = curr->next; 
        return A; 
    }
}
