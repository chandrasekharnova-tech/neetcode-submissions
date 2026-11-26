class Solution {
public:
    vector<vector<string>> res;

    unordered_set<int> col;
    unordered_set<int> pos_diag;
    unordered_set<int> neg_diag;

    void dfs(int row, int n, vector<string>& board)
    {
        if(row == n)
        {
            res.push_back(board);
            return;
        }

        for(int c = 0; c<n; c++)
        {
            if(col.count(c) || pos_diag.count(row+c) || neg_diag.count(row-c))
            continue;

            col.insert(c);
            pos_diag.insert(row+c);
            neg_diag.insert(row-c);

            board[row][c] = 'Q';

            dfs(row+1, n, board);

            board[row][c] = '.';
            col.erase(c);
            pos_diag.erase(row+c);
            neg_diag.erase(row-c);
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        dfs(0, n, board);
        return res;
    }
};
