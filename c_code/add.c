#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void print()
{
	printf("####################################\n");
	printf("------------�����������ĺ�----------\n");
	printf("######==========================####\n");
	printf("\n");
	printf("������������ [�ո�ֿ�]��");
}

void ADD(long x,long y)
{
	printf("�������ĺ�Ϊ��%2d\n",x+y);
}

int main()
{
	print();
	long muna = 0;
	long munb = 0;
	while (1)
	{
		if ((scanf("%d %d", &muna, &munb)) == 2)
		{
			ADD(muna,munb);
			break;
		}
		else
		{
			printf("!!!!!!!!!!!!!!!!!\n");
			printf("=====�ǲ���Ϲ��������>:\n");
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}

	}

	return 0;
}