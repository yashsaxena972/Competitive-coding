// Partition List
/*

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* c1=NULL,*c2=NULL;
    ListNode* l1=c1,*l2=c2;
    ListNode* temp=A;
    while(temp!=NULL){
        if(temp->val<B){
            if(c1==NULL){
                c1=new ListNode(temp->val);
                l1=c1;
            }
            else{
                l1->next=new ListNode(temp->val);
                l1=l1->next;
            }
        }
        else{
            if(c2==NULL){
                c2=new ListNode(temp->val);
                l2=c2;
            }
            else{
                l2->next=new ListNode(temp->val);
                l2=l2->next;
            }
        }
        ListNode* x=temp;
        temp=temp->next;
        free(x);
        A=temp;
    }
    if(c1==NULL) return c2;
    l1->next=c2;
    return c1;
}
