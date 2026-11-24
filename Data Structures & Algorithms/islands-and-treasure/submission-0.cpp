class Solution {
public:
    int MAX = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                q.push({i,j});
            }
        }

        vector<pair<int, int>> dir = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };

        while(!q.empty())
        {
            auto[r,c]=q.front();
            q.pop();

            for(auto &[dr, du] : dir)
            {
                int h = r + dr;
                int v = c + du;

                if(h<0||h>=n||v<0||v>=m)
                {
                    continue;
                }

                if(grid[h][v]!=MAX)
                {
                    continue;
                }

                grid[h][v] = grid[r][c]+1;
                q.push({h,v});
            }
        }
    }
};
