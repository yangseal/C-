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

//����һ����̬��Ա����ָ��
typedef void(*pFunc)(int);

int main()
{
	//����̬��Ա������������ָ��
	pFunc func = Base::print;
	func(2);
	system("pause");
	return 0;
}

/*
	��̬��Ա��������ͨ�ĺ���û��̫��������Ȼ���Ƕ��������У����������Ա����������Ϊ����Ĳ�ͬ������ͬ�Ĵ�����Ϊ��û��thisָ�룬�������ǿ��Խ���������ͨ�ĺ���
*/