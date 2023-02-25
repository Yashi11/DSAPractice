brute force
//class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         set<vector<int>> ans;
//         vector<vector<int>> res;
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<n-3;i++)
//         {
//             if(i>0 && nums[i]==nums[i-1]) continue;
//             for(int j=i+1;j<n-2;j++)
//             {
//                 if(j>i+1 && nums[j-1]==nums[j]) continue;
//                 for(int k=j+1;k<n-1;k++){
//                     if(k>j+1 && nums[k-1]==nums[k]) continue;
//                     int sum=0;
//                     for(int l=k+1;l<n;l++)
//                     {
//                         if(l>k+1 && nums[l]==nums[l-1]) continue;
//                         sum=nums[i]+nums[j]+nums[k]+nums[l];
//                         if(sum==target) ans.insert({nums[i],nums[j],nums[k],nums[l]});
//                         else if(sum>target) break;
//                         else continue;
//                     }
//                 }
//             }
//         }
//         for(auto itr:ans)
//         {
//            res.push_back(itr);
//         }
//         return res;
//     }
// };

2-POINTER Approach

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ump;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;++j)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left=j+1;
                int right=n-1;
                while(left<right)
                {
                    
                    long target2=long(target)-long(nums[j])-long(nums[i]);
                    long currSum=long(nums[left])+long(nums[right]);
                    if(currSum==target2)
                    {
                        ump.insert({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                    }
                    else if(currSum<target2) left++;
                    else right--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto itr:ump)
        {
            ans.push_back({itr[0],itr[1],itr[2],itr[3]});
        }
        return ans;
    }
};

//USING long target2= long(target)-long(num1)-long(num2) IS VERY IMP
