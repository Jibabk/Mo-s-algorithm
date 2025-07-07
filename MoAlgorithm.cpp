#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int block_size;
vector<int> arr;       // array comprimido
vector<int> freq;      // frequência dos valores comprimidos
int unique_count = 0;
 
struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};
 
 
 
void add(int idx) {
    if (++freq[arr[idx]] == 1)
        unique_count++;
}
 
void remove(int idx) {
    if (--freq[arr[idx]] == 0)
        unique_count--;
}
 
vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
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
        answers[q.idx] = unique_count;
    }
    return answers;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
    block_size = sqrt(n);
 
    // Leitura do array original
    vector<int> original(n);
    for (int i = 0; i < n; i++)
        cin >> original[i];
 
    // Inicio da Compressão de coordenadas
    vector<int> temp = original;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    arr.resize(n);
    for (int i = 0; i < n; i++)
        arr[i] = lower_bound(temp.begin(), temp.end(), original[i]) - temp.begin();
 
    int max_val = temp.size();
    freq.resize(max_val, 0);
    // fim da compressão de coordenadas

    // Leitura das queries
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a - 1, b - 1, i};
    }
 
    
    vector<int> result = mo_s_algorithm(queries);
    for (int res : result)
        cout << res << '\n';
 
    return 0;
}