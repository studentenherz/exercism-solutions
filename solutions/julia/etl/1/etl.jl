function transform(input::AbstractDict)
  d = Dict()
  for (value, letters) in input
    for letter in letters
      d[lowercase(letter)] = value
    end
  end
  d
end

