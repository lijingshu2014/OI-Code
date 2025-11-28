#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int key, count;
    TreeNode *left, *right;
    TreeNode(int v): key(v) {count = 1; left = right = nullptr;}
    TreeNode() = default;
};

TreeNode* root;

TreeNode* insert(TreeNode *p, int value) {
    if(p == nullptr) {
        p = new TreeNode(value);
        return p;
    }
    if(value < p->key) {
        p->left = insert(p->left, value);
    }
    else if(value > p->key) {
        p->right = insert(p->right, value);
    }
    else {
        p->count++;
    }
    return p;
}

int find(TreeNode *p, int value) {
    if(p == nullptr) return 0;
    if(value == p->key) return p->count;
    if(value < p->key) return find(p->left, value);
    if(value > p->key) return find(p->right, value);
}

TreeNode *findMaxNode(TreeNode *p) {
    if(p == nullptr) return p;
    if(p->right) return findMaxNode(p->right);
    return p;
}

TreeNode *findMinNode(TreeNode *p) {
    if(p == nullptr) return p;
    if(p -> left) return findMinNode(p->left);
    return p;
}

TreeNode* remove(TreeNode *p, int value) {
    if(p == nullptr) return p;
    if(value < p->key) {
        remove(p->left, value);
    }
    else if(value > p->key) {
        remove(p->right, value);
    }
    else {
        if(p->count > 1) {
            p->count--;
            return p;
        }
        if(p->left == nullptr && p->right == nullptr) {
            delete p;
            return nullptr;
        }
        else if(p->left == nullptr && p->right != nullptr) {
            TreeNode *tmp = p->right;
            delete p;
            return tmp;
        }
        else if(p->left != nullptr && p->right == nullptr) {
            TreeNode *tmp = p->left;
            delete p;
            return tmp;
        }
        else {
            TreeNode *re = findMinNode(p->right);
            p->key = re->key, p->count = re->count;
            re->count = 1;
            p->right = remove(p->right, re->key);
        }
    }
}

int main() {
    root = remove(root, 1);
}