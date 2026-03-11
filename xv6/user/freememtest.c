#include"kernel/types.h"
#include"user/user.h"
#include"kernel/param.h"
int main(void)
{
  uint64 a = freemem();
  printf("free mem: %lu bytes\n", a);
}