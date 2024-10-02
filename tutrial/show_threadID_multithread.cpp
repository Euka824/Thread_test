#include <iostream>
#include <thread>

using namespace std;

void threadFunc() {
    cout << "subthread start" << endl;
    cout << "thread ID: " << this_thread::get_id() << endl;
    cout << "main fin" << endl;

    return;
}

//////////////////////////////////////////////////////////////////

int main() {
    // サブスレッド(thread1)を作成、処理としてthreadFuncを設定する
    thread thread1(threadFunc);

    // 素でプログラムを実行
    cout << "main start" << endl;
    cout << "thread ID: " << this_thread::get_id() << endl;
    cout << "main fin" << endl;

    // サブスレッドthread1の修了を待つ
    thread1.join();

    return 0;
}