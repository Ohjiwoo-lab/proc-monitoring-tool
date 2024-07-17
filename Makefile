OBJ = output/custom_ps.o
TARGET = output/custom_ps

$(TARGET): $(OBJ)
	gcc -o $(TARGET) $(OBJ)

$(OBJ): custom_ps.c
	gcc -c -o $(OBJ) custom_ps.c

clean:
	rm -f $(OBJ) $(TARGET)