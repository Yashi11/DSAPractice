
class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int Ocnt=0;
        int strt=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='O')   Ocnt++;
                
            while(strt<n && Ocnt>m)
            {
                 
                if(arr[strt]=='O') Ocnt--;
                    strt++;
            }
            ans=max(ans,i-strt+1);
        }
        return ans;
    }
};