#include"kernel/types.h"
#include"user/user.h"
#include"kernel/param.h"
int main(void)
{
  uint64 a = freemem();printf("free mem: %lu bytes\n", a);void *p =malloc(10 *4096);
  uint64 b = freemem();printf("after malloc: %lu bytes\n", b);free(p);
  uint64 c = freemem();printf("after free: %lu bytes\n", c);exit(0);
}