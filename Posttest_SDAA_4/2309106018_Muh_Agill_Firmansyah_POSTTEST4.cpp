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

struct Stack {
    Node* top = nullptr;
};

struct Queue {
    Node* front = nullptr;
    Node* rear = nullptr;
};

// Fungsi login
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

// Fungsi pengenalan program
void intro() {
    cout << "==========================================================================" << endl;
    cout << "                      Program Pendataan Hewan Kurban                      " << endl;
    cout << "==========================================================================" << endl;
    cout << "                 Silahkan Isi Data Hewan Terlebih Dahulu !                " << endl;
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

// Fungsi untuk menambah data ke Stack
void push(Stack* stack, Hewan hewan) {
    Node* newNode = new Node;
    newNode->data = hewan;
    newNode->next = stack->top;
    stack->top = newNode;
    cout << "Data berhasil ditambahkan ke Stack" << endl;
}

// Fungsi untuk menghapus data dari Stack
void pop(Stack* stack) {
    if (stack->top == nullptr) {
        cout << "Stack kosong. Tidak ada data yang bisa dihapus." << endl;
        return;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    delete temp;
    cout << "Data berhasil dihapus dari Stack" << endl;
}

// Fungsi untuk menampilkan data dalam Stack
void tampilkan_stack(Stack* stack) {
    if (stack->top == nullptr) {
        cout << "Stack kosong." << endl;
        return;
    }

    Node* temp = stack->top;
    int i = 1;
    while (temp != nullptr) {
        cout << "Hewan pada Stack " << i++ << endl;
        cout << "Nama     : " << temp->data.nama << endl;
        cout << "Umur     : " << temp->data.umur << " Tahun" << endl;
        cout << "Berat    : " << temp->data.berat << " Kg" << endl;
        cout << "Harga    : Rp. " << temp->data.harga << endl;
        temp = temp->next;
        cout << endl;
    }
}

// Fungsi untuk menambah data ke Queue
void enqueue(Queue* queue, Hewan hewan) {
    Node* newNode = new Node;
    newNode->data = hewan;
    newNode->next = nullptr;
    if (queue->rear == nullptr) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    cout << "Data berhasil ditambahkan ke Queue" << endl;
}

// Fungsi untuk menghapus data dari Queue
void dequeue(Queue* queue) {
    if (queue->front == nullptr) {
        cout << "Queue kosong. Tidak ada data yang bisa dihapus." << endl;
        return;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == nullptr) {
        queue->rear = nullptr;
    }
    delete temp;
    cout << "Data berhasil dihapus dari Queue" << endl;
}

// Fungsi untuk menampilkan data dalam Queue
void tampilkan_queue(Queue* queue) {
    if (queue->front == nullptr) {
        cout << "Queue kosong." << endl;
        return;
    }

    Node* temp = queue->front;
    int i = 1;
    while (temp != nullptr) {
        cout << "Hewan pada Queue " << i++ << endl;
        cout << "Nama     : " << temp->data.nama << endl;
        cout << "Umur     : " << temp->data.umur << " Tahun" << endl;
        cout << "Berat    : " << temp->data.berat << " Kg" << endl;
        cout << "Harga    : Rp. " << temp->data.harga << endl;
        temp = temp->next;
        cout << endl;
    }
}

// Fungsi untuk memilih menu
int pilih_menu() {
    int choice;
    cout << "Silahkan Pilih Menu" << endl;
    cout << "[1] Menampilkan Data Linked List" << endl;
    cout << "[2] Menambahkan Data Linked List" << endl;
    cout << "[3] Menampilkan Data Stack" << endl;
    cout << "[4] Menampilkan Data Queue" << endl;
    cout << "[5] Menambahkan Data ke Stack" << endl;
    cout << "[6] Menambahkan Data ke Queue" << endl;
    cout << "[7] Menghapus Data dari Stack (Pop)" << endl;
    cout << "[8] Menghapus Data dari Queue (Dequeue)" << endl;
    cout << "[9] Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";

    while (!(cin >> choice) || choice < 1 || choice > 9) {
        cout << "Masukkan harus berupa angka bulat antara 1 hingga 9. Silakan coba lagi: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return choice;
}

// Fungsi untuk memilih menu rekursif
void pilih_menu_rekursif(LinkedList* sapi, LinkedList* kambing, Stack* stack, Queue* queue) {
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
                cout << "Menampilkan Data dalam Stack" << endl;
                tampilkan_stack(stack);
                break;
            case 4:
                cout << "Menampilkan Data dalam Queue" << endl;
                tampilkan_queue(queue);
                break;
            case 5: {
                Hewan hewanBaru;
                cout << "Tambahkan Hewan ke Stack" << endl;
                cout << "Nama: ";
                cin >> hewanBaru.nama;
                cout << "Umur: ";
                cin >> hewanBaru.umur;
                cout << "Berat: ";
                cin >> hewanBaru.berat;
                cout << "Harga: ";
                cin >> hewanBaru.harga;
                push(stack, hewanBaru);
                break;
            }
            case 6: {
                Hewan hewanBaruQueue;
                cout << "Tambahkan Hewan ke Queue" << endl;
                cout << "Nama: ";
                cin >> hewanBaruQueue.nama;
                cout << "Umur: ";
                cin >> hewanBaruQueue.umur;
                cout << "Berat: ";
                cin >> hewanBaruQueue.berat;
                cout << "Harga: ";
                cin >> hewanBaruQueue.harga;
                enqueue(queue, hewanBaruQueue);
                break;
            }
            case 7:
                pop(stack);
                break;
            case 8:
                dequeue(queue);
                break;
            case 9:
                cout << "Terima Kasih!" << endl;
                return;
            default:
                cout << "Pilihan tidak valid. Silahkan pilih lagi." << endl;
        }
    }
}

int main() {
    User currentUser;
    if (login(&currentUser)) {
        cout << "Selamat datang, " << currentUser.nama << "!\n";

        LinkedList sapi = {nullptr};
        LinkedList kambing = {nullptr};
        Stack stack;
        Queue queue;

        intro();

        pilih_menu_rekursif(&sapi, &kambing, &stack, &queue);
    }

    return 0;
}
