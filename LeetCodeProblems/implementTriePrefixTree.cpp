class Trie {
public:

    class node{
        public:
        bool end;
        node* next[26];
        node()
        {
            end=false;
            for(int i=0;i<26;i++)
            {
                next[i]=NULL;
            }
        }
    };
    node* trie;
    Trie() {
       trie=new node(); 
    }
    
    void insert(string word) {
        node* itr=trie;
       for(int i=0;i<word.length();i++)
       {
           if(itr->next[word[i]-'a']==NULL)
           {
               itr->next[word[i]-'a']=new node();
           }
           itr=itr->next[word[i]-'a'];
       }
       itr->end=true; 
    }
    
    bool search(string word) {
        node* itr=trie;
        for(int i=0;i<word.length();i++)
        {
            if(itr->next[word[i]-'a']==NULL) return false;
            itr=itr->next[word[i]-'a'];
        }
        return itr->end;
    }
    
    bool startsWith(string word) {
        node* itr=trie;
        for(int i=0;i<word.length();i++)
        {
            if(itr->next[word[i]-'a']==NULL) return false;
            itr=itr->next[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */