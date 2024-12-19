#include <iostream>
#include <cstdio>
#include "relation.h"
#include <cstdlib>


using namespace std;

void enterPressed(){
    char ch;
    cin.get(ch);
    while(ch != '\n'){
        cin.get(ch);
    }
}

int main()
{
    listParent LP;
    createListParent(LP);
    listChild LC;
    createListChild(LC);
    listRelations LR;
    createListRelation(LR);

    printMenu();
    int x = 99;
    printf("Pilihan: ");
    cin >> x;
    cin.ignore();
    string namaartis;
    string judulsinetron;
    while (x != 0){
        switch(x){
            case 1: // input judul sinteron baru
                printf("Masukkan judul sinetron: ");
                getline(cin, judulsinetron);
                {
                    adrP P = createElemenParent(judulsinetron);
                    adrP findSame = findParent(LP, judulsinetron);
                    if (findSame == NULL){
                        insertLastParent(LP, P);
                        printf("\ninput sinetron berhasil\n");
                    } else {
                        printf("\ninput tidak berhasil judul :'%s' sudah ada\n", judulsinetron.c_str());
                    }
                }
                printf("tekan enter untuk lanjut: ");
                enterPressed();
                system("CLS");
                break;

            case 2: //input nama artis baru
                printf("Masukkan nama artis: ");
                getline(cin, namaartis);
                {
                    adrC C = createElemenchild(namaartis);
                    adrC findSame = findChild(LC, namaartis);
                    if(findSame == NULL){
                        insertLastChild(LC, C);
                        printf("\ninput artis berhasil\n");
                    } else {
                        printf("\ninput arti tidak berhasil artis bernama: '%s' sudah ada\n", namaartis.c_str());
                    }
                }
                printf("tekan enter untuk lanjut: ");
                enterPressed();
                system("CLS");
                break;

            case 3: //input data relasi
                showAllParent(LP);
                printf("\n\n");
                printAllChild(LC);
                printf("\n\n");
                printf("Masukkan judul sinetron yang ada di list: ");
                getline(cin,judulsinetron);
                printf("Masukkan nama artis yang ada di list: ");
                getline(cin, namaartis);
                {
                    adrP FP = findParent(LP, judulsinetron);

                    if (FP == NULL){
                        printf("sinetron tidak ditemukan\n");
                        printf("tekan enter untuk lanjut: ");
                        enterPressed();
                        system("CLS");
                        break;
                    }
                    adrC FC = findChild(LC, namaartis);
                    if (FC == NULL){
                        printf("artis tidak ditemukan");
                        printf("tekan enter untuk lanjut: ");
                        enterPressed();
                        system("CLS");
                        break;
                    }

                    if(findSameRelation(LR, FC, FP)){
                        printf("\ninput relasi tidak berhasil, sinetron '%s' sudah memiliki artis '%s'\n", judulsinetron.c_str(), namaartis.c_str());
                        break;
                    }
                    adrR R = createElemenRelation(FC, FP);
                    insertLastRelation(LR, R);
                }
                printf("Membuat relasi...\n");
                printf("tekan enter untuk lanjut: ");
                enterPressed();
                system("CLS");
                break;

            case 4: //tampilkan seluruh sinetron
                showAllParent(LP);
                printf("\n");
                printf("tekan enter untuk lanjut: ");
                enterPressed();
                system("CLS");
                break;

            case 5: //tampilkan seluruh artis
                printAllChild(LC);
                printf("\n");
                printf("tekan enter untuk lanjut: ");
                enterPressed();
                system("CLS");
                break;

            case 6: //ubah data sinetron atau data artis
                {
                    string pilihan;
                    printf("Pilih yang ingin diubah(artis / sinetron)? ");
                    getline(cin, pilihan);
                    if(pilihan == "sinetron"){
                        showAllParent(LP);
                        printf("\n masukkan judul sinetron yang akan diubah: ");
                        string judullama;
                        getline(cin,judullama);
                        printf("\n masukkan judul baru: ");
                        string judulbaru;
                        getline(cin,judulbaru);
                        changeDataParent(LP, judullama, judulbaru);
                    } else if(pilihan == "artis"){
                        printAllChild(LC);
                        printf("\n masukkan nama artis yang akan diubah: ");
                        string namalama;
                        getline(cin, namalama);
                        printf("\n masukkan nama baru: ");
                        string namabaru;
                        getline(cin, namabaru);
                        changeDataChild(LC, namalama, namabaru);
                    } else {
                        printf("pilihan salah, kembali ke menu awal");
                    }
                }
                printf("\n");
                printf("tekan enter untuk lanjut: ");
                enterPressed();
                system("CLS");
                break;

            case 7://hapus parent dari list dan menghapus relasinya sert child yang tidak memiliki parent lain
                deleteParentandRelationChild(LP,LC,LR);
                printf("\n");
                printf("tekan enter untuk lanjut: ");
                enterPressed();
                system("CLS");
                break;

            case 8:


            case 9: // menampilkan semua sinetron beserta artis yang memainkan sinetron tersebut
                showAllChildFromAllParent(LP, LC, LR);
                printf("\n");
                printf("tekan enter untuk lanjut: ");
                enterPressed();
                system("CLS");
                break;

            default:
                printf("Pilihan tidak ada\n");
                printf("tekan enter untuk lanjut: ");
                enterPressed();
                system("CLS");
                break;
        }
        printMenu();
        printf("Pilihan: ");
        cin >> x;
        cin.ignore();
    }
    return 0;
}


