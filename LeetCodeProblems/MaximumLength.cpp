// Good Question -> Uses Clever Thinking
class Solution {
public:
    int solve(int a, int b, int c) {
        int maxm=max(a,max(b,c));
        int residue;
        if(maxm==a)
        {
            residue=b+c;
        }
        else if(maxm==b)
        {
            residue=a+c;
        }
        else{
            residue=a+b;
        }
        if(maxm>=2*(residue)+3) return -1;
        else return residue+maxm;
    }
};