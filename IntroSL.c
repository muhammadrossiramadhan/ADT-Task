#include <stdlib.h>
#include <stdio.h>
#include "BasicSL.h"

// Self Refference Structure : struktur yang berisi pointer sebagai petunjuk yang menuju ke struktur yang bertipe sama
// gunanya untuk apa, yaitu untuk menggabungkan dua tipe yang berbeda sehingga menjadi satu dan biasanya dipanggil stuktur atau node.

struct node{

    int value;
    struct node *next;
};


int main (){

    printf("\nini introduction apa itu, kenapa harus, bagaimana caranya, kapan harus pakai linked list\n");

    // GA USAH BINGUNG, Sebenarnya gini struct node itu nama tipe data kita buat yanng isi tadi itu :
    // int value dan struct node *next tapi disini itu bukan si struct node *next terus nextnya kita ganti *head itu bukan
    // ini cuman cara untuk memanggil si tipe data yang sudah kita bua yang mencakup dua tipe variabel yang berbeda.

    struct node *pakai = NULL;

    // Buat node di aloksi memori menggunakan malloc ()

    pakai = malloc(sizeof(struct node));

    // cara menggunakan linked list ini itu gimana dan cara aksesnya gimana ?
    // biasanya orang orang itu pakainya head->value=45; tapi sama aja kok sebenarnya sama aja kok terngatung pemahaman
    // yang artinya dia mengambil nilai dari alamat head yang terkonek ke sturct node untuk mengambil attribut yang ada disitu.
    // head->value=45; itu sama aja dengan (*head).value = 45;

    pakai->value=45;
    pakai->next=NULL;

    // kalau kita ingin buat node baru, maka kita wajib buat malloc lagi gitu
    struct node* current = malloc(sizeof(struct node));

    current->value = 50;
    current->next = NULL;

    // Cara menghubungkan node pertama dan kedua itu harus pakai cara ini :
    pakai->next = current;

    // coba buat node 3
    current = malloc(sizeof(struct node));
    current->value = 10;
    current->next = NULL;
    pakai->next->next = current;
    // kita print kan hasilnya

    printf("\n%d\n",*pakai->next);

    // jadi kesimpulan sementaranya adalah kalau kita setelah kita berhasil nih, head->next = current;
    // kita bisa tahu tuh head->next = 50 sehingga yang tadinya NULL sekaran udah ke isi sebuah nilai baru gitu aja.

    // oke mari kita coba hubungkan dengan cara kedua, jadi kalau kita ingin akses node ketiga maka simplenya kita gak perlu
    // current->next lagi dan kita tahu oh itu punya yang ketiga, tapi kita bisa aja langsung pakai : head->next->next

    // jadi simplenya head->next itu ambil alamatnya si current dan didapatkanlah 50 itu nah lalu kita -> next lagi dari sialamatnya
    // current ini kita menuju si current->nextnya alias isinya apa kira kira yaitu 10 karena kita udah hubungin ama current2

    printf("%d\n",*pakai->next->next);

    printf("\ncontoh contoh kalau pakai fungsi atau tingkat basicnya linked list\n");

    // ini dibawah bawah ini adalah beberapa basic basic yang setidaknya kalian semua pahami dari linked list itu apa ?

    // ini sama aja kayak kita bikin 3 node di fundamental.c, isisnya tetep sama dan yang berubah hanya kita menambahkan 
    // pemanggilan fungsi 
    
    // jangan lupa untuk di panggil kembali ke sini lagi

    // node 1
    struct node *head;
    allocate(&head,5);

    // node 2
    add_at_the_end(head,10);

    // node 3
    add_at_the_end(head,15);

    // uji pemanggilan berbagai fungsi diatas main
    count_of_nodes(head);
    print_nodes(head);

    add_at_the_end(head,25);
    print_nodes(head);
    
    add_at_the_Beginning(&head,0);
    print_nodes(head);

    add_at_pos(head,20,5);
    print_nodes(head);

    delete_at_first(&head);
    print_nodes(head);

    delete_at_end(&head);
    print_nodes(head);

    delete_at_pos(&head,3);
    print_nodes(head);

    search_node(head, 10);
    print_nodes(head);

    destroy(&head);
    print_nodes(head);

    return 0;
}