// Decodes Borze code: . -> 0, -. -> 1, -- -> 2.
#include <bits/stdc++.h>

using namespace std;
int main() {
    string input; 
    getline(cin, input);
    size_t index = 0;
    while (index < input.size()) {
        if (input[index] == '.') {
            printf("0");
        } 
        else if (input[index] == '-' && input[index + 1] == '.') {
            printf("1");
            ++index;
        } 
        else if (input[index] == '-' && input[index + 1] == '-') {
            printf("2");
            ++index;
        }
        ++index;
    }
    return 0;
}
// or in python if needed
/*
# Decodes Borze code: . -> 0, -. -> 1, -- -> 2

input_str = input()
index = 0
output = []

while index < len(input_str):
    if input_str[index] == '.':
        output.append('0')
    elif input_str[index] == '-' and input_str[index + 1] == '.':
        output.append('1')
        index += 1
    elif input_str[index] == '-' and input_str[index + 1] == '-':
        output.append('2')
        index += 1
    index += 1

print(''.join(output))

*/
