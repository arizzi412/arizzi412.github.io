
//This program gives a table of the number of people (2 to 50) and the estimated probability that a group of that size has at least two people with the same birthday

#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXPEOPLE = 50;


// Declaration of class birth
class simulate {
private:
    int people[MAXPEOPLE];
    int N;
    double probs[MAXPEOPLE];

    int get_birthday();
    bool one_group(int n);
    double one_estimate(int n, int m);

public:
    simulate();
    void est_probs();
    void show_probs();
};

simulate::simulate() {
    N = MAXPEOPLE;

    int i;
    for (int i = 0; i < MAXPEOPLE; i++) {
        people[i] = i + 1;
        probs[i] = 0;
    }

}


int simulate::get_birthday() {
    int r;
    r = rand() % 1461;

    // r is 0 to 1460
    if (r == 1460) return 365;
    else return r % 365;
}

bool simulate::one_group(int n) {
    int g[n];
    int i, j;

    for (i = 0; i < n; i++) {
        g[i] = get_birthday();
    }

    for (i = 0; i < (n-1); i++) {
        for (j = (i+1); j < n; j++) {
            if (g[i] == g[j]) return true;
        }
    }
    return false;
}

double simulate::one_estimate(int n, int m) {
    int i, j;
    int c = 0;

    for (i = 0; i < m; i++) {
        if (one_group(n)) c = c + 1;
    }

    return 1.0 * c / m;

}

void simulate::est_probs() {
    int i = 0;
    for (i = 1; i < MAXPEOPLE; i++) {
        probs[i] = one_estimate(i + 1, 100000);
    }
}

void simulate::show_probs() {
    int i;
    for (i = 1; i < MAXPEOPLE; i++) {
        cout << i + 1 << " " << probs[i] << endl;
    }
}

int main() {
    simulate B;

    B.est_probs();
    B.show_probs();
}
