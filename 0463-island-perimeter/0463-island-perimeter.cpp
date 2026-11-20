class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                {
                    // Left case
                    if((j == 0) || (grid[i][j-1] == 0))
                        ans++;

                    // Right case
                    if((j == col - 1) || (grid[i][j+1] == 0))
                        ans++;

                    // Up case
                    if((i == 0) || (grid[i-1][j] == 0))
                        ans++;

                    // Down case
                    if((i == row - 1) || (grid[i+1][j] == 0))
                        ans++;
                }
            }
        }

        return ans;
    }
};