FROM registry.fedoraproject.org/fedora:37

RUN dnf install -y gcc

WORKDIR /app

COPY . .

RUN gcc main.c -o hangman-c

ENTRYPOINT ["./hangman-c"]
