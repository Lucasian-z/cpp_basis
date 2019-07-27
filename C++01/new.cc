#include <iostream>
using std::cout;
using std::endl;

void test()
{
	int *p = new int(10);
	cout << "*p = " << *p << endl;
	int *p1 = new int[10];
	for(int i =0 ; i < 10; ++i)
		cout << p1[i] << endl;
	int *p2 = new int[10]();
	for(int i =0 ; i < 10; ++i)
		cout << p2[i] << endl;
}
int main(int argc, char *argv[])
{
	test();
	return 0;
}
