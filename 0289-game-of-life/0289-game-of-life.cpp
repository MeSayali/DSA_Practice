#include <vector>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Directions for neighbors
        std::vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        std::vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        // First pass: **Mark** temporary state changes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int liveNeighbors = 0;
                for (int d = 0; d < 8; ++d) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        // Check if neighbor was originally live
                        if (board[ni][nj] == 1 || board[ni][nj] == 2) {
                            liveNeighbors++;
                        }
                    }
                }
                
                if (board[i][j] == 1) { // Current cell is live
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = 2; // live -> dead
                    }
                } else { // Current cell is dead
                    if (liveNeighbors == 3) {
                        board[i][j] = 3; // dead -> live
                    }
                }
            }
        }

        // Second pass: **Finalize** state changes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0; // Finalize live -> dead
                } else if (board[i][j] == 3) {
                    board[i][j] = 1; // Finalize dead -> live
                }
            }
        }
    }
};