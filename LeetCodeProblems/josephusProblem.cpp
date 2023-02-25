class Solution
{
    public:
    int newJosephus(int n,int k)
    {
        if(n==1) return 0;
        return( newJosephus(n-1,k)+k)%n;
    }
    int josephus(int n, int k)
    {
       //Your code here
       if(n==1) return 1;
       return newJosephus(n,k)+1;
    }
};