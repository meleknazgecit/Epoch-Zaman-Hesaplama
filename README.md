# Web Sitesinde Geçirilen Süreyi Hesaplama

Bu proje, bir web sitesinde geçirilen süreyi hesaplamak için C programlama dili kullanılarak geliştirilmiştir. Program, kullanıcının web sitesine giriş ve çıkış tarihlerini alır ve bu iki tarih arasındaki süreyi hesaplayarak ekrana yazdırır.

## Özellikler

- Kullanıcıdan web sitesine giriş ve çıkış tarihlerini alır.
- Girilen tarihleri epoch zamanına çevirir.
- İki tarih arasındaki süreyi hesaplar.
- Hesaplanan süreyi gün, saat, dakika ve saniye cinsinden ekrana yazdırır.

## Nasıl Çalışır?

1. **Tarih Girişi:** Kullanıcıdan web sitesine giriş ve çıkış tarihleri istenir. Tarihler `yil`, `ay`, `gun`, `saat`, `dakika` ve `saniye` olarak ayrı ayrı girilir.

2. **Epoch Zamanına Çevirme:** Girilen tarihler, `mktime()` fonksiyonu kullanılarak epoch zamanına (1 Ocak 1970'ten itibaren geçen saniye sayısı) çevrilir.

3. **Zaman Farkı Hesaplama:** İki epoch zamanı arasındaki fark, `difftime()` fonksiyonu ile hesaplanır. Bu fark, gün, saat, dakika ve saniye cinsine dönüştürülür.

4. **Sonuçları Görüntüleme:** Hesaplanan süre, kullanıcıya gün, saat, dakika ve saniye olarak gösterilir.


## Kullanılan Yapılar

- `struct`
- `union`

## Gereksinimler
- `C derleyicisi`
- `time.h kütüphanesi`
