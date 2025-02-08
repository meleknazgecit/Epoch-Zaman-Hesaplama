#include <stdio.h>
#include <time.h>

/* Struct ve union kullanarak bir web sitesinde ge�irilen s�reyi bulmak i�in C program�*/


// Tarihi saklamak i�in:
struct Zaman {
    int yil, ay, gun, saat, dakika, saniye;
};

union Epoch {
    time_t epoch_zamani;
};


// Structtaki tarihi epoch zaman�na �eviren fonksiyon:
time_t tarihi_epoch_yap(struct Zaman zaman) {
    struct tm zaman_bilgisi = {0};

    zaman_bilgisi.tm_year = zaman.yil - 1900;
    zaman_bilgisi.tm_mon  = zaman.ay - 1;
    zaman_bilgisi.tm_mday = zaman.gun;
    zaman_bilgisi.tm_hour = zaman.saat;
    zaman_bilgisi.tm_min  = zaman.dakika;
    zaman_bilgisi.tm_sec  = zaman.saniye;

    return mktime(&zaman_bilgisi);
}

int main() {
    struct Zaman giris, cikis;
    union Epoch epoch_giris, epoch_cikis;

// Kullan�c�dan siteye giri� ve ��k�� bilgileri al�n�r
    printf("Web sitesine giris yaptiginiz tarihi giriniz (yil ay gun saat dakika saniye): ");
    scanf("%d %d %d %d %d %d", &giris.yil, &giris.ay, &giris.gun, &giris.saat, &giris.dakika, &giris.saniye);

    printf("Web sitesinden cikis yaptiginiz tarihi giriniz (yil ay gun saat dakika saniye): ");
    scanf("%d %d %d %d %d %d", &cikis.yil, &cikis.ay, &cikis.gun, &cikis.saat, &cikis.dakika, &cikis.saniye);


// Epoch zaman�na �evrilir
    epoch_giris.epoch_zamani = tarihi_epoch_yap(giris);
    epoch_cikis.epoch_zamani = tarihi_epoch_yap(cikis);

    if (epoch_giris.epoch_zamani == -1 || epoch_cikis.epoch_zamani == -1) {
        printf("Hata: Gecersiz tarih girdiniz. Lutfen tekrar deneyin.\n");
        return 1;
    }

// Zaman fark� hesaplan�r
    double gecen_sure = difftime(epoch_cikis.epoch_zamani, epoch_giris.epoch_zamani);
    
    int gun = gecen_sure / (24 * 3600);
    gecen_sure -= gun * (24 * 3600);

    int saat = gecen_sure / 3600;
    gecen_sure -= saat * 3600;

    int dakika = gecen_sure / 60;
    gecen_sure -= dakika * 60;


// Sonu�lar ekrana yaz�l�r
    printf("\n Web sitesine giris tarihi: %02d/%02d/%04d %02d:%02d:%02d\n", 
           giris.gun, giris.ay, giris.yil, giris.saat, giris.dakika, giris.saniye);

    printf("Web sitesinden cikis tarihi: %02d/%02d/%04d %02d:%02d:%02d\n", 
           cikis.gun, cikis.ay, cikis.yil, cikis.saat, cikis.dakika, cikis.saniye);

    printf("Gecen zaman (epoch): %.0f saniye\n", difftime(epoch_cikis.epoch_zamani, epoch_giris.epoch_zamani));

    printf("Gecen zaman: %d gun, %d saat, %d dakika, %.0f saniye\n", gun, saat, dakika, gecen_sure);

    return 0;
}

