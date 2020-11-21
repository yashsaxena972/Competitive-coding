// Insertion Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void insert(int a, ListNode* A) {
    ListNode* ptr1 = A;
    ListNode* ptr2 = A->next;
    while(ptr2!=NULL && a > ptr2->val) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr1->next = new ListNode(a);
    ptr1->next->next = ptr2;
} 
 
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* sortedList = new ListNode(INT_MIN);

    while(A!=NULL) {
        insert(A->val, sortedList);
        A = A->next;
    }

    return sortedList->next;
}
