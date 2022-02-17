#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int mails = 0;
std::mutex m;
void routine() {
    for (int i = 0; i < 1000000; i++) {
        //m.lock(); // lock mutex
        // code between lock() and unlock() called critical section
        mails++;
        // read mails
        // increment
        // write mails
        //m.unlock(); // unlock mutex
    }
}

int main() {
    std::thread p1(routine);
    std::thread p2(routine);
    std::thread p3(routine);
    std::thread p4(routine);
    p1.join();
    p2.join();
    p3.join();
    p4.join();
    cout << "Number of mails: " << mails <<endl;
    return 0;
}