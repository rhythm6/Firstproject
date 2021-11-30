#define _CRT_SECURE_NO_WARNINGS 1
#include"train.h"
//指向函数指针数组的指针
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main() 
//{
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;//取数组地址
//	int(*pf)(int, int);//*pf是函数指针
//	int(*pfArr[4])(int, int);//函数指针数组
//	int(*(*ppfArr)[4])(int, int) = &pfArr;//ppfArr指向函数指针数组的指针
//	//pfArr是一个数组指针(*pfArr[4]) 指针指向的数组有4个元素
//	//指向数组的每个元素的类型是int(*)(int, int)
//
//	return 0;
//}

//回调函数aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
//void print(char* str)//print就是回调函数 4
//{
//	printf("hehe:%s",str);
//}
//void test(void(*p)(char*))//通过函数指针接收地址 2 
//{
//	printf("test\n");
//	p("bit");//通过p调用print函数 3  回来再打印5
//}
//int main() 
//{
//	test(print);//把print的函数地址传给test函数 1
//	return 0; //6
//}

//复习指针数组 函数指针 数组指针 ...
//int Add(int x, int y) 
//{
//	return x + y;
//}
//int main() 
//{
//	//指针数组
//	//int* arr[10];
//	//数组指针
//	//int* (*pa)[10] = &arr;
//	//函数之中
//	int (*pAdd)(int, int) = Add;//&Add
//	int sum = (*pAdd)(1, 2); //1
//	int sum = pAdd(1, 2);//2
//	int sum = Add(1, 2);//3 3个都一样 因为函数名就是地址 指针存的是函数的地址 
//
//	//函数指针的数组
//	//int (*pArr[5])(int, int);//数组每个元素的类型int(*)(int,int)
//	//指向函数指针数组的指针
//	//ppArr= &pArr
//	int (*(*pArr)[5])(int, int)= &pArr;
//	return 0;
//}


//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++) 
//	{
//		//一趟冒泡排序
//		int j = 0;
//		for ( j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])//交换俩个数
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}

//82 - 220是一整个代码
//因为你比较俩个元素 那char型接收只有一个字符大小，但必须要知道元素大小所以传过来元素大小
//void Swap(char* buf1, char* buf2,int width) 
//{
//	int i = 0;
//	for ( i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
////实现bubble_sort，他是否知道未来排序的数据类型-不知道
////他也不知道要比较的俩个元素的类型 所以设计为void*
////当我们把一个函数的地址传进去之后，在这个函数内部 通过这个函数指针调用另外一个函数 这就叫做回调函数
////设置void*可以接收任意类型的参数
//void bubble_sort(void* base, int sz, int width,int(*cmp)(void*e1,void*e2) )//cmp就是回调函数
//{
//	int i = 0;
//	//趟数
//	for ( i = 0; i < sz-1; i++)
//	{
//		//每一趟比较的对数
//		int j = 0;
//		for ( j = 0; j < sz-1-i; j++)
//		{
//			//两个元素的比较
//			//base是void型 想执行运算符操作 必须强转为其他类型（为啥转换成char*而不是其他，因为char类型的步长是一个字节，跳转一次走一个字节）
//			// base被强制转换成char*后 每次跳转j*width长度 也就是一个元素的长度
//			//因为具体你想比较的类型长度你不知道 所以用width(每个元素的大小) 每次跳一个width 跳了一个元素
//			//base是数组起始位置 加上width每个元素的大小 也就是说base是第一个元素 加一个元素大小 就是第二个元素 以此类推
//			//当j=1 相当于第一个元素和 第二个元素比较, 因为左边加的是0个元素的大小 右边加了一个元素的大小
//			if (cmp((char*)base+j*width,(char*)base+(j+1)*width) > 0)//cmp是你调用的比较函数
//			{
//				//交换
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
//			}
//		}
//	}
//}
//
//struct Stu 
//{
//	char name[20];
//	int age;
//};
//void qsort(void* base,  //qsort 库函数
//	size_t num,
//	size_t width,
//	int(*cmp)(const void* e1, const void* e2)
//		);
//
//int cmp_int(const void* e1, const void* e2) //接收你想比较的俩个数的地址 参数类型完全仿造qsort的参数类型
//{
//	//比较俩个整形值
//	return *(int*)e1 - *(int*)e2;//把void*强转为int*就可以解引用了
//	//当第一个元素小于第二个元素 返回小于0的数
//	//当第一个元素等于第二个元素 返回0
//	//当第一个元素大于第二个元素 返回大于0的数
//}
//int cmp_float(const void* e1,const void* e2)
//{
//	return *(float*)e1 - *(float*)e2;// 1 1有警告
//	
//	if (*(float*)e1 == *(float*)e2)
//		return 0;
//	else if (*(float*)e1 > *(float*)e2) //2没事
//		return 1;
//	else 
//	
//		return -1;
//	return (int)(*(float*)e1 - *(float*)e2);//3 强转后无警告
//}
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//int cmp_stu_by_name(const void* e1, const void* e2) 
//{
//	//字符串比较 不能直接用运算符来比较
//	//应该用 strcmp string compare 字符串比较函数
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//void test1() 
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);//参数分别是: 待排序数组的元素地址 待排序数组元素个数 待排序数组的每个元素大小(字节) 提供一个比较俩个元素的方法(函数)地址，也就是函数名 该函数自己实现
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}
//void test2()
//{
//	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]),cmp_float);
//	int j = 0;
//	for (j = 0; j < sz; j++) 
//	{
//		printf("%f\n", f[j]);
//	}
//}
//void test3()
//{
//	struct Stu s[3] = { {"zhanggan",20},{"list",30},{ "wangwu",10} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]),cmp_stu_by_name);
//}
//void test4()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//使用bubble_sort冒泡函数的程序员一定知道自己排序的是什么数据
//	//他就知道如何比较待排序数组中的元素
//	bubble_sort(arr,sz,sizeof(arr[0]),cmp_int );
//}
//void test5() 
//{
//	struct Stu s[3] = { {"zhanggan",20},{"list",30},{ "wangwu",10} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	bubble_sort(s, sz, sizeof(s[0]),cmp_stu_by_name);
//}
//
//int main()
//{
//	//test1();//冒泡排序排整数
//	//test2();//排浮点型
//	//test3();//排结构体类型
//	//test4();
//	test5();//排序字符型
//	//qsort在#include<stdlib.h>中
////	bubble_sort(arr,sz );
//	return 0;
//}


//int main() 
//{
//	int a = 10;
//	void* p = &a;//无类型指针 正确
//	//非法的间接寻址
//	//*p = 0;//解引用操作错误 void*不能解引用 因为不知道指针类型 系统不知道解引用时能访问几个字节
//	//p++;//错误 因为不知道指针的步长 一次不知道走多少个字节
//	return 0;
//}
//

//一维数组面试笔试题
// sizeof求空间大小
// strlen求字符长度 有\0
 
//例外1 sizeof(数组名)//表示整个数组
//例外2 &数组名 表示取整个数组的地址
//从数值上看：数组地址&arr = 数组首地址arr = 数组首元素地址&arr[0]
//只要是地址的sizeof都是 4 32位/ 8 64位
//int main() 
//{
//	//在32位结果是4 在64位结果就是8
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));//计算的是整个数组的大小 4个元素 每个元素整形 4*4 = 16
//	printf("%d\n", sizeof(a + 0));//这个a是俩个例外之外的情况 还是首元素地址 4+0=0
//	printf("%d\n", sizeof(*a));//数组名表示首元素地址 *a就是首元素 4 
//	printf("%d\n", sizeof(a + 1));//首元素地址跳过一个元素 第二个元素的大小还是4 
//	printf("%d\n", sizeof(a[1]));// 第二个元素的大小 4
//	printf("%d\n", sizeof(&a));//取的是数组的地址 但数组的地址的大小还是4个字节 4
//	printf("%d\n", sizeof(*&a));//取数组的地址 在解引用就是找到数组 计算数组的大小 16,也可以说是&和*抵消了
//	printf("%d\n", sizeof(&a +1 ));//取整个数组的地址再加一就是跳过一个数组,但它还是一个数组的地址 还是4
//	printf("%d\n", sizeof(&a[0]));//取第一个元素的地址 还是4
//	printf("%d\n", sizeof(&a[0]+1));//取第一个元素的地址 再加1是第二个元素的地址 还是4
//	return 0;
//}

//字符数组
//int main() 
//{
//	char arr[] = { 'a','b','c,','d','e','f' };
//	printf("%d\n", sizeof(arr));//6
//	printf("%d\n", sizeof(arr + 0));//首元素地址 4/8 跟数组类型无关！！
//	printf("%d\n", sizeof(*arr));//首元素大小 1
//	printf("%d\n", sizeof(arr[1]));//第二个元素大小 1
//	printf("%d\n", sizeof(&arr));// 数组的地址 还是地址 4/8
//	printf("%d\n", sizeof(&arr + 1));//跳过一个数组 还是地址 还是4/8
//	printf("%d\n", sizeof(&arr[0] + 1));//第二个元素的地址 4/8
//
//
//	//C6054:可能没有为字符串"arr"添加字符串终止符
//	printf("%d\n", strlen(arr));//一直找\0才停止 找不到\0 所以结果是随机值
//	printf("%d\n", strlen(arr + 0));//随机值 理由与上一行类型
//	
//	printf("%d\n", strlen(*arr));//随机值 解引用后 是'a','a' 的ASCII 97 传过去97 strlen函数要的是地址 接收到地址是97(没有这个地址) 然后从97开始向后搜索\0 非法访问内存
//	//读取位置 xxxxx时发生访问冲突
//	printf("%d\n", strlen(arr[1]));//把'b' 98传入 也错误
//	
//	printf("%d\n", strlen(&arr));//随机值 a的地址开始找 不知道什么时候找不到\0  A
//	printf("%d\n", strlen(&arr + 1));// 跳过一个数组 还是不知道什么时候找不到\0 这行与上一行的随机值 差一个数组的长度 差6
//	printf("%d\n", strlen(&arr[0] + 1));//b的地址 往后找还是随机数 比A行的随机数少1
//	return 0;
//}

//int main()
//{
//	//字符串数组
//	char arr[] = "abcdef";//字符串 a b c d e f \0
//
//	//printf("%d\n", sizeof(arr));//数组大小 7 
//	//printf("%d\n", sizeof(arr + 0));//首元素地址 4/8 跟数组类型无关！！
//	//printf("%d\n", sizeof(*arr));//首元素大小 1
//	//printf("%d\n", sizeof(arr[1]));//第二个元素大小 1
//	//printf("%d\n", sizeof(&arr));// 数组的地址 还是地址 4/8 vc6.0 这行代码不是4/8 是编译器的bug
//	//printf("%d\n", sizeof(&arr + 1));//跳过一个数组 还是地址 还是4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));//第二个元素的地址 4/8
//
//	printf("%d\n", strlen(arr));//一直找\0才停止 \0之前有6个元素 字符串长度为6
//	printf("%d\n", strlen(arr + 0));//从第一个字符的地址往后找 一共找到6个字符 
//
//	//printf("%d\n", strlen(*arr));//随机值 解引用后 是'a','a' 的ASCII 97 传过去97 strlen函数要的是地址 接收到地址是97(没有这个地址) 然后从97开始向后搜索\0 非法访问内存
//	//读取位置 xxxxx时发生访问冲突
//	//printf("%d\n", strlen(arr[1]));//把'b' 98传入 也错误
//
//	printf("%d\n", strlen(&arr));//数组的地址 - 数组指针 char (*p)[7] = &arr, 而strlen的函数类型是const char*  这俩个类型不兼容
//	// 警告:“函数”:“const char *”与“char (*)[7]”的间接级别不同 ,随机值 数组的地址开始找 找到\0  6个字符 6 
//	printf("%d\n", strlen(&arr + 1));//随机值 因为跳过整个数组 把\0也跳过了 后面不知道什么时候找到\0
//	printf("%d\n", strlen(&arr[0] + 1));//b的地址 往后找五个字符 5
//
//
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));//计算指针变量大小 4/8
//	printf("%d\n", sizeof(p + 1));//p存的是a的地址 p+1是b的地址 4/8
//	printf("%d\n", sizeof(*p));//*p是字符串的第一个字符 'a' 大小是1
//	printf("%d\n", sizeof(p[0]));// int arr[10]; arr[0] == *(arr+0)  p[0]  == *(p+0) == 'a'   a的大小1
//	printf("%d\n", sizeof(&p));//数组的地址 4/8
//	printf("%d\n", sizeof(&p + 1));//绕过一个数组后的 数组的地址4/8
//	printf("%d\n", sizeof(&p[0] + 1));//b的地址 4/8
//
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	//printf("%d\n", strlen(*p));//error 'a'的ASCII值97当做地址传进去 直接错误 
//	//printf("%d\n", strlen(p[0]));//error 'a'
//	printf("%d\n", strlen(&p));//数组的地址 不知道什么时候找到/0  随机值 
//	printf("%d\n", strlen(&p + 1));//随机值 与上一行类似
//	printf("%d\n", strlen(&p[0] + 1));//第二个元素的地址 开始数 数到\0 是5
//
//	//二维数组
//	int a[3][4] = {0};
//	printf("%d\n", sizeof(a));//整个数组的大小 3行4列 12个元素 吗，每个元素4个字节 48
//	printf("%d\n", sizeof(a[0][0]));//第一行第一列个的元素的大小 4
//	printf("%d\n", sizeof(a[0]));//第一行的4个元素 16  因为第一行的第i个元素是a[0][i]这样表示 所以a[0]代表第一行 a[1]代表第二行..
//	printf("%d\n", sizeof(a[0] + 1));//a[0]现在是第一行第一个元素的地址 +1就是 第一行 第二个元素的地址 4
//	printf("%d\n", sizeof(*(a[0] + 1)));//第一行第二个元素 4
//	printf("%d\n", sizeof(a + 1));//二维数组 把二维数组当成一维数组 数组名是首元素地址(第一行) 每个小数组是它的元素 首元素+1是第二行元素的地址 4
//	printf("%d\n", sizeof(*(a + 1)));//第二个数组 16
//	printf("%d\n", sizeof(&a[0] + 1));//第二行的地址 4
//	printf("%d\n", sizeof(*(&a[0] + 1)));//第二行的大小 16
//	printf("%d\n", sizeof(*a));//a是第一行地址 *a就是计算第一行地址的大小 16
//	printf("%d\n", sizeof(a[3]));//第四行的数组  16
////sizeof()不参与 运算 只是根据类型判断空间大小而已 所以上面数组虽然没有第四行 但是sizeof()当做a[0] 这样判断
//
//	return 0;
//}

// 指针笔试题
//int main() 
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);//数组的地址取出来 在+1 就是该数组地址跳到数组末地址
//	//举个例子理解 
//	//  [&a]|1|2|3|4|5|[&a+1]  也就是跳过一个数组 
//	printf("%d,%d",*(a+1),*(ptr - 1));//a+1 = a[1] 也就是2    5
//	//ptr-1 就是&a+1这个地址的位置往前挪一个位置 就是数组元素5的地址 在解引用就是5
//
//	return 0;
//}

//---------
// 
//struct Test
//{
//	int Num;
//	char* pcNmae;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////假设p的值为0x100000 ,如下表表达式的值分别为多少？
////已知,结构体Test类型的变量大小是20个字节
//// 0x1是16进制1
//int main() 
//{
//	int a = 1048576;
//	//%p打印地址
//	p = (struct Test*)0x100000;//指针变量p, p存的值是0x100000
//	printf("%p\n",p + 0x1);//结构体指针 +1 跳过一个结构体的大小 0x 100000+20 = 0x 100014  补上0 0x 00100014
//	printf("%p\n", (unsigned long)p + 0x1);//强转成长整型+1 就是实实在在的加个1 
//	//0x 100000 10进制 1048576 +1 1048577   再转回来0x100001 补0 0x 00100001
//	printf("%p\n", (unsigned int*)p + 0x1);//强转成无符号整形指针 +1 就是跳过一个无符号整型指针  一个无符号整型指针大小是4
//	//00100004
//
//	return 0;
//}

//----------

//int main() 
//{
//	int a[4] = { 1,2,3,4 };
//	//[数组] 01(ptr1指向的位置) 00 00 00 | 02 00 00 00 | 03 00 00 00 | 04 00 00 00 [数组(&a+1的位置)]   小端存储
//	int* ptr1 = (int*)(&a + 1);//跳过一个数组
//	int* ptr2 = (int*)((int)a + 1);//强制为int型加1 就是地址跳过一个字节 
//	printf("%x,%x",ptr1[-1],*ptr2);//ptr1[-1] = *(ptr1+(-1)) = *(ptr-1) 往前挪一个整型的大小 从|04 00 00 00 |开始倒着读 00 00 00 04 就是0x4  实际打印4
//	//*ptr2 从|00 00 00 02|开始倒着读 02 00 00 00, 0x 02 00 00 00  实际打印2 00 00 00  前面的被控制台省略了
//	return 0; 
//}

//-------------------
//int main() 
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };//(0,1)这里面的逗号是逗号表达式 结果是最后一个数的结果 
//	//实际上放的是1,3,5
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);//就是1
//}

//-------------------
//int main() 
//{
//	int a[5][5];
//	//[p的地址][][][][p+1] | [][][][p+2][] | [][][p+3][][] | [][p+4(+0)][][p+4+(2)][]|[][][&a[4][2]的地址][][]
//	//&a[4][2]就是第5行第3个元素的地址
//	//p[4][2]就是*(p+4)跨越4个整型 16个字节  *(p+4)找到这个位置的值 后面的四个元素就是一个数组 (*(p+4)+2)这四个元素的第3个元素
//	int(*p)[4];
//	p = a;//警告类型不相符 a的类型是int(*)[5] p的类型是int(*)[4]
//	printf("%p\n%d",&p[4][2] - &a[4][2],&a[4][2] - &p[4][2]);//后面减法相差四个字节打印出来就是4
//	//前面是 - 4, 用十六进制打印 														 
//	//%p直接打印16进制的补码值 不关心正负号 %p打印地址
//	//-4 10000000 00000000 00000000 00000100 原
//	//	 11111111 11111111 11111111 11111011 反
//	//   11111111 11111111 11111111 11111100 补
//	// 4个1是一个f,1100是c   0x f f f f f f f c 输出FFFFFFFC
//
//}

//int main() 
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };//二行五列 6 7 8 9 10是第二行的元素
//	//[数组地址]{ 1,2,3,4,5,6,7,8,9,10 }[&aa+1]
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));//(aa+1) = aa[1]是第二行地址 也是第二行首元素6的地址
//	printf("%d,%d\n",*(ptr1 - 1),*(ptr2 - 1));//往前挪一个整形 数组是整形数组 一个元素就是4个字节 所以往前挪一个元素就好 结果;10 5 
//	return 0;
//}

//int main() 
//{
//	char* a[] = { "work","at","alibaba" };//三个元素的数组 每个元素的类型是char*  每个char*存放一个字符串的首地址
//	//字符串存到字符型指针 是把每个字符串的首字符的地址传给字符指针
//	char** pa = a;//pa是指针 pa指向的元素是char*的
//	pa++;//跳过一个字符型 指向第二个元素
//	printf("%s\n",*pa);//%s打印字符 at
//	return 0;
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3, c + 2, c + 1, c };//F,P,N,E
//	char*** cpp = cp;//指向cp的首地址的元素P
//	printf("%s\n",**++cpp);//cpp++指向cp的c+2元素 解引用拿到c+2, c+2是P的地址,在解引用拿到P的地址 %s打印字符串 从p开始打印字符串 结果是POINT
//	printf("%s\n", *--*++cpp +3);//因为上行的cpp已经自增过一次 这次cpp++ 就是c+1的地址 解引用拿到c+1 在c+1 -- 就是c 
//	//在解引用找到E字符的地址 跳过3个字符后开始打印 E是[+0]N是[+1]  从第4个E开始打印  ER
//	printf("%s\n", *cpp[-2] + 3);//上行的cpp是解引用后再-- 所以只有++才会被保留到这里 cpp现在是c+1 地址减2 变成c+3  解引用拿到F的地址 +3
//	//从S开始打印字符串 结果是ST
//	//cpp[-2]  = *(cpp+(-2)),*cpp[-2] + 3 = **(cpp+(-2)) +3
//	//这俩个一 一个是地址 一个是值 地址减一往前挪一  值减一就减一
//	printf("%s\n", cpp[-1][-1]+ 1 );//同理这一行的cpp还是第二行的cpp 还是c+1的地址 -1 c+2  解引用拿到c+2 -1 = c+1 在解引用拿到N +1 就是E
//	//从E开始打印字符串 结果是EW
//	//cpp[-1][-1]+1 = *(*(cpp-1)-1)+1   
//	return 0;
//}


//int main() 
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulPtr;
//
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;//6的地址往前移三个 就是9的地址 解引用这个地址的值+3 = 12
//	printf("%d,%d",*pulPtr, *(pulPtr +3));//6 12
//}


////逆序字符串
//#include<assert.h>
//void reverse(char* str) 
//{
//	assert(str);//断言 保证str值的有效性
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[256] = { 0 };
//	//scanf("%s",arr);//scanf遇到空格就停止了
//	gets(arr);//得到一行
//	reverse(arr);//逆序函数
//	printf("%s\n", arr);
//	return 0;
//}

//求Sn=a + aa + aaa + aaaa的前五项之和 a是同一个数组
//例如 2 + 22 + 222 + 2222
//int main() 
//{
//	int a = 0;
//	int n = 0;
//	printf("输入数字__,前__项\n");
//	scanf("%d%d",&a,&n);//数字是2 前5项 
//	int sum = 0;
//	int i = 0;
//	int ret = 0;
//	for ( i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d\n",sum);
//	return 0;
//}

//打印水仙花数
//求出0~100000之间的所有"水鲜花数"并输出 水仙花数是自幂数的一种
//"水仙花数"是指一个n位数,其各位数字的n次方之和等于该数本身，如153 = 1^3+5^3+3^3
//#include<math.h>
//int main() 
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//判断i是否为水仙花数(自幂数)
//		//1,计算i的位数 n位数
//		// 123/10 不等于0 n++
//		int n = 1;
//		int tmp = i;//i不能动 用tmp来判断位数
//		int sum = 0;
//		while (tmp /= 10)//先除在判断 i小于10的时候余数为0 条件为假停止循环
//		{
//			n++;
//		}
//		//2.计算i的每一位的n次方之和 sum
//		tmp = i;
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, n);// 从“double”转换到“int”，可能丢失数据 pow返回的数是double型 强转一下警告消失
//			//pow求次方函数 括号左边是目标数 右边是次方数 
//			tmp /= 10;
//		}
//		//3比较i==sum
//		if (i == sum)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//打印菱形
//int main() 
//{
//	int line = 0;
//	scanf("%d", &line);//7  
//	//打印上半部分
//	int i = 0;
//	for ( i = 0; i < line; i++)//行数
//	{
//		int j = 0;
//		for ( j = 0; j < line-1-i; j++)//经过观察上半部分最多空格的那行有line-1个空格 是第一行 此后每行减一 
//		{
//			printf(" ");//打印空格
//		}
//		for (j = 0; j <2*i+1 ; j++)//经观察*的数量是2*i+1
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//打印下半部分
//	for ( i = 0; i <line-1; i++)//行数 实际上下半部分也可以写成i<line 因为多出的行数全都是空格了
//	{
//		int j = 0;
//		//打印空格
//		for ( j = 0; j <=i; j++)//下半部分第一行一个空格没有 第二行一个...
//		{
//			printf(" ");
//		}
//		for ( j = 0; j < 2*(line-1-i)-1; j++)//第一行(2*（行数-1-0) 减一  第二行（2*(行数-1-1)）-1
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}

//下列横线中哪个选项哪项不能输出结构体成员a的数据
//答案B B的*优先级低于.  所以没有先解引用 不行
/*
A. a.a 
B. *p.a   
C. p->a
D. (*p).a
*/
//struct S 
//{
//	int a;
//	int b;
//};
//int main() 
//{
//	struct S a, * p = &a;//创建结构体变量a,创建指针变量 p指向结构体变量啊
//	a.a = 99;//结构体变量.结构体成员 = 99;
//	printf("%d\n",p->a);
//	return 0;
//}

//下面程序输出的结果是
//struct stu 
//{
//	int num;
//	char name[10];
//	int age;
//};
//
//void fun(struct stu* p) 
//{
//	printf("%s\n",(*p).name);//第二行的地址解引用访问name 结果是雀氏率
//	return;
//}
//int main() 
//{
//	//结构体成员初始化
//	struct stu students[3] =
//	{   {9801,"张三",20},
//		{9802,"雀氏率",25},
//		{9803,"我想啸",25}
//	};
//	fun(students + 1);//数组名是首元素地址 这里是第一行的地址
//	//第一行的地址+1等于第二行的地址 传过去之后
//	return 0;
//}

//编程题 20块钱 一块钱一瓶水 俩个空瓶子换一瓶水 可以喝多少瓶水
// 规律  在大于1时
// 喝的瓶数 = 2*money -1;
//int main() 
//{
//	//先买俩瓶 此后换一瓶 买一瓶, 再换一瓶 再买一瓶 一直到没钱
//	int a = 0;
//	scanf("%d", &a);//总共的钱数
//	int b = 0;//喝了多少瓶
//	int c = a - 2;
//	int d = b + 2;
//	int i = 0;
//	if (a > 1)
//	{
//
//		for (int i = 0; i < c; i++)
//		{
//			d = d + 2;
//		}
//		d = d++;
//		printf("%d\n", d);
//	}
//	else
//	{
//		printf("就喝一瓶");
//	}
//	
//}


//先买20瓶 再换 再喝 再换..
//int main() 
//{
//	int money = 0;
//	int total = 0;//喝了多少瓶
//	int empty = 0;//空瓶数量
//	scanf("%d", &money);
//	total = money;
//	empty = money;//
//	while (empty >= 2) //空瓶大于2 继续换
//	{
//		total += empty / 2;//喝的瓶数是空瓶数除以2
//		empty = empty / 2 + empty % 2;//剩下空瓶数量 是空瓶数除2的数+余数
//	}
//	printf("total = %d\n",total);
//	return 0;
//}

//输入一个整数数组,实现一个函数 来调整数组中数字的顺序使得奇数位与数组的前半部分。
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
////从左边开始找一个偶数
////从右边开始找一个奇数
////把他们交换
//move(int arr[],int sz) 
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		//从左边找偶数
//		while ((left<right) && arr[left] % 2 == 1)//这里加上left<right 防止全是偶数越界
//		{
//			left++;
//		}
//		//从右边找奇数
//		while ((left<right) && arr[right] % 2 == 0)
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//	
//
//}
//int main() 
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr,sz);
//	print(arr, sz);
//	return 0;
//
//}

//程序的执行结果是什么
//int main()  
//{
//	unsigned char a = 200;//值的范围是0-255 11111111 
//	unsigned char b = 100;
//	unsigned char c = 0;
//	//00000000 00000000 00000000 11001000 200 A
//	//11001000 200放到a里
//	//00000000 00000000 00000000 01100100 100 B
//	//011001000 100放到b里
//	//a+b: 11001000
//	//	   01100100
//	//c 
//
//
//	c = a + b;//发生整型提升A+B = 00000000 00000000 00000001 00101100 在截取8位 00101100给c 运算就要整型提升 最后赋给c
//	//当直接打印a+b时 不需要在取8位直接打印 00000000 00000000 00000001 00101100 正数 原反补相同直接算出值
//	//c为00101100
//	printf("%d %d",a+b,c);//300 44
//	return 0;
//}


//大端存储下 b的值是多少
//int main() 
//{
//	unsigned int a = 0x1234; //0x 00 00 12 34  大端字节序存储 00 00 12 34 小端字节序存储 34 12 00 00 俩个十六进制位是一个字节
//	unsigned char b = *(unsigned char*)&a;//取地址a后强转成unsigned char* 在解引用 只能访问一个字节的空间也就是00 
//	printf("%d\n",b);//52 由于当前编辑器是小端存储 所以是34 然后转十进制 是 52 
//
//	return 0;
//}
////b的值是0