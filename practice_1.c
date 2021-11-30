#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
//int main()
//{
//	int i = 1;
//	while (i<=10)
//	{
//		if (i == 5)
//			continue;//终止本次循环 继续下次循环
//		printf("%d",i);//所以 打印一直循环1
//
//	}
//	return 0;
//}
//int main() 
//{ 
//	int ch = getchar();//gtetchar接收一个键盘输入的字符 输入r
//		//用ch存放
//	putchar(ch);//输出 r
//	printf("\n");
//	printf("%c",ch);//也是一样输出 r
//	return 0;
//}

//int main() 
//{
//	int ch = 0;
//	//EOF - end of file -> -1 文件结束标志，值是-1
//	while ((ch = getchar()) != EOF)//按ctrl+z才能退出 输入EOF不能
//		//因为EOF返回的值是-1 -1为真,循环继续
//	{
//		putchar(ch);
//	}
//	return 0;
//}

//int main() 
//{
//	int ret = 0;
//	char password[20] = {0};
//	printf("请输入密码:>");
//	scanf("%s", password);//输入密码存放在 password数组里
//	printf("确认密码（Y/N）");
//	getchar();//输入字符 若没有这一行 直接就变为放弃确认
//	//原因 上个输入函数scanf = 你输的密码 加上一个回车键 passsword 数组在数据缓冲区拿走123456 剩下回车键
//	第一个getchar会拿走这个回车键 下个getchar就可以正常拿走Y了。
//	ret = getchar();//接收getchar得到的返回值(不含回车)
//	if (ret == 'Y')
//	{
//		printf("确认成功");
//	}
//	else
//	{
//		printf("放弃确认");
//	}
//	return 0;
//}

//下面是可以让输入的任何元素都读到最后的位置
//int main()
//{
//	int ret = 0;
//	int ch = 0;
//	char password[20] = { 0 };
//	printf("请输入密码:>");
//	scanf("%s", password);//输入密码存放在 password数组里
//	printf("确认密码（Y/N）");
//	while ((ch = getchar()) != '\n') {
//	//一直循环 直到读到\n getchar()返回\n 给ch 
//		;//定义一个空语句 让while只做条件语句的内容
//	
//	}
//	//这个getchar就不会读到\n了
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("确认成功");
//	}
//	else
//	{
//		printf("放弃确认");
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')
//			continue;
//			putchar(ch);
//	}
//	return 0;
//}

//int main() 
////用循环打印出1-10
//{	
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//		printf("%d",i);
//	return 0;
//}

//int main() 
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			break;//跳出循环
//		printf("%d",i);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i == 5) {
//			printf("hh\n");
//			printf("hehhe\n");
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	for (i = 0; i < 10; i++)//左边 i = 0; 右边  i < 10 前闭后开
//		//这种标准写法 更有直观的代表10次循环 10次打印 10个元素的作用
//		//for(i = 0;i <= 9;i++)这种i <= 9 也对 但是没有上边的那种看起来舒服
//		//视情况而定
//	{
//		printf("%d", arr[i]);
//	}
//}

//int main() 
//{ 
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)//j循环10次后 回到i循环 i+1 再回到 j循环 j的值又变为0了 j再循环10次..
//		{
//			printf("hehe\n");//打印10*10个hehe
//		}
//	}
//
//	return 0;
//}

//int main() {
//	int x,y;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)//变种for循环 同时满足俩个条件
//	{
//		printf("hehe\n");
//	}
//		return 0;
//}

//int main() {
//	int i = 1;
//	do {
//		printf("%d",i);
//		i++;
//	} while (i <= 10);
//	return 0;
//}

//int main() {
//	long int i = 1;
//	long int j = 1;
//	long int n = 0;
//	long int sum = 0;
//	for (n = 1; n <= 4; n++) {
//		//scanf("%d", &n);
//		while (i <  n)
//		{
//			i++;
//			j = j * i;
//			//printf("%d\n", j);
//		}
//		sum = sum + j;
//	}
//	printf(" % d\n",sum);
//	return 0;
//}

//int main() {
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		ret = ret * n;
//		//n的阶乘
//		sum = sum + ret;
//	}
//	printf("%d \n",sum);
//	return 0;
//}

//最笨的方法查找元素
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k = 9;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//求数组元素的个数
//	for (i = 0; i < sz; i++) 
//	{
//		if (k == arr[i]) 
//		{
//			printf("找到了,下标是: %d \n",i);
//			break;
//		}
//	}
//	if (i == sz)
//		printf("找不到 \n");
//	return 0;
//}


//用二分法 快速查找数组的一个元素
//int main() {
//	int arr[] = {1,2,3,4,5,6,7,8,9,10 };
//	int k = 10;
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算元素个数
//	int left = 0;//左下标
//	int right = sz - 1;//右下标等于元素个数减一
//	while (left <= right) {
//		int mid = (left + right)/2;//中间元素的下标
//		if (arr[mid] > k)//中间元素下标与要找的元素做对比
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else 
//		{
//			printf("找到了,下标是: %d\n", mid);
//			break;
//		}
//	}
//	if (left > right) {
//		printf("找不到");
//	}
//	return 0;
//}

//int main() {
//	//welcome to bit!!!!!!
//	//####################
//	//w##################!
//	//we################!!
//	//we###############!!!
//	//...
//	//welcome to bit!!!!!!
//	char arr[] = "abc";//里面有四个元素
//	//下标分别是 a b c \0
//	//			 0 1 2
//	//4 - 1 得到的是 \0    4 - 2 得到的是c
//
//	char arr1[] = "welcome to bit!!!!!!";//会自动开辟空间[]里面不用填具体的数
//	char arr2[] = "####################";
//	int left = 0;
//	//int right = sizeof(arr1) / sizeof(arr1[0] - 2);//err
//	int right = strlen(arr1)-1;//strlen里面取字符串长度不包括\0
//	
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];//arr1数组的第一个元素 覆盖arr2数组的第一个元素
//		arr2[right] = arr1[right];//arr2数组的最后一个元素 覆盖arr2数组的最后一个元素
//		printf("%s\n", arr2);
//		//休息一秒
//		Sleep(1000);//停止1000毫秒
//		system("cls");//执行系统命令的函数 cls清空屏幕
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//
//			}

//int main() 
//{
//	int i = 0;
//	char password[20] = {0};
//	for (i = 0; i < 3; i++) 
//	{
//		printf("请输入密码");
//		scanf("%s",password);
//		if(strcmp(password,"123456")==0)
////strcmp 用来比较俩个字符串 相等会返回0 第一个元素大于第二个元素 会返回一个大于0的元素 
////第一个元素小于第二个元素 会返回一个小于0的函数
//		{
//			printf("密码正确");
//			break;
//		}
//		else if(i == 3)
//		{
//			printf("三次机会已经用光");
//			break;
//		}
//		else 
//		{
//			printf("输入错误请重新输入 \n");
//		}
//	}
//}