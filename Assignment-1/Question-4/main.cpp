#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

int main(){
    int n = 100;
    int A[n][n];
    int B[n][n];
    int C[n][n];
    fill(*A, *A + n*n, 1);
    fill(*B, *B + n*n, 1);
    chrono::time_point<chrono::system_clock> start, end;
    
    //itterating through the rows of the matrices
    start = chrono::system_clock::now();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "Row order took" << elapsed_seconds.count() << endl;

    //itterating through the coloums of the matrices
    start = chrono::system_clock::now();
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    end = chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Row order took" << elapsed_seconds.count() << endl;
}