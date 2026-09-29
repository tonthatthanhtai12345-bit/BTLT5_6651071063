// cau 1: doi tuong thoigian
// thuoc tinh: gio (0-23), phut (0-59), giay (0-59)
// chong toan tu: nhap (>>), xuat (<<) dang hh:mm:ss
// so sanh (==, !=, <, >), gan (=)
// tang (++ truoc, ++ sau): tang 1 giay, tu nho sang phut, gio
// cong (+) thoigian voi so nguyen giay
// ham: kiem tra hop le, xac dinh buoi, tinh khoang cach 2 moc thoi gian

#include<iostream>
#include<iomanip>
using namespace std;

class ThoiGian{
    private:
        int gio, phut, giay;

    public:
        ThoiGian();                          // constructor mac dinh
        ThoiGian(int g, int p, int gi);      // constructor co tham so
        ThoiGian(const ThoiGian &t);         // constructor sao chep

        // chong toan tu nhap / xuat
        friend istream& operator >>(istream &in, ThoiGian &t);
        friend ostream& operator <<(ostream &out, const ThoiGian &t);

        // chong toan tu so sanh
        bool operator ==(const ThoiGian &t) const;
        bool operator !=(const ThoiGian &t) const;
        bool operator <(const ThoiGian &t) const;
        bool operator >(const ThoiGian &t) const;

        // chong toan tu gan
        ThoiGian& operator =(const ThoiGian &t);

        // chong toan tu tang 1 giay
        ThoiGian& operator ++();      // tien to
        ThoiGian  operator ++(int);   // hau to

        // chong toan tu cong voi so giay
        ThoiGian operator +(int soGiay) const;

        // tra ve tong so giay tinh tu 00:00:00
        long tongGiay() const;

        // ham kiem tra du lieu nhap co hop le khong
        bool hopLe() const;

        // ham xac dinh thoi gian thuoc buoi nao
        string xacDinhBuoi() const;

        // ham tinh khoang cach (so giay) giua 2 moc thoi gian
        static long khoangCach(const ThoiGian &t1, const ThoiGian &t2);
};

ThoiGian::ThoiGian(){
    gio = 0; phut = 0; giay = 0;
}

ThoiGian::ThoiGian(int g, int p, int gi){
    gio = g; phut = p; giay = gi;
}

ThoiGian::ThoiGian(const ThoiGian &t){
    gio = t.gio; phut = t.phut; giay = t.giay;
}

istream& operator >>(istream &in, ThoiGian &t){
    cout << "Nhap gio (0-23): ";
    in >> t.gio;
    cout << "Nhap phut (0-59): ";
    in >> t.phut;
    cout << "Nhap giay (0-59): ";
    in >> t.giay;

    if(!t.hopLe()){
        cout << "Du lieu khong hop le, tu dong dat lai ve 00:00:00\n";
        t.gio = 0; t.phut = 0; t.giay = 0;
    }
    return in;
}

ostream& operator <<(ostream &out, const ThoiGian &t){
    out << setfill('0') << setw(2) << t.gio << ":"
        << setfill('0') << setw(2) << t.phut << ":"
        << setfill('0') << setw(2) << t.giay;
    return out;
}

long ThoiGian::tongGiay() const{
    return (long)gio * 3600 + phut * 60 + giay;
}

bool ThoiGian::operator ==(const ThoiGian &t) const{
    return tongGiay() == t.tongGiay();
}
bool ThoiGian::operator !=(const ThoiGian &t) const{
    return tongGiay() != t.tongGiay();
}
bool ThoiGian::operator <(const ThoiGian &t) const{
    return tongGiay() < t.tongGiay();
}
bool ThoiGian::operator >(const ThoiGian &t) const{
    return tongGiay() > t.tongGiay();
}

ThoiGian& ThoiGian::operator =(const ThoiGian &t){
    if(this != &t){
        gio = t.gio; phut = t.phut; giay = t.giay;
    }
    return *this;
}

// tien to: tang truoc, tra ve gia tri sau khi tang
ThoiGian& ThoiGian::operator ++(){
    giay++;
    if(giay >= 60){
        giay = 0;
        phut++;
        if(phut >= 60){
            phut = 0;
            gio++;
            if(gio >= 24){
                gio = 0; // qua ngay moi, quay lai 00:00:00
            }
        }
    }
    return *this;
}

// hau to: tra ve gia tri truoc khi tang
ThoiGian ThoiGian::operator ++(int){
    ThoiGian temp(*this);
    ++(*this);
    return temp;
}

// cong them mot so giay bat ky, tu dong nho sang phut, gio, ngay
ThoiGian ThoiGian::operator +(int soGiay) const{
    long tong = tongGiay() + soGiay;
    tong = tong % 86400;     // gioi han trong 1 ngay (86400 giay)
    if(tong < 0) tong += 86400;

    ThoiGian ketQua;
    ketQua.gio  = tong / 3600;
    ketQua.phut = (tong % 3600) / 60;
    ketQua.giay = tong % 60;
    return ketQua;
}

bool ThoiGian::hopLe() const{
    return (gio >= 0 && gio <= 23) &&
           (phut >= 0 && phut <= 59) &&
           (giay >= 0 && giay <= 59);
}

string ThoiGian::xacDinhBuoi() const{
    if(gio >= 5 && gio < 11)  return "Sang";
    if(gio >= 11 && gio < 13) return "Trua";
    if(gio >= 13 && gio < 18) return "Chieu";
    if(gio >= 18 && gio < 22) return "Toi";
    return "Dem";
}

long ThoiGian::khoangCach(const ThoiGian &t1, const ThoiGian &t2){
    long hieu = t1.tongGiay() - t2.tongGiay();
    return hieu >= 0 ? hieu : -hieu;
}

// ---------------- menu chuong trinh ----------------
void inMenu1(){
    cout << "\n===== MENU QUAN LY THOI GIAN =====\n";
    cout << "1. Nhap thoi gian\n";
    cout << "2. Xuat thoi gian\n";
    cout << "3. Xem thoi gian thuoc buoi nao\n";
    cout << "4. Tang 1 giay (++ truoc / ++ sau)\n";
    cout << "5. Cong them n giay\n";
    cout << "6. So sanh voi mot moc thoi gian khac\n";
    cout << "7. Tinh khoang cach (giay) voi mot moc thoi gian khac\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

int main(){
    ThoiGian tg;
    int chon;

    do{
        inMenu1();
        cin >> chon;

        switch(chon){
            case 1:
                cin >> tg;
                break;

            case 2:
                cout << "\nThoi gian hien tai: " << tg << endl;
                break;

            case 3:
                cout << "\nThoi gian " << tg << " thuoc buoi: " << tg.xacDinhBuoi() << endl;
                break;

            case 4:{
                cout << "\nTruoc khi tang: " << tg << endl;
                ++tg;
                cout << "Sau khi ++tg: " << tg << endl;

                ThoiGian truoc = tg++;
                cout << "Gia tri tg++ tra ve (truoc khi tang): " << truoc << endl;
                cout << "tg sau khi tg++: " << tg << endl;
                break;
            }

            case 5:{
                int soGiay;
                cout << "Nhap so giay muon cong them: ";
                cin >> soGiay;
                ThoiGian ketQua = tg + soGiay;
                cout << "Ket qua sau khi cong: " << ketQua << endl;
                break;
            }

            case 6:{
                ThoiGian khac;
                cout << "Nhap moc thoi gian de so sanh:\n";
                cin >> khac;

                if(tg == khac) cout << "Hai moc thoi gian BANG nhau.\n";
                if(tg != khac) cout << "Hai moc thoi gian KHAC nhau.\n";
                if(tg > khac)  cout << "Thoi gian hien tai MUON HON.\n";
                if(tg < khac)  cout << "Thoi gian hien tai SOM HON.\n";
                break;
            }

            case 7:{
                ThoiGian khac;
                cout << "Nhap moc thoi gian de tinh khoang cach:\n";
                cin >> khac;
                cout << "Khoang cach: " << ThoiGian::khoangCach(tg, khac) << " giay\n";
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
