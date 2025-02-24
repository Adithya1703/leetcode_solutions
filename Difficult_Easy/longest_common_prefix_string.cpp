/*Question: Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.*/

//CPP Solution - 
//Brute approach - TIme complexity - O(n*m^2) considering first string in array os strings as longest common prefix and dimmin it down till common prefix matches with all strings in array

//code - 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string LongestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string ans = strs[0];  // Assume the first string is the prefix

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(ans) != 0) {  // Check if 'ans' is a prefix
                ans = ans.substr(0, ans.size() - 1);  // Reduce the prefix
                if (ans.empty()) return "";  // If no common prefix, return ""
            }
        }
        return ans;
    }
};

//Another Solution: Using Trie Data structure class can decrease the time complexity to O(n*m)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Trie {
    class Node {
    public:
        bool end;
        Node* child[26];

        Node() {
            end = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;

public:
    // Constructor
    Trie() {
        root = new Node();
    }

    // Insert function
    void insert(const string& strs) {
        Node* current = root;
        for (char c : strs) {
            int index = c - 'a';
            if (!current->child[index]) {
                current->child[index] = new Node();
            }
            current = current->child[index];
        }
        current->end = true;
    }

    // Finding longest common prefix
    string longestCommPref() {
        string prefix;
        Node* current = root;

        while (current) {
            int childCount = 0;
            int index = -1;

            for (int i = 0; i < 26; i++) {
                if (current->child[i]) {
                    childCount++;
                    index = i;
                }
            }

            if (childCount != 1 || current->end) {
                break;  // Stop when more than one branch or end of a word is reached
            }

            current = current->child[index];
            prefix += ('a' + index);
        }
        return prefix;
    }
};


class Solution {
	public:
			string LongestCommonPrefix(vector<string>& strs) {
					if (strs.empty()) return "";
	
					Trie trie;
					for (const string& word : strs) {  // Use string instead of char
							trie.insert(word);
					}
					return trie.longestCommPref();
			}
	};




