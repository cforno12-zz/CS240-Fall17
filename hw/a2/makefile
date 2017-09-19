all: Donate

Donate: FornoCristobalDonorFunctions.o CA2.o
	g++ FornoCristobalDonorFunctions.o CA2.o -o Cris_Donor.exe

FornoCristobalDonorFunctions.o: FornoCristobalDonorFunctions.cpp CA2.cpp
	g++ -c FornoCristobalDonorFunctions.cpp
	g++ -c CA2.cpp

clean:
	rm -f *.o Cris_Donor.exe

compress: clean FornoCristobalDonorFunctions.cpp CA2.cpp Donate.h
	tar -cvvf Forno_Cristobal_cforno1_CA2.tar *.*
	gzip Forno_Cristobal_cforno1_CA2.tar
