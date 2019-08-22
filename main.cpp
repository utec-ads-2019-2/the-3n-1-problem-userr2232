#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int three_n_plus_one(int n, int cycle_length = 1) {
    if(n == 1) return cycle_length;
    if(n%2) n = 3*n+1;
    else n /= 2;
    return three_n_plus_one(n, ++cycle_length);
}

int main() {
    int i, j;
    string line;
    while(getline(cin, line)) {
        istringstream iss(line);
        iss >> i >> j;
        int max_cycle_length = 1;
        for(int k = min(i,j); k <= max(i,j); ++k)
            max_cycle_length = max(three_n_plus_one(k), max_cycle_length);
        cout << i << " " << j << " " << max_cycle_length << endl;
    }
    return 0;
}