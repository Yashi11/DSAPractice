lass Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s;
        dist[S]=0;
        s.insert({0,S});
        while(!s.empty())
        {
            auto x=*(s.begin());
            int distanceOfNode=x.first;
            int node=x.second;
            s.erase(s.begin());
             for(auto j:adj[node])
            {
                if(dist[j[0]]>distanceOfNode+j[1]){
                    if(s.find({dist[j[0]],j[0]})!=s.end()) s.erase({dist[j[0]],j[0]});
                    dist[j[0]]=distanceOfNode+j[1];
                    s.insert({dist[j[0]],j[0]});
                    
                }
            }
        }
        return dist;
    }
};