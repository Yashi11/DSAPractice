class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        if(flowerbed.size()==1)
        {
            if(n>1) return false;
            else if(n==1){
                return flowerbed[0]==0;
            }
            else{
                return true;
            }

        }
        for(int i=0;i<flowerbed.size();i++)
        {
            if(i>0 && flowerbed[i-1]==0 && i<flowerbed.size()-1 && flowerbed[i+1]==0 && flowerbed[i]==0)
            { cnt++;flowerbed[i]=1;}
            else if(i==0 && i+1<flowerbed.size() && flowerbed[i+1]==0 && flowerbed[i]==0) {cnt++;flowerbed[i]=1;}
            else if(i==flowerbed.size()-1 && i-1>0 && flowerbed[i-1]==0 && flowerbed[i]==0) {cnt++;flowerbed[i]=1;}
        }
        return cnt>=n;
    }
};