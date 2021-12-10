#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <iterator>
#include <map>

using namespace std;

template<class FindUnique>
FindUnique find_unique(FindUnique first, FindUnique last) {
    set<string> uniquewords;
    int counter = 1;
    while (first != last) {
        auto result = uniquewords.insert(*first);
        if (!result.second) cout << *first << " is not unique" << "\n";
        else cout << counter++ << "." << *first << "\n";
        next(first);
    }
    return last;
}


int main() {
    ifstream file("d:\\SomeText.txt");
    vector<string> words;
    string word;
    while (!file.eof())
        file >> word;
    words.push_back(word);
    file.close();
    for (int i = 0; i < words.size(); i++) {
        cout << words[i];
    }
    find_unique(words.begin(), words.end());

    map<int, string> sentences;
    string sentence;
    int slovo, count = 0;
    cout << "Enter 10 sentences in a row:";
    cin >> sentence;
    
    while (getline(cin, sentence, '.') || getline(cin, sentence, '?') ||
        getline(cin, sentence, '!') && sentences.size() < 10) {
        int i = 0;
        while (sentence[i] == ' ' && sentence[i] != '\0')
            i++;
        slovo = 0;
        while (sentence[i] != '\0') {
            if (sentence[i] != ' ' && slovo == 0)
            {
                slovo = 1;
                count++;
            }
            else if (sentence[i] == ' ')
                slovo = 0;
            i++;
        }
        sentences.insert({ count, sentence });
    }
    return 0;
}