#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<easyx.h>
#include"payments.h"
#include"Widget.h"//窗口类
#include"button.h"//按钮类
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
float payment::jisuan(shangpin& shp)//计算单次购买总价和流水
{
	sum = number1 * shp.price;
	total += sum;
	return sum;
}
void cashes::xianshi(shangpin& shp)//显示现金支付界面
{
	HWND s1 = initgraph(600, 700);
	SetWindowText(s1, L"自动售货机");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//处理字体背景
	setlinecolor(BLACK); //设置当前线条的颜色为黑色
	cleardevice();//显示背景颜色
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 48;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("宋体"));	// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	char str1[50] = "";
	char str2[50] = "";
	char str3[50] = "";
	sprintf(str1, "应付价格:%.2f元", shp.price);
	sprintf(str2, "实际支付:%.2f元", money);
	sprintf(str3, "找零:%.2f元", jisuan(shp));
	outtextxy(60, 50, Transform(str1));
	outtextxy(60, 160, Transform(str2));
	outtextxy(60, 270, Transform(str3));
	Button* vend;
	vend = new Button(450, 600, 100, 50, L"继续");
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
float cashes::jisuan(shangpin& shp)//计算找零
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
		settextstyle(30, 0, L"微软雅黑");
		outtextxy(60, 160, L"现金不够或售货机无足够零钱，请返回选择其他方式");
		Button* vend;
		vend = new Button(50, 600, 100, 50, L"返回");
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
void wechat::QR(shangpin& shp)//微信
{
	HWND s1 = initgraph(600, 700);
	SetWindowText(s1, L"自动售货机");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//处理字体背景
	setlinecolor(BLACK); //设置当前线条的颜色为黑色
	cleardevice();//显示背景颜色
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 48;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("宋体"));		// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	settextcolor(BLACK);
	outtextxy(160, 50, L"请扫描二维码");
	//定义图片变量
	IMAGE img;
	//图片加载，相对路径
	loadimage(&img, L"./ff.jpg");
	//输出图片
	putimage(150, 210, &img);

	//返回按钮和继续按钮
	Button* vend5;//继续按钮
	Button* vend4;
	vend4 = new Button(50, 600, 100, 50, L"返回");
	vend5 = new Button(450, 600, 100, 50, L"继续");
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

void alipay::QR(shangpin& shp)//支付宝
{
	HWND s1 = initgraph(600, 700);
	SetWindowText(s1, L"自动售货机");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//处理字体背景
	setlinecolor(BLACK); //设置当前线条的颜色为黑色
	cleardevice();//显示背景颜色
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 48;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("宋体"));	// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	settextcolor(BLACK);
	outtextxy(160, 50, L"请扫描二维码");
	//定义图片变量
	IMAGE img;
	//图片加载，相对路径
	loadimage(&img, L"./f2.jpg");
	//输出图片
	putimage(150, 210, &img);
	//返回按钮和继续按钮
	Button* vend5;//继续按钮
	Button* vend4;
	vend4 = new Button(50, 600, 100, 50, L"返回");
	vend5 = new Button(450, 600, 100, 50, L"继续");
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
	SetWindowText(s1, L"自动售货机");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//处理字体背景
	setlinecolor(BLACK); //设置当前线条的颜色为黑色
	cleardevice();//显示背景颜色
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 48;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("宋体"));	// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	outtextxy(180, 200, _T("支付成功！"));
	outtextxy(150, 290, _T("感谢您的购买"));
	shp.number -= 1;
	people.creatf(shp);
	//继续按钮
	Button* vend;
	vend = new Button(450, 600, 100, 50, L"继续");
	vend->show();
	ExMessage msg;
	while (true)
	{
		msg = getmessage();
		if (vend->state(msg))
		{
			//放主菜单函数
			cleardevice();
			sh1(people);
			return;
		}
	}
}

void zf1(shangpin& shp, cashes& cas)
{
	HWND s1 = initgraph(600, 700);
	SetWindowText(s1, L"自动售货机");
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//处理字体背景
	setlinecolor(BLACK); //设置当前线条的颜色为黑色
	cleardevice();//显示背景颜色
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 48;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("宋体"));		// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	outtextxy(140, 50, _T("请选择支付方式"));
	Button* vend1;
	Button* vend2;
	Button* vend3;
	Button* vend4;
	vend1 = new Button(180, 180, W, H, L"微信");
	vend2 = new Button(180, 280, W, H, L"支付宝");
	vend3 = new Button(180, 380, W, H, L"现金");
	vend4 = new Button(50, 600, 100, 50, L"返回");
	vend1->show();
	vend2->show();
	vend3->show();
	vend4->show();
	ExMessage msg;
	while (true)
	{
		msg = getmessage();

		if (vend1->state(msg))//微信
		{
			cleardevice();
			wechat we(1.5, 2);//样例
			we.jisuan(shp);
			we.QR(shp);
			return;
		}
		if (vend2->state(msg))//支付宝
		{
			cleardevice();
			alipay ali(1.5, 2);
			ali.jisuan(shp);
			ali.QR(shp);
		}
		if (vend3->state(msg))//现金
		{
			cleardevice();
			// 定义字符串缓冲区，并接收用户输入
			wchar_t s[10];
			InputBox(s, 10, L"请输入您支付的钱数");
			// 将用户输入转换为数字
			float r = _wtoi(s);
			cas.getmsg(shp.price, r);
			cas.xianshi(shp);
		}
		if (vend4->state(msg))//返回
		{
			cleardevice();
			sh1(people);
			return;
		}

	}

}