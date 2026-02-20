#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int board[MAX];
int N;
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||             
            abs(board[i] - col) == abs(i - row)) 
            return 0;
    }
    return 1;
}
int solveNQueen(int row) {
    if (row == N)
        return 1;   

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;

            if (solveNQueen(row + 1))
                return 1;
        }
    }
    return 0;
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &N);

    if (solveNQueen(0)) {
        printf("Solution:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}