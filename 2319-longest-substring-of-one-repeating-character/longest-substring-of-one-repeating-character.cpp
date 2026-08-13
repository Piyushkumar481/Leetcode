class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;
        int leftLen;
        int rightLen;
        int maxLen;
        int len;
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        Node c;

        c.len = a.len + b.len;
        c.leftChar = a.leftChar;
        c.rightChar = b.rightChar;

        c.leftLen = a.leftLen;
        c.rightLen = b.rightLen;

        c.maxLen = max(a.maxLen, b.maxLen);

        if(a.rightChar == b.leftChar)
        {
            c.maxLen = max(c.maxLen, a.rightLen + b.leftLen);

            if(a.leftLen == a.len)
            {
                c.leftLen = a.len + b.leftLen;
            }

            if(b.rightLen == b.len)
            {
                c.rightLen = b.len + a.rightLen;
            }
        }

        return c;
    }

    void build(string& s, int node, int l, int r) {

        if(l == r)
        {
            tree[node] = {s[l], s[l], 1, 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int index, char ch) {

        if(l == r)
        {
            tree[node] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        if(index <= mid)
        {
            update(node * 2, l, mid, index, ch);
        }
        else
        {
            update(node * 2 + 1, mid + 1, r, index, ch);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {

        int n = s.size();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for(int i = 0; i < queryIndices.size(); i++)
        {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);

            ans.push_back(tree[1].maxLen);
        }

        return ans;
    }
};