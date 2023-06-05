class Solution {
public:
    int countSpecialNumbers(int n)
    {
        string num = to_string(n);
        int dig = num.size(), ans = 0;
        for (int i = 1; i < dig; i++)
        {
            int x = 1, k = 9;
            for (int j = 0; j < i - 1; j++)
                x *= k, k--;
            ans += 9 * x;
        }
        vector<int> done(10, 0);
        for (int i = 0; i < dig; i++)
        { 
            int smaller = 0;
            for (int j = 0; j < num[i] - '0'; j++)
                if (!done[j])
                    smaller++;
            if (i == 0 && num[i] > '0')
                smaller--; 
            int next = 1, rem = 10 - i - 1;
            for (int j = i + 1; j < dig; j++)
                next *= rem, rem--;
            ans += smaller * next;
            if (!done[num[i] - '0'])
                done[num[i] - '0'] = 1;
            else
                return ans;
        }
        return ans + 1;
    }
};