#include <stdio.h>

char board[3][3];

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    printf("   1 2 3\n");
    printf("  -------\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", i+1);
        printf("|%c|%c|%c|\n", board[i][0], board[i][1], board[i][2]);
        printf("  -------\n");
    }
}

int is_valid_move(int row, int col) {
    if (row < 1 || row > 3 || col < 1 || col > 3) {
        printf("Invalid move: row and column must be between 1 and 3.\n");
        return 0;
    }
    if (board[row-1][col-1] != ' ') {
        printf("Invalid move: that space is already taken.\n");
        return 0;
    }
    return 1;
}

int check_win() {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    return 0;
}

int main() {
    int player = 1;
    int row, col;
    int turn = 0;
    initialize_board();
    print_board();
    while (1) {
        printf("Player %d's turn.\n", player);
        printf("Enter a row (1-3): ");
        scanf("%d", &row);
        printf("Enter a column (1-3): ");
        scanf("%d", &col);
        if (is_valid_move(row, col)) {
            board[row-1][col-1] = (player == 1 ? 'X' : 'O');
            print_board();
            if (check_win()) {
                printf("Player %d wins!\n", player);
                break;
            }
            player = (player == 1 ? 2 : 1);
            turn++;
            if (turn == 9) {
                printf("Game over: it's a tie!\n");
                break;
            }
        }
    }
    return 0;
}
