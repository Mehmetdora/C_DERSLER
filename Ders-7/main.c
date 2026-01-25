#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Struct

struct Student {        // Beraberinde bazı bilgiler tutan struct
    char name[20];
    int age;
    char gender;
};
// Bu şekilde oluşturulmuş olan yapılarda name bir dizi olduğundan bu diziye atama yapılırken direkt değer verilemez
// çünkü bu diziye atama yapılırken başka dizinin adresi verilmiş olunur , bu da name'e başka bir dizi vermek yerine
// adres vermek anlamına gelir.

struct Ogrenci {
    char *name;     // bu sayede name değişkeni bir array'i işaret edeceğini söyler. Adres bekler, array gibi
    int age;
    int grades[3];
};


// typedef ile struct tanımlaması, bu sayede Person p şeklinde tanımlama yapılabilir.
typedef struct {
    char *name;
    char *city;
    int age;
} Person;


// bu tür struct yapısında ek olarak en sondaki isimler aynı struct yapısını farklı amaçlarla kullanmak için verilir
// mesela aynı Point yapını koordinat gibi bir kısa tip olarak tanımlamada kullan demek için yapılıyor
// koordinat p1 ;
// p1.x = 10;       gibi , yani aynı Point yapısını farklı amaçlarda farklı isimlerle özelleştirmeye yarar
typedef struct Point {
    int x;
    int y;
} koordinat,en_boy,hiz_vektor;


typedef struct {        // Point üzerinde erişmek için
    struct Point *point;
} Data;

void print_point(const struct Point *point);
struct Point make_point(int x, int y);

int main(void) {


    // Pointer olmadan Strcut yapısı
    struct Student student1;
    student1.age = 22;
    student1.gender = 'K';
    //student1.name = "John";   // Bu şekilde değer ataması yapılamaz
    strcpy(student1.name, "aleyna");    // Ancak bu şekilde kopyalama ile yapılabilir pointer kullanmadan

    printf("student1.age = %d\n", student1.age);
    printf("student1.name = %s\n", student1.name);
    printf("student1.gender = %d\n", student1.gender);



    // Pointer ile struct yapısı
    struct Ogrenci ogrenci1;
    ogrenci1.age = 22;
    ogrenci1.name = "Mehmet";   // Pointer türünde bir değişken olduğundan direkt string array atanabiliyor
    ogrenci1.grades[0] = 100;    // Fakat array tipindeki değişkene tek tek değer verilebilir, direkt adrese değer ataması
    ogrenci1.grades[1] = 70;
    ogrenci1.grades[2] = 10;

    printf("ogrenci1.age = %d\n", ogrenci1.age);
    printf("ogrenci1.name = %s\n", ogrenci1.name);
    printf("ogrenci1.grades[0] = %d\n", ogrenci1.grades[0]);
    printf("ogrenci1.grades[1] = %d\n", ogrenci1.grades[1]);
    printf("ogrenci1.grades[2] = %d\n", ogrenci1.grades[2]);



    printf("\n");
    Person p;
    p.age = 22;
    p.name = "Mehmet";
    p.city = "Adana";
    printf("p.age = %d\n", p.age);
    printf("p.name = %s\n", p.name);
    printf("p.city = %s\n", p.city);




    // Aynı Point yapısı , farklı amaç için kullanım
    koordinat a;
    a.x = 20;
    a.y = 20;

    en_boy b;
    b.x = 20;
    b.y = 20;

    // direkt değer ataması şeklinde struct ataması
    hiz_vektor vektor1 = {
        .x = 10,
        .y = 10
    };

    // bu kullanımda değeri verilmeyen değişkenler otomatik 0 olarak oluşturulur, yani vektor2 tam dolu olarak üretilir
    hiz_vektor vektor2 = {
        .x = 30     // y değeri default olarak 0 dır
    };
    printf("vektor1.x = %d\n", vektor1.x);
    printf("vektor1.y = %d\n", vektor1.y);
    printf("vektor2.x = %d\n", vektor2.x);
    printf("vektor2.y = %d\n", vektor2.y);


    // Aynı türdeki struct 'lar biririne eşitlenebilir
    vektor1 = vektor2;
    printf("vektor1.x = %d\n", vektor1.x);
    printf("vektor1.y = %d\n", vektor1.y);

    printf("\n");
    printf("a.x = %d\n", a.x);
    printf("a.y = %d\n", a.y);
    printf("b.x = %d\n", b.x);
    printf("b.y = %d\n", b.y);


    struct Point points[10];    // 10 tane point yapısı

    for (int i = 0; i < 10; i++) {
        points[i].x = i*i;
        points[i].y = i/2;
    }

    for (int i = 0; i < 10; i++) {
        printf("points[%d].x = %d\n", i, points[i].x);
        printf("points[%d].y = %d\n", i, points[i].y);
    }


    Data data_x;
    Data data_y;
    data_x.point = malloc(2 * sizeof(struct Point));
    data_y.point = malloc(2 * sizeof(struct Point));

    data_x.point[0].x = 10;
    data_x.point[0].y = 10;
    data_x.point[1].x = 21;
    data_x.point[1].y = 21;

    data_y.point[0].x = 20;
    data_y.point[0].y = 20;
    data_y.point[1].x = 11;
    data_y.point[1].y = 11;

    for (int i = 0; i < 2; i++) {
        printf("data_x.point[%d].x = %d\n", i, data_x.point[i].x);
        printf("data_x.point[%d].y = %d\n", i, data_x.point[i].y);
        printf("data_y.point[%d].x = %d\n", i, data_y.point[i].x);
        printf("data_y.point[%d].y = %d\n", i, data_y.point[i].y);
    }

    data_x = data_y;    // data_y nin tüm değerleri data_x e geçer, yani point pointer'ının gösterdiği adresler de geçmiş olur
    printf("\n");

    for (int i = 0; i < 2; i++) {
        printf("data_x.point[%d].x = %d\n", i, data_x.point[i].x);
        printf("data_x.point[%d].y = %d\n", i, data_x.point[i].y);
        printf("data_y.point[%d].x = %d\n", i, data_y.point[i].x);
        printf("data_y.point[%d].y = %d\n", i, data_y.point[i].y);
    }


    print_point(&points[5]);

    struct Point p1 = make_point(13,14);    // Fonksiyon içinden
    printf("p1.x = %d\n", p1.x);
    printf("p1.y = %d\n", p1.y);

    return 0;
}


// Struct pointer olarak fonksiyona gönderiliyor
// tek fark pointer erişimi, (*p).x demek yerine p->x denilerek veriye erişiliyor.
// Bu kullanım sadece struct ve union ile  pointer kullanımı için geçerlidir, başka yerde kullanılmaz
void print_point(const struct Point *p) {

    // p->x = 10;       bu şekilde değeri değiştirilemez çünkü alınan değer const ile alındı
    printf("point.x = %d\n", p->x);
    printf("point.y = %d\n", p->y);
}

struct Point make_point(int x, int y) {
    struct Point p;
    p.x = x;
    p.y = y;
    return p;
}