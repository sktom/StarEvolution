
#include "./const.def"

#define dP(rad, m_r) \
  - PI * rad * m_r
#define dPdMr_(rad, m_r) \
  - G * m_r / (4 * PI * pow(radius,4))
#define g(x) \
  x * (2 * x - 3) * pow(x * x + 1, 0.5) + 3 * ln(x + pow(x * x + 1, 0.5))
#define g_(x) \
  x * (2 * x - 3) * pow(x * x + 1, 0.5) + 3 * ln(x + pow(x * x + 1, 0.5))
#define press(rho, temp) \
  PI * pow(m_e, 4) * pow(c, 5) / (3 * pow(h, 3)) * g(Pf / (m_e * c))
#define drhodMr(temp, rho, comp) \
  dMr / (4 * pi * pow(radius, 2) * dr)
#define dtempdMr(m_r, temp, rad, comp) \
  - (1 - pow(gamma, -1) * G * m_r * temp / (4 * pi * pow(rad, 4) * press)
#define t9 = @temperature / 10**9 
#define dLdMr(temp, rho, comp) \
  (e_pp = 2.4 * 10**4 * @density * @hydrogen**2 / t9**(2.0 / 3) * Math::exp(-3.380 / t9**(3**-1));\
e_cno = 4.4 * 10**25 * @density * @hydrogen * @metal / t9**(2.0 / 3) * Math::exp(-15.228 / t9**(3**-1));\
  e_n = 0;\
  e_pp + e_cno - e_n)
#define drdMr(rad, rho) \
  dMr * pow(4 * pi * pow(rad, 2) * dens, -1)

