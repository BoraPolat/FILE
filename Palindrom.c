int palindrom_mu(const char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (tolower(str[i]) != tolower(str[j])) return 0;
        i++; j--;
    }
    return 1;
}

rewind(fp);
while (fgets(satir, sizeof(satir), fp)) {
    satir[strcspn(satir, "\n")] = 0; // \n kaldır
    if (palindrom_mu(satir)) {
        fprintf(out, "Palindrom: %s\n", satir);
