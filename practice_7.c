#define _CRT_SECURE_NO_WARNINGS 1
//浮点型存储
//#include"train.h"
/*
1001.0 以下面方式存储
(-1)^0 * 1.001 * 2^3
(-1)^S *   M   * 2^E
E是无符号数 但E有时候确实为负数 E如何表示呢
E加上一个中间数来表示 8位数的E就加上127 11位数的加上1023
E的真实值是存进去的值减去127(或1023)

101.1
(-1)^0 * 1.011* 2^2 科学计数法表示
S = 0
M = 1.011  小数位011 补到23位 0110000000000000000000
E = 2 2+127放进去 = 129 129的二进制序列 10000001
0(S) 10000001(E) 0110000000000000000000(M) 二进制位
4个二进制位是一个十六进制位
0100 0000 1011 0000 0000  0000 0000 0000
0x 4 0 b 0 0 0 0 0 16进制 ox开头而已 其他每个数代表上面四个二进制位
二进制反推浮点型
M的开头补1  1.011 
(-1)^0 *1.011 * 2^2

E的俩种特殊情况
1  E的二进制全为0  此时E = 0(存进去的值)- 127 = -127  2 ^-127次方 无限趋近于0
此时规定 浮点数E = 1-127 或1-1023 即为E的真实值 有效数字M不再补个1 而是还原为0.xxxxx的小数 这样是为了表示±0(alt+0177快速打出±)
以及接近于0的很小的数字

2 E的二进制全为1，表示±无穷大
*/

//int main() 
//{
//	int n = 9;
//	//0 00000000 00000000000000000001001 补码
//	//(-1)^2 * 0.00000000000000000001001 * 2^-126  无限趋近于0 
//	float* pFloat = (float *)&n;//结果为0.000000
//	printf("*pFloat的值为:%f\n",*pFloat);//整型初始化 浮点型打印
//
//
//	*pFloat = 9.0;//修改n为浮点型 n=9.0
//	//1001.0
//	//1.001 * 2^3
//	//(-1)^0 * 1.001 * 2^3
//	//0 10000010(这里是3+127) 001 00000000000000000000(后面都是补的0)
//	//转换为10进制 1091567616
//	printf("*pFloat的值为:%d\n",n);//改为浮点型 整型打印 1091567616
//
//}

//指针进阶
// 
//不同操作系统结果不同
//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", sz);//32 位1 64位2
//}
//int main()
//{
//	int arr[10] = { 0 };
//	test(arr);
//	return 0;
//}

//第一种写法
//int main() 
//{
//	char arr[] = "abcdef";
//	char* pc = arr;
//	printf("%s\n",arr);//abcdef
//	printf("%s\n", pc);//abcdef *pc里面是a的值 pc是整个"abcdef"
//	return 0;
//}

//第二种写法
//int main() 
//{
//	const char* p = "abcdef";//"abcdef" 是一个常量字符串 把a的地址赋给p
//	//最好在前面加const 想改都改不了
//	//*p = 'W';//这种写法是错误的 常量字符串里面的东西不能被改
//	printf("%c\n", *p);//a
//	printf("%s\n", p);//abcdef
//	return 0;
//}
//www.stackover.com
//segmentfault.com//防上面的网站做的国内网站 问题解答网站 


//int main() 
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//	printf("%s %s",arr1,arr2);
//	if (arr1 == arr2)//数组名在绝大多数表示 该数组首元素的首地址  能相同吗？不可能的
//	{
//		printf("哈哈哈%s",arr1);
//	}
//	else
//	{
//		printf("嘻嘻嘻%s",arr2);//打印这个
//	}
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	const char* p1 = "abcdef";//常量字符串
//	const char* p2 = "abcdef";//p1 和 p2存的地址一样 
//	printf("%s %s\n", p1, p2);
//	if (p1 == p2)//所以p1 == p2
//	{
//		printf("打印这个\n");
//	}
//	else
//	{
//		printf("绝对不是这个");
//	}
//	return 0;
//}

//指针数组 还是数组 数组里面存的是指针
//int main() 
//{
//	int arr[10] = { 0 };//整型数组
//	char ch[5] = { 0 };//字符数组
//	int* par[4];//存放整型指针的数组
//	char* pch[5];//存放字符指针的数组
//	return 0;
//}

//指针数组 低级用法
//int main() 
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int* arr[4] = { &a , &b ,&c ,&d };//存放的地址
//	int i = 0;
//	for (i = 0; i < 4; i++) 
//	{
//		printf("%d\n",*(arr[i]));
//	}
//	return 0;
//}


//有点类似二维数组的指针数组
//int main() 
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* p[] = { arr1,arr2,arr3 };//里面存的是上面三个数组的地址
//	int i = 0;
//	for (i = 0; i < 3; i++) //外层3次是三个数组的地址
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)//内层五次 是每个数组的五个元素的地址
//		{
//			printf("%d",*(p[i]+j));//p[i]是第i个数组地址 p[i]+j 是第i个数组向后偏移j个元素
//		}
//		printf("\n");
//	}
//	return 0;
//}

//数组指针 还是指针
//int main() 
//{
//	int* p = NULL;//p是整型指针 -指向整型的指针 可以存放整型的地址
//	char* pc = NULL;//pc是字符指针 -指向字符的指针 可以存放字符的地址
//	//数组指针 - 指向数组的指针 可以存放数组的地址 
//	int arr[10] = { 10 };
//	//arr 首元素地址
//	//&arr[0] 首元素地址
//	//&arr 数组的地址
//	int arr[10] = { 1,2,3,5,6,7,8,9,10 };
//	//int* p[10] = &arr;//[]的优先级高于 * 所以这还是个数组 
//	int(*p)[10] = &arr;//括号改变优先级 指针指向这个数组[10] 定义指针时的*可不是解引用
//	//上面的p就是数组指针
//
//	return 0;
//}

//int main() 
//{
//	char* arr[5];//字符型指针数组 数组！！！
//	char* (*pa)[5] = &arr;//指针pa能指向的数组 这个数组有五个元素 它的每个元素是char*类型
//
//	int arr2[10] = { 0 };
//	int (*pa2)[10] = &arr2;
//
//	return 0;
//}
// 
//快速理解数组指针
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int* p = arr;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));//数组首地址加i 解引用打印
//		printf("%d ", *(arr + i));
//		printf("%d ", arr[i]);//arr[i] = *(arr + i)== p[i] == *(p + i) 
//		printf("%d ", p[i]);//这四种打印全部等价
//
//	}
//	return 0;
//}

//数组指针的用法1(最笨的 属于自讨苦吃)
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*pa)[10] = &arr;
//	int i = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d", (*pa)[i]);;//这里的(*pa)[i]相当于arr[i] 完全一致
//		//pa数组名的地址 *pa拿到整个数组的值 *pa = arr
//	}
//	return 0;
//}

//数组指针的用法2(最笨的 属于自讨苦吃)
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*pa)[10] = &arr;
//	int i = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d", *(*pa+i));//和下面一模一样 *pa+i 是arr[i]的地址 在解引用就等于arr[i]了
//		printf("%d",*(arr+i));
//	}
//	return 0;
//}

//数组指针用二维数组以上才方便
//二维数组常规方式打印
//void print1(int arr[3][5], int x, int y) 
//{
//	int i = 0;
//	int j = 0;
//	for ( i = 0; i < x; i++)
//	{
//		for ( j = 0; j < y; j++)
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}

//参数是指针的形式
//void print2(int (*p)[5],int x,int y) //这里的指针p指向的是大数组 把大数组里面的小数组当成大数组的元素
//{
//	int i = 0;
//	for ( i = 0; i < x; i++)
//	{
//		int j = 0;
//		for ( j = 0; j < y; j++)
//		{
//			printf("%d ", p[i][j]);
//			printf("%d ", *(p[i] + j));//这四种也完全一样
//			printf("%d ", *(*(p + i) + j));  //p+i 是指向第i行的地址 *(p+i) 拿到这一行的数组名 还是地址, 因为解引用后找到的值 就是传过来的数组arr中的元素(小数组)的地址 
//			//再加上j 就是这一行的某个元素的地址 然后整体再解引用 拿到这个元素的值
//			//个人总结:上下俩部分区别 上面实际上是找到这个最小的元素的具体地址 然后打印
//			//下面是找到小数组的地址 根据小数组的地址 输入第几位元素 然后打印 
//			printf("%d ", (*(p + i))[j]);  //(*(p+i))== arr[i] 注意一定要带括号 要不解引用会把j也解掉 ,(*(p + i))[j]) == arr[i][j]
// }
//		printf("\n");
//	}
//}
//int main() 
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };//三行五列的二维数组
//	//print1(arr,3,5);
//	print2(arr, 3, 5);
//	return 0;
//}


//int main()
//{
//	//字符指针
//	char ch = 'w';
//	char* p = &ch;//让指针指向ch的地址
//	const char* p2 = "abcdef";//指针不能存放字符串等等,这里指针指的是字符串首元素a的地址
//	//通过a的地址 可以找到整个字符串 相当于存了字符串的地址 
//	//常量字符串 前面最好加const
//	int(*parr3[10])[5];// 每个元素int(*)[5] 是数组指针
//	return 0;
//}

//一维数组传参 

//void test(int arr[])//没问题
//{}
//void test(int arr[10])//没问题 后面的[]写不写都行 写错也不影响
//{}
//void test(int* arr)//没问题
//{}
//void test(int* arr[20])//没问题 [20]可以省略
//{}
//void test(int* * arr)//没问题 数组名是首元素地址 是一级指针的地址,可以放到二级指针里去
//{}
//int main() 
//{
//	int arr[10] = { 0 };
//	int* arr[20] = { 0 };
//	test(arr);
//	test2(arr);
//	return 0;
//}

//二维数组传参
//对一个二维数组,可以不知道有多少行，但是必须知道一行多少元素。
//void test(int arr[3][5])//标准写法
//{}
//void test(int arr[][5])//省略行正确  ,省略列或行列都省略错误！！！
//{}
//void test()
//{}
//void test(int *arr)//错误 二维数组的数组名表示的是首元素的地址  也就是第一行的地址  
//{}
//void test(int** arr)//错误 一级指针是第一行的地址 是一个数组的地址 放不到二级指针中
//{}
//void test(int(*arr)[5]) //正确 用数组指针接收 该指针指向一个数组 该数组有五个元素
//{}
//int main() 
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//	return 0;
//}

//二级指针传参
//void test(int** ptr) //用二级指针接收没毛病
//{
//	printf("num = %d\n", **ptr);
//}
//int main() 
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//	int* arr[10];//存放一级指针的数组 
//	test(pp);//传过去一个二级指针
//	test(&p);//取一级指针的地址 也相当于传过去一个二级指针
//	test(arr);//所以传存放一级指针的数组名也行
//	return 0;
//}

//函数指针 - 指向函数的指针 存放函数地址的指针
//函数也有地址 函数传地址 类似数组 直接函数名就行 &函数名也行 不带()
//int Add(int x, int y) 
//{
//	int z = 0;
//	return z = x + y;
//
//}
//int main() 
//{
//	int a = 10;
//	int b = 20;
//
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;//数组指针写法
//
//	//int(*pa)(int x, int y) = Add;//上下一样
//    int(*pa)(int, int) = Add;//函数指针写法 函数返回类型 指针(函数指针类型) = 函数名
//	printf("%d\n", (*pa)(2, 3));//调用函数
//	
//	//printf("%d\n", Add(a, b));//调用函数
//	//printf("%p\n",Add);//传递函数地址
//	//printf("%p\n",&Add);//传递函数地址
//	return 0;
//}

//void Print(char* str)
//{
//	printf("%s\n",str);
//}
//int main() 
//{
//	void (*p)(char*) = Print;
//	(*p)("hello bit");
//	return 0;
//}

//《C陷阱和缺陷》
//void (*)() 函数指针类型 
//void (*)()0 将0转换为函数指针类型 此时0是一个函数的地址
//*(void(*)()0) 解引用找到函数
//*(void(*)()0)();本质是调用函数 参数是无参 函数返回类型void


//signal(int,void(*)(int)) signal是一个函数声明 第一个参数是int 第二个参数是函数指针 void(*)(int)
// 该函数指针指向的参数是int，返回类型是void
// signal函数的返回类型也是一个函数指针:该函数指针指向的函数参数是int，返回类型是void
//void(*                              )(int);这都是函数signal返回类型
//void(*signal(int, void(*)(int)))(int);//完整版 本质是一个函数声明

//如何简化? 用typedef
// typedef void(* pfun_t)(int);//给函数指针起别名 pfun_t 的类型就是void(*)(int)
//pfun_t signal(int, pfun_t);//完全简化

//int Add(int x, int y) 
//{
//	int z = 0;
//	return z = x + y;
//
//}
//int main() 
//{
//	int a = 10;
//	int b = 20;
//
//    int(*pa)(int, int) = Add;//函数指针写法 函数返回类型 指针(函数指针类型) = 函数名
//	printf("%d\n", (pa)(2, 3));//调用函数 5  
//	printf("%d\n", (Add)(2, 3));//调用函数 5  函数名也是地址 跟数组名差不多
//	printf("%d\n", (*pa)(2, 3));//调用函数 5 
//	printf("%d\n", (**pa)(2, 3));//调用函数 5 后面的多的*都没用
//
//	//printf("%d\n", *pa(2, 3));//错误: *的优先级低于(),想用必须给*加括号
//
//
//	return 0;
//}

//函数指针数组
//int Add(int x, int y) 
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main() 
//{
//	//指针数组
//	//int* arr[5];
//	//需要一个数组,这个数组可以存放4个函数的地址- 函数指针的数组
//	int(*pa)(int, int) = Add;//Sub/Mul/Div
//	//int(*)(int,int) 函数指针类型
//	int(*parr[4])(int, int) = {Add,Sub,Mul,Div};//函数指针的数组
//	
//	//函数指针用法
//	int i = 0;
//	for (i = 0; i < 4; i++) 
//	{
//		printf("%d\n", parr[i](2, 3));// 5 -1 6 0
//// i 为 0 调第一个函数 1调第二个函数 (2,3)是参数....
//	}
//	return 0;
//}

//char* my_strcpy(char* dest, const char* src);
////1 写一个函数指针pf,能够指向my_strcpy;
////int(*pa)(int, int) = Add;//
//char* (*pf)(char*, const char*) = my_strcpy;
//
//
////2 写一个函数指针数组pfArr,能够存放4个my_strcpy函数的地址
//char* (*pfArr[4])(char*, const char*) = { My_A,My_B,My_C,My_D };

//计算器
//int Add(int x, int y) 
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void menu() 
//{
//	printf("***********************\n");
//	printf("*** 1.add         2.sub**");
//	printf("*** 3.add         4.sub**");
//	printf("***        0.exit      **");
//	printf("*************************");
//
//}

//笨比方法(计算器) 多一个功能多好长的代码
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		
//		switch (input)
//		{
//		case 1:
//			printf("请输入俩个操作数");
//   		scanf("%d%d",&x,&y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("请输入俩个操作数");
//			scanf("%d%d",&x,&y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("请输入俩个操作数");
//  		scanf("%d%d",&x,&y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("请输入俩个操作数");
//  		scanf("%d%d",&x,&y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			break;
//		default:
//			printf("你是废物");
//			break;
//
//		}
//
//	} while (input);
//	return 0;
//}


////计算器笨方法(改进) 用回调函数
//void Calc(int(*pf)(int,int))//用函数指针收到 想调用函数的地址  int是想调用函数的类型
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入俩个操作数");
//	scanf("%d%d",&x,&y); 
//	printf("%d\n",pf(x, y));//函数地址(参数) 调用相对的函数
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		
//		switch (input)
//		{
//		case 1:
//			Calc(Add);//传递要调用函数的地址 这是个回调函数
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			break;
//		default:
//			printf("你是废物");
//			break;
//
//		}
//
//	} while (input);
//	return 0;
//}

//(计算器)函数指针数组优化
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	//pfArr 是一个函数指针数组 也叫 转移表
//	int(*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div};
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//
//			printf("请输入俩个操作数");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);// 1就调用第一个函数(x,y)是参数
//			printf("%d\n", ret);
//		}
//		else if(input ==0)
//		{
//			printf("退出");
//		}
//		else
//		{
//			printf("选择错误");
//		}
//	} while (input);
//	return 0;
//}