#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int> students;
    for (int i = 1; i <= n; i++) {
        students.insert(i);
    }
cout << endl;
    for(int i = 1; i <= m; i++) {
        int o; cin >> o;
        students.erase(o);
        cout << *students.rbegin() << " " ;
    }
    cout << endl;

    return 0;
}
