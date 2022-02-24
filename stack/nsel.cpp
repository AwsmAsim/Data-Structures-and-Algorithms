#include <bits/stdc++.h>

using namespace std;

vector<int> nsel(vector<int>& arr){
    stack<int> s1;
    vector<int> answer;
    for(int i = 0; i < arr.size(); i++){
        while(s1.size()>0 && s1.top()>arr[i]){

            // cout << s1.top() ;
            s1.pop();
        }
        if(s1.size()>0 && arr[i] > s1.top()){
            answer.push_back(s1.top());
            // stack.pop();
        }
        if(s1.size()==0){
            answer.push_back(-1);
        }
            s1.push(arr[i]);
    }
    return answer;
}

vector<int> nsel_index(vector<int>& arr){
    stack<int> s1;
    vector<int> answer;
    for(int i = 0; i < arr.size(); i++){
        while(s1.size()>0 && arr[s1.top()]>arr[i]){

            // cout << s1.top() ;
            s1.pop();
        }
        if(s1.size()>0 && arr[i] > arr[s1.top()]){
            answer.push_back(s1.top());
            // stack.pop();
        }
        if(s1.size()==0){
            answer.push_back(-1);
        }
            s1.push(i);
    }
    return answer;
}

int main(){
    // vector<int> arr = {2, 3, 1, 4, 5};
    vector<int> arr = {1, 2, 3, 4 ,5};
    vector<int> answer = nsel(arr);
    answer = nsel_index(arr);
    for(auto a: answer){
        cout << a << " ";
    }
    return 0;
}