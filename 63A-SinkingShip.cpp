#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    scanf("%d\n", &n);
    
    string line, shipCaptain;
    vector<string> rats, womenAndChildren, men;

    while(n--){
        getline(cin, line);
        int split = line.find(' ');
        string name  = line.substr(0, split);
        string title = line.substr(split + 1);

        if(title == "captain") shipCaptain = name;
        else if(title == "rat") rats.push_back(name);
        else if(title == "woman" || title == "child") womenAndChildren.push_back(name);
        else men.push_back(name);
    }

    for(const auto &r : rats) cout << r << endl;
    for(const auto &wc : womenAndChildren) cout << wc << endl;
    for(const auto &m : men) cout << m << endl;
    cout << shipCaptain << endl;

    return 0;
}
