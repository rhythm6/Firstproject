#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<malloc.h>
#include<errno.h>
//C语言是可以创建变长数组 -C99标准 但是不是每款编译器都支持 就像vs的早期版本就不支持
//gcc编译器可以运行
//int main() 
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n];//vs编译器不支持这样写 错误:表达式中必须含有常量
//	int i = 0;
//	for (i = 0; i < n; i++) 
//	{
//		arr[i] = 1;
//	}
//	for (i = 0; i < n; i++) 
//	{
//		printf("%d",arr[i]);
//	}
//	return 0;
//}

//动态内存分配 在堆上申请空间
////INT_MAX 整型最大值
////malloc(动态内存开辟函数) 开辟一块连续可用的空间
////开辟成功返回一个指向开辟好空间的指针，开辟失败返回一个NULL指针
//int main() 
//{
//	//向内存申请10个整形的空间 p放的就是这块空间的地址
//	int* p = (int*)malloc(10 * sizeof(int));//malloc返回是void*型 要强转一下 开辟十个整型大小
//	if (p == NULL) 
//	{
//		//打印错误
//		printf("%s\n",strerror(errno));//失败会把错误信息放到错误码里
//		//再用strerror函数把错误码所对应的错误信息打印出来
//	}
//	else 
//	{
//		//正常使用空间
//		int i = 0;
//		for ( i = 0; i < 10; i++)
//		{
//			*(p + i) = i;//下标为i的元素赋值给i
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ",*(p+i));
//		}
//	}
//	//当动态申请的空间不再使用的时候
//	//就应该还给操作系统
//	free(p);//程序运行过程中释放空间 但是释放完成后p指针还是能找到这块空间
//	p = NULL;//所以把p指针指为空
//	return 0;
//	//程序结束自动释放空间还给操作系统 
//}


//malloc 不会初始化空间 所以malloc的效率更高 那块空间的值都是cd(随机值) 
//calloc 会把空间初始化为0
//int main() 
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n",strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++) 
//		{
//			printf("%d ",*(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//realloc函数 调整动态开辟内存空间的大小
//1 如果p指向的空间之后有足够的内存空间可以追加，则直接追加后,返回p的地址
//2 如果p指向的空间之后没有足够的内存空间可以追加,则realloc函数会重新找一个新的内存区域
// 开辟一块满足需求的空间,并且把原来内存中的数据拷贝回来，释放旧的内存空间
// 最后返回开辟的内存空间地址
//3 得用一个新的指针变量来接收realloc函数的返回值 
//int main() 
//{
//	int* p = (int*)malloc(20);//开辟20个字节
//	if (p == NULL)
//	{
//		printf("%s\n",strerror(errno));
//	}
//	else 
//	{
//		int i = 0;
//		for (int i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	int* ptr = realloc(p, 40);//参数是调控空间地址 调整大小为:40个字节
//	if (ptr != NULL)//内存调整失败就会返回空指针 所以一定要判断一下
//	{
//		p = ptr;//若内存空间调整成功 再把地址给原指针p
//
//		int i = 0;
//		for (int i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (int i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + 1));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//realloc 也可以直接开辟空间
//int main()
//{
//	int* p = ralloc(NULL, 40);//跟malloc一样的
//	return 0;
//}

//常见的动态内存错误 
//1.对NULL指针解引用操作
// int main() 
//{
//	int* p = malloc(40);
//	*p = 10;//malloc开辟空间失败- 对NULL指针解引用
//	return 0;
//}
 

//2.对动态开辟的内存的越界访问
//int main() 
//{
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (p == NULL) 
//	{
//		return 0;
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)//只开辟了5个空间 越界访问十个空间
//		{
//			*(p + i) = i;
//		}
//	}
//	free(p);
//	p = NULL;//程序崩溃了
//}

//3.对非动态开辟内存使用free释放
//int main() 
//{
//	int a = 10;//a是栈开辟空间的
//	int* p = &a;
//	free(p);//释放动态内存是堆上的 这里释放栈的静态空间 错误
//	p = NULL;
//	return 0;
//}

//4.使用free释放动态开辟内存的一部分
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL) 
//	{
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++) 
//	{
//		*p++ = i;
//	}
//	free(p);//p指向的位置 已经改变了， 现在释放p改变后的内存 错误
//	//必须释放申请空间的地址 
//	p = NULL;
//	return 0; 
//
//}

//5.对同一块动态内存的多次释放
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL) 
//	{
//		return 0;
//	}
//	free(p);//p指向的位置 已经改变了， 现在释放p改变后的内存 错误
//	//必须释放申请空间的地址 
//	p = NULL;
//  free(p);//若前面没有p=NULL;这样写就直接崩溃 free不对NULL做操作
//	return 0; 
//
//}

//6.动态开辟内存 忘记释放导致(内存泄漏)
//切记动态开辟的空间一定要释放 尤其是大型项目 这是非常严重的bug
//会导致电脑卡死
//#include<windows.h>
//int main()
//{
//while (1) 
//{
//	malloc(1);
//	//电脑内存飙升 可以看看任务管理器
//}
//	return 0; 
//}

//笔试题 下面程序的运行结果是什么 结果:程序崩溃
//void GetMemory(char* p)//接收一个空指针
//{
//	p = (char*)malloc(100);//用p的值 接收开辟的空间
//	//接收开辟的空间后 离开函数 p失效 再也找不到这块开辟的空间
//	//未释放空间 内存泄漏
//
//}
//void Test(void) 
//{
//	char* str = NULL;//str 指向空指针
//	GetMemory(str);//传进去一个空指针 函数调用完成时str并没有被改变 
//	strcpy(str, "hello world");//把hello world拷贝到str中 str是空指针
//	//没有指向有效空间 strcpy函数一直找空间 就算找到了也是非法访问空间 程序崩溃
//	printf(str);//这种写法没有毛病 直接放地址也可以打印
//}
//int main() 
//{
//	Test();
//	return 0;
//}

//改正方式一
//void GetMemory(char ** p)//用二级指针接收一级指针的地址
//{
//	*p = (char*)malloc(100);//p指针 接收开辟的空间
//
//}
//void Test(void)
//{
//	char* str = NULL;//str 指向空指针
//	GetMemory(&str);//传进去一个一级指针的地址 
//	strcpy(str, "hello world");
//	printf(str);//这种写法没有毛病 直接放地址也可以打印
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//改正方式二
//char* GetMemory(char* p)//接收一个空指针 返回一个char*的地址
//{
//	p = (char*)malloc(100);
//	return p;//主动返回p的值
//}
//void Test(void)
//{
//	char* str = NULL;//str 指向空指针
//	str = GetMemory(str);//传进去一个空指针 返回的p用一个值接收 
//	strcpy(str, "hello world");//把hello world拷贝到str中 str是空指针
//	printf(str);//这种写法没有毛病 直接放地址也可以打印
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//下面代码的执行结果是什么
//char* GetMemory(void)//接收一个空指针 返回一个char*的地址
//{
//	char p[] = "hello world";
//	return p;//主动返回p的值
//}
//void Test(void)
//{
//	char* str = NULL;//str 指向空指针
//	str = GetMemory();//返回p的地址 但由于作用域的原因p的值已经被释放了
//	printf(str);//所以接收的指针指向随机值(非法访问)
//}
//int main()
//{
//	Test();
//	return 0;
//}

//int* test(void)
//{
//	int a = 10;//栈区 在前面加个static就行了 改变它的作用域 放到静态区
//	return &a;
//}
//int main() 
//{
//	int* p = test();//a的值在函数执行后已经被销毁了 指针指向随机值 非法访问
//	*p = 20;
//	return 0;
//}

//int* test() 
//{
//	int* ptr = malloc(100);//堆区 不会主动销毁该空间
//	return ptr;
//}
//int main() 
//{
//	int* p = test();//p可以正确指向这块开辟在堆空间上的空间
//	return 0;
//}

//高质量 C++/C 编程 这本书不错
//void GetMemory(char** p, int num) 
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);//可以打印出来 但没有释放空间 导致内存泄漏
//	//改
//	free(str);
//	str = NULL;
//}
//int main() 
//{
//	Test();
//	return 0;
//}

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL);
//	{
//		strcpy(str, "world");//把释放的空间给强行覆盖掉 非法访问内存
//		//考点是free函数释放空间 不会把指向该空间的指针置为空 
//		printf(str);
//	}
//}
//int main() 
//{
//	Test();
//	return 0;
//}

// C/C++程序的内存开辟
//栈区(向下增长) 存放局部变量 执行完自动释放
//堆区(向上增长) malloc calloc realloc 开辟的空间都在堆上 程序结束时可能由操作系统回收
//数据段(静态区) 存放全局变量，静态(static)数据 程序结束后由系统释放
//代码段 代码段的数据是不能改的 存放执行代码 只读常量(常量字符串一类的 不可被修改)

//柔性数组 写法
//柔性数组特点
//结构中的柔性数组成员前面必须至少有一个其他成员
//sizeof返回的这种结构大小不包括柔性数组的内存
//包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应大于结构体的大小
//以适应柔性数组的预期大小。
//C99标准中 结构体中的最后一个元素允许时未知大小的数组，这就叫做柔性数组成员。
//struct S 
//{
//	int n;
//	int arr[];//未知大小的-数组的大小是可以调整的
//	//int arr[0]这样写也行
//};
//int main() 
//{
//	//struct S s;
//	//printf("%d\n",sizeof(s));//4 计算结构体成员大小时 不包含柔性数组
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 *sizeof(int));//5*sizeof(int)定义柔性数组的大小为5个整型
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++) 
//	{
//		ps->arr[i] = i;//0 1 2 3 4
//	}
//	struct S* ptr = realloc(ps, 44);//扩容 前4个字节是n的大小 后面的都是柔性数组的的大小
//	if (ptr != NULL) 
//	{
//		ps = ptr;
//	}
//	for (i = 5; i < 10; i++) 
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++) 
//	{
//		printf("%d",ps->arr[i]);
//	}
//	//释放空间
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//第二种写法 是常规写法 要开辟俩次空间 释放俩次空间 写起来容易出错 
//struct S 
//{
//	int n;
//	int* arr;
//};
//int main() 
//{
//	struct S* ps = malloc(sizeof(struct S));//开辟一个结构体大小的空间 里面包含n和arr
//	ps->arr = malloc(5 * sizeof(int));//对上面开辟中间里面的arr指针再开辟一块 arr指向这块空间
//	int i = 0;
//	for (i = 0; i < 5; i++) 
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 5; i++) 
//	{
//		printf("%d\n",ps->arr[i]);
//	}
//	//调整大小
//	int *ptr = realloc(ps->arr, 10 * sizeof(int));
//	if (ptr != NULL) 
//	{
//		ps->arr = ptr;
//	}
//	for (i = 5; i < 10; i++) 
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++) 
//	{
//		printf("%d ",ps->arr[i]);
//	}
//	//释放必须先释放arr的空间 若先释放结构体的空间(arr销毁) 就找不到arr这个指针对饮的空间了
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//malloc开辟空间 是哪里有就在哪里开 没有什么规律 而开辟空间会留下难以使用小空间(内存碎片)
//所以开辟次数越少越好 可以提高内存的使用率 而且内存大概率都是连续读取数据
//内存的数据放到高速缓存 高速缓存在放到寄存器 cpu在从寄存器中那数据
//局部性原理:当访问某个内存数据时，后面访问其他数据大概率会访问这个数据附近的内存 
//例子:如果数据1和数据2连着放 就容易读取数据1时随带读取了数据2 叫CPU命中率高
//也就是说空间连续性高 读取速度快

//文件操作(数据文件)
//程序文件：源程序文件.c (在windows环境下) 目标文件.obj 可执行程序.exe 程序文件可以操作数据文件
//数据文件：程序运行时读写的数据 
//文件名:文件路径+文件名主干+文件后缀
//文件类型:文本文件(你能看懂的文件,放的都是字符 )或二进制文件(打开都是乱码) 数据在内存中以二进制的形式存储，如果不加转换输出1到外存，就是二进制文件
//以ASCII字符的形式存储的文件就是文本文件
//一个数据在内存中是怎么存储的?
//字符一律以ASCII形式存储，数值型数据既可以用ASCII形式也可以用二进制形式存储。
//例如:10000 以ASCII存储 就是 一个字符一个字节 1 0 0 0 0 
//以二进制就是4个字节 10 27 00 00(16进制显示) 实际存放顺序00 00 27 10

//int main() 
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");//以二进制写的方式打开该文件 没有该文件就自动创建
//	fwrite(&a, 4, 1, pf);//写a的内容进去（数据源） 写几个字节 写几个数据 存放位置
//	fclose(pf);
//	pf = NULL;
//	return 0;
//
//}
/*
缓冲文件系统:
程序数据区->输出缓冲区->输出->磁盘 (输出缓冲区放满了才放出数据)
磁盘->输入->输入缓冲区->程序数据区
文件类型指针，简称文件指针:每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放
文件的相关信息(例如文件的名字,文件当前的位置)这些信息是保存在一个结构体变量中的。该
结构体类型是有系统声明的，取名FILE(右键转到定义)
*/

//文件的打开和关闭  r 只读 w只写 a 追加 rb 二进制只读 wb 二进制只写 
// 带有写的文件使用方式 会在没有文件时自动创建该文件
//打开fopen函数

//int main() 
//{
//	//..表示上一级路径 下一级表示当前路径
//	//打开文件test.txt
//	//fopen("../../","r");//相对路径
//	//fopen("D:\\2019 v\\Project\\Firstproject\\test.txt", "wb");//绝对路径 \转义\确保第二个\不会转义其他字符
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL) 
//	{
//		printf("%s\n" ,strerror(errno));
//	}
//	//打开成功
//	//读文件
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main() 
//{
//	FILE* pfRead = fopen("TEST.txt","w");//打开文件
//	if (pfRead == NULL) 
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	//读文件
//	printf("%c", fgetc(pfRead));
//	//关闭文件
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}

//流文件
//键盘 - 标准输入设备(stdin FILE*)
//屏幕 - 标准输出设备(stdout FILE*)
//文件               (stderr FLIE*)
//程序默认打开三个流设备
//int main() 
//{
//	int ch = fgetc(stdin);
//	fputc(ch, stdout);//一次只能一个字符字符的打印到屏幕上(打印结果是这样的)
//	return 0;
//}

//fgetc函数 和fputc函数
//int main() 
//{
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	//写文件 把上面FILE哪一行的r改为w 
//	//fputc('b',pf);
//	//fputc('i',pf);
//	//fputc('t',pf); 
//	//读文件
//	int ch = fgetc(pf);
//	printf("%c",ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fgets函数 和puts函数
//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
////读文件
//	fgets(buf, 1024, pf);//读完放到buf中 读1024个字节 读取pf指向的文件
//	//这个函数一次读一行
//	//printf("%s",buf);
//	puts(buf);//这个函数天生自带\n  是个输出函数
//
//	fgets(buf, 1024, pf);
//	//printf("%s", buf);
//	puts(buf);
//
//	fgets(buf, 1024, pf);
//	//printf("%s", buf);
//	puts(buf);
//
//	//printf("%s", buf);
////关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fput函数
//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt","w");
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	//写文件
//	fputs("hello\n",pf);
//	fputs("world\n",pf);
////关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fgets函数
//int main() 
//{
//	//从键盘读取一行文本信息
//	char buf[1024] = { 0 };
//	//fgets(buf, 1024, stdin);//从标准输入流读取 输入什么
//	//fputs(buf, stdout);//输出到标准输出流 这里打印什么
//	gets(buf);//上面俩行等同于这俩行
//	puts(buf);
//	return 0;
//}

//struct s
//{
//	int n;
//	float score;
//	char arr[10];
//};      
//int main()
//{
//	struct s s = { 100,3.14f,"bit" };
//	FILE* pf = fopen("test.txt","w");//注意:写还是读 用双引号扩起来
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	//格式化的形式写文件 放到pf里面
//	fprintf(pf,"%d %f %s",s.n, s.score, s.arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct s
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct s s = { 100,3.14f,"bit" };
//	FILE* pf = fopen("test.txt", "r");//注意:写还是读 用双引号扩起来
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//格式化的输入数据 放到pf里面
//	//fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
//	//printf("%d %f %s\n", s.n, s.score, s.arr);
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);//等同于上面俩行
//	fprintf(stdout, "%d %f %s", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

/*
scanf / printf 是针对标准输入流 / 标准输出流的 格式化输入 / 输出语句
fscanf / fprintf 是针对所有输入流/所有输出流的 格式化输入/输出语句
sscanf / sprintf
sscanf 是从字符串中读取格式化的数据 
sprintf 是把格式化数据输出成(存储到)字符串
*/

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main() 
//{
//	struct S s = { 100, 3.14f, "abcdef" };
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//	//把格式化的数据转换成字符串存储到buf
//	sprintf(buf,"%d %f %s",s.n,s.score,s.arr);
//	//printf("%s\n", buf);
//	
//	//从buf中读取格式化的数据到tmp中
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
//	printf("%d %f %s \n",tmp.n,tmp.score,tmp.arr);
//	return 0;
//}

//二进制读写文件
//struct S 
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main() 
//{
//	//struct S s = { "张三",20,55.6};//写文件的结构图
//	struct S tmp = { 0};//读文件的结构体
//	//FILE* pf = fopen("test.txt","wb");//写文件的
//	FILE* pf = fopen("test.txt", "rb");//读文件的
//	if (pf == NULL) 
//	{
//		return 0;
//	}
//	//二进制的形式写文件
//	//fwrite(&s, sizeof(struct S), 1, pf);//写谁  元素大小 写几个 写到那里去
//	
//	//二进制读文件
//	fread(&tmp, sizeof(struct S), 1, pf);
//	printf("%s %d %lf\n", tmp.name, tmp.age,tmp.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//文件的顺序读写
//int main() 
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL) 
//	{
//		return 0;
//	}
//	//1。定位文件指针
//	fseek(pf, 2, SEEK_CUR);//从pf 当前位置(current 当前的)开始读 向后偏移俩位
//	//SEEK_END 文件最后位置 SEEK_CUR 文件指针的当前位置 SEEK_SET 文件起始位置
//	//若是-2就向前读俩位
//	//2.读取文件
//	int ch = fgetc(pf);
//	printf("%c",ch);
//	fclose(pf);
//	pf = NULL;
//}

//ftell函数 计算偏移量 rewind函数 把文件指针位置放回起始位置
//int main() 
//{
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL) 
//	{
//		return 0;
//	}
//	//定位文件指针	`
//	fseek(pf, -2, SEEK_END);
//	int pos = ftell(pf);//ftell 计算文件指针 相对于起始位置的偏移量
//	printf("%d\n",pos); 
//
//	pos = fgetc(pf);//读字符
//	printf("%c\n",pos);
//	 
//	rewind(pf);//回到文件指针的起始位置
//	pos = ftell(pf);
//	printf("%d\n",pos);
//	
//	pos = fgetc(pf);//读字符
//	printf("%c\n",pos);
//	
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//文件结束判定
//feof函数 是用来判断文件读取结束的原因
//原因1:读取失败 原因2:文件读完了
/*
1.文本文件读取是否结束，
判断返回值是否为EOF(fgetc)
或者NULL(fges) fges

2二进制文件的读取结束判断，判断返回值是否小于实际要读的个数
*/

//int main() 
//{
//	//EOF: END OF FILE 文件结束的标志
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL)
//		return 0;
//	int ch = fgetc(pf);//当文件为空时会返回EOF 而EOF这个函数会返回-1
//	printf("%d\n",ch);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//perror 函数与strerror函数的区别
//int main() 
//{
//	//strerror - 把错误码对饮的错误信息的字符串地址返回
//	//printf("%s\n",strerror(errno));
//	FILE* pf = fopen("test2.txt","r");
//	if (pf == NULL) 
//	{ 
//		perror("fopen函数错误");
//		return 0;
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main() 
//{
//	FILE* pf = fopen("test2.txt","r");
//	if (pf == NULL) 
//	{ 
//		perror("fopen函数错误");
//		return 0;
//	}
//	//读文件
//	int ch = 0;
//	while ((ch = fgetc(pf) != EOF))//判断是否为空
//	{
//		putchar(ch);
//	}
//	//结束原因
//	if (ferror(pf)) //遇到错误返回一个非0值 条件为真
//	{
//		printf("error\n");
//	}
//	else if (feof(pf))//判断文件是否结束
//	{
//		printf("end of file\n");
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//练习题
//typedef struct 
//{
//	int a;// a占4个字节 偏移量0-3 4小于8 对齐数是4    0开始,占4个字节
//	char b;//b占一个字节 偏移量4  1小于8 对齐数是1 偏移量3是1的倍数 占1个字节
//	short c;//c占俩个字节  偏移量5-6 2小于8 对齐数是2
//	// 由于5不是2的倍数 所以浪费一个字节 从6开始 偏移量5-7 占3个字节
//	short d;//d占俩个字节 偏移量8-9 2小于8 对齐数是2 偏移量8是2的倍数 占2个字节
//	//总共占10个字节 
//	//4个对齐数 最大是4 结构体大小必须是最大对齐数的倍数 3*4 = 12
//	//所以最终结果为12
//}AA_T;
//int main() 
//{
//	printf("%d\n",sizeof(AA_T));
//	return 0;
//}

//4字节对齐 16+12 = 28
//typedef struct A 
//{
//	int a;//0-3 4
//	short b;//4-5 2
//	int c;//6-11 6
//	char d;//12 1
//	//13 对齐到16
//}Aid;
//typedef struct B
//{
//	int a;//0-3 4
//	short b;//4-5 2
//	char c;//6 1 1
//	int d;//7-11 5
//	//12
//}Bid;
//int main() 
//{
//
//	printf("%d\n%d",sizeof(Aid),sizeof(Bid));
//	return 0;
//}
//
//#pragma pack(4) //设置为4字节对齐
////long 也是4个字节
//int main(int argc,char* argv[]) 
//{
//	struct tagTest1
//	{
//		short a;//0-1 2
//		char d;//2 1
//		long b;//3-4-7  5
//		long c;//8-11 4
//		//12
//	};
//	struct tagTest2
//	{
//		long b;//0-3 4
//		short c;//4-5 2
//		char d;//6 1
//		long a;//7-8-11 5
//		//12
//	};
//	struct tagTest3
//	{
//		short c;//0-1 2
//		long b;//2 - 4 -7 6
//		char d;//7 1
//		long a;//8 11 4
//		//13-16
//	};
//	printf("%d\n%d\n%d",sizeof(struct tagTest1),sizeof(struct tagTest2),sizeof(struct tagTest3));
//	return 0;
//}