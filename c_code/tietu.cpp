#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main()
{
	initgraph(600 ,880);
	IMAGE  imgs;  //�����洢ͼƬ�ı���
	//loadimage (&imgs,"123.png");  //��Ϊ���ֽ�     ͼƬ���ص��ڴ�
	loadimage(&imgs, "123.png",560,600);//�����ѹ��ͼƬ  ��ͼƬ���ô���
	// 560,300, ��ʾͼƬ�Ĵ�С
	// ,0,300   ͼƬ������ĸ�λ�ÿ�ʼ  ԭͼ��ʾ�°벿��
	//putimage(0, 0, 560, 300, &imgs, 0, 300);   // ͼƬ�����  ��λ��   ԭͼ��ʾ�°벿��
	putimage(0,0, 560,300, &imgs,0,0);   //��ʾ�ϰ벿��
	//˼�� ��ͼƬ ������ʾ���    for ѭ��

	//������
	MOUSEMSG m;  // ����һ���洢�����Ϣ�ı���
	while (1)  //һֱ��ȡ�����Ϣ
	{
		m = GetMouseMsg(); //��ȡ�����Ϣ
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE: //����ƶ�

			break;
		case WM_LBUTTONDOWN: //�����갴��
			circle(m.x,m.y,50);  // ��Բ ���������Ϊ��׼
			break;
		case WM_RBUTTONDOWN: //����ʼ�����
			rectangle(m.x-5,m.y-5,m.x+10,m.y+10);
			break;
		}
	}



	getchar();
	closegraph();
	return 0;
}