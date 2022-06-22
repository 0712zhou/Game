//
// Created by xiaozhou on 2022/6/22.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL],int row,int col);
void DiplayBoard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col);
void ComputerMove(char board[ROW][COL],int row,int col);
char Iswin(char board[ROW][COL],int row,int col);
#endif //GAME_GAME_H
