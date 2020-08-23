// Rotate List
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    // If the linked list is empty 
    if (!A) 
        return A; 
  
    // len is used to store length of the linked list 
    // tmp will point to the last node after this loop 
    ListNode* tmp = A; 
    int len = 1; 
    while (tmp->next != NULL) { 
        tmp = tmp->next; 
        len++; 
    } 
  
    // If k is greater than the size 
    // of the linked list 
    if (B > len) 
        B = B % len; 
  
    // Subtract from length to convert 
    // it into left rotation 
    B = len - B; 
  
    // If no rotation needed then 
    // return the head node 
    if (B == 0 || B == len) 
        return A; 
  
    // current will either point to 
    // kth or NULL after this loop 
    ListNode* current = A; 
    int cnt = 1; 
    while (cnt < B && current != NULL) { 
        current = current->next; 
        cnt++; 
    } 
  
    // If current is NULL then k is equal to the 
    // count of nodes in the list 
    // Don't change the list in this case 
    if (current == NULL) 
        return A; 
  
    // current points to the kth node 
    ListNode* kthnode = current; 
  
    // Change next of last node to previous head 
    tmp->next = A; 
  
    // Change head to (k+1)th node 
    A = kthnode->next; 
  
    // Change next of kth node to NULL 
    kthnode->next = NULL; 
  
    // Return the updated head pointer 
    return A; 
}
