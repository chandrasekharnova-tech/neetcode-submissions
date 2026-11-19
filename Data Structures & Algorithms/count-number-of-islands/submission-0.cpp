class Solution {
public:
    void travel_islands(vector<vector<char>>& grid, int v, int h)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(v<0||v>=m||h<0||h>=n||grid[v][h]=='0')
            return;

        grid[v][h] = '0';
        travel_islands(grid, v-1, h);
        travel_islands(grid, v+1, h);
        travel_islands(grid, v, h-1);
        travel_islands(grid, v, h+1);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1') {
                    islands++;
                    travel_islands(grid, i, j);
                }
            }


        return islands;
    }
};
