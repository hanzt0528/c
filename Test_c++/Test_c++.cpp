// Test_semaphore_console.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream> 
#include <windows.h> 
#include <thread>
#include <mutex>
#include <condition_variable> 
using namespace std;


std::mutex mutex1;

int f1(int n)
{
	
	for (int i = 0; i < 5; ++i) {
		mutex1.lock();
		std::cout << "Thread 1 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		mutex1.unlock();
	}
	return 0;
}

void f2(int& n)
{
	for (int i = 0; i < 5; ++i) {
		mutex1.lock();
		std::cout << "Thread 2 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		mutex1.unlock();
	}
}
/////////////////////////////

std::condition_variable c;
// ����ʹ��mutex������recursive_mutex����Ϊ������Ҫһ���Ի�ȡ���ͷ�
std::mutex mu; // We use a mutex rather than a recursive_mutex because the lock has to be acquired only and exactly once.
void foo5()
{
	std::unique_lock<std::mutex> lock(mu); // Lock the mutex

	c.notify_one(); // WakeConditionVariable. It also releases the unique lock  �ȴ�������������Ҳ���ͷ�unque lock

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << "foo5 notify_one\n";
}
void func5()
{
	std::unique_lock<std::mutex> lock(mu); // Lock the mutex

	std::thread t1(foo5);
	
	// �ȼ���SleepConditionVariableCS��������mutex ����nu��������foo5������
	c.wait(lock); // Equal to SleepConditionVariableCS. This unlocks the mutex mu and allows foo5 to lock it 

	std::cout << "func5 waited lock\n";

	t1.join();
}

////////////////////////////////////



int g_i = 0;
std::mutex g_i_mutex;  // ���� g_i

void safe_increment()
{
	std::lock_guard<std::mutex> lock(g_i_mutex);
	++g_i;

	std::cout << std::this_thread::get_id() << ": " << g_i << '\n';

	// g_i_mutex �����뿪������ʱ�Զ��ͷ�
}

/////////////////////////////////////////


std::mutex mtx; // ȫ�ֻ�����.
std::condition_variable cv; // ȫ����������.
bool ready = false; // ȫ�ֱ�־λ.

void do_print_id(int id)
{
	std::unique_lock <std::mutex> lck(mtx);
	//while (!ready) // �����־λ��Ϊ true, ��ȴ�...
		cv.wait(lck); // ��ǰ�̱߳�����,lck��unlock
					  // �̱߳�����, lck��lock



	std::cout << "thread " << id << '\n';
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	//�����˳�,lck���÷�ΧʧЧ,lck��unlock,����lock mtx���̻߳�����еĻ���.
}

void go()
{

	std::cout << "go" << '\n';
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	std::unique_lock <std::mutex> lck(mtx);
	ready = true; // ����ȫ�ֱ�־λΪ true.
	cv.notify_all(); // ���������߳�.

}
///////////////////////////////////////////////////////////

//std::mutex mtx;
//std::condition_variable cv;

int cargo = 0;
bool shipment_available()
{
	return cargo != 0;
}

// �������߳�.
void consume(int n)
{
	for (int i = 0; i < n; ++i) {
		std::unique_lock <std::mutex> lck(mtx);
		cv.wait(lck, shipment_available);//��wait����Ϊfalseʱ,����wait�Ż�������ǰ�߳�,���յ������̵߳�֪ͨʱ,ֻ��predicateΪtrueʱ,�Ż�������.
		std::cout << cargo << '\n';
		cargo = 0;
	}
}
///////////////////////////////////////////////////////////////////


int value;

void do_read_value()
{
	std::cin >> value;
	cv.notify_one();
}

////////////////////////////////////////////////////////////

void print_id(int id) {
	std::unique_lock<std::mutex> lck(mtx);
	while (!ready) cv.wait(lck);
	// ...
	std::cout << "thread " << id << '\n';
}

void go2() {
	std::unique_lock<std::mutex> lck(mtx);
	std::notify_all_at_thread_exit(cv, std::move(lck));
	ready = true;
}


int main()
{
	//sample1.
	//int n = 0;
	//std::thread t1; // t1 ���߳�
	//std::thread t2(f1, n + 1); // ��ֵ����
	//std::thread t3(f2, std::ref(n)); // �����ô���
	//std::thread t4(std::move(t3)); // t4 �������� f2() �� t3 �������߳�
	//std::thread::id id2 =t2.get_id();
	//std::cout << "t2 thread id " << id2 << '\n';
	//std::thread::id id4 = t4.get_id();
	//std::cout << "t4 thread id " << id4 << '\n';

	//t2.join();
	//t4.join();
	//std::cout << "Final value of n is " << n << '\n';

	//sample2.
	//func5();

	//sample3.
	//std::cout << "main: " << g_i << '\n';

	//std::thread t1(safe_increment);
	//std::thread t2(safe_increment);

	//t1.join();
	//t2.join();

	//std::cout << "main: " << g_i << '\n';

	//sample4.
	//std::thread threads[10];
	//// spawn 10 threads:
	//for (int i = 0; i < 10; ++i)
	//	threads[i] = std::thread(do_print_id, i);

	//std::cout << "10 threads ready to race...\n";
	//go(); // go!

	//for (auto & th : threads)
	//	th.join();


	//for (int i = 0; i < 10; ++i)
	//	threads[i] = std::thread(do_print_id, i);


	//go(); // go!

	//for (auto & th : threads)
	//	th.join();


	//sample5.
	//std::thread consumer_thread(consume, 10); // �������߳�.

	//										  // ���߳�Ϊ�������߳�, ���� 10 ����Ʒ.
	//for (int i = 0; i < 10; ++i) {
	//
	//	while (shipment_available())
	//		std::this_thread::yield();//��shipment_available()Ϊtrueʱ,������ǰ�̵߳�ִ��,��cpu�ø������߳�ִ��.


	//	std::unique_lock <std::mutex> lck(mtx);
	//	cargo = i + 1;
	//	cv.notify_one();
	//}

	//consumer_thread.join();

	//sample6.

	//std::cout << "Please, enter an integer (I'll be printing dots): \n";
	//std::thread th(do_read_value);

	//std::mutex mtx;
	//std::unique_lock<std::mutex> lck(mtx);
	//while (cv.wait_for(lck, std::chrono::seconds(1)) == std::cv_status::timeout) {
	//	std::cout << '.';
	//	std::cout.flush();
	//}

	//std::cout << "You entered: " << value << '\n';

	//th.join();

	//sample7.
	std::thread threads[10];
	// spawn 10 threads:
	for (int i = 0; i<10; ++i)
		threads[i] = std::thread(print_id, i);
	std::cout << "10 threads ready to race...\n";

	std::thread(go2).detach(); // go!

	for (auto& th : threads) th.join();


	return 0;


}

