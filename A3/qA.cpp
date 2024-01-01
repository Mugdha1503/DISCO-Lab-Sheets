#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isReflexive(const vector<pair<int, int>>& relation) {
    unordered_set<int> elements;
    for (const auto& tuple : relation) {
        elements.insert(tuple.first);
        elements.insert(tuple.second);
    }
    for (const auto& element : elements) {
        bool found = false;
        for (const auto& tuple : relation) {
            if (tuple.first == element && tuple.second == element) {
                found = true;
                break;
        }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}
bool isSymmetric(const vector<pair<int, int>>& relation) {
    for (const auto& tuple : relation) {
        bool found = false;
        for (const auto& other : relation) {
            if (tuple.first == other.second && tuple.second == other.first) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}
bool isTransitive(const vector<pair<int, int>>& relation) {
    for (const auto& a : relation) {
        for (const auto& b : relation) {
            if (a.second == b.first) {
                bool found = false;
                for (const auto& c : relation) {
                    if (a.first == c.first && b.second == c.second) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    return false;
                }
            }
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> relation;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        relation.emplace_back(a, b);
    }
    bool reflexive = isReflexive(relation);
    bool symmetric = isSymmetric(relation);
    bool transitive = isTransitive(relation);
    cout << (reflexive ? "YES" : "NO")<<" " ;
    cout << (symmetric ? "YES" : "NO") << " ";
    cout << (transitive ? "YES" : "NO");
    return 0;
}






