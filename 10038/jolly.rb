size = ARGV.first.to_i

positive_deltas = (1..size-1).to_a.shuffle

rand = Random.new
deltas = positive_deltas.collect do |x|
  if rand.rand < 0.5 then
    -x
  else
    x
  end
end

res = [rand.rand(200)-100]

deltas.inject(res) do | result, delta |
  previous = result.pop
  result.push(previous)
  result.push(previous + delta)
end

print res.join(" ")
