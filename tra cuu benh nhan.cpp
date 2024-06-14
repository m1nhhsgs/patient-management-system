#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATIENTS 100
#define MAX_NAME_LEN 100
#define MAX_ADDR_LEN 200
#define MAX_PHONE_LEN 15
#define MAX_DIAG_LEN 200
#define MAX_DRUGS 10

typedef struct {
    int ma_benh_nhan;
    char ten[MAX_NAME_LEN];
    int tuoi;
    char ngay_sinh[MAX_NAME_LEN];
    char gioi_tinh[MAX_NAME_LEN];
    char dia_chi[MAX_ADDR_LEN];
    char sdt[MAX_PHONE_LEN];
    char ten_nguoi_nha[MAX_NAME_LEN];
    char dia_chi_nguoi_nha[MAX_ADDR_LEN];
    char sdt_nguoi_nha[MAX_PHONE_LEN];
    int doi_tuong_bhyt; // 1: Yes, 0: No
    char han_sd_bhyt[MAX_NAME_LEN];
    char so_the_bhyt[MAX_NAME_LEN];
    int trang_thai; // 1: Nhap vien, 0: Khong nhap vien
    char ten_khoa[MAX_NAME_LEN];
    char so_phong[MAX_NAME_LEN];

    char ly_do_vao_vien[MAX_DIAG_LEN];
    char qua_trinh_benh_ly[MAX_DIAG_LEN];
    char tien_su_benh[MAX_DIAG_LEN];
    char di_ung[MAX_DIAG_LEN];
    char tien_su_ban_than[MAX_DIAG_LEN];
    char tien_su_gia_dinh[MAX_DIAG_LEN];
    char tinh_trang_toan_than[MAX_DIAG_LEN];
    char tinh_trang_dau[MAX_DIAG_LEN];
    char ket_qua_xet_nghiem[MAX_DIAG_LEN];
    char chan_doan_chinh[MAX_DIAG_LEN];
    char chan_doan_kem_theo[MAX_DIAG_LEN];
    char thuoc_can_uong[MAX_DRUGS][MAX_NAME_LEN];
    char lieu_luong[MAX_DRUGS][MAX_NAME_LEN];
    char thoi_gian_uong[MAX_DRUGS][MAX_NAME_LEN];

} BenhNhan;

BenhNhan danh_sach[MAX_PATIENTS];
int so_luong_benh_nhan = 0;

void them_benh_nhan() {
    if (so_luong_benh_nhan >= MAX_PATIENTS) {
        printf("Danh sach benh nhan da day.\n");
        return;
    }

    BenhNhan bn;
    printf("Nhap ma benh nhan: ");
    scanf("%d", &bn.ma_benh_nhan);
    printf("Nhap ten: ");
    scanf(" %[^\n]%*c", bn.ten); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap tuoi: ");
    scanf("%d", &bn.tuoi);
    printf("Nhap ngay sinh: ");
    scanf(" %[^\n]%*c", bn.ngay_sinh); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap gioi tinh (Male/Female/Other): ");
    scanf(" %[^\n]%*c", bn.gioi_tinh); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap dia chi: ");
    scanf(" %[^\n]%*c", bn.dia_chi); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap so dien thoai: ");
    scanf(" %[^\n]%*c", bn.sdt); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap ten nguoi nha: ");
    scanf(" %[^\n]%*c", bn.ten_nguoi_nha); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap dia chi nguoi nha: ");
    scanf(" %[^\n]%*c", bn.dia_chi_nguoi_nha); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap so dien thoai nguoi nha: ");
    scanf(" %[^\n]%*c", bn.sdt_nguoi_nha); // Ð?c chu?i có kho?ng tr?ng
    printf("Doi tuong BHYT (1: Yes, 0: No): ");
    scanf("%d", &bn.doi_tuong_bhyt);
    if (bn.doi_tuong_bhyt) {
        printf("Nhap han su dung BHYT: ");
        scanf(" %[^\n]%*c", bn.han_sd_bhyt); // Ð?c chu?i có kho?ng tr?ng
        printf("Nhap so the BHYT: ");
        scanf(" %[^\n]%*c", bn.so_the_bhyt); // Ð?c chu?i có kho?ng tr?ng
    }
    printf("Trang thai (1: Nhap vien, 0: Khong nhap vien): ");
    scanf("%d", &bn.trang_thai);
    if (bn.trang_thai) {
        printf("Nhap ten Khoa: ");
        scanf(" %[^\n]%*c", bn.ten_khoa); // Ð?c chu?i có kho?ng tr?ng
        printf("Nhap so phong: ");
        scanf(" %[^\n]%*c", bn.so_phong); // Ð?c chu?i có kho?ng tr?ng
    }
    printf("Nhap ly do vao vien: ");
    scanf(" %[^\n]%*c", bn.ly_do_vao_vien); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap qua trinh benh ly: ");
    scanf(" %[^\n]%*c", bn.qua_trinh_benh_ly); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap tien su benh: ");
    scanf(" %[^\n]%*c", bn.tien_su_benh); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap di ung: ");
    scanf(" %[^\n]%*c", bn.di_ung); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap tien su ban than: ");
    scanf(" %[^\n]%*c", bn.tien_su_ban_than); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap tien su gia dinh: ");
    scanf(" %[^\n]%*c", bn.tien_su_gia_dinh); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap tinh trang toan than: ");
    scanf(" %[^\n]%*c", bn.tinh_trang_toan_than); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap tinh trang dau: ");
    scanf(" %[^\n]%*c", bn.tinh_trang_dau); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap ket qua xet nghiem: ");
    scanf(" %[^\n]%*c", bn.ket_qua_xet_nghiem); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap chan doan chinh: ");
    scanf(" %[^\n]%*c", bn.chan_doan_chinh); // Ð?c chu?i có kho?ng tr?ng
    printf("Nhap chan doan kem theo: ");
    scanf(" %[^\n]%*c", bn.chan_doan_kem_theo); // Ð?c chu?i có kho?ng tr?ng

    for (int i = 0; i < MAX_DRUGS; i++) {
        printf("Nhap ten thuoc can uong (nhap 'none' de ket thuc): ");
        scanf(" %[^\n]%*c", bn.thuoc_can_uong[i]); // Ð?c chu?i có kho?ng tr?ng
        if (strcmp(bn.thuoc_can_uong[i], "none") == 0) {
            bn.thuoc_can_uong[i][0] = '\0'; // Ðánh d?u k?t thúc
            break;
        }
        printf("Nhap lieu luong: ");
        scanf(" %[^\n]%*c", bn.lieu_luong[i]); // Ð?c chu?i có kho?ng tr?ng
        printf("Nhap thoi gian uong: ");
        scanf(" %[^\n]%*c", bn.thoi_gian_uong[i]); // Ð?c chu?i có kho?ng tr?ng
    }

    danh_sach[so_luong_benh_nhan++] = bn;
}

void hien_thi_benh_nhan(BenhNhan bn) {
    printf("Ma benh nhan: %d\n", bn.ma_benh_nhan);
    printf("Ten: %s\n", bn.ten);
    printf("Tuoi: %d\n", bn.tuoi);
    printf("Ngay sinh: %s\n", bn.ngay_sinh);
    printf("Gioi tinh: %s\n", bn.gioi_tinh);
    printf("Dia chi: %s\n", bn.dia_chi);
    printf("So dien thoai: %s\n", bn.sdt);
    printf("Ten nguoi nha: %s\n", bn.ten_nguoi_nha);
    printf("Dia chi nguoi nha: %s\n", bn.dia_chi_nguoi_nha);
    printf("So dien thoai nguoi nha: %s\n", bn.sdt_nguoi_nha);
    printf("Doi tuong BHYT: %s\n", bn.doi_tuong_bhyt ? "Yes" : "No");
    if (bn.doi_tuong_bhyt) {
        printf("Han su dung BHYT: %s\n", bn.han_sd_bhyt);
        printf("So the BHYT: %s\n", bn.so_the_bhyt);
    }
    printf("Trang thai: %s\n", bn.trang_thai ? "Nhap vien" : "Khong nhap vien");
    if (bn.trang_thai) {
        printf("Ten Khoa: %s\n", bn.ten_khoa);
        printf("So phong: %s\n", bn.so_phong);
    }
    printf("Ly do vao vien: %s\n", bn.ly_do_vao_vien);
    printf("Qua trinh benh ly: %s\n", bn.qua_trinh_benh_ly);
    printf("Tien su benh: %s\n", bn.tien_su_benh);
    printf("Di ung: %s\n", bn.di_ung);
    printf("Tien su ban than: %s\n", bn.tien_su_ban_than);
    printf("Tien su gia dinh: %s\n", bn.tien_su_gia_dinh);
    printf("Tinh trang toan than: %s\n", bn.tinh_trang_toan_than);
    printf("Tinh trang dau: %s\n", bn.tinh_trang_dau);
    printf("Ket qua xet nghiem: %s\n", bn.ket_qua_xet_nghiem);
    printf("Chan doan chinh: %s\n", bn.chan_doan_chinh);
    printf("Chan doan kem theo: %s\n", bn.chan_doan_kem_theo);

    for (int i = 0; i < MAX_DRUGS && bn.thuoc_can_uong[i][0] != '\0'; i++) {
        printf("Thuoc can uong %d: %s\n", i + 1, bn.thuoc_can_uong[i]);
        printf("Lieu luong: %s\n", bn.lieu_luong[i]);
        printf("Thoi gian uong: %s\n", bn.thoi_gian_uong[i]);
    }
}

int tim_kiem_benh_nhan(int ma_benh_nhan) {
    for (int i = 0; i < so_luong_benh_nhan; i++) {
        if (danh_sach[i].ma_benh_nhan == ma_benh_nhan) {
            return i;
        }
    }
    return -1;
}

void xoa_benh_nhan(int ma_benh_nhan) {
    int index = tim_kiem_benh_nhan(ma_benh_nhan);
    if (index != -1) {
        for (int i = index; i < so_luong_benh_nhan - 1; i++) {
            danh_sach[i] = danh_sach[i + 1];
        }
        so_luong_benh_nhan--;
        printf("Da xoa benh nhan.\n");
    } else {
        printf("Khong tim thay benh nhan.\n");
    }
}

void sua_thong_tin_benh_nhan(int ma_benh_nhan) {
    int index = tim_kiem_benh_nhan(ma_benh_nhan);
    if (index != -1) {
        printf("Nhap thong tin moi cho benh nhan (de trong neu khong sua):\n");
        char input[MAX_NAME_LEN];

        printf("Nhap ten moi: ");
        scanf(" %[^\n]%*c", input); // Ð?c chu?i có kho?ng tr?ng
        if (strcmp(input, "") != 0) {
            strcpy(danh_sach[index].ten, input);
        }

        printf("Nhap tuoi moi: ");
        int tuoi;
        scanf("%d", &tuoi);
        if (tuoi > 0) {
            danh_sach[index].tuoi = tuoi;
        }

        // Tuong t? nh?p các thông tin khác...

    } else {
        printf("Khong tim thay benh nhan.\n");
    }
}

int main() {
    int ma_benh_nhan;
    int index; // Khai báo bi?n index ngoài switch
    int choice;

    while (1) {
        printf("Nhap ma benh nhan: ");
        scanf("%d", &ma_benh_nhan);
        index = tim_kiem_benh_nhan(ma_benh_nhan); // S? d?ng bi?n index khai báo bên ngoài
        if (index != -1) {
            printf("Ma benh nhan hop le.\n");
            hien_thi_benh_nhan(danh_sach[index]);
            printf("Chon chuc nang:\n");
            printf("1. Sua thong tin benh nhan\n");
            printf("2. Xoa benh nhan\n");
            printf("3. Tim kiem benh nhan khac\n");
            printf("Nhap lua chon cua ban: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    sua_thong_tin_benh_nhan(ma_benh_nhan);
                    break;
                case 2:
                    xoa_benh_nhan(ma_benh_nhan);
                    break;
                case 3:
                    continue;
                default:
                    printf("Lua chon khong hop le.\n");
                    break;
            }
        } else {
            printf("Khong tim thay benh nhan.\n");
        }
    }

    return 0;
}

