#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  unsigned char buffer[2];
  FILE *in1;
  FILE *in2;
  FILE *out;
  int c1, c2;

  if (argc != 4) {
    printf("Usage: %s in1.bin in2.bin out.bin\n", argv[0]);
    return EXIT_FAILURE;
  }

  in1 = fopen(argv[1], "rb");
  in2 = fopen(argv[2], "rb");
  out = fopen(argv[3], "wb");
  if (!in1 || !in2 || !out) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }
  while ((c1 = fgetc(in1)) != EOF && (c2 = fgetc(in2)) != EOF) {
    fputc(c1, out);
    fputc(c2, out);
  }
  fclose(in1);
  fclose(in2);
  fclose(out);
  return 0;
}