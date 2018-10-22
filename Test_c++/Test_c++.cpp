// Test_semaphore_console.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream> 
#include <windows.h> 
#include <thread>
#include <mutex>
#include <condition_variable> 
#include <vector>
#include <initializer_list>
#include <assert.h>
#include <sstream>
#include <tuple>

#include <map>

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
// 我们使用mutex而不是recursive_mutex是因为该锁需要一次性获取和释放
std::mutex mu; // We use a mutex rather than a recursive_mutex because the lock has to be acquired only and exactly once.
void foo5()
{
	std::unique_lock<std::mutex> lock(mu); // Lock the mutex

	c.notify_one(); // WakeConditionVariable. It also releases the unique lock  等待条件变量，它也会释放unque lock

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << "foo5 notify_one\n";
}
void func5()
{
	std::unique_lock<std::mutex> lock(mu); // Lock the mutex

	std::thread t1(foo5);
	
	// 等价与SleepConditionVariableCS，它解锁mutex 变量nu，并允许foo5来加锁
	c.wait(lock); // Equal to SleepConditionVariableCS. This unlocks the mutex mu and allows foo5 to lock it 

	std::cout << "func5 waited lock\n";

	t1.join();
}

////////////////////////////////////



int g_i = 0;
std::mutex g_i_mutex;  // 保护 g_i

void safe_increment()
{
	std::lock_guard<std::mutex> lock(g_i_mutex);
	++g_i;

	std::cout << std::this_thread::get_id() << ": " << g_i << '\n';

	// g_i_mutex 在锁离开作用域时自动释放
}

/////////////////////////////////////////


std::mutex mtx; // 全局互斥锁.
std::condition_variable cv; // 全局条件变量.
bool ready = false; // 全局标志位.

void do_print_id(int id)
{
	std::unique_lock <std::mutex> lck(mtx);
	//while (!ready) // 如果标志位不为 true, 则等待...
		cv.wait(lck); // 当前线程被阻塞,lck被unlock
					  // 线程被唤醒, lck被lock



	std::cout << "thread " << id << '\n';
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	//函数退出,lck作用范围失效,lck被unlock,其他lock mtx的线程获得运行的机会.
}

void go()
{

	std::cout << "go" << '\n';
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	std::unique_lock <std::mutex> lck(mtx);
	ready = true; // 设置全局标志位为 true.
	cv.notify_all(); // 唤醒所有线程.

}
///////////////////////////////////////////////////////////

//std::mutex mtx;
//std::condition_variable cv;

int cargo = 0;
bool shipment_available()
{
	return cargo != 0;
}

// 消费者线程.
void consume(int n)
{
	for (int i = 0; i < n; ++i) {
		std::unique_lock <std::mutex> lck(mtx);
		cv.wait(lck, shipment_available);//当wait条件为false时,调用wait才会组赛当前线程,当收到其他线程的通知时,只有predicate为true时,才会解除阻塞.
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
enum class Car {
   car_small,
   car_big
};

enum  class House
{
	house_small,
	house_big
};
#define NULL2 (void*)0 //c language

template<typename func>
void filter(func f, vector<int> arr) {
	for (auto i : arr)
	{
		if (f(i))
		{
			cout << i << endl;
		}
	}
}


long double operator"" cm(long double x) { return x * 10; }
int operator"" hex(char const*str, size_t l) {
	cout << "size = " << l << endl;
	return 10; 
}

//Lean c++ 11


tuple<string, int> getNameAge()
{
	return make_tuple("Bob", 34);
}


int main()
{

	//Car c1 = Car::car_small;
	//House h1 = House::house_small;

	//if (c1 == h1)
	//{

	//}

	//sample1.
	//int n = 0;
	//std::thread t1; // t1 非线程
	//std::thread t2(f1, n + 1); // 按值传递
	//std::thread t3(f2, std::ref(n)); // 按引用传递
	//std::thread t4(std::move(t3)); // t4 现在运行 f2() 。 t3 不再是线程
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
	//std::thread consumer_thread(consume, 10); // 消费者线程.

	//										  // 主线程为生产者线程, 生产 10 个物品.
	//for (int i = 0; i < 10; ++i) {
	//
	//	while (shipment_available())
	//		std::this_thread::yield();//当shipment_available()为true时,放弃当前线程的执行,将cpu让给其他线程执行.


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

	//static_assert( sizeof(int) == 4 );

	//std::thread threads[10];
	// spawn 10 threads:
	//for (int i = 0; i<10; ++i)
	//	threads[i] = std::thread(print_id, i);
	//std::cout << "10 threads ready to race...\n";

	//std::thread(go2).detach(); // go!

	//for (auto& th : threads) th.join();


	/*
	* 1 Initializer list
	*/

	//c++ 03 initializer list:
	int arr[4] = { 3,2,4,5 };

	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);

	//c++ 11 extended the support
	vector<int> v2 = {3,2,4,5};//calling initializer_list constructor
	//or vector<int> v2{3,2,4,5}; // this way is just all right.

	//all the relevant STL container have been updated to accept initilizer_list.

	//Define your own initializer_list constructor.
	class BoVector {
		vector<int> m_vec;
	public:
		BoVector(const initializer_list<int>& v)
		{
			for (auto itr = v.begin(); itr != v.end(); ++itr)
			{
				m_vec.push_back(*itr);
			}
		}
	};

	BoVector b = { 1,2,3 };

	//Automatic normal Initialization
	class Rectangle {
	public:
		Rectangle(int height, int width, int length) {};
		static void draw_rect(Rectangle r) { ; };
	};

	Rectangle::draw_rect({ 12,11,10 });

	/*
	 *2. Uniform Initialization
	*/
	//c++ 03
	class Dog {// Aggregate class or struct
	public:
		int age;
		string name;
	};

	Dog d1 = { 5,"Henry" };

	//c++ 11 extended the scope of curly brace initialization.
	class Dog11 {
	public:
		Dog11(int age,string name) {};
	};

	Dog11 d11 = { 5,"Henry" };

	/* Uniform Initialization Search Order
	*1.Initializer_list constructor
	*2.Regular constructor that takes the appropriate parameters.
	*3.Aggregate initializer.
	*/

	class Dog12 {
	public:
		int age;                                  // 3rd choice
		Dog12(int a) { age = a; };                // 2nd choice 
		Dog12(const initializer_list<int>& vec)	{ // 1st choice
			age = *(vec.begin());           
		}
	};


	/*
	* 3.auto type
	*/
	vector<int> vec = { 3,2,4,5 };//calling initializer_list constructor
	vector<int> m_vec;
	//c++ 03
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		m_vec.push_back(*it);
	}

	auto a = 6; // a is a integer
	auto b1 = 9.6;//  b is a double
	auto c = a; // c is a integer
	auto const x = a; // int const x = a
	auto & y = a; // int &y = a
	// it's a static type,no run-time cost,fat-free.
	//it also makes code easier to maintain.

	/*
	 *4.foreach
	*/

	//c++ 03
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		m_vec.push_back(*it);
	}

	//c++ 11
	for (auto i : vec)
	{
		m_vec.push_back(i);
	}

	for (auto &i : vec)
	{
		i++;
	}

	auto g1 = begin(vec);
	int arr1[4] = { 3,2,4,5 };
	auto g = begin(arr1);//g == 3
	auto g2 = end(arr1);// g2 == 5;

	/*
	 * 5.nullptr
	 * To replace NULL in c++ 03
	*/

	class Foo
	{
	public:
		void foo(int i) {
			cout << "foo_int" << endl;

		};
		void foo(char* pc) {
			cout << "foo_char" << endl;
		};
	};

	Foo f;

	f.foo(NULL);// Ambiguity ,it call foo(int) ,because NULL define to 0 in c++

	//c++ 11
	f.foo(nullptr); // call  foo(char*)

	/*
	 * 6.enum class
	*/
	//c++ 03
	enum apple {green_a,red_a};
	enum orange {big_o,small_o};

	apple a1 = green_a;
	orange o = big_o;

	if (a1 == o)
	{
		cout << "green apple and big orange are the same\n";
	}
	else
	{
		cout << "green apple and big orange are not the same\n";
	}

	//c++ 11
	{
		enum class apple { green, red };
		enum class orange { big_o11, small_o11 };
		apple a = apple::green;
		orange o = orange::big_o11;

		// Compile fails because we haven't define == (apple,orange)
		//if (a == o)
		//{
		//	cout << "green apple and big orange are the same\n";
		//}
		//else
		//{
		//	cout << "green apple and big orange are not the same\n";
		//}
	}

	/*
	 * 7. static_assert
	*/

	//run-time assert
	assert(0 != 1);

	// compile time assert(c++ 11)
	static_assert( sizeof(int) == 4,"because equal 4" );

	/*
	 *8. Delegating Constructor
	*/
	{
		class Dog{
		public:
			Dog() {};

			Dog(int a) {
				Dog(); doOtherThings(a);
			}
			void doOtherThings(int a) {};
		};
	}

	// c++ 03
	{
		class Dog {
		public:
			void init() {};
			Dog() { init(); };

			Dog(int a) {
				init(); doOtherThings(a);
			}
			void doOtherThings(int a) {};
		};
	}

	//c++ 11
	{
		class Dog {
		public:

			Dog() { };

			Dog(int a) : Dog(){ // Limitation:Dog() has to be call first.
				 doOtherThings(a);
			}
			void doOtherThings(int a) {};
		};

	}

	/*
	 * 9. override (for virtual function)
	 * To avoid inadvertently create new function in derived class.
	*/
	{
		//c++ 03 
		class Dog {
			virtual void A(int)=0;
			virtual void B()const = 0;
		};

		class YelloDog :public Dog {
			virtual void A(float) {};//create a new function.
			virtual void B() {}; // create a new function.
		};
	}

	{
		//c++ 11
		class Dog {
			virtual void A(int) = 0;
			virtual void B()const = 0;
			void C() {};
		};

		class YelloDog :public Dog {
			//virtual void A(float) override;//Error: no function to override
			//virtual void B() override; //Error: no function to override
			//void C() override; // Error: not a virtual function
		};

	}

	/*
	 * final (for virtual function and for class)
	*/
	{
		class Dog final { // no class can be derived from Dog
			
		};

		class YelloDog {
			virtual void bark() final = 0;//no class can override bark();
		};
	}
	
	/*
	 *11. Compiler Generated Default Constructor
	*/
	{
		class Dog { 
		public:
			Dog(int a) {};
		};
		
		//Dog g; //Error:compiler will not generate the default constructor
	}
	{
		//c++ 11
		class Dog {
		public:
			Dog(int a);
			Dog()=default;
		};

		Dog g; //compiler will  generate the default constructor
	}

	/*
	 *12. delete 
	*/
	{
		class Dog {
		public:
			Dog(int a) {};
		
		};
		Dog a(2);
		Dog b(3.0);// 3.0 is converted from double to int
		a = b; // compiler generated assignment operator
	}

	{
		//c++ 11
		class Dog {
		public:
			Dog(int a) {};
			Dog(double a) = delete;
			Dog & operator=(const Dog&) = delete;

		};
		Dog a(2);
		//Dog b(3.0);
		//a = b;

	}

	/*
	 * 13.constexpr
	*/
	{
		int arr[6]; //ok
		//int A(){ return 3; };
		//int arr[A() + 3];// Compile error

	}
	{
		//c++ 11
		//constexpr int A() { return 3; };

		//int arr[A() + 3]; // create an array of size 6

		//constexpr int cubed(int x) { return x*x*x; };
		//int y = cubed(1789); // computed at compile time,so it is super fast.
	}

	/*
	 *14. New String Literals
	*/
	{
		//c++ 03 
		char * a = "string";
	}
	{
		//c++ 11
		char * a = u8"string"; // define a UTF-8 string.
		char16_t *b = u"string";// define a UTF-16 string.
		char32_t *c = U"string";// define a UTF-32 string.
		//char * d = R"string \\";//to define raw string.
	}

	/*
	 * 15 lambda fuction
	*/
	{
		cout << [](int x, int y) {return x + y; }(3, 4) << endl; // output 7
		auto f = [](int x, int y) {return x + y; };
		cout << f(3, 4) << endl;//output 7



		vector<int> v{ 1,2,3,4,5,6 };

		filter([](int x) {return x > 3; }, v);//output 4,5,6
		int y =1;
		int z = 1;

		filter([&](int x) {return x > y+z; }, v);//output 3,4,5,6
		//[&] tells compiler that we want variable capture.
	}

	/*
	 * 16 user defined literals
	*/
	{
		//c++ 11
		//long double operator"" _cm(long double x) { return x * 10; }
		long double height = 13.0cm;
		cout << height << endl;//output 130


		//int operator"" hex(char const*str, size_t l) {return 10;}
		cout << "fft"hex << endl;
	}

	/*
	 * 17 decltype
	 *It is equivalent of GUN typeof
	*/
	{
		const int & foo();
		decltype(foo()) x1 = 0;//x1 is int &,here function foo() be don't compute ,only used return value of it.
		struct S { double x; };
		decltype(S::x) x2; // x2 is double

	}

	/*
	 * 18 tuple
	*/

	tuple<int, string, char> t(32, "Penny wise", 'a');

	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	cout << get<2>(t) << endl;

	get<1>(t) = "Pound foolish";

	cout << get<1>(t) << endl;

	string &s = get<1>(t);

	s = "Patience is virtue";
	cout << get<1>(t) << endl;

	//get<3>(t);// won't compile,t only has 3 fields.
	
	int i = 1;
	//get<i>(t);// Won't compile,i must be a compile time constant

	tuple<int, string, char> t2;

	t2 = tuple<int, string, char>(12, "Curiosity kills the cat",'d');
	t2 = make_tuple(12, "Curiosity kills the cat", 'd');

	cout << get<0>(t2) << endl;
	cout << get<1>(t2) << endl;
	cout << get<2>(t2) << endl;

	if (t > t2)// Lexicographical comparison
	{
		cout << "t is larger than t2" << endl;
	}

	t = t2; // member by member copying.


	//tuple can store references! STL containers such as vectors cannot. Pair can.
	string st = "In for a penny";
	tuple<string&> t3(st);
	//auto t3 = make_tuple(ref(st));// do the same thing.
	get<0>(t3) = "In for a pound";
	cout << st << endl;

	int x1;
	string y1;
	char z1;

	std::make_tuple(std::ref(x1), std::ref(y1), std::ref(z1)) = t2; // assign t2 to x,y,z
	
	//std::tie(x1, y1, z1) = t2;//same thing.

	cout << y1 << endl;

	cout << get<1>(t2) << endl;
	
	//std::tie(x, std::ignore, z) = t2;//get<1>(t2) is ignored.

	//Other features

	auto t4 = std::tuple_cat(t2, t3);
	cout << get<3>(t4) << endl; //"In for a pound"

	//type traist
	cout << std::tuple_size<decltype(t4)>::value << endl;
	std::tuple_element<1, decltype(t4)>::type dd; // dd is a string;
    
	struct Person { string name; int age; } p;
	tuple<string, int> t6;
	cout << p.name << "" << p.age << endl;
	cout << get<0>(t6) << get<1>(t6) << endl;

	//As a one-time only structure to transfer a group of data.
	string name;
	int age;
	std::tie(name, age) = getNameAge();

	//Comparison of tuples
	tuple<int, int, int> time1, time2;//hours,miutes,seconds

	if (time1 > time2)
		cout << " time1 is a later time";

	//Multi index map
	std::map<tuple<int, int, int>, string> timemap;

	timemap.insert(make_pair(make_tuple(12, 2, 3), "Game start"));
	cout << timemap[make_tuple(12, 2, 3)];



	return 0;
}

