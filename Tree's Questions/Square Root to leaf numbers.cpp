#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(TreeNode* root,int curr) {
        //base case
        if(root == NULL) return 0;
        
        curr = (curr*10) + root->val;
        //root ka left and right is null (leaf node) then return curr
        if(root->left == NULL && root->right == NULL) return curr;

        //store the sum of left part as well as right part
        int left = solve(root->left,curr);
        int right = solve(root->right,curr);


        return left+right;

    }
public:
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};