#include <iostream>
#include <thread>

using namespace std;

int end_flag_;
int msg_;

void ThreadA() {
    int input = 0;
    while (end_flag_) {
        cout << "Please input a number" << endl;
        cout << "0...Send a message to thread B" << endl;
        cout << "1...Finish process" << endl;
        cin >> input;

        switch (input) {
        case 0:
            msg_ = 1;
            break;
        case 1:
            end_flag_ = 0;
            break;
        default:
            cout << "input 0 or 1" << endl;
            break;
        }
    }
    cout << "Finish thread A" << endl;
}

void ThreadB() {
    while (end_flag_) {
        if (msg_) {
            cout << "Got a massage from thread A" << endl;
            msg_ = 0;
        }
    }
    cout << "Finish thread B" << endl;
}

//////////////////////////////////////////////////////////////////

int main() {
    // グローバルで持っている変数の値を設定する
    msg_ = 0;
    end_flag_ = 1;

    // make subthread and set ThreadA or ThreadB as process
    thread th_a(ThreadA);
    thread th_b(ThreadB);

    // サブスレッドthread1の修了を待つ
    th_a.join();
    th_b.join();

    return 0;
}