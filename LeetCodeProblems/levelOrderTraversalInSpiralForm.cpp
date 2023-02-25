// Naive Approach using 1 Queue ->Gave TLE
// vector<int> findSpiral(Node *root)
// {
//     //Your code here
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);
    
//     bool R2L=false;
//     vector<int> ans;
//     vector<int> ansT;
//     while(!q.empty())
//     {
//       Node* temp=q.front();
//       q.pop();
//       if(temp==NULL && !q.empty())
//       {
//           q.push(NULL);
//           if(!R2L) reverse(ansT.begin(),ansT.end());
//           R2L=!R2L;
//           for(auto i:ansT)
//           {
//               ans.push_back(i);
//           }
//           ansT.clear();
//       }
//       else if(temp!=NULL)
//       {
//           if(temp->left) q.push(temp->left);
//             if(temp->right) q.push(temp->right);
//           ansT.push_back(temp->data);
//       }
       
//     }
//     if(!R2L) reverse(ansT.begin(),ansT.end());
//           R2L=!R2L;
//           for(auto i:ansT)
//           {
//               ans.push_back(i);
//           }
//           ansT.clear();
//     return ans;
    
// }

// 2nd Approach using 2 stacks

vector<int> findSpiral(Node *root)
{
    //Your code here
    
    vector<int> ans;
    if(root==NULL) return ans;
    
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);
    
    while(!st1.empty() || !st2.empty())
    {
        while(!st1.empty())
        {
            if(st1.top()->right) st2.push(st1.top()->right);
            if(st1.top()->left) st2.push(st1.top()->left);
            
            ans.push_back(st1.top()->data);
            st1.pop();
        }
        while(!st2.empty())
        {
            if(st2.top()->left) st1.push(st2.top()->left);
            if(st2.top()->right) st1.push(st2.top()->right);
            
            ans.push_back(st2.top()->data);
            st2.pop();
        }
    }
    return ans;
}

