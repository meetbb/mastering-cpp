#include <vector>
#include <string>
#include "ValidAnagram.h"

bool ValidAnagram::isAnagram(string s, string t) {
    // Edge case: if the size of both strings are different.
    if (s.size() != t.size())
    {
        return false;
    }
    
    // Create an array of size 26 for each character.
    // Increment the character count if found at index.
    // Decrement the count if found in t as well.
    int freq[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }        
    }
    return true;
}