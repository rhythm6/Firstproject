#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
/*
C语言预编译
程序的翻译环境: .c文件变成.exe(可执行程序 是个二进制文件 里面放的是二进制代码)的过程 这个过程叫做编译(编译器)和链接(链接器)
在这个环境中源代码被转化为可执行的机器指令(二进制代码)
执行环境:运行程序所依赖的环境 用于实际执行代码
每一个源文件  ---经过编译器单独处理--->生成目标文件(.obj)
链接库--->链接器(进行处理)<---所有目标文件
          变为可执行程序  
组成一个程序的每个源文件通过编译过程分别转换为目标代码(object code)
每个目标文件由链接器(linker)捆绑在一起,形成一个单一而完整的可执行程序
链接器同时也会引入标准C函数库中任何被该程序所用到的函数，而且它可以搜索程序员个人的程序库,
将其需要的函数也链接到到程序中。
预编译->编译->汇编 这三步加起来 才是完整的编译
-----
预编译/预处理 是进行文本操作
1:#include头文件的包含 把头文件的函数都写进来
2:注释删除 使用空格来替换注释
3:#define 把那些define的值替换到相应的代码中去
最后生成 .i文件
-----
编译:把c语言代码翻译成汇编代码 .i 文件  ---编译-> .s文件(汇编代码)
1.语法分析 2.词法分析 3.语义分析 4.符号汇总
汇编.s文件-->.obj(Linux系统中是.o文件)里面都是二进制代码/指令
汇编会形成符号表:一源文件一个符号表
[函数名][函数地址(是哪个文件的)] 
[函数名][函数地址]
[函数名][函数地址]
[函数名][函数地址] 
链接: 1:会合并段表，2:符号表的合并和重定位
段表:obj文件中 是一段段存放信息的 存放格式叫elf
链接时 这些段 相匹配进行链接
符号表链接时 函数名若相同 函数地址不相同， 一定选择有效的函数地址链接
通过符号表去找函数 若合并过程中查看这个函数错误 就发生链接错误
无法解析的外部符号_函数名，该符号在函数_main中被引用

运行环境
程序执行的过程:
1.程序必须载入内存中，在有操作系统的环境中:一般这个由操作系统完成。在独立的环境中，程序的载入必须
手动操作，也可能时通过可执行代码置入只读内容来完成。
2.程序的执行刚开始，接着变调用main函数
3.开始执行程序代码，这个时候程序将使用一个运行时堆栈(stack)，存储函数的局部变量和返回地址。程序同时
也可以使用静态(static)内存，存储于静态内存的变量在程序的整个执行过程一直保留他们的值
4.终止程序。正常终止main;也有可能是意外终止

预处理详解
__FILE__ 进行编译的源文件
__LINE__ 文件当前的行号
__DATE__ 文件被编译的日期
__TIME__ 文件被编译的时间
__STDC__ 如果编译器遵循C语言标准 其值为1 否则未定义
*/
//extern + 要声明的函数 就可以使用其他文件中的函数了 这个就是链接


//int main() 
//{
//    //printf("%s\n", __FILE__);//打印出该文件的完整路径
//    //printf("%d\n", __LINE__);//打印出这行的行号
//    //printf("%s\n", __DATE__);//系统年月日 nov(十一月) 10 2021 
//    //printf("%s\n", __TIME__);//系统时间
//
//    //写日志文件
//    int i = 0;
//    int arr[10] = { 0 };
//    FILE* pf = fopen("log.txt", "w");//生成的日志文件可以去目录看
//
//    for ( i = 0; i < 10; i++)
//    {
//        arr[i] = i;
//        fprintf(pf,"file:%s line:%d date:%s time:%s i=%d function:%s\n", __FILE__,__LINE__,__DATE__,__TIME__, i,__FUNCTION__);
//    }
//    fclose(pf);
//    pf = NULL;
//    for ( i = 0; i < 10; i++)
//    {
//        printf("%d",arr[i]);
//    }
//    return 0;
//}

//int main() 
//{
//    printf("%d\n",__STDC__);//vs编译器不支持这个C语言标准 GCC支持
//    return 0;
//}

/* 
#开头的指令都叫预处理指令
 #define #include  设置对齐数#pragma pack(4)  取消对齐数#pragma
 #if 
 #end
 #endif
 #ifdef
 #line

 #define 可以定义标识符 #define MAX 100
 定义宏 
*/
//#define do_forever for(;;)//是一个死循环
//int main() 
//{
//    do_forever;
//}

//在define后面要不要加;
//最好不要加
//#define MAX 100;
//int main() 
//{
//    int a = MAX;
//    //int a = 100;; #dedfine 是完全替换
//    printf("%d\n", a);
//    //直接报错 MAX替换为MAX printf("%d\n",MAX);
//    return 0;
//}


/*
#define 定义宏 宏大家默认都是纯大写的
#define 包括了一个规定，允许把参数替换到文本中,这种实现通常为宏或定义宏
宏的申明方式 #define name[参数名](parament[参数列表]) stuff(函数表达式)
参数列表的左括号必须与name紧邻。如果两者之间有任何空间存在，参数列表就会被解释为stuff的一部分
用于对数值表达式进行求值的宏定义都应该用这种方式加上括号，避免在使用宏时由于参数中的操作符
或邻近操作符之间不可预料的相互作用
写宏的时候 不要吝啬小括号 否则容易出错
#define替换规则 
1在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号，如果是，他们首先被替换
2替换文本随后被插入到程序中原来文本的位置对于宏，参数名被他们的值替换。
3最后，再次对结果文件进行扫描，看看它是否包含任何由*define定义的符号，如果是，就重复上述处理过程。
宏是不能递归的 字符串常量的内容不被搜索("这里面的宏不会被替换")
取消宏 #undef 宏名  移除一个宏的定义
*/

//#define SQUARE(X) X*X  //用X*X 完全替换SQUARE(X)
//int main() 
//{
//    int ret = SQUARE(5);
//  //实际上就是这样替换 int ret = 5 * 5;
//    printf("ret = %d\n",ret);//25
//    
//    return 0;
//}

//#define SQUARE(X) X*X  //用X*X 完全替换SQUARE(X)
////修改后 #define SQUARE(X) (X)*(X) //(5+1) *(5+1) = 36
//int main()
//{
//    int ret = SQUARE(5 +1);
// // int ret = 5+1 * 5+1;
//    printf("ret = %d\n", ret);//11
//
//    return 0;
//}

//#define MAX 100
//#define DOUBLE(X) X+X
//int main() 
//{
//    int a = 5;
//    int ret = 10 * DOUBLE(MAX + MAX);//俩个MAX都进行替换
//    //int ret = 10 * DOUBLE(a);//10*5+5 = 55
//    printf("%d\n",ret);
//}

//宏的参数插入字符串中 用#
//#define PRINT(X) printf("the value of "#X " is %d\n", X) 
////这里面的#X不会被完全替换而是换成  "传进来的参数" ,"a"
//int main() 
//{
//    int a = 10;
//    int b = 20;
//    PRINT(a); //the value of a is 10
//    PRINT(b); //the value of b is 20
//
//    return 0;
//}

//##可以把位与它俩边的符号合成一个符号(连接),它允许宏定义从分离的文本片段创建标识符
//#define CAT(X ,Y ) X##Y
//int main()
//{
//    int Class84 = 2019;
//    printf("%d\n",CAT(Class,84));
//    //printf("%d\n", Class##84));//##就像是连接符
//    //printf("%d\n", Class84));//这个值就是2019
//}

/*
副作用就是表达式求值的时候出现的永久性效果
例 x+1;//不带副作用  x++;//带有副作用 副作用是改变了x的值
*/

//有副作用的宏参数 - 很危险 容易出现意料之外的结果
//#include <stdio.h>
//#define MAX(X,Y) ( (X)>(Y)? (X) : (Y) )
//int main() 
//{
//    int a = 10;
//    int b = 11;
//
//    int max = MAX(a++, b++);
//   // int max = ((a++) > (b++) ? (a++) : (b++));
//    //先判断 a++ > b++ 这个条件 然后a,b分别加1 再把b的值赋给max 然后进行b++
//    printf("%d\n",max);//目测结果 11 11 12
//    printf("%d\n",a);//实测结果12 11 13
//    printf("%d\n",b);
//    return 0;
//}

//宏和函数很相似 
//区别
//1:宏比函数在程序的规模和速度方面更胜一筹
//2:宏与类型无关 函数只能在类型合适的表达式上使用
//函数在调用时会有函数调用和返回的开销
//而宏在预编译阶段就完成了替换 就没有那么大的开销 
//宏是无法(不方便)调试的(信息差 你看到的和实际运行的不一样)
//宏时不能递归的
//宏的参数可以出现类型 函数不行，所以宏不够严谨
//新的C/C++ 标准定义了inline-内联函数 同时具备宏和函数的优点可以完全替代掉宏

//例如 
//#define SIZEOF(type) sizeof(type)
//int main() 
//{
//    int ret = SIZEOF(int);//宏可传参数
//    printf("%d\n",ret);
//    return 0;
//}

//宏某些时候很方便
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main() 
//{
//    int* p = (int*)malloc(10 * sizeof(int));
//    int* p = MALLOC(10, int);
//}
//条件编译 属于预编译 可以将语句编译或放弃 头文件里用的特别频繁 
//#define DEBUG //DEBUG定义了就可以正常执行这条语句
//int main() 
//{
//    int i = 0;
//#ifdef DEBUG
//    printf("%d\n",i);//如果DEBUG 被定义过 这条语句就参与编译 否则就不参与
//#endif
////等同于
//#if defined(DEBUG)
//    printf("一点也不累！");
//#endif
// //--------
//#if !defined(HONG)
//    printf("雀氏率");//没有定义HONG才可以参与编译
//#endif
////等同于
//#ifndef HONG
//    printf("雀氏率");
//#endif
////---------
//#if 1+1
//    printf("%d\n",i);//跟if语句类似 条件为真 这条语句就参数编译 否则不参与
//#endif
//
// //多分支条件编译 跟正常的if else if else 语句类似
//#if 1==2
//    printf("%d\n",i);
//#elif 2==1
//    printf("%d\n",i);
//#else 
//    printf("雀氏帅");
//#endif
//}

//#include<>  和#include""的区别   ""比<>查找速度慢(所以不要乱用""太多的""会导致代码编译很慢) 但是比<>查找范围大 
//#include<> 只查找库函数所在的头文件
//#include"" 现在源文件所在的目录查找若该文件未找到 再去库函数头文件的位置查找 都找不到就报错

//防止头文件重复包含 因为这是不可避免的,尤其是在大型项目中
//老方法
//在头文件中写(.h文件中)
//#ifndef __TEST_H__  //如果TEST_H(test.h)没有定义
//#define __TEST_H__  //就给它定义一下
////声明的函数  这句话符合test.h没有定义的条件 就参与编译 否则不参与, 这样写就成功的避免了,头文件被重复包含导致影响运行速度。
//#endif

//新方法 也是现在常用的方法
//#pragma once
////声明的函数

//C语言入门最后一节课 讲解习题(鹏哥YYDS)
//offsetof宏的实现 用来计算偏移量的

//#include<stddef.h>
//#define OFFSETOF(struct_name,member_name) (int)&(((struct_name *)0)->member_name)
////默认结构体初始地址为0 那结构体成语的偏移量就是当前结构体成员的地址
//struct S 
//{
//    char c1;
//    int a;
//    char c2;
//};
//int main() 
//{
//    //printf("%d\n",offsetof(struct S,c1)); //调用这个宏
//    printf("%d\n", OFFSETOF(struct S,c1)); //自己实现这个宏
//    printf("%d\n", OFFSETOF(struct S, a));
//    printf("%d\n", OFFSETOF(struct S, c2));
//}


//int main() 
//{
//    unsigned char puc[4];
//    //[00 00 00 00 ][00 00 00 00 ][00 00 00 00][00 00 00 00] 
//    //[00 00 00 10 ][00 10 10 01 ][00 00 00 00][00 00 00 00] 
//
//
//    //位段类型后面的是这个意思:      :所占字节大小
//    //若没说就要单独开辟 而且不能共用
//    struct tagPIM
//    {
//        unsigned char ucPimal;
//        unsigned char ucData0 : 1;//这一个字节中只能用一个比特位
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*pstPrimData;
//    pstPrimData = (struct tagPIM*)puc;//将数组首元素地址强制转换为结构体指针 再拿pstPrimData接收
//    //pstPrimData这个结构体指针指向这个数组的首元素地址 这个数组的每个元素都存放一个结构体
//    memset(puc, 0, 4);//设置puc的值为0 大小是4个字节
//    pstPrimData->ucPimal = 2;//10  占一个字节 放10 单独放在第一个字节
//    pstPrimData->ucData0 = 3;//011 只有1个比特位 就放1 开辟一个字节 8个比特位一起放
//    pstPrimData->ucData1 = 4;//100 只有2个比特位 就放00
//    pstPrimData->ucData2 = 5;//101 有3个比特位    放101
//    printf("%02x %02x %02x %02x\n",puc[0],puc[1],puc[2],puc[3]);//以16进制 打印俩个比特位位读取
//    //00 00是0, 00 10是2  , 00 10是 2 ,10 01 = 9  所以打印02 29 00 00
//    return 0;
//}

//联合体的大小是结构体当中最大对齐数的整数倍
//union Un
//{
//    short s[7];//2x7=14 对齐数是2
//    int n;//4 对齐数是4
//    //俩个共用一块空间大小是14 再对齐就是14+2 = 16
//};
//int main() 
//{
//    printf("%d\n",sizeof(union Un));
//    return 0;
//}

//int main() 
//{
//    union 
//    {
//        short k;
//        char i[2];
//    }*s,a;
//                                        //________
//    s = &a;//s指向a的地址 a是联合体的空间 | i[0] | i[1] |
//    s->i[0] = 0x39;
//    s->i[1] = 0x38;
//    printf("%x\n", a.k);//以k的形式往外拿 由于是同一块空间 一起拿出来
//    printf("%x %x\n",a.i[0],a.i[1]);//39 38
//    // [0x39][0x38]   0x38是低位按小端存储 应该放在低地址也就是前面 0x39放后面 16进制打印 结果是3839
//    return 0;
//}
int main() 
{
    int count = 0;
    int i = 0;
    int j = 0;
    while (i <= 2000)
    {
        if (i < 10)
        {
            if (i % 10 == 2)
            {
                count++;
            }
        }
        j = i;
        while (j > 10)
        {
            if (j % 10 == 2)
            {
                count++;
            }
            j = j / 10;
        }
        ++i;
    }
    printf("%d\n",count);
}