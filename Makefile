CC = g++

CFLAGS  = -Wall -pipe -O2 -g --std=c++17 -lm
 
TARGET = LSEG_RO_atataru
 
all: $(TARGET)
	$(RM) -rf $(TARGET).dSYM
 
$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) src/player.cpp
 
clean:
	$(RM) $(TARGET)