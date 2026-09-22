class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];
    };

    int k;
    int size;
    vector<Node> tree;

    Node mergeNode(const Node& a, const Node& b) {
        Node res{};
        res.prod = (a.prod * b.prod) % k;

        for(int i = 0; i < k; i++)
            res.cnt[i] = a.cnt[i];

        for(int i = 0; i < k; i++) {
            int r = (a.prod * i) % k;
            res.cnt[r] += b.cnt[i];
        }

        return res;
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();
        size = 1;

        while(size < n)
            size *= 2;

        tree.resize(2 * size);

        for(int i = 0; i < n; i++) {
            tree[size + i].prod = nums[i] % k;
            tree[size + i].cnt[nums[i] % k] = 1;
        }

        for(int i = size - 1; i >= 1; i--)
            tree[i] = mergeNode(tree[i * 2], tree[i * 2 + 1]);

        vector<int> ans;

        for(auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            int pos = size + index;

            tree[pos] = Node{};
            tree[pos].prod = value % k;
            tree[pos].cnt[value % k] = 1;

            pos /= 2;

            while(pos >= 1) {
                tree[pos] = mergeNode(tree[pos * 2], tree[pos * 2 + 1]);
                pos /= 2;
            }

            int l = size + start;
            int r = size + n;

            Node left{};
            left.prod = 1;

            Node right{};
            right.prod = 1;

            while(l < r) {
                if(l % 2 == 1) {
                    left = mergeNode(left, tree[l]);
                    l++;
                }

                if(r % 2 == 1) {
                    --r;
                    right = mergeNode(tree[r], right);
                }

                l /= 2;
                r /= 2;
            }

            Node res = mergeNode(left, right);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};