#define _CRT_SECURE_NO_WARNINGS 1
// C�������ű��100��

 NO.01
# include <stdio.h> 

// 1 2 3 4 ��������ɶ��ٸ�������ͬ�����ظ�����λ����   �ֱ��Ƕ���
int main()
{
	int i, j, k;  // ������������
	int a = 0;  //����
	printf("\n"); //��ӡ����
	for (i = 1; i <= 4; i++)  // ����Ϊ����ѭ��
	{
		for (j = 1; j <= 4; j++)
		{
			for (k = 1; k <= 4; k++)
			{
				if (i != k && i != j && j != k)  // ȷ��i��j��k��λ������ͬ
				{
					printf("%d %d %d\n",i ,j,k);
					a++;  // ��ӡһ�� ����1
					
				}
			}
		}
	}
	printf("һ����%d��\n", a);  // ��ӡ����
	return 0;
}

// NO.02
#include <stdio.h>

 //��ҵ���ŵĽ������������ɡ� �Ӽ������뵱������I����Ӧ���Ž���������
//����(I)���ڻ����10��Ԫʱ���������10% ��
//�������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10% ��ɣ�����10��Ԫ�Ĳ��֣������7.5 % ��
//20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5 % ��
//40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3 % ��
//60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5 % ��
//����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1 % ���

int main()
{
	double I;  //���½�����
	double  Bouns, Bouns1, Bouns2, Bouns4, Bouns6, Bouns10;  // 6����ͬ��������ɲ���
	Bouns = 1;
	printf("�����㵱�µ�����<");
	scanf("%lf", &I);
	Bouns1 = 100000 * 0.1;  //  ���ڵ��� 10�� �Ľ���
	Bouns2 = Bouns1 + 100000 * 0.075;  // ����10�� ����20��Ľ���  =  ����10��Ľ��� +  �߳�10�򲿷ֵĽ���
	Bouns4 = Bouns2 + 200000 * 0.05;
	Bouns6 = Bouns4 + 200000 * 0.03;
	Bouns10 = Bouns6 + 400000 * 0.015;
	
	if (I <= 100000)
	{
		Bouns = I * 0.1;  //�������10���  ����=  ����*10%
	}
	else if (I <= 200000)
	{
		Bouns = Bouns1 + (I - 100000) * 0.075;  // ���ڵ���10��Ľ������    �߳��Ĳ��� ��� 7.5%  
		
	}
	else if (I <= 400000)
	{
		Bouns = Bouns2 + (I - 200000) * 0.05;
	}
	else if (I < 600000)
	{
		Bouns = Bouns4 + (I - 400000) * 0.03;
	}
	else if (I <= 1000000)
	{
		Bouns = Bouns6 + (I - 600000) * 0.015;
	}
	else if (I > 1000000)
	{
		Bouns = Bouns10 + (I - 1000000) * 0.01;
	}
	printf("��Ľ���Ϊ��%lf\n",Bouns);
	return 0;
}


//NO.3

#include <stdio.h>

//һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�

int main()
{
	int i, j, m, n, x;
	for (i = 1; i < 168 / 2 + 1; i++)
	{
		if (168 % i == 0)
		{
			j = 168 / i;
			if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0)
			{
				m = (i + j) / 2;
				n = (i - j) / 2;
				x = n * n - 100;
				printf("%d + 100 = %d * %d\n",x,n,n);
				printf("%d + 268 = %d * %d\n",x,m,m);
			}
		}
	}
	return 0;
}


//NO.4
#include<stdio.h>

//����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
int main()
{
	int day, month, year,leap;
	int sum =0;
	printf("\n�������ꡢ�¡���,��ʽΪ���� �� �գ�2015 12 10��\n");
	scanf("%d %d %d",&year,&month,&day); 
	switch (month)
	{
	case 1:
		sum = 0;   // 1�²�����
		break;
	case 2:
		sum = 31;  // 2�� Ҫ���� 1�µ�����
		break;
	case 3:        // 3��  1�º�2�µ�����֮�ͣ�
		sum = 59;
		break;
	case 4:
		sum = 90;
		break;
	case 5:
		sum = 120;
		break;
	case 6:
		sum = 151;
		break;
	case 7:
		sum = 181;
		break;
	case 8:
		sum = 212;
		break;
	case 9:
		sum = 243;
		break;
	case 10:
		sum = 273;
		break;
	case 11:
		sum = 304;
		break;
	case 12:
		sum = 334;
		break;
	default:
		printf("date Error\n");
		break;
	}
	sum = sum + day; // ����ĳ�������
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))  //�ж��ǲ�������
	{
		leap = 1;
	}
	else
	{
		leap = 0;
	}
	if ((leap == 1) && (month > 2)) //������������·ݴ���2,������Ӧ�ü�һ��
	{
		sum++;
	}
	printf("����һ��ĵ�%d��\n",sum);

	return 0;
}

//NO.5
#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	// a>b>c
	printf("-------------------------------\n");
	printf("����������������:\n");
	printf("-------------------------------\n");
	printf("�ո�ֿ�\n");
	scanf("%d %d %d",&a,&b,&c);

	if ( a > b )  //���� a��b ��ֵ
	{
		int tmp = 0;
		tmp = a;   
		a = b;    
		b = tmp;   
	}
	if ( a > c )  
	{
		int tmp=0;
		tmp = a;    
		a = c;
		c = tmp;

	}
	if ( b > c ) 
	{
		int tmp = 0;
		tmp = b;
		b = c;
		c = tmp;

	}
	printf("%d  %d  %d", a, b, c);
	return 0;
}


//NO.6
#include<stdio.h>

//��* �������ĸC��ͼ��
int main()
{
	printf("     *\n");
	printf("  **    **\n");
	printf("**\n");
	printf("*\n");
	printf("**\n");
	printf("  **    **\n");
	printf("     *\n");

	return 0;
}

NO.7
#include<stdio.h>

//�������ͼ��������c���������У���һ����Very Beautiful!

int main()
{
    int a, b;
    for (a = 0; a < 5; a++) //��
    {
        for (b = 0; b < 5; b++) //��
        {
            if (a == b || (a + b+1) == 5)
            {
                printf("��");
            }
            else
                printf("��");
            
        }
        printf("\n");
    }
    return 0;
}


//NO.8
#include<stdio.h>
//���9*9�ھ�
int main()
{
	int i, j;
	for (i = 1; i <= 9;i++)
	{
		
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-3d",j, i, i*j);
		}
		printf("\n");
	}
	return 0;
}


NO.9
#include <stdio.h>
//Ҫ����������������̡�
int main()
{
	int i,j;
    for (i = 0; i < 8; i++) // ������
    {
        for (j = 0; j < 8; j++)  // ������
        {
            if ((i + j) % 2 == 0)
                printf("��");
            else 
                printf("��");
        }
        printf("\n");
    }
}




//NO.10
#include<stdio.h>
// ��ӡ¥�ݣ�ͬʱ��¥���Ϸ���ӡ����Ц��
int main()
{
	int i,j;
	printf("���\n");
	for (i = 1; i <= 11; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("����");
		}
		printf("\n");
		
	}
	return 0;
}


// No.11
#include <stdio.h>
int main()
//�ŵ����⣨�������̣�����һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�С���ӳ����������º�ÿ��������һ�����ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣������ǰ40���¼��ɣ�
//���ӵĳ�������Ϊ ÿ��   1  ��1  ��3 ��5  ��8   ��13  ��21   ���¸�������������֮�ͣ��ӵ������¿�ʼ��
//1 �� 2�� ����һֻ   ���µ�Ϊ ���º�����֮��
{
	long f1 = 1, f2 = 1;  // ��������
	int i;  //ѭ��
	int m =0; //�����·�

	printf("����Ҫ������·�_:");
	scanf("%d",&m);
	printf("\n");

	if (m % 2 == 1)  // �����·ݼ���ѭ������
	{
		m = (m+1) / 2;
	}
	else
	{
		m = m / 2;
	}
	for (i = 1;i <= m; i++)
	{
		printf("��%d������%dֻ����\n",i*2-1,f1);
		printf("��%d������%dֻ����\n", i * 2, f2);
		f1 = f1 + f2; //ǰ�����¼�������ֵ����������
		f2 = f1 + f2; //ǰ�����¼�������ֵ����������
	}

	return 0;
}


// No.12
#include <stdio.h>
//�ж� 101 �� 200 ֮���������
// ��һ�����ֱ�ȥ�� 2 �� sqrt(�����)������ܱ������������������������   ֻ�ܱ�1 �� ��������
int main()
{
	int i, j;
	int count=0;
	for (i = 101; i <= 200; i+=2) //ż��һ����������
	{
		for (j = 2; j < i; j++)
			if (i % j == 0) // �ж��ܷ�����   ������ѭ��
				break;
		if (j >= i)   //�ж�ѭ���Ƿ���ǰ��������� j < i ˵���� 2~j ֮��, i �п���������
		{
			count ++;   //������
			printf("%d ", i);

			if (count % 5 == 0) //  ���У��� count ������ÿ���������
				printf("\n");
		}

	}
	printf("\n");
	printf("100-200 һ����%d ������\n",count);
}


// No.13
#include<stdio.h>

int main()
//��ӡ�����е�"ˮ�ɻ���"
//���λ���������͵��ڸ��� �������磺153��һ��"ˮ�ɻ���"����Ϊ153=1�����η���5�����η���3�����η�
{
	int i, x, y, z;
	int count=0;
	for (i = 100;i < 1000; i++) // �������е���λ��
	{
		x = i % 10;           //ȡ����
		y = i / 10 % 10;     //ȡʮ��
		z = i / 100 % 10;     //ȡ����

		if (i == (x * x * x + y * y * y + z * z * z))
		{
			count++;  //����
			printf("%d ", i);
			
			if (count % 5 == 0) //ÿ���������
				printf("\n");
		}
	}
	printf("һ����%d��ˮ�ɻ���\n",count);
	return 0;
}



// No.13
#include<stdio.h>

int main()
//��ӡ�����е�"ˮ�ɻ���"��λ��
//���λ���������͵��ڸ��� ����
{
	int i, x, y, z,q;
	int count=0;
	for (i = 1000;i < 10000; i++) // �������е���λ��
	{
		x = i % 10;           //ȡ����
		y = i / 10 % 10;     //ȡʮ��
		z = i / 100 % 10;     //ȡ����
		q = i / 1000 % 10;    //ȡǧ��
		if (i == (x * x * x * x + y * y * y * y + z * z * z * z + q * q * q* q))
		{
			count++;  //����
			printf("%d ", i);
			
			if (count % 5 == 0) //ÿ���������
				printf("\n");
		}
	}
	printf("һ����%d��ˮ�ɻ���\n",count);
	return 0;
}

//No.14
#include<stdio.h>
//��һ���������ֽ������������磺����90, ��ӡ��90 = 2 * 3 * 3 * 5
int main()
{
	int n, j;
	printf("������һ��������");
	scanf("%d",&n);
	printf("%d=",n);

	for (j = 2; j <=n; j++)  // j����2 С��  n
	{
		while (n % j == 0)     // n �ܱ�j ���� ����ѭ��
		{
			printf("%d", j);   //��ӡ��һ�ε���   
			n /= j;  // n = n/j;  n =  n /2  
			if (n !=  1)   // �̲�Ϊ1   ��ӡ �˺�  
				printf("*");
		}
	}
	printf("\n");
	return 0;

}

//No.15
#include <stdio.h>

int main()
//�����������Ƕ������ɴ��⣺ѧϰ�ɼ� >= 90�ֵ�ͬѧ��A��ʾ��60 - 89��֮�����B��ʾ��60�����µ���C��ʾ
//(a > b) ? a : b��������������Ļ������ӡ�
{
	int score;
	char  grade;
	printf("�����������");
	scanf("%d",&score);
	grade = (score >= 90) ? 'A' : ((score >= 60) ? 'B' : 'C');

	printf("%c \n",grade);
	return 0;
}

// No.16
#include <stdio.h>
//��������������m��n���������Լ������С��������
int main()
{
	int a, b, r, n;
	printf("��������������:");
	scanf("%d %d", &a, &b);
	if (a < b)   // ��ֵ����   a>b;
	{
		int tmp;
		tmp = b;
		b = a;
		a = tmp;
	}
	r = a % b;  //  �ж��Ƿ��������    11
	n = a * b;  // �������� �ϴ�ֵΪ���Լ��  ��СֵΪ������    420
	while (r != 0)  //�ж� ȡģ��ֵ�Ƿ�Ϊ0��
	{
		a = b;
		b = r;
		r = a % b;  //
	}
	printf("�������������Լ����%d����С��������%d\n", b, n / b);
	return 0;
}