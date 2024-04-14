#include <stdio.h>

#define ROWS 6
#define COLS 7

char board[ROWS][COLS];

// Initialize the game board
void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the game board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
    printf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n\n");
}

// Drop a token into a column
int dropToken(int col, char token) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = token;
            return 1;
        }
    }
    return 0; // Column is full
}

// Check for a win
int checkWin(char token) {
    // Check horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == token && board[i][j + 1] == token && board[i][j + 2] == token && board[i][j + 3] == token) {
                return 1; // Win
            }
        }
    }
    // Check vertical
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == token && board[i + 1][j] == token && board[i + 2][j] == token && board[i + 3][j] == token) {
                return 1; // Win
            }
        }
    }
    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == token && board[i + 1][j + 1] == token && board[i + 2][j + 2] == token && board[i + 3][j + 3] == token) {
                return 1; // Win
            }
        }
    }
    // Check diagonal (bottom-left to top-right)
    for (int i = ROWS - 1; i >= 3; i--) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == token && board[i - 1][j + 1] == token && board[i - 2][j + 2] == token && board[i - 3][j + 3] == token) {
                return 1; // Win
            }
        }
    }
    return 0; // No win
}

// Check if the board is full
int isBoardFull() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

// Main function
int main() {
    int col, turn = 1, gameEnd = 0;
    char token = 'X';

    // Initialize the game board
    initializeBoard();

    // Main game loop
    while (!gameEnd) {
        // Display the game board
        displayBoard();

        // Get player input
        printf("Player %d's turn. Enter column number (1-7): ", turn);
        scanf("%d", &col);

        // Validate input
        if (col < 1 || col > 7) {
            printf("Invalid input. Please enter a number between 1 and 7.\n");
            continue;
        }

        // Drop token into column
        if (!dropToken(col - 1, token)) {
            printf("Column is full. Please choose another column.\n");
            continue;
        }

        // Check for win or draw
        if (checkWin(token)) {
            displayBoard();
            printf("Player %d wins!\n", turn);
            gameEnd = 1;
        } else if (isBoardFull()) {
            displayBoard();
            printf("It's a draw!\n");
            gameEnd = 1;
        }

        // Switch player
        turn = (turn == 1) ? 2 : 1;
        token = (token == 'X') ? 'O' : 'X';
    }

    return 0;
}

