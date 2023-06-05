/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
// First matrix should go from: (0,0) - (n/2-1,n/2-1)
// Second matrix should go from: (0,n/2) - (n/2-1,n-1)
// 3th matrix should go from: (n/2,n/2) - (n-1,n-1)
// 4th matrix should go from: (n/2,0) - (n-1,n/2-1)
class Solution {
public:
    bool allEqual(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int val=grid[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=val) return false;
            }
        }
        return true;
    }
    Node* construct(vector<vector<int>>& grid) {
        Node* root=new Node();
        int n=grid.size();
        if(allEqual(grid))
        {
            root->isLeaf=true;
            root->val=grid[0][0];
            return root;
        }
        else{
            // TopLeft
            vector<vector<int>> temp;
            for(int i=0;i<n/2;i++)
            {
                vector<int> temp1;
                for(int j=0;j<n/2;j++)
                {
                    temp1.push_back(grid[i][j]);
                }
                temp.push_back(temp1);
            }
            root->topLeft=construct(temp);
            // TopRight
            temp.clear();
            for(int i=0;i<n/2;i++)
            {
                vector<int> temp1;
                for(int j=(int)n/2;j<n;j++)
                {
                    temp1.push_back(grid[i][j]);
                }
                temp.push_back(temp1);
            }
            root->topRight =construct(temp);

            //BottomLeft
            temp.clear();
            for(int i=n/2;i<n;i++)
            {
                vector<int> temp1;
                for(int j=0;j<n/2;j++)
                {
                    temp1.push_back(grid[i][j]);
                }
                temp.push_back(temp1);
            }
            root->bottomLeft =construct(temp);
            //BottomRight
            temp.clear();
            for(int i=n/2;i<n;i++)
            {
                vector<int> temp1;
                for(int j=n/2;j<n;j++)
                {
                    temp1.push_back(grid[i][j]);
                }
                temp.push_back(temp1);
            }
            root->bottomRight =construct(temp);
        }
        return root;
    }
};