#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<cstring>
#include<chrono>
#include<algorithm>
using namespace std;


void countWordsUsingMap(const vector<string>& words)
{
    map<string,int>wordCount;
    for(const auto& word:words)
    {
        ++wordCount[word];
    }

    std::ofstream outfile("dirmap.txt");
    for (const auto& entry : wordCount) {
        outfile << entry.first << " " << entry.second << "\n";
    }
}

void countWordsUsingVector(const vector<string>& words)
{
    vector<pair<string,int>>wordCount;
    for(const auto&word:words)
    {
        auto it=find_if(wordCount.begin(),wordCount.end(),
                        [&word](const pair<string,int>&element){return element.first==word;});
        if(it!=wordCount.end())
        {
            ++it->second;
        }
        else
        {
            wordCount.emplace_back(word,1);
        }
    }

     std::ofstream outfile("dirvector.txt");
    for (const auto& entry : wordCount) {
        outfile << entry.first << " " << entry.second << "\n";
    }
}

int main(){
    ifstream file("The_Holy_Bible.txt");
    stringstream buffer;
    buffer<<file.rdbuf();
    string text=buffer.str();

    istringstream iss(text);
    vector<string>words;
    string word;
    while(iss>>word)
    {
        words.push_back(word);
    }

    auto start=chrono::high_resolution_clock::now();
    countWordsUsingMap(words);
    auto end=chrono::high_resolution_clock::now();
    chrono::duration<double>mapDuration=end-start;
    cout<<"Using map took:"<<mapDuration.count()<<"seconds.\n";

    start=chrono::high_resolution_clock::now();
    countWordsUsingVector(words);
    end=chrono::high_resolution_clock::now();
    chrono::duration<double>vectorDuration=end-start;
    cout<<"Using vector took:"<<vectorDuration.count()<<"seconds.\n";

    return 0;
}
