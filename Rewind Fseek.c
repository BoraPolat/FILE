// fseek fonksiyonu dosya içinde istenilen konuma gitmek için kullanılır.
// Söz dizimi:
// int fseek(FILE *stream, long offset, int origin);

// 3. parametre olan 'origin' kısmına şu sabitler gelir:

// SEEK_SET : Dosyanın başından itibaren offset kadar ileri git.
// SEEK_CUR : Mevcut konumdan itibaren offset kadar ileri veya geri git.
// SEEK_END : Dosyanın sonundan itibaren offset kadar geri git.

// offset pozitif veya negatif olabilir:
// - SEEK_SET ile negatif offset kullanmak hataya yol açar.
// - SEEK_CUR ve SEEK_END ile negatif offset kullanmak geçerlidir.

// Örnekler:
// fseek(fp, 10, SEEK_SET);   // Dosyanın başından 10 bayt ileri
// fseek(fp, 5, SEEK_CUR);    // Mevcut konumdan 5 bayt ileri
// fseek(fp, -20, SEEK_END);  // Dosyanın sonundan 20 bayt geri

// rewind(FILE *stream);
// Dosyanın konumunu başa alır. fseek(fp, 0, SEEK_SET) ile aynı işlevi görür.

// ftell(FILE *stream);
// Dosya göstericisinin (okuma/yazma konumunun) bulunduğu bayt konumunu verir (long tipinde).

// fread(void *ptr, size_t size, size_t count, FILE *stream);
// Dosyadan ikili (binary) veri okur. 'count' kadar öğeyi, her biri 'size' kadar olacak şekilde okur.
// Genellikle yapılarla veya byte-by-byte okumalarda kullanılır.

// fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
// Dosyaya ikili veri yazar. 'count' adet öğeyi, her biri 'size' kadar olacak şekilde dosyaya yazar.

// fseek(FILE *stream, long offset, int origin);
// Dosya içinde konumu ayarlar. origin: SEEK_SET, SEEK_CUR, SEEK_END

// feof(FILE *stream);
// Dosya sonuna gelinip gelinmediğini kontrol eder. 1 dönerse EOF, 0 ise devam edilebilir.

// ferror(FILE *stream);
// Dosya işlemlerinde hata oluşup oluşmadığını kontrol eder.

// clearerr(FILE *stream);
// feof ve ferror tarafından ayarlanan hata/sınır durumlarını sıfırlar.

// fflush(FILE *stream);
// Yazma tamponunu zorla dosyaya boşaltır. Genelde dosya yazarken verilerin hemen diske gitmesi için kullanılır.

// ungetc(int ch, FILE *stream);
// Okuma sırasında son okunan karakteri geri iade eder (geri koyar). Sadece bir karakter geri koyulabilir.
