
//This program implements a program that use recursion to solve the famous graph coloring problem


#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

const int NO_COLOR = -1;

class GCP {

private:
    int n; // the number of vertices in the graph
    int ** G; // the adjacency matrix for the graph
    int * the_colors;
    int k; // the number of available colors

    bool color_ok(int c, int m);

public:
    GCP();
    void read_graph(int c, char * filename);
    bool graph_color(int m);

};

GCP::GCP(){}

void GCP::read_graph(int c, char * filename) {

    k = c;

    ifstream ifs;
    ifs.open(filename);

    if (ifs.fail()) {
        cerr << "The file is missing..." << endl;
        exit(0);
    }

    ifs >> n;

    G = new (nothrow) int * [n];

    for (int i = 0; i < n; i++) {
        G[i] = new (nothrow) int [n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ifs >> G[i][j];
        }
    }

    the_colors = new (nothrow) int [n];

    for (int i = 0; i < n; i++) {
        the_colors[i] = NO_COLOR;
    }

}

bool GCP::graph_color(int m){

    bool r;

    if (m == n) {
        for (int i = 0; i < n; i++) {
            cout << i << " " << the_colors[i] << endl;
        }
        return true;
    }
    else {
        for (int c = 0; c < k; c++) {
            if (color_ok(c, m)) {
                the_colors[m] = c;
                r = graph_color(m + 1);
                if (r) {
                    return true;
                }
                the_colors[m] = NO_COLOR;
            }
        }
        return false;
    }
}

bool GCP::color_ok(int c, int m) {
    for (int i = 0; i < m; i++) {
        if (G[m][i] == 1) {
            if (the_colors[i] == c) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char * argv[]) {

    if (argc != 3) {
        cerr << "usage: " << argv[0] << " #colors filename" << endl;
        exit(3);
    }

    GCP gcp;
    bool b;

    gcp.read_graph(atoi(argv[1]), argv[2]);
    b = gcp.graph_color(0);

    if (!b) {
        cout << "No successful coloring with only " << argv[1] << " colors!" << endl;
    }

}
