#include <iostream>
using namespace std;
#include <conio.h>
#include <iomanip>

int data[15] = {1, 8, 2, 5, 4, 9, 7, 10, 18, 15, 13, 17, 11, 14, 20};
int cari;

void urutan()
{
	int temp, min, i, j;
	
	for(i=0; i<7;i++)
	{
		min = i;
		for(j = i+1; j<15; j++)
		{
			if(data[j]<data[min])
			{ min=j;}
		}
		temp = data[i]; ////temp sebagai tempat penyimpanan sementara saat menukar nilai
		data[i] = data[min];
		data[min] = temp;
	}
}

void binary_search()
{
	//searching
	int awal, akhir, tengah, b_flag = 0;
	awal = 0;
	akhir = 7;
	while (b_flag == 0 && awal<=akhir)
	{
		tengah = (awal + akhir)/2;
		if(data[tengah] == cari)
		{ b_flag = 1;
			break; }
			
		else if(data[tengah]<cari)
			awal = tengah + 1;
		else
			akhir = tengah-1;
	}
	if(b_flag ==1) //data kebenaran
		cout<<"\nData ditemukan pada index ke-"<<tengah<<endl;
	else
		cout<<"\nData tidak ditemukan";
}

int main()
{
	cout<<"\t 'BINARY SEARCH'"<<endl;
	cout<<"\t================"<<endl;
	cout<<"\nData		: ";

	for(int x = 0; x<15; x++) //tampilkan data awal
		cout<<setw(3)<<data[x]; // setw(3) fungsi manipulator yang berguna untuk mengatur lebar dari suatu tampilan data.
		cout<<endl;

	cout<<"\nMasukan data yang ingin Anda cari : "; cin>>cari;
	cout<<"\nData diurutkan : ";
	
	urutan(); //urutkan data dengan selection sort

	for(int x = 0; x<15; x++) //tampilkan data setelah diurutkan
		cout<<setw(3)<<data[x];
		cout<<endl;

	binary_search();

	getche();
	return 0;
}

