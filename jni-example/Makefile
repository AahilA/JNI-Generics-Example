JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
CFLAGS=-I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux

all: libHello.so Hello.class

libHello.so: Hello.cpp
	g++ ${CFLAGS} -shared -fPIC -o libHello.so Hello.cpp -lc

Hello.class: Hello.java
	javac Hello.java

clean:
	rm -rf Hello.class libHello.so

