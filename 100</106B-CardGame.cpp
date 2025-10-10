#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> laptop;
    for (int k = 0; k < n; k++) {
        laptop.push_back(vector<int>(4, 0));
        int speed, ram, hdd, cost;
        scanf("%d %d %d %d", &speed, &ram, &hdd, &cost);
        laptop[k][0] = speed;
        laptop[k][1] = ram;
        laptop[k][2] = hdd;
        laptop[k][3] = cost;
    }

    bool *candidate = new bool[n];
    for (int k = 0; k < n; k++) candidate[k] = true;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b) continue;
            if (laptop[a][0] < laptop[b][0] &&
                laptop[a][1] < laptop[b][1] &&
                laptop[a][2] < laptop[b][2] &&
                laptop[a][3] < laptop[b][3]) {
                candidate[a] = false;
                break;
            }
        }
    }

    int bestLaptop = -1, bestPrice = 1001;
    for (int k = 0; k < n; k++) {
        if (!candidate[k]) continue;
        if (laptop[k][3] < bestPrice) {
            bestPrice = laptop[k][3];
            bestLaptop = k;
        }
    }

    printf("%d\n", bestLaptop + 1);

    delete[] candidate;
    return 0;
}
