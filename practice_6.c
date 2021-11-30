#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include "train.h"
#include<assert.h>
//输入一个非复整数 打印组成它的数字之和 递归实现
//int DigitSum(unsigned int num)
//{
//	if (num > 9)
//	{
//		return DigitSum(num / 10) + num % 10;//例777 return 77 递归进去 7 递归完毕 返回+num%10  三次都是7+7+7 再返给ret接收 完毕
//	}
//	else 
//	{
//		return num;
//	}
//}
//int main() 
//{
//	unsigned int num = 0;
//	scanf_s("%d", &num);
//	int ret = DigitSum(num);
//	printf("ret = %d\n",ret);
//	return 0;
//}

//递归实现计算n的k次方
//double Pow(int n, int k) 
//{
//	if (k < 0)
//		return (1.0 / Pow(n, -k));
//	else if (k == 0)
//		return 1;
//	else
//		return n * Pow(n, k - 1);//脑子抽了 n^k 不就是k个n相乘嘛 也就是n*n^k-1 然后减到0 . 一直想n^k哪来的 我真是服了..
//}
//int main() 
//{
//	int n = 0;
//	int k = 0;
//	scanf_s("%d%d", &n, &k);
//	double ret = Pow(n,k);
//	printf("ret =%lf\n", ret);
//	return 0;
//}

//结构体 结构体是一些值的集合,这些值称位成员变量,结构体的每个成员可以是不同类型的变量.

//struct Stu //struct Stu 结构体类型 
//{
//	//成员变量
//	char name[20];
//	short age;  //这个函数代表定义一个结构体类型
//	char tele[12];
//	char sex[5];
//}s1 , s2 , s3;//s1,s2,s3 是三个全局的结构体变量 不建议使用这种方式
//int main()
//{
//	struct Stu s;//创建结构体变量
//	return 0;
//}


//typedef struct Stu // typedef 重命名函数名称
//{
//	//成员变量
//	char name[20];
//	short age;  
//	char tele[12];
//	char sex[5];
//}Stu;//这里的Stu是类型
//int  main()
//{
//	Stu s1 = {"张三",20,"15249287076","男"};//初始化结构体变量
//	struct Stu s2 = {"旺财",21,"121321231","雀氏"};
//	return 0;
//}

//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//struct T
//{
//	char ch[10];
//	struct S s;//嵌套结构体
//	char* pc;
//};
//int main() 
//{
//	char arr[] = "hello bit\n";
//	struct T t = { "hehe",{100,'w',"helloworld",3.14},arr};//嵌套结构体的初始化
//	printf("%s\n",t.ch);//hehe
//	printf("%s\n", t.s.arr);//hello world
//	printf("%lf\n", t.s.d);//3.140000 结构体的访问形式
//	printf("%s\n", t.pc);//hello bit 用.操作符访问结构体成员
//	return 0;
//}

//结构体传参
//typedef struct Stu // typedef 重命名函数名称
//{
//	//成员变量
//	char name[20];
//	short age;  
//	char tele[12];
//	char sex[5];
//}Stu;
//void Printf1(Stu tmp)//上 
//{
//	printf("name:%s\n",tmp.name);
//	printf("age:%d\n",tmp.age);
//	printf("tele:%s\n", tmp.tele);
//	printf("sex:%s\n", tmp.sex);
//
//}
//下面的方法更好 不用开辟空间 省时间 也不会压栈 能用这种就用这种 尤其是变量多的时候
//void Printf2(Stu* ps)//下
//{
//	printf("name:%s\n",ps->name);
//	printf("age:%d\n", ps->age);
//	printf("tele:%s\n", ps->tele);
//	printf("name:%s\n", ps->sex);
//
//}
//int main() 
//{
//	Stu s = {"李四",40,"15965411","男"};
//	Printf1(s);
//	Printf2(&s);
//	return 0;
//
//}

//int main() 
//{
//	int a[20] = { 3,5,2,1 };
//	int* p = a;
//	int i = 0;
//	for ( i = 0; i < 20; i++)
//	{
//		(*p) ++;
//		printf("p=%d\n",*p);
//		p++;
//	}
//	return 0;
//}


//研究阶乘没有正确运行的原因
//int main() 
//{
//	int i = 0;
//	int sum = 0;
//	int n = 0;
//	int ret = 1;
//	scanf_s("%d", &n);
//	for ( i = 1; i <=n; i++)
//	{
//		//ret = 1; 通过调试找到bug ret没有初始化为1
//		int j = 0;
//		for ( j = 1; j <=i; j++)
//		{
//			ret *= j;
//
//		}
//		sum += ret;
//
//	}
//	printf("%d\n",sum);
//	return 0;
//}

//该程序是个死循环 原因是数组越界了
//栈区的默认使用
//先使用高地址的空间，在使用低地址处的空间
//在不同的机器和编译器下内存的布局有差异 分配空间就有差异 死循环的条件也有差异

//死循环解释:
//main函数内部创建了i和arr数组 这俩个都是局部变量 局部变量存放在栈上 由于栈的默认使用习惯是:先使用高地址的空间，在使用低地址处的空间
//所以i一定 在arr的上方创建 随着数组下标增长 地址由低到高增长 所以数组合适的向后越界 就可以在越界的过程中遇到i(此时数组的arr[12]的地址与i相同) 
//在改变数组元素时 有可能越界把i的值也改变了 也就改变了循环条件 造成死循环！！！

//int main()
//{
//	int i = 0;//这句话放到arr创建后面 就不会造成死循环了 但是依旧会报越界错误 因为此时i的地址在arr下面
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for ( i = 0; i <=12; i++)
//	{
//		printf("呵呵\n");
//		arr[i] = 0;//C6201 越界  VS编译器的i是在数组的上面 中间差俩个空元素 所以要i<=12  11就报错(报错原因是编译器读取到了超出数组的元素) 
//		//12以上全都是死循环  为什么不报错 因为编译器正忙着循环
//	}
//	system("pause");
//	return 0;
//}

//解释 当一个负数转换为无符号型时(正数) 将这个负数的补码(包括符号位)当做原码转换成10进制即是答案 因为这个负数转成无符号时 它的符号位1也一起计算了
//
//int main()
//{
//	short i = -32767;
//	unsigned short si = i;
//	printf("%d",si);//32769
//	return 0;
//
//}

//鼠标连点器
//int main() 
//{
//	while (1) 
//	{
//		if (GetAsyncKeyState(VK_SPACE))//按下空格开始执行
//		{
//			while (1) 
//			{
//				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0 ,0, 0, 0);
//				Sleep(0.01);//每0.001s点击一次
//				if (GetAsyncKeyState(VK_ESCAPE)) return 0;//按ESC退出
//			}
//			
//		}
//	}
//	return 0;
//}


//6分算法 满分十分
//void my_strcpy(char* dest ,char*src) 
//{
//	while (*src != '\0')
//	{
//
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;//当循环停下来时 把\0 copy给 arr1数组
//}

// 7分算法  
//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)//
////当src的值是\0时 赋给 dest， dest为\0 循环结束
////判断条件是每次 *dest的值 先赋值 在判断 在++
//	{
//		;
//	}
//
//}

//8分算法
//#include<assert.h>
//void my_strcpy(char* dest, char* src)
//{
//	assert(dest != NULL);//断言 若dest == NULL就会弹出报错信息
//	assert(src != NULL);
//	while (*dest++ = *src++)//
//
//	{
//		;
//	}
//}

////9分
//#include<assert.h>
//void my_strcpy(char* dest, const char* src)//const保护src的值不会改变
//{
//	assert(dest != NULL);//断言 若dest == NULL就会弹出报错信息
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}

//10分
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)//const保护src的值不会改变
//{
//	char* ret = dest;//把dest给ret  链式访问
//	assert(dest != NULL);//断言 若dest == NULL就会弹出报错信息
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;//返回ret 相当于再次调用了char* ret = rest;
//}
//int main() 
//{
//	//strcpy
//	//字符串拷贝
//	char arr1[] = "#############";
//	char arr2[] = "bit";
//	//strcpy(arr1,arr2);//把arr2的值全部拷贝到arr1 包括/0 打印是bit
//	//my_strcpy(arr1, arr2);//传的是地址 拿指针接收
//	//printf("%s\n",arr1);//遇到/0停止打印
//	
//	printf("%s\n", my_strcpy(arr1, arr2));//算法十专用打印
//	return 0;
//}


//const作用 不让修改const类型的值 常量
//int main() 
//{
//	const int num = 10;
//	int n = 100;
//	const int* p = &num;
//	//const 放在指针变量*的左边时,修饰的是*p，也就是说:不能通过p来改变*p(num)的值
//	//*p = 20;//报错:表达式必须是可以修改的左值
//	//p = &n;//这个正常
//	
//	int* const p = &num;
//	//const 放在指针变量*的右边时,修饰的是p本身，p不能被改变了.
//	//*p = 20; //这个正常
//	//p = &n;  //报错:表达式必须是可以修改的左值
//	const int* const p = &num;//*p 和p都改不了了
//	printf("%d",num);
//	return 0;
//}

//满分字符串长度计算
//int my_srtlen(const char* str) //const 保护str指向地址的内容(健壮性)
//{
//	int count = 0;
//	assert(str != NULL);//保证指针的有效值
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main() 
//{
//	char arr[] = "abcdef";
//	int len = my_srtlen(arr);
//	printf("%d\n",len);
//	return 0;
//
//}

//乘法口诀表
//MultiTable(int i, int j) 
//{
//	int a = 0;
//	int b = 0;
//	for (a = 1; a <=i; a++) 
//	{
//		for (b = 1; b <=a; b++) 
//		{
//			printf("%d * %d = %-3d  ",a,b,a*b);
//		}
//		printf("\n");
//	}
//}
//int main() 
//{
//	int i = 0;
//	int j = 0;
//	scanf_s("%d %d", &i, &j);//输入行数  列数
//	MultiTable(i, j);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	float f = 10.0;
//
//	short a = 10; //上
//	short int b = 10;//下 俩种语法一致 int可省略
//
//	return 0;
//}

//写一段代码告诉我们当前机器的字节序是什么
//大多数电脑都是小端存储 即倒着放
//int main() 
//{
//	int a = 1;
//	char* p = (char*)&a;//a是整型 字符型取整型会报错 强转一下 取的还是a的地址 
//	//为啥用char型 因为char型一个字节 在十六进制就是俩位数  01 00 00 00
//	//对于a=1来说只需要判断第一个字节是否是1就行了 
//	if (*p == 1)
//	{
//		printf("小端");
//	}
//	else
//	{
//		printf("大端");
//	}
//	return 0;
//}

//写的好一点
//check_sys() 
//{
//	int a = 1;
//	char* p = (char*)&a;
//	return *p;//可以直接返回*p *p是0就返0 是1就返1
//}
//再好一点
//check_sys()
//{
//	int a = 1;
//	return (char*)&a;//直接返回&a 解引用的值
//}
//int main() 
//{
//	//写一段代码告诉我们当前机器的字节序是什么
//	//返回1,小端
//	//返回0，大端
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//输出什么
//int main()
//{
//	char a = -1;
//	//100000000000000000000000000000001 原
//	//111111111111111111111111111111110 反
//	//111111111111111111111111111111111 补
//	signed char b = -1;
//	unsigned char c = -1; //无符号数整形提升补0 往前面补
//	//0000000000000000000000000 11111111 255
//	printf("a=%d,b=%d,c=%d",a,b,CE_BREAK);//-1 -1 255
//}


//有符号的char范围是-128 ->127
//无符号的char范围是0->255 补码的符号位也计算
//有符号->无符号 先转为补码 在连带符号位计算
//int main() 
//{
//	char a = -128;
//	//10000000 000000000 00000000 10000000 原     //符号位放在最前面
//	//11111111 111111111 11111111 01111111 反
//	//11111111 111111111 11111110 10000000 补
//	//10000000
//	//整形提升11111111 111111111 11111110 10000000  无符号数的原码反码补码相同
//	//这个数就是所求
//	printf("%u\n", a);//%u打印十进制的无符号数字
//	return 0;
//}

//int main() 
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n",i+j);//-10
//// -20
////10000000 00000000 00000000 00010100 原
////11111111 11111111 11111111 11101011 反
////11111111 11111111 11111111 11101100 补
////+
////10
////00000000 00000000 00000000 00001010 原 反 补
////= 
////11111111 11111111 11111111 11110110 补
////10000000 00000000 00000000 00001010 原   -10
//
//}



//任何一个数字放到char型都会被转换到-128-127这个范围内 
//int main() 
//{
//	char a[1000];//-128 - 127
//		int i;
//	for ( i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	//011111111 127
//	//100000000 -128
//	//char的二进制 127时再加1 就变为-128  同理 -128 -1 = 127
//	printf("%d", strlen(a));//-1 -2 ... -128 ->127 126 ...0  strlen读到0就停止 所以是255个字符长度
//	return 0;
//}

//打印杨辉三角 //没有数字的位置默认是0 每个数都是上一行的临近俩个数相加
// 杨辉三角行数等于列数
//		1
//     1 1
//    1 2 1  arr[2][1] = arr[2-1][1-1]+arr[2-1][1] = 1+1 =2
//   1 3 3 1
//  1 4 6 4 1

//1
//11
//121
//1331
//14641

//int main()
//{
//	int arr[10][10] = { 10 };
//	int i = 0;//行
//	int j = 0;//列
//	for ( i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++) 
//		{
//			if (j == 0)//如果第一列为0
//			{
//				arr[i][j] = 1;//第一列改为1
//			}
//			if (i ==j)//对角线全为1
//			{
//				arr[i][j] = 1;
//			}
//			if (i >= 2 && j >= 1)//实际上从第三行第二列才开始计算
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	//打印
//	for ( i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++) //j<=i 由于杨辉三角行数等于列数 所以 列数小于行数打印即可
//		{
//			printf("%d ",arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//题目名称:猜凶手 
//以下为4个嫌疑犯的供词
//A说:不是我             
//B说:是C
//C说:是D
//D说:C在胡说
//一直3个人说了真话,一个人说了假话 写个程序判断凶手

//int main() 
//{
//	int killer = 0;
//	for ( killer = 'a'; killer <= 'd';killer ++)//循环四次 a b c d
//	{
//		//第一次循环killer ='a',if条件为0 + 0 + 0 +1 = 1
//		//第二次循环killer = 'b',if条件为 1 + 0 + 0 + 1 = 2
//		//第三次循环killer = 'c',if条件为1 + 1 + 0 + 1 = 3  满足if条件进行打印 打印killer='c'
//		//第四次循环killer = 'd',if条件为1 + 0 + 1 + 0 = 2
//		if ((killer != 'a')+ (killer == 'c')+ (killer == 'd')+ (killer != 'd') == 3)  //结果是3 代表3个结果为真，一个条件为假
//		{
//			printf("killer = %c\n",killer);//%c打印字符串
//		}
//	}
//	return 0;
//}