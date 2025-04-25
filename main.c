#include "NSLL.h"

int main() {
    addressKota daftarKota = NULL;
    char namaKota[50], namaOrang[50];
    int pilihan;

    do {
        printf("\n=== MENU MANAJEMEN KOTA & ORANG ===\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Orang ke Kota\n");
        printf("3. Tampilkan Semua Data\n");
        printf("4. Hapus Kota\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar();
        
        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0'; // hapus newline
                insertKota(&daftarKota, namaKota);
                printf("Kota \"%s\" berhasil ditambahkan.\n", namaKota);
                break;

            case 2:
                printf("Masukkan nama kota tujuan: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';

                printf("Masukkan nama orang: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = '\0';

                insertOrang(&daftarKota, namaKota, namaOrang);
                break;

            case 3:
                tampilSemua(daftarKota);
                break;

            case 4:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                deleteKota(&daftarKota, namaKota);
                printf("Kota \"%s\" telah dihapus (beserta semua orang di dalamnya).\n", namaKota);
                break;

            case 0:
                printf("Terima kasih. Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

    } while (pilihan != 0);

    return 0;
}
