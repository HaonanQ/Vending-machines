#pragma once
#include"maintain.h"
#include <fstream>
#include <string>
maintain::maintain(string name, int num, int password) :name(name), number(num), password(password)
{

}

maintain::~maintain()
{
}
void maintain::adgoods(Venmac& ven) {
	wchar_t mon[8];
	InputBox(mon, 8, L"请输入货物编号：");
	int nu = _wtoi(mon);
	if (nu >= 94 && nu <= 100) {
		wchar_t mon[8];
		InputBox(mon, 8, L"请输入补货数量：");
		int nus = _wtoi(mon);
		for (int i = ven.getshupian().bianhao; i <= 100; i++)
		{
			if (nu == ven.getshupian().bianhao) {
				ven.getshupian().number += nus;
				break;
			}
			if (nu == ven.getbinggans().bianhao) {
				ven.getbinggans().number += nus;
				break;
			}
			if (nu == ven.getmianbao().bianhao) {
				ven.getmianbao().number += nus;
				break;
			}
			if (nu == ven.getsanmingzhi().bianhao) {
				ven.getsanmingzhi().number += nus;
				break;
			}
			if (nu == ven.getkuangquanshui().bianhao) {
				ven.getkuangquanshui().number += nus;
				break;
			}
			if (nu == ven.getbinghongcha().bianhao) {
				ven.getbinghongcha().number += nus;
				break;
			}
			if (nu == ven.getpijiu().bianhao) {
				ven.getpijiu().number += nus;
				break;
			}
		}
	}else
	{
		MessageBox(NULL, L"无货物信息", L"错误", MB_OK);
		return;
	}
	return;
}
void  maintain::admoney(int x, cashes& ca) {
	ca.admoneys(x);
}
void  maintain::creatf(shangpin& shp) {
	ofstream outfile("product.txt",ios::app);
	outfile << "商品名称：" << shp.leibie << "   购买数量：" << 1 << "  获得收入：" << shp.price <<" 元" << endl;
	outfile.close();
}
bool  maintain::checkac(int numb, int pass) {
	if (numb==number&&pass==password)
	{
		MessageBox(NULL, L"登陆成功", L"提示", MB_OK);
		return true;
	}
	else
	{
		MessageBox(NULL, L"登陆失败，请检查ID和密码。", L"提示", MB_OK);
		return false;
	}
}