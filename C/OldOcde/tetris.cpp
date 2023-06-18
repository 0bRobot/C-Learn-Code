//#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h> //Windows  API
#include "resource.h"
//  main()  ����̨ ��ں���
//WINAPI  �൱�� man���������
// HINSTANCE  Ӧ�ó���ʵ���������  ID

//���ڴ����� ����
LRESULT WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//��ͼ���� ����
void On_Paint(HDC U_Hdc);
//���Ʒ���
void DrawBlock(HDC U_Hdc);

//��Ϸ��ͼ
//��ά����ʵ�ֶ���˹��Ϸ
// 0 ��ʾ�հ�    1  ��ʾ ����ķ���   2 �Ѿ����µķ���
int g_background[20][10] =  // 20.�� 10 ��
{
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,0}
};

int WINAPI WinMain (HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR lpCmdLine,int nCmdShow ) //����4������    ��ջ��ʽ
{
	//����һ����Ϣ��ʾ��
	//MessageBox(NULL, L"�����ҵĵ�һ�����ڳ���", L"��ʾ", MB_YESNO); //MB_YESNO ѡ���Ƿ�
	//��ƴ�����
	
	// 1. ��ƴ�����
	TCHAR szAppClassName[] = TEXT("MRGUI");  // TCHAR  ���ַ�  TEXT  �Զ���Ӧ�ַ���
	WNDCLASS wc;  //
	wc.cbClsExtra = 0; //������Ķ���ռ��С
	wc.cbWndExtra = 0; //������չ�ռ��С
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���ذ�ɫ������ˢ
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); //���ع��
	wc.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1)); //����ͼ��
	wc.hInstance = hInstance;   //��ǰӦ�ó���ʵ�����
	wc.lpfnWndProc = WindowProc; //���ڴ�����
	wc.lpszClassName = szAppClassName; //����������
	wc.lpszMenuName = NULL;   //�˵��� 
	wc.style = CS_HREDRAW | CS_VREDRAW;   // ������ķ��

	
	//2 ע�ᴰ����
	RegisterClass(&wc);
	
	//3 ��������
	HWND hWnd = CreateWindow(
		szAppClassName,       //����������
		TEXT("����˹����"),
		WS_OVERLAPPEDWINDOW, //��������
		300,200,          //�������Ͻ�����
		600,820,           // ���ڿ�͸�
		NULL,	//�����ھ��
		NULL,			//�˵����
		hInstance,       //Ӧ�ó���ʵ�����
		NULL			//����
		);
	// 4. ��ʾ����
	ShowWindow(hWnd, SW_SHOW);
	
	//5. ���´���
	UpdateWindow(hWnd);


	// 6.��Ϣѭ��  // while  sellp ���³������½���
	MSG U_msg;
	while (GetMessage(&U_msg, NULL, 0, 0)) //����WM_QUIt �����˳�
		//���ܷ���  ����ѭ��
	{
		//�����ⰴ����Ϣװ��Ϊ�ַ���Ϣ
		TranslateMessage(&U_msg);
		//����Ϣ�ַ������ڴ���������
		DispatchMessage(&U_msg);
	}
	

	return 0;
	
}

//���ڴ�����
//windows ͨ����Ϣ��������   �������̨һ��ִ��
LRESULT WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT U_PS;
	HDC U_Hdc;
	switch (uMsg)
	{
	case WM_PAINT: //���ڻ�ͼ��Ϣ   �����ڴ����ϻ�ͼ
	U_Hdc =	BeginPaint(hWnd,&U_PS); //��ʼ��ͼ  ���Ǹ������ϡ����ݱ��浽 U_PS�ṹ����
	On_Paint(U_Hdc); //��ͼ����
		
		//���ƾ���
		//Rectangle(U_Hdc,10,10,200,100);  //�ͻ�������ϵ  ���� y
		//����Բ
		//Ellipse(U_Hdc,80,80,200,200); //����Բ
		
		EndPaint(hWnd,&U_PS);//������ͼ
		break;
	
	case WM_CLOSE: //���ڹر���Ϣ  ���Ͻǹر� ��VM_CLOSE
		break;
	case WM_DESTROY:   // ����������Ϣ
		PostQuitMessage(0);// ����0  Ϊ��  
		break;

	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//��ͼʵ��
void On_Paint(HDC U_Hdc)  //U_Hdc  ������ʾ
{
	//˫����  
	//�����ƶ� ���»���  ����˸
	HDC HMenDC = CreateCompatibleDC(U_Hdc);
	HBITMAP hBackBMP =  CreateCompatibleBitmap(U_Hdc, 600, 820);  //�ڴ� ���� ȫ��
	SelectObject(HMenDC, hBackBMP);
	DrawBlock(HMenDC);

	//���ڴ渴�Ƶ�����
	BitBlt(U_Hdc, 0, 0, 600, 820, HMenDC, 0, 0, SRCCOPY);

}

//���Ʒ���
void DrawBlock(HDC U_Hdc)
{
	//����һ������  ��Ϸ��
	Rectangle(U_Hdc,0,0,380,820);
	
	// ����ÿһ������
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (g_background[i][j] == 1 || g_background[i][j] == 2)
			{
				//���ƾ���
				Rectangle(U_Hdc,j*30+1,i*30+1,j*30+30-1,i*30+30-1);
			}
		}
	}
	
}