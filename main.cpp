#include "final.h"

/*EDITED*/


int main()
{
    ListMK lmk;
    ListMHS lmhs;
    adrMK mk;
    MK inputan;

    createListMK(lmk);
    inputan = dataMK("Struktur Data", "IF44GAB", 10, "Reg");
    newElmMK(inputan, mk);
    insertMK(lmk, mk);

    inputan = dataMK("Struktur Data", "IF44INT", 5, "Int");
    newElmMK(inputan, mk);
    insertMK(lmk, mk);

    inputan = dataMK("Logika Matematika", "IF44INT", 5, "Reg");
    newElmMK(inputan, mk);
    insertMK(lmk, mk);


    inputan = dataMK("Logika Matematika", "IF44GAB", 20, "Reg");
    newElmMK(inputan, mk);
    insertMK(lmk, mk);

    inputan = dataMK("Kalkulus", "IF44GAB", 25, "Reg");
    newElmMK(inputan, mk);
    insertMK(lmk, mk);

    inputan = dataMK("Matematika Distrik", "IF44GAB", 10, "Reg");
    newElmMK(inputan, mk);
    insertMK(lmk, mk);


    createListMHS(lmhs);

    string tambahanak;
    cout << "Ingin menambah user (Y/N)? "; cin >> tambahanak;
    while (tambahanak == "Y" || tambahanak == "y") {
        string ulang;
        cout << "Apakah user mengulang Mata Kuliah (Y/N)? "; cin >> ulang;
        if (ulang == "Y" || ulang == "y") {
            menu(lmk, lmhs);
        } else if (ulang == "N" || ulang == "n") {
            cout << "PERIODE PENDAFTARAN BELUM DIBUKA." << endl;
        } else {
            cout << "Inputan tidak valid." << endl;
        }
        cout << "Ingin menambah user (Y/N)? "; cin >> tambahanak;
    }
    ListRelasi lr;
    showAll(lmk, lmhs);
    cout << endl;
    int x = countRelasi(lmk, "Logika Matematika", "Reg");
    cout << x << endl;
    cout << endl;
    deleteRelasi(lmk, lr, "Logika Matematika", "Reg", "tony");
    deleteRelasi(lmk, lr, "Logika Matematika", "Reg", "sthevanie");
    /*deleteRelasi(lmk, lr, "Logika Matematika", "Reg", "tony");*/
    showAll(lmk, lmhs);

}
