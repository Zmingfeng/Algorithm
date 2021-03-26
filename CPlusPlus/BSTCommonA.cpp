#include<iostream>


using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val, TreeNode* _left = nullptr, TreeNode* _right = nullptr) : val(_val), left(_left), right(_right) {}
    ~TreeNode() {}
};

TreeNode* ret = nullptr;

void dfs(TreeNode* root, TreeNode* p, TreeNode*  q) {
    if(!root) return;
    if(p->val < root->val && q->val < root->val) {
        dfs(root->left, p, q);
    }
    else if(p->val > root->val && q->val > root->val) {
        dfs(root->right, p, q);
    }
    else {
        ret = root;
    }
}

TreeNode* bstCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || !p || !q) return ret;
    dfs(root, p, q);
    return ret;
}

int main() {
    return 0;
}