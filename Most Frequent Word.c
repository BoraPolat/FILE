#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KELIME 1000
#define MAX_LEN 100

typedef struct {
    char kelime[MAX_LEN];
    int sayac;
} Kelime;

int kelime_var_mi(Kelime* dizi, int boyut, const char* aranacak) {
    for (int i = 0; i < boyut; i++) {
        if (strcmp(dizi[i].kelime, aranacak) == 0) return i;
    }
    return -1;
}

void kucuk_harfe_cevir(char* str) {
    for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
}

int main() {
    FILE *fp = fopen("girdi.txt", "r");
    FILE *out = fopen("cikti.txt", "w");
    char kelime[MAX_LEN];
    Kelime kelimeler[MAX_KELIME];
    int sayi = 0;

    while (fscanf(fp, "%99s", kelime) == 1) {
        kucuk_harfe_cevir(kelime);
        // noktalama temizle
        int len = strlen(kelime);
        if (ispunct(kelime[len-1])) kelime[len-1] = '\0';

        int index = kelime_var_mi(kelimeler, sayi, kelime);
        if (index == -1) {
            strcpy(kelimeler[sayi].kelime, kelime);
            kelimeler[sayi].sayac = 1;
            sayi++;
        } else {
            kelimeler[index].sayac++;
        }
    }

    // en sık geçen kelime
    int max = 0;
    for (int i = 1; i < sayi; i++) {
        if (kelimeler[i].sayac > kelimeler[max].sayac) max = i;
    }

    fprintf(out, "En sık geçen kelime: %s (%d kez)\n", kelimeler[max].kelime, kelimeler[max].sayac);
    fclose(fp);
    fclose(out);
    return 0;
}
