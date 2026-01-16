#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
 * C de integer türleri ;
 * - char : 1 byte
 * - short : 2 byte
 * - int : 4 byte
 * - long : 4/8 byte
 * - long long : 8 byte
 */

/*
 * C de float türleri ; ---> bu türler ile sabit olmayan değerler de tutulabilir (pi sayısı gibi)
 * - float : düşük hassasiyet
 * - double : orta
 * - long double : yüksek
 */

// char : aslında ASCII kodunda bir integer tutar ama tek karakter de tutabilir, Tek tırnak arasında kullanılır
// bool : c99 ile geldi ve true - false tutar
// struct : birden fazla değişkeni tek bir yerde toplar


// Aynı isimde 2. bi fonk  tanımlanamaz !!!
int topla(int a, int b) {
    return a + b;
}


struct human {
    int boy;
    int kilo;
    char name[20];
};

#define isim "mehmet"  // global olarak kullanılabilir değişken , "macro" denir bu türlere


// giris_ornekler.c
#include "Ortaklar.h"

void print();
int toplama(int a, int b);




void print_binary(unsigned int x) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (x >> i) & 1); // x değerini i kadar sağa ötele ve 1 ile AND le, yani sondaki değer 1 ise 1 , 0 ise 0 yazdırılır
    }
}

int main(void) {

    // Postfix - Prefix
    int x = 10;
    int y = x++;    // bu tür postfix ile önce eski x değeri y ye atanır, sonra x değeri arttırılır
    printf("Postfix: %d\n", y);

    y = ++x;        // burada ise önce x değeri attırılır, sonra yeni x değeri y ye atanır
    printf("Prefix: %d\n", y);




    // Bitwise işlemleri
    // bitler üzerinde işlemler yapılırken unsigned int kullanılır , nedeni ise sayının en sonundaki işaret bitinin kaydırma
    // işlemlerinde hatalı sonuçlara yol açabilmesidir

    // AND - OR - XOR
    unsigned int a = 0x77;
    unsigned int b = 0x3;

    printf(" a: ");
    print_binary(a);

    printf("\n b: ");
    print_binary(b);
    printf("\nİşlemler : \n");

    unsigned int and = a & b;       // 0 varsa 0 olur
    unsigned int or = a | b;        // 1 varsa 1 olur
    unsigned int xor = a ^ b;       // aynı olanlar 0, farklı olanlar 1
    unsigned int shift_left = a << 2;   // bitleri sola 2 birim öteleme
    unsigned int shift_right = a >> 2;  // bitleri sağa 2 birim öteleme, yeni bitler 0 olur

    printf(" AND : ");
    print_binary(and);

    printf("\n OR  : ");
    print_binary(or);

    printf("\n XOR : ");
    print_binary(xor);

    printf("\n SHIFT LEFT : ");
    print_binary(shift_left);

    printf("\n SHIFT RIGHT : ");
    print_binary(shift_right);
    printf("\n");


    printf("Başka dosyadaki fonksiyon çıktısı: %d\n", toplama(10, 10));
    print();

    // Struct Örneği
    Home myHome; // yeni bir struct ortak kullanımı için .h dosyası oluşturulmalıdır(header)
    myHome.windows = 10;
    myHome.doors = 4;
    printf("My Home has %d doors, %d windows\n", myHome.doors, myHome.windows);


    // Union Örneği
    Veri myVeri;
    myVeri.a = 'a';
    myVeri.b = 100;
    strcpy(myVeri.c, "Deneme 123");


    printf("Size of a : %lu\n", sizeof(myVeri.a));
    printf("Size of b : %lu\n", sizeof(myVeri.b));
    printf("Size of c : %lu\n", sizeof(myVeri.c));

    printf("a: %c\n", myVeri.a); // en büyük değişken b olduğu için onun değerini tutar
    printf("b: %d\n", myVeri.b);
    printf("c: %s\n", myVeri.c);


    printf("%s\n", isim);

    int aa = 100;
    char bb = 66; // %d ile sayı olarak yazar, %c ile ASCII karakterini yazar
    char character = 'A'; // %c ile A yazar, %d ile ASCII değerini yazar
    float cc = 3.1f;
    double dd = 3.14;

    printf("%d\n", aa);
    printf("%c\n", bb);
    printf("%c\n", character);
    printf("%f\n", cc);
    printf("%f\n", dd);

    int c = topla(10, 10);
    printf("%d\n", c);

    struct human emirhan = {170, 80, "Emirhan Dora"}; // Tek satırda struct oluşturma
    printf("İsim :%s\n", emirhan.name);
    printf("Boy :%d\n", emirhan.boy);
    printf("Kilo: %d\n", emirhan.kilo);

    printf("-----------\n");

    struct human mehmet; // Çok satırda struct oluşturma
    mehmet.boy = 100;
    mehmet.kilo = 66;
    strcpy(mehmet.name, "Mehmet Dora");
    printf("İsim :%s\n", mehmet.name);
    printf("Boy :%d\n", mehmet.boy);
    printf("Kilo: %d\n", mehmet.kilo);

    return 0;
}



