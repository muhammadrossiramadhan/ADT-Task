ifeq ($(OS),Windows_NT)
    COMPILE = main.exe
    RUN = .\main.exe
else
    COMPILE = main
    RUN = ./main
endif


main: hashmap.c main.c
	rm -rf $(COMPILE)
	gcc hashmap.c main.c -o $(COMPILE)
	$(RUN)