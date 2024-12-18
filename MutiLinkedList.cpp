#include "relation.h"
#include <iostream>
#include <cstdio>
#define null NULL

using namespace std;

void createListParent(listParent &L){
    /*
    is: terdapat variable list yang akan dibuat sehingga menjadi valid
    fs: first dari list menjadi null sehingga valid
     */
    firstP(L) = NULL;
};
adrP createElemenParent(infotypeP newSinetron){
    /*is: diberikan sebuah infotypeP yang sudah diisi seblumnya
    fs: mengembalikan address P, mebuat elemenP terlebih dahulu lalu infotypeP nya dimasukkan*/
    adrP P;
    P = new(elemenP);
    infoP(P) = newSinetron;
    nextP(P) = NULL;
    return P;
};
void insertFirstParent(listParent &L, adrP P){
    /* is: diberikan variabel l merupan list yang mungkin kosong, ada P yang sudah menunjuk elemenP
    fs: P dimasukkan kedalam list dengan cara insert first*/
    nextP(P) = firstP(L);
    firstP(L) = P;
};
void insertLastParent(listParent &L, adrP P){
    /* is: diberikan variabel l merupan list yang mungkin kosong, ada P yang sudah menunjuk elemenP
    fs: P dimasukkan kedalam list dengan cara insert last*/
    adrP Q = firstP(L);
    if (firstP(L) != NULL){
        while (nextP(Q) != null ){
            Q = nextP(Q);
        }
        nextP(Q) = P;
    } else {
        firstP(L) = P;
    }

};
void insertParentGeneral(listParent &L, adrP P){

};
adrP findParent(listParent L, string cariNamaSinetron){
   /*is: diberikan string yang merupakan nama sinetron
   fs: akan dicari pada list nama sinetron tersebut lalu direturn dapat berupa null apabila tidak ketemu */
    adrP P = firstP(L);
    while (P != null){
        if (infoP(P) == cariNamaSinetron){
            break;
        }
        P = nextP(P);
    }
    return P;
};


adrP findParentBefore(listParent L, string cariNamaSinetron){
    adrP P = firstP(L);
    if(firstP(L) == null){
        return null;
    } else if(infoP(P) == cariNamaSinetron){
        return P;
    }else {
        while (nextP(P) != null){
            if (infoP(next(P)) == cariNamaSinetron){
                break;
            }
        }
        return P;
    }
    return null;
};

void showAllParent(listParent L){
    /*menampilkan semua isi parent */
    printf("-----------------------------\n");
    printf(" S E M U A   S I N E T R O N \n");
    printf("-----------------------------\n");

    adrP P = firstP(L);
    if (P == null) {
        cout << " Tidak Ada Sinetron" << endl;
        return;
    }
    int i = 1;
    while(P != null){
        printf("  %d. %s\n", i, infoP(P).c_str());
        P = nextP(P);
        i++;
    }

};
void deleteAfterParent(listParent &L, adrP P){
    /*is: diberikan sebuah address yaitu P
    fs: address setelah P akan dihapus */
    if (P != null){
        if (P != firstP(L)){
            adrP Q = nextP(P);
            nextP(P) = nextP(Q);
            nextP(Q) = null;
            delete(Q);
        } else {
            firstP(L) = nextP(P);
            nextP(P) = null;
            delete(P);
        }
    }
};



void changeDataParent(listParent &LP, string namaLama, string namaBaru){
    adrP P = firstP(LP);
    while (P != null){
        if (infoP(P) == namaLama){
            break;
        }
        P = nextP(P);
    }
    if (P != null){
        infoP(P) = namaBaru;
        cout << "data sudah diperbarui" << endl;
    } else {
        cout << "sinetron tidak ditemukan" << endl;
    }
};

void createListChild(listChild &L){
    /*is: terdapat variable list yang akan dibuat sehingga menjadi valid
    fs: first dari list menjadi null sehingga valid*/
    firstC(L) = NULL;
};
adrC createElemenchild(infotypeC newArtis){
    /*is: diberikan sebuah infotypeC yang sudah diisi seblumnya
    fs: mengembalikan address P, mebuat elemenC terlebih dahulu lalu infotypeP nya dimasukkan*/
    adrC P;
    P = new(elemenC);
    infoC(P) = newArtis;
    nextC(P) = null;
    return P;
};
void insertLastChild(listChild &L, adrC C){
    adrC P = firstC(L);
    if (P != null){
        while(nextC(P) != null){
            P = nextC(P);
        }
        nextC(P) = C;
    } else {
        firstC(L) = C;
    }
};
void deleteAfterChild(listChild &L, adrC C){
    if (C != null){
        if (C == firstC(L)){
            firstC(L) = nextC(C);
            nextC(C) = null;
            delete C;
        }
        if (nextC(C) != null){
            adrC X = nextC(C);
            nextC(C) = nextC(X);
            nextC(X) = null;
            delete X;
        }
    }

};

adrC findChild(listChild &L, string nama){
    adrC P = firstC(L);
    while(P != null){
        if(infoC(P) == nama){
            break;
        }
        P = nextC(P);
    }
    return P;
};
adrC findChildBefore(listChild &L, adrC child){
    if (child == firstC(L)){
        return child;
    }
    adrC P = firstC(L);
    while(P != null){
        if (next(P) == child){
            break;
        }
        P = nextC(P);
    }
    return P;
};

void changeDataChild(listChild &L, string namaLama, string namaBaru){
    adrC P = firstC(L);
    while (P != null){
        if (infoC(P) == namaLama){
            break;
        }
        P = nextC(P);
    }
    if (P != null){
        infoC(P) = namaBaru;
        cout << "data sudah diperbarui" << endl;
    } else {
        cout << "Tidak ditemukan" << endl;
    }
};

void printAllChild(listChild L){
    printf("-----------------------------\n");
    printf("    S E M U A   A R T I S    \n");
    printf("-----------------------------\n");

    adrC P = firstC(L);
    if (P == null) {
        cout << " Tidak Ada Artis" << endl;
        return;
    }
    int i = 1;
    while(P != null){
        printf("  %d. %s\n", i, infoC(P).c_str());
        P = nextC(P);
        i++;
    }
};

void createListRelation(listRelations &L){
    firstR(L) = null;
};
adrR createElemenRelation(adrC child, adrP parent){
    adrR relation = new(elemenR);
    nextR(relation) = null;
    infoRC(relation)= child;
    infoRP(relation) = parent;
    return relation;
}
void insertLastRelation(listRelations &L, adrR relation){
    adrR P = firstR(L);
    if (P != null){
        while (nextR(P) != null){
            P = nextR(P);
        }
        nextR(P) = relation;
    } else {
        firstR(L) = relation;
    }
};
void deleteParentandRelationChild(listParent &LP, listChild &LC, listRelations &LR){
    string judul;
    printf("Masukkan judul sinetron yang ingin dihapus: ");
    cin >> judul;
    adrP P = findParent(LP, judul);
    if (P == null){
        printf("sinetron tidak ditemukan\n");
        return;
    } else{
        adrR FR = firstR(LR);
        while(FR != null){
            if (infoRP(FR) == P){
                adrR FR2 = firstR(LR);
                int ketemu = 0;
                while(FR2 != null){
                    if (infoRC(FR2) == infoRC(FR)){
                        ketemu++;
                    }
                    FR2 = nextR(FR2);
                }
                FR2 = FR;
                FR = nextR(FR);
                if (ketemu >= 2){
                    deleteRelation(LR, FR2);
                } else {
                    adrC C = findChildBefore(LC, infoRC(FR2));
                    deleteAfterChild(LC, C);
                    deleteRelation(LR, FR2);
                }
            } else {
                FR = nextR(FR);
            }

        }
        P = findParentBefore(LP, judul);
        deleteAfterParent(LP, P);
        printf("sinetron telah dihapus, Apabila artis hanya memainkan sinetron tersebut maka artis dihapus");
    }
};
void deleteRelation(listRelations &LR, adrR relation){
    if (relation == firstR(LR)){
        firstR(LR) = nextR(relation);
        nextR(relation) = null;
        delete(relation);
    } else{
        adrR FR = firstR(LR);
        while(nextR(FR) != relation){
            FR = nextR(FR);
        }
        nextR(FR) = nextR(relation);
        nextR(relation) = null;
        delete(relation);
    }
};
void showAllChildFromAllParent(listParent LP, listChild LC, listRelations LR){
    adrP P = firstP(LP);
    int i = 1;
    printf("----------------------------------------------------------\n");
    printf("    S E M U A  S I N E T R O N  D E N G A N  A R T I S    \n");
    printf("----------------------------------------------------------\n");

    while(P != null) {
        printf(" %d. %s :", i, infoP(P).c_str());
        adrR R = firstR(LR);
        while(R != null){
            if (infoRP(R) == P){
                cout << infoC(infoRC(R)) << ", ";
            }
            R = nextR(R);
        }
        cout << endl;
        P = nextP(P);
    }

    printf("----------------------------------------------------------\n");
};
void findChildFromParent(listChild C, adrP P);
void deleteChildFromParent(listChild &LC, listRelations &LR, adrP P);
void countParentFromChild(listRelations LR, adrC C);
void printMenu(){
    printf("-----------------------------\n");
    printf("           M E N U           \n");
    printf("-----------------------------\n");

    printf("1. Insert data sinetron\n2. insert data artis\n3. buat relasi antar sinetorn dan artis\n4. tampilkan semua sinetron\n5. tampilkan semua artis\n6. ubah data sinetron atau data artis\n7. hapus sinetron\n");
    printf("8. hapus artis dari sinetron tertentu\n9. tampilkan semua sinetron beserta artis\n10. tampilkan banyak film yang dimainkan artis\n");
    printf("-----------------------------\n");
}
