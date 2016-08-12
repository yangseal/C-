#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Print(int num)
	{
		cout << "base:" << num << endl;
	}

};

class Child:public Base
{
public:
		//覆盖基类的Print方法
	void  Print(int num)override
	{
		cout << "child:" << num << endl;
	}	 
};

//定义一个成员函数指针
typedef void (Base::*pFunc)(int);

int main()
{
	Base base;
	Child child;
	//给函数指针赋值的时候，必须是用声明函数指针的类来赋值（此处为Base）
	pFunc func = &(Base::Print);
	//通过base对象调用函数指针
	(base.*func)(1);
	//通过child对象调用函数指针
	(child.*func)(3);
	//查看函数指针的大小
	cout << "sizeof Member Function :" << sizeof(func) << endl;
	system("pause");
	return 0;
}

/*
	从上面的结果，我们看出，在最后使用函数指针的时候，这个this指针的对象可以是我们声明函数指针的时候的对象的子类，并且如果我们覆写了基类的函数，是可以调用子类的函数的（注意是覆写基类的virtual函数，如果只是单纯的覆盖是没有多态效果的）.还是这样看待这个函数指针，把它看成普通函数指针增加了一个类对象的this指针作为参数，这个形参我们可以声明为基类的指针，我们给实参的时候，可以给基类的对象，当然也可以给子类对象，这就跟我们普通函数传递参数的情况一样，然后这个参数传递进去，如果有virtual函数，那么就可以触发多态。但是我们在给函数指针赋值的时候，却只能使用基类的函数，因为我们没有声明子类的函数。
	
*/