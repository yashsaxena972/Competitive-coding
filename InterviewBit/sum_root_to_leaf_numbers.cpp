// Sum Root to Leaf Numbers
/*

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

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
 
void sumleaf(TreeNode *root,long long sum,long long &ans)
{
    if(root==NULL)
        return ;
    sum=(sum*10+root->val)%1003;
    
    if(root->left==NULL && root->right==NULL){
        ans=ans+sum;
        return;
    }

    sumleaf(root->left,sum,ans);
    sumleaf(root->right,sum,ans);
}
 
int Solution::sumNumbers(TreeNode* A) {
    long long sum=0;
    long long  ans=0;
    sumleaf(A,sum,ans);
    return (int)ans%1003; 
}
