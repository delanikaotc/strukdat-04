/*
Author      : Delanika Olympiani Trieswari Caesarini
NPM         : 140810180026
Deskripsi   : Program ini menampilkan informasi pegawaix
Tahun       : 2019
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct pegawai{
    char nama[50];
    char bidang[30];
    int gaji;
    pegawai* next;
};
typedef pegawai* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst (List& First, pointer pBaru);
void insertLast (List& First, pointer pBaru);
void traversal (List First);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast (List& First, pointer& pHapus);

main()
{
    pointer pBaru;
    List data;
    int pilihan;

    createList(data);
    while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Tambah data di awal "<<endl;
        cout<<"2. Tambah data di akhir"<<endl;
        cout<<"3. Hapus data paling awal"<<endl;
        cout<<"4. Hapus data paling akhir"<<endl;
        cout<<"5. Tampilkan data"<<endl;
        cout<<"6. Exit"<<endl;
        cout << "Masukan Pilihan : "; cin >> pilihan;
        switch(pilihan){
        case 1:
            createElmt(pBaru);
            insertLast(data, pBaru);
        break;

        case 2:
            createElmt(pBaru);
            insertLast(data, pBaru);
        break;

        case 3:
            deleteFirst(data, pBaru);
        break;

        case 4:
            deleteLast(data, pBaru);
        break;

        case 5:
            traversal(data);
        break;

        case 6:
            return 0;
            break;
        }
        system("pause");
    }
}


void createList(List& First){
    First = NULL;
    }

void createElmt (pointer& pBaru){
    pBaru = new pegawai;
    cin.ignore();
    cout<<"Nama Panjang     : "; cin.getline(pBaru->nama, 50);
    cout<<"Bidang           : "; cin.getline(pBaru->bidang, 30);
    cout<<"Gaji             : "; cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru){
    if(First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast (List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}
void traversal (List First){
    pointer pBantu;
    pBantu=First;
    while(pBantu != NULL){
        cout<<"Nama Panjang     : "<<pBantu->nama<<endl;
        cout<<"Bidang           : "<<pBantu->bidang<<endl;
        cout<<"Gaji             : Rp "<<pBantu->gaji<<endl;
        pBantu=pBantu->next;
    }
}

void deleteFirst(List& First, pointer& pHapus){
    if(First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada  yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast (List& First, pointer& pHapus){
    pointer Last, precLast;
    if (First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        Last=First;
        precLast=NULL;
        while (Last->next!=NULL){
            precLast=Last;
            Last=Last->next;
        }
        pHapus=Last;
        precLast->next=NULL;
    }
}
