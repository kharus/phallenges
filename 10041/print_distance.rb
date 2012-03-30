raw_addresses = gets
adresses = raw_addresses.split
numbers = adresses.collect{ |s| s.to_i}

min_address = numbers.min
max_address = numbers.max

min_address.upto max_address do | number |
  distance = numbers.reduce(0){|total, x| total+=(x-number).abs}
  puts "#{number}:\t#{distance}"
end
