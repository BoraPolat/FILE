#define MAX_SATIR 1000

char *satirlar[MAX_SATIR];
int satir_sayisi = 0;

char buffer[MAX_LINE];
while (fgets(buffer, MAX_LINE, fp_in)) {
    satirlar[satir_sayisi] = strdup(buffer);
    satir_sayisi++;
}

// sıralama (bubble sort)
for (int i = 0; i < satir_sayisi - 1; i++) {
    for (int j = 0; j < satir_sayisi - i - 1; j++) {
        if (strcmp(satirlar[j], satirlar[j+1]) > 0) {
            char *tmp = satirlar[j];
            satirlar[j] = satirlar[j+1];
            satirlar[j+1] = tmp;
        }
    }
}

// çıktıya yaz
for (int i = 0; i < satir_sayisi; i++) {
    fprintf(fp_out, "%s", satirlar[i]);
    free(satirlar[i]); // belleği temizle
}
