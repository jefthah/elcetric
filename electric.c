//5 Desember 2021
#include <stdio.h>
#include <windows.h>
#include <string.h>

void open(){
	
	printf("\n\n");
	printf("\t\t+==============================================================================+\n");
	printf("\t\t|                      SELAMAT DATANG DI MARKET LISTRIK                        |\n");
	printf("\t\t+------------------------------------------------------------------------------+\n");
	printf("\t\t|                                PILIH MENU                                    |\n");
	printf("\t\t+------------------------------------------------------------------------------+\n");
	printf("\t\t|                                                                              |\n");
	printf("\t\t|   1. Beli Token Listrik                                                      |\n");
	printf("\t\t|   2. Bayar Listrik Bulanan                                                   |\n");
	printf("\t\t|   3. Exit                                                                    |\n");
	printf("\t\t|                                                                              |\n");	
	printf("\t\t+==============================================================================+\n\n");
	
}

struct profil{
	char nama[30], no_telp[12];
};

void token();
void token2();
void strukpembelian(struct profil x, char meter[10], int kode_struk);
void strukpembelian2(struct profil x, char meter[10], float harga);

int main(){
	
	system("color 0B");
	
	struct profil member;
	printf("\n\n\t\tLOGIN USER");
	printf("\n\n\t\t   Username: ");
	gets(member.nama);
	printf("\t\t   No Telepon: ");
	gets(member.no_telp);
		
	int kode, kode_struk;
	do{
		system("cls");
		open();
	
		ulang:
		int open;
		printf("\n\t\tMasukkan Pilihan Anda: ");
		scanf("%d", &open);
		;
		if(open == 3){
			break;
		}
		
		
		meter:
		char meter[10];
		printf("\t\tMasukkan Nomor Meter: ");
		scanf("%s", meter);;
	
		page1:
		switch(open){
			case 1:
			token();
			int token;
			printf("\n\t\tMasukkan Pilihan Anda: ");
			scanf("%d", &token);
			switch(token){
				case 1: printf("\t\t\tanda memilih 10.000\n"); kode_struk = 1; break;
				case 2: printf("\t\t\tanda memilih 20.000\n"); kode_struk = 2; break;
				case 3: printf("\t\t\tanda memilih 30.000\n"); kode_struk = 3; break;
				case 4: printf("\t\t\tanda memilih 40.000\n"); kode_struk = 4; break;
				case 5: printf("\t\t\tanda memilih 50.000\n"); kode_struk = 5; break;
				case 6: token2(); 
				int token2;
				printf("\n\t\tMasukkan Pilihan Anda: ");
				scanf("%d", & token2);
				switch(token2){
					case 1: printf("\t\t\tanda memilih 60.000\n"); kode_struk = 6; break;
					case 2: printf("\t\t\tanda memilih 75.000\n"); kode_struk = 7; break;
					case 3: printf("\t\t\tanda memilih 100.000\n"); kode_struk = 8; break;
					case 4: printf("\t\t\tanda memilih 200.000\n"); kode_struk = 9; break;
					case 5: printf("\t\t\tanda memilih 300.000\n"); kode_struk = 10; break;
					case 6: goto page1; break;
					default: printf("\t\t\tMasukkan Anda Tidak Valid\n"); goto repeat; break;
				}; break;
				case 7: goto repeat; break; 
				default: printf("\t\t\tMasukan Tidak Valid\n"); goto repeat; break;

			};strukpembelian(member,meter,kode_struk);break;
			case 2: 
			float daya, harga;
			printf("\t\tMasukkan Daya dalam Sehari (Watt): ");
			scanf("%f", &daya);
			harga = daya;
			harga = ((harga/1000) * 1450) * 24 * 30;
			strukpembelian2(member,meter,harga);break; //untuk penghitungan listrik bulanan 
		};
		

		repeat:
		printf("\t\t\tApakah ingin melakukan transaksi ulang? \n");
		printf("\t\t\t1. Ya\n");
		printf("\t\t\t2. Tidak\n");
		printf("\n\t\t\tMasukkan Pilihan Anda: ");
		scanf("%d", &kode);;
		
	} while (kode == 1);
	
	
	closing:
		printf("\n\t\t\t\t\t\t   terimakasih\n");;

	
	return 0;
}

void token(){
	
	printf("\n\t\t\tPilih Token Listrik Anda\n");
	printf("\t\t\t1. 10.000\n");
	printf("\t\t\t2. 20.000\n");
	printf("\t\t\t3. 30.000\n");
	printf("\t\t\t4. 40.000\n");
	printf("\t\t\t5. 50.000\n");
	printf("\t\t\t6. Halaman selanjutnya\n");
	printf("\t\t\t7. Keluar\n");

}

void token2(){
	
	printf("\n\t\t\tPilih Token Listrik Anda\n");
	printf("\t\t\t1. 60.000\n");
	printf("\t\t\t2. 75.000\n");
	printf("\t\t\t3. 100.000\n");
	printf("\t\t\t4. 200.000\n");
	printf("\t\t\t5. 300.000\n");
	printf("\t\t\t6. Halaman sebelumnya\n");
	
}

void strukpembelian(struct profil x, char meter[10], int kode_struk){
	
	int harga[10] = {10000, 20000, 30000, 40000, 50000, 60000, 75000, 100000, 200000, 300000};
	printf("\n\n\t\t\t\t\t\t STRUK PEMBELIAN\n");
	printf("\t\t==============================================================================\n\n");
	printf("\t\t\t+------------------------------------------------------------+\n");
	printf("\t\t\t|                         MARKET LISTRIK                     |\n");
	printf("\t\t\t|------------------------------------------------------------|\n");
	printf("\t\t\t|Username\t\t\t: %27s| \n", x.nama);
	printf("\t\t\t|Nomor Token\t\t\t: %27s| \n", meter);
	printf("\t\t\t|Harga yang harus di bayar\t: %27d| \n", harga[kode_struk-1]);
	printf("\t\t\t+------------------------------------------------------------+\n\n");
	printf("\t\t==============================================================================\n\n");
	
}

void strukpembelian2(struct profil x, char meter[10], float harga){
	
	printf("\n\n\t\t\t\t\t\t STRUK PEMBELIAN\n");
	printf("\t\t==============================================================================\n\n");
	printf("\t\t\t+------------------------------------------------------------+\n");
	printf("\t\t\t|                         MARKET LISTRIK                     |\n");
	printf("\t\t\t|------------------------------------------------------------|\n");
	printf("\t\t\t|Username\t\t\t: %27s| \n", x.nama);
	printf("\t\t\t|Nomor Token\t\t\t: %27s| \n", meter);
	printf("\t\t\t|Harga yang harus di bayar\t: %27.0f| \n", harga);
	printf("\t\t\t+------------------------------------------------------------+\n\n");
	printf("\t\t==============================================================================\n\n");
	
}
