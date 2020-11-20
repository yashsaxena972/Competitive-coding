// Sort Binary Linked List
/*

Given a Linked List A consisting of N nodes.
The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.
You need to sort the linked list and return the new linked list.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode* zd=new ListNode(8);
ListNode* od=new ListNode(9);

ListNode* crr=A,*z=zd,*o=od;
while(crr!=0){
    if(crr->val==0){
        z->next=crr;
        z=z->next;
    }
    else if(crr->val==1){
        o->next=crr;
        o=o->next;
    }
    crr=crr->next;
}
z->next=od->next;
o->next=NULL;
return zd->next;
}
