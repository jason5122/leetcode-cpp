/*
runtime: O(n^2)
space: O(n^2)
*/
class TicTacToe {
public:
    TicTacToe(int n) : n{n}, board(n, vector<int>(n, 0)) {}

    int move(int row, int col, int player) {
        board[row][col] = player;

        // Horizontals.
        for (int i = 0; i < n; i++) {
            int p1 = 0;
            int p2 = 0;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) p1++;
                if (board[i][j] == 2) p2++;
            }
            if (p1 == n) return 1;
            if (p2 == n) return 2;
        }

        // Verticals.
        for (int j = 0; j < n; j++) {
            int p1 = 0;
            int p2 = 0;
            for (int i = 0; i < n; i++) {
                if (board[i][j] == 1) p1++;
                if (board[i][j] == 2) p2++;
            }
            if (p1 == n) return 1;
            if (p2 == n) return 2;
        }

        // Diagonals.
        int p1_d1 = 0;
        int p2_d1 = 0;
        int p1_d2 = 0;
        int p2_d2 = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][i] == 1) p1_d1++;
            if (board[i][i] == 2) p2_d1++;
            if (board[n - 1 - i][i] == 1) p1_d2++;
            if (board[n - 1 - i][i] == 2) p2_d2++;
        }
        if (p1_d1 == n) return 1;
        if (p2_d1 == n) return 2;
        if (p1_d2 == n) return 1;
        if (p2_d2 == n) return 2;

        return 0;
    }

private:
    int n;
    vector<vector<int>> board;
};

/*
FOLLOW UP
runtime: O(n)
space: O(n)
*/
class TicTacToe {
public:
    TicTacToe(int n) : n{n}, p1_h(n), p2_h(n), p1_v(n), p2_v(n) {}

    int move(int row, int col, int player) {
        if (player == 1) {
            p1_h[row]++;
            p1_v[col]++;
            if (row == col) p1_d1++;
            if (n - 1 - row == col) p1_d2++;
        }
        if (player == 2) {
            p2_h[row]++;
            p2_v[col]++;
            if (row == col) p2_d1++;
            if (n - 1 - row == col) p2_d2++;
        }

        if (p1_h[row] == n || p1_v[col] == n) return 1;
        if (p2_h[row] == n || p2_v[col] == n) return 2;
        if (p1_d1 == n || p1_d2 == n) return 1;
        if (p2_d1 == n || p2_d2 == n) return 2;

        return 0;
    }

private:
    int n;

    vector<int> p1_h;
    vector<int> p2_h;
    vector<int> p1_v;
    vector<int> p2_v;
    int p1_d1 = 0;
    int p2_d1 = 0;
    int p1_d2 = 0;
    int p2_d2 = 0;
};
