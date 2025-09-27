#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Ham kiem tra khoa hoan vi hop le
bool kiemTraKhoa(const vector<int> &khoa, int n) {
    vector<bool> daDung(n, false);
    for (int i : khoa) {
        if (i < 0 || i >= n || daDung[i]) return false;
        daDung[i] = true;
    }
    return true;
}

// Ham ma hoa hoan vi
string maHoaHoanVi(const string &banRong, const vector<int> &khoa) {
    string ketQua = banRong;
    for (int i = 0; i < khoa.size(); i++) {
        ketQua[i] = banRong[khoa[i]];
    }
    return ketQua;
}

// Ham giai ma hoan vi
string giaiMaHoanVi(const string &banMa, const vector<int> &khoa) {
    string ketQua = banMa;
    for (int i = 0; i < khoa.size(); i++) {
        ketQua[khoa[i]] = banMa[i];
    }
    return ketQua;
}

int main() {
    string chuoi;
    int n;

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, chuoi);

    n = chuoi.length();
    vector<int> khoa(n);

    cout << "Nhap khoa hoan vi gom " << n << " so (tu 0 den " << n - 1 << "):\n";
    for (int i = 0; i < n; i++) {
        cin >> khoa[i];
    }

    if (!kiemTraKhoa(khoa, n)) {
        cout << "Khoa khong hop le. Vui long nhap lai.\n";
        return 1;
    }

    string banMa = maHoaHoanVi(chuoi, khoa);
    cout << "Ban ma: " << banMa << endl;

    string banGoc = giaiMaHoanVi(banMa, khoa);
    cout << "Ban goc: " << banGoc << endl;

    return 0;
}