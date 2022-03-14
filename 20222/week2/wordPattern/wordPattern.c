class Solution {
public:
    //获取字符串的子串
    string getsubstr(string s, int start){
        string res ; 
        res+=s[start]; //保存第一个字符
        int j = start+1;
        //从start位置找到第一个单词
        while(j<s.size()&&s[j]!=' '){
            res+=s[j++];
        }
        return res;
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> map1;
        unordered_map<char, string> map2;
        int i=0;
        int j=0;
        //遍历二者，构建映射关系
        for(;i<pattern.size()&&j<s.size();){
            //先将s中的单词取出
            string word = getsubstr(s, j);

            //构建单词->字符的映射
            if(map1.find(word)==map1.end()){
                map1[word] = pattern[i];
            }
            //构建字符->单词的映射
            if(map2.find(pattern[i])==map2.end()){
                map2[pattern[i]] = word;
            }
            //比较二者是否一一对应
            if(map1[word]!=pattern[i] || map2[pattern[i]]!=word){
                return false;
            }
            j+=word.size()+1; //更新j的位置，size+1是为了跳过空格
            i++;
        }
        //判断两者是否同时遍历完成(j多加了1)
        if(i==pattern.size()&&j==s.size()+1) return true;
        else return false; //说明长度对不上
    }
};
