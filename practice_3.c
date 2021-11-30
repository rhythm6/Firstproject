#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
//写一个判断素数的函数 1不是素数
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j < n; j++) { //若j的初始值是1 if条件 return 0 跳出到for循环外部 外部 外部  重要的事情说三遍
//		//会回到主函数里去 就不会执行j++了 然后这样循环 导致无法判断出素数
//		if ((n % j) == 0) {
//			return 0;//能被整除就不是素数
//		}
//	}
//	return 1;//不满足if条件就直接返回1 确定是素数 
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d \n", i);
//	}
//	return 0;
//}

//二分查找k值
//int binary_search(int arr[],int k) //binary(2机制，二元的，此处表示二分)
////此处的int arr[]实际上还是一个指针 32位一个指针是4个字节
//{
//	int sz = sizeof(arr)/ sizeof(arr[0]);//求数组元素个数 4个字节÷4个字节（一个整形元素四个字节） = 1 所以此处应该在主函数里求
//	int left = 0;
//	int right = sz - 1;
//
//	while(left <= right) 
//	{
//		int mid = (left + right) / 2;
//
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main() 
//{
//	//如果找到了返回这个数的下标，找不到返回-1
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int ret = binary_search(arr, k);//在arr数组中查找k 数组在传参的时候 
//	//这里的arr实际上传过去的是第一个元素的地址
//	if (ret == -1) {
//		printf("找不到\n");
//	}
//	else 
//	{
//		printf("找到了,下标是:%d\n",ret);
//	}
//	return 0;
//}

//正确版本
//int binary_search(int arr[], int k,int sz) //binary(2机制，二元的，此处表示二分)
////此处的int arr[]实际上还是一个指针 32位一个指针是4个字节
//{
//	
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	//如果找到了返回这个数的下标，找不到返回-1
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);//求数组元素个数 4个字节÷4个字节（一个整形元素四个字节） = 1 所以此处应该在主函数里求
//	int ret = binary_search(arr, k, sz);//在arr数组中查找k 数组在传参的时候 
//	//这里的arr实际上传过去的是第一个元素的地址
//	if (ret == -1) {
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了,下标是:%d\n", ret);
//	}
//	return 0;
//}

//void Add(int* p)
//{
//	//*p++;//这种写法错误 因为++的优先级＞* 所以是给p的值加1 而不是*p
//	(*p)++;//加个括号改变优先级 给*p整体加1 再传值
//}
//int main() 
//{
//	int num = 0;
//	Add(&num);//每调用一次函数num+1
//	Add(&num);
//	printf("num =%d\n", num);
//	return 0;
//}

//函数的链式调用
//int main() 
//{
//	printf("%d", printf("%d", printf("%d", 43)));//printf 返回所写的字符总数。
//	return 0;
//}


//调用头文件的自定义函数
//#include"train.h"
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = 0;
//	sum = Add(a, b);
//		printf("%d\n", sum);
//		return 0;
//}

//函数递归 输入1234 输出1 2 3 4
//void print(int n) 
//{
//	if (n > 9){//不设此条件 就无限制调用自己 死循环
//		//n = n / 10;
//		//print(n); //这种方法达不到要求 因为 先把n的值除10 导致最终if条件会提前一次终止 输123 打印 1 1 2
//		print(n / 10);//这种可以，因为他是先把值带入下个函数在判断是否满足条件
//	}
//	printf("%d ", n%10);
//}
//int main() 
//{
//	unsigned int num = 0;//无整形的变量
//	scanf_s("%d", &num);
//	print(num);
//	return 0;
//}

 
// 自定义函数求字符串长度
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len = %d",len);
//	return 0;
//	
//}


//不创建临时变量 求字符串长度
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len = %d", len);
//	return 0;
//
//}

//求n的阶乘
//int Fac1(int n) 
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++) 
//	{
//		ret *= i;
//
//	}
//	return ret;
//}
//int Fac2(int n) 
//{
//	if(n<=1)
//	{
//		return 1;
//	}
//	else 
//	{
//		return n * Fac2(n - 1);
//	}
//}
//int main() 
//{
//	int n = 0;
//	int ret = 0;
//	scanf_s("%d", &n);
//	//ret = Fac1(n);//循环的方式
//	ret = Fac2(n);//递归的方式
//	printf("%d\n", ret);
//	return 0;
//}

//斐波那契数列 前俩项之和等于第三项
// 1 1 2 3 5 8 13
//int Fib(int n) 
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) - Fib(n - 2);
//}//这种算法重复套娃 效率极低 不能用
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;//因为前俩项斐波那契都是1 n<=2直接打印c即可
//	while (n > 2) 
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	
//		n--;
//	}
//	return c;
//}
//int main() 
//{
//	int n = 0;
//	int ret = 0;
//	scanf_s("%d", &n);
//	//TDD - 测试驱动开发
//	ret = Fib(n);
//	printf("ret = %d\n",ret);
//	return 0;
//}
//
//汉诺塔问题，青蛙跳台阶 递归算法练习
//
//void move(char x, char y);
//void hannuo(int n, char one, char two, char three)
//{
//	if (n == 1)move(one, three); //递归截止条件
//	else
//	{
//		hannuo(n - 1, one, three, two);//将 n-1个盘子先放到B座位上
//		move(one, three);//将A座上地剩下的一个盘移动到C盘上
//		hannuo(n - 1, two, one, three);//将n-1个盘从B座移动到C座上
//
//	}
//}
//void move(char x, char y)
//{
//	printf("%c--->%c", x, y);
//}
//
//int main()
//{
//	int n;
//	printf("input your number");
//	scanf_s("%d", &n);
//	hannuo(n, 'A', 'B', 'C');
//	return 0;
//}

//void ToH(int n, char x, char y, char z)
//{
//	if (n == 1) {
//		printf("%c-->%c" , x, z);
//	}
//	else
//	{
//		ToH(n - 1, x, z, y);
//		printf("%c-->%c", x, z);
//		ToH(n - 1, y, x, z);
//
//	}
//}
//int main()
//{
//	int n = 0 ;
//	printf("请输入几阶汉诺塔");
//	scanf_s("%d", &n);
//	ToH(n,'a','b','c');//a b c分别为第一个棍，第二个，第三个
//	return 0;
//}

//[]下标引用操作符  也是数组访问操作符
//一维数组创建与初始化
//int main() 
//{//创建一个存放十个整形的数组
//	int arr[10] = { 1,2,3 };//不完全初始化,剩下的元素默认初始化为0
//	char arr1[5] = { 'a',98 };
//	char arr2[5] = "ab";//[a][b][\0]
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//数组大小除以元素大小等于元素2个数
// 		return 0;
//}

//二维数组创建与初始化
//int main() 
//{
//	//三行四列 
//	int arr[3][4] = {1,2,3,4,5};//第一行1234 第二行50000第三行0000
//	int arr1[3][4] = { {123},{456} };//第一行1230 第二行4560 第三行0000
//	int arr2[][4] = { {123},{456} };//行可以省略 列不行 第一行1230 第二行4560
//	return 0;
//}

//遍历二维数组
//int main() 
//{
//	int arr[3][4] = { {1,2,3},{4,5} };
//	//1 2 3 0
//	//4 5 0 0
//	//0 0 0 0
//	int i = 0;
//	for (i = 0; i < 3;i++) 
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++) 
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
 
//冒泡排序
//void bubble_sort(int arr[],int sz)
//{
//	
//	//确定冒泡排序的趟数
//	int i = 0; 
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//假设本次排序已经有序
//		//每一趟的冒泡排序
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)// 第一个数与后九个数逐项比较 大于先交换在执行循环 小于继续下次循环
//			//每一趟的目的是通过交换把最大的数换到最后 这样下次比较就少比较一次 直到循环完毕
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				 flag = 0;//本趟数据排序不完全有序 注意此处是改变flag的值 若是前面加数据类型 循环外部就失效了 因为局部变量的作用域就是最近的那个{}
//			}
//		}
//		if (flag == 1) //当顺序已经是正序时弹出
//		{
//			break;
//		}
//	}
//}
//
//int main() 
//{
//	int arr[] = {9,5,6,7,8,3,4,2,1,0};
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//对arr进行排序,排成正序
//	bubble_sort(arr,sz);//冒泡排序函数
//	for (i = 0; i < sz; i++) {
//		printf("%d",arr[i]);
//	}
//	return 0;
//}

//int main() 
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	printf("%p\n", &arr);
//	printf("%p\b", &arr + 1);//此处是给整个数组的地址加一 
//	//此数组7个元素 每个元素4个字节  数组地址加一总共加的值为: 4*7 = 28
//	return 0;
//}