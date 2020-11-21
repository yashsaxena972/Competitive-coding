// Vertical Order traversal of Binary Tree
/*

Given a binary tree A consisting of N nodes, return a 2-D array denoting the 
vertical order traversal of A.

      6
    /   \
   3     7
  / \     \
 2   5     9

Output
  [
    [2],
    [3],
    [6, 5],
    [7],
    [9]
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
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > v;
    if(A == NULL)return v;
    
    queue<pair <TreeNode*, int> > q;
    q.push({A, 0});
    
    map<int, vector<int> > mp;
    while(!q.empty()){
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        
        if(temp.first->left){
            q.push({temp.first->left, temp.second-1});
        }
        if(temp.first->right){
            q.push({temp.first->right, temp.second+1});
        }
        
        mp[temp.second].push_back(temp.first->val);
    }

    for(map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); it++){
        v.push_back(it->second);
    }
    return v;
}
