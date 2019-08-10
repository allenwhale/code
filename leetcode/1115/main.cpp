#include <bits/stdc++.h>
using namespace std;
class FooBar {
  private:
    int n;
    mutex f, b;

  public:
    FooBar(int n) {
        this->n = n;
        b.lock();
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {

            // printFoo() outputs "foo". Do not change or remove this line.
            f.lock();
            printFoo();
            b.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {

            // printBar() outputs "bar". Do not change or remove this line.
            b.lock();
            printBar();
            f.unlock();
        }
    }
};