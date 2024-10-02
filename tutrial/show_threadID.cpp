#include <iostream>
#include <thread>

using namespace std;

int main() {
    cout << "main start" << endl;
    cout << "thread ID: " << this_thread::get_id() << endl;
    cout << "main fin" << endl;

    return 0;
}