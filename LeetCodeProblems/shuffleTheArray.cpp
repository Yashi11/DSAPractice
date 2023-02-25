//O(N) Space Solution

//class Solution {
//public:
//    vector<int> shuffle(vector<int>& nums, int n) {
//        vector<int> ans;
//        int i=0;
//        while(i<n)
//        {
//            ans.push_back(nums[i]);
//            ans.push_back(nums[i+n]);
//            i++;
//        }
//        return ans;
//    }
//};

//O(1) Space Solution O(N^2) Time Complexity

// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         int i=0;
//         int k=n;
//         while(k<2*n)
//         {
//             int temp=nums[k];
//             for(int j=k-1;j>i;j--)
//             {
//                 nums[j+1]=nums[j];
//             }
//             nums[i+1]=temp;
//             for(auto num:nums)
//             {
//                 cout<<num<<" ";
//             }
//             cout<<"\n";
//             i+=2;
//             k++;
//         }
//         return nums;
//     }
// };

//https://www.programmercoach.com/2017/04/interview-pearls-interleave-array-in.html

// Divide and Conquer but only applicable for arrays of size = power of 2
// class Solution {
// public:
//     void helper(vector<int>& nums,int n,vector<int>::iterator first, vector<int>::iterator last)
//     {
//       int size=last-first;
//         if(size<4 || (size & (size-1))!=0) return;
//         swap_ranges(first+int(size/4),first+int(size/2),first+int(size/2));
//         helper(nums,n,first,first+int(size/2));
//         helper(nums,n,first+int(size/2),last);  
//     }
//     vector<int> shuffle(vector<int>& nums, int n) {
//        helper(nums,n,nums.begin(),nums.end());
//         return nums;
//     }
// };

//Most Optimal Solution
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=0;i<nums.size();i++)
        {
            int currpos=i;
            int currNum=nums[i];
            while(currNum>0)
            {
                int newPos;
                if(currpos<n){
                    newPos=2*currpos;
                }
                else{
                    newPos=2*(currpos-n)+1;
                }
                int newNum=nums[newPos];
                nums[newPos]=(-1)* currNum;
                currpos=newPos;
                currNum=newNum;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]*=-1;
        }
        return nums;
    }
};