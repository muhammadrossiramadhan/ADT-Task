// disini menampilkan ifndef dan define untuk mencegah duplikasi file header 
#ifndef STACK_H
#define STACK_H

// disini kita import module boolean, input output, lib untuk malloc dari library C
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// Sebenarnya linked list itu tak ada batasnya untuk isFULL berapa, tapi karena dalam tugas saya pakai isFULL, maka saya 
// mendefinisikan bahwasanya maximal tumpukan hanyalah 5 saja atau bisa dibilang 5 node linked list.
#define MAX_STACK 5 

// terdapat struc yang berisi dua tipe yakni int dan pointer, int guna sebagai objek refference dari input yang masuk nanti,
// lalu pointer itu berguna untuk link pada tiap node stack yang akan disambungkan dengan node lainnya
struct NodeStack {
    int value;
    struct NodeStack *next;
};

// terdapat stuct dari 2 tipe variabel yaitu int cursize guna menyimpan ukuran saat ini hingga memberikan aksi yang dilakukan sebuah
// fungsi tertentu sehingga pada jumlah maksimal yang didefinisikan diatas, kita harus melakukan drop atau pop kalau di stack
struct Stack {
    struct NodeStack *top;
    int curSize;
};

// terdapat beberap Prototipe Fungsi yang akan kita gunakan

// untuk mengalokasi memori pada sebuah linked list stack
void allocateStack(struct Stack *S);
// untuk memasukkan atau insert elemen yang kita namain push
void push(struct Stack *S, int element);
// untuk mengeluarkan atau drop elemen yang kita namain pop
int pop(struct Stack *S);
// untuk mengambil atau melihat elemen yang paling atas pada sebuah linked list
int top(struct Stack S);
// untuk melihat apakah stack kosong apa ndak ?
bool isEmptyStack(struct Stack S);
// untuk memberikan alert ketika stack telah melebih jumlah maksimal dari pendefinisian maximal stack tersebut
bool isFullStack(struct Stack S);
// untuk memberbaskan sebuah memori yang terlalokasi dengan menggunakan free()
void deallocateStack(struct Stack *S);
// untuk menampilkan hasil output node yang dibuat
void print_nodes(struct Stack S);

#endif