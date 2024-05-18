#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<easyx.h>
#include"payments.h"
#include"Widget.h"//������
#include"button.h"//��ť��
#include"maintain.h"
#define BUFFERSIZE 1024
#define W 250
#define H 60
extern maintain people;
extern cashes cas1, cas2, cas3;

TCHAR* Transform(char c[BUFFERSIZE])
{
	TCHAR result[BUFFERSIZE];
	MultiByteToWideChar(CP_ACP, 0, c, -1, result, BUFFERSIZE);
	return result;
}
float payment::jisuan(shangpin& shp)//���㵥�ι����ܼۺ���ˮ
{
	sum = number1 * shp.price;
	total += sum;
	return sum;
}
void cashes::xianshi(shangpin& shp)//��ʾ�ֽ�֧������
{
	HWND s1 = initgraph(600, 700);
	SetWindowText(s1, L"�Զ��ۻ���");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//�������屳��
	setlinecolor(BLACK); //���õ�ǰ��������ɫΪ��ɫ
	cleardevice();//��ʾ������ɫ
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 48;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));	// ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	char str1[50] = "";
	char str2[50] = "";
	char str3[50] = "";
	sprintf(str1, "Ӧ���۸�:%.2fԪ", shp.price);
	sprintf(str2, "ʵ��֧��:%.2fԪ", money);
	sprintf(str3, "����:%.2fԪ", jisuan(shp));
	outtextxy(60, 50, Transform(str1));
	outtextxy(60, 160, Transform(str2));
	outtextxy(60, 270, Transform(str3));
	Button* vend;
	vend = new Button(450, 600, 100, 50, L"����");
	vend->show();
	ExMessage msg;
	while (true)
	{
		msg = getmessage();
		if (vend->state(msg))
		{
			cleardevice();
			thankyou(shp);
			return;
		}
	}
}
float cashes::jisuan(shangpin& shp)//��������
{
	sum = number1 * shp.price;
	total += sum;
	ExMessage msg;
	if (money >= sum && movemoney>=(money - sum))
	{
		movemoney -= money - sum;
		return money - sum;
	}
	else
	{
		settextstyle(30, 0, L"΢���ź�");
		outtextxy(60, 160, L"�ֽ𲻹����ۻ������㹻��Ǯ���뷵��ѡ��������ʽ");
		Button* vend;
		vend = new Button(50, 600, 100, 50, L"����");
		vend->show();
		while (true)
		{
			msg = getmessage();
			if (vend->state(msg))
			{
				cleardevice();
				zf1(shp,cas1);
				return 0.0;
			}
		}
	}
}
void wechat::QR(shangpin& shp)//΢��
{
	HWND s1 = initgraph(600, 700);
	SetWindowText(s1, L"�Զ��ۻ���");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//�������屳��
	setlinecolor(BLACK); //���õ�ǰ��������ɫΪ��ɫ
	cleardevice();//��ʾ������ɫ
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 48;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	settextcolor(BLACK);
	outtextxy(160, 50, L"��ɨ���ά��");
	//����ͼƬ����
	IMAGE img;
	//ͼƬ���أ����·��
	loadimage(&img, L"./ff.jpg");
	//���ͼƬ
	putimage(150, 210, &img);

	//���ذ�ť�ͼ�����ť
	Button* vend5;//������ť
	Button* vend4;
	vend4 = new Button(50, 600, 100, 50, L"����");
	vend5 = new Button(450, 600, 100, 50, L"����");
	vend4->show();
	vend5->show();
	ExMessage msg;
	while (true)
	{
		msg = getmessage();
		if (vend4->state(msg))
		{
			cleardevice();
			zf1(shp,cas1);
			return;
		}
		if (vend5->state(msg))
		{
			cleardevice();
			thankyou(shp);
			return;
		}
	}
}

void alipay::QR(shangpin& shp)//֧����
{
	HWND s1 = initgraph(600, 700);
	SetWindowText(s1, L"�Զ��ۻ���");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//�������屳��
	setlinecolor(BLACK); //���õ�ǰ��������ɫΪ��ɫ
	cleardevice();//��ʾ������ɫ
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 48;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));	// ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	settextcolor(BLACK);
	outtextxy(160, 50, L"��ɨ���ά��");
	//����ͼƬ����
	IMAGE img;
	//ͼƬ���أ����·��
	loadimage(&img, L"./f2.jpg");
	//���ͼƬ
	putimage(150, 210, &img);
	//���ذ�ť�ͼ�����ť
	Button* vend5;//������ť
	Button* vend4;
	vend4 = new Button(50, 600, 100, 50, L"����");
	vend5 = new Button(450, 600, 100, 50, L"����");
	vend4->show();
	vend5->show();
	ExMessage msg;
	while (true)
	{
		msg = getmessage();
		if (vend4->state(msg))
		{
			cleardevice();
			zf1(shp,cas1);
			return;
		}
		if (vend5->state(msg))
		{
			cleardevice();
			thankyou(shp);
			return;
		}
	}

}

void thankyou(shangpin& shp)
{
	HWND s1 = initgraph(600, 700);
	SetWindowText(s1, L"�Զ��ۻ���");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//�������屳��
	setlinecolor(BLACK); //���õ�ǰ��������ɫΪ��ɫ
	cleardevice();//��ʾ������ɫ
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 48;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));	// ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	outtextxy(180, 200, _T("֧���ɹ���"));
	outtextxy(150, 290, _T("��л���Ĺ���"));
	shp.number -= 1;
	people.creatf(shp);
	//������ť
	Button* vend;
	vend = new Button(450, 600, 100, 50, L"����");
	vend->show();
	ExMessage msg;
	while (true)
	{
		msg = getmessage();
		if (vend->state(msg))
		{
			//�����˵�����
			cleardevice();
			sh1(people);
			return;
		}
	}
}

void zf1(shangpin& shp, cashes& cas)
{
	HWND s1 = initgraph(600, 700);
	SetWindowText(s1, L"�Զ��ۻ���");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//�������屳��
	setlinecolor(BLACK); //���õ�ǰ��������ɫΪ��ɫ
	cleardevice();//��ʾ������ɫ
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 48;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	outtextxy(140, 50, _T("��ѡ��֧����ʽ"));
	Button* vend1;
	Button* vend2;
	Button* vend3;
	Button* vend4;
	vend1 = new Button(180, 180, W, H, L"΢��");
	vend2 = new Button(180, 280, W, H, L"֧����");
	vend3 = new Button(180, 380, W, H, L"�ֽ�");
	vend4 = new Button(50, 600, 100, 50, L"����");
	vend1->show();
	vend2->show();
	vend3->show();
	vend4->show();
	ExMessage msg;
	while (true)
	{
		msg = getmessage();

		if (vend1->state(msg))//΢��
		{
			cleardevice();
			wechat we(1.5, 2);//����
			we.jisuan(shp);
			we.QR(shp);
			return;
		}
		if (vend2->state(msg))//֧����
		{
			cleardevice();
			alipay ali(1.5, 2);
			ali.jisuan(shp);
			ali.QR(shp);
		}
		if (vend3->state(msg))//�ֽ�
		{
			cleardevice();
			// �����ַ������������������û�����
			wchar_t s[10];
			InputBox(s, 10, L"��������֧����Ǯ��");
			// ���û�����ת��Ϊ����
			float r = _wtoi(s);
			cas.getmsg(shp.price, r);
			cas.xianshi(shp);
		}
		if (vend4->state(msg))//����
		{
			cleardevice();
			sh1(people);
			return;
		}

	}

}