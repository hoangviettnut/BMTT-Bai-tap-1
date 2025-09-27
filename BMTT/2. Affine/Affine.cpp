#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int m = 26; // Số ký tự trong bảng chữ cái tiếng Anh

// Tìm nghịch đảo modulo của a
int modInverse(int a, int m) {
    for (int i = 0; i < m; i++) {
        if ((a * i) % m == 1)
            return i;
    }
    return -1; // Không tồn tại nghịch đảo
}

// Mã hóa văn bản
string affineEncrypt(string text, int a, int b) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char upper = toupper(c);
            int x = upper - 'A';
            int y = (a * x + b) % m;
            result += char(y + 'A');
        } else {
            result += c;
        }
    }
    return result;
}

// Giải mã văn bản
string affineDecrypt(string cipher, int a, int b) {
    string result = "";
    int a_inv = modInverse(a, m);
    if (a_inv == -1) {
        return "Khong the giai ma. a khong co nghich dao modulo.";
    }

    for (char c : cipher) {
        if (isalpha(c)) {
            char upper = toupper(c);
            int y = upper - 'A';
            int x = (a_inv * (y - b + m)) % m;
            result += char(x + 'A');
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    int a, b;

    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhao khoa a (nguyen to cung 26): ";
    cin >> a;
    cout << "Nhap khoa b: ";
    cin >> b;

    string encrypted = affineEncrypt(text, a, b);
    cout << "Van ban ma hoa: " << encrypted << endl;

    string decrypted = affineDecrypt(encrypted, a, b);
    cout << "Van ban giai ma: " << decrypted << endl;

    return 0;
}