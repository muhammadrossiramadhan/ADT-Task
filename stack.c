// import pendefinisian prototype fungsi dan import serta struct stack pada file header
#include "stack.h"

// fungsi untuk mengalokasikan memori stack menggunakan paramater pointer berisi top dan cur size guna melihat bahwa sebgai nilai 
// default awal sebelum ditambahkan dibuktikan dengan analisi S->top = NULL itu dia membuat nilai inisialisasi yakni 0 dan curSIze
// tersebut meyimpan berapa banyak elemen yang sudah tersimpan saat melakukan fungsi push

void allocateStack(struct Stack *S) {
    S->top = NULL;
    S->curSize = 0;
    printf("[Sistem] Memori Stack berhasil dialokasikan (Inisialisasi).\n");
}
// saranku allocatestack ini masih kaku akan output trigger massage seprti apa sehingga kau perlu menambahkan agar aku paham lah
// main mu itu apa karena nanti setiap tahap itu yang di main isinya satu fungsi ya satu fungsi ditampilkan output berjejer dilaporan
// tidak jadi satu seperti di main program kamu

// Fungsi untuk mencetak elemen dari TOP sampai bawah
void print_nodes(struct Stack S) {
    if (S.top == NULL) {
        printf("Stack kosong, tidak ada yang bisa dicetak.\n");
        return;
    }

    struct NodeStack *ptr = S.top;
    
    printf("Isi Stack (Puncak ke Bawah): [");
    while(ptr != NULL) {
        printf("%d", ptr->value);
        
        if(ptr->next != NULL) {
            printf(", "); 
        }
        ptr = ptr->next;
    }
    printf("]\n");
}

// fungsi untuk membuat nilai 1 dan 0 atau logika benar atau salah sehingga kalau ketika stack tak pernah diisi atau push maka
// dia return kosong dan membuat pesan untuk mengetahui
bool isEmptyStack(struct Stack S) {
    if (S.top == NULL) {
        printf("[Info] Cek Stack: Status Kosong.\n");
        return true;
    }
    return false;
}

// fungsi yang memberi tahu program kalau jumlah elemen node telah melebih batas maksimal yang sudah kita definisikan tadi
bool isFullStack(struct Stack S) {
    if(S.curSize == MAX_STACK) {
        printf("PERINGATAN : STACK SEKARANG PENUH\n");
        return true;
    }else{
        printf("MASIH AMAN \n");
        return false;
    }
}

// fungsi untuk melakukan push dengan paramater struct stack dan nilai element yang akan diinput
void push(struct Stack *S, int element) {
    // jika stack melebihi batas, disini lah kondisi tersebut berkerja atau lebih dikenal stack overflow
    if (S->curSize == MAX_STACK) {
        printf("Stack Full! Gak bisa push %d\n", element);
        return;
    }

    // Disini kita melakukan malloc() guna untuk membuat node baru dari isian parameter yang ada yakni node newElement
    // yang merujuk pada ukuran struct nodestack yang berisi value dan next untuk proses linked list dibuat
    struct NodeStack *newElement = malloc(sizeof(struct NodeStack));
    // lalu kita mengisi value tersebut dengan element 
    newElement->value = element;
    
    // lalu kita mengisi next yang biasanya NULL, kita assignment S->top, S->top itu adalah tempat menambahkan nilai variabel dimana
    // saat ini yang tertambahkan adalah yang teratas dari stack lainnya atau biasa dikenal LIFO ( Last in First out ), ketika itu
    // terjadi pada elemen pertama itu elemen yang teratas begitu seterusnya terdapat element selanjutnya yang nanti ditambah akan
    // menjadi elemen teratas
    newElement->next = S->top;
    // lalu saat sudah menjadi elemen teratas dari sebuah assignment, jangan lupa untuk memberikan nilai newElement yang berisi 
    // element atau data yang di input untuk diassignment pada S->top menjadi stack yang teratas
    S->top = newElement;
    
    // jangan lupa untuk menambahkan curSize++ karena itu adalah tempat kita untuk mentrigger bahwasanya nanti ketika sudah mencapai
    // nilai maksimum.
    S->curSize++;
    // cetak bahwa push berhasil
    printf("Push: %d berhasil\n", element);
}


// fungsi untuk menghapus nilai elemen sama kayak delete gitu tetapi disini untuk menghapus elemennya itu dari atas maka bisa dibilang
// yang diambil itu dari node linked list yang terakhir atau reverse sehingga masuk logika LIFO nya gitu.
int pop(struct Stack *S) {
    // kondisi ketika stack ternyta sudah penuh maka return -1 mungkin itu adalah bentuk non eksekusi atau exit
    if (isEmptyStack(*S)) return -1;
    
    // kita buat node baru yaitu *current_top yang nilainya itu S->top, jadi nilai yang diambilnya itu nilai teratas karena si top 
    // itu kan pointer sehingga dia itu otoamtis refersh nilai yang terbaru atau paling atas atau mengadress lah yang new.
    struct NodeStack *current_top = S->top;
    // ini mungkin kalau analaisis ku ya 
    // lalu dia ngakses ke value kok bisa ya ? dia itu kan awalnya *current_top awalnya pointer yang menurut ku refference ke 
    //  struct tapi masih belum aku analisis kenapa bisa karena masih hipotesa lebih tepatnya
    int element = current_top->value; 
    
    // ini untuk logika set ini guna untuk menghindari memori leak aja gitu atau dia simpen ke tempat penyimpanan sementara sebelum
    // dihapus, sehingga node stack dibawahnya menjadi yang teratas karena dia dipanggil dengan link yaitu current_top->next istilahnya
    // menjaga rantainya tetap terseambung
    S->top = current_top->next;
    
    // membebaskan memori dalam alokasi elemen node yang paling atas saat ini yaitu refference ke S->top
    free(current_top);
    // jangan lupa decrement, biar program tahu atau lebih tepatnya fungsi alokasi yang attributnya itu auto update 
    S->curSize--;

    // mengebalikan elemet
    return element;
}

//  ini kayaknya cuman ngecek nilai mana yang paling atas tapi kurang output printf ga ada sama kyak allocate 
int top(struct Stack S) {
    if (isEmptyStack(S)) return -1;
    printf("nilai top saat inI : %d\n",S.top->value);
    return S.top->value;
}

// ini fungsinya kayaknya sama kaya destory yakni mengembalikan seluruh node stacknya ke memori yang sudah kita pakai
void deallocateStack(struct Stack *S) {
    while (S->top != NULL) {
        pop(S);
    }
    printf("Memory Stack didealoakasi.\n");
}