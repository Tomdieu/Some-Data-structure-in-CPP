#include<iostream>
#include <stdio.h>
#include"Nv.cpp"
#include<cstdlib>
#include<string>
using namespace std;

class Complexe
{
	public:
	Complexe(float r,float i)
	{
		re = r;
		im = i;
	}
	
	Complexe()
	{
		re = 0;
		im = 0;
	}
	
	Complexe operator +(Complexe b)
	{
		return Complexe(re,im);
	}

	Complexe operator *(Complexe b)
	{
		return Complexe();
	}

	Complexe operator /(Complexe b)
	{
		return Complexe();
	}

	Complexe operator ~()
	{
		return Complexe();
	}

	Complexe operator ^(int x);
	Complexe operator ^(float x);



	void display()
	{
		cout <<re<<"+"<<im<<"i"<<endl;
	}

public:
	float re;
	float im;
};

int chr(string s)
{
	cout<<s<<endl;
	return 0;
}

int main(int argc, char const *argv[])
{
	int (*t)(string);
	t = chr;
	t("Navi Coperation");
	gotoxy(20,10);
	ColorBoldWhite();
	cout <<"Hello World"<<endl;
	Complexe c;
	c = Complexe(2,4);
	c.display();
	NormalColor();
	c = ~c;
	ColorBlue();
	gotoxy(20,30);
	c.display();
	outtexty(30,30,"NV Coperation","red","bold");
	string s1,s2;
	s1 = "World!";
	s2 = "Hello ";
	s1.swap(s2);
	cout<<s1+s2<<endl;
	return 0;
}