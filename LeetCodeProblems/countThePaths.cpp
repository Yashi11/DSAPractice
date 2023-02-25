class Solution {
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    if(s==d) return 1;
	    int cnt=0;
	    for(int i=0;i<edges.size();i++)
	    {
	        if(edges[i][0]==s){
	            //include
	            cnt+=possible_paths(edges,n,edges[i][1],d);
	        }
	    }
	    return cnt;
	}
};