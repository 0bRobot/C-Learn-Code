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

// No.17
#include <stdio.h>

int main()
//����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����
{
	char c;  //char �ַ���
	int ZM = 0, spaces = 0, Nu = 0, other = 0;
	printf("������һд����\n");
	while ((c = getchar()) != '\n')  //��ȡ�����ֵ   
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))   //�ж���ĸ  getchat  ��ֵ ���� aA   С�� zZ  �߼��� �߼���
		{
			ZM++;
		}
		else if (c >= '0' && c<= '9')  //  �ַ�  ���뵥����
		{
			Nu++;
		}
		else if (c == ' ')   ////  �ַ�  ���뵥����
		{
			spaces++;
		}
		else
			other++;
	}
	printf("��ĸ=%d ����=%d �ո�=%d ����=%d \n", ZM, Nu, spaces, other);

		
}

//No.18
#include<stdio.h>
int main()
{
    int s = 0, a, n, t;
    printf("������ a �� n��\n");// a  ��ֵ  n �ǼӼ���
    scanf("%d%d", &a, &n);
    t = a;
    while (n > 0)
    {
        s += t;
        a = a * 10;  //2+22+222     ÿ��һ�� ����*10  �ټ���ԭ����a
        t += a;
        n--;
    }
    printf("a+aa+...=%d\n", s);
}

//No.19
#include <stdio.h>
//һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ"����"������6=1��2��3����ҳ�1000���ڵ�������
#define N 1000

int main()
{
	int i, j, k, n, sum;
	int a[256];
	
	for (i = 2; i <= N; i++)  //���� 2 -1000 ����
	{
		sum = a[0] = 1;
		k = 0;
		for (j = 2 ; j <= (i / 2); j++)
		{
			if (i % j == 0)
			{
				sum += j;
				a[++k] = j;
			}
		}
		if (i == sum)
		{
			printf("%d=%d", i, a[0]);
			for (n = 1; n <= k; n++)
				printf("+%d", a[n]);
			printf("\n");
		}
	}
	return 0;
}

//No.20

#include <stdio.h>

int main()
{
	float h, s;
	h = s = 100;
	h /= 2;  //��һ�η����߶�
	for (int i = 2; i <= 2; i++)   //���Ʒ�������
	{
		s = s + 2 * h; 
		h /=2;  //�ߵ�ÿ�μ���һ��
	}
	printf("10����ؾ���%f�ף���10�η����߶�%f", s, h);
	return 0;
}

//NO.21
#include <stdio.h>

int main()
// ���ӵ�һ��ժ�����ɸ����ӣ���������һ�룬����񫣬�ֶ����һ��
//�ڶ��������ֽ�ʣ�µ����ӳԵ�һ�룬�ֶ����һ�����Ժ�ÿ�����϶�����ǰһ��ʣ��
//��һ����һ�� ����10���������ٳ�ʱ����ֻʣ��һ�������ˡ����һ�칲ժ�˶���
//x1Ϊǰһ������������x2Ϊ�ڶ����������� ��x2=x1/2-1, x1=(x2+1)*2 
{
	int x = 1, day = 9;
	while (day > 0)
	{
		x = (x +1)*2; //�ڶ����1 ��2����ǰһ�������
		day--;

	}
	printf("%d", x);
	return 0;
}

int main()
{
	int x = 1534, day = 9, n;
	while (day<10&&day!=0)
	{
		x = x / 2 - 1;
		day--;

	}
	return 0;
}

//No.22
#include<stdio.h>
//
int main()
// ��ƹ����ӽ��б������������ˡ��׶�Ϊa,b,c���ˣ��Ҷ�Ϊx,y,z���ˡ��ѳ�ǩ���������������������Ա����������������a˵������x�ȣ�c˵������x,z�ȣ�
{
	char  a, b, c;
	for (a = 'x'; a <= 'z'; a++)
	{
		for (b = 'x'; b < 'z'; b++)
		{
			if (a != b)
			{
				for (c = 'x'; c < 'z'; c++)
				{
					if (a != c && b != c)
					{
						if (a != 'x' && c != 'x' && c != 'z')  // a˵������x�ȣ�c˵������x,z��
							printf("a->%c  b->%c  c->%c",a,b,c);
					}
				}
			}

		}
	}

	return 0;
}

No.23
#include <stdio.h>
//��ӡ����
int main()
{
	int i, j, k;
	for (i = 0; i <= 3; i++)  //ѭ�����ƴ�ӡ  ��������   ������
	{
		for (j = 0; j <= 2 - i; j++)     // ��������ո�
		{
			printf(" ");
		}
		for (k = 0; k <= 2 * i; k++)   //�������*
		{
			printf("*");
		}
		printf("\n");    
	}
	for (i = 0; i <= 2; i++)  //ѭ�����ƴ�ӡ  �������� 
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= 4 - 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//No.24
#include <stdio.h>
//��һ�������У�2/1��3/2��5/3��8/5��13/8��21/13...���������е�
//ǰ20��֮��
int main()
{
	int  t;
	float sum = 0;
	float a = 2, b = 1;
	for (int i=1;i<=20;i++)
	{
		sum = sum + a / b;  // a/b ��ֵ��ֵ��sum   
		t = a;   // a �ĸ�ֵ�� ��ʱ����t
		a = a + b;  // a+b ��ֵ ��ֵ��a
		b = t;  // ��ʱ����t ��ֵ��b  
	}
	printf("%9.6f\n",sum);
	return 0;
}

//No.25
#include <stdio.h>
// ��1+2!+3!+...+20!�ĺ͡�  
// �� 1+ 2*1+3*2*1+4*3*2*1 ...
int main()
{
	long double sum=0,mix=1;
	for (int i = 1; i <= 4; i++)
	{
		mix = mix * i;
		sum = sum + mix;
	}
	
	printf("%Lf",sum);  //%Lf ����� long double �ͱ���   %f ����� double �ͱ��� %f ����� float �ͱ���
	return 0;
}

//No.26
#include <stdio.h>
// ���õݹ鷽����5!��  
int fact(int j)
{
	int sum;
	if (j == 0)
	{
		sum = 1;
	}
	else
	{
		sum = j * fact(j - 1);
	}
	return sum;
}

int main()
{
	int fact(int);
	for(int i = 0; i <= 5; i++)
	{
		printf("%d!=%d\n",i,fact(i));
	}
	return 0;
}

//No.27
#include <stdio.h>
//���õݹ麯�����÷�ʽ�����������5���ַ������෴˳���ӡ����
void Prinf(n)
int n;
{
	char next;
	if (n <= 1)
	{
		next = getchar();
		printf("����෴˳��\40:\40");
		putchar(next);
	}
	else
	{
		next = getchar();
		Prinf(n - 1);
		putchar(next);
	}
}

int main()
{
	int i = 5;
	void Prinf(int n);
	printf("������5���ַ�\40:\40");
	Prinf(i);
	printf("/n");
	return 0;
}

// No.28
//��5��������һ���ʵ�����˶����ꣿ��˵�ȵ�4���˴�2�ꡣ�ʵ�4������������˵�ȵ�3���˴�2�ꡣ�ʵ������ˣ���˵�ȵ�2�˴����ꡣ�ʵ�2���ˣ�˵�ȵ�һ���˴����ꡣ����ʵ�һ���ˣ���˵��10�ꡣ���ʵ�����˶��
#include <stdio.h>
int age(n)
int n;
{
	int c;
	if (n == 1) c = 10;
	else
	{
		c = age(n - 1) + 2;
		}
	return(c);
}

int main()
{
	printf("%d\n", age(5));
	return 0;
}

// No.29 
//��һ��������5λ����������Ҫ��һ�������Ǽ�λ�������������ӡ����λ���֡�
#include<stdio.h>
int main()
{
	long a, b, c, d, e, x;
	printf("������5���ַ���");
	scanf("%ld", &x);
	a = x / 10000; //�����λ
	b = x % 10000 / 1000;  //���ǧλ
	c = x % 1000 / 100;  //��İ�λ
	d = x % 100 / 10; //���ʮλ
	e = x % 10; //��ĸ�λ

	if (a != 0) {
		printf("Ϊ 5 λ��,����Ϊ�� %ld %ld %ld %ld %ld\n", e, d, c, b, a);
	}
	else if (b != 0) {
		printf("Ϊ 4 λ��,����Ϊ�� %ld %ld %ld %ld\n", e, d, c, b);
	}
	else if (c != 0) {
		printf("Ϊ 3 λ��,����Ϊ��%ld %ld %ld\n", e, d, c);
	}
	else if (d != 0) {
		printf("Ϊ 2 λ��,����Ϊ�� %ld %ld\n", e, d);
	}
	else if (e != 0) {
		printf("Ϊ 1 λ��,����Ϊ��%ld\n", e);
	}
	return 0;
}


// No.30
#include <stdio.h>
// �г�������λ���Ļ�����
// һ��5λ�����ж����ǲ��ǻ���������12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ
int main()
{
	int count = 0;
	for (int i = 10000; i <= 99999; i++)
	{
		int w=0, q=0, s=0, g=0;
		w = i / 10000;   // ����λ��ֵ
		q = i % 10000 / 1000;  // ��ǧλ��ֵ
		s = i % 100 / 10;   // ��ʮλ��ֵ
		g = i % 10;     // ���λ��ֵ
		
		if(w==g&&q==s)  //�ж� ��λ�͸�λ   ǧλ��ʮλ�Ƿ����
		{
			count++;
			printf("%d  ",i);

			if (count % 9 == 0) //  ���У��� count ������ÿ���������
				printf("\n");

		}
	}
	printf("һ����%d��������",count);
	return 0;
}

//NO.31

#include<stdio.h>
//���������ڼ��ĵ�һ����ĸ���ж�һ�������ڼ��������һ����ĸһ����������жϵڶ�����ĸ


int main()
{
	char i, j;
	printf("���������ڵĵ�һ����ĸ��\n");
	scanf("%c",&i);
	getchar();  //getchar()��ȡ����
	switch (i)
	{
	case 'm':
		printf("monday  1 \n");
		break;
	case 'w':
		printf("wednesday  3\n");
		break;

	case 'f':
		printf("friday 5  \n");
		break;
	
	case 't':
		printf("��������һ����ĸ��\n");
		scanf("%c", &j);
		if (j == 'h')
		{
			printf("thursday   4\n");
			break;
		}
		if (j == 'h')
		{
			printf("thesday  2\n");
			break;
		}
	case 's':
		printf("��������һ����ĸ��");
		scanf("%c",&j);
		if (j == 'a')
		{
			printf("saturday 6\n");
			break;
		}
		if (j == 'u')
		{
			printf("sunday  7\n");
			break;
		}
	default:
		printf("�������\n");
		break;
	}

	return 0;

}

#include <stdio.h>
#include <math.h>


int main()
{
	float a, b, c,x;
	float K, S, Q, Y,Z;

	printf("����������ֵ��<");
	scanf("%f %f %f",&a,&b,&c);
	getchar();
	if (a == 0 && b == 0)
	{
		printf("Data error\n");
	
	}
	if (a == 0 && b != 0)
	{
		x = -c / b;
		printf("%f", x);
	}
	K = pow(b, 2) - 4.0 * a * c;
	if (K < 0)
	{
		printf("�޽�");
	}
	else if( K==0 )
	{
		S = -b / (2 * a);
		printf("%f", S);
	}
	else
	{
		Q = sqrt(K);
		Y = (-b + Q) / (2.0 * a);
		Z = (-b - Q) / (2.0 * a);
		printf("%f%f", Y, Z);
	}


	return 0;
}

//NO.32
// ɾ��һ���ַ����е�ָ����ĸ���磺�ַ��� "aca"��ɾ�����е� a ��ĸ��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* DelChar(char* sdel, char* sCH)
{
	int AA[256];
	if ( sdel == NULL )  //�ж�ɾ����ĸ�Ƿ�Ϊ��
		return sCH;      // Ϊ�շ��� sCH

	for (int i = 0; i < 256; i++)
		AA[i] = 0;
	for (int i = 0; i < strlen(sdel); i++) // ��ɾ���ַ������� �Ƿ�Ϊ1
		AA[sdel[i]] = 1;
	
	int bb=0;
	for (int i = 0; i < strlen(sCH); i++) //�ȱ���Ŀ���ַ�������
	{
		if (!AA[sCH[i]])
			sCH[bb++] = sCH[i];
	}
	sCH[bb] = '\0';
	return sCH;
}

int main()
{
	char del[2] = "a";   //Ҫɾ������ĸ
	char CH[7] = "abcdard"; // Ŀ���ַ���
	printf("%s\n", DelChar(del, CH));
	return 0;
}

//No33
#include<stdio.h>
#include<math.h>
#define MAX 1000

//�ж�һ�������Ƿ�Ϊ���� /����

int prime[MAX];

int isPrimeNaive(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    int limit = (int)sqrt((double)n);
    for (int i = 3; i <= limit; i = i + 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void sieve()
{
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i < MAX; i++)
        prime[i] = 1;
    int limit = (int)sqrt((double)MAX);
    for (int i = 2; i <= limit; i++)
    {
        if (prime[i])
            for (int j = i * i; j <= MAX; j += i)
                prime[j] = 0;
    }
}

int isPrimeSieve(int n)
{
    if (prime[n])
        return 1;
    else
        return 0;
}

int main()
{
    sieve();
    printf("N=%d %d\n", 1, isPrime(1));
    printf("N=%d %d\n", 2, isPrime(2));
    printf("N=%d %d\n", 3, isPrime(3));
    printf("N=%d %d\n", 4, isPrime(4));
    printf("N=%d %d\n", 7, isPrime(7));
    printf("N=%d %d\n", 9, isPrime(9));
    printf("N=%d %d\n", 13, isPrime(13));
    printf("N=%d %d\n", 17, isPrime(17));
    printf("N=%d %d\n", 100, isPrime(100));
    printf("N=%d %d\n", 23, isPrime(23));
    printf("N=%d %d\n", 1, isPrime(1));
    return 0;
}

// No 34
#include <stdio.h>
// �����ĵ���
void hello_p()  //�����õĺ���
{
	printf("hello world��\n");
}

void three_hellos()
{
	int a;
	for (a = 1; a <= 5; a++)
		hello_p();//���ú���
}

int main()
{
	three_hellos(); //���ú���
}

#include <stdio.h>
// �ַ�����ת

void reverse(char* s)
{
	int len = 0;
	char* p = s;
	while (*p != 0)
	{
		//printf("%s", p);
		len++;         //���ַ�������
		p++; //ָ������   
	}

	int i = 0;
	char c;
	while (i <= len / 2 - 1)
	{  //�����ַ���
		c = *(s + 1);
		*(s + i) = *(s + len - 1 - i);
		*(s + len - 1 - i) = c;
		i++;

	}

}
int main()
{
	char s[] = "nihaoa!";
	printf("%s \n", s);
	reverse(s);// ��ת�ַ���
	printf("%s\n", s);
	return 0;
}

#include <stdio.h>
#include <math.h>
//��100���ڵ�����
int main()
{
    int i, j, k, n = 0;
    for (i = 2; i <= 100; i++)
    {
        k = (int)sqrt(i);
        for (j = 2; j <= k; j++)
            if (i % j == 0) break;
        if (j > k)
        {
            printf("%d ", i);
            n++;
            if (n % 5 == 0)
                printf("\n");
        }
    }
    return 0;
}

#include<stdio.h>
#define N 3
int main()
{
    int i, j, a[N][N], sum = 0,sum1=0;  // 3 �� 3 ��
    printf("���������(3*3)��\n");
    
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    
    for (i = 0; i < N; i++)
    
        sum += a[i][i]; //  a[0][0] + a [1][1] + a [2][2]


    printf("�Խ���֮��Ϊ��%d\n", sum);
    printf("�Խ���֮��Ϊ��%d\n", sum1 = a[0][2] + a[1][1] + a[2][0]);

    return 0;
}

#include <stdio.h>
//No 39
//��һ���Ѿ��ź�������顣������һ������Ҫ��ԭ���Ĺ��ɽ�������������
int main()
{
    int a[12]={1,4,6,9,13,16,19,28,40,65,100};
    int temp1,temp2,number,end,i,j;
    printf("ԭʼ������:\n");
    for(i=0;i<11;i++)
        printf("%4d",a[i]);
    printf("\n����һ���µ�����: ");
    scanf("%d",&number);
    end=a[10];
    if(number>end)
        a[10]=number;
    else
    {
        for(i=0;i<11;i++)
        {
            if(a[i]>number)
            {
                temp1=a[i];
                a[i]=number;
                for(j=i+1;j<12;j++)
                {
                    temp2=a[j];
                    a[j]=temp1;
                    temp1=temp2;
                }
                break;
            }
        }
    }
    for(i=0;i<12;i++)
        printf("%4d",a[i]);
    printf("\n");
    return 0;
}

// No_40
//��һ�������������
#include<stdio.h>
#define N 11
int main()
{
    int a[N] = { 0,1,2,3,4,5,6,7,8,9,10};
    int i, t;
    
    printf("ԭʼ������:\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);


    for (i = 0; i < N / 2; i++)  // �õ�һ�������һ������
    {
        t = a[i];
        a[i] = a[N - 1 - i];
        a[N - 1 - i] = t;
    }
   
    printf("\n����������:\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
