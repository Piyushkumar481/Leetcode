/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == NULL)
        {
            return NULL;
        }

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        Node* newNode = new Node(node->val);

        mp[node] = newNode;
        q.push(node);

        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            for(Node* neighbor : temp->neighbors)
            {
                if(mp.find(neighbor) == mp.end())
                {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                mp[temp]->neighbors.push_back(mp[neighbor]);
            }
        }

        return newNode;
    }
};