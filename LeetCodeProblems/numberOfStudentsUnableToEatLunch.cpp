class Solution {
public:
	// O(N)+O(N) Solution
    // int countStudents(vector<int>& students, vector<int>& sandwiches) {
    //     deque<int>q;
    //     for(int i=0;i<sandwiches.size();i++){
    //         q.push_back(students[i]);
    //     }
    //     int i=0,k=0;
        
    //     while(q.size()!=0 && k!=q.size()){
    //         if(q.front()!=sandwiches[i]){q.push_back(q.front());k++;}
    //         else {k=0;i++;}
    //         q.pop_front();
    //     }
    //     return q.size();
    // }

	//O(N)+O(1) Soluntion
     int countStudents(vector<int>& students, vector<int>& sandwiches) {
         int ones=0;
         int zeroes=0;
         for(int i=0;i<students.size();i++){
             if(students[i]==0) zeroes++;
             else ones++;
         }
         for(int i=0;i<sandwiches.size();i++){
             if(sandwiches[i]==0){
                 if(zeroes==0) return ones;
                 zeroes--;
             }
             else{
                 if(ones==0) return zeroes;
                 ones--;
             }
         }
         return 0;
     }
};