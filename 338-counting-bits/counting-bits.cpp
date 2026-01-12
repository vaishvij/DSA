class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> ans;
        for(int i=0; i<=n; i++)
        {
            int count=0, x=i;
            while(x > 1)
            {
                if(x%2 == 1) count++;
                x = x>>1;
            }
            if(x==1) count++;
            ans.push_back(count);
        }
        return ans;
    }
};