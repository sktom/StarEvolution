
#include "./state.h"
#include <math.h>

void init_state(State * state)
{
  state->rho = 1.56 * pow(10, 2); /*gm/cm*/
  state->P = 2.7 * pow(10, 17); /*dyn/cm2*/
  state->T = 1.4 * pow(10, 7); /*K*/
  state->r = 0.0; /*cm*/
  state->Lr = 0.0; /*erg/s*/
  state->comp.X = 0.73; /*nil*/
  state->comp.Y = 0.25; /*nil*/
  state->comp.Z = 0.02; /*nil*/
}

void fit_boundary_state(State * state)
{
  state->rho = 0; /*gm/cm*/
  state->P = 0; /*dyn/cm2*/
  state->T = 0; /*K*/
}

