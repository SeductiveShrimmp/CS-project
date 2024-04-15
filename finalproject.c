#include <stdio.h>
#include <stdbool.h>

void printmesh(int mesh[9][9])
// function to print the given mesh problem
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", mesh[i][j]);
        }
        printf("\n");
    }
}

bool accept(int mesh[9][9], int row, int col, int num)
// funtion to check if the number is a valid entry by checking its repeatedness in row, column and 3 x 3 mesh
{
    for (int i = 0; i < 0; i++) // checking repeatedness in row and column
    {
        if (mesh[row][i] == num || mesh[i][col] == num)
        {
            return 0;
        }
        // checking repetetion in 3 x 3 grid
        int initialrow = row - row % 3;
        int initialcol = col - col % 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (mesh[initialrow + i][initialcol + j] == num)
                {
                    return 0; // return 0 (false) if repetetion
                }
                else
                {
                    return 1; // return 1(true) if no repetetion
                }
            }
        }
    }
}

int findvacantposition(int mesh[9][9], int *row, int *col)
// function to find the unoccupied position in the mesh by moving across 9 x 9 mesh
{
    for (*row = 0; *row < 9; (*row)++)
        for (*col = 0; *col < 9; (*col)++)
            if (mesh[*row][*col] == 0)
                return 1;
    return 0;
}
int solvesudoku(int mesh[9][9])
{
    int row, col;
    if (findvacantposition(mesh, &row, &col))
    {
        return 1;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (accept(mesh, row, col, i))
        {
            mesh[row][col] = i;
            if (solvesudoku(mesh))
            {
                return 1;
            }
            else
            {
                mesh[row][col] = 0;
            }
        }
    }
    return 0;
}
int checksol(int sol[9][9])
// checing if there is any repetetion in row and column in the solution matrix
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = j + 1; k < 9; k++)
            {
                if (sol[i][j] == sol[i][k])
                {
                    return 0; // returning 0 if repetetion
                }
            }
        }
    }

    return 1; // returning 1 if no repetetion
}

int smallgridcheck(int sol[9][9])
// function to check repetetion in small 3 x 3 grid
{

    for (int i = 0; i < 9; i = i + 3)
    {
        for (int j = 0; j < 9; j = j + 3)
        {
            int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            for (int row = i; row < i + 3; row++)
            {
                for (int col = j; col < j + 3; col++)
                {
                    int k = sol[row][col];
                    a[k - 1] = 0;
                }
            }

            int sum = 0;
            for (int i = 0; i < 9; i++)
            {
                sum = sum + a[i];
            }
            if (sum != 0)
            {
                return 0;
                break;
            }
            else
            {
                return 1;
            }
        }
    }
}

void sudokupuzzle()
{
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solvesudoku(grid) == 1)
    { // if solution of sudoku puzzle exists then print the grid
        printmesh(grid);
    }
    else
    {
        printf("No solution exists"); // else print it not solvable
    }

    printf("Enter your solution :\n");
    int sol[9][9];
    for (int i = 0; i < 9; i++)
    { // entry of puzzle solution by user in form of 9 x 9 matrix
        for (int j = 0; j < 9; j++)
        {
            char ch;
            scanf("%c", &ch);
            sol[i][j] = (int)(ch - '0');
            scanf("%c", &ch);
        }
    }

    if (checksol(sol) == 1 && smallgridcheck(sol) == 1)
    { // checking repetetion in row and column as well as 3 x 3 matrixes
        printf("your solution is correct\n");
    }
    else
    {
        printf("your solution is incorrect\n");
    }

    return 0;
}
