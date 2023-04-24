hwk4.exe : main.o Accounts.o Account.o AccountSystem.o AccountChecking.o AccountSaving.o
	g++ main.o Accounts.o Account.o AccountSystem.o AccountChecking.o AccountSaving.o -o hwk4.exe

main.o : main.cpp AccountSystem.h
	g++ -Wall -c main.cpp

Accounts.o : Accounts.cpp Accounts.h
	g++ -Wall -c Accounts.cpp

Account.o : Account.cpp Account.h
	g++ -Wall -c Account.cpp

AccountSystem.o : AccountSystem.cpp AccountSystem.h
	g++ -Wall -c AccountSystem.cpp

AccountChecking.o : AccountChecking.cpp AccountChecking.h
	g++ -Wall -c AccountChecking.cpp

AccountSaving.o : AccountSaving.cpp AccountSaving.h
	g++ -Wall -c AccountSaving.cpp
clean :
	rm *.o hwk4.exe