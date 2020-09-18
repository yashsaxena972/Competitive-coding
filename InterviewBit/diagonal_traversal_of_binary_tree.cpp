// Diagonal Traversal
/*

            1
          /   \
         4      2
        / \      \
       8   5      3
          / \    /
         9   7  6


Output
 [1, 2, 3, 4, 5, 7, 6, 8, 9]         

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
vector<int> Solution::solve(TreeNode* A) {
    TreeNode *root=A;
    queue<TreeNode *> q;
    q.push(root);
    vector<int> v;
    while(!q.empty()){
        root=q.front();
        q.pop();
        while(root!=NULL){
            v.push_back(root->val);
            if(root->left!=NULL)
                q.push(root->left);
            root=root->right;
        }
    }
    return v;
}
