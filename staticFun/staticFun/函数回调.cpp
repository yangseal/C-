#include<iostream>
using namespace std;

class Baker
{
public:
	Baker();
	bool MakeCake();                     //做蛋糕,如果做好了返回true，否则返回false
private:
	int m_iTime;                       //做蛋糕的时间
	static const int m_iMaxTime = 10; //假设10分钟做完
};

Baker::Baker():m_iTime(0){}

bool Baker::MakeCake()
{
	//假设每次调用该函数，m_iTime+1
	m_iTime += 1;
	if (m_iTime == m_iMaxTime)
	{
		cout << "蛋糕做好了!" << endl;
		return true;
	}
	return false;
}

//客户函数
void GetMyCake()
{
	cout << "我来取蛋糕了!" << endl;
}

int main()
{
	//创建一个蛋糕店
	Baker baker;
	while (1)
	{
		//客户如果想第一时间知道蛋糕做没做好，就必须每时每刻查看蛋糕的情况
		if (baker.MakeCake())
		{
			GetMyCake();
			break;
		}
		else
			cout << "蛋糕没做好" << endl;
	}
	system("pause");
	return 0;
}