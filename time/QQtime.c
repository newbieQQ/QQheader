#include <stdio.h>
#include <time.h>
#include "QQtime.h"


char* CurTime() {
  static char buffer[80];
  static struct tm *timeinfo;

  static time_t rawtime;
  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 80, "%Y-%m-%d %H:%M", timeinfo);
  static char *res = buffer;
  return res;
}

#ifdef __TEST__
int main() {
  char *a = CurTime();
  printf("%s", a);
  return 0;
}
#endif
