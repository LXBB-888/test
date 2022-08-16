#pragma once

#include<stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3

//初始化棋盘的
void InitBoard(char board[ROW][COL], int row, int col);

//画出棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayMover(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//
//1. 玩家赢了 - *
//2. 电脑赢了 - #
//3. 平局 - Q
//4. 游戏继续 - C

//判断游戏是否有输赢
char IsWin(char board[ROW][COL], int row, int col);