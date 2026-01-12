class Solution {
public:
    int reverseBits(int n) 
    {
        string org="";
        for(int i=0; i<32; i++)
        {
            if(n%2 == 1) org+='1';
            else org+='0';
            n = n>>1;
        }
        int len = org.length();
        int rev=0, p=1;
        for(int i=len-1; i>0; i--)
        {
            if(org[i] == '1') rev=rev+p;
            p = p<<1;
        }
        return rev;
    }
};