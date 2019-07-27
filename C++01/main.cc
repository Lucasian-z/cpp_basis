#include <iostream>
//using namespace std;
using std::cout;
using std::endl;
namespace lff
{
	int nameid;
	void func()
	{
		cout << "huailing" << endl;
	}
}
int nameid = 999;
int main(int argc, char *argv[])
{
	cout << "hello,world" << endl;
	using namespace lff;
	lff:nameid = 10;
	cout << "lff::nameid = " << lff::nameid << endl;
	lff::func();
	cout << "nameid = " << ::nameid << endl;
	return 0;
}
