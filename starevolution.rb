
require './state'

StarEvolution = Object.new
class << StarEvolution

  def evolute
    init
File.open 'res', 'w' do |f|
    (0..@term).step @dt do |t|
      @log[t] = solve
      f.puts "#{t}, #@luminosity"
    end
end
`gnuplot -persist -e "plot 'res'"`
  end

  private
  def init
    @log = Hash.new
    @state = State.new "initialstate.xml"
    @state.init_state self
    @radius = (3 * @dMr / (4 * @pi * @density))**(3**-1)
  end

  def solve
    (0..@mass).step @dMr do |m_r|
      dr = @dMr * (4 * @pi * @radius**2 * @density)**-1
      @radius += dr
      @pressure += - @G * m_r / (4 * @pi * @radius ** 4)
      @temperature += -(1 - @gamma**-1) * @G * m_r * @temperature / (4 * @pi * @radius**4 * @pressure)

      m_r += @dMr / 2
      @density = @dMr / (4 * @pi * @radius**2 * dr)
      t9 = @temperature / 10**9
      e_pp = 2.4 * 10**4 * @density * @hydrogen**2 / t9**(2.0 / 3) * Math::exp(-3.380 / t9**(3**-1))
      e_cno = 4.4 * 10**25 * @density * @hydrogen * @metal / t9**(2.0 / 3) * Math::exp(-15.228 / t9**(3**-1))
      e_n = 0
      @luminosity += e_pp + e_cno - e_n
    end

    @state
  end


end

StarEvolution.evolute
