#include<iostream>
#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {}
    ~TreeNode() {}
};


void morrishIn(TreeNode* root) {
    if(!root) return;
    TreeNode* cur = root;
    TreeNode* next = nullptr;
    while(cur) {
        next = cur->left;
        if(next) {
            while(next->right && next->right != cur) {
                next = next->right;
            }
            if(!next->right) {
                next->right = cur;
                continue;
            }
            else {
                next->right = nullptr;
            }
        }
        cout << cur->val << ' ';
        cur = cur->right;
    }
}


int main() {
    return 0;
}