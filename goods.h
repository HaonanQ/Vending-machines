#pragma once
#include<iostream>
#include<string>
using namespace std;
class shangpin {

public:
	float price;
	int number;//Ê£ÓàÊıÁ¿
	int bianhao;
	string leibie;
	shangpin(float x, int y, int z, string c = "ÎŞ");
};
shangpin::shangpin(float x, int y, int z, string c) :price(x), number(y), bianhao(z), leibie(c) {
}
