//
// Created by Mehmet Dora on 16.01.2026.
//


// burada define ismi seçimi şu şekilde yapılır ;
// PROJE_KLASOR_DOSYA_H
// bu kodlar Preprocessors directives denir

// buradaki #ifndef kullanımı aslında if not define kontrolü yapar, ilk çalıştırmada değer olmadığı için #define çalışır.
// sonraki çalıştırmalarda tekrar tanımlama olmaz çünkü bir kere tanımlanmıştır ve tekrar struct tanımlanmaz ,
// yani linker/compiler zamanında tekrar tanımlamalar sonucunda hata oluşmasının önüne geçilmiş olunur
#ifndef DERS_1_ORTAKLAR_H
#define DERS_1_ORTAKLAR_H


typedef struct {
    int windows;
    int doors;
} Home;

typedef union {
    char a;
    int b;
    char c[50];
} Veri;

#endif //DERS_1_ORTAKLAR_H
