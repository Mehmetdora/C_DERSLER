#include <stdio.h>
#include <stdlib.h>


// Passing-by-value
// Klasik pointer olmadan fonksiyon kullanımı şeklidir, bir değer fonksiyona verilir ve fonksiyon bu değeri
// kopyalayarak orijinal değer yerine kopyayı kullanır

void change_by_value(int a) {    // Gelen parametre 100 ama bu kopya bir değer olduğu için orijinal değer değiştirilmemiş olur
    a = 1337;
}


// Passing-by-referance
// Pointer ve addres kullanımı ile orijinal değer üzerinde değişkenler üzerinde işlemler yapmaktır
// Fonksiyona orjinal değerin adresi verilir ve bu değer üzerinden sayı değerine erişilere adres üzerinden kesin bir işlem yapılır

void change_by_referance(int *a) {
    *a = 1337;
}



// Pointer heap - stack farkı, Önemli !!!
int *foo() {        // Stack(geçici bellekte) bir değişken oluşturur ve bunu döndürür
    int n = 42;
    return &n;
}
int* foo2() {        // Heap(kalıcı bellekte) bir pointer oluşturu ve bunu döner
    int *n;
    n = malloc(sizeof(int));
    *n = 42;
    return n;
}

void bar() {         // sadece bir değişken oluşturur
    int p ;
    p = 133;
}



int main(void) {

    int val = 100;
    change_by_value(val);       // Orijinal değer verilir fakat fonk içinde kopyası üzerinden işlemler yapılır
    printf("Passing-by-value result: %d\n", val);

    change_by_referance(&val);  // Adresi verilir, bu sayede orijinal değer üzerinden fonk içinde değişkene işlemler yapılarak değiştirilebilir
    printf("Passing-by-referance result: %d\n", val);



    // Pointers

    // int *val ile tanımlanırlar,
    // & ile gösterecekleri değişkenin adresine eşitlenirler,
    // *val ile bu adreste tutulan değere erişilir
    int a = 10;
    char b = 'b';
    int *ptr = &a;                  // POINTER HER ZAMAN ADRES TUTMALI TANIMLANIRKEN
    char *ptr_b = &b;                  // POINTER HER ZAMAN ADRES TUTMALI TANIMLANIRKEN
    printf("Value: %d\n", *ptr);
    *ptr = 100;                     // Adres üzerinde orijinal değer değiştirilir *ptr = a olduğundan
    printf("Value: %d\n", a);
    printf("\n");

    // size of a pointer, the adress
    printf("Size: %d\n", sizeof(ptr));
    printf("Size: %d\n", sizeof(ptr_b));

    // %p adresi bastırmak için kullanılır.
    int n;
    int *pn;
    int **ppn;
    int ***pppn;

    n = 42;
    pn = &n;        // &n -> n değişkeninin ram deki adresini verir
    ppn = &pn;      // pn, n'in adresini tutar, &pn ise bu adres değerinin adresini verir
    pppn = &ppn;

    // Bellek zinciri = pppn -> ppn -> pn -> n -> 42


    // n = 42
    // pn türü = int değişkenler için kullanılan bir pointer
    // pn = n'in adresi
    // *pn = n'in değeri

    printf("N value: %d\n", n);             // orijinal değeri
    printf("N reference: %d\n", *pn);       // n in adresini tutan pointer'ın değeri(pn -> n adresi, *pn -> n değeri)
    printf("n adresi yani &n: %p\n",pn);
    printf("pn değeri yani &n: %p\n", *ppn);
    printf("N reference: %d\n", **ppn);
    printf("N reference: %d\n", ***pppn);




    // Heap-stack pointer kullanımı
    int *pt;

    // Normalde olması gereken foo() ile alınan 42 değerinin her 2 print içinde de yazdırılmasıdır fakat burada
    // foo() çalışması bittikten  sonra stack te ayrılan bellek silinir, yani 42 değeri artık stack in o adresinde yoktur.

    // Stack e veriler üst üste ve sıralı olarak yazılır. Bu nedenle stack te yeri boşalan adrese bar() fonksiyonu ile aynı foo() içindeki
    // aynı türde int değişkeni yazılmış olundu. Ek olarak *pt hayla stack te boş olan adresi gösteriyordur. Bundan sonra bar() fonksiyonu
    // çalışınca stack in boş olan adresine 133 yazıldı ve *pt haliyle bu adresdeki değeri göstermeye başladı , bu nedenle 2. print içiden
    // 133 değeri yazılmış oldu.

    // Bunu engellemek için foo() ile elde ettiğmiz değeri kalıcı bellek e yazmalıyız. Bunu yapmak için heap kullanılır yani malloc() methodu
    // malloc() ile bellekten kalıcı olarak istenilen veri türünün boyutu kadar yer ayrılır. Sonrasında fonksiyon bitse bile bu bellekteki veri
    // free() ile boşaltılmadıkça silinmez(dikkatli olmak gerekir).

    pt = foo();     //  -> 42 - 133
    //pt = foo2();      -> 42 - 42

    printf("foo() result: %d\n", *pt);
    bar();
    printf("last result: %d\n", *pt);


    return 0;
}