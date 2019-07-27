#include <iostream>
using std::cout;
using std::endl;

int num = 999;

namespace wd
{
	int num = 10;
	void func(int num)
	{
		cout << "num = " << num << endl;
		cout << "wd::num = " << wd::num << endl;
		cout << "::num = " << ::num << endl;
	}
}

void test()
{
	using namespace wd;
	func(777);
}
int main(int argc, char *argv[])
{
	test();
	return 0;
}
