#include <iostream>
#include <thread>

using namespace std;

void threadFunc(string S) {
    cout << S << " start" << endl
     << "thread ID: " << this_thread::get_id() << endl
     << S << " fin" << endl;

    return;
}

//////////////////////////////////////////////////////////////////

int main() {
    // サブスレッド(thread1)を作成、処理としてthreadFuncを設定する
    thread thread1(threadFunc, "subthread1");

    // 素でプログラムを実行
    threadFunc("main");

    // サブスレッドthread1の修了を待つ
    thread1.join();

    return 0;
}