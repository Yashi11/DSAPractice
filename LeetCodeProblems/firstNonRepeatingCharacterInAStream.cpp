//QUEUE BASED APPROACH
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    vector<int> trk(26,0);
		    string ans="";
		    for(int i=0;i<A.length();i++)
		    {
		        q.push(A[i]);
		        trk[A[i]-'a']++;
		        while(!q.empty())
		        {
		            if(trk[q.front()-'a']>1) q.pop();
		            else{
		                ans+=q.front();
		                break;
		            }
		        }
		        if(q.empty())
		        {
		            ans+='#';
		        }
		    }
		    return ans;
		}

};
// Another Approach
// class Solution {
// 	public:
// 		string FirstNonRepeating(string A){
// 		    // Code here
// 		    vector<int> trk(26,0);
// 		    vector<char> v;
// 		    string ans="";
// 		    for(int i=0;i<A.length();i++)
// 		    {
// 		        if(!trk[A[i]-'a'])
// 		        {
// 		            v.push_back(A[i]);
// 		        }
// 		        trk[A[i]-'a']++;
// 		        bool flag=false;
// 		        for(int j=0;j<v.size();j++)
// 		        {
// 		            if(trk[v[j]-'a']==1){
// 		                ans+=v[j];
// 		                flag=true;
// 		                break;
// 		            }
// 		        }
// 		        if(!flag) ans+="#";
// 		    }
// 		    return ans;
// 		}

// };