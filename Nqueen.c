#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printGraph(int** board , int n){

    for(int i = 0 ; i < n ; i++){
        for(int  j = 0 ; j < n ; j++){
            printf("%s" , board[i][j] ? "Q " : "_ ");
        }
        printf("\n");
    }
    printf("\n\n");
}

bool isSafe(int** board, int n , int row ,int col){

    for(int i = 0 ; i < row ; i++){
        if(board[i][col]) return false;
    }

    for(int i = row , j = col ; i >= 0 && j >= 0 ; i-- , j--){
        if(board[i][j]) return false;
    }

    for(int i = row , j = col ; i >= 0 && j < n ; i-- , j++){
        if(board[i][j]) return false;
    }

    return true;
}

bool solveNQueen(int** board , int n ,int row){

    if(row == n){
        printGraph(board , n);
        return true;
    }

    bool sol = false;;

    for(int col = 0 ; col < n ; col++ ){
        if(isSafe(board , n , row , col)){
            board[row][col] = 1;
            sol |= solveNQueen(board , n, row+1);
            board[row][col] = 0;
        }
    }
    return sol; 
}

int main(){
    int n = 5;

    int** board = (int**)malloc(n * sizeof(int*));
    for(int i = 0 ; i < n ; i++ ){
        board[i] = (int*)calloc(n , sizeof(int));
    }

    if(!solveNQueen(board,n,0)){
        printf("No solution!!");
    }

    return 0;
}