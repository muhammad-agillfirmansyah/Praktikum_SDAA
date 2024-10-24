#include <iostream>
#include <conio.h>
#include <string>
#include <limits>
#include <vector>
#include <cmath>

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
        queue->front = queue->rear = newNode;
        cout << "Data berhasil ditambahkan ke Queue" << endl;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
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

    if (queue->front == nullptr)
        queue->rear = nullptr;

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

// Fungsi untuk melakukan Fibonacci Search pada array umur hewan
int fibonacciSearch(int arr[], int n, int x) {
    int fib2 = 0; // (m-2)'th Fibonacci No.
    int fib1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fib2 + fib1; // m'th Fibonacci No.

    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < x) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        } else
            return i;
    }

    if (fib1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

// Fungsi untuk melakukan Jump Search pada harga hewan
int jumpSearch(vector<int>& arr, int x) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

// Fungsi untuk mencari nama hewan menggunakan Boyer-Moore
void searchBoyerMoore(const string& text, const string& pattern) {
    int m = pattern.length();
    int n = text.length();
    int badChar[256];

    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i;

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            cout << "Polanya ditemukan pada index " << s << endl;
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {
            s += max(1, j - badChar[text[s + j]]);
        }
    }
}

int main() {
    User user;
    LinkedList list;
    list.head = nullptr;
    Stack stack;
    Queue queue;

    if (!login(&user)) return 0;
    intro();

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Hewan\n";
        cout << "2. Tampilkan Data Hewan\n";
        cout << "3. Sortir Data Hewan\n";
        cout << "4. Pencarian Data Hewan\n";
        cout << "5. Push ke Stack\n";
        cout << "6. Tampilkan Stack\n";
        cout << "7. Enqueue ke Queue\n";
        cout << "8. Tampilkan Queue\n";
        cout << "0. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tambah_data(&list);
                break;
            case 2:
                tampil_data(&list);
                break;
            case 3:
                cout << "Pilih metode pengurutan:\n";
                cout << "1. Merge Sort\n";
                cout << "2. Quick Sort\n";
                int sortChoice;
                cin >> sortChoice;

                if (sortChoice == 1) {
                    mergeSort(&list.head);
                    cout << "Data telah diurutkan dengan Merge Sort." << endl;
                } else if (sortChoice == 2) {
                    quickSort(&list.head);
                    cout << "Data telah diurutkan dengan Quick Sort." << endl;
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;
            case 4: {
                int searchChoice;
                cout << "Pilih metode pencarian:\n";
                cout << "1. Fibonacci Search (Umur)\n";
                cout << "2. Jump Search (Harga)\n";
                cout << "3. Boyer-Moore (Nama)\n";
                cin >> searchChoice;

                switch (searchChoice) {
                    case 1: {
                        // Prepare array of ages for Fibonacci search
                        vector<int> ages;
                        Node* temp = list.head;
                        while (temp != nullptr) {
                            ages.push_back(atoi(temp->data.umur));
                            temp = temp->next;
                        }

                        int ageToSearch;
                        cout << "Masukkan umur yang dicari: ";
                        cin >> ageToSearch;

                        int fibResult = fibonacciSearch(ages.data(), ages.size(), ageToSearch);
                        if (fibResult != -1) {
                            cout << "Umur " << ageToSearch << " ditemukan." << endl;
                        } else {
                            cout << "Umur " << ageToSearch << " tidak ditemukan." << endl;
                        }
                        break;
                    }
                    case 2: {
                        // Prepare vector of prices for Jump search
                        vector<int> prices;
                        Node* temp = list.head;
                        while (temp != nullptr) {
                            prices.push_back(temp->data.harga);
                            temp = temp->next;
                        }

                        int priceToSearch;
                        cout << "Masukkan harga yang dicari: ";
                        cin >> priceToSearch;

                        int jumpResult = jumpSearch(prices, priceToSearch);
                        if (jumpResult != -1) {
                            cout << "Harga " << priceToSearch << " ditemukan." << endl;
                        } else {
                            cout << "Harga " << priceToSearch << " tidak ditemukan." << endl;
                        }
                        break;
                    }
                    case 3: {
                        string nameToSearch;
                        cout << "Masukkan nama yang dicari: ";
                        cin >> nameToSearch;

                        // Prepare the text from the linked list for Boyer-Moore search
                        string allNames;
                        Node* temp = list.head;
                        while (temp != nullptr) {
                            allNames += temp->data.nama + " ";
                            temp = temp->next;
                        }

                        searchBoyerMoore(allNames, nameToSearch);
                        break;
                    }
                    default:
                        cout << "Pilihan tidak valid." << endl;
                }
                break;
            }
            case 5: {
                Hewan hewan;
                cout << "Masukkan data hewan untuk stack:" << endl;
                cout << "Nama     : ";
                cin >> hewan.nama;
                cout << "Umur     : ";
                cin >> hewan.umur;
                cout << "Berat    : ";
                cin >> hewan.berat;
                cout << "Harga    : ";
                cin >> hewan.harga;
                push(&stack, hewan);
                break;
            }
            case 6:
                tampilkan_stack(&stack);
                break;
            case 7: {
                Hewan hewan;
                cout << "Masukkan data hewan untuk queue:" << endl;
                cout << "Nama     : ";
                cin >> hewan.nama;
                cout << "Umur     : ";
                cin >> hewan.umur;
                cout << "Berat    : ";
                cin >> hewan.berat;
                cout << "Harga    : ";
                cin >> hewan.harga;
                enqueue(&queue, hewan);
                break;
            }
            case 8:
                tampilkan_queue(&queue);
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 0);

    return 0;
}
