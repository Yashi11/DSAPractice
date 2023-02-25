class Compare{
  public:
    bool operator()(pair<int,long long int>above,pair<int,long long int>below)
    {
        if(above.first<below.first) return true;
        else if(above.first==below.first){
            if(above.second>below.second) return true;
            else return false;
        }
        else return false;
    }
};
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        priority_queue<pair<int,long long int>,vector<pair<int,long long int>>,Compare> pq;
        set<string> pos(positive_feedback.begin(),positive_feedback.end());
        set<string> neg(negative_feedback.begin(),negative_feedback.end());
        for(int j=0;j<report.size();j++){
            string currWord="";
            int score=0;
            for(int i=0;i<report[j].length();i++)
            {
                
               if(report[j][i]==' '){
                   if(neg.find(currWord) != neg.end() ) score-=1;
                   if(pos.find(currWord) !=  pos.end() ) score+=3;
                   currWord="";
               }
                else{
                    currWord+=report[j][i];
                }
            
            }
             if(neg.find(currWord) != neg.end() ) score-=1;
             if(pos.find(currWord) !=  pos.end() ) score+=3;
            pq.push(make_pair(score,student_id[j]));
        }
        vector<int> ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};