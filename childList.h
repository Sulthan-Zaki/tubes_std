#ifndef CHILDLIST_H_INCLUDED
#define CHILDLIST_H_INCLUDED
#include <iostream>
#define infoC(C) C->infoC
#define nextC(C) C->nextC
#define firstC(L) L.firstC

using namespace std;


typedef string namaArtis;


typedef namaArtis infotypeC;
typedef struct elemenC *adrC;

struct elemenC{
    infotypeC infoC;
    adrC nextC;
};

struct listChild{
    adrC firstC;
};

void createListChild(listChild &L);
adrC createElemenchild(infotypeC newArtis);
void insertLastChild(listChild &L, adrC C);
void deleteAfterChild(listChild &L, adrC C);
adrC findChild(listChild &L, string nama);
adrC findChildBefore(listChild &L, string nama);
void changeDataChild(listChild &L, string namaLama, string namaBaru);
void printAllChild(listChild L);



#endif // CHILDLIST_H_INCLUDED
