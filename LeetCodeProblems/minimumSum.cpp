
class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        int strt=0;
        while(arr[strt]==0) strt++;
        string ans="";
        int carry=0;
        for(int i=n-1;i>strt;i-=2)
        {
            int temp = carry + arr[i]+arr[i-1];
            ans = to_string(temp%10)+ans;
            carry=temp/10;
        }
        if((n-strt)%2==1)
        {
            int temp=carry+arr[strt];
            ans = to_string(temp%10)+ans;
            carry=temp/10;
        }
        while(carry)
        {
            ans = to_string(carry%10)+ans;
            carry = carry/10;
        }
        return ans;
    }
};