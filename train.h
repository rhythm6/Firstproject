#pragma once
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#ifndef _ADD_H__//防止头文件被重复包含和编译。
////函数的声明
//int Add(int x, int y);
//
////三子棋游戏用的函数
//#define ROW 3
//#define COL 3
//void InitBoard(char board[ROW][COL], int row, int col);
//void DisplayBoard(char board[ROW][COL], int row, int col);
//void PlayerMove(char board[ROW][COL], int row, int col);
//void ComputerMove(char board[ROW][COL], int row, int col);
//
////四种游戏状态
////玩家赢 返回Win
////电脑赢 返回Fail
////平局   返回DogFall
////继续游戏 返回 C
//char IsWin(char board[ROW][COL], int row, int col);


//扫雷游戏用的函数
//#define ROW 9
//#define COL 9
//#define ROWS ROW+2
//#define COLS COL+2
//#define EASY_COUNT 5;//定义雷的数量
//void InitBoard(char borad[ROWS][COLS ],int rows , int cols ,char set);
//void DisplayBoard(char board[ROWS][COLS], int row ,int col);
//void SetMine(char board[ROWS][COLS], int row, int col);
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
#endif//防止头文件被重复包含和编译。
