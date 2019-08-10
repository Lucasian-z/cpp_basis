#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[])
{
    vector<int> ivec;
    istream_iterator<int> isi(cin);
    copy(isi, istream_iterator<int>(), back_inserter(ivec));
    ostream_iterator<int> osi(cout, " ");
    copy(ivec.begin(), ivec.end(), osi);
    cout << endl;
    return 0;
}