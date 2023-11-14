#include <iostream>
#include <unordered_map>
using namespace std;

bool isEqual(int l1[], int l2[], int n, int m){
    if(n!=m){
        return false;
    }

    unordered_map<int,int> map;
    for(int i -0;i<n;i++)
        map[l1[i]]++;

    for(int i = 0;i<n;i++){
        if(map.find(l2[i]) == map.end())
            return false;
        if(map[l2[i]] == 0)
            return false;
        map[l2[i]]--;
    }

    return true;
}

int main(){
    int l1[] = {1,2,3,4,5,6};
    int l2[] = {3,6,2,4,1,5};
    int n = l1.size();
    int m = l2.size();
    if(isEqual(l1,l2,n,m))
        cout << "l1 and l2 are equal";
    else
        cout << "l1 and l2 are not equal";
    return 0;
}
