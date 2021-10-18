/*
 * Name: Lucas Boyer
 * Date Submitted: 10-17-21
 * Assignment Name: Single Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm> //added for sort function

using namespace std;

string sortString(string s); //takes input string and sorts it and returns it
vector<string> loadWordlist(string filename);
vector<string> anagram(string word, vector<string> wordlist);

string sortString(string s) { //sorts string
    sort(s.begin(), s.end());
    return s;
}

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    //changed to get rid of error
    for (long unsigned int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

/*
  takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map. The key is input word sorted b/c an anagram
  would have the exact same sorted string
  and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist)
{
    //sorts word and uses it as a key
    string key = sortString(word);
    //makes dictionary for key and all anagram for the key
    unordered_map<string, vector<string>> allAnagrams;
    string sortedWord;
    //goes through wordlist only considers same length words
    for (auto i: wordlist) {
        if (i.length() == word.length()) {
            //sorts potential anagram
            sortedWord = sortString(i);
            //compares to key and if a match add to list of anagram
            if (sortedWord == key) {
                allAnagrams[key].push_back(i);
            }
        }
    }
    //return all anagrams
    return allAnagrams[key];
}