// Naive Approach

// class Solution{
// public:
//     vector<int> optimalArray(int n,vector<int> &a){
//         // Code here
//         vector<int> ans;
//         ans.push_back(0);
//         for(int i=1;i<n;i++)
//         {
//             int mid=a[i/2];
//             int cAns=0;
//             for(int j=0;j<=i;j++)
//             {
//                 cAns+= abs(a[j]-mid);
//             }
//             ans.push_back(cAns);
//         }
//         return ans;
//     }
// };

// Optimized Approach

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<n;i++)
        {
            int mid=a[i/2];
            ans.push_back(ans[i-1]+abs(a[i]-mid));
        }
        return ans;
    }
};