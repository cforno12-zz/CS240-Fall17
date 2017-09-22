all: Donor

link: Donor.o DonorDatabase.o CA2.o  DonorDatabase.h DonorDatabase.cpp Donor.cpp CA2.cpp Donor.h
	g++ Donor.o CA2.o DonorDatabase.o -o Cris_Donor.exe

compile: Donor.h DonorDatabase.h DonorDatabase.cpp Donor.cpp CA2.cpp
	g++ -c -Wall Donor.cpp
	g++ -c -Wall DonorDatabase.cpp
	g++ -c -Wall CA2.cpp

clean:
	rm -f *.o Cris_Donor.exe

compress: clean
	tar -cvvf Forno_Cristobal_cforno1_CA2.tar *.*
	gzip Forno_Cristobal_cforno1_CA2.tar
