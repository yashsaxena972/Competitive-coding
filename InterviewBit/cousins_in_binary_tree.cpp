// Cousins in Binary Tree
/*

Given a Binary Tree A consisting of N nodes.
You need to find all the cousins of node B.

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Output
 [6, 7]

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
vector<int> Solution::solve(TreeNode* A, int B) {
    queue<TreeNode*>q;
    TreeNode* curr=A;

    q.push(A);
    int notv=-1;

    vector<int>v;
    vector<int>arr;
 
    int count=0;

    v.push_back(1);
    arr.push_back(curr->val);
    int levels=-1;
    while(q.size()>0){
        curr=q.front();
        q.pop();
   
        if(curr->left){
            q.push(curr->left);
            v.push_back(v[count]+1);
            arr.push_back(curr->left->val);
            if(curr->left->val==B){
                levels=v[count]+1;
                if(curr->right){
                    notv=curr->right->val;
                }
            }
        }  
        if(curr->right){
            q.push(curr->right);
            v.push_back(v[count]+1);
            arr.push_back(curr->right->val);
            if(curr->right->val==B){
                levels=v[count]+1;
                if(curr->left){
                    notv=curr->left->val;
                }
            }
        }
        count+=1;
    }

    vector<int>ans;
    if(levels==-1)
        return ans;
    for(int i=0;i<v.size();i++){
        if(v[i]==levels && arr[i]!=notv && arr[i]!=B){
            ans.push_back(arr[i]);
        }
    }
    
    return ans;
}
