#pragma once
#include"Widget.h"//������
#include"button.h"//��ť��
#include"Venmac.h"
class shangpin;
 class payment {
public:
	payment(float price, int number1=1) :price(price), number1(number1) {}
	//friend class maintain;
	float jisuan(shangpin& shp);//���㵥�ι����ܼۺ���ˮ����Ʒʣ����
	float total=0;//��������ˮ
	float price;//��Ʒ����
	int number1=1;//��Ʒ��������
	float sum;//��Ʒ�ܼ�
};
class wechat :public payment {
public:
	wechat(float price, int number1) :payment(price, number1) {
		//payment::jisuan();
	}
	void QR(shangpin& shp);//��ʾ��ά��
};
class alipay :public payment {
public:
	alipay(float price, int number1) :payment(price, number1) {}
	void QR(shangpin& shp);//��ʾ��ά��
};
class cashes :virtual public payment {
public:
	cashes(float price=0.0, int number1=1, float money=0) :payment(price, number1), money(money) {
	}
	//friend class maintain;
	float jisuan(shangpin& shp);//��������
	void xianshi(shangpin& shp);//��ʾ�ֽ�֧������
	void getmsg(float value,float money1) {
		money = money1;
		price = value;
	}
	void admoneys(float x) {
		movemoney += x;
	}
private:
	float money;//�û�Ͷ���Ǯ
	float movemoney = 200;//ʣ����Ǯ������
};

