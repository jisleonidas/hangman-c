FROM localhost/rockylinux-gcc:9

WORKDIR /app

COPY *.c header.h /app

RUN gcc main.c -o hangman-c

RUN dnf remove -y gcc

ENTRYPOINT ["./hangman-c"]
