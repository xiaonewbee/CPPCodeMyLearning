#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
 
std::mutex g_display_mutex;
 
void foo()
{
    std::thread::id this_id = std::this_thread::get_id();
 
    g_display_mutex.lock();
    std::cout << "thread " << this_id << " sleeping...\n";
    g_display_mutex.unlock();
 
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
 
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::this_thread::yield();
    std::this_thread::yield();
 
    t1.join();
    t2.join();
}