char c;
int cumleSayisi = 0;

while ((c = fgetc(fp)) != EOF) {
    if (c == '.' || c == '!' || c == '?') cumleSayisi++;
}
fprintf(out, "Cümle sayısı: %d\n", cumleSayisi);
