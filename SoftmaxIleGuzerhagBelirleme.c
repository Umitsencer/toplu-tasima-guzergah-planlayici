#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Mahalle yapısı
struct Mahalle {
    char *isim;
    double nufusYogunlugu;
    double mevcutUlasimAltyapisi;
    double maliyetAnalizi;
    double cevreselEtki;
    double sosyalFayda;
    double softmaxDegeri; // Softmax sonucu
};

// Kriter ağırlıkları
#define AGIRLIK_NUFUS 0.4
#define AGIRLIK_ULASIM 0.2
#define AGIRLIK_MALIYET 0.1
#define AGIRLIK_CEVRE 0.15
#define AGIRLIK_FAYDA 0.15

// Softmax fonksiyonu
void softmax(const double *degerler, double *sonuclar, int boyut) {
    double toplam = 0.0;
    double max_deger = degerler[0];

    // Maksimum değeri bul
    for (int i = 1; i < boyut; i++) {
        if (degerler[i] > max_deger) {
            max_deger = degerler[i];
        }
    }

    // Exponential hesaplama
    for (int i = 0; i < boyut; i++) {
        sonuclar[i] = exp(degerler[i] - max_deger);
        toplam += sonuclar[i];
    }

    // Normalizasyon
    for (int i = 0; i < boyut; i++) {
        sonuclar[i] /= toplam;
    }
}

// Mahalleleri Softmax değerine göre sıralamak için karşılaştırma fonksiyonu
int karsilastir(const void *a, const void *b) {
    double oranA = ((struct Mahalle *)a)->softmaxDegeri;
    double oranB = ((struct Mahalle *)b)->softmaxDegeri;
    return (oranB > oranA) - (oranA > oranB); // Azalan sırada
}

// Güzergah planlama fonksiyonu
void guzergahPlanlama(struct Mahalle *mahalleler, int boyut) {
    double *kriterler = (double *)malloc(boyut * sizeof(double));
    double *softmaxSonuclari = (double *)malloc(boyut * sizeof(double));

    if (!kriterler || !softmaxSonuclari) {
        printf("Bellek tahsis hatası!\n");
        free(kriterler);
        free(softmaxSonuclari);
        return;
    }

    // Ağırlıklı kriter toplamlarını hesapla
    for (int i = 0; i < boyut; i++) {
        kriterler[i] = (mahalleler[i].nufusYogunlugu * AGIRLIK_NUFUS) +
                       (mahalleler[i].mevcutUlasimAltyapisi * AGIRLIK_ULASIM) +
                       (mahalleler[i].maliyetAnalizi * AGIRLIK_MALIYET) +
                       (mahalleler[i].cevreselEtki * AGIRLIK_CEVRE) +
                       (mahalleler[i].sosyalFayda * AGIRLIK_FAYDA);
    }

    // Softmax fonksiyonunu uygula
    softmax(kriterler, softmaxSonuclari, boyut);

    // Softmax değerlerini mahallelere ata
    for (int i = 0; i < boyut; i++) {
        mahalleler[i].softmaxDegeri = softmaxSonuclari[i];
    }

    // Softmax değerlerine göre sıralama yap
    qsort(mahalleler, boyut, sizeof(struct Mahalle), karsilastir);

    // Çıktılar
    printf("\nKırklareli'nin mahalleleri için toplu taşıma hattı uygunluk oranları (Softmax sonuçları):\n");
    for (int i = 0; i < boyut; i++) {
        printf("%s: %.6f\n", mahalleler[i].isim, mahalleler[i].softmaxDegeri);
    }

    printf("\nÖnerilen toplu taşıma güzergahı (Softmax'e göre en uygun sırayla):\n");
    for (int i = 0; i < boyut; i++) {
        printf("%d. %s (Uygunluk: %.6f)\n", i + 1, mahalleler[i].isim, mahalleler[i].softmaxDegeri);
    }

    // Belleği serbest bırak
    free(kriterler);
    free(softmaxSonuclari);
}

int main() {
    struct Mahalle mahalleler[3] = {
        {"Karakaş", 1.2, 1.5, 2.0, 0.8, 1.3, 0.0},
        {"İstasyon", 0.9, 1.2, 1.5, 1.0, 1.1, 0.0},
        {"Demirtaş", 1.5, 1.0, 1.8, 1.2, 1.5, 0.0}
    };

    guzergahPlanlama(mahalleler, 3);

    return 0;
}  