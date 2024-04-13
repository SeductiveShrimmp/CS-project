#include <stdio.h>

char board[3][3];
// 3x3 board

// Function to initialize the board
void initialize() 
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            board[i][j]=' ';
            // Initialising each element of the matrix with a blank space
        }
    }
}

// Function to print the board
void printboard() {
    printf(" %c ", board[0][0]);
    printf(" | ");
    printf( "%c ",board[0][1]);
    printf(" | ");
    printf(" %c ",board[0][2]);
    printf("\n");
    printf("---------------\n");
    printf(" %c ",board[1][0]);
    printf(" | ");
    printf(" %c ",board[1][1]);
    printf(" | ");
    printf(" %c ",board[1][2]);
    printf("\n");
    printf("---------------\n");
    printf(" %c ",board[2][0]);
    printf(" | ");
    printf(" %c ",board[2][1]);
    printf(" | ");
    printf(" %c ",board[2][2]);
    printf("\n");
}

// Function to check if there is a winner
char checkwinner() 
{
    // Checking the row elements are same
    for (int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' ') 
        {
            return board[i][0];
        }
    }
    // Checking the column elements are same
    for(int j=0;j<3;j++) 
    {
        if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&board[0][j]!=' ') 
        {
            return board[0][j];
        }
    }
    // Checking the diagonal elements are same
    if((board[0][0]==board[1][1]&&board[1][1]==board[2][2]) || 
        (board[0][2]==board[1][1]&&board[1][1]==board[2][0])&&(board[0][0]!=' ')) 
    {
        return board[1][1];
    }
    // Check if the board is full (tie)
    for (int i=0;i<3; i++) 
    {
        for (int j=0;j<3;j++) 
        {
            if(board[i][j]==' ')
            {
                return ' ';
            }
        }
    }
    return 'T'; //When the game is Tie
}

int main() 
{
    int row,col;
    char player='X';
    char winner=' ';

    initialize();
    
    printf("Welcome to Tic Tac Toe!\n");

    while (winner==' ') 
    {
        printf("\nPlayer %c's turn. Enter row and column (0-2): ", player);
        scanf("%d%d",&row,&col);
        
        if (row< 0||row > 2||col<0||col>2||board[row][col]!=' ') 
        {
            printf("Invalid move. Try again.\n");
            // when the given row or column number does not exist or chosen the same spot as earlier
            continue;
            // to skip the rest of the lines in the loop since the above input is invalid
        }
        
        board[row][col]=player;
        //printing the board after every choice made by the user
        printboard();
        //checking if the game is over
        winner=checkwinner();
        
        // Switching the player after every turn
        if (player=='X') 
        {
            player='O';
        }
        else 
        {
            player='X';
        }
    }
    
    if (winner=='T') 
    {
        printf("\nThe game is a tie!\n"); 
        // printing statement when the game is a tie
    } 
    else 
    {
        printf("\nPlayer %c wins!\n", winner);
        // printing the winner of the game if any
    }

    return 0;
}