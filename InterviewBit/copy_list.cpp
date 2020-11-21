// Copy List

/*

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.

*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* curr = A, *temp; 
  
    // insert additional node after 
    // every node of original list 
    while (curr) 
    { 
        temp = curr->next; 
  
        // Inserting node 
        curr->next = new RandomListNode(curr->label); 
        curr->next->next = temp; 
        curr = temp; 
    } 
  
    curr = A; 
  
    // adjust the random pointers of the 
    // newly added nodes 
    while (curr) 
    { 
        if(curr->next) 
            curr->next->random = curr->random ? curr->random->next : curr->random; 
  
        // move to the next newly added node by 
        // skipping an original node 
        curr = curr->next?curr->next->next:curr->next; 
    } 
  
    RandomListNode* original = A, *copy = A->next; 
  
    // save the start of copied linked list 
    temp = copy; 
  
    // now separate the original list and copied list 
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp; 
}
