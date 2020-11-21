// Next Greater Number BST
// ie Inorder Successor in O(h)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* searchNode(TreeNode* root, int B){
    if(root->val == B){
        return root;
    }
    else if(root->val < B){
        return searchNode(root->right, B);
    }
    return searchNode(root->left, B);
} 
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* current = searchNode(A, B);
    TreeNode* prev = NULL;
    TreeNode* ancestor = A;
    TreeNode* successor = NULL;
    
    if(current == NULL){
        return NULL;
    }
    // if right subtree exists
    else if(current->right != NULL){
        prev = current->right;
        TreeNode* temp = current->right;
        while(temp != NULL){
            prev = temp;
            temp = temp->left;
        }
        return prev;
    }
    // if right subtree doesn't exist, find the deepest ancestor of the 
    // current node
    else{
        while(ancestor != current){
            if(ancestor->val < B){
                ancestor = ancestor->right;
            }
            else{ // ancestor->val > B
                successor = ancestor;
                ancestor = ancestor->left;
            }
        }
    }
    
    return successor;
}
