#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<easyx.h>
#include"Widget.h"
#include"button.h"
#include"maintain.h"
#include"Venmac.h"
#define BUFFERSIZE 1024
#define W 250
#define H 60
using namespace std;
maintain people("Qhnan", 1, 7);
Venmac ven1(001);
Venmac ven2(002);
Venmac ven3(003);
cashes cas1, cas2, cas3;
TCHAR* Transform(char c[BUFFERSIZE])
{
	TCHAR result[BUFFERSIZE];
	MultiByteToWideChar(CP_ACP, 0, c, -1, result, BUFFERSIZE);
	return result;
}
int main()
{
	sh1(people);
	return 0;
}
void sh1(maintain& p) {
	HWND s1 = initgraph(500, 700);
	SetWindowText(s1, L"自动售货机");
	IMAGE img;
	loadimage(&img, L"./bg.png");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//处理字体背景
	setlinecolor(BLACK); //设置当前线条的颜色为黑色
	cleardevice();//显示背景颜色
	putimage(0, 0, &img);
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 48;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("宋体"));		// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	outtextxy(140, 50, _T("自动售货机"));
	Button* vend1;
	Button* vend2;
	Button* vend3;
	Button* bmaintains;
	vend1 = new Button(140, 180, W, H, L"售货机1");
	vend2 = new Button(140, 280, W, H, L"售货机2");
	vend3 = new Button(140, 380, W, H, L"售货机3");
	bmaintains = new Button(140, 480, W, H, L"维护");
	vend1->show();
	vend2->show();
	vend3->show();
	bmaintains->show();
	ExMessage msg;
	bool on = 1;
	while (on)
	{
		msg = getmessage();

		if (vend1->state(msg))
		{
			cleardevice();
			sh7(ven1,cas1);
		}
		if (vend2->state(msg))
		{
			cleardevice();
			sh7(ven2,cas2);
		}
		if (vend3->state(msg))
		{
			cleardevice();
			sh7(ven3,cas3);
		}
		if (bmaintains->state(msg))
		{
			wchar_t mon[8];
			InputBox(mon, 8, L"请输入ID：");
			int numb = _wtoi(mon);
			wchar_t m[8];
			InputBox(m, 8, L"请输入密码：");
			int pasw = _wtoi(m);
			if (people.checkac(numb,pasw))
			{
				wchar_t mon[8];
				InputBox(mon, 8, L"请输入维护的售货机编号：");
				int ns = _wtoi(mon);
				switch (ns)
				{
				case 001:delete bmaintains; sh2(p, ven1, cas1); break;
				case 002:delete bmaintains; sh2(p, ven2, cas2); break;
				case 003:delete bmaintains; sh2(p, ven3, cas3); break;
				default:
					break;
				}
			}
		}
	}
}
void sh2(maintain& p,Venmac& ven,cashes& cash) {
	HWND s2 = initgraph(600, 700);
	SetWindowText(s2, L"自动售货机");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//处理字体背景
	setlinecolor(BLACK); //设置当前线条的颜色为黑色
	cleardevice();//显示背景颜色
	char str1[50] = "";
	sprintf(str1,"维护人员：%s", p.getname());
	outtextxy(20, 20, Transform(str1));
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 48;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("宋体"));		// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式

	Button* back;
	Button* b1;
	Button* b2;
	Button* b3;
	back = new Button(350, 640, W, H, L"返回");
	b1 = new Button(190, 160, W, H, L"补货");
	b2 = new Button(190, 300, W, H, L"补充零钱");
	b3 = new Button(190, 440, W, H, L"查询（打印）流水");
	b1->show();
	b2->show();
	b3->show();
	back->show();
	ExMessage msg;
	while (1)
	{
		msg = getmessage();

		if (back->state(msg))
		{
			cleardevice();
			sh1(p);
			return;
		}
		if (b1->state(msg))
		{
			p.adgoods(ven);
		}
		if (b2->state(msg))
		{
			wchar_t mon[8];
			InputBox(mon, 8, L"请输入补充的零钱数：");
			float money = _wtoi(mon);
			p.admoney(money,cash);
		}
		if (b3->state(msg))
		{
			MessageBox(s2, L"打印成功", L"提示", MB_OK);
		}
	}

}
