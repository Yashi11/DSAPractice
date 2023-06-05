class Solution {
    public:
        int find_parents(int a,vector<int>& parents)
        {
            if(parents[a]==-1) return a;
            else return parents[a]=find_parents(parents[a],parents);
        }
        void union_set(int a,int b,vector<int>& parents,vector<int>& size)
        {
            int x=find_parents(a,parents);
            int y=find_parents(b,parents);
             if(x!=y)
             {
                 if(x>y) swap(x,y);
                 parents[y]=x;
                 size[x]+=size[y];
             }
        }
        long long int numberOfPairs(vector<vector<int>> &pairs,int p,int n)
        {
            // code here
            vector<int> parents(n,-1);
            vector<int> size(n,1);
            
            for(auto pair:pairs)
            {
                union_set(pair[0],pair[1],parents,size);
            }
            
            long long int ans=0;
            long long int total=0;
            for(int i=0;i<n;i++)
            {
               if(parents[i]!=-1) continue;
                ans+=total*size[i];
                total+=size[i];
            }
            return ans;
        }
};