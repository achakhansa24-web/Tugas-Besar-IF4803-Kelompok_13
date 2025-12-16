#include "Komposer.h"
#include "Musik.h"
#include <iostream>

using namespace std;

void createListParent(ListParent &L){
    L.first = nullptr;
}

void insertFirstParent(ListParent &L, addressP P){
   P-> next = L.first;
    L.first = P;
}

void insertAfterParent(ListParent &L, addressP prec, addressP P){
   if (prec != nullptr){
        P->next = prec->next;
        prec->next = P;
    }
}

void deleteFirstParent(ListParent &L, addressP &P){
  if (L.first != nullptr){
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteAfterParent(ListParent &L, addressP prec, addressP &P){
  if (prec != nullptr && prec->next != nullptr){
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    }
}

void findLeastProductiveParent(ListParent L){
    if (L.first == nullptr){
        cout << "List Komposer Kosong." << endl;
        return;
    }
    addressP P = L.first;
    int minMusic = -1;

    while (P!= nullptr){
        int jumMusik = 0;
        addressC C = P->firstChild;

        while (C != nullptr){
            jumMusik++;
            C = C->next;
        }

        if (minMusic == -1 || jumMusik < minMusic){
            minMusic = jumMusik;
        }

        P = P->next;
    }

    cout << "komposer dengan jumlah musik paling sedikit ( " << minMusic << " lagu): " << endl;

    P = L.first;
    while (P != nullptr){
        int jumMusik = 0;
        addressC C = P->firstChild;

        while (C != nullptr){
            jumMusik++;
            C = C->next;
        }
        if (jumMusik == minMusic){
            cout << "- ID : " << P->infoK.ID << endl;
            cout << " Nama : " << P->infoK.nama << endl;
        }
        P= P->next;
    }
}


void viewParent(ListParent L){
  if (L.first == nullptr){
        cout << "Tidak ada komposer. \n";
    }else{
        addressP P =L.first;
        while (P!= nullptr){
            cout << "ID: " << P->infoK.ID << " | Nama: " << P->infoK.nama << endl;
            P = P->next;
        }
    }
}
