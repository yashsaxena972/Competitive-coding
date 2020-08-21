// List Cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode* temp=A;
    set<ListNode *> s;
    while(temp)
    {
        s.insert(temp);
        temp=temp->next;
        if(s.find(temp)!=s.end())
        {
            return temp;
        }
    
    }
    return NULL;
}
