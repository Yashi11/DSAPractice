//NAIVE SOLUTION
// class Solution {
// public:
//     string reverse(string word)
//     {
//         for(int i=0;i<word.length()/2;i++)
//         {
//             swap(word[i],word[word.length()-i-1]);
//         }
//         cout<<"REVERSED: "<<word<<"\n";
//         return word;
//     }
//     bool validPalindrome(string s) {
//         for(int i=0;i<s.length();i++)
//         {
//             string word = s.substr(0,i)+s.substr(i+1,s.length()-i);
//             cout<<word<<"\n";
//             if(word==reverse(word)) return true;
//         }
//         return false;
//     }
// };

//OPTIMAL SOLUTION

class Solution {
public:
    bool validPalindrome(string s,int save=1) {
        int i=0; int j=s.length()-1;
        while(i<j)
        {
            if(save<1 && s[i]!=s[j]) return false;
            else if(save>=1 && s[i]!=s[j]){
                 save--;
                 return validPalindrome(s.substr(i+1,j-i),save-1) || validPalindrome(s.substr(i,j-i),save-1);
                 
            }
            i++;
            j--;
        }
        return true;
    }
};
