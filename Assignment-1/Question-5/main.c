#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>

void alloc_1000kb(int** arr1, int size){
    
    for(int i = 0; i < size; i++){
        arr1[i] = (int*)malloc(1000000*sizeof(int));
    }
}

void free_memory(int** arr, int size){

    for(int i = 0; i < size; i = i+=2){
        free(arr[i]);
    }
}

void alloc_1250kb(int** arr2, int size){

    for(int i = 0; i < size; i++){
        arr2[i] = (int*)malloc(1250000*sizeof(int));
    }

}


int main(){
    int m = 46000;
    int size = 3*m;
    // 1 megabyte each
    int **arr1 = (int**)malloc(size*sizeof(int*));
    auto start_time1 = std::chrono::system_clock::now();
    alloc_1000kb(arr1, size);
    auto end_time1 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_time1 = end_time1 - start_time1;
    std::cout << "Elapsed time for 1000kb: " << elapsed_time1.count() << "\'s" << std::endl << std::endl;

    // Free arrays
    auto start_time2 = std::chrono::system_clock::now();
    free_memory(arr1, size);
    auto end_time2 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_time2 = end_time2 - start_time2;
    std::cout << "Elapsed time for freeing array: " << elapsed_time2.count() << "\'s" << std::endl << std::endl;

    // 1.25 megabyte each
    int **arr2 = (int**)malloc(size*sizeof(int*));
    auto start_time3 = std::chrono::system_clock::now();
    alloc_1250kb(arr2, m);
    auto end_time3 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_time3 = end_time3 - start_time3;
    std::cout << "Elapsed time for 1250kb: " << elapsed_time3.count() << "\'s" << std::endl << std::endl;
    

    exit(-1);
}