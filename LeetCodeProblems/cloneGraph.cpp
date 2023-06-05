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
    Node* dfs(Node* node,map<Node*,Node*>& vis)
    {
        vector<Node*> neighbors1;
        Node* clone=new Node(node->val);
        vis[node]=clone;

        for(auto n:node->neighbors)
        {
            if(vis.find(n)==vis.end())
            {
                neighbors1.push_back(dfs(n,vis));
            }
            else{
                neighbors1.push_back(vis[n]);
            }
        }
        clone->neighbors = neighbors1;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        
        map<Node*,Node*> vis;
        if(node==NULL) return NULL;
        else if(node->neighbors.size()==0)
        {
            Node* clone=new Node(node->val);
            return clone;
        }
        return dfs(node,vis);
    }
};