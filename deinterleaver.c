#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  unsigned char buffer[2];
  FILE *in;
  FILE *out1;
  FILE *out2;
  int c;

  if (argc != 4) {
    printf("Usage: %s in.bin out1.bin out2.bin\n", argv[0]);
    return EXIT_FAILURE;
  }

  in = fopen(argv[1], "rb");
  out1 = fopen(argv[2], "wb");
  out2 = fopen(argv[3], "wb");
  if (!in || !out1 || !out2) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }
  while ((c = fgetc(in)) != EOF) {
    fputc(c, out1);
    if ((c = fgetc(in)) == EOF)
      break;
    fputc(c, out2);
  }
  fclose(in);
  fclose(out1);
  fclose(out2);
  return 0;
}