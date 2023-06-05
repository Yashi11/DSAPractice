class WordDictionary {
public:
    class node{
        public:
        node* next[26];
        bool end=false;
        node()
        {
            end=false;
            for(int i=0;i<26;i++){
                next[i]=NULL;
            }
        }
    };
    node* trie;
    WordDictionary() {
        trie=new node();
    }
    
    void addWord(string word) {
        int i=0;
        node* it=trie;
        while(i<word.length())
        {
            if(it->next[word[i]-'a']==NULL){
                it->next[word[i]-'a']=new node();
            }
            it=it->next[word[i]-'a'];
            i++;
        }
        it->end=true;
    }
    bool help(string word,node* st)
    {
    
        for(int i=0;i<word.length();i++)
        {
            if(word[i]=='.'){
                for(auto e:st->next)
                {
                    if(e && help(word.substr(i+1),e)) return true;
                }
                return false;
            }
            else{
                if(st->next[word[i]-'a']==NULL) return false;
                st=st->next[word[i]-'a'];
                
            }
        }
       
        return st->end;
    }
    bool search(string word) {
      return help(word,trie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */