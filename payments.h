#pragma once
#include"Widget.h"//窗口类
#include"button.h"//按钮类
#include"Venmac.h"
class shangpin;
 class payment {
public:
	payment(float price, int number1=1) :price(price), number1(number1) {}
	//friend class maintain;
	float jisuan(shangpin& shp);//计算单次购买总价和流水和商品剩余量
	float total=0;//计算总流水
	float price;//商品单价
	int number1=1;//商品购买数量
	float sum;//商品总价
};
class wechat :public payment {
public:
	wechat(float price, int number1) :payment(price, number1) {
		//payment::jisuan();
	}
	void QR(shangpin& shp);//显示二维码
};
class alipay :public payment {
public:
	alipay(float price, int number1) :payment(price, number1) {}
	void QR(shangpin& shp);//显示二维码
};
class cashes :virtual public payment {
public:
	cashes(float price=0.0, int number1=1, float money=0) :payment(price, number1), money(money) {
	}
	//friend class maintain;
	float jisuan(shangpin& shp);//计算找零
	void xianshi(shangpin& shp);//显示现金支付界面
	void getmsg(float value,float money1) {
		money = money1;
		price = value;
	}
	void admoneys(float x) {
		movemoney += x;
	}
private:
	float money;//用户投入的钱
	float movemoney = 200;//剩余零钱的总数
};

