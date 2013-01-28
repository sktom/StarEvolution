
typedef struct
{
  double X;
  double Y;
  double Z;
} Composition;

typedef union ST
{
  double rho;
  double P;
  double T;
  double r;
  double Lr;
  Composition comp;
} State;

State current_state;

