#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define Val 200 // aşağıda tekrar Val isminde bir değişken daha tanımlanamaz
#define VAL (1.0f / 3.14f)  // İşlemler de eklenebilir



int main(void) {

    printf("dene\ndene\tme\nAlert:\a,\nBackspace:@@\b@@\nTırnak işareti kullanımı \"\"\n");

    int ddd ;
    float fff;
    fff = ddd = 33.3f;
    printf("fff: %.2f\nddd: %d\n\n",fff,ddd);
    // burada değer 33.3 önce int'a çevrildiği için 33 sayısı olur, sonra bu değer float a çevrildiği için 33.0 olur !!!

    int rrr = 1;
    int rrr2 = rrr + (rrr = 1); // 1 = 1 sonucu true(1) olduğundan rrr2 değeri 2 oldu
    printf("rrr: %d, rrr2: %d\n\n",rrr,rrr2);

    int ee = 1;
    int ww = 2;
    int tt = 3;
    tt += ww += ee; // önce ww'ye ee eklendir, sonuç üzerinden tt'ye yeni ww değeri eklenir
    printf("tt: %d, ww: %d\n\n",tt,ww);


    // POSTFİX - PREFIX
    int ss = 1;
    printf("ss: %d\n",ss++);    // ss++ ile önce değeri kullanılır sonra ++ ile değeri arttırılır
    printf("ss: %d\n\n",ss);

    printf("ss: %d\n",++ss);    // ++ss ile önce ss değeri ++ ile arttırılır sonra kullanılır.
    printf("ss: %d\n",ss);

    // c = i * i++ --> undefined behavior , ne olacağı belli değil, sıkıntı

    float value;
    printf("scanf() kullanımı için value gir : ");
    scanf("%f", &value);
    printf("Value: %f\n",value);

    int aa,bb;
    printf("Değerleri gir : ");
    scanf("%d - %d",&aa,&bb);   // %d 'ler arasında kullanılan karakterler terminalde sayılar girilirken de aynı şekilde kullanılmalıdır
    printf("a: %d, bb: %5d",aa,bb); // %5d ile sayı yazdırmadan önce 5 karakterlik boşluk buralıkmış olunur

    // Farklı namespace'ler için aynı isim kullanılabilir
    struct Node{int x;};
    int Node = 12;

    signed char c = 250; // char 1 byte = 8 bit tutabildiği için fazlası mod çıkan değer tutulur
    printf("\n%d - %c\n",c,c);  // 256 ile mod alınmış değer ve ASCII için karşılığı
    // Buradaki char 8 bit tutar,
    // 8 bit signed olarak oluşturulduğu içinde -128 - 127 arasında değerler alabilir
    // yani 8 bitin en sol biti işaret biti olduğu için 7 bit sayısal değeri temsil eder
    // 0-127 arasında normal bit sıralaması çalışır,
    // -128 , -1 arasıda ise two's complement şeklinde devam edilir

    signed char c2 = 260;
    printf("\n%d - %c\n",c2,c2);

    // Signed - Unsigned
    /*
        8 bit -> 1 byte bir değişken;
        signed ise -128 ile 127 arasında değer tutabilir, nedeni ise en sol bitin işaret biti olarak ayrılmasıdır
        unsigned ise 0 ile 255 arasında değerler tutabilir. Tüm bitler kullanılır

        Yani signed kullanılmışsa girilen sayının en sol biti otomatik işaretini belirler(two’s complement gösterim),geri kalan bitler
        ise sayının değerini belirler ama unsingned kullanılmışsa tüm bitler sayı değerini belirler

        Eğer mesela bir 300 değeri unsigned 8 bitlik değişkene atanırsa, 300 değeri 9 bit ile temsil edildiğinden
        en soldaki bit silinir ve geri kalan bitlerin değeri olarak değişkende tutulur
        yani unsinged char c = 300; ---> c değeri aslında 300%256 sonucunda 44 değerini tutmuş olur

        Eğer bir 200 değeri singed bir değişkende ataması yapılırsa ilk önce 256 ile mod u alınır, çünkü 8 bitlik
        bir değişkendir elimizdeki. Sonra eğer çıkan sonuç 0 ve 127 veya arasındaki değerlerden biri ise bu değer
        pozitif olarak kullanılır. Ama 128 ve 255 veya arasında bir değer çıkarsa bu sayı negatif demektir ve sayısal değeri
        256 dan çıkarılarak bulunur.
        Yani signed c = 200; ----> mod % 256 = 200 , yani negatif ve değeri ise 256 - 200 = 56 dır. Yani sonuç -56'dır.

    */



    char a = 'A';               // 1 byte - %c - Tek bir karakter tutar,
    char b[] = "Hello World";   // Karakter sayısı kadar boyutu olur - %s -, Karakter grubu tutar - string

    float cc = 3.2342432f;       // 4 byte - %f - 6-7 basamak tutabilir
    double d = 3.23423423424332;// 8 byte - %lf - 15-16 basamak tutabilir
    char f = 200;               // 1 byte - %d yada %c - (-127 ile 128 arasında değer tutabilir)
    unsigned char g = 100;      // 1 byte - %d yada %c - (0 ile 255 arasında değerler alabilir)
    bool e = false;             // 1 byte - %d - true yada false
    short h = 32767;            // 2 byte - %d - (-32768 ile 32767) - sadece short ile de kullanılabilir
    unsigned short int u = 65535; // 2 byte - %d - (0 ile 65535) - sadece unsigned short ile de kullanılabilir
    int i = 36723423;         // 4 byte - %d - (-2,147,483,648 ile 2,147,483,648)
    unsigned int j = 4123434243; // 4 byte  - %u - (0 ile 4,294,967,295)
    long long ll = 9223372036854775807; // 8 byte - %lld
    unsigned long long ull = 9223372036854775807; // 8 byte  - %llu


    // Çıktılar
    printf("***************************************\n");
    printf("char: %c\n",a);
    printf("char array(string): %s , Size: %d byte \n",b,sizeof(b));
    printf("Float: %f\n",cc);   // default olarak 6 basamak gösterilir
    printf("Double: %.14lf\n",d); // %.12lf şeklinde detaylı olarak basamaklara erişilebilir
    printf("Sayı tutan işaretsiz Char: %d\n",f);
    printf("Sayı tutan işaretsiz Char: %d\n",g);
    printf("Bool: %d\n",e);
    printf("Short Int : %d\n",h);
    printf("Unsigned Short Int : %d\n",u);
    printf("Int : %d\n",i);
    printf("Unsigned Int : %u\n",j);
    printf("Long Long Int : %lld\n",ll);
    printf("Unsigned Long Long Int : %llu\n",ull);



    // Type Casting


    return 0;
}