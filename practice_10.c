#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<assert.h>
//�ַ�������ʹ�ú�����
//C�����ж��ַ����ַ����Ĵ������Ƶ��������C���Ա���û���ַ������ͣ�����
//�ַ���ͨ�����ڳ����ַ����л����ַ������С��ַ���������������Щ���������޸ĵ��ַ���������
//��������:
//strlen
//size_t_strlen(const char* str);
//�ַ�����'\0'��Ϊ������ʾ,strlen�������ص������ַ�����'\0'ǰ����ֵ��ַ�
//����ֻ����ַ�������Ҫ��'\0'������
//ע�⺯���ķ���ֵΪsize_t,���޷��ŵ�(�״�)
//typedef _w64 unsigned int size_t; ��unsigned int ������Ϊsize_t
/*
���ַ�������
strlen
���Ȳ������Ƶ��ַ�������  ����ȫ
strcpy strcat strcmp
���������Ƶ��ַ�����������
strncpy strncat strncmp
�ַ�������
strstr strtok
������Ϣ����
strerror
*/
//strlen������ģ��ʵ��:
//1�������ķ���
//2�ݹ�ķ���
//3ָ��-ָ��

//1�������ķ���
//my_strlen(const char* str)//������a�ĵ�ַ ���ַ�ָ�����
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str != '\0')//�˴����Ը�Ϊwhile(*str)��Ϊ*strΪ\0��ʱ��(\0����0) 0����Ϊ�� ѭ����ֹ 
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main() 
//{
//	char arr[] ="abcdef";
//	//����ʾ��: ��֪��strlen�������ҵ�\0�� ������ǿ��������� �������һֱ������
//	//char arr[] = { 'a','b','c','d','e','f' };
//	int len = my_strlen(arr);
//	printf("%d\n",len);
//	if (strlen("abc") - strlen("abcdef" )>0)//3-6 = -3  ������strlen�ĺ������ص����޷���ֵ -3�����޷���ֵ������0��Ķ�! ��ӡhehe
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
//Դ�ַ���������'\0'����
//�ὫԴ�ַ����е�'\0'������Ŀ��ռ� 
//Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ���
//Ŀ��ռ����ɱ�

//ģ��ʵ��
//char* my_strcpy(char* str1 ,char* str2) 
//{
//	char* set = str1;//��һ�з��������whileѭ�����涼�� ��Ϊ����ָ�� ʼ��ָ��str1�ĵ�ַ��ִ��˳��û̫���ϵ
//	assert(str1 != NULL && str2 != NULL);
//	while (*str1++ = *str2++)//��str2��ֵΪ\0ʱ��ֵ��str1 �������ʽ��ֵΪ��ѭ����ֹ
//	{
//		;
//	}
//	//����str1����ʼ��ַ
//	return set;
//}
//int main() 
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "abc";
//	//����ʾ�� strcpy(arr2, arr1);���ܰѳ��ȳ��Ŀ��������ȶ̵� Խ����� �Ѷ̵ĸ��Ŵ���
//	//����ʾ�� char *arr1 = "abcdef";ָ��ָ�����ַ����ĵ�ַ �����ַ��������޸� ǿ�п�������� ������Ŀ���ֻ���޸������ֵ
//	
//	//strcpy(arr1, arr2);//��arr2 abc\n ȫ���Ž�ȥ
//
//	my_strcpy(arr1, arr2);
//	printf("%s\n",arr1);
//	return 0;
//}
 
//strcat
//Դ�ַ���������'0'����
//Ŀ��ռ�����㹻��,��������Դ�ַ��������� Ŀ��ռ���ö���һ��
//Ŀ��ռ������޸�

//char* my_strcat(char* str1,char* str2) 
//{
//	char* ret = str1;
//	assert(str1 != NULL && str2 != NULL);
//	//1 �ҵ�Ŀ���ַ���'\0'
//	while(*str1 !='\0')
//	{
//		str1++;
//	}
//	//2 ��'\0'(����\0)׷��
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
//	printf("%s\n", arr1);//%s��ӡ�ַ��� ��arr1��\0λ�� ȡ��\0����ʼ׷��
//}

//strcmp����
//�Ƚϵ��������ַ������׸��ַ��Ĵ�С 
//��һ���ַ������ڵڶ����ַ���,���ش���0������ 1(vs��1������������֪��)
//��һ���ַ������ڵڶ����ַ���,�򷵻�0
//��һ���ַ���С�ڵڶ����ַ���,�򷵻�С��0������ -1

//int main() 
//{
//	char* p1 = "qbc";
//	char* p2 = "abc";
//	if (strcmp(p1, p2) > 0)//q��ASCIIֵ����a��ASCIIֵ ����p1����ַ����Ĵ�С����p2
//	{
//		printf("p1>p2\n");//��ӡ���
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

//ģ��ʵ��strcmp
//my_strcmp(const char* str1,const char* str2)
//{
//	assert(str1 && str2);
//	//�Ƚ�
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
//		return 1;//����
//	}
//	else
//		return -1;//С��
////���if...else����Ҳ����д��return (*str1 - *str20�����ص��������ַ�֮���ASCII�Ĳ�ֵ
//}
//int main() 
//{
//	char* p1 = "abcdef";
//	char* p2 = "abqwe";
//	int ret = my_strcmp(p1, p2);
//	printf("ret = %d\n", ret);
//}

//strcpy��strncpy������
//int main() 
//{
//	char arr1[5] = "abcde";
//	char arr2[] = "hello bit";
//	strcpy(arr1, arr2);//����arr1�ĳ���ֻ��5 ����strcpy�����Ƴ��� ����ֱ������arr1��ȥ Խ����
//
//	printf("%s\n", arr1);
//	return 0;
//}

//int main() 
//{
//	char arr1[10] = "abcdef";
//	char arr2[] = "hello bit";
//	char arr3[] = "bit";
//	strncpy(arr1, arr2, 4);//ֻ��arr2��ǰ�ĸ��ַ�����arr1 �滻��abcd
//	strncpy(arr2, arr3,6);//bit\0 4��Ԫ�� ��6�� �ټ�����\0��arr2
//	printf("%s\n",arr1);
//	printf("%s\n",arr2);
//	return 0;
//} 

//strncat
//int main() 
//{
//	char arr1[30] = "hello\0xxxxxxxx";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 10);//��arr��\0��ʼ׷��(������\0�ɵ�) ׷�Ӻ��Լ��Ჹ��һ��\0 ���涨�ĳ��ȱ������arr2�� Ҳ���Ჹ�����\0�����Ǹ�strncpy������
//	printf("%s",arr1);
//	return 0;
//}
//
//int main() 
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcqer";
//	//int ret = strcmp(p1, p2);
//	int ret = strncmp(p1, p2, 3);//��ͬ����0 
//	//С�ڷ��ظ��� ���ڷ������� Ҳ������Ƚ��ַ�
//	printf("%d\n",ret);
//	return 0;
//}

//�����ַ�������strstr
//char* strstr(const char* string, const char* strCharSet);
//NULL - ָ���ǿ�ָ��
//NUL/Null - ָ����'\0'

//�����������ַ���ַ ���ַ���ָ�����, ���ڲ���ı�ԭ�����ַ��� ����const  ���ص�Ҳ�ǵ�ַ ���Է�������Ϊchar*
//return ����ֹ���������� 
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);//ȷ��p1 ,p2������Ϊ��ָ��
//	assert(p2 != NULL);
//	char* s1 = NULL;//����д��s1 = cur = p1,s2 = p1 
//	char* s2 = NULL;
//	char* cur = (char*)p1;
//	if (*p2 == '\0')//��p2�ǿ��ַ���
//	{
//		return (char*)p1;//ǿת��������
//	}
//	while (*cur)//cur���ߵ�\0  p2����p1���Ӵ�
//	{
//		s1 = cur;
//		s2 = (char*)p2;
//		//while((*s1!='\0') && (*s2 !='\0') && (*s1 == *s2)) //���ַ���ͬs1,s2һ����
//		while((*s1)&&(*s2)&& !(*s1-*s2))//��������� s1-s2 ��s1,s2��ͬ,���Ϊ0, !ȡ�� ����Ϊ�� 
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')//�ҵ��� ����ƥ��ɹ���λ��
//		{
//			return cur;
//		}
//		if (*s1 == '\0')//��p1�ĳ���С��p2�ĳ��� ��ǰ��ֹ
//		{
//			return NULL;
//		}
//		cur++;//���ַ�����ͬs1������
//	}
//	return NULL;//�Ҳ����Ӵ� ���ؿ�ָ��
//}
//int main()
//{
//	char *p1 = "abcddefghi";
//	char *p2 = "def";
//	//�Ҳ�������һ����ָ�� �ҵ�����d��λ�� 
//	char *ret = my_strstr(p1, p2);//��p1ָ����ַ���������Ƿ����p2ָ����ַ���
//	if (ret == NULL) 
//	{
//		printf("�Ӵ�������\n");
//	}
//	else 
//	{
//		printf("%s\n", ret);//ret����洢��ֵ���ǵ�ַ ������������þͿ�ʹ��
//		//���� p1�ȱ���ֵΪ"abcdef" ��p1ָ��ָ��"abcdef"��a�ĵ�ַ ��������p1���������
//	}
//	return 0;
//}
/*
���ַ���ͬp1,p2һ���� ���ַ���ͬp1��ǰ��
p1ָ��a,p2ָ��d�������ַ���ͬ,p1��ǰ�� �ߵ�b������p2���ߵ�c����p2, p1�ߵ�dʱ��p2��ͬ����ʱp1��p2һ���� 
p1 �ߵ�e ,p2Ҳ�ߵ�e ������ͬ ������һ���� p1 f ,p2 f ����ͬ������ p2�ߵ�\0�� ֹͣ�жϡ�
����p1,p2˭������ �ж��Ƿ��ҵ� һ�������p2������ �����ҵ���,p1�������û�ҵ���

������ʵ���ϻ��и����ӵİ��� ���� abcddef  ��def �Ƚϣ����һ�Ҫ����p1�ַ���ƥ��ɹ�ʱ�����ַ��ĵ�ַ��
��s1ȡ��p1 s2ȡ��p2 ��cur��¼�ַ�ƥ��ɹ���λ��
1 s1,s2������ͬһ����,��ͬs1������ ��
2 ��s1 = cur,����cur��λ����һ�Σ�s1Ҳ��һ��,s2��λ�ûص�p2��λ�á������ж����ַ��Ƿ���ͬ ѭ��1-2����
3 ��cur�ߵ�\0ʱ��p2����p1���Ӵ���
4 ����cur����֮ǰ,s2������ ֤���ҵ����Ӵ� ����cur��ֵ p1��cur��λ����p2ƥ��ɹ�
*/

//strtok ���� �ַ����ָ��
//sep�����Ǹ��ַ���,�����������ָ������ַ�����
//��һ������ָ��һ���ַ���,��������0��������sep�ַ�����һ�����߶���ָ����ָ�ı�ʶ
//strtok�����ҵ�str�е���һ�����(�ַ�),��������\0��β,����һ��ָ�������ǵ�ָ�롣
//ע:strtok������ı䱻�������ַ���,������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸ġ�
//strtok�����ĵ�һ��������ΪNULL���������ҵ�str�е�һ�����,strtok���������������ַ����е�λ��
//strtok�����ĵ�һ������ΪNULL,��������ͬһ���ַ����б������λ�ÿ�ʼ,������һ����ǡ�
//����ַ��������ڸ���ı�ʶ,�򷵻�NULLָ�롣

//int main() 
//{
//	char arr[] = "zpw@bitedu.tech";
//	char* p = "@.";
//	//strtok���������ҵ�@ Ȼ���@�ĳ�\0,����z�ĵ�ַ�õ�zpw ��ס���λ�� �����λ�ü��� �¸�����.�ٸ�\0 ����b�ĵ�ַ �õ�bitedu һֱ����ѭ����һ��\0�ͷָ���һ��
//	//�ҵ�������\0ʱ����t�ĵ�ַ �õ�tech
//	char buf[1024] = { 0 };//strcpy����ַ��� ���Կ���һ�������и�
//	strcpy(buf, arr);
//	char* ret = strtok(arr, p);//����p�ķ����и�arr�ַ���
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);//�ڶ����и�Ժ󴫸���ָ������� ��Ϊ������������б��
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n",ret);
//	return 0;
//}

//����ĵ��ú���д��̫�� ��ѭ�����
//int main()
//{
//	char arr[] = "zpw@bitedu.tech";
//	char* p = "@.";
//	//strtok���������ҵ�@ Ȼ���@�ĳ�\0,����z�ĵ�ַ�õ�zpw ��ס���λ�� �����λ�ü��� �¸�����.�ٸ�\0 ����b�ĵ�ַ �õ�bitedu һֱ����ѭ����һ��\0�ͷָ���һ��
//	//�ҵ�������\0ʱ����t�ĵ�ַ �õ�tech
//	char buf[1024] = { 0 };//strcpy����ַ��� ���Կ���һ�������и�
//	strcpy(buf, arr);
//	char* ret = NULL;//����p�ķ����и�arr�ַ���
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//strerror����
//���ش����룬����Ӧ�Ĵ�����Ϣ��
//int main() 
//{
//	char* str = strerror(0);
//	printf("%s\n",str);
//
//}

//error ��һ��ȫ�ֵĴ�����ı���
//��C���ԵĿ⺯����ִ�й�����,�����˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��
//int main() 
//{
//	FILE* pf = fopen("test.txt", "r");//r�Ƕ��ļ�����˼
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

//�ַ����ຯ��:
//����    ������Ĳ����������������ͷ�����
//iscntrl �κο����ַ�
//isspace �հ��ַ�:�ո�,��ҳ\f,����\n,�س�\r,�Ʊ��\t���ߴ�ֱ�Ʊ��\v
//...

//#include<ctype.h>
//int main() 
//{
//	char ch = 'w';
//	int ret = islower(ch);
//	printf("%d\n",ret);//��Сд ���ط�0���� ����Сд����0
//	return 0;
//}

//�ַ�ת��:
//int tolower(int c);//��дתСд
//int toupper(int c);//Сдת��д

//#include<ctype.h>
//int main()
//{
//	//char ch = tolower('q');//q
//	//putchar(ch);//��ӡ�ַ�
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


//�ַ��������������൱��ľ����� ���ڴ溯��������Զ����
//int main() 
//{
//	int arr1[] = { 1,2,3,4,5 };//01 00 00 00 | 02 00 00 00 | 03 00 00 00 |04 00 00 00 |05 00 00 00
//	int arr2[5] = { 0 };//����һ���ֽڵ��� 01 00(strcpy����0��ֹͣ)���ԾͶ������� �Ϳ���һ��1��ȥ
//	strcpy(arr2, arr1);//arr2ֻ��������һ��1��ȥ
//	//ԭ��strcpy�Ĳ�����char* һ��ֻ����һ���ֽ� ����\0ֹͣ
//	return 0;
//}

//�ڴ溯��:
//memcpy:�ڴ濽�� ��void*�������в��������� 
//memmove:

//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));//������СΪarr1�Ĵ�С
//	return 0;
//}

//struct S 
//{
//	char name[20];
//	int age;
//};
//void* my_memcpy(void* dest,const void* src,size_t num) 
//{	
//	void* ret = dest;//����arr4����ʼ��ַ
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
//C���Ա�׼
//memcpy ֻҪ���� ���ص����ڴ濽���Ϳ��� 
//memmove �����ص��ڴ�Ŀ���
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	my_memcpy(arr+2,arr,20);//20���ֽ� 5��Ԫ�� �������ڴ�ռ䲻���й��� ���򿽱�ʧ�� �ص��ռ�Ŀ�����memmove
//	//������VS�������� memcpyҲ���Դ����ص��ռ�Ŀ���
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main() 
//{
//	struct S arr3[] = { {"����",20},{"30",30} };
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
//	//������ʼλ�ò�ͬѡ��ͬ�Ŀ�����ʽ
//	if (dest < src)//�Ƚϴ�С������û̫���ϵ
//	{
//		//��ǰ��󿽱�
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
//		//�Ӻ���ǰ����
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
//	my_memmove(arr3 + 2, arr3,20);//��1,2,3,4,5������3,4,5,6,7
//	int i = 0;
//	for ( i = 0; i <10; i++)
//	{
//		printf("%d ",arr3[i]);
//	}
//	//���1,2,1,2,3,4,5,8,9,10
//	return 0;
//}

//memcmp ��ͬ����0 arr1С��arr2����С��0���� arr1����arr2���ش���0����
//memcmp�Ӳ���ͬ�ĵ�һ��Ԫ�رȽ� ���Ҳ�Ǹ�������� �����������ûɶ����
//int main() 
//{
//	int arr1[] = { 1,3,4,5,6 };
//	int arr2[] = { 1,2,3,4,5 };
//	int ret = memcmp(arr1, arr2, 16);//�Ƚ�ǰ4��Ԫ�� �ڶ�����ͬԪ��3 >2  1
//	printf("%d\n",ret);
//}

//memset �ڴ�����
//int main() 
//{
//	char arr[10] = "";
//	memset(arr, '#', 10);//��ʮ��Ԫ��ȫ������#
//	//�����÷�
// //int arr[10] = "";
//	memset(arr, 1, 10);//ʵ���ϻ���10���ֽڵ�01 Ҳ����������Ԫ��
//	//01 01 01 01 01 01 01 01 01 01  �����Ԫ�ػ���00 00 00 00 00 00
//	return 0;
//}

//�Զ�����������
//�ṹ������ ���� ����!! �����;Ϳ��Զ������
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
//	//�����Ľṹ�����
//	struct Stu s1;
//	struct Stu s1;
//	return 0;
//}

//�ṹ���������� ���봴���ṹ���ȫ�ֱ��� �����޷������ṹ�����

//struct
//{
//	int a;
//	char c;
//}sa;//�����ṹ������
//struct
//{
//	int a;
//	char c;
//}*psa;//�����ṹ��ָ������
//int main() 
//{
//	psa = &sa;//ʵ���ϱ���������������ṹ�嵱��������ͬ������ ������ 
//	return 0;
//}

//�ṹ��������
//typedef struct Node 
//{
//	int data;
//	//����������� struct Node n;//n�����и� data n ���滹�и�n .....����ѭ�� ���޴�
//	//�ڽṹ���а���һ������ ,Ϊ�ýṹ����ĳ�Ա�Ƿ������? ����
//
//	struct Node* next;//���ָ���¸��ڵ��ָ�� --����
//}Node;//��������ΪNode

//��ͬ��:
//struct Node
//{
//	int data;
//	struct Node* next;
//};
//typedef struct Node Node;

//int main() 
//{
//	struct Node  n1;
//	Node n2;//��������һ��
//	return 0;
//}

//�ṹ���ʼ��
//struct T
//{
//	double weight;
//	short age;
//};
//struct S
//{
//	char c;
//	struct T st;//�ṹ������ṹ��
//	int a;
//	double d;
//	char arr[23];
//};
//int main() 
//{
//	//struct S s   = {'c', 1 , 1.1 ,"����Х���� ȷʵ��˧��"};
//	struct S s = { 'c',{13.2,30},100,3.14,"hello world"};
//	printf("%c %d %f %s\n",s.c,s.a,s.d,s.arr);//%cһ���ַ� %s��һ���ַ���
//	printf("%lf %d",s.st.weight,s.st.age);
//	return 0;
//}

//�ṹ�� �ڴ����
//������μ���
//1 ��һ����Ա����ṹ�����ƫ����Ϊ�ĵ�ַ��
//2 ������Ա����Ҫ���뵽ĳ������(������)����������ַ��
//������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա�Ĵ�С�Ľ�Сֵ
//VS ������Ĭ�ϵĶ����� ��8  gccû��Ĭ�϶�����(�ٷ�˵�� ���˵����4)
//3 �ṹ���ܴ�СΪ����������������
//4 ���Ƕ���˽ṹ������,Ƕ�׵Ľṹ����뵽�Լ���������������������
//�ṹ��������С����������������(��Ƕ�׽ṹ�Ķ�����)��������
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

///Ϊʲô�����ڴ����?
/*
1.ƽ̨ԭ��(��ֲԭ��):�������е�Ӳ��ƽ̨���ܷ��������ַ�ϵ��������ݵģ�ĳЩӲ��ƽ̨
ֻ����ĳЩ��ַ��ȥĳЩ�ض����͵�����,�����׳�Ӳ���쳣��
2.����ԭ��:���ݽṹ(������ջ)Ӧ�þ����ܵ�����Ȼ�߽��϶��롣ԭ�����ڣ�Ϊ�˷���δ�����
�ڴ棬��������Ҫ�������ڴ����;��������ڴ���ʽ���Ҫһ�η��ʡ�
������˵:
�ṹ����ڴ�������ÿռ任ȡʱ���������
*/
//��������ƽṹ���ʱ��,���Ǽ�Ҫ�������,��Ҫ��ʡ�ռ�,�������:
//��ռ�ÿռ�С�ĳ�Ա����������һ��
//����:
//struct S1 
//{
//	char c1;
//	int i;
//	char c2;
//};
////s2�ͱ�s1��ʡ�ռ�
//struct s2 
//{
//	char c1;
//	char c2;
//	int i;
//};

//C���Կ����޸��ڴ������ 
//����Ĭ�϶�����Ϊ4
//#pragma pack(4)
//ȡ�����õ�Ĭ�϶����� #pragma pack()
//struct S
//{
//	char c1;//ռһ���ֽ�
//	//�˷��߸��ֽ�
//	double d;//ռ�˸��ֽ�
//};
//
//int main() 
//{
//	struct S s;
//	printf("%d\n",sizeof(s));
//}

//offsetof(�ṹ�������ṹ���Ա������) ����ṹ���Ա��������ڽṹ����ʼλ�õ�ƫ����
//offsetof()�Ǹ���
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

//�ṹ�崫��
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

//λ�ε������ͽṹ�����Ƶ�,��������ͬ
//1 λ�εĳ�Ա������int�� unsigned int ��signed int ,char...
//2 λ�εĳ�Ա�������һ��ð�ź�һ������
//�ṹ��ʵ��λ�ε�����

//ð�ź���������� ��������Ҫ�ı���λ(���Լ��趨��) һ������λ����һ��������λ
//λ�ε��ڴ����
//1λ�εĳ�Ա������int, unsigned int ,signed int ������char(�������μ���)����
//2λ�εĿռ����ǰ�����Ҫ4���ֽ�(int)����1���ֽ�(char)�ķ�ʽ�����ٵ�
//3λ���漰�ܶ಻ȷ������,λ���ǲ���ƽ̨��,ע�ؿ���ֲ�ĳ���Ӧ�þ�������ʹ��λ��
//λ�εĿ�ƽ̨����
//1 intλ�α������з����������޷������ǲ�ȷ����
//2λ�ε�������Ŀ����ȷ��(16λ�������16,32λ�������32��д��27����16λ�����ϳ���)
//3λ���еĳ�Ա���ڴ��д������ҷ��䣬���Ǵ�����������ש��δ���塣
//4 ��һ���ṹ��������λ�Σ��ڶ���λ�γ�Ա�Ƚϴ��޷��������һ��λ��ʣ���λʱ��
//������ʣ���λ�������ã����ǲ�ȷ���ġ�
//struct S
//{
//	int a : 2;//����Ϊaֻ��Ҫ��������λ�͹��� 
//	int b : 5;
//	int c : 10;
//	int d : 30;
//	//�ܹ���47������λ һ�ֽڰ˸����� ��Ҫ6���ֽھ͹���
//	//��������λ�ε������ڴ���䷽ʽ �����ȷ���4���ֽ� ��abc�� ����d�� �����ڷ���4���ֽ� ��d��
//	//ע��d��ȫ�������¸���4���ֽ����� ��һ���ֽ�ʣ�µı���λ���˷ѵ���
//	//�ܹ�8���ֽ�
//};
//int main() 
//{
//	struct S s = {0};
//
//}

//struct S
//{
//	char _a : 3;//_aֻ��Ҳ�Ǳ����� ֻ�����ܷ��㿴��������λ�ζ���
//	char _b : 4;//����һ���ֽ� ��a ��b ���� c �ٿ�һ�� cռ5�� ����d �ٿ�һ�� ��d
//	char _c : 5;//һ��ռ3���ֽ� �ռ��������ʹ��(С��) �ӵ͵�ַ���ߵ�ַʹ��
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

//�Զ�����������-ö�� �ؼ���enum
//�ѿ��ܵ�ȡֵһһ�о�
//Ĭ��ȡֵ�Ǹ�����һ�����ߵ�
//����A��1 B C����ֵ ��ôA�� 1 B�� 2 C�� 3  ��A C����ֵ B��5  ��ôA�� 0 B�� 5 C�� 6 

//enum Sex
//{
//	//ö�ٵĿ���ȡֵ - ���� 
//	//ö�����������峣���� ��define���峣���кܶ�ô�
//	//���Ӵ���Ŀɶ��ԺͿ�ά���� ��ö�����ͼ����Ͻ�
//	//��ֹ��������Ⱦ(��װ) ���ڵ��� ʹ�÷��� һ�ο��Զ���������
//	MALE = 2 ,
//	FEMALE =4 ,
//	SECRET = 8//�ı�Ĭ��ȡֵ
//};
//enum Color
//{
//	RED,//Ĭ��ȡֵ0
//	GREEN,//1
//	BLUE//2 һֱ����
//};
//int main() 
//{
//	enum  Sex s = MALE;//��ֵֻ�������������ֵ
//	enum Color c = BLUE;
////����д�� enum Color c = 2;//�����ö������ ������������͵���2 �������ͱ��� ����������Ϊ�������﷨��鲻�ϸ�
//	printf("%d %d %d", RED, GREEN, BLUE);
//	return 0;
//}


//�Զ�����������-������(������) �ؼ���union
//������ĳ�Ա�ǹ���ͬһ���ڴ�ռ�ģ�����һ�����ϱ����Ĵ�С������������Ա�Ĵ�С
//��Ϊ����������Ҫ���������������Ǹ���Ա
//�������������ͬʱʹ��       
//union Un
//{
//	char c;//��4���ֽ� �ȷ�c(c��char�͵���ռ��һ���ֽ�) ʣ�µ������ֽ��ٷ�i
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

//�жϴ�С�� ����ͨ������ö�ٷ���
//������Щ�жϷ��������Ժܴ� ֻ���ж��ض�����
//check_sys()
//{
//	int a = 1;//0x 00 00 00 01
//		//С��01 00 00 00
//		//���00 00 00 01
//	return   *(char*)&a;
//}

//������
//check_sys() 
//{
//	union Un
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;//��i���ڵĿռ�ĸ�ֵΪ1 cҲ������ cռ��һ���ֽ�
//	//����1����ʾС��
//			//����0,��ʾ���
//	return u.c;
//}
//int main() 
//{
//	//0x11223344
//	//С��[][]44 33 22 11
//	//���[][]11 22 33 44
//	int ret = check_sys();
//	if (1 == ret)//�����һ���ֽ���1����С��
//	{
//		printf("С��\n");
//	}
//	else 
//	{
//		printf("���");
//	}
//	return 0;
//}

//������Ĵ�С

//union Un 
//{
//
//	int a;//4 8  ������ ��4 
//	char arr[5];//��char[arr] �ܹ�ռ5���ֽ�������Ա    char arr[5]�Ķ�������ÿ��Ԫ�صĴ�С��1
//	//������Ա�Ĵ�С����������������������ʱ�򣬾�Ҫ���뵽���������������� ��
//};
//int main()
//{
//	union Un u;
//	printf("%d\n",sizeof(u));//5���뵽4�ı��� Ϊ8 �˷�3���ֽڴ�С
//	return 0;
//}