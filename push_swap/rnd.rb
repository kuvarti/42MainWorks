def sayiyaz
	print rand(-500..500)
	print " "
end

ARGV[0].to_i.times { sayiyaz }
