#include <iostream>
#include <random>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
struct ress {
  public:
    unsigned int random_fromDevice() { return SEED(); }
    pair<unsigned int, unsigned int> random2_fromDevice() {
        return {SEED(), SEED()};
    }

    unsigned int random_mt() {
        mt19937 ret(SEED());
        return ret();
    }

    void random_float() {
        mt19937 gen(SEED());
        uniform_real_distribution<float> dist(0, 1);
        rep(i, 5) { cout << i << ": " << dist(gen) << endl; }
        return;
    }

  private:
    random_device SEED;
};
/* main func */
int main() {
    random_device rd;
    ress structure1;
    rep(i, 5) { cout << i << ": " << structure1.random_fromDevice() << endl; }
    rep(i, 5) {
        auto p = structure1.random2_fromDevice();
        cout << i << ": " << p.first << ", " << p.second << endl;
    }
    rep(i, 5) { cout << i << ": " << structure1.random_mt() << endl; }
    structure1.random_float();

    return 0;
}