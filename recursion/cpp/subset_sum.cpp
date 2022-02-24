#include <bits/stdc++.h>

using namespace std;

vector<int> allSums;

void all_subset_sum(vector<int> arr, int idx, vector<int> curList, int sum1){

    // cout << idx << endl;
    if(idx >= arr.size()){
        allSums.push_back(sum1);
        return;
    }

    vector<int> list1 = curList, list2=curList;
    list1.push_back(arr[idx]);

    all_subset_sum(arr, idx + 1, list1, sum1 + arr[idx]);
    all_subset_sum(arr, idx + 1, list2, sum1);

}

int main(){

    vector<int> givenArr = {5, 2, 1};
    vector<int> curList = {};
    all_subset_sum(givenArr, 0, curList, 0);
    cout << "running" << '\n';
    cout << allSums.size() << endl;
    sort(allSums.begin(), allSums.end());
    for(auto a: allSums){
        cout << a << "   ";
    }

    return 0;
}