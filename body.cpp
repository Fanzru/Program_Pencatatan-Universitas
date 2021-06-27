#include "adt.h"
#include <iostream>


//====================================
//=============[Parent]===============
//====================================

void createListP(List_parent &L){
    first(L) = NULL;
    last(L) = NULL;
}

address_parent alokasiP(infotype_parent x) {
    address_parent P = new elmlist_parent;
    info(P).namauniv = x.namauniv;
    info(P).akreditasi = x.akreditasi;
    info(P).provinsi = x.provinsi;
    info(P).rektor = x.rektor;
    info(P).tahun = x.tahun;
    info(P).jmlfak = 0;
    next(P) = NULL;
    prev(P) = NULL;
    relasi(P) = NULL;
    return P;
}

void insertFirstP(List_parent &L, address_parent P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}


void deleteFirstP(List_parent &L,address_parent &P){
    if (first(L)== NULL){
        cout << "LIST KOSONG"<<endl;
    } else if ( first(L) == last(L) ){
        P = first(L);
        first(L)= NULL;
        last(L) = NULL;
    } else {
        P = first(L);
        first(L) = next(first(L));
        next(P)= NULL;
        prev(first(L))= NULL;
    }

}
void deleteLastP(List_parent &L,address_parent &P){
    if (first(L)== NULL){
        cout << "LIST KOSONG"<<endl;
    }else if (first(L)==last(L)) {
        P = first(L);
        first(L)= NULL;
        last(L) = NULL;
    }else{
        P = last(L);
        last(L)= prev(last(L));
        next(last(L)) = NULL;
        prev(P)=NULL;
    }
}
void HAPUSuniv(List_parent &L,string U,address_parent &P){
    address_parent R= first(L);
    if (first(L)== NULL){
         cout << "LIST RELASI KOSONG" << endl;
    } else if ( (first(L)==last(L))&& (info(R).namauniv==U)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else if ( info(last(L)).namauniv == U ){
        deleteLastP(L,P);
    }else if ( info(first(L)).namauniv == U ){
        deleteFirstP(L,P);
    } else {
        P = first(L);
        address_parent R;
        while ((next(P)!= NULL)&& (info(P).namauniv != U)){
            R = P;
            P = next(P);
        }
        if (info(P).namauniv != U){
            cout << "Data Tidak diTemukan" <<endl;
        }else if ((info(P).namauniv == U)&&(next(P)== NULL)){
            next(R) = NULL;
        } else {
            next(R) = next(P);
        }
    }

}
address_parent findElmP(List_parent L, infotype_parent x){
    address_parent P = first(L);

    while ((P!= NULL)&&(info(P).namauniv != x.namauniv)){

        P = next(P);
    }
    if (info(P).namauniv == x.namauniv){
        return P;
    } else {
        return NULL;
    }

}
//====================================
//==============[Child]===============
//====================================
void createListC(List_Child &L) {
    first(L) = NULL;
}

address_child alokasiC(infotype_child x) {
    address_child P      = new elmlist_child;
    info(P).bidang       = x.bidang;
    info(P).kejuruan     = x.kejuruan;
    info(P).namafakultas = x.namafakultas;
    next(P) = NULL;
    return P;
}

void insertFirstC (List_Child &L,address_child P){
    if (first(L)== NULL){
        first(L) = P;
    }else {
        next(P)  = first(L);
        first(L) = P;
    }
}
void deleteFirstC(List_Child &L,address_child &P){
    if (first(L)== NULL){
        cout << "List Kosong"<< endl;
    } else if(next(first(L))== NULL){
        P = first(L);
        first(L) = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void HAPUSfak(List_parent &LP, List_Child &LC,string F,address_child &C){
    if (first(LC)== NULL){
        cout << "LIST RELASI KOSONG" << endl;
    } else if ( info(first(LC)).namafakultas == F ){
        deleteFirstC(LC,C);
    } else {
        C = first(LC);
        address_child R;
        while ((next(C)!= NULL)&& (info(C).namafakultas != F) ){
            R = C;
            C = next(C);
        }
        if(info(C).namafakultas != F){
            cout << "Data Tidak diTemukan" <<endl;
        }else if ((info(C).namafakultas == F)&& (next(C)==NULL)){
            next(R) = NULL;
        } else {
            next(R)= next(C);
        }
    }
    if (C!= NULL){
       address_parent A = first(LP);
        while (A != NULL){
            hapusRelasi(A,C);
            A = next(A);
        }
    }
}
address_child findElmC(List_Child L, infotype_child x){
    address_child P = first(L);
    while ((P!= NULL)&&(info(P).namafakultas != x.namafakultas)){
        P = next(P);
    }
    if (info(P).namafakultas == x.namafakultas){
        return P;
    } else {
        return NULL;
    }
}
//===========================================================
void InsertElmR(address_parent &P,address_child &C){
    address_relasi Q = carirelasi(P,C);
    if ((P == NULL)||(C==NULL)){
        cout << "Data Tidak Dapat di Hubungkan" << endl;
    }else if (Q != NULL){
        cout << "Fakultas Sudah ada"<< endl;
    }else if (relasi(P)== NULL){
        address_relasi R = new elmlist_relasi;
        next(R) = NULL;
        child(R) = C;
        info(P).jmlfak++;
        relasi(P)= R;
    } else {
        address_relasi R = new elmlist_relasi;
        next(R) = NULL;
        child(R) = C;
        info(P).jmlfak++;
        next(R) = relasi(P);
        relasi(P) = R;
    }
}
address_relasi carirelasi(address_parent P,address_child C){

    if ((P== NULL)|| (C==NULL)){
        return NULL;
    } else {
        address_relasi R = relasi(P);
        while (R!= NULL){
            if (info(child(R)).namafakultas == info(C).namafakultas){
                return R;
            }
            R = next(R);
        }
        return NULL;

    }

}
void hapusRelasi(address_parent &P, address_child C){
    address_relasi X = relasi(P);
    address_relasi Q;
    if (relasi(P) == NULL){
        cout << "Relasi dari " << info(P).namauniv <<" Kosong " << endl;
    }else if ((P == NULL)||(C == NULL )){
        cout << "Data tidak dapat di hapus"<< endl;
    } else if ((C == child(X) && (next(X) == NULL))){
        info(P).jmlfak = 0;
        relasi(P) = NULL;
    } else if (C == child(X)){
        info(P).jmlfak--;
        Q = relasi(P);
        relasi(P)= next(Q);
        next(Q) = NULL;
    } else {

        while ( (X!= NULL) && (child(X)!= C )){
            Q = X;
            X = next(X);
        }
        if ( child(X)!= C ){
            cout << "Fakultas tidak ada di dalam Univ" << endl;
        } else if ((next(X)== NULL)&&(child(X)= C)){
            info(P).jmlfak--;
            next(Q) = NULL;
        }else {
            info(P).jmlfak--;
            next(Q) = next(X);
        }
    }
}
void TampilFakdanUniv(List_parent L,List_Child LC){
    if (first(L)== NULL){
        cout << "List Kosong"<< endl;
    } else {
        address_parent P = first(L);
        cout << "---------------------------------------" << endl;
        cout << "--------------LIST PARENT--------------" << endl;
        cout << "---------------------------------------" << endl;
        while (P!= NULL){
            cout << "Perguruan Tinggi: "<< info(P).namauniv   << endl;
            cout << "Nama Rektor     : "<< info(P).rektor     << endl;
            cout << "Provinsi        : "<< info(P).provinsi   << endl;
            cout << "Akreditasi      : "<< info(P).akreditasi << endl;
            cout << "Tahun Berdiri   : "<< info(P).tahun      << endl;
            cout << "Fakultas        : "<< endl;
            address_relasi R = relasi(P);
            if ( R== NULL){
                cout << "---------------------------------------" << endl;
                cout << "Tidak ada" << endl;
                cout << "---------------------------------------" << endl;
            }
            while (R != NULL ){
                cout << endl;
                cout << "---------------------------------------" << endl;
                cout << "Nama Fakultas : " <<  info(child(R)).namafakultas << endl;
                cout << "Bidang        : " <<  info(child(R)).bidang << endl;
                cout << "Kejuruan      : " <<  info(child(R)).kejuruan << endl;
                cout << "---------------------------------------" << endl;

                R = next(R);
            }
            cout << "#######################################"<< endl;
            P = next(P);
        }
        cout << "---------------------------------------" << endl;
        cout << "---------------LIST CHILD--------------" << endl;
        cout << "---------------------------------------" << endl;
        if (first(LC)==NULL){
            cout << "LIST CHILD KOSONG"<< endl;
        }else {
            address_child C = first(LC);
            while (C != NULL ){
                cout << endl;
                cout << "---------------------------------------" << endl;
                cout << "Nama Fakultas : " <<  info(C).namafakultas << endl;
                cout << "Bidang        : " <<  info(C).bidang << endl;
                cout << "Kejuruan      : " <<  info(C).kejuruan << endl;
                cout << "---------------------------------------" << endl;

                C = next(C);
            }
        }

    }
}
void tampiljumlahfakultas(List_parent L){
    address_parent P = first(L);
    int a = info(P).jmlfak;
    int b = a;
    string banyak,sedikit;
    if (first(L)== NULL){
        cout << "List Kosong"<< endl;
    } else {
        while (P!= NULL){
            if (b >= info(P).jmlfak ){
                b = info(P).jmlfak;
            }
            if (a <= info(P).jmlfak){
                a = info(P).jmlfak;
            }
            P = next(P);
        }
        if (a == b){
            cout << "semua universitas memiliki jumlah fakultas yang sama" << endl;
        } else {
            cout <<"Tertinggi Memiliki " << a << " Fakultas    :" << endl;
            P = first(L);
            while (P!= NULL){
                if (a == info(P).jmlfak ){
                    cout <<"- Nama Perguruan Tinggi : "<< info(P).namauniv<< endl;
                }
            P = next(P);
            }
            cout <<"Terendah Memiliki " << b << " Fakultas     :" << endl;
            P = first(L);
            while (P!= NULL){
                if (b == info(P).jmlfak ){
                    cout <<"- Nama Perguruan Tinggi : "<< info(P).namauniv<< endl;
                }
            P = next(P);
            }
        }
    }
}

void tampilkanfakultasdalamuniv(address_parent P){
    if (P== NULL){
        cout << "Universitas tidak di temukan "<< endl;
    }else {
        address_relasi X = relasi(P);
        if (relasi(P)== NULL){
            cout << "Universitas Tidak memiliki Fakultas"<< endl;
        } else {
            while (X!= NULL){
                cout << "Nama Fakultas : " <<info(child(X)).namafakultas << endl;
                X = next(X);
            }
        }
    }
}

void tampilfakultas(List_parent L, address_child C){
    if (first(L)== NULL){
        cout << "List Kosong" << endl;
    } else if (C == NULL){
        cout << "Fakultas Tidak Di temukan" << endl;
    } else {
        address_parent P = first(L);
        while (P!= NULL){
            address_relasi X = relasi(P);
            while (X!= NULL){
                if (child(X) == C){
                    cout << "Nama Perguruan Tinggi : "<<info(P).namauniv << endl;
                }
                X = next(X);
            }
            P = next(P);
        }
    }
}
