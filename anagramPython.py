def sortWord(word):
    w = sorted(word)
    sortedWord = "".join(w)
    return sortedWord
    
def loadWordlist(filename):
    file = open(filename)
    words = list()
    for line in file:
        if len(line) > 0:
            words.append(line.strip())
    return words

def anagram(word, wordlist):
    key = sortWord(word)
    anagrams = list()
    dic = dict()
    
    for i in wordlist:
        if len(i) == len(word):
            sorted = sortWord(i)
            if sorted == key:
                anagrams.append(i)
                dic[key] = anagrams
    return dic.get(key, anagrams) 

words = loadWordlist("wordlist.txt");
inputWord = input('Find single-word anagrams for the following word: ')
anagrams = anagram(inputWord, words);

for anagram in anagrams:
    print(anagram)