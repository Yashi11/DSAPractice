// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=0;
        int h=n;
        int m;
        while(l<=h)
        {
            m=l+((h-l)/2); // use this instead of m = (l+h)/2 OR use long long int for l,h.
            if(isBadVersion(m)==true && isBadVersion(m-1)==false) return m;
            else if(isBadVersion(m)==false) l=m+1;
            else if(isBadVersion(m)==true) h = m-1;
        }
        return -1;
    }
};