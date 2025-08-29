// Normalizes three strings and checks if query permutation matches any concatenation ordering.
#include <bits/stdc++.h>
using namespace std;

string convert(string s){
    string output = "";
    for(int p = 0; p < s.size(); p++){
        if('a' <= s[p] && s[p] <= 'z') output += s[p];
        else if('A' <= s[p] && s[p] <= 'Z') output += (s[p] - 'A' + 'a');
    }
    return output;
}

int main(){
    string a; getline(cin, a); a = convert(a);
    string b; getline(cin, b); b = convert(b);
    string c; getline(cin, c); c = convert(c);

    int n; scanf("%d\n", &n);
    while(n--){
        string x; getline(cin, x); x = convert(x);
        if(x == a + b + c || x == a + c + b || x == b + a + c ||
           x == b + c + a || x == c + a + b || x == c + b + a){
            puts("ACC");
        } else {
            puts("WA");
        }
    }

    return 0;
}
