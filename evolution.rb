
module Evolution

    def dPdMr_(rad, m_r)
      - @G * m_r / (4 * @pi * @radius ** 4)
    end
    def press(rho, temp)
    end
    def drhodMr(temp, rho, comp)
      @dMr / (4 * @pi * @radius**2 * dr)
    end
    def dtempdMr(m_r, temp, rad, comp)
      -(1 - @gamma**-1) * @G * m_r * @temperature / (4 * @pi * @radius**4 * @pressure)
    end
    def dLdMr(temp, rho, comp)
      t9 = @temperature / 10**9
      e_pp = 2.4 * 10**4 * @density * @hydrogen**2 / t9**(2.0 / 3) * Math::exp(-3.380 / t9**(3**-1))
      e_cno = 4.4 * 10**25 * @density * @hydrogen * @metal / t9**(2.0 / 3) * Math::exp(-15.228 / t9**(3**-1))
      e_n = 0
      e_pp + e_cno - e_n
    end
    def drdMr(rad, rho)
      @dMr * (4 * @pi * @radius**2 * @density)**-1
    end

    def dcompdt(temp, rho, comp)
    end
    def dPdt(rad, m_r)
    end
    def drhodt(temp, rho, comp)
    end
    def dtempdt(m_r, temp, rad, comp)
    end
    def dLdt(temp, rho, comp)
    end
    def drdt(rad, rho)
    end

    private
    def g()
    end
    def g_()
    end

end
