class Solution{   
 public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int m;
        while(l<=h)
        {
            m=(l+h)/2;
            if(A[m]==key) return m;
            else if(A[m]>A[l])
            {
                if(A[l]==key) return l;
                else if(A[m]>key && A[l]<key) h=m-1;
                else l=m+1;
            }
            else{
                if(A[h]==key) return h;
                else if(A[m]<key && A[h]>key) l=m+1;
                else h=m-1;
            }
        }
        return -1;
    }
};