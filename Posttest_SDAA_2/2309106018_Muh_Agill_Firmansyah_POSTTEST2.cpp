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

struct DataHewan {
    Hewan sapi[5];
    Hewan kambing[5];
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

void intro()
{
    cout<<"=========================================================================="<<endl;
    cout<<"                      Program Pendataan Hewan Kurban                      "<<endl;
    cout<<"=========================================================================="<<endl;
    cout<<"                 Silahkan Isi Data Hewan Terlebih Dahulu !                "<<endl;
}

void pilih_hewan()
{
    cout<<"[A] Sapi"<<endl;
    cout<<"[B] Kambing"<<endl;
    cout<<"\nMasukkan dengan Huruf Kapital !"<<endl;
}

void isi_data_sapi(Hewan* sapi)
{
    int i = 0;
    
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"                                 Data Sapi                                "<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;

    for (i = 0; i < 3; i++)
    {
        cout<<"Sapi Nomor "<<i+1<<endl;
        cout<<"Nama     : ";
        cin>>(sapi[i].nama);fflush(stdin);
        cout<<"Umur     : ";
        cin>>(sapi[i].umur);fflush(stdin);
        cout<<"Berat    : ";
        cin>>(sapi[i].berat);fflush(stdin);
        cout<<"Harga    : ";
        cin>>(sapi[i].harga);fflush(stdin);
        cout<<endl;
    }
}

void isi_data_kambing(Hewan* kambing)
{
    int i = 0;

    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<"                                Data Kambing                              "<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    
    for (i = 0; i < 3; i++)
    {
        cout<<"Kambing Nomor "<<i+1<<endl;
        cout<<"Nama     : ";
        cin>>(kambing[i].nama);fflush(stdin);
        cout<<"Umur     : ";
        cin>>(kambing[i].umur);fflush(stdin);
        cout<<"Berat    : ";
        cin>>(kambing[i].berat);fflush(stdin);
        cout<<"Harga    : ";
        cin>>(kambing[i].harga);fflush(stdin);
        cout<<endl;
    }
}

void tampil_data_sapi(Hewan* sapi)
{
    int i = 0;

    for (i = 0; i < 5; i++)
    {
        cout<<"Sapi Nomor "<<i+1<<endl;
        cout<<"Nama     : "<<sapi[i].nama<<endl;
        cout<<"Umur     : "<<sapi[i].umur<<" Tahun"<<endl;
        cout<<"Berat    : "<<sapi[i].berat<<" Kg"<<endl;
        cout<<"Harga    : Rp. "<<sapi[i].harga<<endl;
        cout<<endl;
    }
}

void tampil_data_kambing(Hewan* kambing)
{
    int i = 0;

    for (i = 0; i < 5; i++)
    {
        cout<<"Kambing Nomor "<<i+1<<endl;
        cout<<"Nama     : "<<kambing[i].nama<<endl;
        cout<<"Umur     : "<<kambing[i].umur<<" Tahun"<<endl;
        cout<<"Berat    : "<<kambing[i].berat<<" Kg"<<endl;
        cout<<"Harga    : Rp. "<<kambing[i].harga<<endl;
        cout<<endl;
    }
}

void tampil_data(DataHewan* dataHewan)
{
    int i = 0;
    string pilih;

    cout<<"Silahkan Pilih Data Hewan yang ingin ditampilkan"<<endl;

    pilih_hewan();

    cout<<"Masukkan Pilihan Data [A/B] : ";
    cin>>pilih;
    cout<<"=========================================================================="<<endl;

    if (pilih == "A")
    {
        tampil_data_sapi(dataHewan->sapi);
    }
    else if (pilih == "B")
    {
        tampil_data_kambing(dataHewan->kambing);
    }
    else 
    {
        cout<<"Mohon Maaf Data Hewan yang Anda Pilih Tidak Tersedia"<<endl;
        cout<<"=========================================================================="<<endl;
    }
}

void tambah_data(Hewan* sapi, Hewan* kambing)
{
    int i = 3;
    string pilih;

    cout<<"Silahkan Pilih Data Hewan yang ingin ditambahkan"<<endl;

    pilih_hewan();
    cout<<"Masukkan Pilihan Data [A/B] : ";
    cin>>pilih;
    cout<<"=========================================================================="<<endl;

    if (pilih == "A")
    {
        cout<<"Nama     : ";
        cin>>sapi[i].nama;fflush(stdin);
        cout<<"Umur     : ";
        cin>>sapi[i].umur;fflush(stdin);
        cout<<"Berat    : ";
        cin>>sapi[i].berat;fflush(stdin);
        cout<<"Harga    : ";
        cin>>sapi[i].harga;fflush(stdin);
        cout<<"=========================================================================="<<endl;
        cout<<"                         Data Berhasil Ditambahkan                        "<<endl;
    }
    else if (pilih == "B")
    {
        cout<<"Nama     : ";
        cin>>kambing[i].nama;fflush(stdin);
        cout<<"Umur     : ";
        cin>>kambing[i].umur;fflush(stdin);
        cout<<"Berat    : ";
        cin>>kambing[i].berat;fflush(stdin);
        cout<<"Harga    : ";
        cin>>kambing[i].harga;fflush(stdin);
        cout<<"=========================================================================="<<endl;
        cout<<"                         Data Berhasil Ditambahkan                        "<<endl;
    }
    else 
    {
        cout<<"Mohon Maaf Data Hewan yang Anda Pilih Tidak Tersedia";
    }
}

void edit_data(Hewan* sapi, Hewan* kambing)
{
    int indeks, i;
    string pilih;

    cout<<"Silahkan Pilih Data Hewan yang ingin diperbarui"<<endl;

    pilih_hewan();
    cout<<"Masukkan Pilihan Data [A/B] : ";
    cin>>pilih;
    cout<<"=========================================================================="<<endl;

    if (pilih == "A")
    {
        tampil_data_sapi(sapi);
        cout<<"Masukkan Nomor Sapi yang ingin diperbarui : ";
        cin>>indeks;
        cout<<"=========================================================================="<<endl;

        i = indeks - 1;

        cout<<"Nama     : ";
        cin>>sapi[i].nama;fflush(stdin);
        cout<<"Umur     : ";
        cin>>sapi[i].umur;fflush(stdin);
        cout<<"Berat    : ";
        cin>>sapi[i].berat;fflush(stdin);
        cout<<"Harga    : ";
        cin>>sapi[i].harga;fflush(stdin);
        cout<<"=========================================================================="<<endl;
        cout<<"                          Data Berhasil Diperbarui                        "<<endl;
    }
    else if (pilih == "B")
    {
        tampil_data_kambing(kambing);
        cout<<"Masukkan Nomor Kambing yang ingin diperbarui : ";
        cin>>indeks;
        cout<<"=========================================================================="<<endl;

        i = indeks - 1;

        cout<<"Nama     : ";
        cin>>kambing[i].nama;fflush(stdin);
        cout<<"Umur     : ";
        cin>>kambing[i].umur;fflush(stdin);
        cout<<"Berat    : ";
        cin>>kambing[i].berat;fflush(stdin);
        cout<<"Harga    : ";
        cin>>kambing[i].harga;fflush(stdin);
        cout<<"=========================================================================="<<endl;
        cout<<"                          Data Berhasil Diperbarui                        "<<endl;
    }
    else 
    {
        cout<<"Mohon Maaf Data Hewan yang Anda Pilih Tidak Tersedia";
    }
}

void hapus_data(Hewan* sapi, Hewan* kambing)
{
    int hapus, i;
    string pilih;

    cout<<"Silahkan Pilih Data Hewan yang ingin dihapus"<<endl;

    pilih_hewan();
    cout<<"Masukkan Pilihan Data [A/B] : ";
    cin>>pilih;
    cout<<"=========================================================================="<<endl;

    if (pilih == "A")
    {
        tampil_data_sapi(sapi);
        cout<<"Masukkan Nomor Sapi yang ingin dihapus : ";
        cin>>hapus;
        if (hapus < 6)
        {
            for (i = hapus - 1; i < 4 ; i++)
            {
                sapi[i] = sapi [i + 1];fflush(stdin);
            }
            cout<<"=========================================================================="<<endl;
            cout<<"                            Data Berhasil Dihapus                         "<<endl;
        }
        else 
        {
            cout<<"Mohon Maaf Nomor Sapi yang dimasukkan Tidak Tersedia"<<endl;
        }
    }
    else if (pilih == "B")
    {
        tampil_data_kambing(kambing);
        cout<<"Masukkan Nomor Kambing yang ingin dihapus : ";
        cin>>hapus;
        if (hapus < 6)
        {
            for (i = hapus - 1; i < 4 ; i++)
            {
                kambing[i] = kambing [i + 1];fflush(stdin);
            }
            cout<<"=========================================================================="<<endl;
            cout<<"                            Data Berhasil Dihapus                         "<<endl;
        }
        else 
        {
            cout<<"Mohon Maaf Nomor Kambing yang dimasukkan Tidak Tersedia"<<endl;
        }
    }
    else 
    {
        cout<<"Mohon Maaf Data Hewan yang Anda Pilih Tidak Tersedia";
    }
}

int pilih_menu() {
    int choice;
    cout<<"Silahkan Pilih Menu"<<endl;
    cout<<"[1] Menampilkan Data"<<endl;
    cout<<"[2] Menambahkan Data"<<endl;
    cout<<"[3] Mengedit Data"<<endl;
    cout<<"[4] Menghapus Data"<<endl;
    cout<<"[5] Keluar"<<endl;
    cout<<"\nMasukkan Pilihan Menu [1, 2, 3, 4, atau 5] : ";
    
    while (!(cin >> choice) || cin.peek() != '\n' || choice < 1 || choice > 5) {
        cout << "Masukkan harus berupa angka bulat antara 1 hingga 5. Silakan coba lagi: ";
        cin.clear(); // Menghapus status error pada cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus input sebelumnya dari buffer
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return choice;
}

void pilih_menu_rekursif(DataHewan* dataHewan) {
    int choice;
    while (true) {
        choice = pilih_menu();
        switch (choice) {
            case 1:
                tampil_data(dataHewan);
                break;
            case 2:
                tambah_data(dataHewan->sapi, dataHewan->kambing);
                break;
            case 3:
                edit_data(dataHewan->sapi, dataHewan->kambing);
                break;
            case 4:
                hapus_data(dataHewan->sapi, dataHewan->kambing);
                break;
            case 5:
                cout << "Terima Kasih!" << endl;
                return;
            default:
                cout << "Pilihan tidak valid. Silahkan pilih lagi.\n";
        }
    }
}

int main()
{
    User currentUser;
    if (login(&currentUser)) {
        cout << "Selamat datang, " << currentUser.nama << "!\n";
        
        DataHewan dataHewan;

        intro();

        isi_data_sapi(dataHewan.sapi);

        isi_data_kambing(dataHewan.kambing);

        pilih_menu_rekursif(&dataHewan);
    }

    return 0;
}

