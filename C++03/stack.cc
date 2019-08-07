#include <iostream>
using namespace std;
//栈类
class Stack
{
public:
    Stack()
    {
        cout << "这是默认构造函数" << endl;
    }
    Stack(int n)
    :nums(new int[n]())
    ,capacity(n)
    {
        cout << "这是有参构造函数" << endl;
        stacksize = 0;
    }
    ~Stack()
    {
        cout << "这是析构函数" << endl;
    }
    void push(int);
    void pop();
    int top();
    bool empty();
    bool full();
    void print();

private:
    int *nums;
    int stacksize;
    int capacity;
};

void Stack::print()//打印栈中元素
{
    for(int i = 0; i < stacksize; ++i)
        cout << nums[i] << endl;
}

bool Stack::empty()
{
    return stacksize == 0;
}

bool Stack::full()
{
    return stacksize == capacity;
}

void Stack::push(int x)//压栈
{
    if(!full())
    {
        nums[stacksize] = x;
        ++stacksize;
    }
    else
    {
        cout << "栈已满，无法push" << endl;
    }
}

void Stack::pop()//弹栈
{
    if(empty())
    {
        cout << "栈空，无法弹栈" << endl;
    }
    else
    {
        --stacksize;
    }
    
}

int Stack::top()//获取栈顶元素
{
    return nums[stacksize-1];
}

int main(int argc, char *argv[])
{
    Stack s1(10);//初始化容量为10的栈
    s1.push(10);
    s1.push(12);
    s1.push(14);
    cout << s1.top() << endl;//输出栈顶元素
    s1.pop();
    cout << s1.top() << endl;
    //s1.print();
    return 0;
}