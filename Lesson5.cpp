#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

template<class FindUnique>
FindUnique find_unique(FindUnique first, FindUnique last){
    set<string> uniquewords;
    int counter = 1;
    while (first != last) {
        auto result = uniquewords.insert(*first);
        if (!result.second) cout << *first << " is not unique" << "\n";
        else cout << counter++ << "." << *first << "\n";
        ++first;
    }
    return last;
}


int main(){
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

    set<string> sentences;
    string sentence;
    cout << "Enter 10 sentences in a row:";
    while (getline(cin, sentence, '.') || getline(cin, sentence, '?') || 
        getline(cin, sentence, '!') && sentences.size() < 10)  {
        sentences.insert(sentence);
    }
    return 0;
}

