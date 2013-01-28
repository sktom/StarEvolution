#include "./evolute.h"
#include "./state.h"
#include <stdio.h>

extern State current_state;
extern void init_state(State *);
extern void create_initail_model(State *);
extern void time_evolute(State *);
extern void spatial_evolute(State *);
State * cs = &current_state;

void
simple_spacial_evolution(double Mr, double dMr)
{
  cs->P += dPdMr(Mr, cs->r) * dMr;
  cs->rho += drhodMr(cs->rho, cs->T, cs->r, cs->comp) * dMr;
  cs->T += dTdMr(Mr, cs->P, cs->T, cs->r, cs->comp) * dMr;
  cs->r += drdMr(cs->rho, cs->r) * dMr;
  cs->Lr += dLrdMr(cs->rho, cs->T, cs->comp) * dMr;
}

void
spacial_evolution(double Mr, double dMr)
{
  cs->P = P(Mr, cs->r);
  cs->rho += drhodMr(cs->rho, cs->T, cs->r, cs->comp) * dMr;
  cs->T += dTdMr(Mr, cs->P, cs->T, cs->r, cs->comp) * dMr;
  cs->r += drdMr(cs->rho, cs->r) * dMr;
  cs->Lr += dLrdMr(cs->rho, cs->T, cs->comp) * dMr;
}

void
time_evolution(double t, double dt)
{
  cs->P += dPdt(t, cs->r) * dt;
  cs->rho += drhodt(cs->T, cs->rho, cs->comp) * dt;
  cs->T += dTdt(t, cs->r) * dt;
  cs->r += drdt(cs->rho, cs->r) * dt;
  cs->Lr += dLrdt(cs->rho, cs->T, cs->comp) * dt;
  cs->comp.X += dXdt() * dt;
  cs->comp.Y += dYdt() * dt;
  cs->comp.Z += dZdt() * dt;
}

int
main(int argc, char *argv[])
{
  State current_state;
  State * last_state_map;
  init_state(&current_state);
  create_initial_model(&last_state_map);

  int t, dt;
  for(t = 0, dt = pow(10, 17); t < pow(10, 19), t += pow(10, 17))
  {
    time_evolute(&current_state);
    State * itor = last_state_map;
    while(++itor)
    {
      spatial_evolute(&current_state, itor);
      &itor = *current_state;
    }
  }

  return 0;
}

