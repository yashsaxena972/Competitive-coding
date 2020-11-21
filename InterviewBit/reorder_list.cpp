// Reorder List
// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int findLength(ListNode *temp){
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
} 
 
ListNode* Solution::reorderList(ListNode* A) {
    int len=findLength(A);
    ListNode *mid=A;
    int half;
    if(len&1){
        half=len/2+1;
    }
    else half=len/2;
    ListNode *prev=NULL;
    for(int i=0;i<half;i++){
     prev=mid;
     mid=mid->next;
    }
    prev->next=NULL;
    
    prev=NULL;
    ListNode *curr=mid;
    ListNode *next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    ListNode* t1=A;
    ListNode* t2=prev;
  
    while(t1!=NULL&&t2!=NULL){
        ListNode* temp1=t1->next;
        ListNode* temp2=t2->next;
        
        t1->next=t2;
        t2->next=temp1;
        
        t2=temp2;
        t1=temp1;
    }
    return A;
}
