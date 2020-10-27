
#include<bits/stdc++.h>
using namespace std;

void max_sliding_window_naive(vector<int> const & A, int w) {

    

    deque<int> el;
    int n = A.size();

    for(int i = 0 ; i < w ; i++){
        while((!el.empty()) && A[i] >= A[el.back()]){
            el.pop_back();
        }
        el.push_back(i);
    }
    for(int i = w;i < n;i++){
        cout<<A[el.front()]<<" ";
        while((!el.empty()) && el.front() <= i - w){
            el.pop_front();
        }

        while((!el.empty()) && A[i] >= A[el.back()]){
            el.pop_back();
        }

        el.push_back(i);
    }
    cout<<A[el.front()]<<" "<<endl;
    // for (size_t i = 0; i < A.size() - w + 1; ++i) {
    //     int window_max = A.at(i);
    //     for (size_t j = i + 1; j < i + w; ++j)
    //         window_max = max(window_max, A.at(j));

    //     cout << window_max << " ";
    // }

    // return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
