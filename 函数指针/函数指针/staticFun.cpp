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

typedef void(*pFunc)(int);

int main()
{
	pFunc func = Base::print;
	func(1);
	system("pause");
	return 0;
}