#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "stdlib.h"
#include "conio.h"
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#include "parentList.h"
#include "relasiList.h"
#include "childList.h"

List_parent LP;
List_child LC;
list_relasi LR;

string nama;

void menuLogin(List_parent& LP,List_child& LC,list_relasi& LR);
void menuAdmin(List_parent& LP,List_child& LC,list_relasi& LR);
void editPermission(List_parent& LP, list_relasi& LR);
void addPohon(List_parent& LP);
void addInvestor(List_child& LC);
void addRelasi(List_parent& LP, List_child& LC, list_relasi& LR, string namaOrang);
void delParent(list_relasi LR,List_parent& LP);
void delInvestasi(List_parent LP,List_child LC,list_relasi& LR);
void menuInvestor(List_parent& LP, list_relasi& LR, List_child& LC,string& nama);
void userLogin(List_parent& LP, list_relasi& LR, List_child& LC);

void menuLogin(List_parent& LP,List_child& LC,list_relasi& LR){
    int userChoise;
    do{
        system("cls");
        cout<<"USER LOGIN \n";
        cout<<"=========== \n";
        cout<<"[1] ADMIN"<<endl;
        cout<<"[2] INVESTOR \n\n"<<endl;
        cout<<"[99] exit aplication \n";
        cout<<"Pilihan Anda : ";
        cin>>userChoise;
        if(userChoise==99){
            system("cls");
            cout<<"Thank you for coming..";
        } else if (userChoise>2){
            system("cls");
            cout<<"Tidak ada pilihan menu "<<userChoise;
            getch();
        } else if (userChoise==1){
            menuAdmin(LP,LC,LR);
        }else if (userChoise== 2){
            userLogin(LP,LR,LC);
        }

    } while (userChoise!=99);
}
void menuAdmin(List_parent& LP,List_child& LC,list_relasi& LR){
    int userChoise;
    do{
        system("cls");
        cout<<"USER LOGIN >> ADMIN \n";
        cout<<"==================== \n";
        cout<<"[1] Lihat data pohon \n";
        cout<<"[2] Lihat data investor \n";
        cout<<"[3] Lihat data investasi \n";
        cout<<"[4] Edit data pohon \n";
        cout<<"[5] Tambah data pohon\n";
        cout<<"[6] Hapus data pohon \n\n";
        cout<<"[99] Kembali ke menu login\n";
        cout<<"Pilihan Anda : ";
        cin>>userChoise;
        if(userChoise==99){
            //menuLogin(LP,LC,LR);
        } else if (userChoise>6){
            system("cls");
            cout<<"Tidak ada pilihan menu "<<userChoise;
            getch();
        } else if (userChoise==1){
            system("cls");
            cout<<"... >> ADMIN >> LIHAT DATA POHON \n";
            cout<<"================================= \n";
            printInfo(LP);
            getch();
        } else if (userChoise==2){
            system("cls");
            cout<<"... >> ADMIN >> LIHAT DATA INVESTOR \n";
            cout<<"==================================== \n";
            printInfo(LC);
            getch();
        } else if (userChoise==3){
            system("cls");
            cout<<"... >> ADMIN >> LIHAT INVESTASI \n";
            cout<<"================================ \n";
            printInfo(LR);
            getch();
        } else if(userChoise==4){
            editPermission(LP,LR);
        } else if(userChoise==5){
            addPohon(LP);
        } else if(userChoise==6){
            delParent(LR,LP);
        }
    } while (userChoise!=99);
}
void userLogin(List_parent& LP, list_relasi& LR, List_child& LC){
    string nama;
    int userChoise;
    do{
        system("cls");
        cout<<"INVESTOR >> USER LOGIN \n";
        cout<<"=======================\n";
        cout<<"[1] DAFTAR BARU\n";
        cout<<"[2] MASUK\n\n";
        cout<<"[9] Kembali ke menu sebelumnya \n";
        cout<<"Pilihan Anda : ";
        cin>>userChoise;
        if (userChoise==1){
            addInvestor(LC);
        } else if (userChoise==2){
            system("cls");
            cout<<"Masukkan nama Anda : ";
            cin>>nama;
            if (searchChild(LC,nama)){
                menuInvestor(LP,LR,LC,nama);
            } else {
                cout<<"Nama Anda tidak terdaftar...";
                getch();
            }
        }
    }while (userChoise==99);
}
void menuInvestor(List_parent& LP, list_relasi& LR, List_child& LC,string& nama){
        int userChoise;
        do{
            system("cls");
            cout<<"USER LOGIN >> INVESTOR \n";
            cout<<"==================== \n";
            cout<<"[1] Tambah Relasi Investasi \n";
            cout<<"[2] Lihat Data Investasi\n";
            cout<<"[3] Hapus data Investasi \n\n";
            cout<<"[99] Kembali ke menu login\n";
            cout<<"Pilihan Anda : ";
            cin>>userChoise;
            if(userChoise==99){
                //menuLogin(LP,LC,LR);
            } else if (userChoise>6){
                system("cls");
                cout<<"Tidak ada pilihan menu "<<userChoise;
                getch();
            } else if (userChoise==1){
                addRelasi(LP,LC,LR,nama);
            } else if (userChoise==2){
                system("cls");
                cout<<"... >> ADMIN >> LIHAT INVESTASI \n";
                cout<<"================================ \n";
                if (first(LR)!=NULL){
                    address_relasi P= first(LR);
                    do{
                        if (info(child(P)).namaOrang==nama){
                            cout<<" "<<setiosflags(ios::left)<<setw(1)<<info(child(P)).namaOrang;
                            cout<<"/";
                            cout<<" "<<setiosflags(ios::left)<<setw(17)<<info(parent(P)).namaPohon;
                            cout<<" "<<setiosflags(ios::left)<<setw(18)<<info(parent(P)).biayaPohon;
                            cout<<" "<<setiosflags(ios::left)<<setw(13)<<info(P).jumlah_pohon;
                            cout<<" "<<setiosflags(ios::left)<<setw(22)<<info(P).keuntungan;
                            cout<<" "<<setiosflags(ios::left)<<setw(17)<<info(P).kerugian;
                            cout<<" "<<setiosflags(ios::left)<<setw(17)<<info(P).total<<endl;
                        }
                        P = next(P);
                    } while (P!=NULL);
                } getch();
            } else if(userChoise==3){
                delInvestasi(LP,LC,LR);
            } else if(userChoise==5){
                addPohon(LP);
            } else if(userChoise==6){
                delParent(LR,LP);
            }
        } while (userChoise!=99);
}
void editPermission(List_parent& LP, list_relasi& LR){
    address_relasi R;
    system("cls");
    cout<<"...<< ADMIN << EDIT DATA POHON \n";
    cout<<"=============================== \n";
    cout<<"Masukkan nama pohon : ";
    string jawab;
    string cariPohon;
    cin>>cariPohon;
    address_parent P = searchParent(LP,cariPohon);
    if (P!=NULL){
        cout<<endl;
        cout<<"Ubah keuntungan? [Y/N] : ";
        cin>>jawab;
        if ((jawab=="Y")||(jawab=="y")){
            cout<<"Masukkan persentase keuntungan : ";
            cin>>info(P).profitPohon;
        }
        cout<<"\n==================================="<<endl;
        cout<<"Ubah kerugian? [Y/N] : ";
        cin>>jawab;
        if ((jawab=="Y")||(jawab=="y")){
            cout<<"Masukkan persentase kerugian : ";
            int loss;
            cin>>loss;
            info(P).lossPohon = loss;
        }
        cout<<"\n==================================="<<endl;
        cout<<"Tambah stock pohon? [Y/N] : ";
        cin>>jawab;
        if ((jawab=="Y")||(jawab=="y")){
            cout<<"Masukkan tambahan jumlah pohon : ";
            int sedia;
            cin>>sedia;
            info(P).stockPohon = info(P).stockPohon + sedia;
        }
        cout<<"\n==================================="<<endl;
        address_relasi Q = first(LR);
        do {
            if (info(parent(Q)).namaPohon==cariPohon){
                info(Q).keuntungan = (info(P).profitPohon*(info(P).biayaPohon*info(Q).jumlah_pohon))/100;
                info(Q).kerugian = (info(P).lossPohon*(info(P).biayaPohon*info(Q).jumlah_pohon))/100;
                info(Q).total = info(P).biayaPohon*info(Q).jumlah_pohon+(info(Q).keuntungan - info(Q).kerugian);
            }
            Q = next(Q);
        } while (Q!=NULL);
        cout<<"click to continue...";
        getch();
    } else {
        cout<<"Data tidak ditemukan";
        getch();
    }
}
void addPohon(List_parent& LP){
    string namaTree;
    infotypeParent X;
    system("cls");
    cout<<"... << ADMIN << TAMBAH POHON\n";
    cout<<"=============================\n";
    cout<<"Masukkan nama pohon : ";
    cin>>namaTree;
    if (!searchParent(LP,namaTree)){
        X.namaPohon = namaTree;
        cout<<"Masukkan harga pohon : ";
        cin>>X.biayaPohon;
        cout<<"Masukkan keuntungan pohon : ";
        cin>>X.profitPohon;
        cout<<"Masukkan kerugian pohon : ";
        cin>>X.lossPohon;
        cout<<"Masukkan ketersediaan pohon : ";
        cin>>X.stockPohon;
        insertFirst(LP,alokasi(X));
    }else{
        cout<<"Maaf data sudah ada...";
        getch();
    }
}
void delParent(list_relasi LR,List_parent& LP){
    system("cls");
    string nama;
    bool periksa = false;
    address_parent P;
    cout<<"... << ADMIN << HAPUS POHON \n";
    cout<<"============================ \n";
    cout<<"Masukkan nama pohon : ";
    cin>>nama;
    P = searchParent(LP,nama);
    if (P!=NULL){
        address_relasi R = first(LR);
        do{
           if(info(parent(R)).namaPohon==nama){
                periksa = true;
           } R = next(R);
        }while((R!=NULL)&&(periksa==false));
        if (periksa==false){
            deleteParent(LP,P,nama);
            cout<<"Data pohon berhasil dihapus";
            dealokasi(P);
            getch();
        } else {
            cout<<"Data pohon tidak bisa dihapus...";
            getch();
        }
    } else {
        cout<<"Data pohon tidak ada...";
        getch();
    }
}
void addInvestor(List_child& LC){
    string namaInvestor;
    infotypeChild X;
    system("cls");
    cout<<"... << USER LOGIN << DAFTAR BARU\n";
    cout<<"=============================\n";
    cout<<"Masukkan nama Investor : ";
    cin>>namaInvestor;
    if(!searchChild(LC, namaInvestor)){
        X.namaOrang = namaInvestor;
        cout<<"Budget : ";
        cin>>X.budget;
        insertFirst(LC,alokasi(X));
    }else{
        cout<<"Maaf nama Anda telah terdaftar... ";
        getch();
    }
}
void addRelasi(List_parent& LP, List_child& LC, list_relasi& LR, string namaOrang){
    int jumlah;
    string cariPohon;
    address_relasi R;
    infotype_relasi x;
    system("cls");
    cout<<"...<< INVESTOR << TAMBAH DATA \n";
    cout<<"=============================== \n";
    cout<<"Masukkan nama pohon : ";
    cin>>cariPohon;
    address_parent P = searchParent(LP,cariPohon);
    cout<<searchParent(LP,cariPohon)<<endl;
    address_child C = searchChild(LC,namaOrang);
    cout<<info(C).namaOrang;
        if(P!= NULL){
            cout<<"DATA POHON YANG DICARI : \n";
            cout<<"Nama pohon : "<<info(P).namaPohon<<endl;
            cout<<"Harga pohon : "<<info(P).biayaPohon<<endl;
            cout<<"Keuntungan (ROI) "<<info(P).profitPohon<<"%\n";
            cout<<"Kerugian (LOSS) "<<info(P).lossPohon<<"%\n";
            cout<<"Stock pohon : "<<info(P).stockPohon<<endl;
            cout<<"================================================= \n";
            cout<<"Total Anggaran yang Anda miliki : Rp "<<info(C).budget<<endl;;
            cout<<"================================================= \n";
            cout<<"Jumlah Pohon : ";
                cin>>jumlah;
                if (jumlah<=info(P).stockPohon){
                    if (jumlah*info(P).biayaPohon>info(C).budget){
                        cout<<"Dana Anda tidak mencukupi...";
                    } else {
                        cout<<"Tanggal Join : ";
                        cin>>x.tgl_join;
                        cout<<"Tanggal Keluar : ";
                        cin>>x.tgl_keluar;
                        x.jumlah_pohon = jumlah;
                        info(C).budget = info(C).budget - (jumlah*info(P).biayaPohon);
                        info(P).stockPohon = info(P).stockPohon - jumlah;
                        insertFirst(LR,alokasi(x,LP,LC,namaOrang,cariPohon));
                        cout<<"Transaksi SUKSES!";
                    }
                } else {
                    cout<<"Stock pohon tidak memadai";
                }
        } else {
            cout<<"Nama pohon tidak ditemukan...";
        }
    getch();
}
void delInvestasi(List_parent LP,List_child LC,list_relasi& LR){
    string data;
    system("cls");
    cout<<"Masukkan data pohon yang ingin dihapus : ";
    cin>>data;
    address_relasi P = searchRelasi(LR,data);
    if(P!=NULL){
        if (P==first(LR)){
            if (next(first(LR))==NULL){
                parent(P) = NULL;
                child(P) = NULL;
                first(LR) = NULL;
            } else if (next(first(LR))!=NULL){
                parent(P) = NULL;
                child(P) = NULL;
                first(LR) = next(P);
                next(P) = NULL;
            }
        } else {
            address_relasi Q = first(LR);
            while(next(Q)!=P){
                Q = next(Q);
            }
            if (next(P)==NULL){
                next(Q) = next(P);
                next(P) = NULL;
                parent(P) = NULL;
                child(P) = NULL;
            } else {
                parent(P) = NULL;
                child(P) = NULL;
                next(Q) = NULL;
            }
        }
    }
}
#endif // MENU_H_INCLUDED
