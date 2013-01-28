
#include "./const.h"

#ifdef _BOOST_
#define _ current_state
#define P _.P
#define Mr _.Mr
#define rho _.rho
#define T _.T
#define r _.r
#define Lr _.Lr
#endif

#define dP(Mr, r) \
  - PI * r * Mr
#define dPdMr(Mr, r) \
  - G * Mr / (4 * PI * pow(r, 4))
#define g(x) \
  x * (2 * x - 3) * pow(x * x + 1, 0.5) + 3 * log(x + pow(x * x + 1, 0.5))
#define g_(x) \
  x * (2 * x - 3) * pow(x * x + 1, 0.5) + 3 * log(x + pow(x * x + 1, 0.5))
#define P(rho, T) \
  PI * pow(Me, 4) * pow(c, 5) / (3 * pow(h, 3)) * g(Pf / (Me * c))
#define drhodMr(rho, T, r, comp) \
  dMr / (4 * PI * pow(r, 2) * drdMr(r, rho))
#define dTdMr(Mr, P, T, r, comp) \
  - (1 - pow(gamma, -1)) * G * Mr * T / (4 * PI * pow(r, 4) * P)
#define t9(T) (T / pow(10, 9))
#define e_pp(rho, T, comp) \
  2.4 * pow(10, 4) * rho * pow(comp.X, 2) / pow(t9(T), 2.0 / 3) * exp(-3.380 / pow(t9(T), pow(3, 1)))
#define e_cno(rho, T, comp) \
  4.4 * pow(10, 25) * rho * comp.X * comp.Z / pow(t9(T), 2.0 / 3) * exp(-15.228 / pow(t9(T), pow(3, 1)))
#define e_n 0
#define dLrdMr(rho, T, comp) \
  e_pp(rho, T, comp) + e_cno(rho, T, comp) - e_n
#define drdMr(rho, r) \
  dMr * pow(4 * PI * pow(r, 2) * rho, -1)

#define drhodt(T, rho, comp) 0
#define dPdt(t, r) 0
#define dTdt(t, r) 0
#define drdt(rho, r) 0
#define dLrdt(rho, T, comp) 0
#define dXdt() 0
#define dYdt() 0
#define dZdt() 0

