#include <iostream>
#include <mutex> // exclusive control
#include <thread>

using namespace std;

mutex mtx_;
int cnt_;

void add_count() {
    // before increment, get mutex
    lock_guard<mutex> lock(mtx_);
    cnt_++;
}

void ThreadA() {
    for (int i = 0; i < 10000; i++) {
        add_count();
    }
}

// start main def

int main() {
    // グローバルで持っている変数の値を設定する
    cnt_ = 0;

    // make subthread and set ThreadA or ThreadB as process
    thread th_a(ThreadA);
    thread th_b(ThreadA);

    // サブスレッドthread1の修了を待つ
    th_a.join();
    th_b.join();

    cout << "counter: " << cnt_ << endl;

    return 0;
}