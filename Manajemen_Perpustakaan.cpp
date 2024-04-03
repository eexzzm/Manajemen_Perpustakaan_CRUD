#include <iostream>
using namespace std;

struct buku
{
    string judul, penerbit, pengarang;
    int tahun;
    int stok;
    buku *next;
    buku *prev;
};

struct riwayat
{
    string transaksi, riwayatJudul;
    int riwayatStok;
};

riwayat rwyt[100];

buku *head, *tail, *cur;

void input(int i, string &judul, string &pengarang, string &penerbit, int &tahun, int &stok);
void create(string &judul, string &pengarang, string &penerbit, int &tahun, int &stok);
void newcreate(string &judul, string &pengarang, string &penerbit, int &tahun, int &stok);
void print();
void pinjam(int &riwayat, string &judul, int &stok);
void kembali(int &riwayat, string &judul, int &stok);
void riwayatTransaksi(int riwayat);
void edit(string judul);
void hapus(string judul);

int main()
{
    int x = 0;
    string judul, penerbit, pengarang;
    int tahun, stok;
    int riwayat = 0;
    do
    {
        cout << "\t--DATA BUKU-- \n1.) Tambah data buku \n2.) Tampilkan data buku \n3.) Edit data buku \n4.) Hapus data buku" << endl
             << "\n\t--TRANSAKSI BUKU-- \n5.) Pinjam buku \n6.) Kembalikan buku \n7.) Riwayat transaksi \n\n0.) Keluar\n"
             << endl;
        cout << "Pilihan : ";
        cin >> x;
        cout << endl;
        switch (x)
        {
        case 1:
            cout << "\t--TAMBAH BUKU--" << endl;
            int n;
            cout << "Masukkan jumlah judul buku: ";
            cin >> n;
            if (head == NULL)
            {
                for (int i = 0; i < n; i++)
                {
                    input(i, judul, pengarang, penerbit, tahun, stok);
                    create(judul, pengarang, penerbit, tahun, stok);
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    input(i, judul, pengarang, penerbit, tahun, stok);
                    newcreate(judul, pengarang, penerbit, tahun, stok);
                }
            }
            break;
        case 2:
            cout << "\t--DATA BUKU--" << endl;
            print();
            break;
        case 3:
            cout << "\t--EDIT BUKU--" << endl;
            if (head == NULL)
            {
                cout << "Tidak ada buku yang dapat diedit\n"
                     << endl;
            }
            else
            {
                cout << "Masukan judul : ";
                getline(cin >> ws, judul);
                edit(judul);
            }
            break;
        case 4:
            if (head == NULL)
            {
                cout << "Tidak ada buku yang dapat dihapus\n"
                     << endl;
            }
            else
            {
                cout << "Masukan judul : ";
                getline(cin >> ws, judul);
                hapus(judul);
            }
            break;
        case 5:
            cout << "\t--PEMINJAMAN--" << endl;
            if (head == NULL)
            {
                cout << "Tidak ada buku yang dapat dipinjam\n"
                     << endl;
            }
            else
            {
                cout << "Masukan judul : ";
                cin >> judul;
                cout << "Masukan jumlah buku : ";
                cin >> stok;
                cout << endl;
                pinjam(riwayat, judul, stok);
            }
            break;
        case 6:
            if (head == NULL)
            {
                cout << "Tidak ada buku yang dapat dikembalikan\n"
                     << endl;
            }
            else
            {
                cout << "Masukan judul : ";
                cin >> judul;
                cout << "Masukan jumlah buku : ";
                cin >> stok;
                cout << endl;
                kembali(riwayat, judul, stok);
            }
            break;
        case 7:
            cout << "\t--RIWAYAT TRANSAKSI--" << endl;
            riwayatTransaksi(riwayat);
            break;
        case 0:
            cout << "bye!" << endl;
            return 0;
            break;

        default:
            cout << "Terjadi kesalahan dalam pilihan anda, silahkan coba lagi" << endl
                 << endl;
            break;
        }
    } while (x != 0);
}

void input(int i, string &judul, string &pengarang, string &penerbit, int &tahun, int &stok)
{
    cout << "Data ke-" << i + 1 << endl;
    cout << "Judul: ";
    getline(cin >> ws, judul);
    cout << "Pengarang: ";
    getline(cin >> ws, pengarang);
    cout << "Penerbit: ";
    getline(cin >> ws, penerbit);
    cout << "Tahun: ";
    cin >> tahun;
    cout << "Stok: ";
    cin >> stok;
    cout << "\nBuku " << judul << " berhasil ditambahkan" << endl
         << endl;

    cin.ignore();
}

void create(string &judul, string &pengarang, string &penerbit, int &tahun, int &stok)
{
    head = tail = NULL;

    buku *baru = new buku;
    baru->judul = judul;
    baru->pengarang = pengarang;
    baru->penerbit = penerbit;
    baru->tahun = tahun;
    baru->stok = stok;
    baru->next = NULL;
    baru->prev = NULL;

    head = tail = baru;
}

void newcreate(string &judul, string &pengarang, string &penerbit, int &tahun, int &stok)
{
    buku *baru = new buku;
    baru->judul = judul;
    baru->pengarang = pengarang;
    baru->penerbit = penerbit;
    baru->tahun = tahun;
    baru->stok = stok;
    baru->next = NULL;
    baru->prev = tail;

    tail->next = baru;
    tail = baru;
}

void print()
{
    if (head == NULL)
    {
        cout << "Tidak ada data yang dapat ditampilkan\n"
             << endl;
    }
    else
    {
        cur = head;
        while (cur != NULL)
        {
            cout << "Judul : " << cur->judul << endl;
            cout << "Pengarang : " << cur->pengarang << endl;
            cout << "Penerbit : " << cur->penerbit << endl;
            cout << "Tahun : " << cur->tahun << endl;
            cout << "Stok : " << cur->stok << endl
                 << endl;

            cur = cur->next;
        }
    }
}

void pinjam(int &riwayat, string &judul, int &stok)
{
    cur = head;
    while (cur != NULL)
    {
        if (cur->judul == judul)
        {
            if (cur->stok > stok)
            {
                riwayat += 1;
                cur->stok -= stok;
                cout << "Buku " << judul << " berhasil dipinjam." << endl;
                rwyt[riwayat].riwayatStok = stok;
                rwyt[riwayat].riwayatJudul = judul;
                rwyt[riwayat].transaksi = "Peminjaman";
                cout << endl
                     << endl;
            }
            else
            {
                cout << "Stok buku " << judul << " tidak cukup untuk dipinjam" << endl;
            }
            break;
        }
        cur = cur->next;
    }
    if (cur == NULL)
    {
        cout << "Buku " << judul << " tidak ditemukan." << endl;
    }
}

void kembali(int &riwayat, string &judul, int &stok)
{
    cur = head;
    cout << "\t--PENGEMBALIAN--" << endl;
    while (cur != NULL)
    {
        if (cur->judul == judul)
        {
            riwayat += 1;
            cur->stok += stok;
            cout << "Buku " << judul << " berhasil dikembalikan." << endl;
            rwyt[riwayat].riwayatStok = stok;
            rwyt[riwayat].riwayatJudul = judul;
            rwyt[riwayat].transaksi = "Pengembalian";
            cout << endl
                 << endl;
            break;
        }
        cur = cur->next;
    }
    if (cur == NULL)
    {
        cout << "Buku " << judul << " tidak ditemukan." << endl;
    }
}

void riwayatTransaksi(int riwayat)
{
    if (riwayat == 0)
    {
        cout << "Tidak ada riwayat yang dapat ditampilkan\n"
             << endl;
    }
    else
    {
        for (int i = 1; i <= riwayat; i++)
        {
            cout << "Riwayat ke-" << i << endl;
            cout << "Judul buku : " << rwyt[i].riwayatJudul << endl;
            cout << "Jumlah buku : " << rwyt[i].riwayatStok << endl;
            cout << "Jenis transaksi : " << rwyt[i].transaksi << endl
                 << endl;
        }
        cout << endl;
    }
}

void edit(string judul)
{
    string m;
    int n;
    cur = head;
    while (cur != NULL)
    {
        if (cur->judul == judul)
        {
            cout << "Pilih data yang ingin di edit" << endl
                 << "1.) Judul \n2.) Pengarang \n3.) Penerbit \n4.) Tahun terbit \n5.) Stok" << endl
                 << "Pilihan : ";
            cin >> n;
            cout << endl;
            switch (n)
            {
            case 1: // Judul
                cout << "Judul lama " << cur->judul << endl;
                cout << "Judul baru : ";
                getline(cin >> ws, m);
                cur->judul = m;
                cout << endl;
                break;
            case 2: // Pengarang
                cout << "Pengarang lama " << cur->pengarang << endl;
                cout << "Pengarang baru : ";
                getline(cin >> ws, m);
                cur->pengarang = m;
                cout << endl;
                break;
            case 3: // Penerbit
                cout << "Penerbit lama " << cur->penerbit << endl;
                cout << "Penerbit baru : ";
                getline(cin >> ws, m);
                cur->penerbit = m;
                cout << endl;
                break;
            case 4: // Tahun
                cout << "Tahun terbit lama " << cur->tahun << endl;
                cout << "Tahun terbit baru : ";
                cin >> n;
                cur->tahun = n;
                cout << endl;
                break;
            case 5: // Stok
                cout << "Stok lama " << cur->stok << endl;
                cout << "Stok baru : ";
                cin >> n;
                cur->stok = n;
                cout << endl;
                break;

            default:
                cout << "Terjadi kesalahan dalam pilihan anda" << endl
                     << endl;
                break;
            }
            cout << "Buku berhasil disunting" << endl
                 << endl;
            break;
        }
        cur = cur->next;
    }
    if (cur == NULL)
    {
        cout << "Buku \"" << judul << "\" tidak ditemukan." << endl;
    }
}

void hapus(string judul)
{
    cur = head;
    while (cur != NULL && cur->judul != judul)
    {
        cur = cur->next;
    }
    if (cur != NULL)
    {
        if (cur == head)
        {
            head = head->next;
        }
        else
        {
            cur->prev->next = cur->next;
            if (cur->next != NULL)
            {
                cur->next->prev = cur->prev;
            }
        }
        delete cur;
        cout << "Buku " << judul << " berhasil dihapus." << endl;
    }
    else
    {
        cout << "Buku " << judul << " tidak ditemukan." << endl;
    }
}