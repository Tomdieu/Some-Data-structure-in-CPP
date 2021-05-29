#ifndef Navi

#define Navi

#include <stdio.h>
#include<string>
#include <iostream>

using namespace std;

#define len(arr) sizeof(arr)/sizeof(*arr)
// My Color Functions Defined Here


void ColorYellow()
{
	printf("\033[1;33m");
}

void NormalColor()
{
	printf("\033[0m");
}

void ColorBlueBold()
{
	printf("\033[1;34");
}

void ColorBlue()
{
	printf("\033[2;31m");
}

void ColorViolet()
{
	printf("\033[1;35m");
}

void ColorSkyBlue()
{
	printf("\033[1;24");
}

void ColorRed()
{
	printf("\033[1;31m");
}

void ColorGreen()
{
	printf("\033[0;32m");
}

void ColorPurple()
{
	printf("\033[0;35");
}

void ColorCyan()
{
	printf("\033[0;36");
}

void ColorBrown()
{
	printf("\033[0;37m");
}

void ColorBlonde()
{
	printf("\033[2;35m");
}

void ColorGreen1()
{
	printf("\033[1;30m");
}

void ColorGreenBold()
{
	printf("\033[1;32m");
}

void ColorGreenBlue()
{
	printf("\033[1;36m");
}

void ColorBoldWhite()
{
	printf("\033[1;37m");
}

void ColorGreen2()
{
	printf("\033[2;30m");
}

void ColorRed1()
{
	printf("\033[2;31m");
}

void ColorBrown1()
{
	printf("\033[2;33m");
}

void ColorLightBrown()
{
	printf("\033[2;38m");
}

void ColorWhiteBoldItalic()
{
	printf("\033[3;20m");
}

void ColorWhiteItalicUnderline()
{
	printf("\033[3;21m");
}

void ColorGreenItalic()
{
	printf("\033[3;30m");
}

void ColorRedItalic()
{
	printf("\033[3;31m");
}

void ColorLigthGreenItalic()
{
	printf("\033[3;32m");
}

void ColorOrangeItalic()
{
	printf("\033[3;33m");
}

void ColorBlueItalic()
{
	printf("\033[3;34m");
}

void ColorPurpleItalic()
{
	printf("\033[3;35m");
}

void ColorGrenBlueItalic()
{
	printf("\033[3;36m");
}

void ColorLightGrayItalic()
{
	printf("\033[3;37m");
}

void ColorWhiteUnderline()
{
	printf("\033[4;39m");
}

void ColorRedUnderline()
{
	printf("\033[4;31m");
}

void ColorLightGreenUnderline()
{
	printf("\033[4;32m");
}

void ColorOrangeUnderline()
{
	printf("\033[4;33m");
}

void ColorBlueUnderline()
{
	printf("\033[4;34m");
}

void ColorPurpleUnderline()
{
	printf("\033[4;35m");
}

void ColorGreenBlueUnderline()
{
	printf("\033[4;36m");
}

//My displacement function define here

void gotoxy(short x,short y)
{
	printf("%c[%d;%df",0x1B,y,x);
}

char colors[][20]={"red","blue","green","black","white","light grey","sky blue","brown","orange"};

void (*StrClr[len(colors)])(char*);

int indexOfColor(string color)
{
	int i;
	for (i = 0; i < len(colors); i++)
	{
		if(color == colors[i])
		{
			cout<<"Equals";
			return i;
		}
	}
	return -1;
}

void displayColor(string arr[])
{
	cout<<endl;
}

void outtexty(int x,int y,string text,string color = "white",string textF="normal")
{
	gotoxy(x,y);
	cout<<text<<endl;
	cout<<"text = "<<text<<"\ncolor ="<<color<<"\ntextF = "<<textF<<endl;
}

#endif