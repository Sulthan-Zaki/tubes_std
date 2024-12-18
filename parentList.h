#ifndef PARENTLIST_H_INCLUDED
#define PARENTLIST_H_INCLUDED
#include <iostream>
#define infoP(P) P->infoP
#define nextP(P) P->nextP
#define firstP(L) L.firstP

using namespace std;


typedef string judulSinetron;

typedef judulSinetron infotypeP;
typedef struct elemenP *adrP;

struct elemenP{
    infotypeP infoP;
    adrP nextP;
};
struct listParent{
    adrP firstP;
};



void createListParent(listParent &L);
adrP createElemenParent(infotypeP newSinetron);
void insertFirstParent(listParent &L, adrP P);
void insertLastParent(listParent &L, adrP P);
void insertParentGeneral(listParent &L, adrP P);
adrP findParent(listParent L, string cariNamaSinetron);
adrP findParentBefore(listParent L, string cariNamaSinetron);
void showAllParent(listParent L);
void deleteAfterParent(listParent &L, adrP P);
void changeDataParent(listParent &LP, string namaLama, string namaBaru);

#endif // PARENTLIST_H_INCLUDED
