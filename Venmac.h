#pragma once
#include"maintain.h"
#include"goods.h"
#include"payments.h"
class cashes;
class Venmac
{
public:
	int numble;
	Venmac( int num) :numble(num){
		
	}
	shangpin& getmianbao(void) {
		return mianbaos;
	}
	shangpin& getbinggans(void) {
		return binggans;
	}
	shangpin& getsanmingzhi(void) {
		return sanmingzhi;
	}
	shangpin& getkuangquanshui(void) {
		return kuangquanshui;
	}
	shangpin& getbinghongcha(void) {
		return binghongcha;
	}
	shangpin& getpijiu(void) {
		return pijiu;
	}
	shangpin& getshupian(void) {
		return shupian;
	}
private:
		shangpin mianbaos{ 3, 20, 100, "���" };
		shangpin binggans{ 5, 20, 99, "����" };
		shangpin sanmingzhi{ 3.5, 20, 98, "������" };
		shangpin kuangquanshui{ 1, 20, 97, "ˮ" };
		shangpin binghongcha{ 3, 20, 96, "�����" };
		shangpin pijiu{ 2.5, 20, 95., "ơ��" };
		shangpin shupian{ 6, 20, 94., "��Ƭ" };
};
void thankyou(shangpin& shp);
void zf1(shangpin& shp, cashes& cas);
void sh7(Venmac& ven, cashes& cas);
void sh8(shangpin& s, Venmac& ven, cashes& cas);
