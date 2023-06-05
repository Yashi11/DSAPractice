class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        // y-y1=m(x-x1) where m=y2-y1/x2-x1.
        double x1=c[0][0];
        double y1=c[0][1];
        double x2=c[1][0];
        double y2=c[1][1];
        double m;
        bool zeroSlope=false;
        if(x2-x1!=0) m=((y2-y1)/(x2-x1));
        else zeroSlope=true;
        //y=m(x-x1)+y1
        for(int i=2;i<c.size();i++)
        {
            if(!zeroSlope && (double)c[i][1]!=(double)(m*(c[i][0]-x1)+y1)) return false;
            if(zeroSlope && (double)c[i][0]!=x1) return false;
        }
        return true;
    }
};