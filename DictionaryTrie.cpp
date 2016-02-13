#include "util.hpp"
#include "DictionaryTrie.hpp"
using namespace std;

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
	root = new TrieNode(false,0,0);
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */

bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
    TrieNode* curr = root;

    if (find(word)) {
        return false;
    }
    if (word.empty()) {
        return false;
    }
    for (unsigned int i=0; i < word.length(); i++) {
        int letter = (int)word[i]-(int)'a';
        if (curr->children[letter] == NULL) {
            if (letter == ' ') {
                letter = 26;
            }
            curr->children[letter] = new TrieNode(false,word[i],0);
            curr->text = word[i];
            //cout << curr->children[letter] << endl;
        }
        curr = curr->children[letter];
    }
    curr->isWord = true;
	return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
    TrieNode* curr = root;
    if (word.empty()) return false;

    for (unsigned int i=0; i<word.length(); i++) {
        int letter = (int)word[i]-(int)'a';
        if (word[i] == ' ') {
            letter = 26;
        }
        if ((curr->children[letter]) == NULL) {
            //cout << "the root is: " << curr->children[letter] << endl;
            return false;
        }
        if ((curr->children[letter]->isWord) && (i==word.length()-1)) {
            return true;
        }
        curr = curr->children[letter];
    }
    return false;
}

/* Return up to num_completions of the most frequent completions
 * of the prefix, such that the completions are words in the dictionary.
 * These completions should be listed from most frequent to least.
 * If there are fewer than num_completions legal completions, this
 * function returns a vector with as many completions as possible.
 * If no completions exist, then the function returns a vector of size 0.
 * The prefix itself might be included in the returned words if the prefix
 * is a word (and is among the num_completions most frequent completions
 * of the prefix)
 */
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){}