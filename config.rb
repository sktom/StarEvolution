
require './xmlparser'

config_file = "constants.xml"
Config = XML::Document.new(config_file)[:constant]

boundary_state = Config[:state][:boundary]
initial_comp = Config[:state][:initial]
CentralState = State.new boundary_state[:central].merge(initial_comp)
SurfaceState = State.new boundary_state[:surface].merge(initial_comp)

consts = Config[:natural]
consts.each do |k, v|
  eval "#{k} = #{v}"
end

