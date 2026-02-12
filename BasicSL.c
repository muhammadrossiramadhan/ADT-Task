#include "BasicSL.h"

// ini fungsi dealocate yang fungsinya jelas adalah untuk membebaskan nilai dari parameternya, contohnya ketika di fungsi delete 
// itu kita harus melakukan tindakan free(head) dan head=null itu bisa dengan simplenya kita pakaia dealocate aja, sebenarnya ini 
// jarang digunakan di main tapi seringnya di fungsi aja sih ini,kalau mau pakai di main tinggal deallocate(head), nah nanti kalau 
// dijalanin itu print_nodes(head); malah kena segmentation fault dan itu aritnya kita itu ya gak bisa akses node 2 dan seterusnya 
// karena node utama alias head karena kena hapus atau udah free atau lebih mudahnya kita ga bisa akses node yang udah difree dan 
// menjangkau node yang lainnya.
void dealocate(struct node *head){
    if( head != NULL){
        free(head);
        head = NULL;
        printf("Memory dihapus\n");
    }
}

// nah ini fungsi allocate, ga usah bingung, ini fungsinya cuman buat alokasi memori aja, yang pertama disitu ada pointer to pointer
// head tipe data struct node kenapa kok pakai double pointer karena supaya kita mudah aja gitu ngeditnya untuk alokasi dan gak bolak
// balik pakai malloc lagi dan harus banget tuh pakai head = nama_fungsi kalau dia bertujuan return tapi kalau fungsinya pakai ini *
// alias satu bintang, kamu harus bolak balik update buat main dan fungsinya buat return jadi gabisa automatic dan disinilah fungsi
// dari duoble pointer biar yang di rujuk itu alamatnya langsung biar cepet, automatic, bisa kasih nilai aja langsung dari manggil
// fungsi ini tanpa harus assignment ke head yang perlu update setiap kalinya.

// panggil saja ini remote control atau teknik pass by refference.
void allocate(struct node **head, int value){
    // kalau kosong headnya, tampiliin apa kek gitu.
    if ( *head == NULL ){
        printf("\nlinked list kamu itu kosong\n");
    }
    // pakai malloc biasa aja, nah disini itu kan ada head kamu jangan lupa isi dan kasih *head disitunya.
    *head = malloc(sizeof(struct node));
    //ini isi kayak biasanya buat linked list pada umumnya tapi jangan lupa kalau dikasih kurung gini biar jelas aja : (*head).
    (*head)->value = value;
    (*head)->next = NULL;
    // cetak display.
    printf("\nberhasil mengalokasikan %d\n", (*head)->value);
}

// ini adalah fungsi menghitung untuk bisa menyusuri setiap node hingga mencapai node terakhir.
void count_of_nodes(struct node *head){
    // ini adalah variabel biasa untuk kita hitung seberapa banyak sih node yang kita buat.
    int iterasi = 0;
    // jika head sama dengan NULL maka dia akan cetak bahwasanya linked listnya kosong gitu.
    if ( head == NULL ){
        printf("linked list kamu itu kosong");
    }
    // lalu kita buat pointer lagi disini gunanya untuk sebagai alat rujuk untuk menyusuri setiap node hingga akhir
    // disini kita isi NULL aja, guna mempermudah pemahaman.
    struct node *ptr = NULL;
    // kita isi ptr tersebut dengan nilai head berarti otomatis dia diisi dengan alamat yang sama dengan head.
    ptr = head;
    // kita buat perulangan yang persyaratannya itu kalau ptr tidak kosong maka dia terus menyusuri tiap node hingga akhir
    // ptr disini tidak kosong dalam artian kalau kita lihat valuenya itu gak NULL gitu bukan nextnya.
    while(ptr != NULL){
        // ini buat ngitung berapa banyak node yang dilewati pakai iterasi yang dideklarasikan.
        iterasi++;
        // ini untuk pindah dari alamat head ke alamat selanjutnya dengan memakai ptr->next.
        ptr = ptr->next;
    }
    // ini untuk mencetak iterasi yang sudah ditugaskan untuk menyusuri setiap node dari awal hingga akhir.
    printf("\nPrint count of nodes : %d\n",iterasi);
}

// ini adalah fungsi mencetak elemen pada setiap node hingga akhir pada linked list biar kita tahu aja linked list kita udah jadi.
void print_nodes(struct node *head){
    // jika head sama dengan NULL maka dia akan cetak bahwasanya linked listnya kosong gitu.
    if ( head == NULL ){
        printf("linked list kamu itu kosong");
    }
    // lalu kita buat pointer lagi disini gunanya untuk sebagai alat rujuk untuk menyusuri setiap node hingga akhir
    // disini kita isi NULL aja, guna mempermudah pemahaman.
    struct node *ptr = NULL;
    // lalu baru kita bisa isi ptr tersebut dengan nilai head berarti otomatis dia diisi dengan alamat yang sama dengan head.
    ptr = head;
    // kita buat perulangan yang persyaratannya itu kalau ptr tidak kosong maka dia terus menyusuri tiap node hingga akhir.
    printf("\nPrint Linked list: ");
    while(ptr != NULL){
        //cetak
        printf("%d",ptr->value);
        // Cek: Apakah ini bukan node terakhir?
        if(ptr->next != NULL) {
            printf(", "); // Cetak koma hanya jika masih ada node berikutnya.
        }
        // ini untuk pindah dari alamat head ke alamat selanjutnya dengan memakai ptr->next.
        ptr = ptr->next;
    }
    // cetak spasi aja sih ini, ga penting.
    printf("\n\n");
}

// ini adalah fungsi menambahkan node elemen di akhir.
void add_at_the_end(struct node *head, int newvalue){
    // kita deklarasikan pointer ptr dan temp yang pastinya tipe data struct node guna bisa akses alamat yg ada attributnya.
    struct node *ptr, *temp;
    // kita isi ptr tersebut dengan nilai head berarti otomatis dia diisi dengan alamat yang sama dengan head.
    ptr = head;
    // kita buat malloc untuk buat alokasi alamat yang baru untuk bisa digunakan update.
    temp = malloc(sizeof(struct node));
    //kita isi data atau valuenya dan pointer nextnya.
    temp->value = newvalue;
    temp->next = NULL;
    // kita buat perulangan yang persyaratannya itu kalau ptr tidak kosong maka dia terus menyusuri tiap node hingga akhir.
    while(ptr->next != NULL){
        // ini untuk pindah dari alamat head ke alamat selanjutnya dengan memakai ptr->next.
        ptr = ptr->next;
    }
    // jika null setelahnya, tambahkan value atau elemen node baru.
    ptr->next = temp;
    printf("update value di bagian akhir tertambahkan %d\n",temp->value);
  
}

// FYI : JIKA KAMU GA SUKA DENGAN RETURN, KAMU BISA PAKAI VOID TAPI UNTUK ALAMAT HEAD PADA TIPE STRUCT NODE HARUS **NAMA VARIABEL
// DAN PASTIKAN UNTUK SEMUA AKSES KETIKA INGIN HEAD SEBAGAI ASSIGNMENT ITU HARUS *HEAD, SINGKATNYA GINI :
// STRUCT NODE* ---> RETURN.
// VOID ---> DOUBLE POINTER.
// karena ini fungsinya itu harus mengembalikan nilai karena kita mengubah headnya otomatis yang ada di main itu harus berubah juga
// jadi begitu teman teman kenapa harus pakai double pointer.

// ini adalah fungsi menambahkan node elemen di akhir.
    void add_at_the_Beginning(struct node **head, int newvalue){
    // kita deklarasikan pointer ptr guna bisa merujuk pada setiap node hingga akhir mencari next kosong.
    struct node *ptr = malloc(sizeof(struct node));
    
    // kita isi dulu value dan nextnya pada pointer yang menjadi rujukan insert pada awal elemen, seperti newvalue yang jadi rujukan.
    ptr->value = newvalue;
    ptr->next = NULL;
    
    // kita bisa lihat bahwasanya ptr next atau ptr yang null, kita bisa isikan langsung dengan head atau awal elemen node yang ada
    // sehingga saat ini terdapat alamat baru pada next head yang kita buat.
    ptr->next = *head;
    // pada saat ini jangan lupa untuk head diubah penunjuknya ke pointer yang baru dibuat supaya mereka tetap logis pada
    // urutan memori alokasi yang tidak hanya di tampilan displaynya saja ketika di print.
    *head = ptr;
    // cetak.
    printf("update value di bagian awal tertambahkan %d\n",ptr->value);
    
}

    // ini adalah fungsi menambahkan node elemen pada posisi tertentu, ini gak perlu pakai stuct deh karena gk ubah head.
    void add_at_pos(struct node *head, int newvalue, int position){
    // kita deklarasikan pointer ptr dan temp yang pastinya tipe data struct node
    // kita buat alamat dan nilainya ptr itu sama dengan head sebagai node pertama guna berpindah setiap node jadi mudah.
    struct node *ptr = head;
    //kita buat node baru yang sesuai pada pata dan position yang akan kita taruh nanti.
    struct node *temp = malloc(sizeof(struct node));

    // kita buat node baru terlebih dahulu
    temp->value = newvalue;
    temp->next = NULL;
    
    // kita set default position ini berkurang guna untuk bisa menaruh position yang kita inginkan sehingga saat di perulangan 
    // nanti dia akan berada sebelum node terakhir alias NULL. 
    position--;
    // perulangan biasa untuk ptr berpindah pindah setiap nodenya jika ptr tersebut tidak null yang memiliki alamat 
    // dan value mula yang sama dengan : head
    // disini postion yang pakai karena jika position itu sama dengan 1 maka dia false atau berhenti guna berhenti sebelum ke 
    // node terakhir yaitu NULL. 
    while(position != 1){ 
        ptr = ptr->next;
        // kita perlu decrement position lagi guna dia terus berkurang hingga 1.
        position--;
    }
    
    // setelah tidak null, kita update lah node baru yakni temp dengan nextnya itu adalah ptr yang paling terakhir.
    temp->next = ptr->next;
    // baru kita bisa untuk mengubah nextnya ptr dengan yang dimiliki node baru yaitu ptr2 untuk nanti diletakkan antara
    // posisi ke setelah node 2 dan sebelum node 3.
    ptr->next = temp;
    
    printf("update value di bagian posisi tertambahkan %d sebelum %d\n", temp->value, *temp->next);
}
    // ini adalah fungsi menghapus node elemen di awal, gampangnya disini rata rata kalau delete itu pasti pakai double pointer
    // karena mau ga mau dia ada hubungannya ama ubah posisi dari si head itu.
    void delete_at_first(struct node **head){
    // jika head kosong maka dia akan kasih pesan gitu.
    if(*head == NULL){
            printf("linked list sudah kosong!");
    }

    // disini kita buat temp atau variabel node baru guna membuat node sementara untuk menyimpan.
    struct node *temp = *head;
    // nah sebelum hapus itu mending lu jaga headnya ke node selanjutnya karena head yang saat ini mau dihapus, soalnya kalau udah
    // kadung hapus duluan bakalan segmentation fault ntar.
    *head = (*head)->next;
    //cetak
    printf("menghapus value di bagian awal %d\n", temp->value);
    // nah ini fungsi deallocate buat bebasin memori yang tadi kehapus, bisa scroll ajalah keatas.
    dealocate(temp);




}

// ini adalah fungsi menghapus node elemen di akhir
    void delete_at_end(struct node **head){
    
    // jika head kosong maka dia akan kasih pesan gitu
    if(*head == NULL){
        printf("linked list sudah kosong!");
    // jika headnya cuman 1 doang maka kondisi ini terpenuhi soale ya kan cuman 1 langsung hapus ae headnya dia kan node utama.
    }else if((*head)->next == NULL){
        free(*head);
        *head = NULL;
    }
    // ini buat dua node kenapa kok bisa gitu ?, 2 node yang saling nunjuk ke head ini supaya dia berguna buat ketika nanti node
    // terakhir kita hapus itu otomatis buat node sebelumnya yang isi nextnya adalah alamat dari node yang dihapus tersebut hilang
    // dengan cara kita setting null di akhir perulangan. 
    
    // ini buat yang mau dihapus nodenya yang mana.
    struct node *temp = *head;
    // ini buat node yang mau dijadikan automatic nullnya.
    struct node *temp2 = *head;

    // perulangan yang kita singgung tadi yang kondisinya terpenuhi kalau semisal next temp nya itu tidak null alias lanjut
    // hingga ke belakang sampai ujung dah namanya juga akhir ya kan.
    while(temp->next != NULL){
        // nah ini temp2 tadi kita singgungkan sebelum dia automatic null sebelum node dihapus, dia itu harus banget simpan value
        // dan nextnya yang sekarang ini sebelum si temp diupdate, kalau si temp2 dia bakalan update satu langkah mundur dari temp
        // tiap perulangannya, program itu jalan urut dari atas kebawah kok.
        temp2 = temp;
        temp = temp->next;
    }
    // terus untuk next temp2 kita jadikan null dari kondisi perulangan yang udah mentok ujung kita otomatic jadikan null karena si
    // temp itu bakalah dihapus, alias kita putuskan lah nextnya antara node yang ada dengan node yang mau dihapus.
    temp2->next = NULL;

    // Cetak display dulu biar tahu apa yang dihapus gitu
    printf("menghapus value di bagian akir %d\n", temp->value);
    
    // nah ini fungsi deallocate buat bebasin memori yang tadi kehapus, bisa scroll ajalah keatas, dan si temp udah kehapus dan
    // rantainya udah keputus dari awal si temp2 udah diset NULL.
    dealocate(temp);

}

// ini adalah fungsi menghapus node elemen pada posisi.
    void delete_at_pos(struct node **head, int position){
    // ini ada dua node kayak biasanya kita butuh supaya dia bisa nge link ke node selanjutnya.
    
    // ini buat maju ke depan cari mana yang mau dihapus.
    struct node *current = *head;
    // ini buat nge link ke node selanjutnya setelah node current dengan link nextnya si current->next itu jadi nyambung nanti.
    struct node *previous = *head;
    
    // jika head kosong maka dia akan kasih pesan gitu.
    if(*head == NULL){
        printf("linked list sudah kosong!");
    // kalau poisinya cuman 1 node, ya kalian tahulah tinggal hapus aja lah.
    }else if (position == 1){
        // head butuh nyalin dulu sebelum di hapus atau gak jadi memory leak pastinya, jadi itu gunanya si current selain buat
        // hapus dia juga sebagai tempat penyimpanan sementara. kalau bingung sama aja sih kayak *head = (*head)->next dah itu
        // sama aja cuman biar konsiten pakai current kan sama sama megang si value adalah *head. 
        *head = current->next;
        // hapus aja kayak biasanya.
        dealocate(current);
    }
    // kalau posisinya udah beda dari 1 node kayak semisal kamu pengen posisi lebih dari 1 hingga seterusnya itu pakai si current
    // itu berkerja aja dimana kita buat si previous nyalin alamat si current dulu yang dimana si current nanti update ntar kalau
    // si position udah sama dengan 1 dia berhenti tuh dan lanjut eksekusi perintah di luar loopingnya.
    while(position != 1){
        // simpan dan salin dulu bair ngikut dari belakang curent kayak satu langkah mundur dari current saat ini ada.
        previous = current;
        // si current nya update dan next currentnya bakalan jalan sampai position sama dengan satu atau false.
        current = current->next;
        // ini decrementnya.
        position--;
    }
    // nah yang previous tadi kan udah satu langkah mundur dari current nah sekarang tinggal ngelink aja dari next previous ke
    // next currentnya
    previous->next = current->next;
    // cetak dulu gab
    printf("menghapus value pada posisi node yang diiginkan %d\n",current->value);
    // nah ini fungsi deallocate buat bebasin memori yang tadi kehapus, bisa scroll ajalah keatas
    // hapus aja posisi yang kita mau itu, dan beres
    dealocate(current);


}

// fungsi yang gunanya buat nyari elemen node dan posisi nya dimana dia
void search_node(struct node *head, int target) {
    // kaita buat pointer nya dulu 
    struct node *ptr = head;
    // terus buat posisi
    int posisi = 1;
    // terus buat boolean buat nanti kalau ketemu akan set 1 atau true
    int ditemukan = 0; // Variabel penanda (boolean type)

    // jika head kosong maka dia akan kasih pesan gitu.
    if (head == NULL) {
        printf("Linked list kosong, tidak ada yang bisa dicari.\n");
        return;
    }
    // jika elemen yang dicari ada, ini kondisi perulanagan bakalan dieksekusi bro selama gak null aja
    while (ptr != NULL) {
        // jika ptr valuenya sama dengan target maka dia akan mencetak target dan poisi 
        if (ptr->value == target) {
            printf("Data %d ditemukan pada posisi ke-%d\n", target, posisi);
            ditemukan = 1;
            break; // Berhenti cari kalau sudah ketemu
        }
        // ini proses carinya kalau dia ada dimana gitu dan terus beriterasi juga posisinya
        ptr = ptr->next;
        posisi++;
    }
    
    // jika elemen yang dicari gak ada, ini kondisi bakalan dieksekusi
    if (ditemukan == 0) {
        printf("Data %d tidak ditemukan di dalam list.\n", target);
    }
}

// ini fungsi kayak mengahpus seluruh node atau delete all atau destroy bedanya ama dealocate dia cuman satu atau spesifik
// kalau ini pakai perulangan untuk hapus ajalah semua isi node linked listnya biar bebas memori gitu

// pakai double pointer supaya perubahannya nyampek ke main, dan gak bolak balik aku harus assignment
void destroy(struct node **head) {
    struct node *current = *head;
    struct node *next;

    while (current != NULL) {
        next = current->next; // 1. Simpan alamat node berikutnya
        free(current);        // 2. "Destroy" node saat ini
        current = next;       // 3. Pindah ke node simpanan tadi
    }
    
    *head = NULL; // 4. Pastikan head di main jadi NULL
}
