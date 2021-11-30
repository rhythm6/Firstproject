#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include "train.h"
//测试三子棋游戏
//void menu() 
//{
//	printf("***********************************");
//	printf("**********1.play   0.exit *********");
//	printf("***********************************");
//}
////游戏的整个算法实现
//void game() 
//{
//	//棋盘样子
////   |   |
////---|---|---
////   |   |   
////---|---|---
////   |   |
//	char ret = 0;
//	//数组存放玩家走出的棋盘信息
//	char board[ROW][COL] = { 0 };
//	//初始化数组
//	InitBoard(board, ROW, COL);
//	//打印棋盘
//	DisplayBoard(board, ROW ,COL);
//	//下棋
//	while (1)
//	{
//		//玩家下棋
//		PlayerMove(board, ROW , COL);
//		DisplayBoard(board, ROW, COL);
//		//判断玩家赢输
//		ret = IsWin(board, ROW, COL);
//		if (ret != 'C') 
//		{
//			break;
//		}
//		//电脑下棋
//		ComputerMove(board, ROW, COL);
//		DisplayBoard(board, ROW, COL);
//		//判断电脑输赢
//		ret = IsWin(board, ROW, COL);
//		if (ret != 'C')
//		{
//			break;
//		}
//	}
//	if (ret == '*') 
//	{
//		printf("玩家胜利\n");
//	}
//	else if (ret == '#')
//	{
//		printf("电脑胜\n");
//	}
//	else 
//	{
//		printf("平局\n");
//	}
//
//}
//void test() 
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//（time函数返回的是time \t 的值）强制转换成 unsigned int类型
//	//要引入<time.h>头文件
//	do 
//	{
//		menu();//打印菜单
//		printf("请选择");
//		scanf_s("%d", &input);
//		switch (input) 
//		{
//		case 1:
//			game();
//			printf("三子棋\n");
//			break;
//		case 0:
//			printf("退出游戏");
//			break;
//		default:
//			printf("选择错误请重现选择!!!");
//			break;
//		}
//	} while(input);//input为0时 0代表假 就会认为条件是假 跳出循环 不用再写input == 0
//}
//int main() 
//{
//	test();
//	return 0;
//}

////扫雷游戏
//void menu() 
//{
//	printf("*****************************\n");
//	printf("***** 1.play      ***********\n");
//	printf("***** 0,exit      ***********\n");
//	printf("*****************************\n");
//
//}
//void game()
//{
//	//雷的信息存储
//	//1.布置好的雷的信息
//	char mine[ROWS][COLS] = { 0 };
//	//排查出的雷的信息
//	//玩家看的棋盘
//	char show[ROWS][COLS] = { 0 };
//	//初始化数组
//	InitBoard(mine, ROWS, COLS, '0');//分别初始化为:0    *
//	InitBoard(show, ROWS, COLS, '*');
//	//打印棋盘
//	DisplayBoard(mine, ROW, COL);
//	//DisplayBoard(show, ROW, COL);
//	//布置雷
//	SetMine(mine, ROW, COL);
//	DisplayBoard(mine, ROW, COL);
//	FindMine(mine, show, ROW, COL);
//}
//void test() 
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf_s("%d", &input);
//		switch (input) 
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏");
//			break;
//		default:
//			printf("选择错误，重新选择");
//			break;
//		}
//	} while (input);
//}
//int main() 
//{
//	test();
//	return 0;
//}

//单目操作符
//int main()
//{
//	//& 按二进制位与 同时为真才为真
//	int a = 3;
//	int b = 5;
//	int c = a & b;
//	//000000000000000000000000000011
//	//000000000000000000000000000101
//	//000000000000000000000000000001
//	printf("%d\n",c);//1
//	return 0;
//}

//int main()
//{
//	//| 按二进制位或 同时为假才为假
//	int a = 3;
//	int b = 5;
//	int c = a | b;
//	//000000000000000000000000000011
//	//000000000000000000000000000101
//	//000000000000000000000000000111
//	printf("%d\n", c);//7
//	return 0;
//}

//int main()
//{
//	// ^ 按二进制位异或 相同为0 相异为1
//	int a = 3;
//	int b = 5;
//	int c = a ^ b;
//	//000000000000000000000000000011
//	//000000000000000000000000000101
//	//000000000000000000000000000110
//	printf("%d\n", c);//6
//	return 0;
//}


//不创建第三个变量 交换俩个变量的值
//int main()
//{
//	
//	int a = 5;
//	int b = 3;
//	////加减法--只能用整形 容易栈溢出 或者丢失数据
//	//a = a + b;
//	//b = a - b;
//	//a = a - b;
//	
//	//按位异或法
//	//一个数
//	//原理:一个数异或它自己等于0,0异或任何数(0以外的数) 都是那个数本身 --> 一个数连续异或自己俩边=自己
//
//	a = a ^ b;
//	b = a ^ b;// b = a(^b^b)=a^0=a
//	a = a ^ b;// a = a^b^b(第一个b还是等于原来的b 第二个b等于a) = a^b^a = b
//	printf("%d %d", a, b);
//	return 0;
//}
//求一个整数存储在内存中的二进制中1的个数
//int main() 
//{
//	int num = 0;//3 - 011 第一次模2 01 在模1 得0
//	int count = 0;
//	scanf_s("%d", &num);
//	//统计二进制中补码中有多少个1
//	//while (num) //法1
//	//{
//	//	if (num % 2 == 1)
//	//	{
//
//	//		count++;
//	//	}
//	//	num = num / 2;//若这一行写进if里 num的值传给while一次后又会变为num本身的值 若此时num！=1 这就是个死循环
//	//}
//	
//	//int i = 0;//法2
//	//for ( i = 0; i < 32; i++)
//	//{
//	//	if (1 == ((num >> i) & 1))
//	//	count++;
//	//}
//	//法3 最好
//	while (num) 
//	{
//		count++;
//		num = num & (num - 1);
//	}
//	//3的二进制是011
//	//011 与
//	//010
//	//得 
//	//010
//	// 
//	//001 与
//	//000
//	// 得
//	//000 while循环停止
//	printf("%d\n", count);
//	return 0;
//}

//变量创建的时候给值叫初始化
//后面再给值叫赋值
//单目操作符 只有一个操作符
// ！ 逻辑反操作 真变假 假变真
//int main() 
//{
//	int a = 0;
//	//printf("%d\n",!a);//使a变为1(真)
//	if (!a)//如果a为假 则!a为真 执行函数体
//	{
//		printf("呵呵\n");
//	}
//	
//	return 0;
//}
//&取地址操作符
//*解引用操作符 通过p里面的值找到它所指的对象a
//int main() 
//{
//
//	int a = 10;
//	int *p = &a;
//	*p= 20;//把a的值改为20
//}
// 
//sizeof()操作符 计算变量(包括数组)所占内存空间的大小 单位是字节
//sizeof() 后面是变量可以省去括号sizeof 是类型就不行
//int main()
//{
//	int a = 10;
//	char c = 'r';
//	char* p = &c;
//	int arr[10] = { 0 };
//	printf("%d\n",sizeof(a));//4 整形一个元素四个字节
//	printf("%d\n", sizeof(c));//1 字符型1个
//	printf("%d\n", sizeof(p));//4 指针在32位中是4个 64位中是8个
//	printf("%d\n", sizeof(arr));//40 10个整形变量空间 10*4=40
//	printf("%d\n", sizeof(int));// 4
//	printf("%d\n", sizeof(char));// 1
//	printf("%d\n", sizeof(char*));// 4
//	printf("%d\n", sizeof(int [4]));// 16 数组也是有类型的 去掉名字就是类型
//	short s = 0;
//	int a = 10;
//	printf("%d\n",sizeof(s = a+s));// 2 短整型一个字符是2 无论a s 是何值 最终结果还是看等号左边的s
//	printf("d\n",s);//0 sizeof(括号内不参与运算)
//	return 0;
//}

// ~按位取反 0变1 1变0
//int main() 
//{
//	int a = 0;
//// 0000000000000000000000000000000 ~
//// 1111111111111111111111111111111 补码
//// 1111111111111111111111111111110 补码减一
//// 0000000000000000000000000000001 在取反就是原码
//	printf("%d\n",~a);//-1 打印的是原码
//	return 0;
//}

//int main() 
//{
//	int b = 11;
//	b = b | (1 << 2);
//	printf("%d\n", b);//15
//	b = b & (~(1 << 2));
//	/*
//	 0001 <<2
//	 0100 ~
//	 1011 
//	 & 1111
//	 1011
//
//	 */
//	printf("%d\n", b);//11
//	return 0;
//}
/* ++i 前置++ 先++, 后使用该元素 
   i++ 后置++ 先使用 再++

*/

//(强制类型转换)
//int main() 
//{
//	int a = (int)3.14;
//	return 0;
//}

//void test1(int arr[])
//{
//	printf("%d\n",sizeof(arr)); //虽然数组是int型 但这里的参数是第一个元素的地址 只要是地址传过来 
//							//接收地址就要用指针 所以在32位的环境下 arr大小就是4
//}
//void test2(char ch[])
//{
//	printf("%d\n",sizeof(ch));//同理也是4
//}
//int main() 
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n",sizeof(arr));//整形4个字节 乘 10个元素 40
//	printf("%d\n",sizeof(ch));// 字符型一个字节 乘10个元素 10
//	test1(arr);
//	test2(ch);
//	return 0;
//}

//逻辑操作符
//&& 逻辑与 当&&左边的条件是假,右边语句不再计算 直接返回0 可以连续&&判断 顺序从左往右
//int main() 
//{
//	int a = 3;
//	int b = 5;
//	int c = a && b;
//	printf("%d\n",c);//1 都为真结果为真
//	return 0;
//}
// ||逻辑或 当||左边的条件是真,右边语句不再计算 直接返回1 可以连续||判断 顺序从左往右
//int main()
//{
//	int a = 0;
//	int b = 5;
//	int c = a || b;
//	printf("%d\n", c);//1 俩个为假才为假
//	return 0;
//}

//int main() 
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;//当a=0时条件已经为假 a++右边的语句不再执行
//	//printf(" i= %d\n a=%d\n b=%d\n c=%d\n d=%d\n", i, a, b, c, d);//0 1 2 3 4
//	i = a++ || ++b || d++;
//	printf(" i= %d\n a=%d\n b=%d\n c=%d\n d=%d\n", i,a, b, c, d);//1 1 3 3 4 a为假判断b b为真 停止判断 若a=1 答案1 2 2 3 4
//	return 0;
//}
// 
//条件操作符 (三目操作符)
// ？: 
//表达式1 ? 表达式2: 表达式3  表达式为真 计算表达式2 忽略表达式3
//表达式1为假 表达式3计算 忽略表达式2
//int main() 
//{
//	int a = 0;
//	int b = 0;
//	//if (a > 5)
//	//{
//	//	b = 3;
//	//}
//	//else
//	//{
//	//	b = -3;
//	//}
//	b = a > 5 ? 3 : -3;//上面if else等同这一行
//	return 0;
//}

//逗号表达式 从左往右执行 整个表达式的结果是最后一个表达式的结果
//int main() 
//{
//
//	int a = 1, b = 2;
//	int c = (a > b, a=b+10, b = a + 1);//c的值为最后b的值
//	printf("%d\n",c);//c=b=12+1=13
//	return 0;
//}
// 
//int main() {
//	int a = 2;
//	int b = 1;
//	int c = 1;
//	int d = 0;
//	if (a = b + 3, c = a / 2, d > 0) //先从左往右执行(与最后的表达式不冲突) 最后再判断if条件是否成立
//	{
//		printf(" %d\n %d\n %d\n %d\n",a,b,c,d);//条件为假 不执行
//	}
//	printf(" %d\n %d\n %d\n %d\n", a, b, c, d);//4 1 2 0
//}
//[]下标引用操作符 操作数是数组名和下标值
//()函数调用操作符 最少一个参数 操作数是函数名，参数

//创建结构体 关键字struct 结构体名称
// {
// }; //注意结尾的大括号要再加一个分号
//学生
//.操作符用来访问结构体成员 
//struct Stu //是一种类型
//{
//	//成员变量
//	char name[20];
//	int age;
//	char id[20];
//};
//法一

//int main() 
//{
//	int a = 10;
//	struct Stu s1 = {"张三",20,"2019010305"};
//	printf("%s\n", s1.name);//结构体变量.成员名
//	printf("%d\n", s1.age);
//	printf("%s\n", s1.id);
//	return 0;
//}

//法二 用指针访问结构体变量 ->操作符跟逗号功能差不多(看起来更直观)
// 结构体指针 -> 成员名
//int main() 
//{
//
//	int a = 10;
//	struct Stu s1 = {"张三",20,"2019010305"};
//	struct Stu* ps = &s1;
//	printf("%s\n", ps->name);
//	printf("%d\n", ps->age);
//	printf("%s\n", ps->id);
//	/*printf("%s\n",(*ps).name);
//	printf("%d\n", (*ps).age);
//	printf("%s\n", (*ps).id);*/ //这样写太啰嗦 
//
//	return 0;
//}

//隐式类型转换(看不见的类型转换)
//C的整形算是运算总是以缺省整形类型的精度来进行的。
//为了获得这个精度,表达式中的字符和短整型操作数在使用之前前被转换为普通
//整型，这种转换称位整型提升。
//整型提升的意义:整型运算在CPU的相应的运算器件内执行,CPU的操做数的字节长度一般就是
//int的字节长度(8),同时也是CPU的通用寄存器的长度。
//因此 即便是两个char类型相加,CPU实际执行时也要先转换为整型在相加。
//CPU难以直接实现俩个8比特字节直接运算,所以表达式中可能小于int长度的整型值，
//都必须先转换为int或unsigned int ,然后才能送入CPU去执行运算。

//整形提升
//int main() 
//{ 
//	char a = 3;
//	//3的二进制00000000 00000000 00000000 00000011
//	//进行截断 最后面的8位数拿下来00000011 - a
//
//	char b = 127;
//	//00000000 00000000 00000000 01111111
//	//截断 011111111 - b
//	char c = a + b;
//	// 00000011(a)  +
//	// 01111111(b) 要运算必须要进行整形提升
//	//整型提升 符号位(首位)是0前面补上24个0 是1补上24个1
//	//00000000 00000000 00000000 00000011
//	//00000000 00000000 00000000 01111111 直接相加后 从末尾开始加 满2进1
//	//00000000 00000000 00000000 10000010 因为c是char型再次截断
//	//10000010 - c 但由于打印的是%d整形 提升 符号位为1 补1
//	//11111111 11111111 11111111 10000010 - 补码
//	//11111111 11111111 11111111 10000001 - 补码-1得反码
//	//10000000 00000000 00000000 01111110 符号位不变 其他全取反 原码
//	printf("%d\n",c);//-126 打印的是原码
//	return 0;
//}

//整型提升 实例
//int main() 
//{
//	char a = 0xb6;//10110110
//	short b = 0xb600;
//	int c = 0xb6000000;
//	if (a == 0xb6)//由于a 和 b 都不是整型所以会进行整形提升
//		//提升后的值与原来就不同了
//		printf("a");
//	if (b == 0xb600)
//		printf("b\n");	
//	if (c == 0xb6000000)
//		printf("c");//只有c原本是整形 可以正常打印
//
//	return 0;
//}

//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c));//1
//	printf("%u\n", sizeof(+c));//4 c只要参加表达式运算,就会发生整形提升 c的值改变 但打印完后c还是1 所以实际上还是不参与运算
//	printf("%u\n", c);
//	printf("%u\n", sizeof(!c));//1 sizeof(括号内不参与运算 最终c的值还是1)
//	return 0;
//}

//算式转换 低级别想与高级别运算 那么只能是低转成高
/* 从高到低
long double
double
float
unsigned long int
long int
unsigned int 
int
*/
//操作符的优先性和结合性(就是执行顺序) 想看直接百度
//我们写的表达式必须要有唯一的计算路径 否则不同的编译器的结果不同 不同系统环境下也不同 别写很复杂的表达式
