// K reverse linked list
// Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,
// You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int findLen(ListNode *temp){
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
} 

ListNode* rev(ListNode *A){
    ListNode *prev=NULL;
    ListNode *curr=A;
    ListNode *next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
 
ListNode* reverseBetween(ListNode* A, int m, int n) {
      if(m==n) return A;
    ListNode *temp=A,*first=A,*last=A,*prev=NULL;
    int i=1;
    for(;i<m;i++){
     prev=temp;
     temp=temp->next;
    }
   
   first=temp;
   
    for(;i<n;i++)
     temp=temp->next;
    last=temp;
    
    ListNode* next=last->next;
    last->next=NULL;
    
    first=rev(first);
    
    if(prev!=NULL)prev->next=first;
    else A=first;
    temp=first;
    while(temp->next!=NULL)
     temp=temp->next;
    
    temp->next=next;
    return A;
}
 
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode *res=A;
    int n=findLen(A);
    int x=1;
    while(x<=n-B+1){
        res=reverseBetween(res,x,x+B-1);
        x+=B;
    }
    return res;
}
