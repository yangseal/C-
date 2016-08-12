#include<iostream>
#include<string>
#include<list>


using namespace std;

void(*pFunc)(int);

void PrintInt(int i)
{
	cout << i << endl;
}

int main(int argc, char *argv[])
{
	pFunc = &PrintInt;
	//pFunc = PrintInt;
	(*pFunc)(1);
	//pFunc(1);
	system("pause");
	return 0;
}