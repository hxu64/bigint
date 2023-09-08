#include <iostream>
#include <string>

using namespace std;

int compare(string a, string b){
    // 0 if y > x
    // 1 if x > y
    // 2 if x = y
    if(a[0] == '-'){
        a = a.substr(1);
    }
    if(b[0] == '-'){
        b = b.substr(1);
    }
    int x = a.length();
    int y = b.length();
    if(x == y){
        for(int i=0;i<x;i++){
            if(a[i] != b[i]){
                return (a[i] > b[i]);
            }
        }
        return 2;
    }
    return (x > y);
}

string add(string a, string b)
{
    if(a[0] == '-'){
        a = a.substr(1);
    }
    if(b[0] == '-'){
        b = b.substr(1);
    }
    a = "0" + a;
    int x = a.length(), y = b.length();
    for(int i=1;i<=min(x, y);i++){
        a[x-i] += (b[y-i]-'0');
        if(a[x-i] > '9'){
            a[x-i] -= 10;
            a[x-i-1] += 1;
        }
    }
    if(a[x-y-1] > '0'){
        for(int i=x-y-1;i>=0;i--){
            if(a[i] > '9'){
                a[i] -= 10;
                a[i-1] += 1;
            }
        }
    }
    a.erase(0, a.find_first_not_of('0'));
    if(a == ""){
        return "0";
    }
    return a;
    // cout  << " = " << a << '\n';
    // cout << "a[y]: "<< a[x-y-1] << '\n';
}

string subtract(string a, string b)
{
    if(a[0] == '-'){
        a = a.substr(1);
    }
    if(b[0] == '-'){
        b = b.substr(1);
    }
    a = "0" + a;
    int x = a.length(), y = b.length();
    for(int i=1;i<=min(x, y);i++){
        a[x-i] -= (b[y-i]-'0');
        if(a[x-i] < '0'){
            a[x-i] += 10;
            a[x-i-1] -= 1;
        }
    }
    if(a[x-y-1] < '0'){
        for(int i=x-y-1;i>=0;i--){
            if(a[i] < '0'){
                a[i] += 10;
                a[i-1] -= 1;
            }
        }
    }
    a.erase(0, a.find_first_not_of('0'));
    if(a == ""){
        return "0";
    }
    return a;
}

string compute(string a, string b){
    if(a[0] == b[0] && a[0] == '-'){
        return '-' + add(a.substr(1), b.substr(1));
    }else if(a[0] != '-' && b[0] != '-'){
        return add(a, b);
    }else{
        int k = compare(a, b);
        // k = 0 if y > x
        // k = 1 if x > y
        // k = 2 if x = y
        if(k == 2){
            return "0";
        }
        if(k == 1){ // x > y
            if(a[0] == '-'){
                return '-' + subtract(a, b);
            }else{
                return subtract(a, b);
            }
        }else if(k == 0){ // x < y
            if(a[0] == '-'){
                return subtract(b, a);
            }else{
                return '-' + subtract(b, a);
            }
        }
    }
    return "0";
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string a, b, c;
    cin >> a >> b;
    if(a.length() < b.length()){
        cout << compute(b, a) << '\n';
    }else{
        cout << compute(a, b) << '\n';
    }

    return 0;
}
