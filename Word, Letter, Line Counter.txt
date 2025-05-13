int karakterSay = 0, kelimeSay = 0, satirSay = 0;
char c, onceki = ' ';

while ((c = fgetc(fp_in)) != EOF) {
    karakterSay++;
    if (c == '\n') satirSay++;
    if ((onceki == ' ' || onceki == '\n' || onceki == '\t') && (c != ' ' && c != '\n' && c != '\t')) {
        kelimeSay++;
    }
    onceki = c;
}
fprintf(fp_out, "Karakter: %d\nKelime: %d\nSatır: %d\n", karakterSay, kelimeSay, satirSay);
