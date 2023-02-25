class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int j=0;
        for(int i=0;i<T.length();i++)
        {
            if(T[i]>='A' && T[i]<='Z')
            {
                if(T[i]!=S[j]) return 0;
                j++;
            }
            else if(T[i]>='0' && T[i]<='9')
            {
                int temp=0;
                while(T[i]>='0' && T[i]<='9')
                {
                    temp= temp*10 + (T[i]-'0');
                    i++;
                }
                i--;
                j+=temp;
                if(j>S.length()) return 0;
            }
        }
        return 1;
    }
};