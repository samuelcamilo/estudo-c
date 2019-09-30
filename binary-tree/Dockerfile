FROM gcc:4.9

COPY . /usr/src/binary-tree
WORKDIR /usr/src/binary-tree
RUN gcc -o binary-tree ./Source/main.c
CMD ["./binary-tree"]