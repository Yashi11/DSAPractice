// seperate UC and LC letters->sort seperately check the preious string for posns of upper and lower case 
// put letter from appropriate list accordingly to final ans
class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<char> charU;
        vector<char> charL;
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a' && str[i]<='z'){
                charL.push_back(str[i]);
            }
            else{
                charU.push_back(str[i]);
            }
        }
        sort(charU.begin(),charU.end());
        sort(charL.begin(),charL.end());
       
        vector<char> str2(n,'.');
        int l=0;int u=0;
        for(int i=0;i<n;i++)
        {
            if('a'<=str[i] && str[i]<='z'){
                str[i]=charL[l];l++;
            }
            else{
                str[i]=charU[u];u++;
            }
         }
        
        return str;
        
    }
};