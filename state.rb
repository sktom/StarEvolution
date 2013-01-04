
require './xmlparser'

class State < Hash
  def initialize config_file
    update XML::Document.new(config_file)
  end
  def init_state instance
    Kernel.send :define_method, :parse do |hash|
      hash.each do |k, v|
        v.kind_of?(Hash) ? parse(v) : instance.instance_eval("@#{k} = #{v}")
      end
    end
    parse self
  end

end

