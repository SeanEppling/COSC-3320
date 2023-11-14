#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include "avl.h"
using namespace std;

float average(vector<float> v){
    float temp = 0;
    for(int i = 0; i < v.size(); i++)
        temp += v[i];
    return temp / v.size();
}

int main(){
    ofstream out("results.txt");
    int max = 50;
    srand(time(0));
    int *num = new int[100000];
    for(int i = 0; i < 100000; i++)
        num[i] = rand() % 299 + 1;
    avl tree;
    vector<float> initial;
    vector<float> insertion;
    vector<float> deletion;
    float seconds;
    clock_t t, t2;
    for(int i = 0; i < 100000; i++){
        if(tree.count() > 50){
            t = clock();
            tree.remove(tree.min());
            t = clock()-t;
            seconds = float(timer)/CLOCKS_PER_SEC;
            deletion.push_back(seconds);

            t2 = clock();
            tree.insert(num[i]);
            t2 = clock-t2;
            seconds = float(t2)/CLOCKS_PER_SEC;
            insertion.push_back(seconds);
        }
        else{
            t = clock();
            tree.insert()num[i];
            t = clock-t;
            seconds = float(t)/CLOCKS_PER_SEC;
            initial.push_back(t);
        }
    }
    float avg_initial, avg_insertion, avg_deletion;
    avg_initial = average(initial);
    avg_insertion = average(insertion);
    avg_deletion = average(deletion);
    out << "average time for initial insertions (num nodes < 50): " << avg_initial << " seconds" << endl;
    out << "average time for insertions (num nodes > 50): " << avg_insertion << " seconds" << endl; 
    out << "average time for deletion (num nodes > 50): " << avg_deletion << " seconds" << endl;
    return 0; 
}