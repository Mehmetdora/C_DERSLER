#include <stdio.h>




// Bitwise operators


struct FilePermissions {
    unsigned char open : 1;         // sadece 1 bit yer kaplar
    unsigned char close : 1;
    unsigned char execute : 1;
    unsigned char owner_id : 5;     // 5 bit yer kaplar.
};


int main(void) {

    unsigned char num = 10;   // 1010
            // 5 ->    0101
    num = num | 5;  // 1111 -> 15 yapar
    printf("OR: %d\n", num);

    num = num & 5;      // 5 yapar
    printf("AND: %d\n", num);

    num = 10;       // 1010
    num = num ^ 5;  // 0101     --> farklı olanlar 1 olur, 1111
    printf("XOR: %d\n", num);

    num = 15;   // 0000 1111
    num = ~num; // 1111 0000        tersini al
    printf("NOT: %d\n", num);


    num = 10;
    num = num << 1;     // bir bit sola kaydır, yani 2 katını al
    printf("SHL: %d\n", num);

    num = num >> 2;     // 2 bit sağa kaydır, yani 4 e böl
    printf("SHR: %d\n", num);



    // Bit masking
    num = 10 ; // 0000 1010
    unsigned char mask = 1;     // 0000 0001
    if (mask & num) {   // sayının son biti 1 ise sonuç 1 çıkar ve true döner , 0 ise 0 çıkar ve false döner

    }


    // Bit setting
    unsigned char flags = 0;    // 0000 0000
    flags |= (1 << 3);          // 0000 1000 , burada yapılan 1 sayının sondaki bitini(1) 3 kez sola kaydırmak
                                // bu sayede istenen bit set edilir
    printf("FLAGS: %d\n", flags);

    // bit clearing
    flags = 9;      // 0000 1001 , 4. bitini 0 yapar ve değer 1 olur.
    flags &= ~(1 << 3); // 3. biti önce 1 sonra tersini alarak 0 yapar. flags değeri -> 1111 0111 olur
    printf("FLAGS: %d\n", flags);




    struct FilePermissions my_file;

    // Değer atama
    my_file.open = 1;      //   1 bitten fazla bir değer verilirse en son bir bit kullanılır sadece
    my_file.close = 0;     //
    my_file.execute = 1;   //
    my_file.owner_id = 28; // 0-31 arası bir değer (5 bit)

    // Değerleri okuma
    printf("Open Permission: %d\n", my_file.open);
    printf("Owner ID: %d\n", my_file.owner_id);
    printf("Size of struct: %lu byte\n", sizeof(my_file));  // toplam 8 bitlik bir yapı oldu.


    return 0;
}