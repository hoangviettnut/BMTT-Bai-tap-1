#include<iostream>
#include<string>
using namespace std;

string encode(string s, int k){
    string cipher;
    int n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            char new_char = ((s[i] - 'A') + k) % 26 + 'A';
            cipher += new_char;
        } else if(s[i] >= 'a' && s[i] <= 'z'){
            char new_char = ((s[i] - 'a') + k) % 26 + 'a';
            cipher += new_char;
        } else {
            cipher += s[i];
        }
    }
    return cipher;
}

string decode(string s, int k){
    string plain;
    int n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            char new_char = ((s[i] - 'A') - k + 26) % 26 + 'A';
            plain += new_char;
        } else if(s[i] >= 'a' && s[i] <= 'z'){
            char new_char = ((s[i] - 'a') - k + 26) % 26 + 'a';
            plain += new_char;
        } else {
            plain += s[i];
        }
    }
    return plain;
}

int main(){
    int k;
    string s;
    cout << "Nhap k (k > 1): "; cin >> k;
    cin.ignore();
    cout << "Nhap xau s: "; getline(cin, s);

    string cipher = encode(s, k);
    cout << "Chuoi sau khi duoc ma hoa la: " << cipher << endl;

    string plain = decode(cipher, k);
    cout << "Chuoi sau khi giai ma la: " << plain << endl;

    return 0;
}