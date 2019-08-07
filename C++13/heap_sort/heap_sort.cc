#include <iostream>
#include <map>

using namespace std;
template<class T>
void Swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}
template<class T, class Compare = less<T>>
class HeapSort
{
public:
    HeapSort(T *a, int n)
    :arr(a)
    ,_n(n){};
    void heapAdjust(int start, int end){
        int dad = start, son = 2*dad+1;
        while(son < end){
            if(son+1 < end && arr[son] > arr[son+1])
                ++son;
            if(arr[dad] < arr[son])
                break;
            else{
                Swap(arr[dad], arr[son]);
                dad = son;
                son = 2*dad + 1;
            }
        }
    }
    void sort(){
        int i;
        for(i = _n/2-1; i >= 0; --i){
            heapAdjust(i, _n);
        }
        swap(arr[0], arr[_n-1]);
        for(i = _n-1; i > 1; --i){
            heapAdjust(0, i);
            Swap(arr[0], arr[i-1]);
        }
    }
private:
    T *arr;
    int _n;
};

int main(int argc, char *argv[])
{
    int array[10] = {1,2,33,4,2,2,4,5,7,3};//测试整形数据
    HeapSort<int> hs(array, 10);
    hs.sort();
    for(auto const &item : array)
        cout << item << " ";
    cout << endl;
    char array2[12] = "kjihgfedcba";//测试字符型数据
    HeapSort<char> hs2(array2, 12);
    hs2.sort();
    for(auto const &item : array2)
        cout << item << " ";
    cout << endl;
    return 0;
}