int harf_sayilari[256] = {0};

int anagram_mi(const char* a, const char* b) {
    if (strlen(a) != strlen(b)) return 0;
    for (int i = 0; a[i]; i++) harf_sayilari[(unsigned char)a[i]]++;
    for (int i = 0; b[i]; i++) harf_sayilari[(unsigned char)b[i]]--;
    for (int i = 0; i < 256; i++) {
        if (harf_sayilari[i] != 0) return 0;
    }
    return 1;
}
