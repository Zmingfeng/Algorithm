#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val, TreeNode* _left = nullptr, TreeNode* _right = nullptr) : val(_val), left(_left), right(_right) {}
    ~TreeNode() {}
};

TreeNode* ret = nullptr;
bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return false;
    bool lhs = dfs(root->left, p, q);
    bool rhs = dfs(root->right, p, q);
    if((lhs && rhs) || ((root == p || root == q) && (lhs || rhs))) {
        ret = root;
    } 
    return root == p || root == q || lhs || rhs;
}

TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || !p || !q) return ret;
    dfs(root, p ,q);
    return ret;
}

int main() {
    return 0;
}