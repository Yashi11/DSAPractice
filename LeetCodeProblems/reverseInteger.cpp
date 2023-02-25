class Solution {
public:
    int reverse(int x) {
        bool flag=false;
        if(x<0){
            flag=true;
            if(x==INT_MIN) return 0;
            x*=-1;
        }
        long int ans=0;        
            while(x)
            {
                if(ans*10>INT_MAX) return 0;
                ans=ans*10 + (x%10);
                x=x/10;
            }
            if(flag) ans*=-1;
            return ans;
        
    }
};