#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
	int num = 999;
	void func()
	{
		cout << "huailing" << endl;
	}
}

int main(int argc, char *argv[])
{
	cout << "num = " << wd::num << endl;
	wd::func();
	return 0;
}
