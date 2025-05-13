void temizle(char* str) {
    int i = 0, j = 0;
    int bosluk = 0;

    // Baştaki boşlukları atla
    while (str[i] == ' ') i++;

    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i++];
            bosluk = 0;
        } else {
            if (!bosluk) str[j++] = ' ';
            bosluk = 1;
            i++;
        }
    }
    if (j > 0 && str[j - 1] == ' ') j--; // sondaki boşluk
    str[j] = '\0';
}
