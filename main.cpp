#include<windows.h>
#include<iostream>
#include <string>
#include "adt.h"

int main(){
    string  menu;
    List_parent LP;
    List_Child LC;
    createListP(LP);
    createListC(LC);
    //====================
    infotype_child F;
    address_child Fak;
    infotype_parent U;
    address_parent Univ;
    cout << "===============================================" << endl;
    cout << "Nama : Ananda Affan Fattahila" << endl;
    cout << "NIM  : 1301194175" << endl;
    cout << "Kelas: IF-43-02" << endl;
    cout << "===============================================" << endl;
    system("pause");
    do {
        system("cls");
        cout << "===============================================" << endl;
        cout << "--------------Hello Selamat Datang-------------" << endl;
        cout << "------di Pencatatan Data Perguruan Tinggi------" << endl;
        cout << "===============================================" << endl;
        cout << "1.Tambahkan data Perguruan Tinggi."<< endl;
        cout << "2.Tambahkan data Fakultas."<< endl;
        cout << "3.Relasi antara Perguruan Tinggi dan fakultas"<< endl;
        cout << "4.Hapus data perguruan Tinggi tertentu."<< endl;
        cout << "5.Hapus data Fakultas tertentu."<< endl;
        cout << "6.Tampilkan data Semua Perguruan Tinggi beserta data Fakultas yang terdapat."<< endl;
        cout << "7.Tampilkan data Perguruan Tinggi yang memiliki Fakultas tertentu."<< endl;
        cout << "8.Tampilkan data Fakultas yang dimiliki Perguruan Tinggi tertentu."<< endl;
        cout << "9.Tampilkan data Perguruan Tinggi yang memiliki jumlah Fakultas paling banyak & sedikit."<< endl;
        cout << "===============================================" << endl;
        cout << "Masukan Pilihan Menu : " ;
        cin >> menu;
        cout << "===============================================" << endl;
        if ( menu == "1"){
            infotype_parent U;
            address_parent Univ;
            cout << "Nama Universitas       : ";
            cin.ignore();
            getline(cin, U.namauniv);
            cout << "Nama Rektor            : ";
            getline(cin, U.rektor);
            cout << "Provinsi Universitas   : ";
            getline(cin, U.provinsi);
            cout << "Akreditasi Universitas : ";
            getline(cin, U.akreditasi);
            cout << "Tahun Berdiri          : ";
            getline(cin, U.tahun);
            Univ = alokasiP(U);
            insertFirstP(LP,Univ);
        }else if (menu == "2"){
            infotype_child F;
            address_child Fak;
            cin.ignore();
            cout << "Nama Fakultas          : ";
            getline(cin, F.namafakultas);
            cout << "Bidang                 : ";
            getline(cin, F.bidang);
            cout << "Kejuruan               : ";
            getline(cin, F.kejuruan);
            Fak = alokasiC(F);
            insertFirstC(LC,Fak);
        }else if (menu == "3"){
            string menu_2;
            cout<< "====================================================="  << endl;
            cout<< "1.Tambahkan Relasikan Antara Universitas dan Fakultas"  << endl;
            cout<< "2.Hapus Relasikan Antara Universitas dan Fakultas    "  << endl;
            cout<< "====================================================="  << endl;
            cout<< "Masukan Pilihan Anda (0 untuk keluar) : ";
            cin >> menu_2;
            cout<< "====================================================="  << endl;
            if (menu_2 == "1"){
                cout << "Nama Universitas : ";
                cin.ignore();
                getline(cin,U.namauniv);
                cout << "Nama Fakultas    : ";
                getline(cin,F.namafakultas);
                Fak = findElmC(LC,F);
                Univ = findElmP(LP,U);

                InsertElmR(Univ,Fak);
                do {
                    cout << "===============================================" << endl;
                    cout << "Masukan 0 untuk lanjutkan : ";
                    cin  >> menu;
                    cout << "===============================================" << endl;
                } while(menu != "0");
            } else if (menu_2 == "2") {
                cout << "Nama Universitas : ";
                cin.ignore();
                getline(cin,U.namauniv);
                cout << "Nama Fakultas    : ";
                getline(cin,F.namafakultas);
                Univ = findElmP(LP,U);
                Fak = findElmC(LC,F);
                hapusRelasi(Univ,Fak);
                do {
                    cout << "===============================================" << endl;
                    cout << "Masukan 0 untuk lanjutkan : ";
                    cin  >> menu;
                    cout << "===============================================" << endl;
                } while(menu != "0");
            } else {
                do {
                cout<< "====================================================="  << endl;
                cout<< "Masukan Pilihan Anda (0 untuk keluar) : ";
                cin >> menu_2;
                cout<< "====================================================="  << endl;
                } while(menu_2 != "0");
            }
        }else if (menu == "4"){
            infotype_parent U;
            address_parent Univ;
            cout << "Hapus Data Universitas"<< endl;
            cout << "Masukan Nama Universitas yang akan di Hapus : ";
            cin.ignore();
            getline(cin,U.namauniv);
            HAPUSuniv(LP,U.namauniv,Univ);
            do {
                cout << "===============================================" << endl;
                cout << "Masukan 0 untuk lanjutkan : ";
                cin  >> menu;
                cout << "===============================================" << endl;
            } while(menu != "0");
        }else if (menu == "5"){
            infotype_child F;
            address_child Fak;
            cout << "Hapus Data Fakultas"<< endl;
            cout << "Masukan Nama yang akan di Hapus : ";
            cin.ignore();
            getline(cin,F.namafakultas);
            HAPUSfak(LP,LC,F.namafakultas,Fak);
            do {
                cout << "===============================================" << endl;
                cout << "Masukan 0 untuk lanjutkan : ";
                cin  >> menu;
                cout << "===============================================" << endl;
            } while(menu != "0");
        }else if (menu == "6"){
            TampilFakdanUniv(LP,LC);
            do {
                cout << "===============================================" << endl;
                cout << "Masukan 0 untuk lanjutkan : ";
                cin  >> menu;
                cout << "===============================================" << endl;
            } while(menu != "0");
            system("cls");
        }else if (menu == "7"){
            cin.ignore();
            cout << "Tampilkan Universitas yang Memiliki Fakultas : ";
            getline(cin,F.namafakultas);
            Fak = findElmC(LC,F);
            tampilfakultas(LP,Fak);
            do {
                cout << "===============================================" << endl;
                cout << "Masukan 0 untuk lanjutkan : ";
                cin  >> menu;
                cout << "===============================================" << endl;
            } while(menu != "0");
            system("cls");
        }else if (menu == "8"){
            cin.ignore();
            cout << "Tampilkan Fakultas yang di miliki Universitas : ";
            getline(cin,U.namauniv);
            Univ = findElmP(LP,U);
            tampilkanfakultasdalamuniv(Univ);
            do {
                cout << "===============================================" << endl;
                cout << "Masukan 0 untuk lanjutkan : ";
                cin  >> menu;
                cout << "===============================================" << endl;
            } while(menu != "0");
            system("cls");

        }else if (menu == "9"){
            tampiljumlahfakultas(LP);
            do {
                cout << "===============================================" << endl;
                cout << "Masukan 0 untuk lanjutkan : ";
                cin  >> menu;
                cout << "===============================================" << endl;
            } while(menu != "0");
            system("cls");
        }else {
            system("cls");
            cout << "===============================================" << endl;
            cout << "--------------Hello Selamat Datang-------------" << endl;
            cout << "------di Pencatatan Data Perguruan Tinggi------" << endl;
            cout << "===============================================" << endl;
            cout << "1.Tambahkan data Perguruan Tinggi."<< endl;
            cout << "2.Tambahkan data Fakultas."<< endl;
            cout << "3.Relasi antara Perguruan Tinggi dan fakultas"<< endl;
            cout << "4.Hapus data perguruan Tinggi tertentu."<< endl;
            cout << "5.Hapus data Fakultas tertentu."<< endl;
            cout << "6.Tampilkan data Semua Perguruan Tinggi beserta data Fakultas yang terdapat."<< endl;
            cout << "7.Tampilkan data Perguruan Tinggi yang memiliki Fakultas tertentu."<< endl;
            cout << "8.Tampilkan data Fakultas yang dimiliki Perguruan Tinggi tertentu."<< endl;
            cout << "9.Tampilkan data Perguruan Tinggi yang memiliki jumlah Fakultas paling banyak & sedikit."<< endl;
            cout << "===============================================" << endl;
            cout << "Masukan Pilihan Menu : " ;
            cin >> menu;
            cout << "===============================================" << endl;
        }
    }while( menu != "-1");
}



