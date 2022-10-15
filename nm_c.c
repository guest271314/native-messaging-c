// Native Messaging host C
// https://stackoverflow.com/q/64400254
// https://gist.github.com/zed/4459378be67a4b37f53430e0703cb700
// guest271314, 2022

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://www.reddit.com/r/C_Programming/comments/y4omt0/comment/isfgnsd
uint8_t* getMessage() {
  uint32_t messageLength = 0;
  fread(&messageLength, sizeof(messageLength), 1, stdin);
  uint8_t *message = calloc(messageLength, sizeof(*message));
  fread(message, sizeof(*message), messageLength, stdin);
  return message;
}

void sendMessage(uint8_t *response) {
  const uint32_t responseLength = strlen(response);
  fwrite(&responseLength, sizeof responseLength, 1, stdout);
  fwrite(response, responseLength, 1, stdout);
  fflush(stdout);
}

int main(void) {
  while (1) {
    uint8_t *const message = getMessage();
    sendMessage(message);
    free(message);
  }
}
