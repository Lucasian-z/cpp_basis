#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<char, int> imap;
    vector<string> ivec;
    string line, str1, str2, res;
    int i = 0;
    while (i < 4)
    {
        cin >> line;
        ivec.push_back(line);
        ++i;
    }
    for(i = 0; i < ivec[0].size() && i < ivec[1].size(); ++i)
        if(ivec[1][i] == ivec[0][i] && ivec[0][i] <= 'Z' && ivec[0][i] >= 'A')
        {
            res += ivec[0][i];
            break;
        }    
    ++i;
    for(; i < ivec[0].size() && i < ivec[1].size(); ++i)
        if((ivec[1][i] == ivec[0][i])&&(ivec[0][i] >= 'A' && ivec[0][i] <= 'N' || ivec[0][i] >= '0' && ivec[0][i] <= '9'))
        {
            res += ivec[0][i];
            break;
        }  
    for(i = 0; i < ivec[2].size() && i < ivec[3].size(); ++i)
        if(isalpha(ivec[2][i]) && ivec[2][i] == ivec[3][i])
            break;
    cout << res << endl;
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    printf("%s ", week[(res[0]-'A')%7].c_str());
    if(res[1] <= '9')
    {
        printf("0%d:", res[1]-'0');
    }
    else
    {
        printf("%d:", res[1]-'A'+10);
    }
    
    if(i < 10)
        printf("0%d", i);
    else
        printf("%d", i);
    return 0;
}
