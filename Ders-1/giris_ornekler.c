//
// Created by Mehmet Dora on 16.01.2026.
//

#include <stdio.h>

// PREPROCESSORS
/*
 C de preprocessors 'lar kodun içinde dışarıdan alıntılanan kod dosya isimleri üzerinden
 gerekli çağrılan kodları eklerler  '#include MyFuncs.c' gibi bir kullanımda çalışırlar
 */


// Objects
// C dilinde bellekte yer kaplayan ve değeri olan herşeydir, Fonksiyonalar, makrolar(#define) ve türler(int,float) object değildir


float a = 3.13f; // Float sayılar tam hassas değildir -> 0.1 + 0.2 != 0.3

char ab = 'a'; // char kullanımında tek bir değer için '' tırnakları kullanılır
char b[5] = "abc"; // Eğer çoklu karakter olacaksa "" tırnakları kullnılır

// C dilinde ondalıklı sayılar default olarak double olarak varsayılır.
// Eğer suffix kullanılmazsa derleyici bunu önce double olarak üretip sonra float a çeviri arka planda,
// gömülü sistemlerde bellek hassasiyeti için float kullanılabilir
// float c = 3.14   Yani;
// 3.14 --> aslında bir double dır, sonradan arka planda float a çevrilir
// 3.14f ---> kesin olarak bu bir float dır  , sonraki suffix kullannımı ile


// Eğer daha yüksek hassasiyet gerektiren yerler varsa double kullanılır ;
double c = 3.8584958728378;
// printf ile yazdırılırken %.8f ile basılırsa ondalık değerin 8 hanesinin yazıdırılacağı anlanmına gelir bu
// double için suffix gerekmez


// Struct
// birden fazla veriyi toplu bir şekilde anlamlı olarak tutmak için kullnaılır
// Tüm üyeleri ayr ayrı yer kaplar , toplam boyut tüm üyelerin toplamı + alignment dır
struct Home {
    int windows;
    int doors;
};


// Union
// Tüm verileri aynı bellek alanını paylaşır
// Yani a ve b ,tümü aynı adresi kullanır,
// union boyutu ise en büyük boyutlu olan değişkenin boyutu kadardır , yani burada b'dir(char=1 byte, int = 4 byte)
// union un diğer değerler küçük değişkenleri de en büyüğün bellekteki yerini kullanır


void print() {
    printf("%.8f\n", c);
}


int toplama(int a, int b) {
    return a + b;
}


