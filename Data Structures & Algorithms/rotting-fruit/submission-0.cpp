class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;

        queue<pair<int, int>> q;

        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                q.push({i,j});

                if(grid[i][j]==1)
                fresh++;
            }
        }

        vector<pair<int, int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        int minutes = 0;

        while(!q.empty() && fresh>0)
        {
            int sz = q.size();

            for(int i = 0;i<sz;i++)
            {

                auto[r,c] = q.front();
                q.pop();

                for(auto &[dr, dc] : dir)
                {
                    int h = r+dr;
                    int v = c+dc;

                    if(h<0||h>=n||v<0||v>=m)
                    continue;

                    if(grid[h][v]!=1)
                    continue;

                    grid[h][v] = 2;
                    fresh--;

                    q.push({h,v});
                }
            }
            minutes++;
        }


        return fresh== 0 ? minutes:-1;
    }
};
