#include<iostream>
using namespace std;

//定义pcall这种函数指针的类型
typedef int(*pcall)(int, int);

//处理函数，接受一个pcall类型的函数作为参数
void func(pcall p, int x, int y)
{
	cout << "begin func:" << endl;
	cout << "result is :" << p(x, y) << endl;
	cout << "end func "   <<  endl;
}

//加法函数
int AddFUnc(int x, int y)
{
	return x + y;
}

//减法函数
int SubFunc(int x, int y)
{
	return x - y;
}

int main()
{
	//将函数指针作为参数传递给函数
	//&符号可以省略
	func(&AddFUnc, 2, 1);
	func(&SubFunc, 2, 1);
	system("pause");
	return 0;
}