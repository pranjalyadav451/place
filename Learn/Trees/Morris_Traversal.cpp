#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

vector<int> get_in_order(TreeNode *root) {
    vector<int> inorder;
    TreeNode *cur = root;
    while (cur != NULL) {
        if (cur->left == NULL) {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode *leftChild = cur->left;
            while (leftChild->right and leftChild->right != cur) {
                leftChild = leftChild->right;
            }
            if (leftChild->right == NULL) {
                leftChild->right = cur;
                cur = cur->left;
            }
            else {
                leftChild->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}


int main() {

}