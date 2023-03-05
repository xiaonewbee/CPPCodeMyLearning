// first get a glance of STL
/*
unique_ptr.swap(unque_ptr&)
unique_ptr.get()
unique_ptr.release()
unique_ptr.reset()
unique_ptr.reset(unque_ptr&)
*/


template <typename T>
class Unique_ptr
{
public:
    Unique_ptr(const Unique_ptr&) = delete;
    Unique_ptr operator=(const Unique_ptr&) = delete;

    Unique_ptr operator=(const Unique_ptr&&) {
        
    }

public:
    Unique_ptr(T* ptr) : ptr(ptr) {}

    auto swap(Unique_ptr& other) {

    }



// getters
    auto get() const noexcept{
        return ptr;
    }
    T* operator->() const noexcept {
        return ptr;
    }
    T& operator*() const noexcept {
        return *ptr;
    }
// release

    T* release () {
        auto it = ptr;
        ptr = nullptr;
        return it;
    }
private:
    T *ptr;
};


// chatGPT Below code

template<typename T>
class my_unique_ptr {
public:
    // Constructors
    my_unique_ptr() noexcept : ptr(nullptr) {}
    explicit my_unique_ptr(T* ptr) noexcept : ptr(ptr) {}

    // Destructor
    ~my_unique_ptr() {
        delete ptr;
    }

    // Copy and move constructors and assignments
    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;

    my_unique_ptr(my_unique_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    my_unique_ptr& operator=(my_unique_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Getters
    T* get() const noexcept {
        return ptr;
    }

    T& operator*() const noexcept {
        return *ptr;
    }

    T* operator->() const noexcept {
        return ptr;
    }

    // Release ownership
    T* release() noexcept {
        T* result = ptr;
        ptr = nullptr;
        return result;
    }

    // Reset the pointer to a new value
    void reset(T* new_ptr = nullptr) noexcept {
        delete ptr;
        ptr = new_ptr;
    }

    // Swap two unique_ptr objects
    void swap(my_unique_ptr& other) noexcept {
        std::swap(ptr, other.ptr);
    }

private:
    T* ptr;
};

// chatGPT Below code
template<typename T>
class smart_ptr {
public:
    // Constructors
    smart_ptr() noexcept : ptr(nullptr), ref_count(nullptr) {}
    explicit smart_ptr(T* ptr) : ptr(ptr), ref_count(new size_t(1)) {}

    // Copy constructor
    smart_ptr(const smart_ptr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        if (ref_count) {
            ++(*ref_count);
        }
    }

    // Destructor
    ~smart_ptr() {
        if (ref_count && --(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

    // Copy assignment operator
    smart_ptr& operator=(const smart_ptr& other) {
        if (this != &other) {
            if (ref_count && --(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ref_count) {
                ++(*ref_count);
            }
        }
        return *this;
    }

    // Getters
    T* get() const noexcept {
        return ptr;
    }

    T& operator*() const noexcept {
        return *ptr;
    }

    T* operator->() const noexcept {
        return ptr;
    }

private:
    T* ptr;
    size_t* ref_count;
};
