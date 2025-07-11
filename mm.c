#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

void
_(const char *l, mpz_t v)
{
  gmp_printf("  %s\n", l);
  gmp_printf("    dec %Zd\n", v);
  gmp_printf("    hex 0x%Zx\n", v);
  gmp_printf("    oct 0%Zo\n", v);
}

int
main(int ac, char **av, char **ev)
{
  (void)ev;
  if(ac != 2)
  {
    fprintf(stderr, "usage: %s <bytes>\n", av[0]);
    return 1;
  }

  int by = atoi(av[1]);
  if(by <= 0)
    return 1;
  int bi = by * 8;

  mpz_t um, un, sm, sn;
  mpz_inits(um, un, sm, sn, NULL);

  mpz_set_ui(un, 0);
  mpz_ui_pow_ui(um, 2, bi);
  mpz_sub_ui(um, um, 1);

  mpz_ui_pow_ui(sm, 2, bi - 1);
  mpz_sub_ui(sm, sm, 1);

  mpz_ui_pow_ui(sn, 2, bi - 1);
  mpz_neg(sn, sn);

  printf("[%d bytes => %d bits]\nunsigned\n", by, bi);
  _("min", un);
  _("max", um);

  printf("signed\n");
  _("min", sn);
  _("max", sm);

  mpz_clears(um, un, sm, sn, NULL);
  return 0;
}
