#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();


const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int appendCharacters(string s, string t) {
        int slen = s.size(),tlen = t.size();
        int i=0,j=0;

        while(i<slen && j<tlen){
            if(s[i] == t[j]){
                j++;
            }
            i++;
        }
        return tlen - j;
    }
};