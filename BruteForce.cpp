#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define ll long long

int main(){
    ll size, querys;
    cin >> size;
    cin >> querys;
    vector<ll> arr;
    for(ll i = 0; i < size; i++){
        ll item;
        cin >> item;
        arr.push_back(item);
    }
    while(querys--){
        ll start, end;
        cin >> start >> end;
        set<ll> uniqueElements;
        for (ll i = start - 1; i <= end - 1; i++){
            uniqueElements.insert(arr[i]);
        }
        cout << uniqueElements.size() << endl;
    }
}
