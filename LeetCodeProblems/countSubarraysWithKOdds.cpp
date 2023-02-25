class Solution{
public:
int count = 0;
    int prefix[n + 1] = { 0 };
    int odd = 0;
 
    // traverse in the array
    for (int i = 0; i < n; i++)
    {
 
        prefix[odd]++;
 
        // if array element is odd
        if (a[i] & 1)
            odd++;
 
        // when number of odd elements>=M
        if (odd >= m)
            count += prefix[odd - m];
    }
 
    return count;
}
};