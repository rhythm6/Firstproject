#define _CRT_SECURE_NO_WARNINGS 1
#include"train.h"
#include<assert.h>
//赛马问题 6个跑道 36匹马 无计时器 最少赛几次才能确定前三名 这些马的速度各不相同:
//首先 测试6次得到 每个组的第一名 在对每个组的第一名测试第七次 得到真正的第一名
//第二 由于第一名所在的组 不知道它们之中是否有比每个组第一那次测试的第二第三名跑得快的
//需要让它们与小组测试中的第二名，第三名比较 因为只有6个跑道故先与第三名比较 这是第8次
//同理再拿 第二名所在的小组的其余五匹马与第三名比较 这是第9次
//最后拿第一名所在的小组的第二匹马与 小组赛中的第二名比较 
//这是第10次


//五位运动员 参加比赛 预测他们的比赛排名
//A选手说: B第二，我第三
//B选手说: 我第二,E第四
//C选手说: 我第一,D第二
//D选手说: C最后, 我第三
//E选手说: 我第四,A第一
// 
// 每位选手都只说对一半,请编程确定比赛的名字
//int main() 
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	//名次从1到5 循环也从1开始 加到5之后停止
//	for (int a = 1; a <= 5; a++)
//	{
//		for (int b = 1; b <= 5; b++) 
//		{
//			for (int c = 1; c <= 5; c++) 
//			{
//				for (int d = 1; d <= 5; d++) 
//				{
//					for (int e = 1; e <= 5; e++) 
//					{
//						if (
//							   ((b==2)+(a==3)==1)
//							&& ((b==2)+(e==4)==1)
//							&& ((c==1)+(d==2)==1)
//							&& ((c==5)+(d==3)==1)
//							&& ((e==4)+(a==1)==1)
//							)
//						{
//							if(a*b*c*d*e==120)//若满足abcde分别是第一名第二名...第五名在打印
//							printf("a是第%d名 b是第%d名 c是第%d名 d是第%d名 e是第%d名", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//int main() 
//{
//	//申请空间
//	int *p =(int*) malloc(10 * sizeof(int));//申请十个整型的空间大小 malloc会把申请好的40个字节的地址返回来(默认返回类型为void *) 强转之后用指针接收一下
//	//使用空间(暂时先不讲)
//	//释放空间
//	free(p);
//	p = NULL;//自己改为空指针
//	return 0;
//}

//下面哪个代码是错误的)(D)
//int main() 
//{
//	int* p = NULL;
//	int arr[10] =&arr;
//	return 0;
//}
//A p = arr; 数组首地址给arr 对
//B int(*ptr)[10] = &arr; 数组地址用数组指针接收没毛病
//C p = &arr[0]; 取数组首元素的地址给p 对
//D p = &arr;数组的地址应该放到数组指针里去 这个错误


//下面哪个是函数指针(C)
//A int* fun(int a, int b);//这是一次函数声明 函数返回类型是int*
//B int(*)fun(int a, int b);//语法完全错误
//C int(*fun)(int a, int b);//*fun 指针 指向一个函数 函数的参数是int, int 返回类型是int 
//D(int*)fun(int a, int b);//跟第一种写法一样 也是一个函数声明


//定义一个函数指针,指向的函数有俩个int形参并且返回一个函数指针,返回的指针指向一个有一个int形参且返回int的函数?下面哪个是正确的?(A)
//A int(*(*F)(int, int)    (int)), (*F)(int, int)是指针 外面剩下的返回类型int(*(int)), 还是一个指针 指向的是一个函数 函数的参数是int
//返回类型是int
//B int(*F)(int, int);//光是一个函数指针
//C int(*(*F))(int, int);//什么都不是
//D *(*F)(int, int)(int);//什么都不是

//设有以下函数void fun(int n, char* s)(......), 则下面对函数指针的定义和赋值均是正确的是:(B)
//A void(*pf)(int, char); pf = &fun;//函数参数不对
//B void(*pf)(int n, char* s); pf = fun;
//C void* pf(); *pf = fun;
//D void* pf(); pf = fun;

//下列代码中print_arr函数参数设计那个是正确的 ? (C)
//int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//print_arr(arr,3 ,5);
//
////数组指针int(*arr)[5]
//A void print_arr(int arr[][], int row, int col);//二维数组只能行省略
//B void print_arr(int* arr, int row, int col);//二维数组用二级指针或数组指针接收
//C void print_arr(int*(arr)[5], int row, int col);//拿数组指针接收 正确
//D void print_arr(int(*arr)[3], int row, int col);//元素不对


//int main() 
//{
//	int a[5] = { 5,4,3,2,1 };
//	//5 4 3 2 1
//	int* ptr = (int*)(&a + 1);
//	printf("%d，%d", *(a + 1), *(ptr - 1));//数组的第2位元素4，跨过一个数组再减一 再解引用1的地址 就是1       4    1 
//	return 0;
//}

//int main() 
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));//*(aa+1) 是第二行的地址 也是第二行首元素的地址
//	printf("%d %d",*(ptr1 -1 ),*(ptr2 -1 ));//1 , 6(第二行首元素的地址往前再走一个整型  就是6的地址 解引用 6)
//	return 0;
//}


//题目内容这里面的俩个主函数 要共用一些函数-------------------
//实现一个函数,可以左旋字符串中的K个字符
//例如
//ABCD左旋一个字符得到BCDA
//ABCD左旋俩个字符得到CDAB
//旋转字符串
//#include<assert.h>
////暴力求解法 一个一个挪
//void left_move(char arr[],int k) 
//{
//	assert(arr);//确保指针有效性
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++) 
//	{
//		//左旋转一个字符
//		//1 用临时变量存储字符
//		char tmp = *arr;
//		//2 把其他元素往前挪
//		int j = 0;
//		for (j = 0; j <len-1 ; j++) 
//		{
//			*(arr + j) = *(arr + j + 1);//第1+j个元素与1+j+1个元素换位置  所以j最大是len-1 否则 越界了
//		}
//		//3
//		*(arr + len - 1) = tmp;//把临时变量放到最后一个位置
//	}
//}

//三步翻转法
//ab cdef 
//ba fedc 先逆序ab在逆序cdef
//cd efab 再整体逆序一下

//void reverse(char * left,char* right)
//{
//	assert(left != NULL);
//	assert(right!= NULL);
//	while (left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int len = strlen(arr);
//	assert(k <= len);
//	reverse(arr, arr + k - 1);//逆序左边 为什么要减- 因为arr就是1 第k个元素的地址+1-1还是第k个元素
//	reverse(arr+k, arr + len - 1);//逆序右边
//	reverse(arr, arr + len - 1);//逆序整体
//}
//int main() 
//{
//	char arr[] = "abcdef";
//	left_move(arr, 4);//实际上传的是a的地址
//	printf("%s\n",arr);
//	return 0;
//}

//写一个函数,判断一个字符串是否为另外一个字符串旋转之后的字符串
//例如:给定s1 = AABCD 和 s2=BCDAA 返回1
//给定s1 = abcd 和s2 = ACBD,返回0
/*
AABCD左旋一个字符得到ABCDA
*/

//int is_left_move(char* s1, char* s2)
//{
//	int len = strlen(s1);
//	int i = 0;
//	for (int i = 0; i < len; i++)
//	{
//		left_move(s1, 1);//每次旋转一个字符 然后比较一次
//		int ret = strcmp(s1, s2);//strcmp俩个字符串比较 相等返回0 不相等返回1
//		if (ret == 0)//如果返回的是0就相等
//			return 1;
//		
//	}
//	return 0;
//} 

//另一种is_lest_move
//int is_left_move(char* str1, char* str2)
//{
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 != len2)
//		return 0;
//	//strcat(str1, str1);//strcat字符串连接0函数 参数一想要追加的字符串名字 参数二追加的字符串名字 把str1追加给str1\
//	// String Catenate
//	//上面的代码是错误的 strcat函数不能这样自己追加自己  说明:abc\0 追加def\0 ,先找到a的地址再找到第一个\0的地址，从\0开始把
//	//   /def\0 一个一个的搬过来 最后是读到\0,函数停止 若追加自己:abc\0 abc\0 由于前面俩个字符串都在一个空间存储,只要从\0开始追加abc
//	//  /0就会消失 函数就不会停止 程序就崩溃了。 简单来说追加自己 没有俩个\0让你用
//	strncat(str1, str1, 6);//追加str1本身 6是固定了长度 这个函数可以用来追加自己
//	//把src所指字符串的前n个字符添加到dest所指字符串的结尾处，并覆盖dest所指字符串结尾的'\0'，从而实现字符串的连接。
//	char* ret = strstr(str1, str2);//strstr函数的作用是:在str1里面找找有没有str2 符合就返回str2的首字符地址 不符合返回空指针
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	else 
//	{
//		return 1;
//	}
//}
//int main() 
//{
//	char arr1[30] = "abcdef";//此处不给数组值就会报错 可能是因为strncat函数要知道arr1的长度
//	char arr2[] = "cdefab";
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("是旋转得来的");
//	}
//	else
//	{
//		printf("不是");
//	}
//	return 0;
//}
//共用函数线 ---------------------

//strcat 函数使用
//int main() 
//{
//	char arr1[30] = "abc";
//	char arr2[] = "def";
//	strcat(arr1, arr2);
//	printf("%s\n",arr1);//abcdef
//	return 0;
//} 

//题目名称:
//杨氏矩阵
//题目内容
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在
/*
 1 2 3
 4 5 6
 7 8 9
 */
//要求:时间复杂度小于O(N);
//算法解释 如果找7 先与右上角3比较 3<7 下移一行,再与第二行最右边的6比较 6<7 不在第二行 再下移一行
//再与第三行最右边的9比较 9>7 说明不在第三列 左移一列,再与第二列的最下边的8比较 8>7 不在第二列 再左移一列，
//与最后一个元素7比较 7 = 7符合条件 返回1

//FindNum(int arr[3][3], int k, int* row, int* col)
//{
//	int x = 0;//第一行
//	int y = *col - 1;//第三列
//	while (x <= *row - 1 && y >= 0) 
//	{
//		if (arr[x][y] > k)//右上角的元素比我要找的元素k要大,排除掉右上角这一列
//		{
//			y--;//左移一列
//		}
//		else if (arr[x][y] < k)//右上角元素小于k,说明不在右上角这一行
//		{
//			x++;//下移一行
//		}
//		else
//		{
//			*row = x;//通过地址改掉了x,y的值
//			*col = y;
//			return 1;
//		}
//	}
//	//找不到
//	return 0;
//}
//int main() 
//{
//	int arr[3][3] = { {1,2,3}, {4,5,6},{7,8,9} };
//	int k = 7;//要查找的数是7
//	int x = 3;
//	int y = 3;
//
//	//返回型参数 这个参数可以带回来一些值 
//	int ret = FindNum(arr, k, &x,&y);//传地址可以改变x,y的值
//	if (ret == 1) 
//	{
//		printf("找到了\n");
//		printf("下标是:[%d][%d]", x, y);
//	}
//	else 
//	{
//		printf("没找到\n");
//	}
//	return 0;
//}

