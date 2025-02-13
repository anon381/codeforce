#include <bits/stdc++.h>

using namespace std;

int main(){

    string input; getline(cin, input);
    string output("");

    for(int k = 0; k < input.size(); k++){
        if(output.empty() || output.back() != input[k]){output += input[k];}
        else{output.pop_back();}
    }

    cout << output << endl;
    return 0;
}