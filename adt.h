#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>

using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define child(P) P->child
#define parent(P) P->parent
#define relasi(P) P->relasi

struct infotype_child{
    string namafakultas, kejuruan, bidang;
};

struct infotype_parent{
    string namauniv, provinsi, tahun, rektor,akreditasi;
    int jmlfak;
};

typedef struct elmlist_relasi *address_relasi;
typedef struct elmlist_parent *address_parent;
typedef struct elmlist_child *address_child;


struct elmlist_parent{
    infotype_parent info;
    address_parent next;
    address_parent prev;
    address_relasi relasi;
};
struct List_parent{
    address_parent first;
    address_parent last;
};
void createListP(List_parent &L);
void insertFirstP(List_parent &L, address_parent P);
void deleteFirstP(List_parent &L, address_parent &P);
void deleteFirstP(List_parent &L,address_parent &P);
address_parent alokasiP(infotype_parent x);
address_parent findElmP(List_parent L, infotype_parent x);
void HAPUSuniv(List_parent &L,string U,address_parent &P);
//===========================================
//===========================================
//===========================================

struct elmlist_child{
    infotype_child info;
    address_child next;
};

struct List_Child{
    address_child first;

};
void createListC(List_Child &L);
address_child alokasiC(infotype_child x);
void insertFirstC (List_Child &L,address_child P);
void deleteFirstC(List_Child &L,address_child &P);
address_child findElmC(List_Child L, infotype_child x);
void deleteAfterP(List_Child &L,address_child Prec,address_child &P);
void HAPUSfak(List_parent &LP, List_Child &LC,string F,address_child &C);
//============================================================


struct elmlist_relasi {
    address_child child;
    address_relasi next;
};
void InsertElmR(address_parent &P,address_child &C);
void TampilFakdlmUniv(List_parent L);
void tampiljumlahfakultas(List_parent L);
address_relasi carirelasi(address_parent P,address_child C);
void tampilfakultas(List_parent L, address_child C);
void tampilkanfakultasdalamuniv(address_parent P);
void tampiljumlahfakultas(List_parent L);
void TampilFakdanUniv(List_parent L,List_Child LC);
void hapusRelasi(address_parent &P, address_child C);
#endif // ADT_H_INCLUDED
