CPP = g++
CFLAGS = -Wall -Wextra -Werror

all: clean main main2 tweets.o NaughtyOrNice.o

main: tweets.o
	  $(CPP) $(CFLAGS) -o tweet_test tweets.o

main2: NaughtyOrNice.o
	  $(CPP) $(CFLAGS) -o NoN_list NaughtyOrNice.o

tweets.o: tweets.cpp
	  $(CPP) $(CFLAGS) -c tweets.cpp

NaughtyOrNice.o: NaughtyOrNice.cpp
	  $(CPP) $(CFLAGS) -c NaughtyOrNice.cpp

clean:
	  rm -f *.o;
	  rm -f main;
	  rm -f main2;
	  rm -f *~;
