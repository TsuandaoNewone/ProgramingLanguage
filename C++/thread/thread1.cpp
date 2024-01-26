#include<iostream>
#include<thread>
using namespace std;
void proc(int a,int& b)
{
    cout << "我是子线程"<<a<<",传入参数为" << b << endl;
    cout << "子线程"<<a<<"中显示子线程id为" << this_thread::get_id() << endl;
}
int main()
{
    cout << "主线程开始" << endl;
    int a = 9;
    int b = 8;
    //Create Thread
    //parse parameters
    thread th1(proc, 1, ref(b));
    thread th2(proc, 2,ref(a));//第一个参数为函数名，第二个参数为该函数的第一个参数，如果该函数接收多个参数就依次写在后面。此时线程开始执行。
    
    //此处省略多行，不要在创建完线程后马上join,应该在程序结束前join
    th2.join();//此时主线程被阻塞直至子线程执行结束。
    th1.join();
    cout << "主线程结束" << endl;
    return 0;
}