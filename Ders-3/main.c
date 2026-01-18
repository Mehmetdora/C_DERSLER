#include <stdbool.h>
#include <stdio.h>


/*
 * RELATIONAL OPERATORS
 *   <  ,  >  ,  <=  ,  >=
 *   ==  ,  !=
 *   &&(and)  ,  ||(or)  ,  !(not)
 */


/*
 * LOOPS
 * while , do-while, for
 *
 *
 *
 */


int main(void) {

    int i = 1, j = 1;
    int k = 2;

    if (i < k == k < j)    // bu koşul ile (i<k) == (k<j) aynıdır
        printf("ok\n");
    else if (i > k || j > k || (k != 0 && j == 0))
        printf("ok2\n");
    else                    // if koşulunun hemen altında bir satır için {} açılmaması hata vermez
        printf("not ok\n");

    if (i = 3) {   //  Bu durumda i değeri 3 yapılır ve sıfır olup olmadığına bakılır , 0 ise çalışmaz , 0dan farklı ise hep çalışır
        printf("%d ,ok3\n",i);
    }

    if (i == 1) printf("ok4\n");    // tek satırlık işlemlerde {} zorunlu değil
    else printf("not ok4\n");

    // Dikkat!
    // Aşağıdaki gibi bir kodda sanki ilk if ile sondaki else biririnin eşi gibi ama C de else yakın olan if else ile eşleşir
    // yani ilk if'e girilirse aşağısındaki il-else bloğu çalışır ,  ilk if e girilmezse hiçbir kod çalışmaz
    if (i == 5) // i = 3
        if (i == 4)
            printf("ok6\n");
    else
        printf("not ok5\n");


    // Conditional Expressions
    int a = 2;
    int b = a < 0 ? a : -a;     // koşul doğru ise ? ile : arasındaki işlemi yap, yanlış ise :'den sonraki işlemi yap
    printf("a: %d , a < 0 --> %d\n", b, b<0);


    // Booleans
    bool state = false;     // bool anahtar kelimesini kullanabilmek için stdbool include edilmelidir
    printf("Bool state: %d\n",state);


    // Switch-case

    // uzun if-else kullanmak yerine case kullanılabilir
    // kontrol edilecek değer en başta switch() içine girilir
    // her olası durum için case kullanılır
    // her case e girildikten sonra diğer durumların kontrolünü bitirip switch-case'den çıkabilmek için break kullanılmalıdır

    // Çoklu olasılık durumları olma ihtimali için alt alta case: kullanılabilir
    int age = 25;
    switch (age) {
        case 1:
            printf("age: %d\n",age);
            break;

        case 23:
        case 22:
        case 21:
        case 20:
            printf("age: one of 23,22,21,20\n");
            break;

        case 24 : case 25: case 26: case 27:
            printf("age 24,25,26,27\n");
            break;
        default:
            printf("default: %d\n",age);
            break;
    }




    // LOOPS

    // while
    int ff = 10;
    while (ff < 20) {
        printf("ff: %d\n",ff++);
    }

    while (ff > 0) printf(" %d,",ff--);

    while (1) {
        printf("*\n");  // sonsuz döngüdür ve ancak break , goto veya return ile durdurulabilir
        break;
    }

    // do-while
    // döngüye başlamadan önce yaptırılacak bir şey olursa durumları için
    ff= 0;
    do {
        if (ff == 0) ff = 100;
        printf("ff: %d\n",ff++);
    }while (ff < 120) ;


    // for
    // for() içindeki ilk değer başlangıç statement dır. sonraki kontrol statement dır. en son değişim statement dır
    ff = 0;
    for (int i = 0; i<10; i++) {
        printf(" %d,",i);
    }

    // aşağıdaki 3 for loop için başlangıç statement kullanımı ile döngü çalışabilir
    // istenen değerden başlatılabilir, değeri ne ise oradan devam ettirilebilir, boş bırakılabilir
    printf("\n");
    for (ff = 10; ff < 20; ff++) printf(" %d,",ff);
    printf("\n");
    for (ff; ff > 10; ff--) printf(" %d,",ff);
    printf("\n");
    for (;ff < 20; ff++) printf(" %d,",ff);    // değer statement olmadan da çalışır
    printf("\n");
    for (int a = 0; a< 10;) printf(" %d,",a++); // değişim statement olmadan da çalışır

    printf("\n");
    ff= 25;
    for (;ff > 20;) printf(" %d,",ff--);    // hem değer hemde artış statement olmadan

    printf("\n");
    for (;;) {              // Sonsuz loop için kullanılır, hiçbir statement olmadan
        printf("*\n");
        break;
    }

    int sum, s = 0;
    for (sum = 0,s = 0;s<10;s++) {          // döngünün başlangıç değeri statement içiden birden fazla expression tanımlanabilir
        sum += s;
        printf("sum:  %d, i: %d\n",sum,s);
    }

    int aa = 0;
    while (aa < 10) {       // döngü sırasında o anki döngü adımını atlayıp bir sonraki adıma geçmek için continue kullanılır
        aa++;
        if (aa%2 == 0) continue;
        if (aa == 7) break;         // döngüden tamamen çıkmak ve bitirmek için break kullanılır
        printf("aa: %d, ",aa);
    }


    // goto

    // goto keyword ile bir isim tanımlanır , bu isim nerede kullanılırsa kod oradan devam eder
    // Bu eğer bir while loop içinde birde switch kullanılmışsa break'in işe yaramayacağı durumda kullanılabilir.
    printf("\n");
    int last_index = 0;
    for (i = 0; i<10; i++) {
        last_index = i;
        if (i == 6) goto cikis;
    }
    cikis:
    printf("Last Index: %d\n",last_index);



    // Type Conversion - Casting

    // long != int farklıdır !!!

    // Implicit(örtük) conversion - derleyicinin kendi yaptığı dönüşümler
    char u = 10;    // burada hata alınmadan arkada derleyici char -> int yapar
    int p = u;

    float uu = 10.55f;
    int uo = 10;
    float pp = uu + uo;     // aritmetik conversion ile toplama yapılırken int -> float yapar

    char hh = 'A';      // char --> int
    int gg = hh + 10;


    int nn = 9;
    long mk = 9;
    long long llk = 9;
    printf("\nint: %d, long: %d , long long: %d\n",sizeof(nn),sizeof(mk),sizeof(llk));


    // 2 sayının arasında işlem yapılırken sonuç şu sarıya göre otomatik dönüşür;
    // int -> unsinged int -> long long -> unsigned long  long -> float -> double -> long double
    // Daha düşük seviyedeki sayı daha yüksek seviyedeki sayının seviyesine otomatik olarak yükseltilir

    // yani tam sayı olanlar ondalıklı olanlara, signed olanlar unsigned olanlara, küçük olanlar büyük olanlara otomatik dönüştürülür
    // özellikle singed - unsinged dönüşümlerine dikkat etmek gerekir , bir signed değerin unsigned ile dönüşümü boyutu tam tersine çevirebilir



    // DİKKAT - BÜYÜK HATA ÖRNEĞİ
    // if statement içinde ls değeri otomatik unsinged yapılır ve değeri max int değeri olur
    // ls değeri değişmez ama kontrol sırasında değeri değiştiği için hataya sebep açabilir ve sorunu görmek çok zordur

    int ls = -1;
    unsigned int zz = 1;
    if (ls < zz)  printf("zz daha büyüktür: %d\n",zz);
    else printf("ls daha büyüktür: %d\n",ls);



    // Explicit(açık) conversion - kendimizin kontrol ederek yaptığımız dönüşümler
    float hhh = 6.4f;
    int jj = (int)hhh;      // tam sayı alınır , jj = 6

    int ii = 5,ll = 2;          // int->float dönüşümü
    float vv = (float)ii/ll;
    printf("vv: %f\n",vv);

    // dönüşüm sırası: char -> short -> int -> long long
     //                int -> float -> double -> long double

    // dikkat edilmesi gereken dönüşümler:
    // double -> float
    // float -> int
    // int -> char
    // signed -> unsigned


    // Şu türler otomatik olarak direkt int 'a yükseltilir, yine sığmazsa unsigned int 'a yükseltilirler
    // signed char , unsigned char , short , unsigned short , bool
    // char + char = int
    unsigned char rr = 'A';
    unsigned char yy = 'C';
    unsigned char top = rr + yy;
    printf("toplam: %d\n",top);



    // Arrays

    int a_a[10] = {1,2,3,4,5,6,7,8,9,10};
    int summ = 0;
    int array_size = (int)sizeof(a_a)/sizeof(a_a[0]);
    // array boyutu macro olarak tanımlanabilir : #define SIZE ((int)sizeof(a_a)/sizeof(a_a[0]))
    for (int i = 0; i < array_size; i++) {
        summ += a_a[i];
    }
    printf("sum: %d\n",summ );

    int str = 0;
    while (str < array_size)
        a_a[str++] = array_size - str;      // array değeri içinde işlem yapılabilir
    for (int i = 0; i < array_size; i++) printf("a_a[%d]: %d , ",i,a_a[i]);


    // array initialization
    printf("\n");
    int arr[10] = {1,2,3,4,5};      // array tanımlanırken değeri verilmeyen index 'lerin değeri default olarak 0 olur
    for (int i = 0; i < 10; i++) printf(" %d , ",arr[i]);

    printf("\n");
    int arr2[10] = {[1] = 232,[4] = 44, [8] = 4232};    // sadece istenilen indexlere değer girme ile array tanımlama, diğer indexler 0 olur
    for (int i = 0; i < 10; i++) printf(" %d , ",arr2[i]);


    int arr3[3][3] = {0};   // multiple dimensial array


    return 0;
}