#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

template <class T>
class Myvector
{
public:
    Myvector();
    ~Myvector();
    void push_back(const T &item);
    void pop_back();
    size_t size()const;
    size_t capacity()const;
    const T* begin()const { return _start; }
    const T* end()const { return _finish; }
    T& operator[](size_t idx)
    {
        return _start[idx];
    }
private:
    void realloc();
private:
    static allocator<T> alloc;
    T *_start;
    T *_finish;
    T *_end_of_storge;
};
template <class T>
allocator<T> Myvector<T>::alloc;
template <class T>
Myvector<T>::Myvector()
:_start(nullptr)
,_finish(nullptr)
,_end_of_storge(nullptr)
{
    cout << "Myvector()" << endl;
}

template <class T>
Myvector<T>::~Myvector()
{
    cout << "~Myvector()" << endl;
    if(_start)
    {
        while(_finish != _start)
            alloc.destroy(--_finish);
        alloc.deallocate(_start, capacity());
    }
}
template <class T>
void Myvector<T>::push_back(const T &item)
{
    if (size() == capacity())
    {
        realloc();
    }
    alloc.construct(_finish++,item);
}
template <class T>
void Myvector<T>::pop_back()
{
    if(size() > 0)
        alloc.destroy(--_finish);
}
template <class T>
size_t Myvector<T>::size()const
{
    return _finish - _start;
}
template <class T>
size_t Myvector<T>::capacity() const
{
    return _end_of_storge - _start;
}
template <class T>
void Myvector<T>::realloc()
{
    size_t n = capacity();
    size_t capa = 2 * n > 0 ? 2 * n : 1;
    T *ptmp = alloc.allocate(capa);
    if (_start)
    {
        uninitialized_copy(_start, _finish, ptmp);
        while (_finish != _start)
        {
            alloc.destroy(--_finish);
        }
        alloc.deallocate(_start, n);
    }
    _start = ptmp;
    _finish = _start + n;
    _end_of_storge = _start + capa;
}
template<class container>
void display(const container &c)
{
    auto it = c.begin();
    while (it != c.end())
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
    Myvector<int> ivec;
    showcapacity(ivec);
    ivec.push_back(3);
    showcapacity(ivec);
    ivec.push_back(3);
    showcapacity(ivec);
    ivec.push_back(4);
    showcapacity(ivec);
    display(ivec);
    cout << ivec[2] << endl;
    return 0;
}