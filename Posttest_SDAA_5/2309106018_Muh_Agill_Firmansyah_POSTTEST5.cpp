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

// Fungsi untuk mendapatkan node terakhir dari linked list (untuk quick sort)
Node* getTail(Node* curr) {
    while (curr != nullptr && curr->next != nullptr)
        curr = curr->next;
    return curr;
}

// Fungsi untuk menggabungkan dua linked list yang sudah diurutkan (untuk merge sort)
Node* merge(Node* left, Node* right) {
    if (!left)
        return right;
    if (!right)
        return left;

    Node* result = nullptr;

    if (left->data.harga <= right->data.harga) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Fungsi untuk membagi linked list menjadi dua bagian (untuk merge sort)
void split(Node* source, Node** front, Node** back) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

// Merge Sort untuk pengurutan secara ascending
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    Node* left;
    Node* right;

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    split(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headRef = merge(left, right);
}

// Fungsi untuk partisi linked list (untuk quick sort)
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* curr = head;
    Node* tail = pivot;

    while (curr != pivot) {
        if (curr->data.harga > pivot->data.harga) { // Descending order
            if (*newHead == nullptr)
                *newHead = curr;

            prev = curr;
            curr = curr->next;
        } else {
            if (prev)
                prev->next = curr->next;

            Node* temp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if (*newHead == nullptr)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

// Quick Sort untuk pengurutan secara descending
Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;

    Node* newHead = nullptr;
    Node* newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
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

// Menampilkan menu
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
    cout << "[9] Sort Linked List Ascending (Merge Sort)" << endl;
    cout << "[10] Sort Linked List Descending (Quick Sort)" << endl;
    cout << "[11] Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";

    while (!(cin >> choice) || choice < 1 || choice > 11) {
        cout << "Masukkan harus berupa angka bulat antara 1 hingga 11. Silakan coba lagi: ";
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
                Hewan hewan;
                cout << "Masukkan Data Hewan ke Stack" << endl;
                cout << "Nama     : ";
                cin >> hewan.nama;
                cout << "Umur     : ";
                cin >> hewan.umur;
                cout << "Berat    : ";
                cin >> hewan.berat;
                cout << "Harga    : ";
                cin >> hewan.harga;
                push(stack, hewan);
                break;
            }
            case 6: {
                Hewan hewan;
                cout << "Masukkan Data Hewan ke Queue" << endl;
                cout << "Nama     : ";
                cin >> hewan.nama;
                cout << "Umur     : ";
                cin >> hewan.umur;
                cout << "Berat    : ";
                cin >> hewan.berat;
                cout << "Harga    : ";
                cin >> hewan.harga;
                enqueue(queue, hewan);
                break;
            }
            case 7:
                pop(stack);
                break;
            case 8:
                dequeue(queue);
                break;
            case 9:
                cout << "Mengurutkan Data Sapi Secara Ascending (Merge Sort)" << endl;
                mergeSort(&sapi->head);
                tampil_data(sapi);  // Menampilkan data setelah sorting
                cout << "Mengurutkan Data Kambing Secara Ascending (Merge Sort)" << endl;
                mergeSort(&kambing->head);
                tampil_data(kambing);  // Menampilkan data setelah sorting
                break;
            case 10:
                cout << "Mengurutkan Data Sapi Secara Descending (Quick Sort)" << endl;
                quickSort(&sapi->head);
                tampil_data(sapi);  // Menampilkan data setelah sorting
                cout << "Mengurutkan Data Kambing Secara Descending (Quick Sort)" << endl;
                quickSort(&kambing->head);
                tampil_data(kambing);  // Menampilkan data setelah sorting
                break;
            case 11:
                cout << "Terima Kasih!" << endl;
                return;
            default:
                // Menu lainnya tetap seperti sebelumnya
                break;
        }
    }
}

// Program utama
int main() {
    User user;

    if (!login(&user)) {
        return 0;
    }

    LinkedList sapi;
    sapi.head = nullptr;
    LinkedList kambing;
    kambing.head = nullptr;
    Stack stack;
    Queue queue;

    intro();
    pilih_menu_rekursif(&sapi, &kambing, &stack, &queue);

    return 0;
}
