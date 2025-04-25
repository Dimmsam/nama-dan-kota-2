#include "NSLL.h"

bool isEmpty(List L) {
    return L == NULL;
}

void Create_Node(address *p, infotype data) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        strcpy((*p)->info, data);  
        (*p)->next = NULL;
    }
}

void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

void PrintList(List L) {
    address P = L;
    if (P == NULL) {
        printf("  (Nama tidak ada)\n");
    }
    while (P != NULL) {
        printf("  - %s\n", P->info);
        P = P->next;
    }
}

address Search(List L, infotype X) {
    address P = L;
    while (P != NULL && P->info != X) {
        P = P->next;
    }
    return P;
}

bool fSearch(List L, address P) {
    address PSearch = L;
    while (PSearch != NULL && PSearch != P) {
        PSearch = PSearch->next;
    }
    return (PSearch == P);
}

address SearchPrec(List L, infotype X) {
    address P = L;
    address Prec = NULL;

    while (P != NULL && P->info != X) {
        Prec = P;
        P = P->next;
    }
    return Prec;
}

void InsertFirst(List *L, address P) {
    if (isEmpty(*L)) {
        *L = P;
        P->next = NULL;
    } else {
        P->next = *L;
        *L = P;
    }
}

void InsertAfter(List *L, address P, address Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    } else {
        printf("Prec bernilai NULL, tidak dapat menyisipkan setelahnya.\n");
    }
}

void InsertLast(List *L, address P) {
    if (isEmpty(*L)) {
        *L = P;
    } else {
        address Last = *L;
        while (Last->next != NULL) {
            Last = Last->next;
        }
        Last->next = P;
    }
}

void InsVFirst(List *L, infotype X) {
    address P;

    Create_Node(&P, X);
    if (P != NULL) {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X) {
    address P;

    Create_Node(&P, X);
    if (P != NULL) {
        InsertLast(L, P);
    }
}

void DelFirst(List *L, address *P) {
    if (!isEmpty(*L)) {
        *P = *L;
        *L = (*P)->next;
        DeAlokasi(P);
    }
}

void DelP(List *L, infotype X) {
    address P, Prec;

    P = Search(*L, X);
    if (P != NULL) {
        if (P == *L) {
            DelFirst(L, &P);
        } else {
            Prec = SearchPrec(*L, X);
            DelAfter(L, &P, Prec);
            DeAlokasi(&P);
        }
    } else {
        printf("Data tidak ditemukan.\n");
    }
}

void DelLast(List *L, address *P) {
    if (!isEmpty(*L)) {
        address Last = *L;
        address Prec = NULL;

        while (Last->next != NULL) {
            Prec = Last;
            Last = Last->next;
        }
        *P = Last;
        if (Prec != NULL) {
            Prec->next = NULL;
        } else {
            *L = NULL;
        }
        DeAlokasi(P);
    }
}

void DelAfter(List *L, address *Pdel, address Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        *Pdel = Prec->next;
        Prec->next = (*Pdel)->next;
        DeAlokasi(Pdel);
    } else {
        printf("Prec bernilai NULL atau tidak memiliki next.\n");
    }
}

void DelVFirst(List *L, infotype *X) {
    address P;

    if (!isEmpty(*L)) {
        P = *L;
        strcpy(*X, P->info);
        *L = P->next;
        DeAlokasi(&P);
    }
}

void DelVLast(List *L, infotype *X) {
    address P, Prec = NULL;

    if (!isEmpty(*L)) {
        P = *L;
        while (P->next != NULL) {
            Prec = P;
            P = P->next;
        }
        strcpy(*X, P->info); 
        if (Prec == NULL) {
            *L = NULL;
        } else {
            Prec->next = NULL;
        }
        DeAlokasi(&P);
    }
}

void insertKota(addressKota *firstKota, char *namaKota) {
    addressKota newKota = (addressKota)malloc(sizeof(Kota));
    if (newKota != NULL) {
        strcpy(newKota->kt, namaKota);
        newKota->p = NULL;
        newKota->next = *firstKota;
        *firstKota = newKota;
    }
}

addressKota searchKota(addressKota firstKota, char *namaKota) {
    addressKota current = firstKota;
    while (current != NULL && strcmp(current->kt, namaKota) != 0) {
        current = current->next;
    }
    return current;
}

void deleteKota(addressKota *firstKota, char *namaKota) {
    addressKota current = *firstKota;
    addressKota prev = NULL;

    while (current != NULL && strcmp(current->kt, namaKota) != 0) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            *firstKota = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

void insertOrang(addressKota *firstKota, char *namaKota, char *namaOrang) {
    addressKota kota = searchKota(*firstKota, namaKota);
    if (kota != NULL) {
        address newOrang = (address)malloc(sizeof(ElmtList));
        if (newOrang != NULL) {
            strcpy(newOrang->info, namaOrang);
            newOrang->next = kota->p;
            kota->p = newOrang;
        }
    } else {
        printf("Kota tidak ditemukan.\n");
    }
}

void tampilSemua(addressKota firstKota) {
    addressKota currentKota = firstKota;
    while (currentKota != NULL) {
        printf("Kota: %s\n", currentKota->kt);
        PrintList(currentKota->p);
        currentKota = currentKota->next;
    }
}
