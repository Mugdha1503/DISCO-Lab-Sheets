#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addClosure(set<pair<int, int>>& closure, const set<pair<int, int>>& relation, int& numAdded) {
    bool added = false;
    for (const auto& r1 : relation) {
        for (const auto& r2 : relation) {
            if (r1.second == r2.first) {
                pair<int, int> newTuple = make_pair(r1.first, r2.second);
                if (closure.find(newTuple) == closure.end()) {
                    closure.insert(newTuple);
                    added = true;
                    ++numAdded;
                }
            }
        }
    }
    if (added) {
    cout<<numAdded << endl;
    for (const auto& tuple : closure) {
        if (relation.find(tuple) == relation.end()) {
            cout << tuple.first << " " << tuple.second << endl;
        }
    }
} else 
    cout << "0" << endl;
}
void findTransitiveClosure(int n, const vector<pair<int, int>>& tuples) {
    set<pair<int, int>> relation(tuples.begin(), tuples.end());
    set<pair<int, int>> closure(relation);
    int numAdded = 0;
    addClosure(closure, relation, numAdded);
}
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tuples;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        tuples.emplace_back(a, b);
    }
    findTransitiveClosure(n, tuples);
    return 0;
}

