int sayi, toplam = 0;
while (fscanf(fp_in, "%d", &sayi) == 1) {
    toplam += sayi;
}
fprintf(fp_out, "Toplam: %d\n", toplam);
