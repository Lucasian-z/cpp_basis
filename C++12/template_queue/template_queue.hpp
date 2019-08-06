#pragma once
#include <iostream>
using namespace std;

template<class T>
class Queue
{
private:
    T *_arr;//底层数组
    int _size;
    int _front;
    int _rear;//头尾指针
public:
    Queue(int n);
    ~Queue();
    void push(T);
    void pop();
    bool isFull();
    bool isEmpty();
    T getFront();
    T getRear();
    void print();
};

template<class T>
Queue<T>::Queue(int n)
:_arr(new T[n+1]())
,_size(n+1)
,_front(0)
,_rear(0)
{
    cout << "Queue(int n)" << endl;
}

template<class T>
Queue<T>::~Queue()
{
    if(_arr)
        delete []_arr;
    cout << "~Queue()" << endl;
}

template<class T>
bool Queue<T>::isEmpty()
{
    return _front == _rear;
}

template<class T>
bool Queue<T>::isFull()
{
    return (_rear+1)%_size == (_front);
}

template<class T>
void Queue<T>::push(T n)
{
    if(isFull())
        cout << "队列已满，无法push" << endl;
    else{
        _arr[_rear] = n;
        _rear = (_rear+1)%_size;
    }
}

template<class T>
void Queue<T>::pop()
{
    if(isEmpty())
        cout << "队列已空，无法pop" << endl;
    else{
        _front = (_front+1)%_size;
    }
}

template<class T>
void Queue<T>::print()
{
    if(!isEmpty()){
        for(int i = _front; i != _rear; i = (i+1)%_size)
            cout << _arr[i] << " ";
        cout << endl;
    }
    else{
        cout << "队列为空" << endl;
    }
}

template<class T>
T Queue<T>::getFront()
{
    return _arr[_front];
}
template<class T>
T Queue<T>::getRear()
{
    return _arr[(_rear-1+_size)%_size];
}