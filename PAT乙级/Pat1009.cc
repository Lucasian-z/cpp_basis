#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> ivec;
    string word;
    while (cin >> word)
    {
        ivec.push_back(word);
        if(cin.get() == '\n')
            break;
    }
    auto it2 = ivec.rend();
    --it2;
    for(auto it = ivec.rbegin(); it != it2; ++it)
    {
        cout << *it << " ";
    }
    cout << *ivec.begin();
    return 0;
}