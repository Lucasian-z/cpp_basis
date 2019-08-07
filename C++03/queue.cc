#include <iostream>
using namespace std;
//利用数组实现循环队列
class Queue
{
public:
    Queue()
    {
        cout << "这是默认构造函数" << endl;
    }
    Queue(int n)//设置给定大小的数组
    :capacity(n+1)
    ,frot(0)
    ,rear(0)
    ,nums(new int[n+1]())
    {
        cout << "这是有参构造函数" << endl;
    }
    ~Queue()
    {
        cout << "这是析构函数" << endl;
    }
    void push(int);
    void pop();
    int front();
    int back();
    bool empty();
    bool full();
    void print();

private:
    int *nums;
    int capacity;
    int frot;
    int rear;
};

void Queue::print()//打印队列元素
{
    if(!empty())
    {
        for(int i = frot; i != rear; i = (i+1)%capacity)
            cout << nums[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "队列为空" << endl;
    }
    
}

bool Queue::empty()//判断队空
{
    return frot == rear;
}

bool Queue::full()//判断队满
{
    return frot == (rear+1)%capacity;
}

void Queue::push(int x)//入队
{
    if(!full())
    {
        nums[rear] = x;
        rear = (rear+1)%capacity;
    }
    else
    {
        cout << "队列已满，无法push" << endl;
    }
    
}

void Queue::pop()//出队
{
    if(!empty())
        frot = (frot+1)%capacity;
    else
    {
        cout << "队空，无法pop" << endl;
    }
    
}

int Queue::front()//获取队首元素
{
    return nums[frot];
}

int Queue::back()//获取队尾元素
{
    //return nums[]
    if(!empty())
    {
        for(int i = frot; i != rear; i = (i+1)%capacity)
            if((i+1)%capacity == rear)
                return nums[i];
    }
    else
        cout << "队空" << endl;
}

int main(int argc, char *argv[])
{
    Queue q(10);//初始化容量为10的队列
    for(int i = 0; i < 10; ++i)
        q.push(i);
    q.print();
    q.push(1);
    q.pop();
    q.print();
    cout << q.front() << endl;
    cout << q.back() << endl;
    return 0;
}