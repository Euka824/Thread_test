#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void threadFunc(int maxnum, int &ret) {
    for (int i = 0; i < maxnum; i++) {
        ret++;
    }
    return;
}

//////////////////////////////////////////////////////////////////

int main() {
    int ansnum = 10;
    vector<int> rets(ansnum, 0);
    vector<thread> ths(ansnum);
    // サブスレッド(thread1)を作成、処理としてthreadFuncを設定する
    for (int i = 0; i < ansnum; i++) {
        ths[i] = thread(threadFunc, 100 + i, ref(rets[i]));
    }
    // サブスレッドthread1の終了を待つ
    for (int i = 0; i < ansnum; i++) {
        ths[i].join();
    }
    for (int i = 0; i < ansnum; i++) {
        cout << i << ": " << rets[i] << endl;
    }

    return 0;
}