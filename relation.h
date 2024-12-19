#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>
#include "parentList.h"
#include "childList.h"

#define nextR(P) P->nextR
#define infoRC(P) P->Child
#define infoRP(P) P->Parent
#define firstR(L) L.firstR

using namespace std;

typedef struct elemenR *adrR;

struct elemenR{
    adrR nextR;
    adrC Child;
    adrP Parent;
};

struct listRelations{
    adrR firstR;
};


void createListRelation(listRelations &L);
adrR createElemenRelation(adrC child, adrP parent);
void insertLastRelation(listRelations &L, adrR relation);
void deleteParentandRelationChild(listParent &LP, listChild &LC, listRelations &LR);
void deleteRelation(listRelations &LR, adrR relation);
void showAllChildFromAllParent(listParent LP, listChild LC, listRelations LR);
bool findSameRelation(listRelations LR, adrC child, adrP parent);
void printChildFromParent(listRelations LR, adrP P);
void deleteChildFromParent(listChild &LC, listRelations &LR, adrP P, adrC C);
void countParentFromChild(listRelations LR, listChild LC);
void printMenu();


#endif // RELATION_H_INCLUDED
