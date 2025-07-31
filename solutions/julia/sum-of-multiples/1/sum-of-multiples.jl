function sum_of_multiples(limit, factors)
  multiples = []

  for factor in factors
    if factor != 0
      multiples = multiples ∪ (collect(1:(limit÷factor)) * factor)
    end
  end
  setdiff!(multiples, [limit])

  isempty(multiples) ? 0 : sum(multiples)
end
