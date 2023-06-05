class BrowserHistory {
public:
    vector<string> myHistory;
    int curIndx=-1;
    BrowserHistory(string homepage) {
        myHistory.push_back(homepage);
        curIndx=0;
    }
    
    void visit(string url) {
        myHistory =vector<string>(myHistory.begin(),myHistory.begin()+curIndx+1);
        myHistory.push_back(url);
        curIndx=myHistory.size()-1;
    }
    
    string back(int steps) {
        if(curIndx-steps>=0){
            curIndx-=steps; 
        }
        else{
            curIndx=0;
        }
        return myHistory[curIndx];

    }
    
    string forward(int steps) {
        if(curIndx+steps<myHistory.size())
        {
            curIndx+=steps;
        }
        else{
            curIndx=myHistory.size()-1;
        }
        return myHistory[curIndx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */