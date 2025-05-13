char en_uzun[MAX_LEN] = ;
rewind(fp);
while (fscanf(fp, %99s, kelime) == 1) {
    if (strlen(kelime)  strlen(en_uzun)) {
        strcpy(en_uzun, kelime);
    }
}
fprintf(out, En uzun kelime %sn, en_uzun);
