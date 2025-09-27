#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Ham lap lai khoa theo so luong ky tu chu cai
string lapKhoa(const string &chuoi, const string &khoa) {
    string khoaLap;
    int j = 0;
    for (char c : chuoi) {
        if (isalpha(c)) {
            khoaLap += toupper(khoa[j % khoa.length()]);
            j++;
        } else {
            khoaLap += ' '; // giu vi tri cho ky tu dac biet
        }
    }
    return khoaLap;
}

// Ham ma hoa Vigenere
string maHoaVigenere(const string &chuoi, const string &khoa) {
    string ketQua = "";
    string khoaLap = lapKhoa(chuoi, khoa);

    for (int i = 0; i < chuoi.length(); i++) {
        char c = chuoi[i];
        char k = khoaLap[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char ma = (toupper(c) - 'A' + (k - 'A')) % 26 + base;
            ketQua += ma;
        } else {
            ketQua += c;
        }
    }
    return ketQua;
}

// Ham giai ma Vigenere
string giaiMaVigenere(const string &banMa, const string &khoa) {
    string ketQua = "";
    string khoaLap = lapKhoa(banMa, khoa);

    for (int i = 0; i < banMa.length(); i++) {
        char c = banMa[i];
        char k = khoaLap[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char goc = (toupper(c) - 'A' - (k - 'A') + 26) % 26 + base;
            ketQua += goc;
        } else {
            ketQua += c;
        }
    }
    return ketQua;
}

int main() {
    string chuoi, khoa;

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, chuoi);

    cout << "Nhap khoa Vigenere: ";
    getline(cin, khoa);

    string banMa = maHoaVigenere(chuoi, khoa);
    cout << "Ban ma: " << banMa << endl;

    string banGoc = giaiMaVigenere(banMa, khoa);
    cout << "Giai ma: " << banGoc << endl;

    return 0;
}