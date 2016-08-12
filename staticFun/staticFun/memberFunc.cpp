#include<iostream>
using namespace std;

class Base
{
public:
	void print(int num)
	{
		cout << num << endl;
	}
};

//定义一个成员函数指针
typedef void (Base::*pfunc)(int);


int main()
{
	Base base;
	//取成员函数的地址，必须以这种形式，不能以对象的形式获取，而且必须加上&符号
	pfunc func = &Base::print;
	//调用的时候写法也比较特殊，base.*func表示函数体，是一个整体，需要用（）
	(base.*func)(2);
	system("pause");
	return 0;
}

/*
	1.（Base：：*pFunc）（int），其实就相当于（*pFunc）（Base*， int），相当于普通的函数指针需要多一个this指针作为参数，而这个this指针在不同的对象中一定是不同的，所以成员函数指针之间是不能互相转化的，只有同类型的对象的函数才能赋给这种对象的函数指针。在指针赋值的时候，注意一下写法，普通的函数指针在赋值的时候，可以不写&符号，但是成员函数指针赋值的时候比较严格，如果不写的话会报出这样的错误：error C3867: “Base::Print”: 函数调用缺少参数列表；请使用“&Base::Print”创建指向成员的指针而且在赋值的时候，不要用对象赋值，要用 类名：：函数名 这种方式赋值，使用 对象名.函数的时候会报出这样的错误： error C2276: “&”: 绑定成员函数表达式上的非法操作
	2.由于成员函数指针需要一个this指针作为参数，这个参数又不能直接给出，所以我们就只能通过对象来调用函数，在使用函数的时候，由于函数是一个整体，所以需要用（），在括号内部，我们通过*func获得函数，然后前面使用base.就将base作为this指针传递给了函数。
*/