#include <stdio.h>


// Pre processors
// preprocessors , tam kod execute edilemeden önce yapılır ve sonrasında execute compile edilir kodlar

// preprocessor'lar tanımlanması için yukarıdan aşağı doğru bir kural yoktur , her yerden erişilebilir
#define VAR3 VAR2


#define MY_CONST 100    // değeri 100 olan bir değişken tanımlandı
#define MY_VAR 100.0
#define VAR2 'A'
#define VAR1 MY_CONST   // macor ile yeni macor tanımlama

#define yazdir printf("İstenen Bİr FONK çalıştı\n") // sadece değer değil fonksiyon tanımı da yapılabilir

#define bir_fazlasi(x) x+1  // değer alabilen bir fonksiyon tanımalanabilir tek satır içinde
#define min(x,y) x<y ? x : y


#define DEBUG_MODE

#define program_val 2
#define version_code 'B'

#define MAX_VAL 101


int main(void) {

    printf("Size of marco: %lu\n",sizeof(MY_CONST));
    printf("Size of marco: %lu\n",sizeof(MY_VAR));
    printf("Size of marco: %lu\n",sizeof(VAR1));
    printf("Size of marco: %lu\n",sizeof(VAR2));
    yazdir;

    int x = 100;
    int y = bir_fazlasi(x);
    printf("y : %d\n",y);

    printf("Min value: %d\n",min(x,y));


    //printf("debug mode value: %d\n",DEBUG_MODE);  Değeri olmaz ama ifdef ile tanımlı olması kontrol edilir
    #ifdef DEBUG_MODE   // değer tanımlı ise true döner ve kod çalışır.
        printf("DEBUG_MODE\n");
    #else
        printf("NOT DEBUG_MODE\n");
    #endif

    #ifndef DEBUG_MODE
        printf("NOT DEBUG_MODE\n");
    #endif


    #if program_val == 1
        printf("Program Value 1 : %d\n",program_val);
    #elif program_val == 2
        printf("Program Value  2 : %d\n",program_val);
    #else
        printf("Program Value not 1 or 2: %d\n",program_val);
    #endif


    #if version_code == 'A'
        printf("version is : %c\n",version_code);
    #else
        printf("version code is not A: %c\n",version_code);
    #endif


    printf("VAR3: %c\n",VAR3);


    // Eğer koşul sağlanırsa compiler hata verecek
    #if MAX_VAL < 100
        #error Max değer 100'den küçük olamaz
    #endif


    // predefined preprocessors,
    printf("Date: %s\n",__DATE__);
    printf("Time: %s\n",__TIME__);
    printf("File: %s\n",__FILE__);



    return 0;
}