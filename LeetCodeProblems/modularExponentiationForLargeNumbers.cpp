class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    if(n==0) return 1;
		    long long int res=1;
		    while(n)
		    {
		        if(n%2==0)
		        {
		            x=(x*x)%M;
		            n=n/2;
		        }
		        else if(n%2==1)
		        {
		            res=(res*x)%M;
		            n--;
		        }
		    }
		    return res;
		}
};