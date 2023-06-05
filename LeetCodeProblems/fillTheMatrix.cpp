// Naive Approach: Use BFS
// class Solution{   
// public:
//     int minIteration(int N, int M, int x, int y){    
//         // code here
//         queue<pair<pair<int,int>,int>> q;
//         set<pair<int,int>> vis;
//         q.push({{x,y},0});
//         int drow[]={-1,0,+1,0};
//         int dcol[]={0,-1,0,+1};
//         int ans=0;
//         while(!q.empty())
//         {
//             int r=q.front().first.first;
//             int c=q.front().first.second;
//             int itr=q.front().second;
//             vis.insert({r,c});
//             q.pop();
//             ans = max(ans,itr);
//             for(int i=0;i<4;i++)
//             {
//                 int cRow=r+drow[i];
//                 int cCol=c+dcol[i];
//                 if(cRow>0 && cCol>0 && cRow<=N && cCol<=M && vis.find({cRow,cCol})==vis.end())
//                 {
//                     q.push({{cRow,cCol},itr+1});
//                 }
//             }
            
//         }
//         return ans;
//     }
// };

// Using Common Sense: that honestly i dont have
	// Just calculate the maximum distance of the current point from each of the 
		// diagonal end points i.e. topLeft, topRight, bottomLeft, bottomRight
class Solution{   
public:
    int minIteration(int N, int M, int X, int Y){    
        // code here
        if(N==1 && M==1) return 0;
        int ans=0;
        X=X-1;
        Y=Y-1;
        //top left
        ans = max(ans,X+Y);
        // top right
        ans = max(ans,X+(M-(Y+1)));
        // bottom left
        ans = max(ans,(N-(X+1)+Y));
        // bottom right
        ans = max(ans,(N-(X+1))+(M-(Y+1)));
        return ans;
    }
};