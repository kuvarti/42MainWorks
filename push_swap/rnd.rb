require 'set'

def rand_n(n)
	randoms = Set.new
	loop do
		randoms << rand(-500..500)
		return randoms if randoms.size >= n
	end
end

rand_n(ARGV[0].to_i).each do |dgr|
	print dgr
	print " "
end
