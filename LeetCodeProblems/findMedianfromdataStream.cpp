class MedianFinder {
public:
        priority_queue<int,vector<int>> pqMax;
        priority_queue<int,vector<int>,greater<int>> pqMin;
        
    MedianFinder() {

    }
    
    void addNum(int num) {
        int maxSize=pqMax.size();
        int minSize=pqMin.size();
        if(maxSize==0){
            pqMax.push(num);
        }
        else if(maxSize==minSize)
        {
            if(num<pqMin.top())
            {
                pqMax.push(num);   
            }
            else{
                int temp=pqMin.top();
                pqMin.pop();
                pqMax.push(temp);
                pqMin.push(num);
                 
            }
        }
        else{
            if(minSize==0)
            {
                if(num>=pqMax.top()){
                    pqMin.push(num);
                    
                }
                else{
                    int temp=pqMax.top();
                    pqMax.pop();
                    pqMax.push(num);
                    pqMin.push(temp);
                }
               
            }
            else if(num>=pqMin.top())
                {
                    pqMin.push(num);
                    
                }
            else{
                if(num<pqMax.top())
                {
                        int temp=pqMax.top();
                        pqMax.pop();
                        pqMax.push(num);
                        pqMin.push(temp);
                }
                    else{
                        pqMin.push(num);
                    }
                }
            }
        }
    
    double findMedian() {
        if(pqMax.size()>pqMin.size()) return pqMax.top();
        else  return double(pqMax.top()+pqMin.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */