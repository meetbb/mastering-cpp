#include "TreesProblems.h"
#include <iostream>
#include <stack>
using namespace std;

void inorder(TreeNode* root, vector<int>& result) {
    if (root == NULL)
    {
        return;
    }
    
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

vector<int> TreesProblems::inorderTraversal(TreeNode *root) {
    /*
        This approach is a BRUTE-FORCE approach. It usually is recursive.
        The recursion often has time complexity O(n) because we eventually 
        traverse through every node in tree. And Space: O(n) because it 
        depends on call stack. Here O(n) is not constant. The best case would
        be O(log n) if the tree is balanced.
    */
    vector<int> result;
    inorder(root, result);
}

vector<int> TreesProblems::inorderTraversalItertive(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode *curr = root;

    while (curr != NULL || !st.empty())
    {
        // Step 1: Go LEFT as much as possible
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        
        // Step 2: Process node
        curr = st.top();
        st.pop();
        result.push_back(curr->val);

        // Step 3: Move RIGHT
        curr = curr->right;
    }
    return result;
    /*
        This approach isn't any different than recursive.
        It also takes same Space Complexity as recursive.
    */
}

vector<int> TreesProblems::morrisTraversal(TreeNode *root) {
    vector<int> result;
    TreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            result.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            // Find inorder predecessor
            TreeNode *pred = curr->left;
            while (pred->right != NULL && pred->right != curr)
            {
                pred = pred->right;
            }
            
            if (pred->right == NULL)
            {
                // Create thread
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // Remove thread
                pred->right = NULL;
                result.push_back(curr->val);
                curr = curr->right;
            }
            
        }
                
    }    
}

bool TreesProblems::isSameTree(TreeNode *p, TreeNode *q) {
    // Case 1: both NULL
    if (p == NULL && q == NULL)
    {
        return true;
    }
    
    // Case 2: One NULL
    if (p == NULL || q == NULL)
    {
        return false;
    }
    
    // Case 3: values differ
    if (p->val != q->val)
    {
        return false;
    }
    
    // Case 4: check subtrees
    return isSameTree(p->left, q->left) &&
    isSameTree(p->right, q->right);
}