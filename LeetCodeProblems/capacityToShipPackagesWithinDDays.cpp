// ADVANCED BINARY SEARCH APPROACH
class Solution {
public:
    bool check(vector<int>& weights, int days, int capacity)
    {
        int currCapacity=0;
        int expectedDays=1;
        for(int i=0;i<weights.size();i++)
        {
            if(currCapacity+weights[i]>capacity)
            {
                expectedDays++;
                currCapacity=0;
            }
            currCapacity += weights[i];
        }
        if(expectedDays>days) return false;
        else return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       
        int left=INT_MIN;
        int right=0;

        for(int i=0;i<weights.size();i++)
        {
    // we know that the min capacity we can have=max element in the vector weights
        // this is we shift each item each day
            left=max(left,weights[i]);
    //we know that the max capacity we can have = sum of all elements in vector
        // this is all are shipped together in one day
            right+=weights[i];
        }
        int mid;
        int ans;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(check(weights,days,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};