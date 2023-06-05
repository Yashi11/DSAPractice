class Solution{
public:   
    int countNodes(Node* root)
    {
        int cnt=0;
       if(root==NULL) return cnt;
      else{
          if(root->left) cnt+=countNodes(root->left);
          if(root->right) cnt+=countNodes(root->right);
          return cnt+1;
      }
    }
    bool bfs(Node* root,int cnt)
    {
        queue<Node*> q;
        q.push(root);
        while(cnt--)
        {
            Node* front = q.front();
            q.pop();
            if(front==NULL) return false;
            if(front->left) q.push(front->left);
            else q.push(NULL);
            if(front->right) q.push(front->right);
            else q.push(NULL);
        }
        return true;
    }
    bool isCompleteBT(Node* root){
        //code here
       int cnt=countNodes(root);
        return bfs(root,cnt);
    }
};