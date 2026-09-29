// cau 3: doi tuong hoadondien
// thuoc tinh: makh, tenkh, chisocu, chisomoi
// sodientieuthu = chisomoi - chisocu
// tinh tien theo bac thang + vat 8%
// chong toan tu: nhap (>>) co bat loi chisomoi < chisocu, xuat (<<)
// so sanh (>, <, ==) theo tong tien, gan (=)
// tang (++ truoc, ++ sau): tang chisomoi them 1
// giam (-- truoc, -- sau): giam chisomoi 1, khong nho hon chisocu
// cong (+) 2 hoa don cung khach hang: cong don so dien
// ham: tinh tien dien theo bac thang, xep muc tieu thu, kiem tra vuot dinh muc

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class HoaDonDien{
    private:
        string maKH;
        string tenKH;
        int chiSoCu;
        int chiSoMoi;

    public:
        HoaDonDien();
        HoaDonDien(string ma, string ten, int csCu, int csMoi);
        HoaDonDien(const HoaDonDien &hd);

        string layMaKH() const { return maKH; }

        // chong toan tu nhap / xuat
        friend istream& operator >>(istream &in, HoaDonDien &hd);
        friend ostream& operator <<(ostream &out, const HoaDonDien &hd);

        // chong toan tu so sanh theo tong tien
        bool operator >(const HoaDonDien &hd) const;
        bool operator <(const HoaDonDien &hd) const;
        bool operator ==(const HoaDonDien &hd) const;

        // chong toan tu gan
        HoaDonDien& operator =(const HoaDonDien &hd);

        // chong toan tu tang chi so moi them 1
        HoaDonDien& operator ++();      // tien to
        HoaDonDien  operator ++(int);   // hau to

        // chong toan tu giam chi so moi bot 1 (khong nho hon chisocu)
        HoaDonDien& operator --();      // tien to
        HoaDonDien  operator --(int);   // hau to

        // chong toan tu cong 2 hoa don cung khach hang
        HoaDonDien operator +(const HoaDonDien &hd) const;

        // ham lay so dien tieu thu
        int soDienTieuThu() const { return chiSoMoi - chiSoCu; }

        // ham tinh tien dien theo bac thang (da gom vat)
        double tinhTienDien() const;

        // ham xep muc tieu thu
        string xepMucTieuThu() const;

        // ham kiem tra co vuot dinh muc khong (vuot 200 kwh)
        bool coVuotDinhMucKhong() const;
};

HoaDonDien::HoaDonDien(){
    maKH = ""; tenKH = "";
    chiSoCu = 0; chiSoMoi = 0;
}

HoaDonDien::HoaDonDien(string ma, string ten, int csCu, int csMoi){
    maKH = ma; tenKH = ten;
    chiSoCu = csCu; chiSoMoi = csMoi;
}

HoaDonDien::HoaDonDien(const HoaDonDien &hd){
    maKH = hd.maKH; tenKH = hd.tenKH;
    chiSoCu = hd.chiSoCu; chiSoMoi = hd.chiSoMoi;
}

istream& operator >>(istream &in, HoaDonDien &hd){
    cout << "Nhap ma khach hang: ";
    in >> hd.maKH;
    cin.ignore();
    cout << "Nhap ten khach hang: ";
    getline(in, hd.tenKH);
    cout << "Nhap chi so cu: ";
    in >> hd.chiSoCu;

    // bat loi: chi so moi phai lon hon hoac bang chi so cu
    do{
        cout << "Nhap chi so moi: ";
        in >> hd.chiSoMoi;
        if(hd.chiSoMoi < hd.chiSoCu){
            cout << "Loi: chi so moi khong duoc nho hon chi so cu. Nhap lai!\n";
        }
    }while(hd.chiSoMoi < hd.chiSoCu);

    return in;
}

ostream& operator <<(ostream &out, const HoaDonDien &hd){
    out << fixed << setprecision(0);
    out << "Ma KH        : " << hd.maKH << endl;
    out << "Ten KH       : " << hd.tenKH << endl;
    out << "Chi so cu    : " << hd.chiSoCu << endl;
    out << "Chi so moi   : " << hd.chiSoMoi << endl;
    out << "So dien tieu thu: " << hd.soDienTieuThu() << " kWh" << endl;
    out << "Tong tien phai tra: " << hd.tinhTienDien() << " dong" << endl;
    return out;
}

double HoaDonDien::tinhTienDien() const{
    int soDien = soDienTieuThu();
    double tien = 0;

    if(soDien <= 50){
        tien = soDien * 1800.0;
    }
    else if(soDien <= 100){
        tien = 50 * 1800.0 + (soDien - 50) * 1900.0;
    }
    else if(soDien <= 200){
        tien = 50 * 1800.0 + 50 * 1900.0 + (soDien - 100) * 2200.0;
    }
    else{
        tien = 50 * 1800.0 + 50 * 1900.0 + 100 * 2200.0 + (soDien - 200) * 2900.0;
    }

    tien = tien * 1.08; // cong them vat 8%
    return tien;
}

bool HoaDonDien::operator >(const HoaDonDien &hd) const{
    return tinhTienDien() > hd.tinhTienDien();
}
bool HoaDonDien::operator <(const HoaDonDien &hd) const{
    return tinhTienDien() < hd.tinhTienDien();
}
bool HoaDonDien::operator ==(const HoaDonDien &hd) const{
    return tinhTienDien() == hd.tinhTienDien();
}

HoaDonDien& HoaDonDien::operator =(const HoaDonDien &hd){
    if(this != &hd){
        maKH = hd.maKH; tenKH = hd.tenKH;
        chiSoCu = hd.chiSoCu; chiSoMoi = hd.chiSoMoi;
    }
    return *this;
}

// tien to: tang chi so moi truoc, tra ve gia tri sau khi tang
HoaDonDien& HoaDonDien::operator ++(){
    chiSoMoi++;
    return *this;
}

// hau to: tra ve gia tri truoc khi tang
HoaDonDien HoaDonDien::operator ++(int){
    HoaDonDien temp(*this);
    ++(*this);
    return temp;
}

// tien to: giam chi so moi truoc, khong duoc nho hon chi so cu
HoaDonDien& HoaDonDien::operator --(){
    if(chiSoMoi > chiSoCu) chiSoMoi--;
    return *this;
}

// hau to: tra ve gia tri truoc khi giam
HoaDonDien HoaDonDien::operator --(int){
    HoaDonDien temp(*this);
    --(*this);
    return temp;
}

// cong 2 hoa don cung 1 khach hang: cong don so dien tieu thu
HoaDonDien HoaDonDien::operator +(const HoaDonDien &hd) const{
    HoaDonDien ketQua;
    ketQua.maKH = maKH;
    ketQua.tenKH = tenKH;

    if(maKH != hd.maKH){
        cout << "Canh bao: hai hoa don khong cung 1 khach hang, van cong don so dien.\n";
    }

    int tongSoDien = soDienTieuThu() + hd.soDienTieuThu();
    ketQua.chiSoCu = 0;
    ketQua.chiSoMoi = tongSoDien; // quy doi thanh 1 hoa don gop, chi so cu = 0
    return ketQua;
}

string HoaDonDien::xepMucTieuThu() const{
    int soDien = soDienTieuThu();
    if(soDien <= 100) return "Tiet kiem";
    else if(soDien <= 200) return "Binh thuong";
    else if(soDien <= 400) return "Cao";
    else return "Rat cao";
}

bool HoaDonDien::coVuotDinhMucKhong() const{
    return soDienTieuThu() > 200;
}

// ---------------- menu chuong trinh ----------------
void inMenu3(){
    cout << "\n===== MENU QUAN LY HOA DON DIEN =====\n";
    cout << "1. Nhap hoa don\n";
    cout << "2. Xuat hoa don\n";
    cout << "3. Xem muc tieu thu va canh bao vuot dinh muc\n";
    cout << "4. Tang chi so moi them 1 (++ truoc / ++ sau)\n";
    cout << "5. Giam chi so moi bot 1 (-- truoc / -- sau)\n";
    cout << "6. So sanh voi mot hoa don khac\n";
    cout << "7. Cong don voi mot hoa don khac (cung khach hang)\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

int main(){
    HoaDonDien hd;
    int chon;

    do{
        inMenu3();
        cin >> chon;

        switch(chon){
            case 1:
                cin >> hd;
                break;

            case 2:
                cout << "\n--- Thong tin hoa don ---\n";
                cout << hd;
                break;

            case 3:
                cout << "\nMuc tieu thu: " << hd.xepMucTieuThu() << endl;
                if(hd.coVuotDinhMucKhong())
                    cout << "Canh bao: da vuot dinh muc 200 kWh!\n";
                else
                    cout << "Chua vuot dinh muc.\n";
                break;

            case 4:{
                cout << "\nTruoc khi tang: chi so moi = " << hd.soDienTieuThu() + 0 << endl;
                ++hd;
                cout << "Sau khi ++hd:\n" << hd;

                HoaDonDien truoc = hd++;
                cout << "hd sau khi hd++:\n" << hd;
                break;
            }

            case 5:{
                --hd;
                cout << "\nSau khi --hd:\n" << hd;

                HoaDonDien truoc = hd--;
                cout << "hd sau khi hd--:\n" << hd;
                break;
            }

            case 6:{
                HoaDonDien khac;
                cout << "Nhap hoa don de so sanh:\n";
                cin >> khac;

                if(hd == khac) cout << "Hai hoa don co tong tien BANG nhau.\n";
                if(hd > khac)  cout << "Hoa don hien tai co tong tien LON HON.\n";
                if(hd < khac)  cout << "Hoa don hien tai co tong tien NHO HON.\n";
                break;
            }

            case 7:{
                HoaDonDien khac;
                cout << "Nhap hoa don can cong don (cung khach hang):\n";
                cin >> khac;
                HoaDonDien tong = hd + khac;
                cout << "\nHoa don sau khi cong don:\n" << tong;
                break;
            }

            case 0:
                cout << "Ket thuc chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    }while(chon != 0);

    return 0;
}
