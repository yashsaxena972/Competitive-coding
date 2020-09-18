// Populate Next Right Pointers Tree
/*

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no 
next right node, the next pointer should be set to NULL.

Given the following binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
TreeLinkNode * connected ( TreeLinkNode *root){
        
        if(root==NULL) 
            return NULL;
            
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeLinkNode * cur = q.front();
            q.pop();
            if(cur==NULL){
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
           
            if(cur) 
                cur->next = q.front();
            if(cur){
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
           }
        }
}
 
void Solution::connect(TreeLinkNode* A) {
    A = connected(A);
}
