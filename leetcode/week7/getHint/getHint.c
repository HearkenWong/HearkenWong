class Solution {
public:
    string getHint(string secret, string guess) {   
        int n = secret.size(), a = 0, b = 0;
        int cnt[10] = {0};
        for(int i = 0; i < n; ++i){
            if(secret[i] != guess[i]){
                cnt[secret[i]-'0'] += 1;
                cnt[guess[i]-'0'] += 1<<16;
            }
            else a++;
        }
        for(int i = 0; i < 10; ++i)
            b += min(cnt[i]&0xffff, cnt[i]>>16);
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};
