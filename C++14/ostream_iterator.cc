#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> ivec{1,3,4,3,5,2,52,5};
    ostream_iterator<int> osi(cout, " ");//定义一个输出流大迭代器
    copy(ivec.begin(), ivec.end(), osi);//将原有元素通过泛型算法拷贝到输出流中
    cout << endl;
    return 0;
}