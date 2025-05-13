char aranacak[] = "openai";
int sayac = 0;

rewind(fp_in); // önceki okumadan sonra başa dön
while (fgets(satir, sizeof(satir), fp_in)) {
    if (strstr(satir, aranacak)) {
        sayac++;
    }
}
fprintf(fp_out, "'%s' kelimesi %d kez geçti.\n", aranacak, sayac);
