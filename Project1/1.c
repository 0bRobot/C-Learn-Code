
#define  _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
//
//int main()
//{
//	int a = 4;
//	printf("%d \n", a);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int a = 20;
//	int* d = &a; // d ��һ����ַ��������ָ�������  int*   int ��Ӧ a ����������  * ����a ����ָ�������
//	//printf("%p \n", d);  // %p ��ӡ ��ַ/ָ�� 
//	*d = 2021; // *��Ӧ�ò�����/ ��ӷ��ʲ�������   �޸Ķ�Ӧ�ĵ�ַ�����ֵ��
//	printf("%d \n", a); //��ӡ a  ��� 2021.
//	return 0;
//}
//
//int main()
//
//{
//	double cc = 3.141546;
//	double* ff = &cc;
//	*ff = 7.834525;
//	printf("%lf\n", cc);  //double ����%lf ��ӡ
//	printf("%lf \n", *ff);  // ֱ�Ӵ�ӡ *ff
//	printf("%d \n", sizeof(ff)); //  ���е�ָ������ x86  4���ֽ�  x64 8���ֽ�  // ���ܱ������͵ĳ���
//	return 0;
//}


//�ṹ��  
 //char  int double  �� ������  ���Ӷ���     ������� ���� ����
//���Ӷ��� �����ṹ��
//�Լ����������һ������
//
//#include <string.h>
//
//	struct ren       //struct  �ṹ��ؼ��� 
//	{
//		char name[20];
//		short nianlin;
//		char  xinbei[20];
//	};
//
//	int main()
//	{
//		struct ren NO1 = { "����",22,"��" }; //��һ��д��
//		//NO1.nianlin = 54; // �޸����䡣  ��������ֱ�Ӹ�ֵ  
//		// ���鲻�ܸ�ֵ  
//		strcpy(NO1.name, "�Ź���"); 
//		// strcpy -- string copy  �ַ���������  �⺯��  ���ͷ�ļ���
//		
//		struct ren* DD = &NO1;  //ȡ��ַ ��DD
//
//		//printf("%s\n", (*DD).name);
//		//printf("%d\n", (*DD).nianlin); // ��Ӧ��   �ڴ�ӡ
//		//printf("%s\n", (*DD).xinbei);
//
//
//		printf("%s \n" ,DD->name);
//		printf("%d \n", DD->nianlin);
//
//		//################### . �ṹ����� . �ҵ���Ա
//		//###################  -> �ṹ��ָ��-> �ҵ���Ա��
//
//		//printf("˭%s\n", NO1.name);
//		//printf("����%d\n", NO1.nianlin);
//		//printf("�Ա� %s \n", NO1.xinbei);
//
//		return 0;
//	}

//struct stu {
//	char name[40]; //����
//	int mum; //���
//	int age; // ����
//	char groups[30]; //��
//}class[2] = {
//	{"�Ź���",001,43, "����"},
//	{"����",002,53,'����'}
//};
//int main()
//{
//	printf("˭%s \n", class->name); // ���Դ�ӡ Ĭ������һ�� class
//	return 0;
//}


// c������һ��  �ṹ���� �����������
//1. ˳��ṹ 
//2.ѡ��ṹ   ��֧���  if   switch  
//3. ѭ���ṹ   while   for   dowhile


//ѡ��ṹ  //   ��֧���   
//ѭ���ṹ  // ѭ�����
 
//���  ��c��������һ���ֺ�; �����ľ���һ�����
//; �����  ��һ�������

//��֧���  ѡ�����


//if

//#include <stdio.h>

//int main()
//{
//	//;// �����  �����
//
//	int age = 45;
//	/*if (age < 18)
//		printf("δ����\n");*/   // ����֧
//	if (age < 18)
//		printf("δ����\n"); // ˫��֧   if ����� ���ʽ
//	else
//		printf("������\n");
//
//	return 0;
//}

//int main()
//{
//	int age = 124;
//	if (age < 18)
//		printf("δ����\n");
//	//else if (18 <= age < 28) // �����߼����󡣡�
//	else if (age >= 18 && age < 28)
//		printf("����\n");
//	else if (age >= 28 && age < 50)
//		printf("����\n");
//	else if (age >= 50 && age < 90)
//		printf("����\n");
//	else
//		printf("��˵�� ��ţ��!!! \n");
//
//	return 0;
//}

//int main()
//{
//	int age = 54;
//	if (age < 18)
//		printf("δ����\n");
//	else   // Ƕ�� if  else   ţ���� ���Զ��Ƕ��
//	{
//		if (age >= 18 && age < 28)
//			printf("����\n");
//		else if (age >= 28 && age < 50)
//			printf("����\n");
//		else if (age >= 50 && age < 90)
//			printf("����\n");
//		else
//			printf("��˵�� ��ţ��!!! \n");
//
//	}
//	
//		return 0;
//}


// c ������  0 ��ʾ��   ��0 ��ʾ��  ��-1  Ҳ��ʾ�棩
//������ʽ����ִ�ж������  ʹ�ô����
//
//int main()
//{
//	int a = 45;
//	
//	if (a < 18)
//	{
//		printf("��δ����\n");  //   һ�������� ����һ�������
//		printf("��������ߺ�� \n");//  if  else  ���ƶ������ ����ʹ�ô����
//	}
//	else
//	{
//		printf("18����ֹ\n");
//		printf("�㶮�� \n");
//	}
//	return 0;
//}


//else ��������
//int main()
//{
//	// c ������  0 ��ʾ��   ��0 ��ʾ��
//	int a = 0;
//	int b = 2;
//	if (a == 1) // Ϊ��  ��ִ�С� // else ��������δƥ���if ƥ�䡣
//
//		if (b == 2)
//			printf("nihao\n");   // else ��������δƥ���if ƥ�䡣
//		else
//			printf("���\n"); // else ��������δƥ���if ƥ�䡣
//
//
//	return 0;
//}


//int main()
//{
//	// c ������  0 ��ʾ��   ��0 ��ʾ��
//	int a = 0;
//	int b = 2;
//	if (a == 1) // Ϊ��  ��ִ�С� // else ��������δƥ���if ƥ�䡣
//
//	{
//		if (b == 2)
//			printf("nihao\n");   // else ��������δƥ���if ƥ�䡣
//	}
//		else
//			printf("���\n"); // else ��������δƥ���if ƥ�䡣
//
//
//	return 0;
//}
//
//int main()
//
//{
//	int mun = 4;
//	if (mun = 7)  //  =  �Ǹ�ֵ       ==  ���ж�  ��������
//	if (7 == mun) // �����ж� ����д���
//	{
//	
//		printf("����һ᲻�ᱻ��ӡ \n");
//	}
//
//
//	return 0;
//}


// ���1-100��������

int main()

{
	int a = 0;
	while (a<=100)
	{
		if (a % 2 == 1)
			printf("%d  ", a);
		a++;
	}
	

	return 0;
}


//int main()
//
//{
//	int a = 1;
//	while (a <= 100)
//	{
//		printf("%d ", a);
//		a += 2;
//	}
//
//
//	return 0;
//}

//switch ���   Ҳ��һ�ַ�֧��� �������ڶ��֧�����

