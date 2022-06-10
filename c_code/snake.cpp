#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <mmsystem.h>  //��ý��ӿڵ�ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��ý��ӿڵ�ͷ�ļ�

#define SNAKE_MUN 1000  //�ߵ���󳤶�
#define W_HIGHT 480  //���ڸ�
#define W_WIDE  880   //���ڿ�
/*
��Ŀ ̰���� 

֪ʶ��:�ṹ�壬ѭ�������� ��EasyX [ͼ�ν����]  �� ����
ͼ�λ�  ����һ��ͼ�δ���
*/

enum DIR  //ö��
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

struct Snakes  //�ߵĽṹ    
{
	int Size; //�ߵĳ���
	int Dir;  // �ߵķ���
	int speed; //�ߵ��ٶ�
	POINT Coor[SNAKE_MUN];// ����  x   y  POINT 2 ��long���ε� �ṹ��  [] ������Ҫ����


}Snakes;

struct Food
{
	int x;   //ʳ������
	int y;
	int r;   //ʳ���С
	bool flag;//�Ƿ񱻳�
	DWORD color; //ʳ����ɫ
}Food;

void GameInit()
{
	//���ű�������
	//mciSendString("open ./res/snake_bgm.mp3 alias BGM", 0, 0, 0);
	//mciSendString("play BGM repeat", 0, 0, 0);
	// init ��ʼ��  graph ͼ�δ���
	initgraph(W_WIDE, W_HIGHT);  //��ʼ��ͼ�δ��ڲ����ô�С��(640, 480,SHOWCONSOLE) ��ʾ����̨
	//�������������  srand()
	srand(GetTickCount());//һ����ʱ���  GetTickCount()��ȡϵͳ���������ڵĺ�����
								 
	//��ʼ����
	Snakes.Size = 3; //��ʼ��С
	Snakes.speed = 10; //��ʼ�ٶ�
	Snakes.Dir = RIGHT;    //����
	for (int i = 0; i < Snakes.Size; i++)
	{
		Snakes.Coor[i].x = 40-10*i;  //��ʼy����  y��������
		Snakes.Coor[i].y = 10;  //��ʼx����  x��������  ���Ͻ� ����Ϊ 0 0 
	}
	//��ʼ��ʳ��
	Food.x = rand()% W_WIDE; //ʳ������� �ڴ�������
	//rand() �������һ�����������û������������ӣ�ÿ�ζ��ǹ̶���������
	//��������������Ҫͷ�ļ� stdlib.h
	Food.y = rand() % W_HIGHT;
	Food.color = RGB(rand() % 256, rand() % 256, rand() % 256);  //�����ɫ
	Food.r = rand() % 10 + 5;
	Food.flag = true;

}

void BKColor()
{
	//˫�����ͼ
	BeginBatchDraw();
	//���ô��ڱ���
	setbkcolor(RGB(95, 211, 234)); //���ô��ڱ�����ɫ
	cleardevice();//������ɫ2��    ��ջ�ͼ�豸
	
	//������
	setfillcolor(GREEN);
	for (int i = 0; i < Snakes.Size; i++)
	{
		solidcircle(Snakes.Coor[i].x, Snakes.Coor[i].y, 6);   //����һ��Բ  �뾶Ϊ5
	}

	//����ʳ��
	if (Food.flag)
	{
		solidcircle(Food.x, Food.y, Food.r);
	}
	//˫�������
	EndBatchDraw();
}
	
//�ƶ���
void MoveSnake()
{
	//�ƶ������귢���ı�
	//���������ͷ�ƶ�
	for (int i = Snakes.Size-1; i > 0; i--)
	{
		Snakes.Coor[i] = Snakes.Coor[i - 1];
	}	
	switch (Snakes.Dir)
	{
	case UP:
		Snakes.Coor[0].y-=Snakes.speed;
		if (Snakes.Coor[0].y <= 0)  //y ����С��0  ����������߽�
		{
			Snakes.Coor[0].y = W_HIGHT-10;  // ��ǽ
		}
		break;
	case DOWN:
		Snakes.Coor[0].y += Snakes.speed;
		if (Snakes.Coor[0].y >= W_HIGHT) //y ������ڵ��ڴ��ڸ߶�  ������������߽�
		{
			Snakes.Coor[0].y = 10;
		}
		
		break;
	case LEFT:
		Snakes.Coor[0].x -= Snakes.speed;
		if (Snakes.Coor[0].x <= 0)
		{
			Snakes.Coor[0].x = W_WIDE-10;
		}
		break;
	case RIGHT:
		Snakes.Coor[0].x+=Snakes.speed;
		if (Snakes.Coor[0].x >= W_WIDE)
		{
			Snakes.Coor[0].x = 10;
		}
		break;

	}
}

//ͨ�������ı��ߵķ���
void InputKey()
{
	//�ж��Ƿ��а���
	if (_kbhit())
	{
		//�а���������
		switch (_getch())  //_getch()  ��ȡ����  ��Ҫͷ�ļ�  #include <conio.h>
		//_getch()  ��������  �������̻�ֹͣ����
		{
			//72  80 75 77  �������� ��ֵ
		case'w':
		case'W':
		case 72:
			if (Snakes.Dir != DOWN) //�����ߵ�ͷ
			{
				Snakes.Dir = UP;
			}
			break;
		case's':
		case'S':
		case 80:
			if (Snakes.Dir != UP)
			{
				Snakes.Dir = DOWN;
			}
			break;
		case'a':
		case'A':
		case 75:
			if (Snakes.Dir != RIGHT)
			{
				Snakes.Dir = LEFT;
			}
			break;
		case'd':
		case'D':
		case 77:
			if(Snakes.Dir != LEFT)
			{
				Snakes.Dir = RIGHT;
			}
			break;
		case ' ':  //�ո�  ��Ϸ��ͣ
			while (1)
			{
				if (_getch() == ' ')
					return;
			}
			break;
		}

	}
	
}
void EatFood()
{
	if ( Food.flag && Snakes.Coor[0].x >= Food.x-Food.r && Snakes.Coor[0].x <= Food.x+Food.r &&
		Snakes.Coor[0].y >= Food.y - Food.r && Snakes.Coor[0].y <= Food.y + Food.r)
		//�ж����Ƿ������� ʳ�����ꡣ �� Food flag Ϊ��
	{
		Food.flag = false;  //�Ե��Ժ�  flagΪ false
		Snakes.Size++;
	}

	if (!Food.flag) //ʳ����ʧ���³�ʼ��ʳ��
	{
		//��ʼ��ʳ��
		Food.x = rand() % W_WIDE-10; //ʳ������� �ڴ�������
		//rand() �������һ�����������û������������ӣ�ÿ�ζ��ǹ̶���������
		//��������������Ҫͷ�ļ� stdlib.h
		Food.y = rand() % W_HIGHT-10;
		Food.color = RGB(rand() % 256, rand() % 256, rand() % 256);  //�����ɫ
		Food.r = rand() % 10 + 10;
		Food.flag = true;

	}

}

int main()
{
	GameInit();
	
	while (1)//��ֹͼ�λ��˳�
	{
		BKColor();
		MoveSnake();
		InputKey();
		EatFood();
		Sleep(100);
	}
	return 0;
}
