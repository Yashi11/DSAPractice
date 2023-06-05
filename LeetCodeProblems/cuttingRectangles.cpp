class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        // code here
       int gcd=1;
       int div=min(L,B);
       int n=max(L,B);
       while(true)
       {
            n = n%div;
            if(n==0) break;
            swap(n,div);
       }
       gcd=div;
       L = L/gcd;
       B = B/gcd;
       return {L*B,gcd};
    }
};