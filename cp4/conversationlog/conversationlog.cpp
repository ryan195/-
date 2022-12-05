#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numPpl;
    cin >> numPpl;
    string extra, line;
    unordered_map<string, int> count;
    unordered_map<string, unordered_set<string>> wordsSpoken;

    getline(cin, extra);
    for (int i = 0; i < numPpl; i++) {
        getline(cin, line);
        bool onlyName = false;
        string word = "", name = "";
        for (int j = 0; j < line.length(); j++) {
            char c = line[j];
            if (c == ' ') {
                line = line.substr(j + 1);
                break;
            } else {
                name.push_back(c);
            }
            if (j == line.length() - 1) {
                onlyName = true;
            }
        }
        if (onlyName) {
            continue;
        }
        for (int j = 0; j < line.length(); j++) {
            char c = line[j];
            if (c == ' ') {
                if (count.find(word) == count.end()) {
                    count.insert({word, 1});
                } else {
                    count[word] += 1;
                }
                if (wordsSpoken.find(name) == wordsSpoken.end()) {
                    wordsSpoken.insert({name, {word}});
                } else {
                    wordsSpoken[name].insert(word);
                }
                word = "";
            } else {
                word.push_back(c);
                if (j == line.length() - 1) {
                    if (count.find(word) == count.end()) {
                        count.insert({word, 1});
                    } else {
                        count[word] += 1;
                    }
                    if (wordsSpoken.find(name) == wordsSpoken.end()) {
                        wordsSpoken.insert({name, {word}});
                    } else {
                        wordsSpoken[name].insert(word);
                    }
                }
            }
        }
    }
    vector<pair<int, string>> vect;
    unordered_set<string> words = wordsSpoken.begin()->second;
    for (string word: words) {
        bool cantFind = false;
        for (auto it = wordsSpoken.begin(); it != wordsSpoken.end(); it++) {
            unordered_set<string> compareWords = it->second;
            if (compareWords.find(word) == compareWords.end()) {
                cantFind = true;
                break;
            }
        }
        if (!cantFind) {
            vect.push_back({count[word], word});
        }
    }
    if (vect.size() == 0) {
        cout << "ALL CLEAR" << endl;
    } else {
        sort(vect.begin(), vect.end(), [](auto lhs, auto rhs){
            if (lhs.first > rhs.first) {
                return true;
            } else if (lhs.first < rhs.first) {
                return false;
            } else {
                return (lhs.second < rhs.second);
            }
        });
        for (auto it = vect.begin(); it != vect.end(); it++) {
            cout << it->second << endl;
        }
    }
    return 0;
}