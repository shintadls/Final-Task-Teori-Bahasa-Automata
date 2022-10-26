#ifndef FINAL_H_INCLUDED
#define FINAL_H_INCLUDED

#include <iostream>
/*EDITED*/
using namespace std;

#define nextMK(P) (P)->nextMK
#define firstMK(L) ((L).firstMK)

#define nextRelasi(P) (P)->nextRelasi
#define prevRelasi(P) (P)->prevRelasi
#define lastRelasi(L) ((L).lastRelasi)

#define nextMHS(P) (P)->nextMHS
#define firstMHS(L) ((L).firstMHS)

#define info(P) (P)->info

typedef struct elmMK *adrMK;
typedef struct elmMHS *adrMHS;
typedef struct elmRelasi *adrRelasi;

struct MK{
    string namaMK;
    string kelas;
    int nmax_quota;
    string jenisMHS;
};

struct MHS{
    string namaMHS;
    string nimMHS;
    string asal_kelas;
    string jenisMHS;
};

struct elmRelasi {
    adrRelasi nextRelasi;
    adrRelasi prevRelasi;
    adrMHS nextMHS;
};

struct elmMK{
    adrMK nextMK;
    adrRelasi nextRelasi;
    MK info;
};

struct elmMHS{
    adrMHS nextMHS;
    MHS info;
};

struct ListMK{
    adrMK firstMK;
};

struct ListMHS{
    adrMHS firstMHS;
};

struct ListRelasi {
    adrRelasi lastRelasi;
};

void createListMK(ListMK &L);
void createListMHS(ListMHS &L);

MK dataMK(string namaMK, string Class, int nmax, string jenismhs);
MHS dataMHS(string namaMHS, string nimMHS, string asal_kelas, string jenisMHS);

void newElmMK(MK info, adrMK &MK);
void newElmMHS(MHS info, adrMHS &MHS);
void newElmRelasi(adrRelasi &R);

void insertMK(ListMK &L, adrMK MK);
void insertMHS(ListMHS &L, adrMHS MHS);
void insertRelasi(ListMK &L, adrRelasi R, adrMK MK, string namaMK, string jenisMHS);

void delete_firstMK(ListMK &L, adrMK &MK);
void delete_lastMK(ListMK &L, adrMK &MK);
void delete_afterMK(adrMK prec, adrMK &MK);
void deleteMK(ListMK &L, string namaMK);

void delete_firstMHS(ListMHS &L, adrMHS &MHS);
void delete_lastMHS(ListMHS &L, adrMHS &MHS);
void delete_afterMHS(adrMHS prec, adrMHS &MHS);
void deleteMHS(ListMHS &L, string namaMHS);

void delete_firstRelasi(ListMK &lmk, ListRelasi &lr, adrRelasi &R, string namaMK, string jenisMHS);
void delete_lastRelasi(ListMK &lmk, ListRelasi &lr, adrRelasi R);
void delete_afterRelasi(adrRelasi prec, adrRelasi &R);
void deleteRelasi(ListMK &lmk, ListRelasi &lr, string namaMK, string jenisMHS, string namaMHS);

int countRelasi(ListMK lmk, string namaMK, string jenisMHS);

adrMK searchMK(string namaMK, string jenisMHS, ListMK lmk);

void showMK(ListMK L);
void showMHS(ListMHS L);
void showAll(ListMK lmk, ListMHS lmhs);
void connecting(ListMK lmk, ListMHS lmhs, string namaMHS, string namaMK, string jenisMHS);

void menu(ListMK &lmk, ListMHS &lmhs);


#endif // FINAL_H_INCLUDED
