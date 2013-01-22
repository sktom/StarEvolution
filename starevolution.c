
#include "./evolute.def"
//#include "./state.h"
#include <stdio.h>
#include <math.h>

typedef struct
{
  double X;
  double Y;
  double Z;
} Composition;

typedef union
{
  double rho;
  double P;
  double T;
  double r;
  double Lr;
  Composition comp;
} State;

State current_state;

void simple_spacial_evalution(double Mr, double dMr)
{
  State * cs = &current_state;
  cs->P += dPdMr(Mr, cs->r);
  cs->rho += drhodMr(cs->rho, cs->T, cs->r, cs->comp);
  cs->T += dTdMr(Mr, cs->P, cs->T, cs->r, cs->comp);
  cs->r += drdMr(cs->rho, cs->r);
  cs->Lr += dLrdMr(cs->rho, cs->T, cs->comp);
}

void spacial_evalution(double Mr, double dMr)
{
  State * cs = &current_state;
  cs->P = P(Mr, cs->r);
  cs->rho += drhodMr(cs->rho, cs->T, cs->r, cs->comp);
  cs->T += dTdMr(Mr, cs->P, cs->T, cs->r, cs->comp);
  cs->r += drdMr(cs->rho, cs->r);
  cs->Lr += dLrdMr(cs->rho, cs->T, cs->comp);
}

/*FIX HERE
void time_evalution(double t, double dt)
{
  State * cs = &current_state;
  cs->P += dPdt(t, cs->r);
  cs->rho += drhodt(cs->T, cs->rho, cs->comp);
  cs->T += dTdt(t, cs->r);
  cs->r += drdt(cs->rho, cs->r);
  cs->Lr += dLrdt(cs->rho, cs->T, cs->comp);
}
*/
int
main(int argc, char *argv[])
{
  printf("%f", pow(3,4));

  return 0;
}

