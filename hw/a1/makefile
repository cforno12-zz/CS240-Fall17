all: Donate

Donate: FornoCristobalDonorFunctions.o CA1.o
	g++ FornoCristobalDonorFunctions.o CA1.o -o Cris_Donor.exe

FornoCristobalDonorFunctions.o: FornoCristobalDonorFunctions.cpp CA1.cpp
	g++ -c FornoCristobalDonorFunctions.cpp
	g++ -c CA1.cpp

clean:
	rm -f *.o Cris_Donor.exe
