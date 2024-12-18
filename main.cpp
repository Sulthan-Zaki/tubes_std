#include <iostream>
#include <cstdio>
#include "relation.h"
#include <cstdlib>


using namespace std;

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
    string namaartis;
    string judulsinetron;
    while (x != 0){
        switch(x){
            case 1:
                printf("Masukkan judul sinetron: ");
                cin >> judulsinetron;
                {
                    adrP P = createElemenParent(judulsinetron);
                    insertLastParent(LP, P);
                }
                printf("input apa saja untuk lanjut: ");
                cin.ignore();
                cin.get();
                system("CLS");
                break;

            case 2:
                printf("Masukkan nama artis: ");
                cin >> namaartis;
                {
                    adrC C = createElemenchild(namaartis);
                    insertLastChild(LC, C);
                }
                printf("input apa saja untuk lanjut: ");
                cin.ignore();
                cin.get();
                system("CLS");
                break;

            case 3:
                showAllParent(LP);
                printf("\n\n");
                printAllChild(LC);
                printf("\n\n");
                printf("Masukkan judul sinetron yang ada di list: ");
                cin >> judulsinetron;
                printf("Masukkan nama artis yang ada di list: ");
                cin >> namaartis;
                {
                    adrP FP = findParent(LP, judulsinetron);

                    if (FP == NULL){
                        printf("sinetron tidak ditemukan\n");
                        printf("input apa saja untuk lanjut: ");
                        cin.ignore();
                        cin.get();
                        system("CLS");
                        break;
                    }
                    adrC FC = findChild(LC, namaartis);
                    if (FC == NULL){
                        printf("artis tidak ditemukan");
                        printf("input apa saja untuk lanjut: ");
                        cin.ignore();
                        cin.get();
                        system("CLS");
                        break;
                    }

                    adrR R = createElemenRelation(FC, FP);
                    insertLastRelation(LR, R);
                }
                printf("Membuat relasi...\n");
                printf("input apa saja untuk lanjut: ");
                cin.ignore();
                cin.get();
                system("CLS");
                break;

            case 4: //tampilkan seluruh sinetron
                showAllParent(LP);
                printf("\n");
                printf("input apa saja untuk lanjut: ");
                cin.ignore();
                cin.get();
                system("CLS");
                break;

            case 5: //tampilkan seluruh artis
                printAllChild(LC);
                printf("\n");
                printf("input apa saja untuk lanjut: ");
                cin.ignore();
                cin.get();
                system("CLS");
                break;

            case 6: //ubah data sinetron atau data artis
                {
                    string pilihan;
                    printf("Pilih yang ingin diubah(artis / sinetron)? ");
                    cin >> pilihan;
                    if(pilihan == "sinetron"){
                        showAllParent(LP);
                        printf("\n masukkan judul sinetron yang akan diubah: ");
                        string judullama;
                        cin >> judullama;
                        printf("\n masukkan judul baru: ");
                        string judulbaru;
                        cin >> judulbaru;
                        changeDataParent(LP, judullama, judulbaru);
                    } else if(pilihan == "artis"){
                        printAllChild(LC);
                        printf("\n masukkan nama artis yang akan diubah: ");
                        string namalama;
                        cin >> namalama;
                        printf("\n masukkan nama baru: ");
                        string namabaru;
                        cin >> namabaru;
                        changeDataChild(LC, namalama, namabaru);
                    } else {
                        printf("pilihan salah, kembali ke menu awal");
                    }
                }
                printf("\n");
                printf("input apa saja untuk lanjut: ");
                cin.ignore();
                cin.get();
                system("CLS");
                break;

            case 7:
                deleteParentandRelationChild(LP,LC,LR);
                printf("\n");
                printf("input apa saja untuk lanjut: ");
                cin.ignore();
                cin.get();
                system("CLS");
                break;

            case 9:
                showAllChildFromAllParent(LP, LC, LR);
                printf("\n");
                printf("input apa saja untuk lanjut: ");
                cin.ignore();
                cin.get();
                system("CLS");
                break;

            default:
                // Optional default case to handle unexpected input
                printf("Pilihan tidak ada\n");
                printf("input apa saja untuk lanjut: ");
                cin.ignore();
                cin.get();
                system("CLS");
                break;
        }
        printMenu();
        printf("Pilihan: ");
        cin >> x;
    }
    return 0;
}
