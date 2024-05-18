#pragma once
#include <iostream>
#include<easyx.h>
#include"Widget.h"
#include"button.h"
#include"payments.h"

using namespace std;
class Venmac;
class shangpin;
class cashes;
class maintain
{
public:
	maintain(string name,int num,int password);
	void adgoods(Venmac& ven);
	void admoney(int x, cashes& ca);
	void creatf(shangpin& shp);
	bool checkac(int numb, int pass);
	char* getname(void) {
		for (int i = 0; i < name.size(); i++)
		{
			na[i] = name[i];
		}
		return na;
	}
	~maintain();

private:
	string name;
	char na[20];
	int number;
	int password;
};
void sh1(maintain& people);
void sh2(maintain& p,Venmac& ven,cashes& cash);