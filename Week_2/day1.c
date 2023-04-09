#include <stdio.h>

char board[3][3]; // the tic-tac-toe board

void init_board()
{
    // initialize the board with empty spaces
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board()
{
    // print the current state of the board
    int i, j;
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("---|---|---\n");
        }
    }
}

int check_winner(char player)
{
    // check if the given player has won the game
    int i;
    for (i = 0; i < 3; i++) {
        // check rows
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        // check columns
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main()
{
    int row, col, turn = 0;
    char player = 'X';
    init_board();
    printf("Tic Tac Toe\n");
    while (1) {
        printf("\n");
        print_board();
        printf("Player %c's turn\n", player);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        row--;
        col--;
        if (board[row][col] != ' ') {
            printf("That space is already occupied. Try again.\n");
            continue;
        }
        board[row][col] = player;
        if (check_winner(player)) {
            printf("\n");
            print_board();
            printf("Player %c wins!\n", player);
            break;
        }
        turn++;
        if (turn == 9) {
            printf("\n");
            print_board();
            printf("Tie game!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X'; // switch players
    }
    return 0;
}