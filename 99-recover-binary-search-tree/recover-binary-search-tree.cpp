/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inorder(TreeNode* root, vector<TreeNode*>& ans)
    {
        if(root == NULL)
        {
            return;
        }

        inorder(root->left, ans);

        ans.push_back(root);

        inorder(root->right, ans);
    }

    void recoverTree(TreeNode* root) {

        vector<TreeNode*> ans;

        inorder(root, ans);

        TreeNode* first = NULL;
        TreeNode* second = NULL;

        for(int i = 1; i < ans.size(); i++)
        {
            if(ans[i]->val < ans[i-1]->val)
            {
                if(first == NULL)
                {
                    first = ans[i-1];
                }

                second = ans[i];
            }
        }

        swap(first->val, second->val);
    }
};