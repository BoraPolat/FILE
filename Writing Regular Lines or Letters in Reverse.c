void tersCevir(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

// Uygulama
rewind(fp_in);
while (fgets(satir, sizeof(satir), fp_in)) {
    satir[strcspn(satir, "\n")] = 0; // \n kaldır
    tersCevir(satir);
    fprintf(fp_out, "%s\n", satir);
}
