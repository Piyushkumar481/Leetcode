/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void preorder(TreeNode* root, string& s)
    {
        if(root == NULL)
        {
            return;
        }

        s = s + to_string(root->val) + " ";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s = "";

        preorder(root, s);

        return s;
    }

    TreeNode* build(vector<int>& nums, int& i, int low, int high)
    {
        if(i >= nums.size())
        {
            return NULL;
        }

        if(nums[i] < low || nums[i] > high)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(nums[i]);

        i++;

        root->left = build(nums, i, low, root->val);
        root->right = build(nums, i, root->val, high);

        return root;
    }

    TreeNode* deserialize(string data) {

        if(data == "")
        {
            return NULL;
        }

        vector<int> nums;

        string temp = "";

        for(int i = 0; i < data.size(); i++)
        {
            if(data[i] == ' ')
            {
                nums.push_back(stoi(temp));
                temp = "";
            }
            else
            {
                temp = temp + data[i];
            }
        }

        int i = 0;

        return build(nums, i, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;