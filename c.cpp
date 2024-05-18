#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<string>
#include"button.h"
#include"Widget.h"
#include"goods.h"
#include"maintain.h"
#include"Venmac.h"
#define BUFFERSIZE 1024
#define W1 110
#define H2 33
extern maintain people;
extern Venmac ven1;
extern Venmac ven2;
extern Venmac ven3;

TCHAR* Transform(char c[BUFFERSIZE])
{
	TCHAR result[BUFFERSIZE];
	MultiByteToWideChar(CP_ACP, 0, c, -1, result, BUFFERSIZE);
	return result;
}
void sh7(Venmac &ven, cashes& cas) {

	IMAGE A, B, C, D, E, F, G;
	HWND s7 = initgraph(600, 700);
	char str[10] = "";
	sprintf(str, "�ۻ�����ţ�%d ,   ��������", ven.numble);
	SetWindowText(s7, L"�Զ��ۻ���");//���ñ���
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//�������屳��
	setlinecolor(BLACK); //���õ�ǰ��������ɫΪ��ɫ
	cleardevice();//��ʾ������ɫ
	settextcolor(RED);
	outtextxy(20, 20, Transform(str));
	settextcolor(BLACK);
	Button* bt[8];
	bt[0] = new Button(70, 176, W1, H2, L"�������");
	bt[1] = new Button(246, 176, W1, H2, L"�������");
	bt[2] = new Button(422, 176, W1, H2, L"����������");
	bt[3] = new Button(70, 362, W1, H2, L"�����Ȫˮ");
	bt[4] = new Button(246, 362, W1, H2, L"��������");
	bt[5] = new Button(422, 362, W1, H2, L"����ơ��");
	bt[6] = new Button(246, 548, W1, H2, L"������Ƭ");
	bt[7] = new Button(40, 650, W1, H2, L"��  ��");
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 48;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	//outtextxy(190, 50, _T("�Զ��ۻ���"));
	loadimage(&A, L"./1.png", 106, 106);
	putimage(70, 50, &A);
	loadimage(&B, L"./2.png", 106, 106);
	putimage(246, 50, &B);
	loadimage(&C, L"./3.png", 106, 106);
	putimage(422, 50, &C);
	loadimage(&D, L"./4.png", 104, 104);
	putimage(70, 236, &D);
	loadimage(&E, L"./5.png", 106, 106);
	putimage(246, 236, &E);
	loadimage(&F, L"./6.png", 104, 122);
	putimage(422, 236, &F);
	loadimage(&G, L"./7.png", 106, 82);
	putimage(246, 422, &G);
	bt[0]->show();
	bt[1]->show();
	bt[2]->show();
	bt[3]->show();
	bt[4]->show();
	bt[5]->show();
	bt[6]->show();
	bt[7]->show();//����
	ExMessage msg;
	while (1) {
		msg = getmessage();
		if (bt[0]->state(msg))
		{
			cleardevice();
			sh8(ven.getmianbao(),ven,cas);
			
		}
		if (bt[1]->state(msg))
		{
			cleardevice();
			sh8(ven.getbinggans(),ven,cas);
			
		}
		if (bt[2]->state(msg))
		{
			cleardevice();
			sh8(ven.getsanmingzhi(),ven,cas);
			
		}
		if (bt[3]->state(msg))
		{
			cleardevice();
			sh8(ven.getkuangquanshui(),ven,cas);
			
		}
		if (bt[4]->state(msg))
		{
			cleardevice();
			sh8(ven.getbinghongcha(),ven,cas);
			
		}
		if (bt[5]->state(msg))
		{
			cleardevice();
			sh8(ven.getpijiu(),ven,cas);
			
		}
		if (bt[6]->state(msg))
		{
			cleardevice();
			sh8(ven.getshupian(),ven,cas);
			
		}
		if (bt[7]->state(msg))
		{
			cleardevice();
			sh1(people);
			
		}
	}
}
void sh8(shangpin& s,Venmac& ven, cashes& cas) {
	IMAGE A, B, C, D, E, F, G;
	HWND s8 = initgraph(600, 700);
	SetWindowText(s8, L"�Զ��ۻ���");//���ñ���
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//�������屳��
	setlinecolor(BLACK); //���õ�ǰ��������ɫΪ��ɫ
	cleardevice();//��ʾ������ɫ
	//settextcolor(RED);
	//outtextxy(20, 20, L"�������");
	settextcolor(BLACK);
	ExMessage msg;
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 48;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	char str[10] = "";
	sprintf(str, "ʣ��:%d", s.number);
	while(1) {
		msg = getmessage();
		switch (s.bianhao)
		{
			Button* sb[7];
			Button* fanhui;

		case 100:
			loadimage(&A, L"./1.png", 200, 200);
			putimage(200, 100, &A);
			msg = getmessage();
			sb[0] = new Button(240, 550, 120, H2, L"�������");
			if (s.number==0)
			{
				outtextxy(250, 450, L"Ŀǰ�޻����뷵��.");
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
			}
			else {
				sb[0]->show();
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				outtextxy(250, 350, L"�۸�3.0Ԫ");
				outtextxy(250, 400, L"������1.0");
				outtextxy(250, 450, Transform(str));
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
				if (sb[0]->state(msg))
				{
					cleardevice();
					zf1(s,cas);
				}
			}
			break;
		case 99:
			loadimage(&B, L"./2.png", 200, 200);
			putimage(200, 100, &B);
			sb[1] = new Button(240, 550, 120, H2, L"�������");
			if (s.number == 0)
			{
				outtextxy(250, 450, L"Ŀǰ�޻����뷵��.");
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
			}
			else {
				sb[1]->show();
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				outtextxy(250, 350, L"�۸�5.0Ԫ");
				outtextxy(250, 400, L"������1.0");
				outtextxy(250, 450, Transform(str));
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
				if (sb[1]->state(msg))
				{
					cleardevice();
					zf1(s,cas);
				}
			}
			break;
		case 98:
			loadimage(&C, L"./3.png", 200, 200);
			putimage(200, 100, &C);
			sb[2] = new Button(240, 550, 120, H2, L"����������");
			if (s.number == 0)
			{
				outtextxy(250, 450, L"Ŀǰ�޻����뷵��.");
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
			}
			else {
				sb[2]->show();
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				outtextxy(250, 350, L"�۸�3.5Ԫ");
				outtextxy(250, 400, L"������1.0");
				outtextxy(250, 450, Transform(str));
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
				if (sb[2]->state(msg))
				{
					cleardevice();
					zf1(s,cas);
				}
			}
			break;
		case 97:
			loadimage(&D, L"./4.png", 200, 200);
			putimage(200, 100, &D);
			sb[3] = new Button(240, 550, 120, H2, L"�����Ȫˮ");
			if (s.number == 0)
			{
				outtextxy(250, 450, L"Ŀǰ�޻����뷵��.");
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
			}
			else {
				sb[3]->show();
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				outtextxy(250, 350, L"�۸�1.0Ԫ");
				outtextxy(250, 400, L"������1.0");
				outtextxy(250, 450, Transform(str));
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
				if (sb[3]->state(msg))
				{
					cleardevice();
					zf1(s,cas);
				}
			}
			break;
		case 96:
			loadimage(&E, L"./5.png", 200, 200);
			putimage(200, 100, &E);
			sb[4] = new Button(240, 550, 120, H2, L"��������");
			if (s.number == 0)
			{
				outtextxy(250, 450, L"Ŀǰ�޻����뷵��.");
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
			}
			else {
				sb[4]->show();
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				outtextxy(250, 350, L"�۸�3.0Ԫ");
				outtextxy(250, 400, L"������1.0");
				outtextxy(250, 450, Transform(str));
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
				if (sb[4]->state(msg))
				{
					cleardevice();
					zf1(s,cas);
				}
			}
			break;
		case 95:
			loadimage(&F, L"./6.png", 200, 200);
			putimage(200, 100, &F);
			sb[5] = new Button(240, 550, 120, H2, L"����ơ��");
			if (s.number == 0)
			{
				outtextxy(250, 450, L"Ŀǰ�޻����뷵��.");
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
			}
			else {
				sb[5]->show();
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				outtextxy(250, 350, L"�۸�2.5Ԫ");
				outtextxy(250, 400, L"������1.0");
				outtextxy(250, 450, Transform(str));
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
				if (sb[5]->state(msg))
				{
					cleardevice();
					zf1(s,cas);
				}
			}
			break;
		case 94:
			loadimage(&G, L"./7.png", 200, 200);
			putimage(200, 100, &G);
			sb[6] = new Button(240, 550, 120, H2, L"������Ƭ");
			if (s.number == 0)
			{
				outtextxy(250, 450, L"Ŀǰ�޻����뷵��.");
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
			}
			else {
				sb[6]->show();
				fanhui = new Button(50, 600, W1, H2, L"��  ��");
				fanhui->show();
				outtextxy(250, 350, L"�۸�6.0Ԫ");
				outtextxy(250, 400, L"������1.0");
				outtextxy(250, 450, Transform(str));
				if (fanhui->state(msg))
				{
					cleardevice();
					sh7(ven,cas);
					return;
				}
				if (sb[6]->state(msg))
				{
					cleardevice();
					zf1(s,cas);
				}
			}
			break;
		default:break;

		}
	}
}