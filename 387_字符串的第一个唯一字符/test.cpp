#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 - 1

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = { 0 };
        //哈希映射方式计数
        //计数完成后再次遍历数组找到相对位置
        for (auto e : s) {
            count[e - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};