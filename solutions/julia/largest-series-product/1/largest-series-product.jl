function largest_product(str, span)
  if span > length(str) || span < 0
    throw(ArgumentError("Invalid span"))
  end

  maxp = 0
  for i in 1:(length(str)-span+1)
    p = 1
    for j in 0:(span-1)
      p *= parse(Int, str[i+j])
    end
    maxp = max(maxp, p)
  end
  maxp
end