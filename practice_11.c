#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<malloc.h>
#include<errno.h>
//C�����ǿ��Դ����䳤���� -C99��׼ ���ǲ���ÿ���������֧�� ����vs�����ڰ汾�Ͳ�֧��
//gcc��������������
//int main() 
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n];//vs��������֧������д ����:���ʽ�б��뺬�г���
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

//��̬�ڴ���� �ڶ�������ռ�
////INT_MAX �������ֵ
////malloc(��̬�ڴ濪�ٺ���) ����һ���������õĿռ�
////���ٳɹ�����һ��ָ�򿪱ٺÿռ��ָ�룬����ʧ�ܷ���һ��NULLָ��
//int main() 
//{
//	//���ڴ�����10�����εĿռ� p�ŵľ������ռ�ĵ�ַ
//	int* p = (int*)malloc(10 * sizeof(int));//malloc������void*�� Ҫǿתһ�� ����ʮ�����ʹ�С
//	if (p == NULL) 
//	{
//		//��ӡ����
//		printf("%s\n",strerror(errno));//ʧ�ܻ�Ѵ�����Ϣ�ŵ���������
//		//����strerror�����Ѵ���������Ӧ�Ĵ�����Ϣ��ӡ����
//	}
//	else 
//	{
//		//����ʹ�ÿռ�
//		int i = 0;
//		for ( i = 0; i < 10; i++)
//		{
//			*(p + i) = i;//�±�Ϊi��Ԫ�ظ�ֵ��i
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ",*(p+i));
//		}
//	}
//	//����̬����Ŀռ䲻��ʹ�õ�ʱ��
//	//��Ӧ�û�������ϵͳ
//	free(p);//�������й������ͷſռ� �����ͷ���ɺ�pָ�뻹�����ҵ����ռ�
//	p = NULL;//���԰�pָ��ָΪ��
//	return 0;
//	//��������Զ��ͷſռ仹������ϵͳ 
//}


//malloc �����ʼ���ռ� ����malloc��Ч�ʸ��� �ǿ�ռ��ֵ����cd(���ֵ) 
//calloc ��ѿռ��ʼ��Ϊ0
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


//realloc���� ������̬�����ڴ�ռ�Ĵ�С
//1 ���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷�ӣ���ֱ��׷�Ӻ�,����p�ĵ�ַ
//2 ���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷��,��realloc������������һ���µ��ڴ�����
// ����һ����������Ŀռ�,���Ұ�ԭ���ڴ��е����ݿ����������ͷžɵ��ڴ�ռ�
// ��󷵻ؿ��ٵ��ڴ�ռ��ַ
//3 ����һ���µ�ָ�����������realloc�����ķ���ֵ 
//int main() 
//{
//	int* p = (int*)malloc(20);//����20���ֽ�
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
//	int* ptr = realloc(p, 40);//�����ǵ��ؿռ��ַ ������СΪ:40���ֽ�
//	if (ptr != NULL)//�ڴ����ʧ�ܾͻ᷵�ؿ�ָ�� ����һ��Ҫ�ж�һ��
//	{
//		p = ptr;//���ڴ�ռ�����ɹ� �ٰѵ�ַ��ԭָ��p
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


//realloc Ҳ����ֱ�ӿ��ٿռ�
//int main()
//{
//	int* p = ralloc(NULL, 40);//��mallocһ����
//	return 0;
//}

//�����Ķ�̬�ڴ���� 
//1.��NULLָ������ò���
// int main() 
//{
//	int* p = malloc(40);
//	*p = 10;//malloc���ٿռ�ʧ��- ��NULLָ�������
//	return 0;
//}
 

//2.�Զ�̬���ٵ��ڴ��Խ�����
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
//		for (i = 0; i < 10; i++)//ֻ������5���ռ� Խ�����ʮ���ռ�
//		{
//			*(p + i) = i;
//		}
//	}
//	free(p);
//	p = NULL;//���������
//}

//3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//int main() 
//{
//	int a = 10;//a��ջ���ٿռ��
//	int* p = &a;
//	free(p);//�ͷŶ�̬�ڴ��Ƕ��ϵ� �����ͷ�ջ�ľ�̬�ռ� ����
//	p = NULL;
//	return 0;
//}

//4.ʹ��free�ͷŶ�̬�����ڴ��һ����
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
//	free(p);//pָ���λ�� �Ѿ��ı��ˣ� �����ͷ�p�ı����ڴ� ����
//	//�����ͷ�����ռ�ĵ�ַ 
//	p = NULL;
//	return 0; 
//
//}

//5.��ͬһ�鶯̬�ڴ�Ķ���ͷ�
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL) 
//	{
//		return 0;
//	}
//	free(p);//pָ���λ�� �Ѿ��ı��ˣ� �����ͷ�p�ı����ڴ� ����
//	//�����ͷ�����ռ�ĵ�ַ 
//	p = NULL;
//  free(p);//��ǰ��û��p=NULL;����д��ֱ�ӱ��� free����NULL������
//	return 0; 
//
//}

//6.��̬�����ڴ� �����ͷŵ���(�ڴ�й©)
//�мǶ�̬���ٵĿռ�һ��Ҫ�ͷ� �����Ǵ�����Ŀ ���Ƿǳ����ص�bug
//�ᵼ�µ��Կ���
//#include<windows.h>
//int main()
//{
//while (1) 
//{
//	malloc(1);
//	//�����ڴ���� ���Կ������������
//}
//	return 0; 
//}

//������ �����������н����ʲô ���:�������
//void GetMemory(char* p)//����һ����ָ��
//{
//	p = (char*)malloc(100);//��p��ֵ ���տ��ٵĿռ�
//	//���տ��ٵĿռ�� �뿪���� pʧЧ ��Ҳ�Ҳ�����鿪�ٵĿռ�
//	//δ�ͷſռ� �ڴ�й©
//
//}
//void Test(void) 
//{
//	char* str = NULL;//str ָ���ָ��
//	GetMemory(str);//����ȥһ����ָ�� �����������ʱstr��û�б��ı� 
//	strcpy(str, "hello world");//��hello world������str�� str�ǿ�ָ��
//	//û��ָ����Ч�ռ� strcpy����һֱ�ҿռ� �����ҵ���Ҳ�ǷǷ����ʿռ� �������
//	printf(str);//����д��û��ë�� ֱ�ӷŵ�ַҲ���Դ�ӡ
//}
//int main() 
//{
//	Test();
//	return 0;
//}

//������ʽһ
//void GetMemory(char ** p)//�ö���ָ�����һ��ָ��ĵ�ַ
//{
//	*p = (char*)malloc(100);//pָ�� ���տ��ٵĿռ�
//
//}
//void Test(void)
//{
//	char* str = NULL;//str ָ���ָ��
//	GetMemory(&str);//����ȥһ��һ��ָ��ĵ�ַ 
//	strcpy(str, "hello world");
//	printf(str);//����д��û��ë�� ֱ�ӷŵ�ַҲ���Դ�ӡ
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//������ʽ��
//char* GetMemory(char* p)//����һ����ָ�� ����һ��char*�ĵ�ַ
//{
//	p = (char*)malloc(100);
//	return p;//��������p��ֵ
//}
//void Test(void)
//{
//	char* str = NULL;//str ָ���ָ��
//	str = GetMemory(str);//����ȥһ����ָ�� ���ص�p��һ��ֵ���� 
//	strcpy(str, "hello world");//��hello world������str�� str�ǿ�ָ��
//	printf(str);//����д��û��ë�� ֱ�ӷŵ�ַҲ���Դ�ӡ
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//��������ִ�н����ʲô
//char* GetMemory(void)//����һ����ָ�� ����һ��char*�ĵ�ַ
//{
//	char p[] = "hello world";
//	return p;//��������p��ֵ
//}
//void Test(void)
//{
//	char* str = NULL;//str ָ���ָ��
//	str = GetMemory();//����p�ĵ�ַ �������������ԭ��p��ֵ�Ѿ����ͷ���
//	printf(str);//���Խ��յ�ָ��ָ�����ֵ(�Ƿ�����)
//}
//int main()
//{
//	Test();
//	return 0;
//}

//int* test(void)
//{
//	int a = 10;//ջ�� ��ǰ��Ӹ�static������ �ı����������� �ŵ���̬��
//	return &a;
//}
//int main() 
//{
//	int* p = test();//a��ֵ�ں���ִ�к��Ѿ��������� ָ��ָ�����ֵ �Ƿ�����
//	*p = 20;
//	return 0;
//}

//int* test() 
//{
//	int* ptr = malloc(100);//���� �����������ٸÿռ�
//	return ptr;
//}
//int main() 
//{
//	int* p = test();//p������ȷָ����鿪���ڶѿռ��ϵĿռ�
//	return 0;
//}

//������ C++/C ��� �Ȿ�鲻��
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
//	printf(str);//���Դ�ӡ���� ��û���ͷſռ� �����ڴ�й©
//	//��
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
//		strcpy(str, "world");//���ͷŵĿռ��ǿ�и��ǵ� �Ƿ������ڴ�
//		//������free�����ͷſռ� �����ָ��ÿռ��ָ����Ϊ�� 
//		printf(str);
//	}
//}
//int main() 
//{
//	Test();
//	return 0;
//}

// C/C++������ڴ濪��
//ջ��(��������) ��žֲ����� ִ�����Զ��ͷ�
//����(��������) malloc calloc realloc ���ٵĿռ䶼�ڶ��� �������ʱ�����ɲ���ϵͳ����
//���ݶ�(��̬��) ���ȫ�ֱ�������̬(static)���� �����������ϵͳ�ͷ�
//����� ����ε������ǲ��ܸĵ� ���ִ�д��� ֻ������(�����ַ���һ��� ���ɱ��޸�)

//�������� д��
//���������ص�
//�ṹ�е����������Աǰ�����������һ��������Ա
//sizeof���ص����ֽṹ��С����������������ڴ�
//�������������Ա�Ľṹ��malloc()���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ���ڽṹ��Ĵ�С
//����Ӧ���������Ԥ�ڴ�С��
//C99��׼�� �ṹ���е����һ��Ԫ������ʱδ֪��С�����飬��ͽ������������Ա��
//struct S 
//{
//	int n;
//	int arr[];//δ֪��С��-����Ĵ�С�ǿ��Ե�����
//	//int arr[0]����дҲ��
//};
//int main() 
//{
//	//struct S s;
//	//printf("%d\n",sizeof(s));//4 ����ṹ���Ա��Сʱ ��������������
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 *sizeof(int));//5*sizeof(int)������������Ĵ�СΪ5������
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++) 
//	{
//		ps->arr[i] = i;//0 1 2 3 4
//	}
//	struct S* ptr = realloc(ps, 44);//���� ǰ4���ֽ���n�Ĵ�С ����Ķ�����������ĵĴ�С
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
//	//�ͷſռ�
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//�ڶ���д�� �ǳ���д�� Ҫ�������οռ� �ͷ����οռ� д�������׳��� 
//struct S 
//{
//	int n;
//	int* arr;
//};
//int main() 
//{
//	struct S* ps = malloc(sizeof(struct S));//����һ���ṹ���С�Ŀռ� �������n��arr
//	ps->arr = malloc(5 * sizeof(int));//�����濪���м������arrָ���ٿ���һ�� arrָ�����ռ�
//	int i = 0;
//	for (i = 0; i < 5; i++) 
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 5; i++) 
//	{
//		printf("%d\n",ps->arr[i]);
//	}
//	//������С
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
//	//�ͷű������ͷ�arr�Ŀռ� �����ͷŽṹ��Ŀռ�(arr����) ���Ҳ���arr���ָ������Ŀռ���
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//malloc���ٿռ� �������о������￪ û��ʲô���� �����ٿռ����������ʹ��С�ռ�(�ڴ���Ƭ)
//���Կ��ٴ���Խ��Խ�� ��������ڴ��ʹ���� �����ڴ����ʶ���������ȡ����
//�ڴ�����ݷŵ����ٻ��� ���ٻ����ڷŵ��Ĵ��� cpu�ڴӼĴ�����������
//�ֲ���ԭ��:������ĳ���ڴ�����ʱ����������������ݴ���ʻ����������ݸ������ڴ� 
//����:�������1������2���ŷ� �����׶�ȡ����1ʱ�����ȡ������2 ��CPU�����ʸ�
//Ҳ����˵�ռ������Ը� ��ȡ�ٶȿ�

//�ļ�����(�����ļ�)
//�����ļ���Դ�����ļ�.c (��windows������) Ŀ���ļ�.obj ��ִ�г���.exe �����ļ����Բ��������ļ�
//�����ļ�����������ʱ��д������ 
//�ļ���:�ļ�·��+�ļ�������+�ļ���׺
//�ļ�����:�ı��ļ�(���ܿ������ļ�,�ŵĶ����ַ� )��������ļ�(�򿪶�������) �������ڴ����Զ����Ƶ���ʽ�洢���������ת�����1����棬���Ƕ������ļ�
//��ASCII�ַ�����ʽ�洢���ļ������ı��ļ�
//һ���������ڴ�������ô�洢��?
//�ַ�һ����ASCII��ʽ�洢����ֵ�����ݼȿ�����ASCII��ʽҲ�����ö�������ʽ�洢��
//����:10000 ��ASCII�洢 ���� һ���ַ�һ���ֽ� 1 0 0 0 0 
//�Զ����ƾ���4���ֽ� 10 27 00 00(16������ʾ) ʵ�ʴ��˳��00 00 27 10

//int main() 
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");//�Զ�����д�ķ�ʽ�򿪸��ļ� û�и��ļ����Զ�����
//	fwrite(&a, 4, 1, pf);//дa�����ݽ�ȥ������Դ�� д�����ֽ� д�������� ���λ��
//	fclose(pf);
//	pf = NULL;
//	return 0;
//
//}
/*
�����ļ�ϵͳ:
����������->���������->���->���� (��������������˲ŷų�����)
����->����->���뻺����->����������
�ļ�����ָ�룬����ļ�ָ��:ÿ����ʹ�õ��ļ������ڴ��п�����һ����Ӧ���ļ���Ϣ�����������
�ļ��������Ϣ(�����ļ�������,�ļ���ǰ��λ��)��Щ��Ϣ�Ǳ�����һ���ṹ������еġ���
�ṹ����������ϵͳ�����ģ�ȡ��FILE(�Ҽ�ת������)
*/

//�ļ��Ĵ򿪺͹ر�  r ֻ�� wֻд a ׷�� rb ������ֻ�� wb ������ֻд 
// ����д���ļ�ʹ�÷�ʽ ����û���ļ�ʱ�Զ��������ļ�
//��fopen����

//int main() 
//{
//	//..��ʾ��һ��·�� ��һ����ʾ��ǰ·��
//	//���ļ�test.txt
//	//fopen("../../","r");//���·��
//	//fopen("D:\\2019 v\\Project\\Firstproject\\test.txt", "wb");//����·�� \ת��\ȷ���ڶ���\����ת�������ַ�
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL) 
//	{
//		printf("%s\n" ,strerror(errno));
//	}
//	//�򿪳ɹ�
//	//���ļ�
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main() 
//{
//	FILE* pfRead = fopen("TEST.txt","w");//���ļ�
//	if (pfRead == NULL) 
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	//���ļ�
//	printf("%c", fgetc(pfRead));
//	//�ر��ļ�
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}

//���ļ�
//���� - ��׼�����豸(stdin FILE*)
//��Ļ - ��׼����豸(stdout FILE*)
//�ļ�               (stderr FLIE*)
//����Ĭ�ϴ��������豸
//int main() 
//{
//	int ch = fgetc(stdin);
//	fputc(ch, stdout);//һ��ֻ��һ���ַ��ַ��Ĵ�ӡ����Ļ��(��ӡ�����������)
//	return 0;
//}

//fgetc���� ��fputc����
//int main() 
//{
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	//д�ļ� ������FILE��һ�е�r��Ϊw 
//	//fputc('b',pf);
//	//fputc('i',pf);
//	//fputc('t',pf); 
//	//���ļ�
//	int ch = fgetc(pf);
//	printf("%c",ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fgets���� ��puts����
//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
////���ļ�
//	fgets(buf, 1024, pf);//����ŵ�buf�� ��1024���ֽ� ��ȡpfָ����ļ�
//	//�������һ�ζ�һ��
//	//printf("%s",buf);
//	puts(buf);//������������Դ�\n  �Ǹ��������
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
////�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fput����
//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt","w");
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	//д�ļ�
//	fputs("hello\n",pf);
//	fputs("world\n",pf);
////�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fgets����
//int main() 
//{
//	//�Ӽ��̶�ȡһ���ı���Ϣ
//	char buf[1024] = { 0 };
//	//fgets(buf, 1024, stdin);//�ӱ�׼��������ȡ ����ʲô
//	//fputs(buf, stdout);//�������׼����� �����ӡʲô
//	gets(buf);//�������е�ͬ��������
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
//	FILE* pf = fopen("test.txt","w");//ע��:д���Ƕ� ��˫����������
//	if (pf == NULL)
//	{
//		printf("%s\n",strerror(errno));
//		return 0;
//	}
//	//��ʽ������ʽд�ļ� �ŵ�pf����
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
//	FILE* pf = fopen("test.txt", "r");//ע��:д���Ƕ� ��˫����������
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//��ʽ������������ �ŵ�pf����
//	//fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
//	//printf("%d %f %s\n", s.n, s.score, s.arr);
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);//��ͬ����������
//	fprintf(stdout, "%d %f %s", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

/*
scanf / printf ����Ա�׼������ / ��׼������� ��ʽ������ / ������
fscanf / fprintf ���������������/����������� ��ʽ������/������
sscanf / sprintf
sscanf �Ǵ��ַ����ж�ȡ��ʽ�������� 
sprintf �ǰѸ�ʽ�����������(�洢��)�ַ���
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
//	//�Ѹ�ʽ��������ת�����ַ����洢��buf
//	sprintf(buf,"%d %f %s",s.n,s.score,s.arr);
//	//printf("%s\n", buf);
//	
//	//��buf�ж�ȡ��ʽ�������ݵ�tmp��
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
//	printf("%d %f %s \n",tmp.n,tmp.score,tmp.arr);
//	return 0;
//}

//�����ƶ�д�ļ�
//struct S 
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main() 
//{
//	//struct S s = { "����",20,55.6};//д�ļ��Ľṹͼ
//	struct S tmp = { 0};//���ļ��Ľṹ��
//	//FILE* pf = fopen("test.txt","wb");//д�ļ���
//	FILE* pf = fopen("test.txt", "rb");//���ļ���
//	if (pf == NULL) 
//	{
//		return 0;
//	}
//	//�����Ƶ���ʽд�ļ�
//	//fwrite(&s, sizeof(struct S), 1, pf);//д˭  Ԫ�ش�С д���� д������ȥ
//	
//	//�����ƶ��ļ�
//	fread(&tmp, sizeof(struct S), 1, pf);
//	printf("%s %d %lf\n", tmp.name, tmp.age,tmp.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//�ļ���˳���д
//int main() 
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL) 
//	{
//		return 0;
//	}
//	//1����λ�ļ�ָ��
//	fseek(pf, 2, SEEK_CUR);//��pf ��ǰλ��(current ��ǰ��)��ʼ�� ���ƫ����λ
//	//SEEK_END �ļ����λ�� SEEK_CUR �ļ�ָ��ĵ�ǰλ�� SEEK_SET �ļ���ʼλ��
//	//����-2����ǰ����λ
//	//2.��ȡ�ļ�
//	int ch = fgetc(pf);
//	printf("%c",ch);
//	fclose(pf);
//	pf = NULL;
//}

//ftell���� ����ƫ���� rewind���� ���ļ�ָ��λ�÷Ż���ʼλ��
//int main() 
//{
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL) 
//	{
//		return 0;
//	}
//	//��λ�ļ�ָ��	`
//	fseek(pf, -2, SEEK_END);
//	int pos = ftell(pf);//ftell �����ļ�ָ�� �������ʼλ�õ�ƫ����
//	printf("%d\n",pos); 
//
//	pos = fgetc(pf);//���ַ�
//	printf("%c\n",pos);
//	 
//	rewind(pf);//�ص��ļ�ָ�����ʼλ��
//	pos = ftell(pf);
//	printf("%d\n",pos);
//	
//	pos = fgetc(pf);//���ַ�
//	printf("%c\n",pos);
//	
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//�ļ������ж�
//feof���� �������ж��ļ���ȡ������ԭ��
//ԭ��1:��ȡʧ�� ԭ��2:�ļ�������
/*
1.�ı��ļ���ȡ�Ƿ������
�жϷ���ֵ�Ƿ�ΪEOF(fgetc)
����NULL(fges) fges

2�������ļ��Ķ�ȡ�����жϣ��жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���
*/

//int main() 
//{
//	//EOF: END OF FILE �ļ������ı�־
//	FILE* pf = fopen("test.txt","r");
//	if (pf == NULL)
//		return 0;
//	int ch = fgetc(pf);//���ļ�Ϊ��ʱ�᷵��EOF ��EOF��������᷵��-1
//	printf("%d\n",ch);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//perror ������strerror����������
//int main() 
//{
//	//strerror - �Ѵ���������Ĵ�����Ϣ���ַ�����ַ����
//	//printf("%s\n",strerror(errno));
//	FILE* pf = fopen("test2.txt","r");
//	if (pf == NULL) 
//	{ 
//		perror("fopen��������");
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
//		perror("fopen��������");
//		return 0;
//	}
//	//���ļ�
//	int ch = 0;
//	while ((ch = fgetc(pf) != EOF))//�ж��Ƿ�Ϊ��
//	{
//		putchar(ch);
//	}
//	//����ԭ��
//	if (ferror(pf)) //�������󷵻�һ����0ֵ ����Ϊ��
//	{
//		printf("error\n");
//	}
//	else if (feof(pf))//�ж��ļ��Ƿ����
//	{
//		printf("end of file\n");
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//��ϰ��
//typedef struct 
//{
//	int a;// aռ4���ֽ� ƫ����0-3 4С��8 ��������4    0��ʼ,ռ4���ֽ�
//	char b;//bռһ���ֽ� ƫ����4  1С��8 ��������1 ƫ����3��1�ı��� ռ1���ֽ�
//	short c;//cռ�����ֽ�  ƫ����5-6 2С��8 ��������2
//	// ����5����2�ı��� �����˷�һ���ֽ� ��6��ʼ ƫ����5-7 ռ3���ֽ�
//	short d;//dռ�����ֽ� ƫ����8-9 2С��8 ��������2 ƫ����8��2�ı��� ռ2���ֽ�
//	//�ܹ�ռ10���ֽ� 
//	//4�������� �����4 �ṹ���С���������������ı��� 3*4 = 12
//	//�������ս��Ϊ12
//}AA_T;
//int main() 
//{
//	printf("%d\n",sizeof(AA_T));
//	return 0;
//}

//4�ֽڶ��� 16+12 = 28
//typedef struct A 
//{
//	int a;//0-3 4
//	short b;//4-5 2
//	int c;//6-11 6
//	char d;//12 1
//	//13 ���뵽16
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
//#pragma pack(4) //����Ϊ4�ֽڶ���
////long Ҳ��4���ֽ�
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