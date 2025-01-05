class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLength = haystack.length();
    int needleLength = needle.length();
        if (needleLength > haystackLength) {
        return -1;
    }

    for (int i = 0; i <= haystackLength - needleLength; i++) {
        if (haystack.substr(i, needleLength) == needle) {
            return i; 
        }
    }
    return -1;
}
        
    
};