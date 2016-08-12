#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
	static void print(int num)
	{
		cout << num << endl;
	}
};

//定义一个静态成员函数指针
typedef void(*pFunc)(int);

int main()
{
	//将静态成员函数赋给函数指针
	pFunc func = Base::print;
	func(2);
	system("pause");
	return 0;
}

/*
	静态成员函数与普通的函数没有太多区别，虽然他们定义在类中，但是这个成员函数不会因为对象的不同而做不同的处理，因为它没有this指针，所以我们可以将它看成普通的函数
*/