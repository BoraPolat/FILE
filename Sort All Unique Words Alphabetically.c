int compare(const void a, const void b) {
    return strcmp((const char)a, (const char)b);
}

 Yukarıdaki kodla birlikte toplanan kelimeleri
qsort(kelimeler, sayi, sizeof(Kelime), compare);
for (int i = 0; i  sayi; i++) {
    fprintf(out, %sn, kelimeler[i].kelime);
}
