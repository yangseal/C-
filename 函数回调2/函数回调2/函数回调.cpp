
#include <iostream>

using namespace std;

//声明一种回调函数
typedef void(*CallBackFunc)(void);

class Baker
{
private:
	int m_iTime;			  //做蛋糕的时间
	static const int m_iMaxTime = 10;//假设10分钟做完
	CallBackFunc m_pfCallBack;//回调函数
public:
	//注册：留下买蛋糕的人的联系方式
	void Invoke(CallBackFunc);
	//打电话通知买蛋糕的人
	void Notify();
	//做蛋糕，如果做好了，直接通知客户
	void MakeCake();
	//构造函数
	Baker();
};

Baker::Baker() : m_iTime(0){}

void Baker::MakeCake()
{
	while (m_iTime < m_iMaxTime)
	{
		//假设每次调用该函数，m_iTime+1
		m_iTime += 1;
	}
	cout << "蛋糕做好了!" << endl;
	Notify();
}

void Baker::Invoke(CallBackFunc pfunc)
{
	//注册过程
	m_pfCallBack = pfunc;
	cout << "留下了您的联系方式!" << endl;
}

void Baker::Notify()
{
	if (m_pfCallBack)
		m_pfCallBack();
}


//客户函数
void GetMyCake()
{
	cout << "我来取蛋糕啦!" << endl;
}

int main()
{
	//创建一个蛋糕店
	Baker baker;
	//注册：留下联系方式
	baker.Invoke(GetMyCake);
	//注册之后，客户就不需要实时查询了
	cout << "好了叫我就好，我去玩儿啦!" << endl;
	//做蛋糕
	baker.MakeCake();

	system("pause");
	return 0;
}