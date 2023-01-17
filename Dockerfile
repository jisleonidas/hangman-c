FROM localhost/rockylinux-gcc:9

WORKDIR /app

COPY *.c header.h /app

RUN gcc main.c -o hangman-c

ENTRYPOINT ["./hangman-c"]
