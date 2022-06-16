// Native Messaging host C
// https://stackoverflow.com/q/64400254
// https://gist.github.com/zed/4459378be67a4b37f53430e0703cb700
// guest271314, 2022
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *getMessage() {
  uint32_t message_length;
  fread(&message_length, sizeof message_length, 1, stdin);
  char *message = malloc(message_length);
  fread(message, sizeof *message, message_length, stdin);
  return message;
}

void sendMessage(const char *response) {
  const uint32_t response_length = strlen(response);
  fwrite(&response_length, sizeof response_length, 1, stdout);
  fwrite(response, response_length, 1, stdout);
  fflush(stdout);
}

int main() {
  while (1) {
    const char *message = getMessage();
    sendMessage(message);
  }
}
