#include <iostream>

#define MAX_N 250001
#define MAX 65536

using namespace std;
typedef long long ll;

ll segment_tree[4*MAX_N], arr[MAX_N], n, k, sum;


//  if range is excluded return
//  if x=y that is the location of pos so, + val(1)
ll update_tree(ll pos, ll val, ll node, ll x, ll y) {
    if (y < pos || x > pos) {
        return segment_tree[node];
    }
    if (x == y) {
        segment_tree[node] += val;
        return segment_tree[node];
    }
    ll mid = (x + y) / 2;
    segment_tree[node] = update_tree(pos, val, node*2, x, mid) + update_tree(pos, val, node*2 + 1, mid+1, y);
    return segment_tree[node];
}

//  pos is location node, x is start range, y is end range, segment_tree[node] represent sum of [x,y]
//  if pos  is smaller then segment_tree element, pos would be in the left child. [x, mid]
//  else pos will be in the right chile [mid + 1, y]
ll get_middle(ll pos, ll node, ll x, ll y) {
    ll mid = (x + y) / 2;
    if (x == y) return x;
    if (segment_tree[node*2] >= pos) return get_middle(pos, node*2, x, mid);
    return get_middle(pos - segment_tree[node*2], node*2+1, mid+1, y);
}

int main() {
    cin >> n >> k; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < k-1; i++) {
        update_tree(arr[i], 1, 1, 0, MAX-1);
    }
    
    for (int i = k-1; i < n; i++) {
        update_tree(arr[i], 1, 1, 0, MAX-1);
        sum += get_middle((k+1)/2, 1, 0, MAX-1);
        update_tree(arr[i-k+1], -1, 1, 0, MAX-1);
    }

    cout << sum << endl;
    
    return 0;
}
