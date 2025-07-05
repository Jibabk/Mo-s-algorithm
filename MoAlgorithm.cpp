#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pll pair<ll, ll>


ll block_size; // Global variable for block size in Mo's algorithm
multiset<ll> numbers;
set<ll> unique_numbers;
vector<ll> arr;


bool cmp(pair<ll, ll> p, pair<ll, ll> q) {
    if (p.first / block_size != q.first / block_size)
        return p < q;
    return (p.first / block_size & 1) ? (p.second < q.second) : (p.second > q.second);
}
struct Query {
    ll l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

void remove(ll idx){
    numbers.erase(numbers.find(arr[idx]));
    if (numbers.find(arr[idx]) == numbers.end()) {
        unique_numbers.erase(arr[idx]);
    }
}; 

void add(ll idx){
    numbers.insert(arr[idx]);
    unique_numbers.insert(arr[idx]);
};   

ll get_answer(){
    return unique_numbers.size(); // Returns the number of unique elements in the current range
};

vector<ll> mo_s_algorithm(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());

    ll cur_l = 0;
    ll cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    ll size, quantQuerys;
    cin >> size;
    block_size = sqrt(size); // Size of each block for Mo's algorithm
    cin >> quantQuerys;
    vector<Query> arrQuerys;
    int idx = 0; // Index to keep track of the query number


    for(ll i = 0; i < size; i++){       //O(n)
        ll item;
        cin >> item;
        arr.push_back(item);
    }
    while(quantQuerys--){               // O(q)
        ll start, end;
        cin >> start >> end;
        Query q;
        q.l = start - 1; // Convert to 0-based index
        q.r = end - 1;   // Convert to 0-based index
        q.idx = idx; // Store the index of the query
        idx++;
        arrQuerys.push_back(q);
    }

    vector<ll> results = mo_s_algorithm(arrQuerys);         // O((n + q) * sqrt(n))


    for(ll i = 0; i < results.size(); i++){             // O(q)
        cout << results[i] << endl; // Output the result for each query
    }
return 0;
}