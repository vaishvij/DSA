class Solution {
public:
    vector<int> eachRow(int row)
    {
        long long el = 1;
        vector<int> temp;
        temp.push_back(1);
        for(int col=1; col<row; col++)
        {
            el = el * (row-col);
            el = el / col;
            temp.push_back(el);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++)
        {
            ans.push_back(eachRow(i));
        }
        return ans;
    }
};