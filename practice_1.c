#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
//int main()
//{
//	int i = 1;
//	while (i<=10)
//	{
//		if (i == 5)
//			continue;//��ֹ����ѭ�� �����´�ѭ��
//		printf("%d",i);//���� ��ӡһֱѭ��1
//
//	}
//	return 0;
//}
//int main() 
//{ 
//	int ch = getchar();//gtetchar����һ������������ַ� ����r
//		//��ch���
//	putchar(ch);//��� r
//	printf("\n");
//	printf("%c",ch);//Ҳ��һ����� r
//	return 0;
//}

//int main() 
//{
//	int ch = 0;
//	//EOF - end of file -> -1 �ļ�������־��ֵ��-1
//	while ((ch = getchar()) != EOF)//��ctrl+z�����˳� ����EOF����
//		//��ΪEOF���ص�ֵ��-1 -1Ϊ��,ѭ������
//	{
//		putchar(ch);
//	}
//	return 0;
//}

//int main() 
//{
//	int ret = 0;
//	char password[20] = {0};
//	printf("����������:>");
//	scanf("%s", password);//������������ password������
//	printf("ȷ�����루Y/N��");
//	getchar();//�����ַ� ��û����һ�� ֱ�Ӿͱ�Ϊ����ȷ��
//	//ԭ�� �ϸ����뺯��scanf = ��������� ����һ���س��� passsword ���������ݻ���������123456 ʣ�»س���
//	��һ��getchar����������س��� �¸�getchar�Ϳ�����������Y�ˡ�
//	ret = getchar();//����getchar�õ��ķ���ֵ(�����س�)
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�");
//	}
//	else
//	{
//		printf("����ȷ��");
//	}
//	return 0;
//}

//�����ǿ�����������κ�Ԫ�ض���������λ��
//int main()
//{
//	int ret = 0;
//	int ch = 0;
//	char password[20] = { 0 };
//	printf("����������:>");
//	scanf("%s", password);//������������ password������
//	printf("ȷ�����루Y/N��");
//	while ((ch = getchar()) != '\n') {
//	//һֱѭ�� ֱ������\n getchar()����\n ��ch 
//		;//����һ������� ��whileֻ��������������
//	
//	}
//	//���getchar�Ͳ������\n��
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�");
//	}
//	else
//	{
//		printf("����ȷ��");
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')
//			continue;
//			putchar(ch);
//	}
//	return 0;
//}

//int main() 
////��ѭ����ӡ��1-10
//{	
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//		printf("%d",i);
//	return 0;
//}

//int main() 
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			break;//����ѭ��
//		printf("%d",i);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i == 5) {
//			printf("hh\n");
//			printf("hehhe\n");
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	for (i = 0; i < 10; i++)//��� i = 0; �ұ�  i < 10 ǰ�պ�
//		//���ֱ�׼д�� ����ֱ�۵Ĵ���10��ѭ�� 10�δ�ӡ 10��Ԫ�ص�����
//		//for(i = 0;i <= 9;i++)����i <= 9 Ҳ�� ����û���ϱߵ����ֿ��������
//		//���������
//	{
//		printf("%d", arr[i]);
//	}
//}

//int main() 
//{ 
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)//jѭ��10�κ� �ص�iѭ�� i+1 �ٻص� jѭ�� j��ֵ�ֱ�Ϊ0�� j��ѭ��10��..
//		{
//			printf("hehe\n");//��ӡ10*10��hehe
//		}
//	}
//
//	return 0;
//}

//int main() {
//	int x,y;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)//����forѭ�� ͬʱ������������
//	{
//		printf("hehe\n");
//	}
//		return 0;
//}

//int main() {
//	int i = 1;
//	do {
//		printf("%d",i);
//		i++;
//	} while (i <= 10);
//	return 0;
//}

//int main() {
//	long int i = 1;
//	long int j = 1;
//	long int n = 0;
//	long int sum = 0;
//	for (n = 1; n <= 4; n++) {
//		//scanf("%d", &n);
//		while (i <  n)
//		{
//			i++;
//			j = j * i;
//			//printf("%d\n", j);
//		}
//		sum = sum + j;
//	}
//	printf(" % d\n",sum);
//	return 0;
//}

//int main() {
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		ret = ret * n;
//		//n�Ľ׳�
//		sum = sum + ret;
//	}
//	printf("%d \n",sum);
//	return 0;
//}

//��ķ�������Ԫ��
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k = 9;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//������Ԫ�صĸ���
//	for (i = 0; i < sz; i++) 
//	{
//		if (k == arr[i]) 
//		{
//			printf("�ҵ���,�±���: %d \n",i);
//			break;
//		}
//	}
//	if (i == sz)
//		printf("�Ҳ��� \n");
//	return 0;
//}


//�ö��ַ� ���ٲ��������һ��Ԫ��
//int main() {
//	int arr[] = {1,2,3,4,5,6,7,8,9,10 };
//	int k = 10;
//	int sz = sizeof(arr) / sizeof(arr[0]);//����Ԫ�ظ���
//	int left = 0;//���±�
//	int right = sz - 1;//���±����Ԫ�ظ�����һ
//	while (left <= right) {
//		int mid = (left + right)/2;//�м�Ԫ�ص��±�
//		if (arr[mid] > k)//�м�Ԫ���±���Ҫ�ҵ�Ԫ�����Ա�
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else 
//		{
//			printf("�ҵ���,�±���: %d\n", mid);
//			break;
//		}
//	}
//	if (left > right) {
//		printf("�Ҳ���");
//	}
//	return 0;
//}

//int main() {
//	//welcome to bit!!!!!!
//	//####################
//	//w##################!
//	//we################!!
//	//we###############!!!
//	//...
//	//welcome to bit!!!!!!
//	char arr[] = "abc";//�������ĸ�Ԫ��
//	//�±�ֱ��� a b c \0
//	//			 0 1 2
//	//4 - 1 �õ����� \0    4 - 2 �õ�����c
//
//	char arr1[] = "welcome to bit!!!!!!";//���Զ����ٿռ�[]���治����������
//	char arr2[] = "####################";
//	int left = 0;
//	//int right = sizeof(arr1) / sizeof(arr1[0] - 2);//err
//	int right = strlen(arr1)-1;//strlen����ȡ�ַ������Ȳ�����\0
//	
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];//arr1����ĵ�һ��Ԫ�� ����arr2����ĵ�һ��Ԫ��
//		arr2[right] = arr1[right];//arr2��������һ��Ԫ�� ����arr2��������һ��Ԫ��
//		printf("%s\n", arr2);
//		//��Ϣһ��
//		Sleep(1000);//ֹͣ1000����
//		system("cls");//ִ��ϵͳ����ĺ��� cls�����Ļ
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//
//			}

//int main() 
//{
//	int i = 0;
//	char password[20] = {0};
//	for (i = 0; i < 3; i++) 
//	{
//		printf("����������");
//		scanf("%s",password);
//		if(strcmp(password,"123456")==0)
////strcmp �����Ƚ������ַ��� ��Ȼ᷵��0 ��һ��Ԫ�ش��ڵڶ���Ԫ�� �᷵��һ������0��Ԫ�� 
////��һ��Ԫ��С�ڵڶ���Ԫ�� �᷵��һ��С��0�ĺ���
//		{
//			printf("������ȷ");
//			break;
//		}
//		else if(i == 3)
//		{
//			printf("���λ����Ѿ��ù�");
//			break;
//		}
//		else 
//		{
//			printf("����������������� \n");
//		}
//	}
//}