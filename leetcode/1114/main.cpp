#include <bits/stdc++.h>
using namespace std;
class Foo {
  public:
    mutex m1, m2;
    Foo() {
        m1.lock();
        m2.lock();
    }

    void first(function<void()> printFirst) {
        printFirst();
        m1.unlock();
    }

    void second(function<void()> printSecond) {
        m1.lock();
        printSecond();
        m1.unlock();
        m2.unlock();
    }

    void third(function<void()> printThird) {
        m2.lock();
        printThird();
        m2.unlock();
    }
};
int main() {
    atomic<int> c(0);
    int ex = 0;
    printf("%d\n", c.compare_exchange_weak(ex, 1));
    printf("%d\n", c.load());
    return 0; //
}