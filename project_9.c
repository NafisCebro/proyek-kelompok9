#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char username[50];
    char password[50];
} User;

User  users[100];
int jumlah_pengguna = 0;

int validasi_username(char *username) {
    // Memeriksa apakah username memiliki panjang minimal 6 karakter
    if (strlen(username) < 6) {
        printf("Username harus terdiri dari minimal 6 karakter.\n");
        return 0;
    }
    // Memeriksa apakah karakter pertama adalah huruf kapital
    if (!isupper(username[0])) {
        printf("Username harus diawali dengan huruf kapital.\n");
        return 0;
    }
    // Memeriksa apakah semua karakter selanjutnya adalah huruf kecil atau huruf
    for (int i = 1; i < strlen(username); i++) {
        if (!islower(username[i]) && !isalpha(username[i])) {
            printf("Username hanya boleh menggunakan huruf kapital di awal dan huruf kecil selanjutnya.\n");
            return 0;
        }
    }
    return 1;
}

int validasi_password(char *password) {
    int has_upper = 0, has_digit = 0, has_symbol = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) has_upper = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (ispunct(password[i])) has_symbol = 1; // Memeriksa simbol
    }
    if (!has_upper || !has_digit || !has_symbol) {
        printf("Password harus mengandung huruf kapital, angka, dan simbol.\n");
        return 0;
    }
    return 1;
}

void daftar_pengguna() {
    if (jumlah_pengguna >= 100) {
        printf("Batas pengguna telah tercapai. Tidak dapat mendaftar lebih banyak pengguna.\n");
        return;
    }

    char username[50];
    char password[50];

    printf("Pendaftaran\n");
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    
    // Memeriksa apakah username valid
    if (!validasi_username(username)) {
        return;
    }

    // Memeriksa apakah username sudah ada
    for (int i = 0; i < jumlah_pengguna; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username sudah ada. Silakan pilih yang lain.\n");
            return;
        }
    }

    printf("Password: ");
    fgets(password, sizeof(password), stdin);

    // Memeriksa apakah password valid
    if (!validasi_password(password)) {
        return;
    }

    // Menyimpan data pengguna
    strcpy(users[jumlah_pengguna].username, username);
    strcpy(users[jumlah_pengguna].password, password);
    jumlah_pengguna++;

    printf("Pendaftaran berhasil!\n");
}

void login_pengguna() {
    char username[50];
    char password[50];

    printf("Login\n");
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    printf("Password: ");
    fgets(password, sizeof(password), stdin);

    for (int i = 0; i < jumlah_pengguna; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login berhasil! Selamat datang, %s!\n", username);
            return;
        }
    }

    printf("Login gagal. Username atau password tidak valid.\n");
}

int main() {
    int pilihan;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Daftar\n");
        printf("2. Login\n");
        printf("3. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                daftar_pengguna();
                break;
            case 2:
                login_pengguna();
                break;
            case 3:
                printf("Keluar...\n");
                return 0;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}

// blok kode quis sementara
void daftar_pengguna() {

int main() {
    int ans, poin = 0;
    int kunci_jawaban[] = {2, 5, 1, 4, 3}; 
    int no_soal = 5;
    
    char *questions[] = {
    "Pertanyaan 1: Mana jawaban yang benar?\n1. Jawaban 1\n2. Jawaban 2\n3. Jawaban 3\n4. Jawaban 4\n",
    "Pertanyaan 2: Apa jawabannya?\n1. Jawaban 1\n2. Jawaban 2\n3. Jawaban 3\n4. Jawaban 4\n",
    "Pertanyaan 3: Pilih opsi yang benar.\n1. Jawaban 1\n2. Jawaban 2\n3. Jawaban 3\n4. Jawaban 4\n",
    "Pertanyaan 4: Apa jawaban yang benar?\n1. Jawaban 1\n2. Jawaban 2\n3. Jawaban 3\n4. Jawaban 4\n",
    "Pertanyaan 5: Pertanyaan terakhir!\n1. Jawaban 1\n2. Jawaban 2\n3. Jawaban 3\n4. Jawaban 4\n"
    };


    for (int i = 0; i < no_soal; i++) {
        printf("%s", questions[i]);
        printf("Masukan Jawabanmu : ");
        fgets(ans, sizeof(ans), stdin);

        if (ans == kunci_jawaban[i]) {
            poin += 20; 
            printf("Benar! point anda sekarang %d .\n\n", poin);
        } else {
            printf("Salah! Game over... anda berhasil mendapatkan %d poin.\n", poin);
            return 0;
        }
    }

    printf("Selamat! anda memenangkan permainan ini dengan %d points!\n", poin);
    return 0;
}
}// akhir blok kode quiz
