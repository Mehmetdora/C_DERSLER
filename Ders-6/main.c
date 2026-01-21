#include <stdio.h>
#include <stdlib.h>


// Pointer'lar ve Array'ler

// Array'ler de bir sıralı pointer gibi düşünülebilir, değerler arka arkaya tutularak erişilir


// Array decay örneği
void change_arr(int arr[],int size) {       // parametre olarak gönderilen array artık bir array değil pointer'dır, sizeof(arr) farklıdır

    // Buradaki arr size'ı artık bir pointer size'ına eşittir çünkü arr artık bir pointer'dır, pointer olarak kullanılır
    printf("sizeof(arr): %d\n",(int)sizeof(arr));
    for (int i = 0; i < size; i++) {
        arr[i] = 1;
    }
}

int main(void) {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    printf("Arr address: %p\n",arr);            // array in kendisi bir pointer gibi adres tutar
    printf("Arr address: %p\n",&arr);           // Kritik: buradaki *(arr + 1) ile array in 1. indexsindeki elemana erişilir
                                                // Fakat *(&arr + 1) ile 10 index sonraki adresteki elemana erişilir



    printf("Arr[0] address: %p\n",&arr[0]);     // Array in ilk elemanı ile array in kendisi aynı adresi gösterir
    printf("Arr[1] address: %p\n",&arr[1]);
    printf("Arr[2] address: %p\n",&arr[2]);

    // Pointer ve array benzerlikleri
    printf("*arr: %d\n",*arr);                      // Array de sanki bir pointer gibi tututuğu adresteki değeri gösterebilir
    printf("*arr ile ilk eleman: %d\n",*(arr + 0)); // pointer'larda olduğu gibi arrayde de bir sonraki değere adresi bir int kadar arttırarak erişilebilir
    printf("*arr ile 2. eleman: %d\n",*(arr + 1));
    printf("*arr ile 3. eleman: %d\n",*(arr + 2));


    printf("\n\n");

    int arr2[10];           // C de boş array tanımlanamaz - compiler uyarmaz , Hatalı : int arr2[] = {};
    int my_ptr_arr_size = 10;

    // Bir array için de mesela 10 elemanlı array in boyutu 10*sizeof(int) dan 40 dır.
    // pointer da bir array olarak kullanılabildiği için pointer ın göstereceği 40 byte lık bellek ayrılır.
    // Fakat pointer ın kendisinin boyutu yine 8 byte dır. İşaret ettiği bellek ise 40 byte dır .
    int *my_ptr_arr = malloc(my_ptr_arr_size * sizeof(int));
    printf("Size of my_ptr_arr: %d\n",(int)sizeof(my_ptr_arr));     //Pointer yine 8 byte boyutuna sahip

    // BEllek ayrılmamasına karşı kontrol edilmeli
    if (my_ptr_arr == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // Array boyutu kadar for ile asıl pointer üzerinden belleğe sıralı olarak erişilir.
    // Asıl pointer bir adresi işaret eder ve bu adresten diğer adreslere atlanarak sanki bir array miş gibi değerler adreslere verilir
    // *(my_ptr_arr + 1) ile asıl adresten i kadar sonraki adrese gidilir. i ise 4 byte yani bir int olduğu için tam oalrak bir array gibi çalışır
    // *( --- ) ile de bu adresteki değere erişilerek değer verilmiş olunur , hemen alttaki array de olduğu gibi
    for (int i = 0; i < my_ptr_arr_size; i++) {
        *(my_ptr_arr + i) = i;
        arr2[i] = i;
    }


    // Görüldüğü gibi hem array pointer gibi kullanılabiliyor hemde pointer array gibi kullanılabiliyor.
    for (int i = 0; i < my_ptr_arr_size; i++) {
        printf("my_ptr_arr[%d] = %d  --  ", i, my_ptr_arr[i]);
        printf("*(my_ptr_arr + %d) = %d  --  ", i, *(my_ptr_arr + i));
        printf("arr2[%d] = %d  --  ", i, arr2[i]);
        printf("*(arr2 + %d) = %d\n", i, *(arr2 + i));
    }

    // yani my_ptr_arr[i] == *(my_ptr_arr + i)


    free(my_ptr_arr);

    int val = 10;
    int *ptr = &val;
    int *ptr2 = &val;

    // Her iki pointer da aynı değişkeni point eder.
    printf("*ptr ve *ptr2: %d , %d \n",*ptr,*ptr2);

    // Bir tanesi bu değişkeni değiştirirse hepsi için değişmiş olur.
    *ptr2 = 20;
    printf("*ptr ve *ptr2: %d , %d \n",*ptr,*ptr2);



    // Two dimensional Arrays
    int col = 10, row = 10;
    int arr3[row][col];

    // tüm değerlerini 0 yap
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr3[i][j] = 0;
        }
    }

    // pointer üzerinden arraye erişerek tüm değerlerini 1 yap
    int *p;
    for (p = &arr3[0][0]; p <= &arr3[row-1][col-1]; p++) {
        *p = 1;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr3[%d][%d] = %d\n", i, j, arr3[i][j]);
        }
    }


    // Array Kullanımları

    // Dikkat : arr[0] == 0[arr] 'dir
    // NAsıl: C de a[b] == *(a + b) dir
    // Bu nedenle arr[0] aslında *(arr + 0) dır

    // Aynı şekilde 0[arr] de *(0 + arr) dir
    // *(0 + arr) == *(arr + 0) dır.
    // ilk kurala dönülürse bu da arr[0] a eşittir.

    int v[10];
    v[0] = 1;

    printf("Text: %c \n", "HELLO"[0]);
    printf("Text: %c \n", *("HELLO" + 1));
    printf("Text: %c \n", 3["HELLO"]);
    printf("Text: %c \n", 4["HELLO"]);  // "HELLO" asılnda char v[6] = {'H','E','L','L','O','\0'} olarak görülür


    // Array Decay
    int arr4[10] = {0};

    int *ptr4 = &arr4[0];      // Bu işleme array decay denir, pointer üzerinden tanımlı olan array i kullanmak
                                // Yada zorunlu olarak bir fonksiyona parametre olarak array gönderildiğinde bu array in ilk adresinin bir pointer ile göstilmesidir

    // Array pointer a dönüşmez , array yine aynı array'dir
    // Sen array e pointer üzerinden erişirsin

    // Yani array decay demek bu array'e artık pointer üzerinden erişileceği demektir .
    // Şu durumlar aslında array decay durumlarıdır;
    // func(arr)
    // int *p = arr
    // *(arr + 1)

    // C de fonksiyonlar aldığı parametrenin kopyası ile çalışır,
    // Bir array gönderildiğinde bunun tümünü kopyalamak yerine array in adresini beklerler
    //

    // Tüm array 0
    for (int i = 0; i < 10; i++) {
        printf("arr4[%d] = %d\n", i, arr4[i]);
    }

    printf("sizeof(arr4): %d\n",(int)sizeof(arr4));     //  Normal array
    change_arr(arr4, 10);                           // GÖnderliern array fonksiyon içinde pointer 'a dönüşür
    printf("sizeof(arr4): %d\n",(int)sizeof(arr4));     // Normal Array


    for (int i = 0; i < 10; i++) {
        printf("arr4[%d] = %d\n", i, arr4[i]);
    }





    // CONST kullanımı

    // const hemen sağındakini sabit tutmayı sağlan
    const int value = 10;   //value = 20; şeklinde değiştirilemez

    int u = 10;
    int y = 20;
    const int *j = &u;      // const int *j , kullanımı ile int değer sabit ama pointer serbest
                            // int* const j , kullanımı ile pointer sabit ama değer değişebilir
                            // const int* const j, kullanımı ile hem değer hemde pointer sabit olur
    //int* const j = &u;
    //const int* const j = &u;

    // Pointer ile const kullanıldığında sadece o pointer için sabitlik geçerlidir, asıl değişken yine değiştirilebilir
    u = 30;

    // *j = 5;     // Değiştirilemez, veri const ile korunuyor ama pointer serbest
    j = &y;



    // String Literals

    // Bir "hello" string dizisi değiştirilebilir değildir !!! Bir karakterine erişilerek değiştirmeye çalışmak tanımsız sonuç verir

    /*
    char *s = "HELLO";
    s[0] = 'h';
    printf("s: %s\n",s);
    */

    // Bunu daha compiler tarafından uyarılabilir yapmak için;
    const char* s = "HELLO";
    // s[0] = 'M';              // burada compiler artık bu string array'in sabit olduğunu kullanıcıya uyarır, izin vermez
    printf("%s\n", s);




    // Pointer aritmetiği

    // Burada sayı unsigned int türündedir ve bu sayıyı byte byte parçalama yapılıyor
    // Bunun için bir byte'Lık yani unsinged char kadarlık bir pointer ile bu sayı adresi üzerinde geziliyor.
    // Her bir unsinged char kadarlık parçada bir array içinde ayrı ayrı tutuluyor.

    // Burada dikkay edilmesi gerekn yer asıl sayının başlangıç adresini bir pointer a verilir
    // ve bu pointer türü kadar boyut olarak adres üzerinden ileri veya geri giderek değer üzerinde gezer
    unsigned int sayi = 0xAB123456;

    // Bradaki sayi bize göre AB 12 34 56 şeklinde byükten küçüğe doğru basamağına göre sıralanır
    // ama belleğe farklı şekillerde kaydedilebilir little endian veya big endian türleri ile
    // little endian ile küçük basamaklı değerler küçük adresten başlayarak değerler belleğe yazılır
    // big endian ise büyük basamak değerli parçalar küçük adresten başlayarak ters şekilde yazılır
    unsigned char *s_ptr;
    unsigned char list[4];

    s_ptr = (unsigned char *)&sayi;     // sayi değişkeni değişmez ama bu değişkenin okunma boyutu değişir, bir byte'lık parçalar şeklinde okumak için
    printf("s_ptr: %x\n", *s_ptr);
    list[0] = *s_ptr;
    list[1] = *(s_ptr + 1);
    list[2] = *(s_ptr + 2);
    list[3] = *(s_ptr + 3);

    printf("Sayının BYTE BYTE ayrımı: %x - %x - %x - %x \n",list[0],list[1],list[2],list[3]);


    return 0;
}