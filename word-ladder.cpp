/*
Task : 
1. Transform one word(startWord) into another(endWord) by changing only one letter at a time — and every word you create must be a real word from a list (wordList). (hit → hot → dot → dog → cog)
2. Give the shortest possible sequence from beginWord to endWord.

        hit
         |
        hot
       /   \
     dot   lot
     |      |
    dog    log
       \   /
        cog


Logic :
S0. Its a graph(for this problem, undirected graph, why-> hot<->do) problem how I come to that-->(reason :  idea of words being connected when 1 letter changes is exactly like how nodes in a graph are connected by edges. So, Words = Nodes, One-letter change = Edges) --> (When a problem talks about connections between things, and you need to find the shortest path between them — that’s a big clue that it’s a graph problem.)
S1. Treat each word as a point and connect two words if they differ by exactly one letter — this forms a graph, and we use BFS to find the shortest path from the start word to the end word.

*/


#include<bits/stdc++.h>
using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // BFS
        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            
            if (word == endWord) return steps;

            
            for (int i = 0; i < word.length(); ++i) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;

                    if (temp == word) continue; 
                    if (wordSet.find(temp) != wordSet.end()) { 
                        q.push({temp, steps + 1});
                        wordSet.erase(temp); 
                    }
                }
            }
        }
  
        return 0;
}

int main() {
 
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit";
    string endWord = "cog";

    int result = ladderLength(beginWord, endWord, wordList);
    cout << "Shortest transformation sequence length: " << result << endl;

    return 0;
}
