class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystacklength = haystack.length();
        int needlelength = needle.length();
        if(needle.empty()){
            return 0;
        }
        if(needlelength > haystacklength){
            return -1;
        }
        for(int sI = 0; sI <= haystacklength - needlelength;sI++){
            if(haystack.substr(sI,needlelength)==needle){
                return sI;
            }
        }
        return -1;
    }
};