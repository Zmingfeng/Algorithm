#include <unistd.h>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <iostream>
#include <thread>
#include <functional>
#include <assert.h>
using namespace std;
int main()
{
    thread t1([&] {
        while (true)
        {
            sleep(1000);
            cout << "runing1" << endl;
        }
    });

    thread t2([&] {
        while (true)
        {
            int a = 5 / 0;
            cout << "runing2" << endl;
        }
    });
    t1.join();
    t2.join();
    return 0;
}