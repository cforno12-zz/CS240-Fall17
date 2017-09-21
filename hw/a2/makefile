all: Donor

Donor: Donor.o
	g++ Donor.o CA2.o -o Cris_Donor.exe

FornoCristobalDonorFunctions.o:
	g++ -c Donor.cpp
	g++ -c CA2.cpp

clean:
	rm -f *.o Cris_Donor.exe

compress: clean
	tar -cvvf Forno_Cristobal_cforno1_CA2.tar *.*
	gzip Forno_Cristobal_cforno1_CA2.tar
