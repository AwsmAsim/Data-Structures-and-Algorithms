#include <bits/stdc++.h>

using namespace std;
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
            answer.push_back(arr.size());
        }
            s1.push(i);
    }
    for(int i = 0; i < answer.size()/2; i++){
        answer[i] = answer[answer.size()-1-i];
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
    vector<int> arr = {1, 2, 3, 4, 5};
    arr = {8979, 4570, 6436, 5083, 7780, 3269, 5400, 7579, 2324, 2116};
    vector<int> nsel = nsel_index(arr);
    vector<int> nser = nser_index(arr);
    int ans = INT_MIN;
    for(auto a: nsel){
        cout << a << " ";
    }
    cout << "\n";
    for(auto a: nser){
        cout << a << " ";
    }
    for(int i = 0; i < arr.size(); ++i){
        
        ans = max(ans, (nser[i] - nsel[i] - 1)*arr[i]);
        cout << "Ans" << ans << endl;
    }
    cout << "\n";
    cout << ans << endl;
    return ans;
}