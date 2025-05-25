#include <stdio.h> // header file agar bisa printf dan scanf
#include <time.h> // header file agar bisa menampilkan waktu, saat ini atau untuk kode yang berhubungan dengan waktu (akan ada penjelasan di bawah)
#include <windows.h> // header file agar bisa menampilkan popUp

void showPopup(const char *message) { //Fungsi ini merupakan fungsi untuk membuat popUp message
    MessageBox(NULL, message, "Reminder untuk:", MB_OK | MB_ICONINFORMATION); //ini merupakan program dari apa saja yang akan ditampilkan pada popUp windows message
}

void reminder(){ // Fungsi bernama reminder
    char namaReminder[50]; // Variable untuk menyimpan nama reminder
    char reminderOutput[100]; // variable untuk menyimpa output reminder
    int hr, bln, thn, jm, mnt; // variable untuk menyimpan waktu reminder

    time_t waktuSekarang = time(NULL); // variable untuk menyimpan waktu saat ini dalam bentuk yang dibaca oleh komputer
    char *string_waktuSekarang = ctime(&waktuSekarang); // Bagian ini adalah agar waktu yang diberikan menjadi bisa dibaca
    printf("Waktu Sekarang: %s\n", string_waktuSekarang); // Bagian ini untuk print string waktu yaitu: string_waktuSekarang

    printf("Masukkan nama reminder: "); // bagian ini untuk mencetak perintah masukan nama reminder
    scanf("%s", &namaReminder); // bagian ini untuk membaca input nama reminder yang dimasukan oleh user

    printf("Masukkan hari dan waktu: (tgl bln thn jam menit)\n"); // bagian ini untuk mencetak perintah memasukan waktu reminder
    scanf("%d %d %d %d %d", &hr, &bln, &thn, &jm, &mnt); // bagian ini untuk membaca input waktu reminder dari user


    struct tm reminderInput = {0}; // Varibel dengan tipe struct tm untuk menyimpan waktu dengan nama waktu reminder dan default {0}
    reminderInput.tm_mday = hr; // menyimpan tanggal yang dimasukan pada variable hr ke tm_mday.
    reminderInput.tm_mon = bln - 1; // menyimpan bulan yang dimasukan pada variable bln ke tm_mon. dan dikurangi 1 karena 0 = januari dan 11 = desember
    reminderInput.tm_year = thn - 1900; // menyimpan tahun yang dimasukan pada variable thn ke tm_year. dan dikurangi 1900
    reminderInput.tm_hour = jm; // menyimpan jam yang dimasukan pada variable jm ke tm_hour.
    reminderInput.tm_min = mnt;// menyimpan menit yang dimasukan pada variable mnt ke tm_min.
    reminderInput.tm_sec = 0;// menyimpan detik yang dimulai dari 0

    time_t waktuReminder = mktime(&reminderInput);//bagian ini untuk mengubah struktur tm menjadi time_t, dan mktime agar input yang dimasukan bisa dibaca oleh komputer
    while(1){ // Bagian ini adalah loop infinite
        time_t waktuSekarang = time(NULL); // bagian ini, time(NULL) menjadi bentuk time_t
        if(waktuSekarang >= waktuReminder){// bagian kondisional, apabila waktu sekarang itu lebih besar sama dengan waktu yang diinputkan reminder, maka:
            sprintf(reminderOutput, "%02d/%02d/%d %02d:%02d\n\n Sudah waktunya untuk: %s", hr, bln, thn, jm, mnt, namaReminder);// mencetak reminder output yang dikelompokkan dengan "sprintf"
            showPopup(reminderOutput);// memunculkan popup yaitu reminder output
            break; // bagian ini adalah untuk menghentikan loop ketika popUp sudah muncul
        }
        Sleep(1000); // bagian ini supaya program menunggu selama 1 detik sebelum mengecek ulang loop while agar komputer tidak lambat
    }
}


int main(){ // fungsi utama
    char user[50]; // variable yang menyimpan nama user

    printf("Masukan Nama User: "); // mencetak perintah untuk memasukan nama user
    scanf("%49s", user); // membaca nama user yang dimasukan
    printf("Hi %s! :D\n\n", user); // mencetak kalimat sapaan dengan nama user

    reminder(); //memanggil fungsi reminder yang sudah dibuat di awal
    return 0;
}
