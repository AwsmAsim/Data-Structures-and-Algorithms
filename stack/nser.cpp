#include <bits/stdc++.h>

using namespace std;

vector<int> nser(vector<int>& arr){
    stack<int> s1;
    vector<int> answer;
    for(int i = arr.size()-1; i>=0; i--){
        while(s1.size()>0 && s1.top()>arr[i]){
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
    for(int i = 0; i < answer.size()/2; i++){
        answer[i] = answer[answer.size()-1-i];
    }

    return answer;
}

vector<int> nser_index(vector<int>& arr){
    stack<int> s1;
    vector<int> answer;
    for(int i = arr.size()-1; i>=0; i--){
        while(s1.size()>0 && arr[s1.top()]>=arr[i]){
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
    for(int i = 0; i < answer.size()/2; i++){
        answer[i] = answer[answer.size()-1-i];
    }

    return answer;
}

int main(){
    // vector<int> arr = {2, 3, 1, 4, 5};
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> answer = nser(arr);
    answer = nser_index(arr);
    for(auto a: answer){
        cout << a << " ";
    }
    return 0;
}

