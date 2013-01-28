
#include "./state.h"

void init_state(State * ps)
{
  ps->rho = 1.56 * pow(10, 2); /*gm/cm*/
  ps->P = 2.7 * pow(10, 17); /*dyn/cm2*/
  ps->T = 1.4 * pow(10, 7); /*K*/
  ps->r = 0.0; /*cm*/
  ps->Lr = 0.0; /*erg/s*/
  ps->comp.X = 0.73; /*nil*/
  ps->comp.Y = 0.25; /*nil*/
  ps->comp.Z = 0.02; /*nil*/
}

