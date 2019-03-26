#include <stdio.h>

#define u8 unsigned int
u8 reverse_bits(u8 value) {
  //u8 tmp = 0;
  u8 t2 = 0;
  u8 ix = 1;
#if 0
  for (ix=0; ix<(sizeof(u8)*8); ix++) {
    tmp = (value>>ix)&1;
    t2 <<= 1;
    t2 |= tmp;
  }
#endif
#if 0
  tmp = value;
  while (0 != ix) {
    t2 <<= 1;
    t2 |= (tmp&1);
    tmp >>= 1;
    ix <<= 1;
  }
#endif
  for (ix=1; ix!=0; ix<<=1) {
    t2 <<= 1;
    t2 |= value&1;
    value >>= 1;
  }
  return t2;
}
main() {
  u8 value = 25;
  printf("reverse_bits(0x%x)=0x%x \n", value, reverse_bits(value));

}
