#include <iostream>
#include <conio.h>
#include <string>
#include <limits>

using namespace std;

struct User {
    string nama;
    string nim;
};

struct Hewan {
    string nama;
    char umur[10];
    float berat;
    int harga;
};

struct Node {
    Hewan data;
    Node* next;
};

struct LinkedList {
    Node* head;
};

bool login(User* user) {
    const int maxAttempts = 3;
    int attempts = 0;

    const User correctUser = {"muhammad agill firmansyah", "2309106018"};

    while (attempts < maxAttempts) {
        cout << "Masukkan Nama: ";
        getline(cin, user->nama);

        cout << "Masukkan NIM: ";
        getline(cin, user->nim);

        if (user->nama == correctUser.nama && user->nim == correctUser.nim) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi.\n";
            attempts++;
        }
    }

    cout << "Anda telah gagal login sebanyak 3 kali. Program berhenti.\n";
    return false;
}

void intro() {
    cout << "==========================================================================" << endl;
    cout << "                      Program Pendataan Hewan Kurban                      " << endl;
    cout << "==========================================================================" << endl;
    cout << "                 Silahkan Isi Data Hewan Terlebih Dahulu !                " << endl;
}

void pilih_hewan() {
    cout << "[A] Sapi" << endl;
    cout << "[B] Kambing" << endl;
    cout << "\nMasukkan dengan Huruf Kapital !" << endl;
}

// Fungsi untuk menambah node ke dalam linked list
void tambah_data(LinkedList* list) {
    Node* newNode = new Node;

    cout << "Nama     : ";
    cin >> newNode->data.nama;
    cout << "Umur     : ";
    cin >> newNode->data.umur;
    cout << "Berat    : ";
    cin >> newNode->data.berat;
    cout << "Harga    : ";
    cin >> newNode->data.harga;
    newNode->next = nullptr;

    if (list->head == nullptr) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data Berhasil Ditambahkan" << endl;
}

// Fungsi untuk menampilkan data dalam linked list
void tampil_data(LinkedList* list) {
    Node* temp = list->head;
    int i = 1;

    if (temp == nullptr) {
        cout << "Tidak ada data hewan." << endl;
        return;
    }

    while (temp != nullptr) {
        cout << "Hewan Nomor " << i++ << endl;
        cout << "Nama     : " << temp->data.nama << endl;
        cout << "Umur     : " << temp->data.umur << " Tahun" << endl;
        cout << "Berat    : " << temp->data.berat << " Kg" << endl;
        cout << "Harga    : Rp. " << temp->data.harga << endl;
        temp = temp->next;
        cout << endl;
    }
}

// Fungsi untuk menghapus data dalam linked list
void hapus_data(LinkedList* list, int posisi) {
    if (list->head == nullptr) {
        cout << "Tidak ada data hewan yang bisa dihapus." << endl;
        return;
    }

    Node* temp = list->head;
    if (posisi == 1) {
        list->head = temp->next;
        delete temp;
        cout << "Data Berhasil Dihapus" << endl;
        return;
    }

    for (int i = 1; temp != nullptr && i < posisi - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    Node* nextNode = temp->next->next;
    delete temp->next;
    temp->next = nextNode;

    cout << "Data Berhasil Dihapus" << endl;
}

int pilih_menu() {
    int choice;
    cout << "Silahkan Pilih Menu" << endl;
    cout << "[1] Menampilkan Data" << endl;
    cout << "[2] Menambahkan Data" << endl;
    cout << "[3] Menghapus Data" << endl;
    cout << "[4] Keluar" << endl;
    cout << "\nMasukkan Pilihan Menu [1, 2, 3, atau 4] : ";

    while (!(cin >> choice) || cin.peek() != '\n' || choice < 1 || choice > 4) {
        cout << "Masukkan harus berupa angka bulat antara 1 hingga 4. Silakan coba lagi: ";
        cin.clear(); // Menghapus status error pada cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus input sebelumnya dari buffer
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return choice;
}

void pilih_menu_rekursif(LinkedList* sapi, LinkedList* kambing) {
    int choice;
    while (true) {
        choice = pilih_menu();
        switch (choice) {
            case 1:
                cout << "Menampilkan Data Sapi" << endl;
                tampil_data(sapi);
                cout << "Menampilkan Data Kambing" << endl;
                tampil_data(kambing);
                break;
            case 2:
                cout << "Menambahkan Data Sapi" << endl;
                tambah_data(sapi);
                cout << "Menambahkan Data Kambing" << endl;
                tambah_data(kambing);
                break;
            case 3:
                int hapusPos;
                cout << "Masukkan nomor hewan yang ingin dihapus: ";
                cin >> hapusPos;
                hapus_data(sapi, hapusPos);
                break;
            case 4:
                cout << "Terima Kasih!" << endl;
                return;
            default:
                cout << "Pilihan tidak valid. Silahkan pilih lagi.\n";
        }
    }
}

int main() {
    User currentUser;
    if (login(&currentUser)) {
        cout << "Selamat datang, " << currentUser.nama << "!\n";

        LinkedList sapi = {nullptr};
        LinkedList kambing = {nullptr};

        intro();

        pilih_menu_rekursif(&sapi, &kambing);
    }

    return 0;
}
