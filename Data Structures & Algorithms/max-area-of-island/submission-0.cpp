class Solution {
public:
    int travel_islands(vector<vector<int>>& grid, int v, int h)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(v<0||v>=m||h<0||h>=n||grid[v][h]==0)
        return 0;

        grid[v][h]=0;

        return 1 + travel_islands(grid, v-1, h) +
                   travel_islands(grid, v+1, h) +
                   travel_islands(grid, v, h-1) +
                   travel_islands(grid, v, h+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
       int m = grid.size();
       int n = grid[0].size();

       int max_area = 0;

       for(int i = 0; i<m;i++)
       {
        for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==1)
                {   
                    int area = travel_islands(grid, i, j);
                    max_area = (max_area > area) ? max_area : area;
                }
            }
        }

        return max_area;
    }
};
