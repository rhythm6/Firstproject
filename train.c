#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include "train.h"
//函数的定义
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
////三子棋定义的函数
//void InitBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++) 
//	{
//		for (j = 0; j < col; j++)
//		{
//			board[i][j] = ' ';//把每个元素初始化为空格
//		}
//	}
//}
////void DisplayBoard(char board[ROW][COL], int row, int col) {
////	//一行数据   一行分割
////	int i = 0;
////	for (i = 0; i < row; i++) 
////	{
////	//打印一行的数据
////		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
////		//打印分割行
////		if (i < row - 1)
////		{
////			printf("---|---|---\n");
////		}
////	}
////}

////n阶 棋盘
//void DisplayBoard(char board[ROW][COL], int row, int col) {
//	//一行数据   一行分割
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//打印一行的数据
//		int j = 0;
//		for (j = 0; j < row; j++) {
//			printf(" %c ",board[i][j]);//打印的是空格 
//			if (j < row - 1)
//				printf("|");
//
//		}
//		printf("\n");
//		//打印分割行
//			for (j = 0; j < row; j++)
//			{
//				printf("---");
//				if (j < row - 1) 
//				printf("|");
//			}	
//		printf("\n");
//	}
//}
//
//void PlayerMove(char board[ROW][COL], int row, int col) 
//{
//	int x = 0;
//	int y = 0;
//	printf("玩家下棋:> \n");
//	while (1)
//	{
//		printf("请输入要下的坐标");
//		scanf_s("%d%d", &x, &y);
//		//判断x,y坐标的合法性
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (board[x - 1][y - 1] == ' ')
//			{
//				board[x - 1][y - 1] = '*';
//				break;
//			}
//			else
//			{
//				printf("该坐标非法");
//			}
//		}
//		else 
//		{
//		printf("请重新输入");
//		}
//	}
//}
//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	printf("电脑下棋 >\n");
//
//	while (1)
//	{
//		x = rand() % row;//模3 余 0 1 2 
//		y = rand() % col;//用rand必须调用srand
//		if (board[x][y] == ' ')//如果内容是空格 说明这个格子没有下过
//		{
//			board[x][y] = '#';
//			break;
//		}
//	}
//}
//
////返回1表示棋盘满了 返回0表示没满
//char IsFull(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++) 
//	{
//		for (j = 0; j < row; j++) 
//		{
//			if (board[i][j] == ' ')
//			{
//				//如果没有空格棋盘就满了
//				return 0;//满了
//			}
//		}
//	}
//	return 1;//没满
//}
//char IsWin(char board[ROW][COL], int row, int col) 
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//判断行相连胜利情况
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]  && board[i][1] != ' ')
//			
//		{
//			return board[i][1];
//		}
//	}
//	for (i = 0; i < col; i++) 
//	{
//		//判断列相连胜利情况
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') 
//		{
//			return board[i][1];//返回其中一个数组元素 用来判断谁赢
//		}
//	}
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
//	{
//		return board[1][1];
//	}
//	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
//	{
//		return board[1][1];
//	}
//	//只要有return 的返回值 就代表电脑或玩家胜利
//	//判断是否平局
//	if (1 == IsFull(board, ROW, COL)) {
//		//return 'DogF'; 单引号只能放四个字节 多了报错
//		return "DogFall";
//	}
//	return 'C';
//}

////扫雷游戏实现函数
//void InitBoard(char borad[ROWS][COLS], int rows, int cols, char set)
//{
//	int i = 0; 
//	int j = 0;
//	for (i = 0; i < rows; i++) 
//	{
//		for (j = 0; j < cols; j++)
//		{
//			borad[i][j] = set;
//		}
//	}
//}
//void DisplayBoard(char board[ROWS][COLS], int row, int col) 
//{
//	int i = 0;
//	int j = 0;
//	//打印列号
//	for (i = 0; i <= col; i++) 
//	{
//		printf("%d ",i);
//	}
//	printf("\n");//打印行号
//	for (i = 1; i <= row; i++) 
//	{
//		printf("%d ",i);
//		for (j = 1; j <= col; j++) {
//			printf("%c ",board[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//}
//
//void  SetMine(char board[ROWS][COLS], int row, int col)
//{
//	int count = EASY_COUNT;
//	while (count) 
//	{
//		int x = rand() % row + 1;//模10 余1-9
//		int y = rand() % col + 1;
//		if (board[x][y] == '0') {
//			board[x][y] = '$';//1代表是雷
//			count--;
//		}
//	}
//
//}
////'1'-'0'=1
////'3'+'1' = 4 字符3+字符1等于数字4 因为他们的ASCII值相减 就等于他们的数字相减
//int  get_mind_count(char mine[ROWS][COLS], int x, int y) 
//{
//	//每个坐标里面是'1' 减去'0'就是 1 (1代表这是一个雷)
//	//把八个坐标的值加起来再减8个'0' 就是这八个坐标有几个雷
//// return mine[x - 1][y] +
////		mine[x - 1][y + 1] +
////		mine[x][y + 1] +
////		mine[x + 1][y + 1] +
////		mine[x + 1][y] +
////		mine[x + 1][y - 1] +
////		mine[x][y - 1] +
////		mine[x - 1][y - 1] - 8 * '0';
////
//	int count = 0;
//	int i = 0;
//	for (i = x - 1; i <= x + 1; i++) {
//		int j = 0;
//		for (j = y + 1; j >= y - 1; j--) {
//			if (mine[i][j] == '$')
//				count++;
//		}
//	}
//	return count;
//}
////void NoMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y) 
////{
////		if (mine[x - 1][y] != '1' &&
////			mine[x - 1][y + 1] != '1' &&
////			mine[x][y + 1] != '1' &&
////			mine[x + 1][y + 1] != '1' &&
////			mine[x + 1][y] != '1' &&
////			mine[x + 1][y - 1] != '1' &&
////			mine[x][y - 1] != '1' &&
////			mine[x - 1][y - 1] != '1')
////		{
////			show[x - 1][y] = ' ';
////			show[x - 1][y + 1] = ' ';
////			show[x][y + 1] = ' ';
////			show[x + 1][y + 1] = ' ';
////			show[x + 1][y] = ' ';
////			show[x + 1][y - 1] = ' ';
////			show[x][y - 1] = ' ';
////			show[x - 1][y - 1] = ' ';
////		}
////
////}
//void ExcludeMine(char show[ROWS][COLS], char mine[ROWS][COLS], int x, int y)
//{
//	int count1 = get_mind_count(mine, x, y);
//	int i = 0;
//	int j = 0;
//	if (mine[x][y] != '$') 
//	{
//		for (i = x - 1; i <= x + 1; i++)
//		{
//			int j = 0;
//			for (j = y + 1; j >= y - 1; j--) {
//				if ((j == y && i == x) == 0)
//				{
//					if (count1 == 0 && mine[i][j] != '$')
//					{
//						show[i][j] = ' ';
//					}
//				}
//				else if (j == y && i == x && count1 == 0)
//				{
//					show[i][j] = ' ';
//				}
//			}
//		}
//		if (x <= ROWS && y <= COLS) {
//			ExcludeMine(show, mine, x = x + 2, y = y + 2);
//		}
//	}
//}
//void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	int win = 0;
//	int set = EASY_COUNT;
//	while (win < row * col - set)
//	{
//	printf("请输入排查雷的坐标:>");
//	scanf_s("%d%d", &x, &y);
//	if (x >= 1 && x <= row && y >= 1 && y <= col) //判断坐标是否合法
//	{
//		if (mine[x][y] == '$')
//		{
//			printf("踩到雷了!!!\n");
//			DisplayBoard(mine, row, col);
//			break;
//		}
//		else
//		{
//			//合法 统计周围雷的个数
//			int count = get_mind_count(mine, x, y);
//			show[x][y] = count + '0';
//			ExcludeMine(show, mine, x, y);
//			//NoMine(mine, show, x, y);//啊啊啊 参数传递顺序搞反了 搞了好几个小时
//			DisplayBoard(show, row, col);
//			win++;
//
//			
//		}
//	}
//	else //不合法
//	{
//		printf("非法请重新输入");
//
//	}
//	}
//	if (win == row * col - set) 
//	{
//		printf("恭喜你排雷成功\n");
//		DisplayBoard(show, row, col);
//
//	}
//
//}
