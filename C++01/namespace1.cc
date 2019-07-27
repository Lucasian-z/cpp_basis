#include <iostream>
using std::cout;
using std::endl;

namespace huailing
{
	int num = 999;
	namespace lifangfei
	{
		int num = 899;
		void func()
		{
			cout << "hello,I am lifangfei" << endl;
		}
	}
}

namespace ranjiarui
{
	int num = 799;
	//using namespace huailing;	
	void func()
	{
		cout << "hello,I am ranjiarui" << endl;
		huailing::lifangfei::func();
	}
}

int main(int argc, char *argv[])
{
	using namespace ranjiarui;
	func();
	return 0;
}
