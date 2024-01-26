#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;
void proc1(int a)
{
	unique_lock<mutex> g1(m, defer_lock);//始化了一个没有加锁的mutex
	cout << "" << endl;
	g1.lock();//手动加锁，注意，不是m.lock();注意，不是m.lock(),m已经被g1接管了;
	cout << "proc1函数正在改写a" << endl;
	cout << "原始a为" << a << endl;
	cout << "现在a为" << a + 2 << endl;
	g1.unlock();//临时解锁
	cout << "unlock temprarily" << endl;
	g1.lock();
	cout << "unlock automatically" << endl;
}//自动解锁

void proc2(int a)
{
	//m.lock();
	unique_lock<mutex> g2(m, try_to_lock);//尝试加锁一次，但如果没有锁定成功，会立即返回，不会阻塞在那里，且不会再次尝试锁操作。
	if (g2.owns_lock()) {//锁成功
		cout << "proc2函数正在改写a" << endl;
		cout << "原始a为" << a << endl;
		cout << "现在a为" << a + 1 << endl;
	}
	else {//锁失败则执行这段语句
		cout << "lock failed" << endl;
	}
	//m.unlock();
}//自动解锁

int main()
{
	int a = 0;
	thread t1(proc1, a);
	thread t2(proc2, a);
	t1.join();
	t2.join();
	return 0;
}