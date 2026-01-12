class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        long long ans=0;
        bool sign=true;
        if(dividend<0 && divisor>0) sign=false;
        if(dividend>0 && divisor<0) sign=false;

        if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

        long long n = llabs(dividend);
        long long d = llabs(divisor);
        while(n >= d)
        {
            int count=0;
            while(n >= (d<<(count+1)))
            {
                count++;
            }
            ans = ans + (1 << count);
            n = n - (d << count);
        }
        
        return sign ? ans : -ans;
    }
};