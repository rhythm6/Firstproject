#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include "train.h"
//�����Ķ���
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
////�����嶨��ĺ���
//void InitBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++) 
//	{
//		for (j = 0; j < col; j++)
//		{
//			board[i][j] = ' ';//��ÿ��Ԫ�س�ʼ��Ϊ�ո�
//		}
//	}
//}
////void DisplayBoard(char board[ROW][COL], int row, int col) {
////	//һ������   һ�зָ�
////	int i = 0;
////	for (i = 0; i < row; i++) 
////	{
////	//��ӡһ�е�����
////		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
////		//��ӡ�ָ���
////		if (i < row - 1)
////		{
////			printf("---|---|---\n");
////		}
////	}
////}

////n�� ����
//void DisplayBoard(char board[ROW][COL], int row, int col) {
//	//һ������   һ�зָ�
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//��ӡһ�е�����
//		int j = 0;
//		for (j = 0; j < row; j++) {
//			printf(" %c ",board[i][j]);//��ӡ���ǿո� 
//			if (j < row - 1)
//				printf("|");
//
//		}
//		printf("\n");
//		//��ӡ�ָ���
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
//	printf("�������:> \n");
//	while (1)
//	{
//		printf("������Ҫ�µ�����");
//		scanf_s("%d%d", &x, &y);
//		//�ж�x,y����ĺϷ���
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (board[x - 1][y - 1] == ' ')
//			{
//				board[x - 1][y - 1] = '*';
//				break;
//			}
//			else
//			{
//				printf("������Ƿ�");
//			}
//		}
//		else 
//		{
//		printf("����������");
//		}
//	}
//}
//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	printf("�������� >\n");
//
//	while (1)
//	{
//		x = rand() % row;//ģ3 �� 0 1 2 
//		y = rand() % col;//��rand�������srand
//		if (board[x][y] == ' ')//��������ǿո� ˵���������û���¹�
//		{
//			board[x][y] = '#';
//			break;
//		}
//	}
//}
//
////����1��ʾ�������� ����0��ʾû��
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
//				//���û�пո����̾�����
//				return 0;//����
//			}
//		}
//	}
//	return 1;//û��
//}
//char IsWin(char board[ROW][COL], int row, int col) 
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//�ж�������ʤ�����
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]  && board[i][1] != ' ')
//			
//		{
//			return board[i][1];
//		}
//	}
//	for (i = 0; i < col; i++) 
//	{
//		//�ж�������ʤ�����
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') 
//		{
//			return board[i][1];//��������һ������Ԫ�� �����ж�˭Ӯ
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
//	//ֻҪ��return �ķ���ֵ �ʹ�����Ի����ʤ��
//	//�ж��Ƿ�ƽ��
//	if (1 == IsFull(board, ROW, COL)) {
//		//return 'DogF'; ������ֻ�ܷ��ĸ��ֽ� ���˱���
//		return "DogFall";
//	}
//	return 'C';
//}

////ɨ����Ϸʵ�ֺ���
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
//	//��ӡ�к�
//	for (i = 0; i <= col; i++) 
//	{
//		printf("%d ",i);
//	}
//	printf("\n");//��ӡ�к�
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
//		int x = rand() % row + 1;//ģ10 ��1-9
//		int y = rand() % col + 1;
//		if (board[x][y] == '0') {
//			board[x][y] = '$';//1��������
//			count--;
//		}
//	}
//
//}
////'1'-'0'=1
////'3'+'1' = 4 �ַ�3+�ַ�1��������4 ��Ϊ���ǵ�ASCIIֵ��� �͵������ǵ��������
//int  get_mind_count(char mine[ROWS][COLS], int x, int y) 
//{
//	//ÿ������������'1' ��ȥ'0'���� 1 (1��������һ����)
//	//�Ѱ˸������ֵ�������ټ�8��'0' ������˸������м�����
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
//	printf("�������Ų��׵�����:>");
//	scanf_s("%d%d", &x, &y);
//	if (x >= 1 && x <= row && y >= 1 && y <= col) //�ж������Ƿ�Ϸ�
//	{
//		if (mine[x][y] == '$')
//		{
//			printf("�ȵ�����!!!\n");
//			DisplayBoard(mine, row, col);
//			break;
//		}
//		else
//		{
//			//�Ϸ� ͳ����Χ�׵ĸ���
//			int count = get_mind_count(mine, x, y);
//			show[x][y] = count + '0';
//			ExcludeMine(show, mine, x, y);
//			//NoMine(mine, show, x, y);//������ ��������˳��㷴�� ���˺ü���Сʱ
//			DisplayBoard(show, row, col);
//			win++;
//
//			
//		}
//	}
//	else //���Ϸ�
//	{
//		printf("�Ƿ�����������");
//
//	}
//	}
//	if (win == row * col - set) 
//	{
//		printf("��ϲ�����׳ɹ�\n");
//		DisplayBoard(show, row, col);
//
//	}
//
//}
