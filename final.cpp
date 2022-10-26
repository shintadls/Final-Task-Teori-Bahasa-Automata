#include "final.h"

void createListMK(ListMK &L){
    firstMK(L) = NULL;
}

void createListMHS(ListMHS &L){
    firstMHS(L) = NULL;
}

MK dataMK(string namaMK, string Class, int nmax, string jenismhs) {
    MK info;
    info.namaMK = namaMK;
    info.kelas = Class;
    info.nmax_quota = nmax;
    info.jenisMHS = jenismhs;
    return info;
}

MHS dataMHS(string namaMHS, string nimMHS, string asal_kelas, string jenisMHS) {
    MHS info;
    info.namaMHS = namaMHS;
    info.nimMHS = nimMHS;
    info.asal_kelas = asal_kelas;
    info.jenisMHS = jenisMHS;
    return info;
}

void newElmMK(MK info, adrMK &MK){
    MK = new elmMK;
    info(MK) = info;
    nextMK(MK) = NULL;
    nextRelasi(MK) = NULL;
}

void newElmMHS(MHS info, adrMHS &MHS){
    MHS = new elmMHS;
    info(MHS) = info;
    nextMHS(MHS) = NULL;
}

void newElmRelasi(adrRelasi &R) {
    R = new elmRelasi;
    nextRelasi(R) = NULL;
    nextMHS(R) = NULL;
}

void insertMK(ListMK &L, adrMK MK){ //insert last
    if (firstMK(L) == NULL){
        firstMK(L) = MK;
        nextMK(MK) = firstMK(L);
    } else {
        adrMK q = firstMK(L);
        while (nextMK(q) != firstMK(L)) { //looping to find the last element
            q = nextMK(q);
        }
        nextMK(q) = MK;
        nextMK(MK) = firstMK(L);
    }
}

void insertMHS(ListMHS &L, adrMHS MHS){ // insert last
    if (firstMHS(L) == NULL){
        firstMHS(L) = MHS;
        nextMHS(MHS) = firstMHS(L);
    } else {
        adrMHS q = firstMHS(L);
        nextMHS(MHS) = firstMHS(L);
        while (nextMHS(q) != firstMHS(L)) { //looping to find the last element
            q = nextMHS(q);
        }
        nextMHS(q) = MHS;
    }
}

void insertRelasi(ListMK &lmk, adrRelasi R, adrMK MK, string namaMK, string jenisMHS) { //insert first{
    if (nextRelasi(MK) == NULL) {
        nextRelasi(MK) = R;
    } else {
        nextRelasi(R) = nextRelasi(MK);
        prevRelasi(nextRelasi(MK)) = R;
        nextRelasi(MK) = R;
    }
}

void delete_firstMK(ListMK &L, adrMK &MK){
    adrMK q;
    q = firstMK(L);
    if (nextMK(firstMK(L)) == firstMK(L)){
        firstMK(L) = NULL;
        nextMK(MK) = NULL;
    } else {
        firstMK(L) = nextMK(firstMK(L));
        nextMK(MK) = NULL;
        nextMK(q) = firstMK(L);
        nextMK(MK) = NULL;
    }
}

void delete_lastMK(ListMK &L, adrMK &MK){
    adrMK q;
    q = firstMK(L);
    while (nextMK(nextMK(q)) != firstMK(L)) { //looping q points before last element
        q = nextMK(q);
    }
    nextMK(MK) = NULL;
    nextMK(q) = firstMK(L);
}

void delete_afterMK(adrMK prec, adrMK &MK) {
    MK = nextMK(prec);
    nextMK(prec) = nextMK(MK);
    nextMK(MK) = NULL;
}

void deleteMK(ListMK &L, string namaMK) {
    adrMK p = firstMK(L);
    adrMK q = firstMK(L);
    while (nextMK(q) != firstMK(L)){ //looping q points before last element
        q = nextMK(q);
    }
    if (info(p).namaMK == namaMK) {
        delete_firstMK(L, p);
    } else if (info(q).namaMK == namaMK) {
        delete_lastMK(L, q);
    } else {
        adrMK MK;
        delete_afterMK(q, MK);
    }
}

void delete_firstMHS(ListMHS &L, adrMHS &MHS){
    adrMHS q;
    MHS = firstMHS(L);
    if (nextMHS(firstMHS(L)) == firstMHS(L)){
        firstMHS(L) = NULL;
        nextMHS(MHS) = NULL;
    } else {
        firstMHS(L) = nextMHS(firstMHS(L));
        nextMHS(MHS) = NULL;
        nextMHS(q) = firstMHS(L);
        nextMHS(MHS) = NULL;
    }
}

void delete_lastMHS(ListMHS &L, adrMHS &MHS){
    adrMHS q;
    q = firstMHS(L);
    while (nextMHS(q) != firstMHS(L)){ //looping q points before last element
        q = nextMHS(q);
    }
    nextMHS(MHS) = NULL;
    nextMHS(q) = firstMHS(L);
}

void delete_afterMHS(adrMHS prec, adrMHS &MHS) {
    MHS = nextMHS(prec);
    nextMHS(prec) = nextMHS(MHS);
    nextMHS(MHS) = NULL;
}

void deleteMHS(ListMHS &L, string namaMHS) {
    adrMHS p = firstMHS(L);
    adrMHS q = firstMHS(L);
    while (nextMHS(q) != firstMHS(L)){ //looping q points before last element
        q = nextMHS(q);
    }
    if (info(p).namaMHS == namaMHS) {
        delete_firstMHS(L, p);
    } else if (info(q).namaMHS == namaMHS) {
        delete_lastMHS(L, q);
    } else {
        adrMHS MHS;
        delete_afterMHS(q, MHS);
    }
}

void delete_firstRelasi(ListMK &lmk, ListRelasi &lr, adrRelasi &R, string namaMK, string jenisMHS) {
    adrMK P = searchMK(namaMK, jenisMHS, lmk);
    R = nextRelasi(P);
    if (R == NULL) {
        R = NULL;
        lastRelasi(lr) = NULL;
    } else {
        nextRelasi(P) = nextRelasi(R);
        prevRelasi(R) = NULL;
        nextRelasi(R) = NULL;
        nextMHS(R) = NULL;
    }
}

void delete_lastRelasi(ListMK &lmk, ListRelasi &lr, adrRelasi &R, string namaMK, string jenisMHS) {
    adrMK P = searchMK(namaMK, jenisMHS, lmk);
    R = nextRelasi(P);
    adrRelasi Q = lastRelasi(lr);
    if (nextRelasi(R) == NULL) {
        Q = NULL;
        R = NULL;
    } else {
        lastRelasi(lr) = prevRelasi(Q);
        prevRelasi(Q) = NULL;
        nextRelasi(Q) = NULL;
        nextMHS(Q) = NULL;
    }
}

void delete_afterRelasi(adrRelasi prec, adrRelasi &R) {
    R = nextRelasi(prec);
    nextRelasi(prec) = nextRelasi(R);
    prevRelasi(nextRelasi(R)) = prec;
    nextRelasi(R) = NULL;
    prevRelasi(R) = NULL;
    nextMHS(R) = NULL;
}

void deleteRelasi(ListMK &lmk, ListRelasi &lr, string namaMK, string jenisMHS, string namaMHS) {
    adrMK P = searchMK(namaMK, jenisMHS, lmk);
    adrRelasi Q1 = nextRelasi(P);
    adrRelasi Q2 = lastRelasi(lr);
    adrMHS R1 = nextMHS(Q1);
    adrMHS R2 = nextMHS(Q2);
    if (info(R1).namaMHS == namaMHS) {
        delete_firstRelasi(lmk, lr, Q1, namaMK, jenisMHS);
    } else if (info(R2).namaMHS == namaMHS) {
        delete_lastRelasi(lmk, lr, Q2, namaMK, jenisMHS);
    } else {
        int verif1 = 0;
        while (Q1 != NULL && verif1 == 0) {
            if (info(R1).namaMHS == namaMHS) {
                verif1 = 1;
            }
            Q1 = nextRelasi(Q1);
            R1 = nextMHS(Q1);
        }
        adrRelasi Relasi;
        delete_afterRelasi(Q1, Relasi);
    }
}

int countRelasi(ListMK lmk, string namaMK, string jenisMHS) {
    adrMK MK = searchMK(namaMK, jenisMHS, lmk);
    adrRelasi R = nextRelasi(MK);
    int i;
    while (R != NULL) {
        i++;
        R = nextRelasi(R);
    }
    return i;
}

//search dipikirkan lagi
adrMK searchMK(string namaMK, string jenisMHS, ListMK lmk){
    adrMK MK = firstMK(lmk);
    int verif = 0;
    while (nextMK(MK) != firstMK(lmk) && verif == 0)  {
        if (info(MK).namaMK == namaMK && info(MK).jenisMHS == jenisMHS) {
            verif = 1;
            break;
        }
        MK = nextMK(MK);
    }
    return MK;
}

/*adrMHS searchMHS(string namaMHS, ListMHS L){
    adrMHS P = firstMHS(L);
    while(namaMHS != info(P).namaMHS){
        P = next(P);
    }
    return P;
}*/


void showMK(ListMK L) {
    adrMK P = firstMK(L);
    while (nextMK(P) != firstMK(L)) {
        cout << info(P).namaMK << " " << info(P).kelas << endl;
        P = nextMK(P);
    }
    cout << info(P).namaMK << " " << info(P).kelas << endl;
}

void showMHS(ListMHS L) {
    adrMHS P = firstMHS(L);
    while (nextMHS(P) != firstMHS(L)) {
        cout << info(P).namaMHS << endl;
        P = nextMHS(P);
    }
    cout << info(P).namaMHS << endl;
}

void showAll(ListMK lmk, ListMHS lmhs) {
    adrMK P = firstMK(lmk);
    while (nextMK(P) != firstMK(lmk)) {
        cout << info(P).namaMK << " " << info(P).kelas << endl;
        adrRelasi Q = nextRelasi(P);
        while (Q != NULL) {
            if (nextMHS(Q) != NULL) {
                adrMHS R = nextMHS(Q);
                cout << info(R).namaMHS << endl;
            }
            Q = nextRelasi(Q);
        }
        P = nextMK(P);
    }
    cout << info(P).namaMK << " " << info(P).kelas << endl;
}
//Bukan pake &parameter di procedurenya?
void connecting(ListMK lmk, ListMHS lmhs, adrMK MK, string namaMHS, string namaMK, string jenisMHS) {
    adrRelasi P = nextRelasi(MK);
    while (P != NULL) {
        if (nextMHS(P) == NULL) {
            adrMHS Q = firstMHS(lmhs);
            int verif1 = 0;
            while (nextMHS(Q) != firstMHS(lmhs) && verif1 == 0) {
                if (info(Q).namaMHS == namaMHS) {
                    verif1 = 1;
                }
                Q = nextMHS(Q);
            }
            nextMHS(P) = Q;
        }
        P = nextRelasi(P);
    }
}

void menu(ListMK &lmk, ListMHS &lmhs) {
    string namaMHS;
    string nimMHS;
    string classMHS;
    string jenisMHS;
    cout << "=== LECTURE REGISTRATION ===" << endl;
    cout << "Name: "; cin >> namaMHS;
    cout << "NIM: "; cin >> nimMHS;
    cout << "Class: "; cin >> classMHS;
    cout << "Regular/Int? "; cin >> jenisMHS;
    MHS info = dataMHS(namaMHS, nimMHS, classMHS, jenisMHS);
    adrMHS MHS1;
    newElmMHS(info, MHS1);
    insertMHS(lmhs, MHS1);
    int i = 0;
    string Continue = "Y";
    while (i < 3 && (Continue == "Y" || Continue == "y")) {
        int choice;
        cout << "Lecture: " << endl;
        cout << "1. Struktur Data IF44GAB" << endl;
        cout << "2. Struktur Data IF44INT" << endl;
        cout << "3. Logika Matematika IF44INT" << endl;
        cout << "4. Logika Matematika IF44GAB" << endl;
        cout << "5. Kalkulus IF44GAB" << endl;
        cout << "6. Matematika Diskrit IF44GAB" << endl;
        cout << "Add lecture: "; cin >> choice;
        adrRelasi R;
        newElmRelasi(R);
        adrMK MK;

        int sum;
        string namaMK, kelas;
        if (choice == 1) {
            // kita looping dr elmt mk pertama, liat maxnya, kalo kurang connect-in
            namaMK = "Struktur Data";
            jenisMHS = "Reg";
            sum = countRelasi(lmk, namaMK, jenisMHS);
            MK = searchMK(namaMK, jenisMHS, lmk);
            if (sum < info(MK).nmax_quota) {
                insertRelasi(lmk, R, MK, namaMK, jenisMHS);
                connecting(lmk, lmhs, MK, namaMHS, namaMK, jenisMHS);
            } else {
                cout << "Quota tidak mencukupi.";
            }
        } else if (choice == 2) {
            namaMK = "Struktur Data";
            jenisMHS = "Int";
            sum = countRelasi(lmk, namaMK, jenisMHS);
            MK = searchMK(namaMK, jenisMHS, lmk);
            if (sum < info(MK).nmax_quota) {
                insertRelasi(lmk, R, MK, namaMK, jenisMHS);
                connecting(lmk, lmhs, MK, namaMHS, namaMK, jenisMHS);
            } else {
                cout << "Quota tidak mencukupi.";
            }
        } else if (choice == 3) {
            namaMK = "Logika Matematika";
            jenisMHS = "Int";
            sum = countRelasi(lmk, namaMK, jenisMHS);
            MK = searchMK(namaMK, jenisMHS, lmk);
            if (sum < info(MK).nmax_quota) {
                insertRelasi(lmk, R, MK, namaMK, jenisMHS);
                connecting(lmk, lmhs, MK, namaMHS, namaMK, jenisMHS);
            } else {
                cout << "Quota tidak mencukupi.";
            }
        } else if (choice == 4) {
            namaMK = "Logika Matematika";
            jenisMHS = "Reg";
            sum = countRelasi(lmk, namaMK, jenisMHS);
            MK = searchMK(namaMK, jenisMHS, lmk);
            if (sum < info(MK).nmax_quota) {
                insertRelasi(lmk, R, MK, namaMK, jenisMHS);
                connecting(lmk, lmhs, MK, namaMHS, namaMK, jenisMHS);
            } else {
                cout << "Quota tidak mencukupi.";
            }
        } else if (choice == 5) {
            namaMK = "Kalkulus";
            jenisMHS = "Reg";
            sum = countRelasi(lmk, namaMK, jenisMHS);
            MK = searchMK(namaMK, jenisMHS, lmk);
            if (sum < info(MK).nmax_quota) {
                insertRelasi(lmk, R, MK, namaMK, jenisMHS);
                connecting(lmk, lmhs, MK, namaMHS, namaMK, jenisMHS);
            } else {
                cout << "Quota tidak mencukupi.";
            }
        } else if (choice == 6) {
            namaMK = "Matematika Diskrit";
            jenisMHS = "Reg";
            sum = countRelasi(lmk, namaMK, jenisMHS);
            MK = searchMK(namaMK, jenisMHS, lmk);
            if (sum < info(MK).nmax_quota) {
                insertRelasi(lmk, R, MK, namaMK, jenisMHS);
                connecting(lmk, lmhs, MK, namaMHS, namaMK, jenisMHS);
            } else {
                cout << "Quota tidak mencukupi.";
            }
        }
        cout << "Do you want to continue (Y/N)? "; cin >> Continue;
        cout << endl;
    }
}
