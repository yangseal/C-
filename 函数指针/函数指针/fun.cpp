#include<iostream>
#include<string>
using namespace std;

typedef void(*pFun)(int);

void PrintInt(int i)
{
	cout << i << endl;
}

int main()
{
	pFun func = PrintInt;
	//func(1)
	(*func)(1);
	system("pause");
	return 0;

}