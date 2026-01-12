class Solution {
public:
    string addBinary(string a, string b) 
    {
        string ans = "";
        int i = a.length()-1;
        int j = b.length()-1;
        char c='0';

        while(i>=0 || j>=0 || c=='1')
        {
            char x = (i>=0) ? a[i] : '0';
            char y = (j>=0) ? b[j] : '0';

            if(c=='0' && x=='0' && y=='0') ans+='0';
            else if(c=='1' && x=='0' && y=='0') {ans+='1'; c='0';}
            else if((c=='0' && x=='0' && y=='1') || (c=='0' && x=='1' && y=='0')) ans+='1';
            else if((c=='1' && x=='0' && y=='1') || (c=='1' && x=='1' && y=='0')) {ans+='0'; c='1';}
            else if(c=='0' && x=='1' && y=='1') {ans+='0'; c='1';}
            else if(c=='1' && x=='1' && y=='1') {ans+='1'; c='1';}
            i--; j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};