#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
/* �ж��������������� ����С��
����1 û�а�˳��� ֻ��ӡ�����ֵ
//int main() 
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	//char a[10], b[10], c[10];
//	printf("�������ַ���:");
//	//scanf("%s%s%s", &a, &b, &c); �����޷������Ƚ� �����
//	if ((a > b) && (a > c))
//	{
//		printf("%d", a);
//	}
//	else if((b > a) && (b > c))
//	{
//		printf("%d", b);
//	}
//	else if((c > a) && (c > b))
//	{
//		printf("%d", c);
//	}
//	else 
//	{
//		printf("���ã�");
//	}
//}

����2
int main() 
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("��������������");
	scanf("%d%d%d", &a, &b, &c); //&ǰ���и��ո�����
	if(a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
		//����һ��tmp �洢a��ֵ
		//��a < b ʱa b ͨ��һ��������������ֵ
	}
	if(a < c)//��a < b ��ʱ�൱�� b < c ���бȽ�
	{
		int tmp = a;
		a = c;
		c = tmp;
		//��a < c ʱa c ͨ��һ��������������ֵ
	}
	if(b < c)
	{
		int tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}
*/
// ���Լ������ շת�����
//int main() 
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//	scanf("%d%d", &m, &n);
//	while (m % n) 
//	{
//		r = m % n;
//		m = n;
//		n = r;
//	}
//	printf("%d\n", n);
//
//}

//���㼸���굽�������ж��ٸ�����
//int main() 
//{
//	int count = 0;
//	int year = 0;
//	for(year = 1000; year <= 2000; year++)
//	{
//		
//		if (year % 4 == 0 && year % 100 != 0)
//		{
//			printf("%d ",year);
//			count++;//������ͼ�1
//		}
//		else if (year % 400 == 0) 
//		{
//			printf("%d ", year);
//			count++;
//		}
//
//	}
//	printf("\n count = %d", count);
//	return 0;
//}
//����һ�и㶨
//int main()
//{
//	int count = 0;
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//
//		if((year%4 == 0 && year%100!= 0)||(year%400==0))
//		{
//			printf("%d ", year);
//			count++;//������ͼ�1
//		}
//	}
//	printf("\n count = %d", count);
//	return 0;
//}

//�Գ���
//int main() 
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i<=200; i++)//�ж�100��200������ ������
//	{
//		//�ж�i�Ƿ�������
//		//����2 ��i-1 ������
//		int j = 0;
//		for (j=2; j<i; j++)//���� 
//		{
//			if (i%j == 0)//�ӿ�ʼ ����������
//			{
//
//				break;//��������������
//			}
//		}
//		if (j == i)//ֻ�е�i%j û������ ִ�е�i=jʱ ��������
//		{
//			printf("%d\n", i);
//			count++;
//		}
//	}
//	return 0;
//	printf("\n count = %d",count);
//}

//շת����� �Ż��㷨: ��Ϊż�������������� �����ų�ż��
//���� i = a x b; ��ʱa,b�ض���һ����С�ڵ��� i�Ŀ�ƽ��
//���Կ������ж�һЩ�� sqrt���ǿ�ƽ��
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i+=2)//�ж�100��200������ ���Ǳ�����
//	{
//		//�ж�i�Ƿ�������
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)//���� 
//		{
//			if (i % j == 0)//�ӿ�ʼ ����������
//			{
//
//				break;//��������������
//			}
//		}
//		if (j > sqrt(i))//�������� i�Ŀ�ƽ�� �Ͳ����ж��� ֱ�Ӵ�ӡ
//		{
//			printf("%d\n", i);
//			count++;
//		}
//	}
//	return 0;
//	printf("\n count = %d", count);
//}

//1-100��9����
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{//��λΪ9
//			count++;
//		}
//		else if (i / 10 == 9)
//		{//ʮλΪ9
//			count++;
//		}
//	}
//	printf("count = %d\n", count);
//	return 0;
//
//}
//1-100�ж��ٸ�9
//int main()//����if��Ҫ��
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		//��λΪ9
//			count++;
//		if (i / 10 == 9)
//			count++;
//		
//	}
//	printf("count = %d\n", count);
//	return 0;
//
//}

//����һ��֮һ������֮һ������֮һ...��һ�ٷ�֮һ
//int main() 
//{
//	int i = 0;
//	double sum = 0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		//sum += 1 / i;//�������� ֻ��ȵ����� �ᶪʧ����
//		sum += flag * 1.0 / i;
//		flag = -flag;//ÿ��һ�� �ı�һ�η���
//	}
//	printf("%lf", sum);//��ӡ������
//}

//�ж�ʮ��Ԫ�صĴ�С
//int main()
//{
//	int arr[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
//	//int max = 0;//���ֵ�����Լ��趨ֵ 
//	int max = arr[0];//Ӧ������Ϊ������� �����Լ��趨������Զ���ᳬ�������Ԫ��ֵ
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//��ȡ���鳤��
//	for (i = 0; i < sz; i++) 
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max =%d",max);
//	return 0;
//}

//��ӡ�žų˷��ھ���
//int main() 
//{
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		//��ӡ����
//		int j = 1;
//		for (j = 1; j <= i; j++)//��ӡ����
//		{
//			printf("%d*%d=%d\t", i, j, i * j);//%-2d������� �����ո�
//		}
//		printf("\n");
//	}
//	return 0;
//}


//��������Ϸ
//void menu()
//{
//	printf("*****************888888888****");
//	printf("****** 1.Play  0. EXit    *****");
//	printf("**************888888888*******");
//
//}
////RAND_MAX; 16������ ֵ��32727
//void game() 
//{
//	//1.���������
//	int ret = rand();
//	int guess = 0;
//	ret = rand()%100+1;//0-32727 ģ��100����ķ�Χ��1-99 ���Լ�1 ����1-100
//	//printf("%d\n",ret);
//	//2.������
//	while (1)
//	{
//		printf("�������");
//		scanf_s("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´���\n");
//		}
//		else if (guess < ret) 
//		{
//			printf("��С��");
//		}
//		else 
//		{
//			printf("�¶���\n");
//			break;
//		}
//
//
//	}
//}
//int main() 
//{
//	//��ʱ��� �����������������ʼ�� 
//	srand((unsigned int)time(NULL));//��ȡʱ���
//	//srand �Ĳ�������Ҫint�� ��time�����Ӹ�unsigned int ת����int��
//	//srand ������������ĳ�ʼ������
//	//����ʱ���Ҫ������� ���ܷ������� һ�ξ���
//	int input = 1; 
//	do
//	{
//		menu();
//		printf("��ѡ��>:");
//		scanf_s("%d", &input);
//		switch(input)
//		{
//		case 0://�˳���Ϸ
//			printf("�˳���Ϸ");
//			break;//�����breakֻ������switch������
//		case 1:
//			game();//����game������ʼ����Ϸ
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while(input);// while 0Ϊ�� ����Ϊ�� ����һ�� ���� 0 while������
//	return 0;
//}

//goto���
//int main()
//{
//again:
//	printf("������");
//	goto again;//again �ŵ����� goto�������� �������ֱ������ĳ��λ�� ��ǿ���break ָ���ص㽵��
//	return 0;//goto������� bug֮��
//}

//int main() 
//{
//	char input[20] = {0};
//	//shutdown -s -t 60 �趨����60s��ػ�
//	//shutdown -aȡ������
//	system("shutdown -s -t 60");
//again:
//	printf("��ע��,��ĵ�����1�����ڹػ�,�������:������,��ȡ��: ");
//	scanf_s("%s", input);
//	if (strcmp(input, "������") == 0)//�Ƚ������ַ���-strcmp
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//		return 0;
//}
//int main() 
//{
//	// strcpy �ַ�������
//	// strlen �ַ������� 
//	char arr1[] = "bit";
//	char arr2[] = "##############";
//	strcpy(arr2, arr1);//��arr1��ֵ����arr2 ,����arr1�ĳ��� ҪС��arr2
//	//ԭ��������Ӧ����bit###########
//	//������bit ���и�\0 ����\0��ֹͣ������ ����#####��û��
//	printf("%s\n",arr2);
//	return 0;
//}

//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, '*', 5);//��ǰ����ַ� �������*
//	printf("%s\n",arr);
//	return 0;
//}
//// memset�� memory���ڵ�������ڴ� ������˼�Ǽ��䣩 set ����

//дһ���������Խ����������α���������
//void Swap1(int x ,int y )//void ���޷������� int x,int y�����β�
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//	return x, y;
//	//�˺���û�н�ֵ������������ȥ ����ԭa��b��ֵû�л���
//}
//void Swap2(int* pa, int* pb)//ָ����� �������յ�ַ int* pa, int* pbҲ���β�
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//  Swap1(a,b)//��ֵ����
//	Swap2(&a, &b);//��ַ���ã� & ȡ��ַ�� ��������&a,&b����ʵ��
//  
//	printf("a = %d,b =%d\n", a, b);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* pa = 20;//pa int���͵�ָ�����
//	*pa = 20;//�����ò��� 
//	printf("%d\n", a);
//	return 0;
//}