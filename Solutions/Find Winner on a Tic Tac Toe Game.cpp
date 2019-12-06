class Solution {
public:
    string FindWinner(const vector<vector<char>>& board, int num_moves) {
        const char empty = 'q';
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != empty) {
                cout << board[i][0] << endl;
                return string(1, board[i][0]);
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != empty) {
                return string(1, board[0][i]);
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != empty) {
            return string(1, board[0][0]);
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != empty) {
            return string(1, board[0][2]);
        }
        return num_moves == 9 ? "Draw" : "Pending";
    }
    string tictactoe(vector<vector<int>>& moves) {
        bool is_A_turn = true;
        vector<vector<char>> board(3, vector<char>(3, 'q'));
        for (const vector<int> move : moves) {
            board[move[0]][move[1]] = is_A_turn ? 'A' : 'B';
            is_A_turn = !is_A_turn;
        }
        return FindWinner(board, moves.size());
    }
};
