class Solution {
public:
    bool findWord(vector<vector<char> >& board,string s)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(recursion(board,s,i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool recursion(vector<vector<char> >& board,string s,int x,int y,int ind)
    {
        if(ind==s.length()) return true;
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size()) return false;
        if(board[x][y]!=s[ind]) return false;
        board[x][y]='*';
        bool ans=recursion(board,s,x+1,y,ind+1) || recursion(board,s,x,y+1,ind+1);
        ans = ans || recursion(board,s,x-1,y,ind+1) || recursion(board,s,x,y-1,ind+1);
        ans = ans || recursion(board,s,x-1,y-1,ind+1) || recursion(board,s,x-1,y+1,ind+1);
        ans = ans || recursion(board,s,x+1,y-1,ind+1) || recursion(board,s,x+1,y+1,ind+1);
        board[x][y]=s[ind];
        return ans;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<string> ans;
	    for(int i=0;i<dictionary.size();i++)
	    {
	        if(findWord(board,dictionary[i])){
	            ans.push_back(dictionary[i]);
	        }
	    }
	    return ans;
	}
};