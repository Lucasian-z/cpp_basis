#include <string.h>
#include <iostream>
using namespace std;
class String
{
	public:
		String();//默认构造函数
		String(const char *pstr);//有参构造函数
		String(const String &rhs);//拷贝构造函数
		String &operator=(const String &rhs);//赋值函数
		~String();//析构函数
		void print();
	private:
		char *str;
};

String::String()
{
	str = new char[1];//默认构造函数，将字符串初始化为空
	*str = '\0';
	//cout << "调用默认构造函数" << endl;
}

String::String(const char *pstr)//有参构造函数
{
	if(pstr == NULL)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		str = new char[strlen(pstr)+1];
	   	strcpy(str, pstr);
	}
}

String::String(const String &rhs)
{
	int len = strlen(rhs.str)+1;
	str = new char[len]();
	strcpy(str, rhs.str);
}

String &String::operator=(const String &rhs)
{
	int len = strlen(rhs.str)+1;
	str = new char[len]();
	strcpy(str, rhs.str);
	return *this;
}
void String::print()
{
	cout << str << endl;
	//cout << "这是打印函数" << endl;
}

String::~String()//析构函数
{
	delete []str;
}

int main(int argc, char *argv[])
{
	String str1;
	str1.print();
	String str2 = "Hello,world";
	String str3 = "wangdao";
	str2.print();
	str3.print();
	String str4 = str3;
	str4.print();
	str4 = str2;
	str4.print();
	return 0;
}
