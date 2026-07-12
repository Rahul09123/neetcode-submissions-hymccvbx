#include<bits/stdc++.h>
class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for(string& str : strs){
            encoded += to_string(str.size());
            encoded += '#';
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string>ans;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i,j-i));// extracting the length
            string str = s.substr(j+1,len);
            ans.push_back(str);
            i = j + 1 + len;

        }
        return ans;
    }
};
