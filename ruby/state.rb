
require './xmlparser'
require './evolution'

class State
  attr :Mr, :P, :rho, :T, :Lr
  class SimpleMrProc < Proc; include Evolution::SimpleMrEvolution; end
  class MrProc < Proc; include Evolution::MrEvolution; end
  class TimeProc < Proc; include Evolution::TimeEvolution; end

  def initialize attrs = nil
    @simple_mr_evolution = simple_mr_evolution
    @mr_evolution = mr_evolution
    @reverse_mr_evolution = reverse_mr_evolution
    @simple_mr_evolution = time_evolution

    return unless attrs
    attrs.each{|k, v| eval "@#{k} = #{v}"}
  end

  def simple_mr_evolute m_r; @simple_mr_evolution.call m_r; end
  def mr_evolute m_r; @mr_evolution.call m_r; end
  def reverse_mr_evolute m_r; @reverse_mr_evolution.call m_r; end
  def time_evolute t; @time_evolution.call t; end

  def shallow_copy
    Marshal.dump Marshal.load(self)
  end

  def to_s
    "#@P #@rho #@T #@Lr"
  end

  private
  def simple_mr_evolution
    SimpleMrProc.new do |m_r|
      @Mr = m_r
      dP = dP(@r, @Mr)
      drho = drho(@T, @rho, @comp)
      dT = dT(@Mr, @T, @r, @comp)
      @P += dP; @rho += drho; @T += dT
      @Mr += @dMr / 2
      dr = dr(@r, @rho)
      dL = dL(@T, @r, @comp)
      @r += dr; @L += dL
    end
  end
  def mr_evolution
    MrProc.new do |m_r|
      @Mr = m_r
      drho = drho(@T, @rho, @comp)
      dT = dT(@Mr, @T, @r, @comp)
      @P = press; @rho += drho; @T += dT
      @Mr += @dMr / 2
      dr = dr(@r, @rho)
      dL = dL(@T, @r, @comp)
      @r += dr; @L += dL
    end
  end
  def reverse_mr_evolution
    MrProc.new do |m_r|
      @Mr = m_r
      drho = drho(@T, @rho, @comp)
      dT = dT(@Mr, @T, @r, @comp)
      @P = press; @rho -= drho; @T -= dT
      @Mr -= @dMr / 2
      dr = dr(@r, @rho)
      dL = dL(@T, @r, @comp)
      @r -= dr; @L -= dL
    end
  end
  def time_evolution
    TimeProc.new do |t|
      @t = t
      dP = dP(@rho, @T)
      drho = drho(@T, @rho, @comp)
      dT = dT(@Mr, @T, @r, @comp)
      @P += dP; @rho += drho; @T += dT
      dr = dr(@r, @rho)
      dL = dL(@T, @r, @comp)
      @r += dr; @L += dL
    end
  end

end

#class State < Hash
#  def initialize config_file
#    update XML::Document.new(config_file)
#    each do |k, v|
#      v.kind_of?(Hash) ? parse(v) : eval("@#{k} = #{v}")
#    end
#    @radius = (3 * @dMr / (4 * @pi * @density))**(3**-1)
#  end
#
#  def update m_r, t
#    calc = lambda{|op|
#      #dp = - @G * m_r / (4 * @pi * @radius ** 4)
#      @pressure = 
#      dt = -(1 - @gamma**-1) * @G * m_r * @temperature / (4 * @pi * @radius**4 * @pressure)
#      @temperature += dt
#      drho = 
#      @density = @dMr / (4 * @pi * @radius**2 * dr)
#
#      m_r += @dMr / 2
#      dr = @dMr * (4 * @pi * @radius**2 * @density)**-1
#      @radius += dr
#      t9 = @temperature / 10**9
#      e_pp = 2.4 * 10**4 * @density * @hydrogen**2 / t9**(2.0 / 3) * Math::exp(-3.380 / t9**(3**-1))
#      e_cno = 4.4 * 10**25 * @density * @hydrogen * @metal / t9**(2.0 / 3) * Math::exp(-15.228 / t9**(3**-1))
#      e_n = 0
#      @luminosity += e_pp + e_cno - e_n
#    }
#
#    @luminosity
#  end
#
#end
#

