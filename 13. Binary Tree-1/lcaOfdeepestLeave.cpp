#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val == p->val or root->val == q->val) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* rght = lowestCommonAncestor(root->right, p, q);
        if(not left) return rght;
        else if(not rght) return left;
        else return root;
    }
    int level(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<pair<TreeNode*, int>> q; q.push({root, 1});
        int lev = level(root);
        vector<TreeNode*> result;
        while(q.size()){
            TreeNode* parent = q.front().first; int n = q.front().second; q.pop();
            if(n == lev) result.push_back(parent);
            if(parent->left){
                q.push({parent->left, n+1});
            }
            if(parent->right){
                q.push({parent->right, n+1});
                
            }
        }
        for(auto it : result) cout<<it->val<<" ";
        if(result.size() > 1) return lowestCommonAncestor(root, result[0], result.back());
        else return result[0];
    }
};


int main(){

}