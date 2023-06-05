// BFS Approach with modifications

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        map<int,int> mp;
        for(int i=0;i<N*2-1;i+=2)
        {
            mp[arr[i]]=arr[i+1];
        }
        int moves=0;
        queue<int> q;
        q.push(1);
        vector<bool> vis(30,false);
        vis[1]=true;
        bool found=false; // whether we found 30 or not
        while(!q.empty() && !found)
        {
            int sz=q.size();
            while(sz--)
            {
                int temp=q.front();
                q.pop();
                for(int i=1;i<7;i++)
                {
                    if(temp+i==30)
                    {
                        found = true;
                    }
                    else if(temp+i<30 && mp.find(temp+i)!=mp.end())
                    {
                        vis[mp[temp+i]]=true;
                        if(mp[temp+i]==30) found = true;
                        q.push(mp[temp+i]);
                    }
                    else if( temp+i<30 && mp.find(temp+i)==mp.end())
                    {
                        vis[temp+i]=true;
                        q.push(temp+i);
                    }
                }
            }
             moves++;
        }
        if(found) return moves;
        else return -1;
    }
};