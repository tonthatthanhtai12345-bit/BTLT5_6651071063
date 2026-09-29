// cau 2: doi tuong nhanvien
// thuoc tinh: manv, hoten, luongcoban, hesoluong, phucap
// luong thuc linh = luongcoban*hesoluong + phucap - baohiem
// baohiem = 10.5% cua (luongcoban*hesoluong)
// chong toan tu: nhap (>>), xuat (<<)
// so sanh (>, <, ==) theo luong thuc linh, gan (=)
// tang (++ truoc, ++ sau): nang bac, tang hesoluong them 0.33
// ham: tinh luong thuc linh, xep loai thu nhap, kiem tra co dong thue tncn
// main: nhap danh sach n nhan vien, sap xep giam dan theo luong,
//       tim nhan vien luong cao nhat, nang bac theo manv

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

class NhanVien{
    private:
        string maNV;
        string hoTen;
        double luongCoBan;
        double heSoLuong;
        double phuCap;

    public:
        NhanVien();
        NhanVien(string ma, string ten, double lcb, double hs, double pc);
        NhanVien(const NhanVien &nv);

        string layMaNV() const { return maNV; }
        string layHoTen() const { return hoTen; }

        // chong toan tu nhap / xuat
        friend istream& operator >>(istream &in, NhanVien &nv);
        friend ostream& operator <<(ostream &out, const NhanVien &nv);

        // chong toan tu so sanh theo luong thuc linh
        bool operator >(const NhanVien &nv) const;
        bool operator <(const NhanVien &nv) const;
        bool operator ==(const NhanVien &nv) const;

        // chong toan tu gan
        NhanVien& operator =(const NhanVien &nv);

        // chong toan tu tang: nang bac, tang hesoluong them 0.33
        NhanVien& operator ++();      // tien to
        NhanVien  operator ++(int);   // hau to

        // ham tinh luong thuc linh
        double tinhLuongThucLinh() const;

        // ham xep loai thu nhap
        string xepLoaiThuNhap() const;

        // ham kiem tra co phai dong thue tncn khong
        bool coDongThueTNCN() const;
};

NhanVien::NhanVien(){
    maNV = ""; hoTen = "";
    luongCoBan = 0; heSoLuong = 0; phuCap = 0;
}

NhanVien::NhanVien(string ma, string ten, double lcb, double hs, double pc){
    maNV = ma; hoTen = ten;
    luongCoBan = lcb; heSoLuong = hs; phuCap = pc;
}

NhanVien::NhanVien(const NhanVien &nv){
    maNV = nv.maNV; hoTen = nv.hoTen;
    luongCoBan = nv.luongCoBan;
    heSoLuong = nv.heSoLuong;
    phuCap = nv.phuCap;
}

istream& operator >>(istream &in, NhanVien &nv){
    cout << "Nhap ma nhan vien: ";
    in >> nv.maNV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(in, nv.hoTen);
    cout << "Nhap luong co ban: ";
    in >> nv.luongCoBan;
    cout << "Nhap he so luong: ";
    in >> nv.heSoLuong;
    cout << "Nhap phu cap: ";
    in >> nv.phuCap;
    return in;
}

ostream& operator <<(ostream &out, const NhanVien &nv){
    out << fixed << setprecision(0);
    out << "Ma NV       : " << nv.maNV << endl;
    out << "Ho ten      : " << nv.hoTen << endl;
    out << "Luong co ban: " << nv.luongCoBan << endl;
    out << "He so luong : " << nv.heSoLuong << endl;
    out << "Phu cap     : " << nv.phuCap << endl;
    out << "Luong thuc linh: " << nv.tinhLuongThucLinh() << " dong" << endl;
    return out;
}

double NhanVien::tinhLuongThucLinh() const{
    double luongCoSo = luongCoBan * heSoLuong;
    double baoHiem = luongCoSo * 0.105;
    return luongCoSo + phuCap - baoHiem;
}

bool NhanVien::operator >(const NhanVien &nv) const{
    return tinhLuongThucLinh() > nv.tinhLuongThucLinh();
}
bool NhanVien::operator <(const NhanVien &nv) const{
    return tinhLuongThucLinh() < nv.tinhLuongThucLinh();
}
bool NhanVien::operator ==(const NhanVien &nv) const{
    return tinhLuongThucLinh() == nv.tinhLuongThucLinh();
}

NhanVien& NhanVien::operator =(const NhanVien &nv){
    if(this != &nv){
        maNV = nv.maNV; hoTen = nv.hoTen;
        luongCoBan = nv.luongCoBan;
        heSoLuong = nv.heSoLuong;
        phuCap = nv.phuCap;
    }
    return *this;
}

// tien to: nang bac truoc, tra ve gia tri sau khi nang
NhanVien& NhanVien::operator ++(){
    heSoLuong += 0.33;
    return *this;
}

// hau to: tra ve gia tri truoc khi nang bac
NhanVien NhanVien::operator ++(int){
    NhanVien temp(*this);
    ++(*this);
    return temp;
}

string NhanVien::xepLoaiThuNhap() const{
    double luong = tinhLuongThucLinh();
    if(luong < 7000000) return "Thap";
    else if(luong < 15000000) return "Trung binh";
    else if(luong < 25000000) return "Kha";
    else return "Cao";
}

bool NhanVien::coDongThueTNCN() const{
    return tinhLuongThucLinh() > 11000000;
}

// ---------------- menu chuong trinh ----------------
void inMenu2(){
    cout << "\n===== MENU QUAN LY NHAN VIEN =====\n";
    cout << "1. Nhap danh sach n nhan vien\n";
    cout << "2. Xuat danh sach nhan vien\n";
    cout << "3. Sap xep giam dan theo luong thuc linh\n";
    cout << "4. Tim nhan vien co luong cao nhat\n";
    cout << "5. Nang bac cho 1 nhan vien theo ma NV\n";
    cout << "6. Xep loai thu nhap va kiem tra thue TNCN cua tung nhan vien\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

int main(){
    vector<NhanVien> ds;
    int chon;

    do{
        inMenu2();
        cin >> chon;

        switch(chon){
            case 1:{
                int n;
                cout << "Nhap so luong nhan vien: ";
                cin >> n;
                ds.clear();
                for(int i = 0; i < n; i++){
                    cout << "\n-- Nhan vien thu " << i + 1 << " --\n";
                    NhanVien nv;
                    cin >> nv;
                    ds.push_back(nv);
                }
                break;
            }

            case 2:
                if(ds.empty()){
                    cout << "\nDanh sach rong, hay nhap truoc.\n";
                    break;
                }
                for(size_t i = 0; i < ds.size(); i++){
                    cout << "\n-- Nhan vien " << i + 1 << " --\n";
                    cout << ds[i];
                }
                break;

            case 3:{
                // sap xep giam dan bang bubble sort, dung toan tu >
                for(size_t i = 0; i < ds.size(); i++){
                    for(size_t j = 0; j + 1 < ds.size() - i; j++){
                        if(ds[j] < ds[j + 1]){
                            NhanVien temp = ds[j];
                            ds[j] = ds[j + 1];
                            ds[j + 1] = temp;
                        }
                    }
                }
                cout << "\nDa sap xep giam dan theo luong thuc linh.\n";
                break;
            }

            case 4:{
                if(ds.empty()){
                    cout << "\nDanh sach rong.\n";
                    break;
                }
                NhanVien caoNhat = ds[0];
                for(size_t i = 1; i < ds.size(); i++){
                    if(ds[i] > caoNhat) caoNhat = ds[i];
                }
                cout << "\nNhan vien co luong cao nhat:\n" << caoNhat;
                break;
            }

            case 5:{
                string ma;
                cout << "Nhap ma nhan vien can nang bac: ";
                cin >> ma;
                bool timThay = false;
                for(size_t i = 0; i < ds.size(); i++){
                    if(ds[i].layMaNV() == ma){
                        ds[i]++;   // nang bac (hau to)
                        cout << "Da nang bac cho nhan vien " << ds[i].layHoTen() << "\n";
                        timThay = true;
                        break;
                    }
                }
                if(!timThay) cout << "Khong tim thay nhan vien co ma " << ma << "\n";
                break;
            }

            case 6:
                if(ds.empty()){
                    cout << "\nDanh sach rong.\n";
                    break;
                }
                for(size_t i = 0; i < ds.size(); i++){
                    cout << "\n" << ds[i].layHoTen()
                         << " - Xep loai: " << ds[i].xepLoaiThuNhap()
                         << " - Dong thue TNCN: " << (ds[i].coDongThueTNCN() ? "Co" : "Khong") << endl;
                }
                break;

            case 0:
                cout << "Ket thuc chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    }while(chon != 0);

    return 0;
}
