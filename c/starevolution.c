
#include "./evolution.h"
#include "./state.h"
#include <stdio.h>
#include <stdlib.h>

extern State current_state;
/*State * cs = &current_state;*/
extern State * cs;
extern void init_state(State *);
extern void create_initail_model(State *);
extern void time_evolution(double);
extern void simple_spatial_evolution(State *, double);
extern void spatial_evolution(State *);

int
main(int argc, char *argv[])
{
  init_state(cs);
  State * last_state_map = (State *)malloc(sizeof(State) * (M / dMr));
  State * log = (State *)malloc(sizeof(State) * (term / dt) * sizeof(State) * (M / dMr));
  create_initial_model(last_state_map);

  State * itor = last_state_map;
  int t;
  for(t = t0; t < term; t += dt)
  {
    time_evolution(t);
    while(++itor)
    {
      spatial_evolution(itor);
    }
    fit_boundary_state(cs);
    while(--itor)
    {
      spatial_evolution(itor);
      *itor = *cs;
    }
    log = itor;
    log += (unsigned long)(sizeof(State) * (M / dMr));
  }

  return 0;
}

