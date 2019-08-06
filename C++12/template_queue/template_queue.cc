#include "template_queue.hpp"

void test0()//测试整形
{
    Queue<int> que(10);
    for(int i = 0; i < 10; ++i)
        que.push(i*i);
    que.print();
    cout << "队列是否为满:" << que.isFull() << endl;
    cout << "队列是否为空:" << que.isEmpty() << endl;
    que.pop();
    cout << "删除元素之后" << endl;
    que.print();
    cout << "获取队头队尾元素" << endl;
    cout << que.getFront() << " " << que.getRear() << endl;
}

void test1()//测试字符型
{
    Queue<char> que(10);
    for(int i = 0; i < 10; ++i)
        que.push('a'+i);
    que.print();
    cout << "队列是否为满:" << que.isFull() << endl;
    cout << "队列是否为空:" << que.isEmpty() << endl;
    que.pop();
    cout << "删除元素之后" << endl;
    que.print();
    cout << "获取队头队尾元素" << endl;
    cout << que.getFront() << " " << que.getRear() << endl;
}

void test2()//测试string类型
{
    Queue<string> que(10);
    for(int i = 0; i < 10; ++i)
        que.push(string(3,'z'-i));
    que.print();
    cout << "队列是否为满:" << que.isFull() << endl;
    cout << "队列是否为空:" << que.isEmpty() << endl;
    que.pop();
    cout << "删除元素之后" << endl;
    que.print();
    cout << "获取队头队尾元素" << endl;
    cout << que.getFront() << " " << que.getRear() << endl;
}

int main(int argc, char *argv[])
{
    //test0();
    //test1();
    test2();
    return 0;
}