#include <iostream>
using std::cout;
using std::endl;
extern "C"
{
int add(int x, int y)
{
	return x+y;
}
}
int main(int argc, char *argv[])
{
	cout << add(3,45) << endl;
	return 0;
}
