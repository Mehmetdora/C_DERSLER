#include <stdio.h>
#include <string.h>


typedef unsigned int unsigned_int;  // kullanıcı tarafıdan tanımlanan değişken tipi

typedef enum {true , false} bool;


// enum kullanımında aşağıdaki gibi olabilecek değerler verilmişse bu tiplerin değerleri
// 0 dan başlayarak sağa doğru artarak her tipe verilir
// yani yeni bir durum değişkeni oluşturulduğunda onaylandi ise değeri int 0 dır. 1-2-3 şeklinde devam eder.

typedef enum {onaylandi,beklemede,reddedildi} durum;
/*
    if (durum == 2) yazmak yerine;
    if (durum == reddedildi) yazmak kodu çok daha okunabilir kılar.
 */


// bu şekilde tiplere özel olarak değer ataması da yapılabilir
typedef enum {kotu = 40,orta = 65, iyi = 85, pek_iyi = 100} karne;


// bu şekilde bazılarına değer verilip bazılarına değer verilmeyebilri, verilmeyenler solundakinin bir fazlasını temsil eder
typedef enum {soguk = 40,ilik = 65, sicak = 85, kaynama} derece;    // kaynama = 86 dır




// Union
// bu veri tipi struct yerine kullanılmak için tasarlanmıştır, struct ile tüm tanımlanan değişkenler
// bellekte kullanılmasa bile yer kaplar. AMa union ile tek bir değişkenin boyutu kadar yer kaplar.
// Yani aynı zamanda tek bir değişkenin boyutu kadar bellekte yer kaplanır.

// Yani ihtiyaca göre veriye farklı türlerinde erişmek için kullanılırlar. Kullanılmayanlar rasgele değerler alırlar.

// Veri boyutu ise en büyük olan değişkenin boyutu kadardır. Fakat bu boyut belirlenirken diğer değişkenlerin tipleride
// hesaplanarak en büyük veri boyutuna sahip veri tipinin katı olacak şekilde tamamlanır. Mesela aşağıdaki örnekte
// en büyük char[10] olur fakat boyut 10 olması gerekirken int katı olan 12 ye yuvarlanır.
// Buna memory alignment denir. Belleğin tam olarak dolmasını sağlar.

union tip {
    int by_size;
    char by_char[10];
    float by_float;
};

// enum ve union birlikte kullanımı
struct Data {
    enum {
        INT, STRING, FLOAT
    } type;
    union {
        int integer;
        char *string;
        float floating;
    } data;
};

void print_union(union tip *my_tip);

int main(void) {

    unsigned_int my_num = 300;
    printf("my_num: %d\n", my_num);

    bool my_bool = false;
    printf("my_bool: %d\n", my_bool);
    my_bool = true;
    printf("my_bool: %d\n", my_bool);

    durum my_durum;             //
    printf("my_durum: %d\n", my_durum);
    my_durum = beklemede;
    printf("my_durum: %d\n", my_durum);
    my_durum = reddedildi;
    printf("my_durum: %d\n", my_durum);
    my_durum = onaylandi;
    printf("my_durum: %d\n", my_durum);


    karne my_karne;
    my_karne = iyi;
    printf("my_karne: %d\n", my_karne);

    karne bro_karne = orta;
    printf("karne: %d\n", bro_karne);


    derece my_derrece;
    my_derrece = sicak;
    printf("my_derrece: %d\n", my_derrece);
    my_derrece = kaynama;
    printf("my_derrece: %d\n", my_derrece);



    // Union

    union tip my_tip;
    printf("Size of union : %lu\n",sizeof(my_tip));
    print_union(&my_tip);


    my_tip.by_size = 300;
    printf("Size of union : %lu\n",sizeof(my_tip));
    print_union(&my_tip);

    strcpy(my_tip.by_char, "my_tip i");
    printf("Size of union : %lu\n",sizeof(my_tip));
    print_union(&my_tip);

    my_tip.by_float = 3.14f;
    printf("Size of union : %lu\n",sizeof(my_tip));
    print_union(&my_tip);

    // Pointer üzerinden union a erişim
    union tip *my_tip_ptr = &my_tip;
    printf("Size of union : %lu\n",sizeof(my_tip_ptr));
    printf("%f\n", my_tip_ptr->by_float);


    // enum -  union birlikte kullanımı
    struct Data my_data;
    my_data.type = INT;
    my_data.data.integer = 42;
    printf("Size of union : %lu\n",sizeof(my_data));    // boyut 16  ---> 8 union(pointer), 4 enum, 4 boşluk(alignment)
    printf("Type of union : %d\n",my_data.type);
    printf("Data of union : %d\n",my_data.data.integer);


    my_data.type = STRING;
    my_data.data.string = "Adım nedir?";
    printf("Size of union : %lu\n",sizeof(my_data));    // boyut 16  ---> 8 union(pointer), 4 enum, 4 boşluk(alignment)
    printf("Type of union : %d\n",my_data.type);
    printf("Data of union : %s\n",my_data.data.string);


    return 0;
}

void print_union(union tip *my_tip) {

    printf("my_tip char: %s\n", my_tip->by_char);
    printf("my_tip float: %f\n", my_tip->by_float);
    printf("my_tip size: %d\n", my_tip->by_size);
    printf("\n");
}