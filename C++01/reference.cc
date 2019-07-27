#include <iostream>
using std::cout;
using std::endl;
int a = 100;
int & test()
{
	//int a = 100;
	cout << "before a = " << a << endl;
	int &b = a;
	b = 99;
	cout << "after a = " << a << "b = " << b << endl;
	return a;
}

int main(int argc, char *argvp[])
{
	test() = 20;
	cout << "test = " << test() << endl;
	cout << "test = " << test() << endl;
	return 0;
}
