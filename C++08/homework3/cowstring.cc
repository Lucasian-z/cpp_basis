#include <cstring>
#include <iostream>
using namespace std;

class CowString
{
    class CharProxy
    {
    public:
        CharProxy(CowString& self, int idx)
        :_self(self)
        ,_idx(idx)
        {
            cout << "CharProxy(CowString& self, int idx)" << endl;
        }
        ~CharProxy()
        {
            cout << "~CharProxy()" << endl;
        }
        operator char()
        {
            return _self._pstr[_idx];
        }
        char &operator=(const char &ch);
    private:
        CowString &_self;
        int _idx;
    };
public:
    CowString()
    :_pstr(new char[5]()+4)
    {
        *(_pstr-4) = '\0';
        initref();
        cout << "CowString()" << endl;
    }
    CowString(const char *pstr)
    :_pstr(new char[strlen(pstr)+5]()+4)
    {
        cout << "CowString(const char *pstr)" << endl;
        strcpy(_pstr, pstr);
        initref();
    }
    CowString(const CowString& rhs)
    :_pstr(rhs._pstr)
    {
        cout << "CowString(const CowString& rhs)" << endl;
        increaseref();
    }
    CowString& operator=(const CowString& rhs)
    {
        cout << "CowString& operator=(const CowString& rhs)" << endl;
        if(this != &rhs)
        {
            release();
            _pstr = rhs._pstr;
            increaseref();
        }
        return *this;
    }
    int length()
    {
        return *(int*)(_pstr-4);
    }
    const char *c_str()
    {
        return _pstr;
    }
    void showref()
    {
        cout << *(int*)(_pstr-4) << endl;
    }
    friend std::ostream &operator<<(std::ostream &os, const CowString &rhs);
    CharProxy operator[](int idx);
private:
    void initref()
    {
        *(int *)(_pstr-4) = 1;
    }
    void increaseref()
    {
        ++*(int *)(_pstr-4);
    }
    void decreaseref()
    {
        --*(int *)(_pstr-4);
    }
    void release()
    {
        decreaseref();
        if(*(int *)(_pstr-4) == 0)
            delete [](_pstr-4);
    }
    char *_pstr;
};

CowString::CharProxy CowString::operator[](int idx)
{
    return CharProxy(*this, idx);
}
std::ostream &operator<<(std::ostream &os, const CowString &rhs)
{
    cout << rhs._pstr;
    return os;
}
char &CowString::CharProxy::operator=(const char &ch)
{
    if(_idx >= 0 && _idx < _self.length())
    {
        if(*(int*)(_self._pstr-4) > 1)
        {
            _self.release();
            char *tmp = new char[strlen(_self._pstr)+5]()+4;
            strcpy(tmp, _self._pstr);
            _self._pstr = tmp;
            _self.initref();
        }
        _self._pstr[_idx] = ch;
        return _self._pstr[_idx];
    }
    else
    {
        static char nullchar = '\0';
        return nullchar;
    }
}

int main(int argc, char *argv[])
{
    CowString s1 = "hello,world";
	CowString s2 = s1;
	CowString s3 = "shenzhen";
	cout << "s3 = " << s3 << endl;

	s3 = s1;
	cout << "执行赋值操作之后:" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << endl;
    s1.showref();
	cout << "s2's refcount = "<< endl;
    s2.showref();
	cout << "s3's refcount = "<< endl;
    s3.showref();

	cout << "\n 修改共享字符串的内容之后:" << endl;
	s3[0] = 'X';
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << endl;
    s1.showref();
	cout << "s2's refcount = "<< endl;
    s2.showref();
	cout << "s3's refcount = "<< endl;
    s3.showref();

	cout << "\n 执行读操作之后:" << endl;
	cout << "s1[0] = " << s1[0] << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << endl;
    s1.showref();
	cout << "s2's refcount = "<< endl;
    s2.showref();
	cout << "s3's refcount = "<< endl;
    s3.showref();
    return 0;
}