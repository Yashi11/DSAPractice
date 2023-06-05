// Graph fundamentals in Binary Tree [IMP]
class Solution{

    public:
    map<Node*,Node*> parent;
    unordered_set<Node*> vis;
    Node* dfs(Node* root,int home)
    {
        if(!root) return NULL;
        if(root->data==home) return root;
        if(root->left) {
            parent[root->left]=root;
            Node* ans1=dfs(root->left,home);
            if(ans1!=NULL) return ans1;}
        if(root->right) {
            parent[root->right]=root;
            Node* ans2=dfs(root->right,home);
            if(ans2!=NULL) return ans2;}
    }
    int help(Node* root,int k)
    {
        if(root==NULL || k<0 ||vis.find(root)!=vis.end()) return 0;
        vis.insert(root);
        int res=root->data;
        res+=help(parent[root],k-1)+help(root->left,k-1)+help(root->right,k-1);
        return res;
    }
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        parent[root]=NULL;
        Node* homeNode=dfs(root,home);
        return help(homeNode,k);
    }


};