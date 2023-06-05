class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	     vector<pair<int,int>> temp;
	     for(int i=0;i<nums.size();i++)
	     {
	         temp.push_back({nums[i],i});
	     }
	     sort(temp.begin(),temp.end());
	     int ans=0;
	     for(int i=0;i<temp.size();i++)
	     {
	         int val=temp[i].first;
	         int indx=temp[i].second;
	         if(indx!=i)
	         {
	            ans++;
	            swap(temp[i],temp[indx]);
	            i--;
	         }
	     }
	     return ans;
	}
};