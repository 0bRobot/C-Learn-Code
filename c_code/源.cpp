#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <graphics.h>  // ��������ͼ�ο�ͷ�ļ�   

void outtextxy_int(int x, int y, char *format, int iNumber)
{
	char str[20] = "";
	sprintf(str,format,iNumber);
	outtextxy(x,y,str);
}

int main()
{
	initgraph(400, 600);  // ��ʼ������ (int  width,int height )
	//���Ͻ�Ϊ ԭ��  0   ��0
	// ���� Ϊ  x ��
	//���� Ϊ y ��
	setbkcolor(LIGHTRED);//���ñ�����ɫ
	cleardevice();  // ���ñ�����ɫ��Ҫˢ��
	

	putpixel(340,268,RED);  //����    ��ɫ�� ��ʾ��ɫ  BULE  BLACK ������
	for (int x = 0; x < 400; x += 2)  //for ѭ������� 
	{
		 putpixel(x, 268, RED);
	}
	setlinecolor(LIGHTBLUE);  //�����ߵ���ɫ
	line(10,10,10,100); //����
	//������
	setfillcolor(LIGHTCYAN); //���������ɫ
	rectangle(0, 0, 398, 598);
	fillrectangle(50, 50, 100, 130);
	
	setlinecolor(RGB(54,154,75));  //����Բ ������ɫ
	circle(70,40,40);  //��Բ

	setfillcolor(RED);
	solidcircle(100, 210, 34); //�ޱ߽��ߵ�Բ
	
	settextcolor(LIGHTGREEN);
	char outst[] = "NI Hao C!!!!";
	setbkmode(TRANSPARENT); //ȥ�����ֱ���
	//for (int i = 0; i <= 200; i += 20)
	//{
	//	cleardevice(); //�����ʾ�豸
	//	settextstyle(i, 0, "Consolas");  //������ ���
	//	outtextxy(10, 60, outst);  //�������  ʹ�ÿ��ֽ�
	//	Sleep(270);
	//}

	settextstyle(50, 0, "Consolas");  //������ ���
	outtextxy(80, 350, outst);  //�������  ʹ�ÿ��ֽ�

	outtextxy_int(200, 200, "���!% d", 1314); //�������

	getchar(); //�Ӵ��ڻ�ȡ����  ��ֹ���ڹر�

	closegraph(); //�رմ���
	return 0;
}