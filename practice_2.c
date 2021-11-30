#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
/* 判断三个数中最大的数 按大到小放
方法1 没有按顺序放 只打印出最大值
//int main() 
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	//char a[10], b[10], c[10];
//	printf("请输入字符串:");
//	//scanf("%s%s%s", &a, &b, &c); 数组无法用来比较 会错误
//	if ((a > b) && (a > c))
//	{
//		printf("%d", a);
//	}
//	else if((b > a) && (b > c))
//	{
//		printf("%d", b);
//	}
//	else if((c > a) && (c > b))
//	{
//		printf("%d", c);
//	}
//	else 
//	{
//		printf("有用？");
//	}
//}

方法2
int main() 
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("请输入三个数字");
	scanf("%d%d%d", &a, &b, &c); //&前面有个空格不能少
	if(a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
		//创建一个tmp 存储a的值
		//当a < b 时a b 通过一个其他变量交换值
	}
	if(a < c)//若a < b 此时相当于 b < c 进行比较
	{
		int tmp = a;
		a = c;
		c = tmp;
		//当a < c 时a c 通过一个其他变量交换值
	}
	if(b < c)
	{
		int tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}
*/
// 最大公约数的求法 辗转相除法
//int main() 
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//	scanf("%d%d", &m, &n);
//	while (m % n) 
//	{
//		r = m % n;
//		m = n;
//		n = r;
//	}
//	printf("%d\n", n);
//
//}

//计算几几年到几几年有多少个闰年
//int main() 
//{
//	int count = 0;
//	int year = 0;
//	for(year = 1000; year <= 2000; year++)
//	{
//		
//		if (year % 4 == 0 && year % 100 != 0)
//		{
//			printf("%d ",year);
//			count++;//是闰年就加1
//		}
//		else if (year % 400 == 0) 
//		{
//			printf("%d ", year);
//			count++;
//		}
//
//	}
//	printf("\n count = %d", count);
//	return 0;
//}
//条件一行搞定
//int main()
//{
//	int count = 0;
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//
//		if((year%4 == 0 && year%100!= 0)||(year%400==0))
//		{
//			printf("%d ", year);
//			count++;//是闰年就加1
//		}
//	}
//	printf("\n count = %d", count);
//	return 0;
//}

//试除法
//int main() 
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i<=200; i++)//判断100到200的素数 被除数
//	{
//		//判断i是否是素数
//		//产生2 到i-1 的素数
//		int j = 0;
//		for (j=2; j<i; j++)//除数 
//		{
//			if (i%j == 0)//从开始 除不尽继续
//			{
//
//				break;//不是素数就跳出
//			}
//		}
//		if (j == i)//只有当i%j 没有跳出 执行到i=j时 才是素数
//		{
//			printf("%d\n", i);
//			count++;
//		}
//	}
//	return 0;
//	printf("\n count = %d",count);
//}

//辗转相除法 优化算法: 因为偶数不可能是素数 所以排除偶数
//由于 i = a x b; 此时a,b必定有一个数小于等于 i的开平法
//所以可以少判断一些数 sqrt就是开平发
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i+=2)//判断100到200的素数 这是被除数
//	{
//		//判断i是否是素数
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)//除数 
//		{
//			if (i % j == 0)//从开始 除不尽继续
//			{
//
//				break;//不是素数就跳出
//			}
//		}
//		if (j > sqrt(i))//除数大于 i的开平方 就不用判断了 直接打印
//		{
//			printf("%d\n", i);
//			count++;
//		}
//	}
//	return 0;
//	printf("\n count = %d", count);
//}

//1-100含9的数
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{//个位为9
//			count++;
//		}
//		else if (i / 10 == 9)
//		{//十位为9
//			count++;
//		}
//	}
//	printf("count = %d\n", count);
//	return 0;
//
//}
//1-100有多少个9
//int main()//俩个if都要走
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		//个位为9
//			count++;
//		if (i / 10 == 9)
//			count++;
//		
//	}
//	printf("count = %d\n", count);
//	return 0;
//
//}

//计算一分之一减二分之一加三分之一...减一百分之一
//int main() 
//{
//	int i = 0;
//	double sum = 0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		//sum += 1 / i;//这样不行 只会等到整数 会丢失数据
//		sum += flag * 1.0 / i;
//		flag = -flag;//每算一次 改变一次符号
//	}
//	printf("%lf", sum);//打印浮点型
//}

//判断十个元素的大小
//int main()
//{
//	int arr[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
//	//int max = 0;//最大值不能自己设定值 
//	int max = arr[0];//应该设置为数组的数 这样自己设定的数永远不会超过数组的元素值
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//获取数组长度
//	for (i = 0; i < sz; i++) 
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max =%d",max);
//	return 0;
//}

//打印九九乘法口诀表
//int main() 
//{
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		//打印行数
//		int j = 1;
//		for (j = 1; j <= i; j++)//打印列数
//		{
//			printf("%d*%d=%d\t", i, j, i * j);//%-2d是左对齐 俩个空格
//		}
//		printf("\n");
//	}
//	return 0;
//}


//猜数字游戏
//void menu()
//{
//	printf("*****************888888888****");
//	printf("****** 1.Play  0. EXit    *****");
//	printf("**************888888888*******");
//
//}
////RAND_MAX; 16进制数 值是32727
//void game() 
//{
//	//1.生成随机数
//	int ret = rand();
//	int guess = 0;
//	ret = rand()%100+1;//0-32727 模上100结果的范围是1-99 所以加1 就是1-100
//	//printf("%d\n",ret);
//	//2.猜数字
//	while (1)
//	{
//		printf("请猜数字");
//		scanf_s("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else if (guess < ret) 
//		{
//			printf("猜小了");
//		}
//		else 
//		{
//			printf("猜对了\n");
//			break;
//		}
//
//
//	}
//}
//int main() 
//{
//	//拿时间戳 设置随机数的生成起始点 
//	srand((unsigned int)time(NULL));//获取时间戳
//	//srand 的参数类型要int型 给time函数加个unsigned int 转换成int型
//	//srand 随机数发生器的初始化函数
//	//由于时间戳要设置起点 不能反复调用 一次就行
//	int input = 1; 
//	do
//	{
//		menu();
//		printf("请选择>:");
//		scanf_s("%d", &input);
//		switch(input)
//		{
//		case 0://退出游戏
//			printf("退出游戏");
//			break;//这里的break只是跳出switch语句而已
//		case 1:
//			game();//进入game函数开始玩游戏
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while(input);// while 0为假 非零为真 所以一旦 输入 0 while就跳出
//	return 0;
//}

//goto语句
//int main()
//{
//again:
//	printf("狐臭弹");
//	goto again;//again 放到哪里 goto跳到哪里 最好用来直接跳到某个位置 加强版的break 指定地点降落
//	return 0;//goto语句少用 bug之王
//}

//int main() 
//{
//	char input[20] = {0};
//	//shutdown -s -t 60 设定电脑60s后关机
//	//shutdown -a取消命令
//	system("shutdown -s -t 60");
//again:
//	printf("请注意,你的电脑在1分钟内关机,如果输入:我是猪,就取消: ");
//	scanf_s("%s", input);
//	if (strcmp(input, "我是猪") == 0)//比较俩个字符串-strcmp
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//		return 0;
//}
//int main() 
//{
//	// strcpy 字符串拷贝
//	// strlen 字符串长度 
//	char arr1[] = "bit";
//	char arr2[] = "##############";
//	strcpy(arr2, arr1);//用arr1的值拷贝arr2 ,首先arr1的长度 要小于arr2
//	//原本拷贝后应该是bit###########
//	//但由于bit 后有个\0 遇到\0就停止拷贝了 所以#####都没了
//	printf("%s\n",arr2);
//	return 0;
//}

//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, '*', 5);//把前五个字符 换成五个*
//	printf("%s\n",arr);
//	return 0;
//}
//// memset： memory（在电脑里叫内存 单词意思是记忆） set 设置

//写一个函数可以交换俩个整形变量的内容
//void Swap1(int x ,int y )//void 是无返回类型 int x,int y就是形参
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//	return x, y;
//	//此函数没有将值传回主函数里去 所以原a，b的值没有互换
//}
//void Swap2(int* pa, int* pb)//指针变量 用来接收地址 int* pa, int* pb也是形参
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//  Swap1(a,b)//传值调用
//	Swap2(&a, &b);//传址调用， & 取地址符 这个里面的&a,&b就是实参
//  
//	printf("a = %d,b =%d\n", a, b);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* pa = 20;//pa int类型的指针变量
//	*pa = 20;//解引用操作 
//	printf("%d\n", a);
//	return 0;
//}