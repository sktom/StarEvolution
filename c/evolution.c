
#include "./const.h"
#include "./state.h"
#include "./evolution.h"

extern State current_state;
State * cs = &current_state;

void
simple_spatial_evolution(State * st, double Mr)
{
  st->Mr = Mr;
  st->P += dPdMr(Mr, st->r) * dMr;
  st->rho += drhodMr(st->rho, st->T, st->r, st->comp) * dMr;
  st->T += dTdMr(Mr, st->P, st->T, st->r, st->comp) * dMr;
  st->r += drdMr(st->rho, st->r) * dMr;
  st->Lr += dLrdMr(st->rho, st->T, st->comp) * dMr;
}

void
create_initial_model(State * state_map)
{
  State state;
  init_state(&state);
  double Mr;
  for(Mr = 0; Mr < M; Mr += dMr)
  {
    simple_spatial_evolution(&state, Mr);
    *state_map++ = state;
  }
}

void
spatial_evolution(State * ls)
{
  cs->Mr = ls->Mr;
  cs->P = P(cs->Mr, cs->r);
  cs->rho += drhodMr(cs->rho, cs->T, cs->r, cs->comp) * dMr;
  cs->T += dTdMr(cs->Mr, cs->P, cs->T, cs->r, cs->comp) * dMr;
  cs->Mr += dMr / 2;
  cs->r += drdMr(cs->rho, cs->r) * dMr;
  cs->Lr += dLrdMr(cs->rho, cs->T, cs->comp) * dMr;
}

void
time_evolution(double t)
{
  cs->P += dPdt(t, cs->r) * dt;
  cs->rho += drhodt(cs->T, cs->rho, cs->comp) * dt;
  cs->T += dTdt(t, cs->r) * dt;
  cs->r += drdt(cs->rho, cs->r) * dt;
  double dLr = dLrdt(cs->rho, cs->T, cs->comp) * dt;
  cs->Lr += dLr;
  cs->comp.X += dXdt(dLr) * dt;
  cs->comp.Y += dYdt(dLr) * dt;
  cs->comp.Z += dZdt(dLr) * dt;
}

