#include <bits/stdc++.h>
using namespace std;

int main(){
    system("cls");
    int n;
    cin >> n;

    int pi, output;
    while (n--){
        cin >> pi;

        if(pi >= 1 && pi <= n){
            output++;
        }
    }
    
    cout << output;
}