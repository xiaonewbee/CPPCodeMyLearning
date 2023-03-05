#include <iostream>
#include <thread>
#include <mutex>

// std::recursive_mutex mtx;
std::mutex mx;
void foo(int i) {
    // std::unique_lock<std::recursive_mutex> lock(mtx);
	std::lock_guard<std::mutex> lock(mx); 
    std::cout << "foo " << i << std::endl;
    if (i > 0) {
		
        foo(i - 1);
    }
}

int main() {
    std::thread t2(foo, 2);
    std::thread t1(foo, 3);

    t1.join();
    t2.join();
    return 0;
}
