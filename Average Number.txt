int toplam = 0, adet = 0, sayi;
while (fscanf(fp_in, "%d", &sayi) == 1) {
    toplam += sayi;
    adet++;
}
if (adet > 0)
    fprintf(fp_out, "Ortalama: %.2f\n", (float)toplam / adet);
else
    fprintf(fp_out, "Sayı bulunamadı\n");
