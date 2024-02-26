//============================================================================
// Name        : fallow-rain.cpp
// Author      : Sam T
// Version     :
// Copyright   : None
// Description : Mod 7 Portfolio Milestone CSC450
//============================================================================

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable> // Similar to a semaphore


using namespace std;

mutex mtx; // Mutex for critical section control
condition_variable cv; // Synchronization var
bool ready = false; // Control variable flag

void countUp() {
    for (int i = 1; i <= 20; ++i) {
        lock_guard<mutex> lock(mtx); // Release lock when out of scope

        cout << "Count Up: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100)); // Slow down the counting for visibility
    }
    ready = true; // Thread says I am done now
    cv.notify_one(); // Let the waiting thread know it has access
    cout << "Thread 1 is done, now " << endl;
}

void countDown() {
	unique_lock<mutex> lock(mtx);
	cv.wait(lock, []{return ready;}); // Listening for ready flag
	lock.unlock(); // Unlock to start countdown
	cout << "unlocking thread 2" << endl;
    for (int i = 20; i > 0; --i) {
        lock_guard<mutex> lg(mtx); // Re lock to do output
        cout << "Count Down: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    thread t1(countUp);
    thread t2(countDown);


    t1.join(); // Wait for the count up to finish
    t2.join();

    return 0;
}


