#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include "train.h"
#include<assert.h>
//����һ���Ǹ����� ��ӡ�����������֮�� �ݹ�ʵ��
//int DigitSum(unsigned int num)
//{
//	if (num > 9)
//	{
//		return DigitSum(num / 10) + num % 10;//��777 return 77 �ݹ��ȥ 7 �ݹ���� ����+num%10  ���ζ���7+7+7 �ٷ���ret���� ���
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

//�ݹ�ʵ�ּ���n��k�η�
//double Pow(int n, int k) 
//{
//	if (k < 0)
//		return (1.0 / Pow(n, -k));
//	else if (k == 0)
//		return 1;
//	else
//		return n * Pow(n, k - 1);//���ӳ��� n^k ������k��n����� Ҳ����n*n^k-1 Ȼ�����0 . һֱ��n^k������ �����Ƿ���..
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

//�ṹ�� �ṹ����һЩֵ�ļ���,��Щֵ��λ��Ա����,�ṹ���ÿ����Ա�����ǲ�ͬ���͵ı���.

//struct Stu //struct Stu �ṹ������ 
//{
//	//��Ա����
//	char name[20];
//	short age;  //�������������һ���ṹ������
//	char tele[12];
//	char sex[5];
//}s1 , s2 , s3;//s1,s2,s3 ������ȫ�ֵĽṹ����� ������ʹ�����ַ�ʽ
//int main()
//{
//	struct Stu s;//�����ṹ�����
//	return 0;
//}


//typedef struct Stu // typedef ��������������
//{
//	//��Ա����
//	char name[20];
//	short age;  
//	char tele[12];
//	char sex[5];
//}Stu;//�����Stu������
//int  main()
//{
//	Stu s1 = {"����",20,"15249287076","��"};//��ʼ���ṹ�����
//	struct Stu s2 = {"����",21,"121321231","ȸ��"};
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
//	struct S s;//Ƕ�׽ṹ��
//	char* pc;
//};
//int main() 
//{
//	char arr[] = "hello bit\n";
//	struct T t = { "hehe",{100,'w',"helloworld",3.14},arr};//Ƕ�׽ṹ��ĳ�ʼ��
//	printf("%s\n",t.ch);//hehe
//	printf("%s\n", t.s.arr);//hello world
//	printf("%lf\n", t.s.d);//3.140000 �ṹ��ķ�����ʽ
//	printf("%s\n", t.pc);//hello bit ��.���������ʽṹ���Ա
//	return 0;
//}

//�ṹ�崫��
//typedef struct Stu // typedef ��������������
//{
//	//��Ա����
//	char name[20];
//	short age;  
//	char tele[12];
//	char sex[5];
//}Stu;
//void Printf1(Stu tmp)//�� 
//{
//	printf("name:%s\n",tmp.name);
//	printf("age:%d\n",tmp.age);
//	printf("tele:%s\n", tmp.tele);
//	printf("sex:%s\n", tmp.sex);
//
//}
//����ķ������� ���ÿ��ٿռ� ʡʱ�� Ҳ����ѹջ �������־������� �����Ǳ������ʱ��
//void Printf2(Stu* ps)//��
//{
//	printf("name:%s\n",ps->name);
//	printf("age:%d\n", ps->age);
//	printf("tele:%s\n", ps->tele);
//	printf("name:%s\n", ps->sex);
//
//}
//int main() 
//{
//	Stu s = {"����",40,"15965411","��"};
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


//�о��׳�û����ȷ���е�ԭ��
//int main() 
//{
//	int i = 0;
//	int sum = 0;
//	int n = 0;
//	int ret = 1;
//	scanf_s("%d", &n);
//	for ( i = 1; i <=n; i++)
//	{
//		//ret = 1; ͨ�������ҵ�bug retû�г�ʼ��Ϊ1
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

//�ó����Ǹ���ѭ�� ԭ��������Խ����
//ջ����Ĭ��ʹ��
//��ʹ�øߵ�ַ�Ŀռ䣬��ʹ�õ͵�ַ���Ŀռ�
//�ڲ�ͬ�Ļ����ͱ��������ڴ�Ĳ����в��� ����ռ���в��� ��ѭ��������Ҳ�в���

//��ѭ������:
//main�����ڲ�������i��arr���� ���������Ǿֲ����� �ֲ����������ջ�� ����ջ��Ĭ��ʹ��ϰ����:��ʹ�øߵ�ַ�Ŀռ䣬��ʹ�õ͵�ַ���Ŀռ�
//����iһ�� ��arr���Ϸ����� ���������±����� ��ַ�ɵ͵������� ����������ʵ����Խ�� �Ϳ�����Խ��Ĺ���������i(��ʱ�����arr[12]�ĵ�ַ��i��ͬ) 
//�ڸı�����Ԫ��ʱ �п���Խ���i��ֵҲ�ı��� Ҳ�͸ı���ѭ������ �����ѭ��������

//int main()
//{
//	int i = 0;//��仰�ŵ�arr�������� �Ͳ��������ѭ���� �������ɻᱨԽ����� ��Ϊ��ʱi�ĵ�ַ��arr����
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for ( i = 0; i <=12; i++)
//	{
//		printf("�Ǻ�\n");
//		arr[i] = 0;//C6201 Խ��  VS��������i������������� �м��������Ԫ�� ����Ҫi<=12  11�ͱ���(����ԭ���Ǳ�������ȡ���˳��������Ԫ��) 
//		//12����ȫ������ѭ��  Ϊʲô������ ��Ϊ��������æ��ѭ��
//	}
//	system("pause");
//	return 0;
//}

//���� ��һ������ת��Ϊ�޷�����ʱ(����) ����������Ĳ���(��������λ)����ԭ��ת����10���Ƽ��Ǵ� ��Ϊ�������ת���޷���ʱ ���ķ���λ1Ҳһ�������
//
//int main()
//{
//	short i = -32767;
//	unsigned short si = i;
//	printf("%d",si);//32769
//	return 0;
//
//}

//���������
//int main() 
//{
//	while (1) 
//	{
//		if (GetAsyncKeyState(VK_SPACE))//���¿ո�ʼִ��
//		{
//			while (1) 
//			{
//				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0 ,0, 0, 0);
//				Sleep(0.01);//ÿ0.001s���һ��
//				if (GetAsyncKeyState(VK_ESCAPE)) return 0;//��ESC�˳�
//			}
//			
//		}
//	}
//	return 0;
//}


//6���㷨 ����ʮ��
//void my_strcpy(char* dest ,char*src) 
//{
//	while (*src != '\0')
//	{
//
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;//��ѭ��ͣ����ʱ ��\0 copy�� arr1����
//}

// 7���㷨  
//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)//
////��src��ֵ��\0ʱ ���� dest�� destΪ\0 ѭ������
////�ж�������ÿ�� *dest��ֵ �ȸ�ֵ ���ж� ��++
//	{
//		;
//	}
//
//}

//8���㷨
//#include<assert.h>
//void my_strcpy(char* dest, char* src)
//{
//	assert(dest != NULL);//���� ��dest == NULL�ͻᵯ��������Ϣ
//	assert(src != NULL);
//	while (*dest++ = *src++)//
//
//	{
//		;
//	}
//}

////9��
//#include<assert.h>
//void my_strcpy(char* dest, const char* src)//const����src��ֵ����ı�
//{
//	assert(dest != NULL);//���� ��dest == NULL�ͻᵯ��������Ϣ
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}

//10��
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)//const����src��ֵ����ı�
//{
//	char* ret = dest;//��dest��ret  ��ʽ����
//	assert(dest != NULL);//���� ��dest == NULL�ͻᵯ��������Ϣ
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;//����ret �൱���ٴε�����char* ret = rest;
//}
//int main() 
//{
//	//strcpy
//	//�ַ�������
//	char arr1[] = "#############";
//	char arr2[] = "bit";
//	//strcpy(arr1,arr2);//��arr2��ֵȫ��������arr1 ����/0 ��ӡ��bit
//	//my_strcpy(arr1, arr2);//�����ǵ�ַ ��ָ�����
//	//printf("%s\n",arr1);//����/0ֹͣ��ӡ
//	
//	printf("%s\n", my_strcpy(arr1, arr2));//�㷨ʮר�ô�ӡ
//	return 0;
//}


//const���� �����޸�const���͵�ֵ ����
//int main() 
//{
//	const int num = 10;
//	int n = 100;
//	const int* p = &num;
//	//const ����ָ�����*�����ʱ,���ε���*p��Ҳ����˵:����ͨ��p���ı�*p(num)��ֵ
//	//*p = 20;//����:���ʽ�����ǿ����޸ĵ���ֵ
//	//p = &n;//�������
//	
//	int* const p = &num;
//	//const ����ָ�����*���ұ�ʱ,���ε���p����p���ܱ��ı���.
//	//*p = 20; //�������
//	//p = &n;  //����:���ʽ�����ǿ����޸ĵ���ֵ
//	const int* const p = &num;//*p ��p���Ĳ�����
//	printf("%d",num);
//	return 0;
//}

//�����ַ������ȼ���
//int my_srtlen(const char* str) //const ����strָ���ַ������(��׳��)
//{
//	int count = 0;
//	assert(str != NULL);//��ָ֤�����Чֵ
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

//�˷��ھ���
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
//	scanf_s("%d %d", &i, &j);//��������  ����
//	MultiTable(i, j);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	float f = 10.0;
//
//	short a = 10; //��
//	short int b = 10;//�� �����﷨һ�� int��ʡ��
//
//	return 0;
//}

//дһ�δ���������ǵ�ǰ�������ֽ�����ʲô
//��������Զ���С�˴洢 �����ŷ�
//int main() 
//{
//	int a = 1;
//	char* p = (char*)&a;//a������ �ַ���ȡ���ͻᱨ�� ǿתһ�� ȡ�Ļ���a�ĵ�ַ 
//	//Ϊɶ��char�� ��Ϊchar��һ���ֽ� ��ʮ�����ƾ�����λ��  01 00 00 00
//	//����a=1��˵ֻ��Ҫ�жϵ�һ���ֽ��Ƿ���1������ 
//	if (*p == 1)
//	{
//		printf("С��");
//	}
//	else
//	{
//		printf("���");
//	}
//	return 0;
//}

//д�ĺ�һ��
//check_sys() 
//{
//	int a = 1;
//	char* p = (char*)&a;
//	return *p;//����ֱ�ӷ���*p *p��0�ͷ�0 ��1�ͷ�1
//}
//�ٺ�һ��
//check_sys()
//{
//	int a = 1;
//	return (char*)&a;//ֱ�ӷ���&a �����õ�ֵ
//}
//int main() 
//{
//	//дһ�δ���������ǵ�ǰ�������ֽ�����ʲô
//	//����1,С��
//	//����0�����
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}

//���ʲô
//int main()
//{
//	char a = -1;
//	//100000000000000000000000000000001 ԭ
//	//111111111111111111111111111111110 ��
//	//111111111111111111111111111111111 ��
//	signed char b = -1;
//	unsigned char c = -1; //�޷���������������0 ��ǰ�油
//	//0000000000000000000000000 11111111 255
//	printf("a=%d,b=%d,c=%d",a,b,CE_BREAK);//-1 -1 255
//}


//�з��ŵ�char��Χ��-128 ->127
//�޷��ŵ�char��Χ��0->255 ����ķ���λҲ����
//�з���->�޷��� ��תΪ���� ����������λ����
//int main() 
//{
//	char a = -128;
//	//10000000 000000000 00000000 10000000 ԭ     //����λ������ǰ��
//	//11111111 111111111 11111111 01111111 ��
//	//11111111 111111111 11111110 10000000 ��
//	//10000000
//	//��������11111111 111111111 11111110 10000000  �޷�������ԭ�뷴�벹����ͬ
//	//�������������
//	printf("%u\n", a);//%u��ӡʮ���Ƶ��޷�������
//	return 0;
//}

//int main() 
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n",i+j);//-10
//// -20
////10000000 00000000 00000000 00010100 ԭ
////11111111 11111111 11111111 11101011 ��
////11111111 11111111 11111111 11101100 ��
////+
////10
////00000000 00000000 00000000 00001010 ԭ �� ��
////= 
////11111111 11111111 11111111 11110110 ��
////10000000 00000000 00000000 00001010 ԭ   -10
//
//}



//�κ�һ�����ַŵ�char�Ͷ��ᱻת����-128-127�����Χ�� 
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
//	//char�Ķ����� 127ʱ�ټ�1 �ͱ�Ϊ-128  ͬ�� -128 -1 = 127
//	printf("%d", strlen(a));//-1 -2 ... -128 ->127 126 ...0  strlen����0��ֹͣ ������255���ַ�����
//	return 0;
//}

//��ӡ������� //û�����ֵ�λ��Ĭ����0 ÿ����������һ�е��ٽ����������
// �������������������
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
//	int i = 0;//��
//	int j = 0;//��
//	for ( i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++) 
//		{
//			if (j == 0)//�����һ��Ϊ0
//			{
//				arr[i][j] = 1;//��һ�и�Ϊ1
//			}
//			if (i ==j)//�Խ���ȫΪ1
//			{
//				arr[i][j] = 1;
//			}
//			if (i >= 2 && j >= 1)//ʵ���ϴӵ����еڶ��вſ�ʼ����
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	//��ӡ
//	for ( i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++) //j<=i ����������������������� ���� ����С��������ӡ����
//		{
//			printf("%d ",arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//��Ŀ����:������ 
//����Ϊ4�����ɷ��Ĺ���
//A˵:������             
//B˵:��C
//C˵:��D
//D˵:C�ں�˵
//һֱ3����˵���滰,һ����˵�˼ٻ� д�������ж�����

//int main() 
//{
//	int killer = 0;
//	for ( killer = 'a'; killer <= 'd';killer ++)//ѭ���Ĵ� a b c d
//	{
//		//��һ��ѭ��killer ='a',if����Ϊ0 + 0 + 0 +1 = 1
//		//�ڶ���ѭ��killer = 'b',if����Ϊ 1 + 0 + 0 + 1 = 2
//		//������ѭ��killer = 'c',if����Ϊ1 + 1 + 0 + 1 = 3  ����if�������д�ӡ ��ӡkiller='c'
//		//���Ĵ�ѭ��killer = 'd',if����Ϊ1 + 0 + 1 + 0 = 2
//		if ((killer != 'a')+ (killer == 'c')+ (killer == 'd')+ (killer != 'd') == 3)  //�����3 ����3�����Ϊ�棬һ������Ϊ��
//		{
//			printf("killer = %c\n",killer);//%c��ӡ�ַ���
//		}
//	}
//	return 0;
//}