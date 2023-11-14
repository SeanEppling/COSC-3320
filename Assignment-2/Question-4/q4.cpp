#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main(){
    ofstream outfs(results.txt)
    int n[6] = {16,64,256,1024,4096,16384};
    int iter = 0;
    outfs << "m = 13421772800" << endl;
    while(iter < 6){
        int a,b,x;
        int** M = new int* [n[iter]];
        for(int i = 0; i < n[iter]; i++){
            M[i] = new int[n[iter]];
        }

        for(int i = 0; i < n[iter]; i++){
            for(int j = 0; j < n[iter]; j++){
                M[i][j] = 2;
            }
        }

        size_t m = 13421772800;
        clock_t t;
        t = clock();

        for(int i = 0; i < m; i++){
            x = rand() % 100 + 1;
            a = rand() % n[iter];
            b = rand() % n[iter];
            M[a][b] = M[a][b] + x
        }
        t = clock() - t;
        outfs << "n = " << n[iter] << " takes"
              << float(t) / CLOCKS_PER_SEC << " seconds" << endl;
        iter++;
    }
    return 0;
}