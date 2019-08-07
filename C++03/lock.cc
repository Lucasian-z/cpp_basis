#include <iostream>
#include <pthread.h>
using namespace std;

int num = 0;
class Mutexlock
{
public:
    static Mutexlock* getinstance()
    {
        if(pinstance == nullptr)
            pinstance = new Mutexlock();
        return pinstance;
    }
    static Mutexlock* destory()
    {
        if(pinstance)
            delete pinstance;
        pinstance = nullptr;
    }
    Mutexlock();
    ~Mutexlock();
    void lock();
    void unlock();

public:
    pthread_mutex_t mutex;
private:
    
    static Mutexlock *pinstance;
};

Mutexlock * Mutexlock::pinstance = nullptr;
Mutexlock::Mutexlock()//将锁初始化为0
{
    pthread_mutex_init(&mutex, nullptr);
}
Mutexlock::~Mutexlock()
{
    cout << "这是析构函数" << endl;
}

void Mutexlock::lock()
{
    pthread_mutex_lock(&mutex);
}
void Mutexlock::unlock()
{
    pthread_mutex_unlock(&mutex);
}

class Condition
{
public:
    Condition();
    ~Condition()
    {};
    void wait();
    void notify();
    void notifyall();
    static Condition* getinstance()
    {
        if(pinstance == nullptr)
            pinstance = new Condition();
        return pinstance;
    }
    static Condition* destory()
    {
        if(pinstance)
            delete pinstance;
        pinstance = nullptr;
    }

private:
    static Condition* pinstance;
    pthread_cond_t cond;
};
Condition* Condition::pinstance = nullptr;
Condition::Condition()
{
    pthread_cond_init(&cond, nullptr);
    cout << "这是默认构造函数" << endl;
}

void Condition::wait()
{
    Mutexlock *p = Mutexlock::getinstance();
    pthread_cond_wait(&cond,&p->mutex);
}

void Condition::notify()
{
    pthread_cond_signal(&cond);
}

void Condition::notifyall()
{
    pthread_cond_broadcast(&cond);
}

void *thread1(void *p)//将num加至40000000
{
    int num1 = 0;
    Mutexlock *p1 = Mutexlock::getinstance();
    Condition *p2 = Condition::getinstance();
    while(1)
    {
        p1->lock();
        if(num < 40000000)
        {
            ++num;
            ++num1;
            if(num == 40000000)
                p2->notify();
        }
        else
        {
            p1->unlock();
            break;
        }    
        p1->unlock();
        
    }   
    cout << "1:" << num1 << endl;   
    p1->destory();  
    p2->destory();
}
void *thread2(void *p)//将num加至40000000
{
    int num2 = 0;
    Mutexlock *p1 = Mutexlock::getinstance();
    Condition *p2 = Condition::getinstance();
    while(1)
    {
        p1->lock();
        if(num < 40000000)
        {
            ++num;
            ++num2;
            if(num == 40000000)
                p2->notify();
        }
        else
        {
            p1->unlock();
            break;
        }
        p1->unlock();
        
    }
    cout << "2:" << num2 << endl;
}

void* thread3(void *p)//当thread1和thread2将num加至40000000时，thread3将num重置
{
    Mutexlock *p1 = Mutexlock::getinstance();
    Condition *p2 = Condition::getinstance();
    p1->lock();
    if(num < 40000000)
    {
        p2->wait();
    }
    num = 0;
    p1->unlock();
}

int main(int argc, char *argv[])
{
    pthread_t p1, p2, p3;
    pthread_create(&p1, nullptr, thread1, nullptr);
    pthread_create(&p2, nullptr, thread2, nullptr);
    pthread_create(&p3, nullptr, thread3, nullptr);

    pthread_join(p1, nullptr);
    pthread_join(p2, nullptr);
    pthread_join(p3, nullptr);
    return 0;
}