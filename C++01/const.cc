#include <iostream>
using std::cout;
using std::endl;
/*void test()
{
	int num = 10;
	const int *p = &num;//常量指针
	*p = 20;
	int a = 30;
	p = &a;
}*/

/*void test()
{
	int num = 10;
	int *const p = &num;
	*p = 20;
	int a = 20;
	p = &a;
}*/
void test()
{
	int num = 10;
	const int * const p = &num;
	*p = 30;
	int a = 20;
	p = &a;
}
int main(int argc, char *argv[])
{
	test();
	return 0;
}

