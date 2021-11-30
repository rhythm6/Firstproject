#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include "train.h"
//int main() 
//{
//	int a = 10;
//	//int*p = &a;//指针变量
//	//*p = 20;
//	//printf("%d",a);
//	
//	//上下俩部分完全一致 只不过下面 初始化指针被分: 1创建(声明)指针 2给指针赋值 
//
//  int *p;
//  p=&a;
//  *p = 20;
//	printf("%d",a);
//	return 0;
//}


//忘调用库函数了 我说咋一直错误 
//int main() 
//{
//	int a = 0x11223344;
//	int* pa = &a;
//	printf("%d\n",sizeof(char*));
//	printf("%d\n",sizeof(short*));
//	printf("%d\n",sizeof(int*));
//	printf("%d\n",sizeof(double*));//都是4 因为指针大小跟指针类型无关
//	char* pc = &a; 
//	printf("%p\n", pa);
//	printf("%p\n", pc);
//	return 0;
//}


//调试启动 窗口 ->内存 输入&变量值 可查看该变量具体内存
// 然后跟之前一样F10 F11往下走
////https://blog.csdn.net/Young__Fan/article/details/90579437
//int main() 
//{
//	int a = 0x11223344;
//	int* pa = &a;
//	*pa = 0;//把32位的四个字节全部换成00   00 00 00 00
//	//char* pc = &a;
//	//*pc = 0;//把32位的第一个字节变为00   00 ？？ ？？ ？？ 
//	//指针类型决定了指针今夕解引用操作的时候，能够访问空间的大小
//	//例:int *p *p 能够访问4个字节
//	//char *p *p 能够访问1个字节
//	// double *p *p能够访问八个字节
//	return 0;
//}

//指针类型决定了:指针走一步走多远(指针的步长)单位字节
//int* p; p + 1 -- > 4步
//char* p; p + 1-- > 1步
//double* p;p+1 -->8步

//int main()
//{
//	int* arr[10] = { 0 };
//	//int* p = arr;//数组名-首元素的地址 可以改完十个元素 40个字节
//	char* p = arr;//只能改2个半元素 10个字节
//	int i = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		*(p + i) = 1;//指向的第p+i个元素的值 改为1
//	}
//	return 0;
//}

//野指针:
//1 指针未初始化
//int main() 
//{
//	//int a;//局部变量不初始化 默认是随机值
//	int* p;//局部的指针变量 放的是随机值
//	*p = 20;//把随机值给修改为20 非法！！！
//	return 0;
//}
//2 指针越界访问
//int main() 
//{
//	int arr[10] = { 0 };
//	int* p = arr;//调用数组时 本身取的就是数组的首位地址 不需要再使用取地址符
//	int i = 0;
//	for ( i = 0; i < 12; i++)
//	{
//		p++;//当p++能够越过他能管理的范围时(10)就称为指针越界 
//	}
//	return 0;
//}
//3 指针指向的空间释放
//下面程序的解说:主函数开始走 走到内部调用test()函数,test()函数创建a的值,a的地址
//是0x0012ff44 return返回这个地址 然后释放这个地址(因为出这个函数了) p可以接收到0x0012ff44这个地址 但是 此时
//test()里面的地址 早已释放 无法改变 所以这个*p指向一个已经释放的地址 也就是别人的地址 非法!!!
//int* test() 
//{
//	int a = 10;
//	return &a;
//}
//int main() 
//{
//	int* p = test();
//	*p = 20;
//	return 0;
//}

//int main() 
//{
//	int a = 10;
//	int* pa = &a;//指针初始化
//	* pa = 20;
//	pa = NULL;//当你不想要这个指针指向其他地址的时候或者用完不想用的时候
//	//把它变成空指针
//	//#define NULL ((void *)0) NULL实际上是0被强制转换为void类型的0
//	//*pa = 10;//非法 前面的指针已经变为空指针 访问空指针就错误
//		//指针使用之前检查有效性:
//	/*if (pa != NULL) {
//	   
//	}*/
//	return 0;
//
//}

//指针运算
//int main() 
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组个数
//	int* p = arr;//此时p的值是arr首位元素的地址对应的值 
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d",*p);//12345678910
//		p += 1;//注意这里加的是p指针访问的地址加1
//	}
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 9,2,7,4,5,6,3,8,1,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组个数
//	int* p = arr;//此时p的值是arr首位元素的地址对应的值 
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d", *p);//9 7 5 3 1
//		p+=2;//每次循环访问的是地址加2的元素 
//	}
//	return 0;
//}
//int main() 
//{
//	int a = 10;
//	int* pa = &a;
//	pa = 20;
//	printf("%d\n%p", a,pa); //10  00000014(16进制 ，还是20)  光给pa赋值不会改变a的值
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 20;
//	printf("%d\n%p\n", a, pa);//20 随机16进制数 会通过指向a的地址 改变a的值 然后指针失效 指向任意值
//	*pa = 30;
//	printf("%d\n%p\n", a, pa);// 30 随机16进制数 会通过指向a的地址 改变a的值 然后指针失效 指向任意值
//	return 0;
//}

//int main() {
//#define N_VALUES 5
//	float values[N_VALUES];//创建数组分配5个空间
//	float* vp;//定义单精度浮点型指针 创建指针
//	for (vp = &values[0]; vp < &values[N_VALUES];)//给指针赋值 至此指针初始化完毕 不再是野指针了
//	{
//		printf("%p\n", vp);//vp每循环一次 指针走4步 地址加4 直到等于value[N_VALUES]的地址停止
//	    /*
//		012FF744
//		012FF748
//		012FF74C
//		012FF750
//		012FF754
//		*/
//		*vp ++= 0;
//	}
//	return 0;
//}

//int main() 
//{
//	char ch[5] = { 0 };
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d", &arr[9] - &arr[0]);// 9 地址减去地址 得到的数是数组长度 9-0=9 第十位数减第一位数的地址
//	//不同数组的地址不同相减
//	// printf("%d", &arr[9] - &ch[0]);// warning C4133: “-”: 从“char *”到“int *”的类型不兼容
//}




//strlen -求字符串长度
//	//这次用指针模拟实现strlen 
//int my_strlen(char* str) 
//{
//	char* start = str;//数组首位地址
//	char* end = str;
//	printf("%p\n", str);
//	while (*end != '\0')
//	{
//		end++;//"bit" 实际上是"bit\0" 一直增加到读到\0停止 就是数组末位地址
//	}
//	return end - start;
//}
//int main() 
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("%d\n",len);
// return 0;
//}

//#define N_VALUES 5
//int main()
//{
//
//	float values[N_VALUES];
//	float* vp;
//	for (vp = &values[N_VALUES]; vp > &values[0];)//标准写法
//	{
//		* --vp = 0;//从数组的最后一个元素开始把数据全部替换为0
//	}
//	//这俩种写法在绝大多数的编译器都可以运行 但第一个符合C语言标准
//	//允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较,
//	//但不允许与第一个元素之前的内存位置的指针进行比较。
//	//意思是可以向后越界，对数组最后面的元素再加1的内存位置比较 
//	//不可以向前越界，对数组最前面的元素再-1d的内存位置比较
//	for (vp = &values[N_VALUES]; vp >= &values[0];vp--)//不规范写法 vp>= 把等于去掉就标准了
//	{
//		*vp = 0;//从数组的最后一个元素开始把数据全部替换为0
//	}
//	return 0;
//}

//int main() 
//{
//	int arr[10] = { 0 };
//	printf("%p\n",arr);
//	printf("%p\n",&arr[0]);
//	printf("%p\n", &arr);
//		/*
//		0057FE68
//		0057FE68 虽然上面结果都一样 但&arr取得确实是整个数组的地址
//		0057FE68 因为整个数组的地址开头也是 数组的首位元素的地址
//		*/
//	printf("%p\n", arr + 1);//增加4个字节
//	printf("%p\n", &arr[0]+1);//增加4个字节
//	printf("%p\n", &arr+1);//增加 4*10个字节
//	//数组名在绝大多数时都是首元素的地址 有俩个例外
//	//1 &arr时 此时数组名表示整个数组 取出整个数组的地址
//	printf("%p\n",&arr[0]);
//	//2 size(arr) 数组名表示整个数组 计算的整个数组的大小 单位是字节
//}


//int main() 
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;//把arr[10] 变成{1,2,3,4,5,6,7,8,9}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", arr[i]);//可以用数组的方式打印
//		printf("%d\n", *(p + i));//也可以用指针的方式打印
//	}
//	//for ( i = 0; i < 10; i++)
//	//{
//	//	printf("%p ======%p\n", p + i, &arr[i]);//p+i 的地址等于&arr[i]一致
//	//}
//	return 0; 
//}
 
 
//二级指针 多级指针 
//最右边的*的意思是这是一个指针变量 左边的n个*表示这个指针指向的对象的类型是int n个* 
//int main() 
//{
//	int a = 10;
//	int* pa = &a;
//	int* * ppa = &pa;//二级指针 ppa指向的对象是int*类型
//	**ppa = 20;
//	printf("%d\n%d",a,**ppa);//20 20
//	int* ** pppa = &ppa;//三级指针 以此类推
//	return 0;
//}
//指针数组 还是数组 数组里面的元素是指针
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* pa = &a;
//	int* pb = &b;
//	int* pc = &c;
//	int* arr[3] = { &a,&b,&c };//指针数组
//	int i = 0;
//	for ( i = 0; i < 3; i++)
//	{
//		printf("%d\n", *(arr[i]));//10 20 30 遍历数组通过数组里面的指针找到各自对应的值然后打印
//	}
//	return 0;
//}

//int main()
//{
//	char acX[] = "abcdefg";
//	char axY[] = { 'a','b','c','d', 'e', 'f', 'g' };
//	printf("%d\n", sizeof(acX));//8 因为字符串是以\0结尾 所以多算一位 
//	printf("%d\n", sizeof(axY));//7 数组acX的长度>数组axY的长度
//	return 0;
//}

//交换俩个数组的值
//int main() 
//{
//	int arr1[] = {1,3,5,7,9};
//	int arr2[] = { 2,4,6,8,0 };
//	int tmp = 0;
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);//整个数组的字节大小/某个元素字节大小 = 元素个数
//	for ( i = 0; i <sz ; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//		printf("%d\n", arr2[i]);
//	}
// 	return 0;
//}

//int main() 
//{
//	int arr[] = {1,2,3,4,5};
//	short* p = (short*)arr;//指向arr数组的首元素的地址(为什么不用取地址符呢 因为调用数组名 直接就得到数组首位元素的地址不需要&)
//    //当然再加上&也不会错，并把类型强制转换为short*类型 若不转 报个警告 正常运行 ，若转为short型相当于给一个地址转成short当然错误！！
//	//short 是俩个字节
//	int i = 0;
//	for (i = 0; i < 4; i++) 
//	{
//		*(p + i) = 0;//循环四次 改变4*2个字节 = 8 数组是整型 改变前2个元素为0
//	}
//	for ( i = 0; i < 5; i++)
//	{
//		printf("%d\n",arr[i]);// 0 0 3 4 5
//	}
// 	return 0;
//}

//int main() 
//{
//	//1个字节是8位，二进制8位：xxxxxxxx 范围从00000000－11111111，表示0到255。
//	//一位16进制数（用二进制表示是xxxx）最多只表示到15（即对应16进制的F），要表示到255,就还需要第二位。
//	//所以1个字节＝2个16进制字符，一个16进制位＝0.5个字节。
//
//	int a = 0x11223344;//一个16进制位＝0.5个字节
//	//a在内存中是倒着放的 俩个16进制位等于一个字节 44 33 22 11
//	//一个字节 八位二进制数组成
//	char* pc = (char*)&a;
//	*pc = 0;//倒着改一个字节00 33 22 11
//	printf("%x\n",a);//然后在反着打印 %x以16进制位输出
//	return 0;
//}

//int i;//不放在函数(包括主函数)内的变量才是全局变量  默认是0
//int main() 
//{
//	i--;//-1
//	//-1
//	//10000000000000000000000000000001 原码
//	//11111111111111111111111111111110 反码
//	//11111111111111111111111111111111 补码
//	//01111111111111111111111111111111 将符号位转变为有效位 可以当做正数看待 并不是真的转成0开头了 所以这个数巨大肯定比0大的多
//	if (i > sizeof(i))
//	{
//		printf(">\n");//打印这个 原因sizeof()计算变量/类型 所占内存的大小 大小永远>=0 无符号数>=0
//	}
//	//当一个整数和一个无符号数进行运算的时候 会把这个整数也变成无符号数 0是最大的无符号数
//	else 
//	{
//		printf("<");;
//	}
//	return 0;
//}

//十进制转二进制(纯自己想)
//int main() 
//{
//	int a = 0;//此处不能直接定义a为无符号型 因为scanf_s你输入的时候是有符号的 判断的时候又要是无符号的 计算机就蒙了
//	printf("十进制转二进制");
//	printf("请输入十进制数");
//	scanf_s("%d", &a);
//	int b = 0;
//	int arr[32] = {0};//定义一个数组 用来存储计算的b的值
//	int i = 0;
//	int count = 0;
//
//	if (a >= 0) 
//	{
//		while (b = a)//计算a每次模2的余数
//		{
//			b = a % 2;
//			a = a / 2;
//			arr[i] = b;
//			i++;
//			//printf("%d ",a);
//			//printf("%d\n", b);
//		}
//		int count = i;
//		while (count != 0)//将数组反着打印
//		{
//			--count;
//			printf("%d", arr[count]);
//		}
//		printf("该数是个正数，符号位是0");
//	}
//	else
//	{
//			a = abs(a);//abs() 绝对值函数 将负数变为正数
//			while (b = a)//计算a每次模2的余数
//			{
//				b = a % 2;
//				a = a / 2;
//				arr[i] = b;
//				i++;
//				//printf("%d ",a);
//				//printf("%d\n", b);
//			}
//			int count = i;
//			while (count != 0)//将数组反着打印
//			{
//				--count;
//				printf("%d", arr[count]);			
////printf("-%d", printf("%d", arr[i]));这样写的结果不是把里面的printf的打印结果加个-, 而是里面先打印 外面在打印里面的-printf。
//			}
//			printf("该数是个负数 符号位是1");
//	}
//	system("pause");//pause(暂停)保证可执行程序exe 按回车后不会立马闪退
//	return 0;
//}

//求a的二进制(补码)表示中有几个1
// 算法1
//int count_bit_one(unsigned int n)//把输入的值转换成 无符号值进行判断 就可以判断负数
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1) 
//		{
//			count++;
//		}
//		n = n / 2;
//	}
//	return count;
//}

//算法2
//int count_bit_one(unsigned int n) 
//{
//	int count = 0;
//	int i = 0;
//	for ( i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)//先右移一位 然后与1比较,由于1的二进制位前面全是0最后一个是1 所以每右移一次 最后一位二进制比较一次 俩个都为1才为1 count++
//		{
//			count++;
//		}
//	}
//	return count;
//}

//算法最优版
// n = n&(n-1)

// n = 13 1101
// &
// n-1 1100
// n 1100 最右边一消失了 每进行一次n=n&(n-1) 消失一个1
// ---
// 0000 n//直到n=0

//int count_bit_one(unsigned int n)
//{
//	int count = 0;
//	while (n) //n=0自动停止
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//int main() 
//{
//	int a = 0;
//	scanf_s("%d",&a);
//	int count = count_bit_one(a);
//	printf("count = %d\n",count);
//	return 0;
//}

//求二进制中不同位的个数
//int get_diff_bit(int m, int n) 
//{
//	int count = 0;
//	int tmp = m ^ n;//^ 按二进制位异或 相同为0 相异为1 得到的tmp中的1 就是这俩个数不同位的个数
//	while (tmp)
//	{ 
//		tmp = tmp & (tmp - 1);//用上面的算法统计1的个数
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf_s("%d%d", &m, &n);
//	int count = get_diff_bit(m, n);
//	printf("count = %d\n",count);
//	return 0;
//}

//获取一个整数二进制序列所有的奇数和偶数项，分别打印
// void print(int m)
// {
//	 int i = 0;
//	 printf("奇数位:\n");
//	 for (i = 30; i >= 0; i -= 2)
//	 {
//		 printf(" %d",(m>>i)&1);//把所有的奇数位右移到最后一位让后打印
//	 }
//	 printf("\n");
//	 printf("偶数位:\n");
//	 for (i = 31; i >= 1; i -= 2)
//	 {
//		 printf(" %d", (m >> i) & 1);//把所有的偶数位右移到最后一位然后打印 
//	 }
// }
//int main() 
//{
//	int m = 0;
//	scanf_s  ("%d",&m);
//	print(m);
//	return 0;
//}

//用指针打印数组内容
//void print(int* p, int sz)//接收的是首地址
//{
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d", *(p + i));//打印(首地址+i)的地址所对应的元素值
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//}


///n+1传递给下个fun 判断 在+1再判断 直到 n==5 向上返回n=2 递归几次乘几个2
//int Fun(int n)
//{
//	if (n == 5)
//		return 2;
//	else
//		return 2 * Fun(n + 1);
//}
//int main() 
//{
//	int count = 0;
//	int n = 2;
//	printf("%d", count = Fun(n));
//	return 0;
//}

//乘法口诀表 行数和列数可以自定义
//void print_table(int n) 
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//			for (j = 0; j <= i; j++)
//			{
//				printf("%d*%d = %-3d ", i, j, i*j);//-3是改缩进 对齐代码
//					
//			}
//			printf("\n");
//	}
//}
//int main() 
//{
//	int n = 0;
//	scanf_s("%d",&n);
//	print_table(n);
//	return 0;;
//}


//void reverse_string(char arr[])//这里取的是arr数组的值 因为带[]了 用char arr*也可以
//{
//	int left = 0;
//	//int right = strlen(arr)-1;//使用库函数
//	int right = my_strlen(arr) - 1;//使用自定义函数
//	while (left < right)// 最左边和最右边开始互换 然后最左和最右各减一再互换
//		//4 3 2 1 -> 1 32 4 ->12 34
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}

//递归的方法实现
//总体流程 tmp先存储第一个数  将第一个数换成最后一个数 计算数组长度为mystr_len=6 然后将最后一个数换成\0  递归arr+1 
//此时从第二位数开始 tmp先存储这第二个数  将第二个数换成倒数第二个数 计算数组长度mystr_len = 4(前面从第二个数算 后面的\0不算那就是6-1-1个数) 
//然后倒数第二个数换成\0  再次递归arr+1+1
//此时从第三位数开始 tmp先存储第三个数 将第三位换成倒数第三位 此时数组mystr_len = 2  将倒数第三个数换成\0 但注意此时mystrlen(arr+1) 因为这一次递归传的值是
// arr+1+1 所以mystrlen(arr+1)实际上是mystrlen(arr+1+1+1) 计算结果从第四位开始计算 整个数组长度为0 不符合递归条件 开始执行最后一句代码 逐次返回给最后第4位
// 第五位 第六位 数 至此字符串反向排列完毕
//执行步骤 a b c d e f \0 -> f b c d e \0 
// -> b c d e \0 \0 ->  e c d  \ 0 \0 - > c d \0 \0 \0
 //-> d \0 \0 \0 \0  ->d c \0 \0 \0 -> e d c b \0 \0 -> f e d c b  \0 \0 -> f e d c b a  \0

//将字符串反向排列
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')//遍历数组的字符串 判断字符串长度
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//void reverse_string(char* arr) 
//{
//	char tmp = arr[0];//创建变量保存第一个数
//	int len = my_strlen(arr);//得到数组长度
//	arr[0] = arr[len - 1];//第一个数换成最后一个数
//	arr[len - 1] = '\0';//把最后一个数先换成\0
//	if (my_strlen(arr + 1) >= 1)
//	{
//		reverse_string(arr + 1);//递归传的值是第二个数,第三个数..
//		printf("第次递归");//进来俩次
//	}
//	arr[len - 1] = tmp;//最后一个数换成最开始保存的tmp也就是第一个数 这一步当递归结束之后开始执行
//
//}
//int main() 
//{
//	char arr[] = "abcdef";// abcdef \0
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}