function sum_of_multiples(limit, factors)
  multiples = Set{Int}()

  for factor in factors
    if factor != 0
      multiples = multiples ∪ (collect(1:(limit÷factor)) * factor)
    end
  end
  setdiff!(multiples, [limit])

  sum(multiples)
end
