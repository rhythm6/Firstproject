#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
//дһ���ж������ĺ��� 1��������
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j < n; j++) { //��j�ĳ�ʼֵ��1 if���� return 0 ������forѭ���ⲿ �ⲿ �ⲿ  ��Ҫ������˵����
//		//��ص���������ȥ �Ͳ���ִ��j++�� Ȼ������ѭ�� �����޷��жϳ�����
//		if ((n % j) == 0) {
//			return 0;//�ܱ������Ͳ�������
//		}
//	}
//	return 1;//������if������ֱ�ӷ���1 ȷ�������� 
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d \n", i);
//	}
//	return 0;
//}

//���ֲ���kֵ
//int binary_search(int arr[],int k) //binary(2���ƣ���Ԫ�ģ��˴���ʾ����)
////�˴���int arr[]ʵ���ϻ���һ��ָ�� 32λһ��ָ����4���ֽ�
//{
//	int sz = sizeof(arr)/ sizeof(arr[0]);//������Ԫ�ظ��� 4���ֽڡ�4���ֽڣ�һ������Ԫ���ĸ��ֽڣ� = 1 ���Դ˴�Ӧ��������������
//	int left = 0;
//	int right = sz - 1;
//
//	while(left <= right) 
//	{
//		int mid = (left + right) / 2;
//
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main() 
//{
//	//����ҵ��˷�����������±꣬�Ҳ�������-1
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int ret = binary_search(arr, k);//��arr�����в���k �����ڴ��ε�ʱ�� 
//	//�����arrʵ���ϴ���ȥ���ǵ�һ��Ԫ�صĵ�ַ
//	if (ret == -1) {
//		printf("�Ҳ���\n");
//	}
//	else 
//	{
//		printf("�ҵ���,�±���:%d\n",ret);
//	}
//	return 0;
//}

//��ȷ�汾
//int binary_search(int arr[], int k,int sz) //binary(2���ƣ���Ԫ�ģ��˴���ʾ����)
////�˴���int arr[]ʵ���ϻ���һ��ָ�� 32λһ��ָ����4���ֽ�
//{
//	
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	//����ҵ��˷�����������±꣬�Ҳ�������-1
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);//������Ԫ�ظ��� 4���ֽڡ�4���ֽڣ�һ������Ԫ���ĸ��ֽڣ� = 1 ���Դ˴�Ӧ��������������
//	int ret = binary_search(arr, k, sz);//��arr�����в���k �����ڴ��ε�ʱ�� 
//	//�����arrʵ���ϴ���ȥ���ǵ�һ��Ԫ�صĵ�ַ
//	if (ret == -1) {
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ���,�±���:%d\n", ret);
//	}
//	return 0;
//}

//void Add(int* p)
//{
//	//*p++;//����д������ ��Ϊ++�����ȼ���* �����Ǹ�p��ֵ��1 ������*p
//	(*p)++;//�Ӹ����Ÿı����ȼ� ��*p�����1 �ٴ�ֵ
//}
//int main() 
//{
//	int num = 0;
//	Add(&num);//ÿ����һ�κ���num+1
//	Add(&num);
//	printf("num =%d\n", num);
//	return 0;
//}

//��������ʽ����
//int main() 
//{
//	printf("%d", printf("%d", printf("%d", 43)));//printf ������д���ַ�������
//	return 0;
//}


//����ͷ�ļ����Զ��庯��
//#include"train.h"
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = 0;
//	sum = Add(a, b);
//		printf("%d\n", sum);
//		return 0;
//}

//�����ݹ� ����1234 ���1 2 3 4
//void print(int n) 
//{
//	if (n > 9){//��������� �������Ƶ����Լ� ��ѭ��
//		//n = n / 10;
//		//print(n); //���ַ����ﲻ��Ҫ�� ��Ϊ �Ȱ�n��ֵ��10 ��������if��������ǰһ����ֹ ��123 ��ӡ 1 1 2
//		print(n / 10);//���ֿ��ԣ���Ϊ�����Ȱ�ֵ�����¸��������ж��Ƿ���������
//	}
//	printf("%d ", n%10);
//}
//int main() 
//{
//	unsigned int num = 0;//�����εı���
//	scanf_s("%d", &num);
//	print(num);
//	return 0;
//}

 
// �Զ��庯�����ַ�������
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len = %d",len);
//	return 0;
//	
//}


//��������ʱ���� ���ַ�������
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len = %d", len);
//	return 0;
//
//}

//��n�Ľ׳�
//int Fac1(int n) 
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++) 
//	{
//		ret *= i;
//
//	}
//	return ret;
//}
//int Fac2(int n) 
//{
//	if(n<=1)
//	{
//		return 1;
//	}
//	else 
//	{
//		return n * Fac2(n - 1);
//	}
//}
//int main() 
//{
//	int n = 0;
//	int ret = 0;
//	scanf_s("%d", &n);
//	//ret = Fac1(n);//ѭ���ķ�ʽ
//	ret = Fac2(n);//�ݹ�ķ�ʽ
//	printf("%d\n", ret);
//	return 0;
//}

//쳲��������� ǰ����֮�͵��ڵ�����
// 1 1 2 3 5 8 13
//int Fib(int n) 
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) - Fib(n - 2);
//}//�����㷨�ظ����� Ч�ʼ��� ������
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;//��Ϊǰ����쳲���������1 n<=2ֱ�Ӵ�ӡc����
//	while (n > 2) 
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	
//		n--;
//	}
//	return c;
//}
//int main() 
//{
//	int n = 0;
//	int ret = 0;
//	scanf_s("%d", &n);
//	//TDD - ������������
//	ret = Fib(n);
//	printf("ret = %d\n",ret);
//	return 0;
//}
//
//��ŵ�����⣬������̨�� �ݹ��㷨��ϰ
//
//void move(char x, char y);
//void hannuo(int n, char one, char two, char three)
//{
//	if (n == 1)move(one, three); //�ݹ��ֹ����
//	else
//	{
//		hannuo(n - 1, one, three, two);//�� n-1�������ȷŵ�B��λ��
//		move(one, three);//��A���ϵ�ʣ�µ�һ�����ƶ���C����
//		hannuo(n - 1, two, one, three);//��n-1���̴�B���ƶ���C����
//
//	}
//}
//void move(char x, char y)
//{
//	printf("%c--->%c", x, y);
//}
//
//int main()
//{
//	int n;
//	printf("input your number");
//	scanf_s("%d", &n);
//	hannuo(n, 'A', 'B', 'C');
//	return 0;
//}

//void ToH(int n, char x, char y, char z)
//{
//	if (n == 1) {
//		printf("%c-->%c" , x, z);
//	}
//	else
//	{
//		ToH(n - 1, x, z, y);
//		printf("%c-->%c", x, z);
//		ToH(n - 1, y, x, z);
//
//	}
//}
//int main()
//{
//	int n = 0 ;
//	printf("�����뼸�׺�ŵ��");
//	scanf_s("%d", &n);
//	ToH(n,'a','b','c');//a b c�ֱ�Ϊ��һ�������ڶ�����������
//	return 0;
//}

//[]�±����ò�����  Ҳ��������ʲ�����
//һά���鴴�����ʼ��
//int main() 
//{//����һ�����ʮ�����ε�����
//	int arr[10] = { 1,2,3 };//����ȫ��ʼ��,ʣ�µ�Ԫ��Ĭ�ϳ�ʼ��Ϊ0
//	char arr1[5] = { 'a',98 };
//	char arr2[5] = "ab";//[a][b][\0]
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//�����С����Ԫ�ش�С����Ԫ��2����
// 		return 0;
//}

//��ά���鴴�����ʼ��
//int main() 
//{
//	//�������� 
//	int arr[3][4] = {1,2,3,4,5};//��һ��1234 �ڶ���50000������0000
//	int arr1[3][4] = { {123},{456} };//��һ��1230 �ڶ���4560 ������0000
//	int arr2[][4] = { {123},{456} };//�п���ʡ�� �в��� ��һ��1230 �ڶ���4560
//	return 0;
//}

//������ά����
//int main() 
//{
//	int arr[3][4] = { {1,2,3},{4,5} };
//	//1 2 3 0
//	//4 5 0 0
//	//0 0 0 0
//	int i = 0;
//	for (i = 0; i < 3;i++) 
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++) 
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
 
//ð������
//void bubble_sort(int arr[],int sz)
//{
//	
//	//ȷ��ð�����������
//	int i = 0; 
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//���豾�������Ѿ�����
//		//ÿһ�˵�ð������
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)// ��һ�������Ÿ�������Ƚ� �����Ƚ�����ִ��ѭ�� С�ڼ����´�ѭ��
//			//ÿһ�˵�Ŀ����ͨ��������������������� �����´αȽϾ��ٱȽ�һ�� ֱ��ѭ�����
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				 flag = 0;//��������������ȫ���� ע��˴��Ǹı�flag��ֵ ����ǰ����������� ѭ���ⲿ��ʧЧ�� ��Ϊ�ֲ����������������������Ǹ�{}
//			}
//		}
//		if (flag == 1) //��˳���Ѿ�������ʱ����
//		{
//			break;
//		}
//	}
//}
//
//int main() 
//{
//	int arr[] = {9,5,6,7,8,3,4,2,1,0};
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//��arr��������,�ų�����
//	bubble_sort(arr,sz);//ð��������
//	for (i = 0; i < sz; i++) {
//		printf("%d",arr[i]);
//	}
//	return 0;
//}

//int main() 
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	printf("%p\n", &arr);
//	printf("%p\b", &arr + 1);//�˴��Ǹ���������ĵ�ַ��һ 
//	//������7��Ԫ�� ÿ��Ԫ��4���ֽ�  �����ַ��һ�ܹ��ӵ�ֵΪ: 4*7 = 28
//	return 0;
//}