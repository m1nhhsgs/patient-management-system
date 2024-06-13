#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct {
    char ten[30];
    char dia_chi[100];
    char sdt[12];
} Nguoi_nha;

typedef struct
{
    int co_the_bao_hiem;
    char han_su_dung[20];
    char ma_so_the[20];
} Bao_hiem_y_te;

typedef struct
{
    int co_nhap_vien;
    char ten_khoa[50];
    short so_phong;
} Nhap_vien;

typedef struct
{
    char di_ung[200];
    char tien_su_ban_than[200];
    char tien_su_gia_dinh[200];
} Tien_su_benh;

typedef struct
{
    char tinh_trang_toan_than[200];
    char tinh_trang_dau[200];
} Tinh_trang;

typedef struct
{
    char benh_chinh[100];
    char benh_kem_theo[100];
} Chan_doan;


typedef struct
{
    char ten_thuoc[50];
    char lieu_luong[50];
    char thoi_gian_uong[50];
} Thuoc_can_uong;

typedef struct
{
    char ma_benh_nhan[20];
    char ten_benh_nhan[30];
    int tuoi_benh_nhan;
    char ngay_thang_nam_sinh[20];
    char gioi_tinh[10];
    char dia_chi[100];
    char sdt[12];
    Nguoi_nha nguoi_nha;
    Bao_hiem_y_te bao_hiem_y_te;
    Nhap_vien nhap_vien;
    char ly_do_vao_vien[200];
    char qua_trinh_benh_ly[200];
    Tien_su_benh tien_su_benh;
    Tinh_trang tinh_trang;
    char ket_qua_xet_nghiem[200];
    Chan_doan chan_doan;
    Thuoc_can_uong thuoc_can_uong;
} Benh_nhan;

void nhap_thong_tin_benh_nhan(Benh_nhan *benh_nhan) {
    printf("Nhap ma benh nhan: ");
    fgets(benh_nhan->ma_benh_nhan, 15, stdin);
    benh_nhan->ma_benh_nhan[strcspn(benh_nhan->ma_benh_nhan, "\n")] = 0;

    printf("Nhap ten : ");
    fgets(benh_nhan->ten_benh_nhan, 30, stdin);
    benh_nhan->ten_benh_nhan[strcspn(benh_nhan->ten_benh_nhan, "\n")] = 0;

    printf("Nhap tuoi : ");
    scanf("%d", &benh_nhan->tuoi_benh_nhan);
    getchar();

    printf("Nhap ngay thang nam sinh (dd/mm/yyyy): ");
    fgets(benh_nhan->ngay_thang_nam_sinh, 20, stdin);
    benh_nhan->ngay_thang_nam_sinh[strcspn(benh_nhan->ngay_thang_nam_sinh, "\n")] = 0;

    printf("Nhap gioi tinh (Nam/Nu/Khac): ");
    fgets(benh_nhan->gioi_tinh, 10, stdin);
    benh_nhan->gioi_tinh[strcspn(benh_nhan->gioi_tinh, "\n")] = 0;

    printf("Nhap dia chi: ");
    fgets(benh_nhan->dia_chi, 100, stdin);
    benh_nhan->dia_chi[strcspn(benh_nhan->dia_chi, "\n")] = 0;

    printf("Nhap so dien thoai: ");
    fgets(benh_nhan->sdt, 12, stdin);
    benh_nhan->sdt[strcspn(benh_nhan->sdt, "\n")] = 0;

    printf("\n--- Thong tin nguoi nha ---\n");
    printf("Nhap ten nguoi nha: ");
    fgets(benh_nhan->nguoi_nha.ten, 30, stdin);
    benh_nhan->nguoi_nha.ten[strcspn(benh_nhan->nguoi_nha.ten, "\n")] = 0;

    printf("Nhap dia chi nguoi nha: ");
    fgets(benh_nhan->nguoi_nha.dia_chi, 100, stdin);
    benh_nhan->nguoi_nha.dia_chi[strcspn(benh_nhan->nguoi_nha.dia_chi, "\n")] = 0;

    printf("Nhap so dien thoai nguoi nha: ");
    fgets(benh_nhan->nguoi_nha.sdt, 12,stdin);
    benh_nhan->nguoi_nha.sdt[strcspn(benh_nhan->nguoi_nha.sdt, "\n")] = 0;

    printf("\n--- Thong tin bao hiem y te ---\n");
    printf("Co the bao hiem (1 la co, 0 la khong): ");
    scanf("%d", &benh_nhan->bao_hiem_y_te.co_the_bao_hiem);
    getchar();
    if (benh_nhan->bao_hiem_y_te.co_the_bao_hiem) {
        printf("Nhap han su dung cua bao hiem (dd/mm/yyyy): ");
        fgets(benh_nhan->bao_hiem_y_te.han_su_dung, 20,stdin);
        benh_nhan->bao_hiem_y_te.han_su_dung[strcspn(benh_nhan->bao_hiem_y_te.han_su_dung, "\n")] = 0;

        printf("Nhap ma so the bao hiem y te: ");
        fgets(benh_nhan->bao_hiem_y_te.ma_so_the, 20, stdin);
        benh_nhan->bao_hiem_y_te.ma_so_the[strcspn(benh_nhan->bao_hiem_y_te.ma_so_the, "\n")] = 0;
    }

    printf("\n--- Thong tin nhap vien ---\n");
    printf("Da nhap vien chua (1 la roi, 0 la chua): ");
    scanf("%d", &benh_nhan->nhap_vien.co_nhap_vien);
    getchar();
    if (benh_nhan->nhap_vien.co_nhap_vien) {
        printf("Nhap khoa dieu tri: ");
        fgets(benh_nhan->nhap_vien.ten_khoa, 50, stdin);
        benh_nhan->nhap_vien.ten_khoa[strcspn(benh_nhan->nhap_vien.ten_khoa, "\n")] = 0;

        printf("Nhap so phong: ");
        scanf("%d", &benh_nhan->nhap_vien.so_phong);
        getchar();
    }

    printf("\n--- Benh an ---\n");
    printf("Ly do nhap vien: ");
    fgets(benh_nhan->ly_do_vao_vien, 200, stdin);
    benh_nhan->ly_do_vao_vien[strcspn(benh_nhan->ly_do_vao_vien, "\n")] = 0;

    printf("Qua trinh ben ly: ");
    fgets(benh_nhan->qua_trinh_benh_ly, 200, stdin);
    benh_nhan->qua_trinh_benh_ly[strcspn(benh_nhan->qua_trinh_benh_ly, "\n")] = 0;

    printf("Tien su di ung cua benh nhan: ");
    fgets(benh_nhan->tien_su_benh.di_ung, 200, stdin);
    benh_nhan->tien_su_benh.di_ung[strcspn(benh_nhan->tien_su_benh.di_ung, "\n")] = 0;

    printf("Tien su benh cua benh nhan: ");
    fgets(benh_nhan->tien_su_benh.tien_su_ban_than, 200, stdin);
    benh_nhan->tien_su_benh.tien_su_ban_than[strcspn(benh_nhan->tien_su_benh.tien_su_ban_than, "\n")] = 0;

    printf("Tien su benh cua gia dinh ben nhan: ");
    fgets(benh_nhan->tien_su_benh.tien_su_gia_dinh, 200, stdin);
    benh_nhan->tien_su_benh.tien_su_gia_dinh[strcspn(benh_nhan->tien_su_benh.tien_su_gia_dinh, "\n")] = 0;

    printf("Tinh trang co the cua benh nhan: ");
    fgets(benh_nhan->tinh_trang.tinh_trang_toan_than, 200, stdin);
    benh_nhan->tinh_trang.tinh_trang_toan_than[strcspn(benh_nhan->tinh_trang.tinh_trang_toan_than, "\n")] = 0;

    printf("Tinh trang dau cua benh nhan: ");
    fgets(benh_nhan->tinh_trang.tinh_trang_dau, 200, stdin);
    benh_nhan->tinh_trang.tinh_trang_dau[strcspn(benh_nhan->tinh_trang.tinh_trang_dau, "\n")] = 0;

    printf("Ket qua xet nghiem cua benh nhan: ");
    fgets(benh_nhan->ket_qua_xet_nghiem, 200, stdin);
    benh_nhan->ket_qua_xet_nghiem[strcspn(benh_nhan->ket_qua_xet_nghiem, "\n")] = 0;

    printf("Chan doan benh chinh: ");
    fgets(benh_nhan->chan_doan.benh_chinh, 100, stdin);
    benh_nhan->chan_doan.benh_chinh[strcspn(benh_nhan->chan_doan.benh_chinh, "\n")] = 0;

    printf("Chan doan benh kem theo: ");
    fgets(benh_nhan->chan_doan.benh_kem_theo, 100, stdin);
    benh_nhan->chan_doan.benh_kem_theo[strcspn(benh_nhan->chan_doan.benh_kem_theo, "\n")] = 0;

    printf("Ten thuoc can uong: ");
    fgets(benh_nhan->thuoc_can_uong.ten_thuoc, 50, stdin);
    benh_nhan->thuoc_can_uong.ten_thuoc[strcspn(benh_nhan->thuoc_can_uong.ten_thuoc, "\n")] = 0;

    printf("Lieu luong thuoc: ");
    fgets(benh_nhan->thuoc_can_uong.lieu_luong, 50, stdin);
    benh_nhan->thuoc_can_uong.lieu_luong[strcspn(benh_nhan->thuoc_can_uong.lieu_luong, "\n")] = 0;

    printf("Lich uong thuoc: ");
    fgets(benh_nhan->thuoc_can_uong.thoi_gian_uong, 50, stdin);
    benh_nhan->thuoc_can_uong.thoi_gian_uong[strcspn(benh_nhan->thuoc_can_uong.thoi_gian_uong, "\n")] = 0;

}

int main(){
    Benh_nhan benh_nhan;
    nhap_thong_tin_benh_nhan(&benh_nhan);
    return 0;
}
