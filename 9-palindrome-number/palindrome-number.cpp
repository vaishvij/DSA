class Solution {
public:
    bool isPalindrome(int x) 
    {
        int org = x; long long rev=0;
        int dig;
        if(x < 0) return false;
        while(org > 0)
        {
            dig = org % 10;
            rev = (rev*10) + dig;
            org = org/10;
        }
        if(x == rev) return true;
        else return false;
    }
};