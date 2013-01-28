#!/usr/local/bin/ruby

require './state'
require './config'
require './evolution'
require 'active_support'

eval Config[:experimental].map{|k, v| "@#{k} = #{v}"}.join(';')

mr_itor = (@dMr..@M).step @dMr
r_mr_itor = (@dMr..@M).step(@dMr).reverse_each
time_itor = (@dt..@term).step @dt

state = CentralState
mr_itor.each{|m_r| state.simple_mr_evolute m_r}
time_itor.each do |t|
  mr_itor.each do |m_r|
    state.mr_evolute m_r
  end
  state = SurfaceState
  r_mr_itor.each do |m_r|
    state.mr_evolute m_r
  end
  state.time_evolute t
end

#StarEvolution = Object.new
#class << StarEvolution
#
#  def evolute
#    consts = XML::Document.new 'constants.xml'
#    consts[:experimental].each{|k, v| eval "@#{k}=#{v}"}
#    state = State.new constant[:state][:initial]
#    @log = {[0, 0] => Marshal.load Marshal.dump(state)}
#
#    T = @term / @dt
#    M = @mass / @dMr
#    T.times do |t|
#      [M.times, M.times.reverse_each].each do |enum|
#        enum.each do |m_r|
#          state.update m_r, t
#          @log[m_r, t] = Marshal.load Marshal.dump(@status)
#        end
#      end
#    end
#    output
#  end
#
#  def output
#    File.open 'res', 'w' do |f|
#      f.puts @log.map{|k, v| "#{k} #{v}"}.join "\n"
#    end
#    `gnuplot -persist -e "plot 'res'"`
#  end
#
#
#end
#
#StarEvolution.evolute
#

