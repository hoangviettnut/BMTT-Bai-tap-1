#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char matrix[5][5];

// Tao bang Playfair tu khoa
void taoBang(string khoa) {
    string bang = "";
    vector<bool> daDung(26, false);

    for (char c : khoa) {
        c = toupper(c);
        if (c == 'J') c = 'I';
        if (isalpha(c) && !daDung[c - 'A']) {
            bang += c;
            daDung[c - 'A'] = true;
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (!daDung[c - 'A']) {
            bang += c;
            daDung[c - 'A'] = true;
        }
    }

    for (int i = 0; i < 25; i++) {
        matrix[i / 5][i % 5] = bang[i];
    }
}

// Tim vi tri cua ky tu trong bang
void timViTri(char c, int &row, int &col) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == c) {
                row = i;
                col = j;
                return;
            }
}

// Chuan hoa chuoi ban ro
string chuanHoa(string chuoi) {
    string ketQua = "";
    for (char c : chuoi) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            ketQua += c;
        }
    }

    string digraphs = "";
    for (int i = 0; i < ketQua.length(); i++) {
        digraphs += ketQua[i];
        if (i + 1 < ketQua.length()) {
            if (ketQua[i] == ketQua[i + 1]) {
                digraphs += 'X';
            } else {
                digraphs += ketQua[++i];
            }
        }
    }
    if (digraphs.length() % 2 != 0) digraphs += 'X';
    return digraphs;
}

// Ma hoa Playfair
string maHoa(string chuoi) {
    string ketQua = "";
    chuoi = chuanHoa(chuoi);

    for (int i = 0; i < chuoi.length(); i += 2) {
        int r1, c1, r2, c2;
        timViTri(chuoi[i], r1, c1);
        timViTri(chuoi[i + 1], r2, c2);

        if (r1 == r2) {
            ketQua += matrix[r1][(c1 + 1) % 5];
            ketQua += matrix[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            ketQua += matrix[(r1 + 1) % 5][c1];
            ketQua += matrix[(r2 + 1) % 5][c2];
        } else {
            ketQua += matrix[r1][c2];
            ketQua += matrix[r2][c1];
        }
    }
    return ketQua;
}

// Giai ma Playfair
string giaiMa(string chuoi) {
    string ketQua = "";
    for (int i = 0; i < chuoi.length(); i += 2) {
        int r1, c1, r2, c2;
        timViTri(chuoi[i], r1, c1);
        timViTri(chuoi[i + 1], r2, c2);

        if (r1 == r2) {
            ketQua += matrix[r1][(c1 + 4) % 5];
            ketQua += matrix[r2][(c2 + 4) % 5];
        } else if (c1 == c2) {
            ketQua += matrix[(r1 + 4) % 5][c1];
            ketQua += matrix[(r2 + 4) % 5][c2];
        } else {
            ketQua += matrix[r1][c2];
            ketQua += matrix[r2][c1];
        }
    }
    return ketQua;
}

int main() {
    string khoa, chuoi;
    cout << "Nhap khoa Playfair: ";
    getline(cin, khoa);
    taoBang(khoa);

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, chuoi);

    string banMa = maHoa(chuoi);
    cout << "Ban ma: " << banMa << endl;

    string banGoc = giaiMa(banMa);
    cout << "Giai ma: " << banGoc << endl;

    return 0;
}