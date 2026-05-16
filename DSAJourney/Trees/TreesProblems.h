#ifndef TREES_PROBLEMS_H
#define TREES_PROBLEMS_H
#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreesProblems
{
public:
    std::vector<int> inorderTraversal(TreeNode *root);
    std::vector<int> inorderTraversalItertive(TreeNode *root);
    std::vector<int> morrisTraversal(TreeNode *root);
    bool isSameTree(TreeNode *p, TreeNode *q);
};

#endif