#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;
template<class T>
class Myvector
{
public:
    Myvector();
    ~Myvector();
    void push_back(const T &item);
    void pop_back();
    size_t size()const { return _finish - _start; }
    size_t capacity()const { return _end_of_storge - _start; }
    T* begin()  { return _start; }
    T* end() { return _finish; }
    T& operator[](size_t idx)
    {
        return _start[idx];
    }
private:
    void reallocate();
private:
    static allocator<T> alloc;
    T* _start;
    T* _finish;
    T* _end_of_storge;
};
template<class T>
allocator<T> Myvector<T>::alloc;
template<class T>
void Myvector<T>::reallocate()
{
    int capa = capacity();
    int newcapa = 2*capa > 0 ?2*capa:1;
    T* ptmp = alloc.allocate(newcapa);
    if(_start)
    {
        uninitialized_copy(_start, _finish, ptmp);
        while(_finish != _start)//销毁原对象
            alloc.destroy(--_finish);
        alloc.deallocate(_start, capa);
    }
    _start = ptmp;
    _finish = _start + capa;
    _end_of_storge = _start + newcapa;
}

template<class T>
Myvector<T>::Myvector()
:_start(nullptr)
,_finish(nullptr)
,_end_of_storge(nullptr)
{
    cout << "Myvector()" << endl;
}

template<class T>
Myvector<T>::~Myvector()
{
    while(_finish != _start)
        alloc.destroy(--_finish);
    alloc.deallocate(_start, capacity());
    cout << "~Myvector()" << endl;
}

template<class T>
void Myvector<T>::push_back(const T &item)
{
    if(size() == capacity())
        reallocate();
    alloc.construct(_finish++, item);
}

template<class T>
void Myvector<T>::pop_back()
{
    if(_start)
        alloc.destroy(--_finish);
}

template<class container>
void display(container &c)
{
    auto it = c.begin();
    while(it != c.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

template<class container>
void showcapacity(const container &c)
{
    cout << "size = " << c.size() << endl
         << "capacity = " << c.capacity() << endl;
}


int main(int argc, char *argv[])
{
    Myvector<int> s;
    s.push_back(2);
    showcapacity(s);
    s.push_back(2);
    showcapacity(s);
    s.push_back(2);
    showcapacity(s);
    s.push_back(2);
    showcapacity(s);
    s.push_back(2);
    showcapacity(s);
    display(s);
    cout << s[3] << endl;
    s.push_back(3);
    showcapacity(s);
    display(s);
    s.pop_back();
    display(s);
    return 0;
}