#include "bill.hpp"
#include "customer.hpp"
#include "menu.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Dinh nghia cac ham cho lop HoaDon

HoaDon::HoaDon(KhachHang khach, Ngay ngay, vector<int> soMoiMon, vector<string> tenMonGoi, vector<float> giaMonGoi,
               int soMonGoi, float tongTien, float tienThua, float tienNguyenLieu)
    : khach(khach), ngayNhapDon(ngay), soMoiMon(soMoiMon), tenMonGoi(tenMonGoi), giaMonGoi(giaMonGoi), 
      soMonGoi(soMonGoi), tongTien(tongTien), tienThua(tienThua), tienNguyenLieu(tienNguyenLieu) {}

KhachHang HoaDon::getKhach() const {
    return khach;
}

void HoaDon::setKhach(const KhachHang& khach) {
    this->khach = khach;
}

Ngay HoaDon::getNgay() const {
    return ngayNhapDon;
}

void HoaDon::setNgay(const Ngay& ngay) {
    ngayNhapDon.setNgay(ngay.getNgay());
    ngayNhapDon.setThang(ngay.getThang());
    ngayNhapDon.setNam(ngay.getNam());
}

vector<int> HoaDon::getSoMoiMon() const {
    return soMoiMon;
}

vector<int>& HoaDon::getRefSoMoiMon() {
    return soMoiMon;
}

void HoaDon::setSoMoiMon(const vector<int>& soLuong) {
    soMoiMon = soLuong;
}

vector<string> HoaDon::getTenMon() const {
    return tenMonGoi;
}

vector<string>& HoaDon::getRefTenMon() {
    return tenMonGoi;
}

void HoaDon::setTenMon(const vector<string>& dsTen) {
    tenMonGoi = dsTen;
}

vector<float> HoaDon::getGiaMoiMon() const {
    return giaMonGoi;
}

vector<float>& HoaDon::getRefGiaMoiMon() {
    return giaMonGoi;
}

void HoaDon::setGiaMoiMon(const vector<float>& giaMon) {
    giaMonGoi = giaMon;
}

int HoaDon::getSoMonGoi() const {
    return soMonGoi;
}

void HoaDon::setSoMonGoi(const int soMon) {
    soMonGoi = soMon;
}

float HoaDon::getTongTien() const {
    return tongTien;
}

float& HoaDon::getRefTongTien() {
    return tongTien;
}

void HoaDon::setTongTien(const float tongTien) {
    this->tongTien = tongTien;
}

float HoaDon::getTienThua() const {
    return tienThua;
}

float& HoaDon::getRefTienThua() {
    return tienThua;
}

void HoaDon::setTienThua(const float tienThua) {
    this->tienThua = tienThua;
}

float HoaDon::getTienNguyenLieu() const {
    return tienNguyenLieu;
}

void HoaDon::setTienNguyenLieu(const float tienNguyenLieu) {
    this->tienNguyenLieu = tienNguyenLieu;
}

float& HoaDon::getRefTienNguyenLieu() {
    return tienNguyenLieu;
}

int HoaDon::doiTuongCoNhuNhau(const DoiTuongLamViec& other) const {
    const HoaDon* otherHoaDon = dynamic_cast<const HoaDon*>(&other);
    return (
        khach.doiTuongCoNhuNhau(otherHoaDon->khach) &&
        ngayNhapDon.coNhuNhauNgay(otherHoaDon->ngayNhapDon) &&
        soMoiMon == otherHoaDon->soMoiMon &&
        tenMonGoi == otherHoaDon->tenMonGoi &&
        giaMonGoi == otherHoaDon->giaMonGoi &&
        soMonGoi == otherHoaDon->soMonGoi &&
        tongTien == otherHoaDon->tongTien &&
        tienThua == otherHoaDon->tienThua &&
        tienNguyenLieu == otherHoaDon->tienNguyenLieu
    );
}

int HoaDon::coLaMotDoiTuong(const DoiTuongLamViec& other) const {
    const HoaDon* otherHoaDon = dynamic_cast<const HoaDon*>(&other);

    return (
        khach.doiTuongCoNhuNhau(otherHoaDon->khach) &&
        ngayNhapDon.coNhuNhauNgay(otherHoaDon->ngayNhapDon) &&
        soMoiMon == otherHoaDon->soMoiMon &&
        tenMonGoi == otherHoaDon->tenMonGoi &&
        giaMonGoi == otherHoaDon->giaMonGoi &&
        soMonGoi == otherHoaDon->soMonGoi &&
        tongTien == otherHoaDon->tongTien &&
        tienThua == otherHoaDon->tienThua
    );
}

void HoaDon::nhapThongTinNhanDang() {
    khach.nhapThongTin();
    ngayNhapDon.nhapNgay();

    do {
        cout << "Nhap so mon (toi da " << MAX_MON << "): ";
        saferScanf("%d", &soMonGoi);
    } while (soMonGoi < 0 || soMonGoi > MAX_MON);

    vector<string> tenMon;
    vector<int> soMon;
    vector<float> giaMon;
    string ten;
    int soLuong;
    float gia;
    for (int i = 0; i < soMonGoi; i++) {
        cout << "Nhap ten mon an: ";
        getline(cin, ten);
        tenMon.push_back(ten);
        cout << "So luong mon an: ";
        saferScanf("%d", &soLuong);
        soMon.push_back(soLuong);
        cout << "Gia mon an: ";
        saferScanf("%f", &gia);
        giaMon.push_back(gia);
    }

    tenMonGoi = tenMon;
    soMoiMon = soMon;
    giaMonGoi = giaMon;

    cout << "Nhap tong tien hoa don: ";
    saferScanf("%f", &tongTien);
    cout << "Nhap tien thua: ";
    saferScanf("%f", &tienThua);
}

void HoaDon::nhapThongTin() {
    khach.nhapThongTin();
    ngayNhapDon.nhapNgay();

    do {
        cout << "Nhap so mon (toi da " << MAX_MON << "): ";
        saferScanf("%d", &soMonGoi);
    } while (soMonGoi < 0 || soMonGoi > MAX_MON);

    vector<string> tenMon;
    vector<int> soMon;
    vector<float> giaMon;
    string ten;
    int soLuong;
    float gia;
    for (int i = 0; i < soMonGoi; i++) {
        cout << "Nhap ten mon an: ";
        getline(cin, ten);
        tenMon.push_back(ten);
        cout << "So luong mon an: ";
        saferScanf("%d", &soLuong);
        soMon.push_back(soLuong);
        cout << "Gia mon an: ";
        saferScanf("%f", &gia);
        giaMon.push_back(gia);
    }

    tenMonGoi = tenMon;
    soMoiMon = soMon;
    giaMonGoi = giaMon;

    cout << "Nhap tong tien hoa don: ";
    saferScanf("%f", &tongTien);
    cout << "Nhap tien thua: ";
    saferScanf("%f", &tienThua);
    cout << "Nhap chi phi nguyen lieu: ";
    saferScanf("%f", &tienNguyenLieu);
}

void HoaDon::saoChepThongTin(const DoiTuongLamViec& other) {
    const HoaDon* otherHoaDon = dynamic_cast<const HoaDon*>(&other);
    khach.saoChepThongTin(otherHoaDon->khach);
    ngayNhapDon = otherHoaDon->ngayNhapDon;
    soMoiMon = otherHoaDon->soMoiMon;
    tenMonGoi = otherHoaDon->tenMonGoi;
    giaMonGoi = otherHoaDon->giaMonGoi;
    soMonGoi = otherHoaDon->soMonGoi;
    tongTien = otherHoaDon->tongTien;
    tienThua = otherHoaDon->tienThua;
    tienNguyenLieu = otherHoaDon->tienNguyenLieu;
}

// Dinh nghia cac ham cho lop quan li hoa don

QuanLiHoaDon::QuanLiHoaDon(int maxMang, int maxFile, int luaChon, string dauDan) 
            : QuanLiDanhSach(maxMang, maxFile, luaChon, dauDan) {};

HoaDon QuanLiHoaDon::taoDoiTuongTuXau(string xauThongTin) const {
    xauThongTin.erase(xauThongTin.find_last_not_of('\n') + 1);

    istringstream iss(xauThongTin);
    vector<string> tokens;
    string token;

    // Tach chuoi bang dau phay
    while (getline(iss, token, ',')) {
        tokens.push_back(token);
    }

    int soMonGoi = stoi(tokens[96]);

    KhachHang khach(tokens[0], tokens[1], stof(tokens[2]));

    Ngay ngay(stoi(tokens[3]), stoi(tokens[4]), stoi(tokens[5]));

    vector<int> soMoiMon(soMonGoi, 0);
    vector<string> tenMonGoi(soMonGoi, "");
    vector<float> giaMonGoi(soMonGoi, 0.0f);

    for (int i = 0; i < soMonGoi; i++) {
        soMoiMon[i] = tokens[6 + i].empty() ? 0 : stoi(tokens[6 + i]);
        tenMonGoi[i] = tokens[36 + i];
        giaMonGoi[i] = tokens[66 + i].empty() ? 0.0f : stof(tokens[66 + i]);
    }

    float tongTien = stof(tokens[97]);
    float tienThua = stof(tokens[98]);
    float tienNguyenLieu = stof(tokens[99]);

    return HoaDon(khach, ngay, soMoiMon, tenMonGoi, giaMonGoi, soMonGoi, tongTien, tienThua, tienNguyenLieu);
}

string QuanLiHoaDon::layXauDoiTuong(const HoaDon& hoaDon) const {
    stringstream ss;
    
    QuanLiKhachHang qlkh(0, 0, 0, "");
    string khachHangInfo = qlkh.layXauDoiTuong(hoaDon.getKhach());
    khachHangInfo.erase(khachHangInfo.find_last_not_of('\n') + 1);
    ss << khachHangInfo << NGAN_PHAN_TU_CSV;
    
    Ngay ngay = hoaDon.getNgay();
    ss << ngay.getNgay() << NGAN_PHAN_TU_CSV << ngay.getThang() << NGAN_PHAN_TU_CSV << ngay.getNam() << NGAN_PHAN_TU_CSV;
    
    vector<int> soMoiMon = hoaDon.getSoMoiMon();
    vector<string> tenMonGoi = hoaDon.getTenMon();
    vector<float> giaMonGoi = hoaDon.getGiaMoiMon();
    
    for (int i = 0; i < MAX_MON; i++) {
        if(i < soMoiMon.size()) {
            ss << soMoiMon[i] << NGAN_PHAN_TU_CSV;
            continue;
        }
        ss << 0 << NGAN_PHAN_TU_CSV;
    }

    for (int i = 0; i < MAX_MON; i++) {
        if(i < tenMonGoi.size()) {
            ss << tenMonGoi[i] << NGAN_PHAN_TU_CSV;
            continue;
        }
        ss << "" << NGAN_PHAN_TU_CSV;
    }

    for (int i = 0; i < MAX_MON; i++) {
        if(i < giaMonGoi.size()) {
            ss << fixed << setprecision(2) << giaMonGoi[i] << NGAN_PHAN_TU_CSV;
            continue;
        }
        ss << 0 << NGAN_PHAN_TU_CSV;
    }
    
    ss << hoaDon.getSoMonGoi() << NGAN_PHAN_TU_CSV;
    ss << hoaDon.getTongTien() << NGAN_PHAN_TU_CSV;
    ss << hoaDon.getTienThua() << NGAN_PHAN_TU_CSV;
    ss << hoaDon.getTienNguyenLieu();
    ss << "\n";
    
    return ss.str();
}

void QuanLiHoaDon::hienThi(const vector<HoaDon>& danhSach) const {
    for (int i = 0; i < danhSach.size(); i++) {
        ostringstream oss;
        oss << fixed << setprecision(2); // Cai dat format
        oss << "\n========================= DANH SACH HOA DON =========================\n\n";
        oss << "----------------------------------------------------------------------\n";
        oss << "HOA DON SO: " << i + 1 << endl;
        oss << "----------------------------------------------------------------------\n";
        oss << "Ten khach hang   : " << danhSach[i].getKhach().getName() << "\n";
        oss << "Diem tich luy    : " << danhSach[i].getKhach().getPoint() << "\n";
        oss << "So dien thoai    : " << danhSach[i].getKhach().getPhoneNum() << "\n";
        oss << "Ngay nhap don    : "
            << danhSach[i].getNgay().getNgay() << "/"
            << danhSach[i].getNgay().getThang() << "/"
            << danhSach[i].getNgay().getNam() << "\n";
        oss << "----------------------------------------------------------------------\n";
        oss << left << setw(5) << "STT" 
            << setw(20) << "Ten mon" 
            << setw(10) << "So luong" 
            << setw(10) << "Don gia" 
            << setw(10) << "Thanh tien" << endl;
        oss << "----------------------------------------------------------------------\n";

        for (int j = 0; j < danhSach[i].getSoMonGoi(); j++) {
            oss << setw(5) << j + 1
                << setw(20) << danhSach[i].getTenMon()[j] 
                << setw(10) << danhSach[i].getSoMoiMon()[j] 
                << setw(10) << danhSach[i].getGiaMoiMon()[i] 
                << setw(10) << danhSach[i].getSoMoiMon()[j] * danhSach[i].getGiaMoiMon()[i] << "\n";
        }

        oss << "----------------------------------------------------------------------\n";
        oss << setw(36) << "" << setw(10) << "TONG TIEN: " << danhSach[i].getTongTien() << "\n";
        oss << setw(36) << "" << setw(10) << "TIEN THUA: " << danhSach[i].getTienThua() << "\n";
        oss << "======================================================================\n\n";

        // Output the built string to console
        cout << oss.str();
    }
}

void QuanLiHoaDon::timKiem(const vector<HoaDon>& danhSach) const {
    int luaChon;
    float giaTien;
    string keyword;
    int monTimKiem;

    cout << "\nChon phuong thuc tim kiem hoa don:\n";
    cout << "1. Tim theo gia tien\n";
    cout << "2. Tim theo ten/sdt khach hang\n";
    cout << "3. Tim theo mon an\n";
    cout << "Nhap lua chon: ";
    saferScanf("%d", &luaChon);

    if (luaChon == 1) {
        cout << "Nhap gia tien hoa don: ";
        saferScanf("%f", &giaTien);
        
        ostringstream oss;
        oss << "\nDanh sach hoa don tim duoc theo gia tien " << fixed << setprecision(2) << giaTien << ":\n";
        for (int i = 0; i < danhSach.size(); i++) {
            if (danhSach[i].getTongTien() == giaTien) {
                oss << "Hoa don " << i + 1 << ": "
                    << "Ten khach hang: " << danhSach[i].getKhach().getName() 
                    << " - So dien thoai: " << danhSach[i].getKhach().getPhoneNum() 
                    << " - Ngay nhap: " << danhSach[i].getNgay().getNgay() << "/"
                    << danhSach[i].getNgay().getThang() << "/"
                    << danhSach[i].getNgay().getNam() 
                    << " - Tong tien: " << fixed << setprecision(2) << danhSach[i].getTongTien();
            }
        }
        cout << oss.str() << "\n";

    } else if (luaChon == 2) {
        cout << "Nhap ten hoac so dien thoai khach hang: ";
        getline(cin, keyword);
        
        ostringstream oss;
        oss << "\nDanh sach hoa don tim duoc theo ten/sdt khach hang '" << keyword << "':\n";
        for (int i = 0; i < danhSach.size(); i++) {
            if (danhSach[i].getKhach().getName().find(keyword) != string::npos || 
                danhSach[i].getKhach().getPhoneNum().find(keyword) != string::npos) {
                oss << "Hoa don " << i + 1 << ": "
                    << "Ten khach hang: " << danhSach[i].getKhach().getName() 
                    << " - So dien thoai: " << danhSach[i].getKhach().getPhoneNum() 
                    << " - Ngay nhap: " << danhSach[i].getNgay().getNgay() << "/"
                    << danhSach[i].getNgay().getThang() << "/"
                    << danhSach[i].getNgay().getNam() 
                    << " - Tong tien: " << fixed << setprecision(2) << danhSach[i].getTongTien();
            }
        }
        cout << oss.str() << "\n";

    } else if (luaChon == 3) {
        cout << "Nhap mon an can tim: ";
        getline(cin, keyword);

        ostringstream oss;
        oss << "\nDanh sach hoa don chua mon an '" << keyword << "':\n";
        for (int i = 0; i < danhSach.size(); i++) {
            for (int j = 0; j < danhSach[i].getSoMonGoi(); j++) {
                if (danhSach[i].getTenMon()[j].find(keyword) != string::npos) {
                    oss << "Hoa don " << i + 1 << ": "
                        << "Ten khach hang: " << danhSach[i].getKhach().getName() 
                        << " - So dien thoai: " << danhSach[i].getKhach().getPhoneNum() 
                        << " - Ngay nhap: " << danhSach[i].getNgay().getNgay() << "/"
                        << danhSach[i].getNgay().getThang() << "/"
                        << danhSach[i].getNgay().getNam() 
                        << " - Tong tien: " << fixed << setprecision(2) << danhSach[i].getTongTien();
                    break;  // Dung khi thay mon an
                }
            }
        }

        cout << oss.str() << "\n";
    } else {
        cout << "Lua chon khong hop le.\n";
    }
}

// Dinh nghia ham thanh toan

void thanhToan(const QuanLiMenu& menu, QuanLiNguyenLieu& kho, QuanLiKhachHang& dsKhach, QuanLiHoaDon& dsHoaDon) {
    int soNguyenLieuKho = kho.soLuongMang();
    if(soNguyenLieuKho == 0) {
        cout << "Kho trong, khong the order\n";
        return;
    }

    ostringstream oss;

    int soMon = menu.soLuongMang();
    vector<NguyenLieu> khoNguyenLieu = kho.layDanhSachMang();
    vector<MonAn> dsMon = menu.layDanhSachMang();
    HoaDon hoaDon;
    KhachHang khach;
    Ngay ngay;

    // Nhap thong tin khach hang cho hoa don + lay diem tich luy
    string tenKhach, sdtKhach;
    
    cout << "Nhap thong tin khach hang:\n";
    cout << "Nhap ten khach hang: ";
    getline(cin, tenKhach);
    cout << "Nhap so dien thoai khach hang: ";
    getline(cin, sdtKhach);
    khach.setName(tenKhach);
    khach.setPhoneNum(sdtKhach);

    // Lay diem tich luy da co:
    // Uu tien lay trong mang
    int diemTichLuy = dsKhach.layDiemTichLuyMang(khach);
    if(diemTichLuy == -1) { // Khong lya duoc trong mang thi tim trong file
        diemTichLuy = dsKhach.layDiemTichLuyFile(khach);
    }
    khach.setPoint(diemTichLuy == -1 ? 0 : diemTichLuy);


    // Nhap ngay
    ngay.nhapNgay();

    // Chon mon
    int idxMon;
    cout << "Chon mon va so luong mon:\n";
    while(1) {
        menu.hienThiMang();

        string tenMon;
        cout << "Nhap ten mon (nhan '0' de dung): ";
        getline(cin, tenMon);

        if(tenMon == "0") {
            break;
        }

        // Kiem tra menu co mon khon
        int timThay = 0;
        for(int i = 0; i < soMon; i++) {
            if(tenMon == dsMon[i].getName()) {
                idxMon = i;
                timThay = 1;
                break;
            }
        }
        if(timThay == 0) {
            cout << "Khong tim thay mon an\n";
            continue;
        }

        // Kiem tra kha nang dap ung cua kho
        MonAn monChon = dsMon[idxMon];
        vector<NguyenLieu> nguyenLieuMon = monChon.getIngredient();
        int soMonToiDa = KHONG_GIOI_HAN;
        int chenhLech = 0; // So lan nguyen lieu trong kho voi nguyen lieu yeu cau trong menu
        int chonMonKhac = 0;
        int timThayNguyenLieu = 0;
        for(int i = 0; i < nguyenLieuMon.size(); i++) {
            int timNguyenLieu = 0;
            timThayNguyenLieu = 0;
            for(int j = 0; j < soNguyenLieuKho; j++) {
                if(monChon.getIngredient()[i].getName() == kho.layDanhSachMang()[j].getName()) {
                    timThayNguyenLieu = 1;
                    chenhLech = (int) (kho.layDanhSachMang()[j].getQuantity() / monChon.getIngredient()[i].getQuantity());
                    if(chenhLech == 0) {
                        chonMonKhac = 1;
                        break;
                    } else if(soMonToiDa > chenhLech) {
                        soMonToiDa = chenhLech;
                        break;
                    }
                }
            }
        }
        if(chonMonKhac == 1 || timThayNguyenLieu == -1) {
            cout << "So nguyen lieu trong kho hien tai khong the lam mon nay. Vui long chon mon khac.\n";
            continue;
        }

        int soMonChon = 0;
        do {
            cout << "Chi co the order " << soMonToiDa << " mon " << monChon.getName() << " Nhap '0' de order mon khac.\n";
            cout << "Nhap so luong cho mon " << monChon.getName() << ": ";
            saferScanf("%d", &soMonChon);
        } while(soMonChon < 0 || soMonChon > soMonToiDa);
        if(soMonChon == 0) {
            continue;
        }

        // Dam bao lua chon mon nhu nhau se duoc cong don, chu khong phai la tung lua chon rieng le
        int coMat = 0;
        if(hoaDon.getSoMonGoi() == 0) {
            hoaDon.getRefTenMon().push_back(monChon.getName());
            hoaDon.getRefGiaMoiMon().push_back(monChon.getPrice());
            hoaDon.getRefSoMoiMon().push_back(soMonChon);
            hoaDon.setSoMonGoi(hoaDon.getSoMonGoi() + 1);
        } else {
            for(int i = 0; i < hoaDon.getSoMonGoi(); i++) {
                if(hoaDon.getTenMon()[i] == monChon.getName()) {
                    hoaDon.getRefSoMoiMon()[i] += soMonChon;
                    coMat = 1;
                    break;
                }
            }
            if(coMat == 0) {
                hoaDon.getRefTenMon().push_back(monChon.getName());
                hoaDon.getRefGiaMoiMon().push_back(monChon.getPrice());
                hoaDon.getRefSoMoiMon().push_back(soMonChon);
                hoaDon.setSoMonGoi(hoaDon.getSoMonGoi() + 1);
            }
        }
        hoaDon.getRefTongTien() += soMonChon * monChon.getPrice();
        for(int i = 0; i < nguyenLieuMon.size(); i++) {
            kho.truNguyenLieuMang(monChon.getIngredient()[i], soMonChon * monChon.getIngredient()[i].getQuantity());
            hoaDon.getRefTienNguyenLieu() += monChon.getIngredient()[i].getPrice() * soMonChon;
        }
    }
    
    oss << "\nTong tien thanh toan: " << fixed << setprecision(2) << hoaDon.getTongTien() << "\n";
    cout << oss.str();
    oss.clear();

    // Lua chon su dung diem de giam gia
    int coSuDungDiem = 0;
    float diemTichLuySuDung = 0, gioiHanDiem = 0;
    if(hoaDon.getTongTien() > khach.getPoint()) {
        gioiHanDiem = khach.getPoint();
    } else {
        gioiHanDiem = hoaDon.getTongTien() / 100;
    }

    cout << "Su dung diem tich luy de duoc giam gia? (1 - co) ";
    saferScanf("%d", &coSuDungDiem);
    if(coSuDungDiem == 1) {
        do {
            cout << "Nhap so diem ban muon su dung.\n";
            oss << "So diem khong duoc am va khong qua " << fixed << setprecision(2) << gioiHanDiem << ".\n";
            cout << oss.str();
            oss.clear();
            cout << "Nhap so diem: ";
            saferScanf("%f", &diemTichLuySuDung);
        } while(diemTichLuySuDung < 0 || diemTichLuySuDung > gioiHanDiem);

        khach.setPoint(khach.getPoint() - diemTichLuySuDung);
        hoaDon.getRefTongTien() -= diemTichLuySuDung; 

        oss << "So diem tich luy con lai: " << fixed << setprecision(2) << khach.getPoint() << "\n"
            << "So tien can thanh toan da duoc giam con: " << hoaDon.getTongTien() << "\n";
    }

    // Tich luy diem cho khach hang
    khach.setPoint(khach.getPoint() + (hoaDon.getTongTien() / 10));
    oss << "So diem tich luy cua khach hang: " << fixed << setprecision(2) << khach.getPoint() << "\n";
    cout << oss.str();
    oss.clear();

    float tienKhachDua, tienThua;
    do {
        cout << "Nhap so tien khach dua: ";
        saferScanf("%f", &tienKhachDua);
        tienThua = tienKhachDua - hoaDon.getTongTien();
    } while (tienThua < 0);
    hoaDon.setTienThua(tienThua);
    oss << "Tien thua: " << fixed << setprecision(2) << tienThua << "\n";
    cout << oss.str();
    oss.clear();

    hoaDon.setKhach(khach);
    hoaDon.setNgay(ngay);

    int coHoaDon = dsHoaDon.timPhanTu(dsHoaDon.layDanhSachMang(), hoaDon);
    if(coHoaDon != -1) {
        cout << "Hoa don da co trong mang\n";
    } else {
        dsHoaDon.layDanhSachMangRef().push_back(hoaDon);
        cout << "Hoa don da duoc them vao mang\n";
    }

    int coKhach = dsKhach.timPhanTu(dsKhach.layDanhSachMang(), khach);
    if(coKhach == -1) {
        dsKhach.layDanhSachMangRef().push_back(khach);
    }
}
