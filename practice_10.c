#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<assert.h>
//字符串函数使用和剖析
//C语言中对字符和字符串的处理很是频繁，但是C语言本身没有字符串类型！！！
//字符串通常放在常量字符串中或者字符数组中。字符串常量适用于那些对他不做修改的字符串函数。
//函数介绍:
//strlen
//size_t_strlen(const char* str);
//字符串以'\0'作为结束表示,strlen函数返回的是在字符串中'\0'前面出现的字符
//参数只想的字符串必须要以'\0'结束。
//注意函数的返回值为size_t,是无符号的(易错)
//typedef _w64 unsigned int size_t; 把unsigned int 重命名为size_t
/*
求字符串长度
strlen
长度不受限制的字符串函数  不安全
strcpy strcat strcmp
长度受限制的字符串函数介绍
strncpy strncat strncmp
字符串查找
strstr strtok
错误信息报告
strerror
*/
//strlen函数的模拟实现:
//1计数器的方法
//2递归的方法
//3指针-指针

//1计数器的方法
//my_strlen(const char* str)//传过来a的地址 拿字符指针接收
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str != '\0')//此处可以改为while(*str)因为*str为\0的时候(\0就是0) 0条件为假 循环终止 
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main() 
//{
//	char arr[] ="abcdef";
//	//错误示范: 不知道strlen在哪里找到\0的 结果人是看不出来的 计算机会一直往下找
//	//char arr[] = { 'a','b','c','d','e','f' };
//	int len = my_strlen(arr);
//	printf("%d\n",len);
//	if (strlen("abc") - strlen("abcdef" )>0)//3-6 = -3  但由于strlen的函数返回的是无符号值 -3当做无符号值看待比0大的多! 打印hehe
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}

//strcpy
//源字符串必须以'\0'结束
//会将源字符串中的'\0'拷贝到目标空间 
//目标空间必须足够大，以确保能存放源字符串
//目标空间必须可变

//模拟实现
//char* my_strcpy(char* str1 ,char* str2) 
//{
//	char* set = str1;//这一行放在上面和while循环下面都行 因为这是指针 始终指向str1的地址跟执行顺序没太大关系
//	assert(str1 != NULL && str2 != NULL);
//	while (*str1++ = *str2++)//当str2的值为\0时赋值给str1 整个表达式的值为假循环终止
//	{
//		;
//	}
//	//返回str1的起始地址
//	return set;
//}
//int main() 
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "abc";
//	//错误示范 strcpy(arr2, arr1);不能把长度长的拷贝给长度短的 越界访问 把短的给撑大了
//	//错误示范 char *arr1 = "abcdef";指针指向常量字符串的地址 常量字符串不能修改 强行拷贝会错误 而上面的拷贝只是修改数组的值
//	
//	//strcpy(arr1, arr2);//把arr2 abc\n 全部放进去
//
//	my_strcpy(arr1, arr2);
//	printf("%s\n",arr1);
//	return 0;
//}
 
//strcat
//源字符串必须以'0'结束
//目标空间必须足够大,能容纳下源字符串的内容 目标空间最好定义一下
//目标空间必须可修改

//char* my_strcat(char* str1,char* str2) 
//{
//	char* ret = str1;
//	assert(str1 != NULL && str2 != NULL);
//	//1 找到目的字符串'\0'
//	while(*str1 !='\0')
//	{
//		str1++;
//	}
//	//2 从'\0'(包括\0)追加
//	while (*str1++ = *str2++) 
//	{
//		;
//	}
//	return ret;
//
//}
//int main() 
//{
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	//strcat(arr1, arr2);
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);//%s打印字符串 从arr1的\0位置 取代\0并开始追加
//}

//strcmp函数
//比较的是俩个字符串的首个字符的大小 
//第一个字符串大于第二个字符串,返回大于0的数字 1(vs是1其他编译器不知道)
//第一个字符串等于第二个字符串,则返回0
//第一个字符串小于第二个字符串,则返回小于0的数字 -1

//int main() 
//{
//	char* p1 = "qbc";
//	char* p2 = "abc";
//	if (strcmp(p1, p2) > 0)//q的ASCII值大于a的ASCII值 所以p1这个字符串的大小大于p2
//	{
//		printf("p1>p2\n");//打印这个
//	}
//	else if (strcmp(p1, p2) == 0)
//	{
//		printf("pa == p2");
//	}
//	else if (strcmp(p1, p2) < 0)
//	{
//		printf("p1<p2\n");
//	}
//}

//模拟实现strcmp
//my_strcmp(const char* str1,const char* str2)
//{
//	assert(str1 && str2);
//	//比较
//	while (*str1 == *str2) 
//	{
//		if (*str1 == '\0') 
//		{
//
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//	{
//		return 1;//大于
//	}
//	else
//		return -1;//小于
////这个if...else整体也可以写成return (*str1 - *str20；返回的是俩个字符之间的ASCII的差值
//}
//int main() 
//{
//	char* p1 = "abcdef";
//	char* p2 = "abqwe";
//	int ret = my_strcmp(p1, p2);
//	printf("ret = %d\n", ret);
//}

//strcpy和strncpy的区别
//int main() 
//{
//	char arr1[5] = "abcde";
//	char arr2[] = "hello bit";
//	strcpy(arr1, arr2);//尽管arr1的长度只有5 但是strcpy不限制长度 还是直接塞到arr1里去 越界了
//
//	printf("%s\n", arr1);
//	return 0;
//}

//int main() 
//{
//	char arr1[10] = "abcdef";
//	char arr2[] = "hello bit";
//	char arr3[] = "bit";
//	strncpy(arr1, arr2, 4);//只把arr2的前四个字符拷给arr1 替换掉abcd
//	strncpy(arr2, arr3,6);//bit\0 4个元素 传6个 再加俩个\0给arr2
//	printf("%s\n",arr1);
//	printf("%s\n",arr2);
//	return 0;
//} 

//strncat
//int main() 
//{
//	char arr1[30] = "hello\0xxxxxxxx";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 10);//从arr的\0开始追加(会把这个\0干掉) 追加后自己会补上一个\0 若规定的长度比这里的arr2长 也不会补多余的\0，这是跟strncpy的区别
//	printf("%s",arr1);
//	return 0;
//}
//
//int main() 
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcqer";
//	//int ret = strcmp(p1, p2);
//	int ret = strncmp(p1, p2, 3);//相同返回0 
//	//小于返回负数 大于返回整数 也是逐个比较字符
//	printf("%d\n",ret);
//	return 0;
//}

//查找字符串函数strstr
//char* strstr(const char* string, const char* strCharSet);
//NULL - 指的是空指针
//NUL/Null - 指的是'\0'

//传过来俩个字符地址 拿字符型指针接收, 由于不会改变原来的字符串 加上const  返回的也是地址 所以返回类型为char*
//return 有终止函数的作用 
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);//确保p1 ,p2都不能为空指针
//	assert(p2 != NULL);
//	char* s1 = NULL;//后面写了s1 = cur = p1,s2 = p1 
//	char* s2 = NULL;
//	char* cur = (char*)p1;
//	if (*p2 == '\0')//若p2是空字符串
//	{
//		return (char*)p1;//强转消除警告
//	}
//	while (*cur)//cur先走到\0  p2不是p1的子串
//	{
//		s1 = cur;
//		s2 = (char*)p2;
//		//while((*s1!='\0') && (*s2 !='\0') && (*s1 == *s2)) //俩字符相同s1,s2一起走
//		while((*s1)&&(*s2)&& !(*s1-*s2))//这个更精简 s1-s2 若s1,s2相同,结果为0, !取反 条件为真 
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//找到了 返回匹配成功的位置
//		{
//			return cur;
//		}
//		if (*s1 == '\0')//若p1的长度小于p2的长度 提前终止
//		{
//			return NULL;
//		}
//		cur++;//俩字符不相同s1独自走
//	}
//	return NULL;//找不到子串 返回空指针
//}
//int main()
//{
//	char *p1 = "abcddefghi";
//	char *p2 = "def";
//	//找不到返回一个空指针 找到返回d的位置 
//	char *ret = my_strstr(p1, p2);//在p1指向的字符串里查找是否存在p2指向的字符串
//	if (ret == NULL) 
//	{
//		printf("子串不存在\n");
//	}
//	else 
//	{
//		printf("%s\n", ret);//ret本身存储的值不是地址 所以无需解引用就可使用
//		//例如 p1先被赋值为"abcdef" 但p1指针指向"abcdef"中a的地址 所引用以p1无需解引用
//	}
//	return 0;
//}
/*
俩字符相同p1,p2一起走 俩字符不同p1向前走
p1指向a,p2指向d。这俩字符不同,p1往前走 走到b不等于p2，走到c等于p2, p1走到d时与p2相同。此时p1和p2一块走 
p1 走到e ,p2也走到e 还是相同 ，继续一起走 p1 f ,p2 f 还相同接着走 p2走到\0了 停止判断。
根据p1,p2谁先走完 判断是否找到 一起走完和p2先走完 都是找到了,p1先走完就没找到。

但由于实际上会有更复杂的案列 例如 abcddef  和def 比较，而且还要返回p1字符串匹配成功时所在字符的地址，
用s1取代p1 s2取代p2 用cur记录字符匹配成功的位置
1 s1,s2还是相同一起走,不同s1独自走 。
2 令s1 = cur,所以cur的位置走一次，s1也走一次,s2的位置回到p2的位置。接着判断俩字符是否相同 循环1-2过程
3 当cur走到\0时，p2不是p1的子串。
4 若在cur走完之前,s2走完了 证明找到了子串 返回cur的值 p1从cur的位置与p2匹配成功
*/

//strtok 函数 字符串分割函数
//sep参数是个字符串,定义了用作分隔符的字符集合
//第一个参数指定一个字符串,它包含了0个或多个由sep字符串中一个或者多个分隔符分割的标识
//strtok函数找到str中的下一个标记(字符),并将其用\0结尾,返回一个指向这个标记的指针。
//注:strtok函数会改变被操作的字符串,所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。
//strtok函数的第一个参数不为NULL，函数将找到str中第一个标记,strtok函数将保存它在字符串中的位置
//strtok函数的第一个参数为NULL,函数将在同一个字符串中被保存的位置开始,查找下一个标记。
//如果字符串不存在更多的标识,则返回NULL指针。

//int main() 
//{
//	char arr[] = "zpw@bitedu.tech";
//	char* p = "@.";
//	//strtok函数首先找到@ 然后把@改成\0,返回z的地址拿到zpw 记住这个位置 从这个位置继续 下个符号.再改\0 返回b的地址 拿到bitedu 一直这样循环，一个\0就分割了一段
//	//找到最后面的\0时返回t的地址 拿到tech
//	char buf[1024] = { 0 };//strcpy会改字符串 所以拷贝一个用来切割
//	strcpy(buf, arr);
//	char* ret = strtok(arr, p);//根据p的符号切割arr字符串
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);//第二次切割及以后传个空指针就行了 因为这个函数做的有标记
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n",ret);
//	return 0;
//}

//上面的调用函数写的太捞 用循环解决
//int main()
//{
//	char arr[] = "zpw@bitedu.tech";
//	char* p = "@.";
//	//strtok函数首先找到@ 然后把@改成\0,返回z的地址拿到zpw 记住这个位置 从这个位置继续 下个符号.再改\0 返回b的地址 拿到bitedu 一直这样循环，一个\0就分割了一段
//	//找到最后面的\0时返回t的地址 拿到tech
//	char buf[1024] = { 0 };//strcpy会改字符串 所以拷贝一个用来切割
//	strcpy(buf, arr);
//	char* ret = NULL;//根据p的符号切割arr字符串
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//strerror函数
//返回错误码，所对应的错误信息。
//int main() 
//{
//	char* str = strerror(0);
//	printf("%s\n",str);
//
//}

//error 是一个全局的错误码的变量
//当C语言的库函数在执行过程中,发生了错误，就会把对应的错误码，赋值到errno中
//int main() 
//{
//	FILE* pf = fopen("test.txt", "r");//r是读文件的意思
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//	}
//	else 
//	{
//		printf("open file success \n");
//	}
//	return 0;
//}

//字符分类函数:
//函数    如果他的参数符合下列条件就返回真
//iscntrl 任何控制字符
//isspace 空白字符:空格,换页\f,换行\n,回车\r,制表符\t或者垂直制表符\v
//...

//#include<ctype.h>
//int main() 
//{
//	char ch = 'w';
//	int ret = islower(ch);
//	printf("%d\n",ret);//是小写 返回非0数字 不是小写返回0
//	return 0;
//}

//字符转换:
//int tolower(int c);//大写转小写
//int toupper(int c);//小写转大写

//#include<ctype.h>
//int main()
//{
//	//char ch = tolower('q');//q
//	//putchar(ch);//打印字符
//	char arr[] = "I Am A Student";
//	int i = 0;
//	while (arr[i]) 
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n",arr);
//	return 0;
//}


//字符串拷贝函数有相当大的局限性 而内存函数功能性远超它
//int main() 
//{
//	int arr1[] = { 1,2,3,4,5 };//01 00 00 00 | 02 00 00 00 | 03 00 00 00 |04 00 00 00 |05 00 00 00
//	int arr2[5] = { 0 };//拷贝一个字节的来 01 00(strcpy读到0就停止)所以就读到这里 就拷贝一个1过去
//	strcpy(arr2, arr1);//arr2只被拷贝了一个1过去
//	//原因strcpy的参数是char* 一次只拷贝一个字节 遇到\0停止
//	return 0;
//}

//内存函数:
//memcpy:内存拷贝 用void*接收所有参数的类型 
//memmove:

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));//拷贝大小为arr1的大小
//	return 0;
//}

//struct S 
//{
//	char name[20];
//	int age;
//};
//void* my_memcpy(void* dest,const void* src,size_t num) 
//{	
//	void* ret = dest;//返回arr4的起始地址
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
//C语言标准
//memcpy 只要处理 不重叠的内存拷贝就可以 
//memmove 处理重叠内存的拷贝
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	my_memcpy(arr+2,arr,20);//20个字节 5个元素 ，俩块内存空间不能有关联 否则拷贝失败 重叠空间的拷贝用memmove
//	//但是在VS编译器下 memcpy也可以处理重叠空间的拷贝
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main() 
//{
//	struct S arr3[] = { {"张三",20},{"30",30} };
//	struct S arr4[3] = { 0 };
//	//memcpy(arr4,arr3,sizeof(arr3));
//	my_memcpy(arr4, arr3, sizeof(arr3));
//	return 0;
//
//}


//void* my_memmove(void* dest, const void* src, size_t count) 
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	//根据起始位置不同选择不同的拷贝方式
//	if (dest < src)//比较大小和类型没太大关系
//	{
//		//从前向后拷贝
//		while (count--) 
//		{
//			(char*)dest = (char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//
//	}
//	else 
//	{
//		//从后向前拷贝
//		while (count--) 
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}
//int main() 
//{
//	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
//	// 1 2 3 4 5 6 7 8 9 10
//	my_memmove(arr3 + 2, arr3,20);//把1,2,3,4,5拷贝到3,4,5,6,7
//	int i = 0;
//	for ( i = 0; i <10; i++)
//	{
//		printf("%d ",arr3[i]);
//	}
//	//结果1,2,1,2,3,4,5,8,9,10
//	return 0;
//}

//memcmp 相同返回0 arr1小于arr2返回小于0的数 arr1大于arr2返回大于0的数
//memcmp从不相同的第一个元素比较 结果也是根据这个来 后面的其他数没啥用了
//int main() 
//{
//	int arr1[] = { 1,3,4,5,6 };
//	int arr2[] = { 1,2,3,4,5 };
//	int ret = memcmp(arr1, arr2, 16);//比较前4个元素 第二个不同元素3 >2  1
//	printf("%d\n",ret);
//}

//memset 内存设置
//int main() 
//{
//	char arr[10] = "";
//	memset(arr, '#', 10);//把十个元素全部换成#
//	//错误用法
// //int arr[10] = "";
//	memset(arr, 1, 10);//实际上换了10个字节的01 也就是俩个半元素
//	//01 01 01 01 01 01 01 01 01 01  后面的元素还是00 00 00 00 00 00
//	return 0;
//}

//自定义数据类型
//结构体类型 类型 类型!! 是类型就可以定义变量
//struct Stu
//{
//	char name[20];
//	char tele[12];
//	char sex[10];
//	int age;
//
//}s4,s5,s6;
//int main() 
//{
//	//创建的结构体变量
//	struct Stu s1;
//	struct Stu s1;
//	return 0;
//}

//结构体匿名创建 必须创建结构体的全局变量 否则无法创建结构体变量

//struct
//{
//	int a;
//	char c;
//}sa;//匿名结构体类型
//struct
//{
//	int a;
//	char c;
//}*psa;//匿名结构体指针类型
//int main() 
//{
//	psa = &sa;//实际上编译器会把这俩个结构体当做俩个不同的类型 报警告 
//	return 0;
//}

//结构体自引用
//typedef struct Node 
//{
//	int data;
//	//错误的自引用 struct Node n;//n里面有个 data n 里面还有个n .....无线循环 无限大
//	//在结构体中包含一个类型 ,为该结构本身的成员是否可以呢? 不行
//
//	struct Node* next;//存放指向下个节点的指针 --链表
//}Node;//类型名简化为Node

//等同于:
//struct Node
//{
//	int data;
//	struct Node* next;
//};
//typedef struct Node Node;

//int main() 
//{
//	struct Node  n1;
//	Node n2;//上下俩行一样
//	return 0;
//}

//结构体初始化
//struct T
//{
//	double weight;
//	short age;
//};
//struct S
//{
//	char c;
//	struct T st;//结构体包含结构体
//	int a;
//	double d;
//	char arr[23];
//};
//int main() 
//{
//	//struct S s   = {'c', 1 , 1.1 ,"我想啸啊！ 确实不帅！"};
//	struct S s = { 'c',{13.2,30},100,3.14,"hello world"};
//	printf("%c %d %f %s\n",s.c,s.a,s.d,s.arr);//%c一个字符 %s以一个字符串
//	printf("%lf %d",s.st.weight,s.st.age);
//	return 0;
//}

//结构体 内存对齐
//考点如何计算
//1 第一个成员在与结构体变量偏移量为的地址处
//2 其他成员变量要对齐到某个数字(对齐数)的整数倍地址处
//对齐数 = 编译器默认的一个对齐数 与 该成员的大小的较小值
//VS 编译器默认的对齐数 是8  gcc没有默认对齐数(官方说的 民间说法是4)
//3 结构体总大小为最大对齐数的整数倍
//4 如果嵌套了结构体的情况,嵌套的结构体对齐到自己的最大对齐数的整数倍，
//结构体的整体大小就是所有最大对齐数(含嵌套结构的对齐数)的整数倍
//struct S1
//{
//	char c1;
//	int a;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//struct S4 
//{
//	char c;
//	struct S3 s3;
//	double d;
//};
//int main() 
//{
//	struct S1 s1 = { 0 };
//	printf("%d\n",sizeof(s1));//12
//	struct S2 s2 = { 0 };
//	printf("%d\n",sizeof(s1));//8
//	struct S4 s4;
//	printf("%d\n",sizeof(s4));
//	return 0;
//}

///为什么存在内存对齐?
/*
1.平台原因(移植原因):不是所有的硬件平台都能访问任意地址上的任意数据的，某些硬件平台
只能在某些地址处去某些特定类型的数据,否则抛出硬件异常。
2.性能原因:数据结构(尤其是栈)应该尽可能地在自然边界上对齐。原因在于，为了访问未对齐的
内存，处理器需要作俩次内存访问;而对齐的内存访问仅需要一次访问。
总体来说:
结构体的内存对齐是拿空间换取时间的做法。
*/
//所以在设计结构体的时候,我们既要满足对齐,又要节省空间,如何做到:
//让占用空间小的成员尽量集中在一起。
//例如:
//struct S1 
//{
//	char c1;
//	int i;
//	char c2;
//};
////s2就比s1节省空间
//struct s2 
//{
//	char c1;
//	char c2;
//	int i;
//};

//C语言可以修改内存对齐数 
//设置默认对齐数为4
//#pragma pack(4)
//取消设置的默认对齐数 #pragma pack()
//struct S
//{
//	char c1;//占一个字节
//	//浪费七个字节
//	double d;//占八个字节
//};
//
//int main() 
//{
//	struct S s;
//	printf("%d\n",sizeof(s));
//}

//offsetof(结构体名，结构体成员变量名) 计算结构体成员变量相对于结构体起始位置的偏移量
//offsetof()是个宏
//#include<stddef.h>
//struct S
//{
//	char c;
//	int i;
//	double d;
//};
//int main() 
//{
//	printf("%d\n",offsetof(struct S,c));
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, d));
//	return 0;
//}

//结构体传参
//struct S 
//{
//	int a;
//	char c;
//	double d;
//};
//void Init(struct S* tmp)
//{
//	tmp->a = 100;
//	tmp->c = 'w';
//	tmp->d = 3.14;
//}
//void Print1(struct S tmp)
//{
//	printf("%d %c %lf\n", tmp.a, tmp.c, tmp.d);
//}
//void Print2(struct S* ps) 
//{
//	printf("%d %c %lf\n",ps->a,ps->c,ps->d);
//}
//int main() 
//{
//	struct S s;
//	Init(&s);
//	Print1(s);
//	Print2(&s);
//	//s.a = 100;
//	//s.c = 'w';
//	//s.d = 3.14;
//	//printf("%d\n",s.a);
//	return 0;
//}

//位段的声明和结构是类似的,有俩个不同
//1 位段的成员必须是int， unsigned int 或signed int ,char...
//2 位段的成员名后边有一个冒号和一个数字
//结构体实现位段的能力

//冒号后面的数字是 该数所需要的比特位(你自己设定的) 一个比特位就是一个二进制位
//位段的内存分配
//1位段的成员可以是int, unsigned int ,signed int 或者是char(属于整形家族)类型
//2位段的空间上是按照需要4个字节(int)或者1个字节(char)的方式来开辟的
//3位段涉及很多不确定因素,位段是不跨平台的,注重可移植的程序应该尽量避免使用位段
//位段的跨平台问题
//1 int位段被当成有符号数还是无符号数是不确定的
//2位段的最大的数目不能确定(16位机器最大16,32位机器最大32，写成27会在16位机器上出错)
//3位段中的成员在内存中从左向右分配，还是从右向左分配标砖尚未定义。
//4 当一个结构包含俩个位段，第二个位段成员比较大，无法容纳与第一个位段剩余的位时，
//是舍弃剩余的位还是利用，这是不确定的。
//struct S
//{
//	int a : 2;//你认为a只需要俩个比特位就够了 
//	int b : 5;
//	int c : 10;
//	int d : 30;
//	//总共是47个比特位 一字节八个比特 需要6个字节就够了
//	//但是由于位段的特殊内存分配方式 整型先分配4个字节 够abc用 不够d用 所以在分配4个字节 给d用
//	//注意d是全部放在新给的4个字节里面 上一个字节剩下的比特位就浪费掉了
//	//总共8个字节
//};
//int main() 
//{
//	struct S s = {0};
//
//}

//struct S
//{
//	char _a : 3;//_a只是也是变量名 只不过能方便看出来这是位段而已
//	char _b : 4;//开辟一个字节 够a 够b 不够 c 再开一个 c占5个 不够d 再开一个 放d
//	char _c : 5;//一共占3个字节 空间从右向左使用(小端) 从低地址到高地址使用
//	char _d : 4;
//};
//int main() 
//{
//	struct S s = { 0 };
//	s._a = 10;
//	s._b = 20;
//	s._c = 3;
//	s._d = 4;
//	return 0;
//}

//自定义数据类型-枚举 关键字enum
//把可能的取值一一列举
//默认取值是跟着上一个数走的
//例如A：1 B C不赋值 那么A： 1 B： 2 C： 3  若A C不赋值 B：5  那么A： 0 B： 5 C： 6 

//enum Sex
//{
//	//枚举的可能取值 - 常量 
//	//枚举是用来定义常量的 比define定义常量有很多好处
//	//增加代码的可读性和可维护性 有枚举类型检查更严谨
//	//防止了命名污染(封装) 便于调试 使用方便 一次可以定义多个常量
//	MALE = 2 ,
//	FEMALE =4 ,
//	SECRET = 8//改变默认取值
//};
//enum Color
//{
//	RED,//默认取值0
//	GREEN,//1
//	BLUE//2 一直递增
//};
//int main() 
//{
//	enum  Sex s = MALE;//赋值只能是上面的三个值
//	enum Color c = BLUE;
////错误写法 enum Color c = 2;//左边是枚举类型 你给他赋个整型的数2 编译器就报错 不报错是因为编译器语法检查不严格
//	printf("%d %d %d", RED, GREEN, BLUE);
//	return 0;
//}


//自定义数据类型-联合体(共用体) 关键字union
//联合体的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小
//因为联合体至少要有能力保存最大的那个成员
//联合体变量不能同时使用       
//union Un
//{
//	char c;//共4个字节 先放c(c是char型单独占据一个字节) 剩下的三个字节再放i
//	int i;
//};
//int main() 
//{
//	union Un u;
//	printf("%d\n",sizeof(u));//4
//	printf("%p\n", &(u));//010FF704
//	printf("%p\n", &(u.c));//010FF704
//	printf("%p\n", &(u.i));//010FF704
//
//	return 0;
//}

//判断大小端 用普通方法和枚举方法
//但是这些判断方法局限性很大 只能判断特定的数
//check_sys()
//{
//	int a = 1;//0x 00 00 00 01
//		//小端01 00 00 00
//		//大端00 00 00 01
//	return   *(char*)&a;
//}

//联合体
//check_sys() 
//{
//	union Un
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;//把i所在的空间的赋值为1 c也在里面 c占第一个字节
//	//返回1，表示小端
//			//返回0,表示大端
//	return u.c;
//}
//int main() 
//{
//	//0x11223344
//	//小端[][]44 33 22 11
//	//大端[][]11 22 33 44
//	int ret = check_sys();
//	if (1 == ret)//如果第一个字节是1就是小端
//	{
//		printf("小端\n");
//	}
//	else 
//	{
//		printf("大端");
//	}
//	return 0;
//}

//联合体的大小

//union Un 
//{
//
//	int a;//4 8  对齐数 是4 
//	char arr[5];//但char[arr] 总共占5个字节是最大成员    char arr[5]的对齐数是每个元素的大小是1
//	//当最大成员的大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍 。
//};
//int main()
//{
//	union Un u;
//	printf("%d\n",sizeof(u));//5对齐到4的倍数 为8 浪费3个字节大小
//	return 0;
//}