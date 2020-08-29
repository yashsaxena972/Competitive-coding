// Level Order

/*

Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

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
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    vector<vector<int> > ans;
    vector<int> temp;
    
    // Base Case 
    if (A == NULL){
        return ans;  
    }  
  
    // Create an empty queue for level order traversal 
    queue<TreeNode *> q; 
    queue<int> level;
  
    // Enqueue Root and initialize height 
    q.push(A); 
    level.push(0);
  
    while (q.empty() == false) 
    { 
        // Print front of queue and remove it from queue 
        TreeNode *node = q.front(); 
        int l = level.front();
        
        if(ans.size() != l+1){
            ans.push_back(temp);
        } 
        ans[l].push_back(node->val);
  
        /* Enqueue left child */
        if (node->left != NULL){
            q.push(node->left); 
            level.push(l+1);
        }
            
  
        /*Enqueue right child */
        if (node->right != NULL){
            q.push(node->right); 
            level.push(l+1);
        } 
          
        q.pop();
        level.pop();
    } 
    
    return ans;
}
