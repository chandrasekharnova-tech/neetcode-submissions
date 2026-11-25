class Solution {
public:
    vector<vector<int>> res;
    vector<int> pairs;

    void dfs(vector<int>& nums, vector<bool>& used)
    {
        if(pairs.size() == nums.size())
        {
            res.push_back(pairs);
            return;
        }

        for(int i= 0; i<nums.size();i++)
        {
            if(used[i])
            continue;

            pairs.push_back(nums[i]);
            used[i] = true;

            dfs(nums, used);

            pairs.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
};
