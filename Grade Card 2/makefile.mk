CC= gcc
CFLAGS= -Wall -Wextra

EXECUTABLE= gradecard

all: $(EXECUTABLE)

$(EXECUTABLE): main.o grades.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) main.o grades.o

main.o: main.c grades.h
	$(CC) $(CFLAGS) -c main.c

grades.o: grades.c grades.h
	$(CC) $(CFLAGS) -c grades.c

clean:
	rm -f $(EXECUTABLE) main.o grades.o

