#include <iostream>
#include <thread> // for std::shared_ptr
#include <mutex>
#include <pthread.h>
using namespace std;

int myAmount = 0;

void addMoney () {
	++myAmount;
}
void subMoney () {
	myAmount-=4;
}
void mulMoney () {
	myAmount = myAmount*2;
}
int main()
{
	thread t1(addMoney);
	thread t2(subMoney);
	thread t3(mulMoney);
	t1.join();
	t2.join();
	t3.join();
	cout << myAmount << endl;
 
	return 0;
}