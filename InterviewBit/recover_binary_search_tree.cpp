// Recover Binary Search Tree
/*

Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored

Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST  

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ans;
    
    TreeNode *first = NULL, *last = NULL, *prev = NULL, *curr = A;
    
    stack<TreeNode*> st;
    bool isDone = false;
    
    while(!isDone){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            curr = st.top();
            st.pop();
            if(prev != NULL){
                if(prev->val > curr->val){
                    if(first == NULL){
                        first = prev;
                    }    
                    last = curr;
                }
            }
            prev = curr;
            curr = curr->right;
        }
        if(st.empty() &&  curr == NULL){
           isDone = true; 
        }
    }
    
    ans.push_back(first->val);
    ans.push_back(last->val);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}
