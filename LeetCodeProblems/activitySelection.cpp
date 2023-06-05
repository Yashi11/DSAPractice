class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> activities;
        for(int i=0;i<n;i++)
        {
            activities.push_back({start[i],end[i]});
        }
        sort(activities.begin(),activities.end(),[&] (pair<int,int> a, pair<int,int> b)
        {
            if(a.second<b.second) return true;
            else return false;
        });
        int ans=1;
        int endT=activities[0].second;
        for(int i=1;i<n;i++)
        {
            if(activities[i].first> endT){
                ans++;
                endT=activities[i].second;
            }   
        }
        return ans;
    }
};