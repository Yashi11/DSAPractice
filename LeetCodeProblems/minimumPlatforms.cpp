// naive Approach-> using greedy recursively -> GOT TLE
// class Solution{
//     public:
//     //Function to find the minimum number of platforms required at the
//     //railway station such that no train waits.
//     int helper(vector<pair<int,int>> trns,int n)
//     {
//         if(n==0) return 0;
//       sort(trns.begin(),trns.end(),[&] (pair<int,int> a,pair<int,int> b)
//         {
//             return a.second<b.second;
//         });
//         vector<pair<int,int>> temp;
//         int end=trns[0].second;
//     	for(int i=1;i<n;i++)
//     	{
//     	    if(trns[i].first>end)
//     	    {
//     	        end=trns[i].second;
//     	        continue;
//     	    }
//     	    else{
//     	     temp.push_back({trns[i].first,trns[i].second});   
//     	    }
//     	}
//     	return 1+helper(temp,temp.size());
//     }
//     int findPlatform(int arr[], int dep[], int n)
//     {
//     	// Your code here
//     	vector<pair<int,int>> trns;
//     	for(int i=0;i<n;i++){
//     	    trns.push_back({arr[i],dep[i]});
//     	}
//     	return helper(trns,trns.size());
        
//     }
// };

// optimized Approach
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int ans=0;
    	int cnt=0;
    	int i=0;
    	int j=0;
    	
    	while(i<n)
    	{
    	    if(arr[i]<=dep[j]){
    	        cnt++;
    	        ans=max(ans,cnt);
    	        i+=1;
    	    }
    	    else if(arr[i]>dep[j])
    	    {
    	        cnt--;
    	        j++;
    	    }
    	}
    	return ans;
    }
};