class Parent {
public:
    Parent(int a, int b) {
        x = a;
        y = b;
    }
protected:
    int x;
    int y;
};

class Child : public Parent {
public:
    using Parent::Parent;  // 继承父类的构造函数
private:
    int z;
};

int main() {
    Child obj(1, 2);
    return 0;
}
